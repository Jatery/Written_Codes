#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "cset.h"
#include "sset.h"

int main () {
	StudentSet *sset = (StudentSet *)malloc(sizeof(StudentSet));
	CodeSet *cset = (CodeSet *)malloc(sizeof(CodeSet));
	sset_init(sset);
	cset_init(cset);
	char opt[100];
	char name[100];
	char lastname[100];
	char discard[100];
	while (true) {
		int test = scanf("%10s %20s %20s %[\n]", opt, lastname, name, discard);
		if (test == EOF) {
			break;
		}
		printf("%s %s %s\n", opt, lastname, name);
		if (test != 3 || strlen(name) > 15 || strlen(lastname) > 15) {
			printf("Invalid input\n");
			continue;
		}
		bool flag = false;
		for (int i = 0; i < strlen(name); i++) {
			if (!isalpha(name[i])) {
				flag = true;
			} else {
				name[i] = tolower(name[i]);
			}
		}
		for (int i = 0; i < strlen(lastname); i++) {
			if (!isalpha(lastname[i])) {
				flag = true;
			} else {
				lastname[i] = tolower(lastname[i]);
			}
		}
		if (flag) {
			printf("Invalid input\n");
			continue;
		}
		strcat(lastname, name);
		printf("%s", lastname);
		if (strcmp(opt, "register") == 0) {
			char code[100];
			scanf("%15s", code);
			if (strlen(code) != 10 || !cset_contains(cset, code)) {
				printf("Code invalid\n");
			} else if (sset_contains(sset, lastname)) {
				printf("Student already registered\n");
			} else {
				if (sset_insert(sset, lastname)) {
					printf("Student registered successfully\n");
				} else {
					printf("Student registration failed\n");
				}
				if (cset_remove(cset, code)) {
					printf("Code removed successfully\n");
				} else {
					printf("Code removal failed\n");
				}			
			}
		} else if (strcmp(opt, "withdraw") == 0) {
			if (sset_contains(sset, lastname)) {
				if (sset_remove(sset, lastname)) {
					printf("Student withdraw out successfully\n");
				} else {
					printf("Student withdraw failed\n");
				}
			} else {
				printf("Student not registered\n");
			}
		} else if (strcmp(opt, "check") == 0) {
			if (sset_contains(sset, lastname)) {
				printf("Student registered\n");
			} else {
				printf("Student not registered\n");
			}
		}
		else {
			printf("Invalid command\n");
		}
	}
}
