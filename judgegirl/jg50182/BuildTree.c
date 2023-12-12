#include <stdio.h>
#include <stdlib.h>
#include "BuildTree.h"

Node* BuildTree(Node* list1, Node* list2) {
	if (list1 == NULL && list2 == NULL) {
		return NULL;
	}
	if (list1 == NULL) {
		return list2;
	}
	if (list2 == NULL) {
		return list1;
	}
	int l1 = 0, l2 = 0;
	Node* tmp = list1;
	while (tmp != NULL) {
		l1++;
		tmp = tmp->left;
	}
	tmp = list2;
	while (tmp != NULL) {
		l2++;
		tmp = tmp->left;
	}
	Node *list1L = list1, *list1R = list1, *list2L = list2, *list2R = list2;
	if (list1->val < list2->val) {
		l1--;
		list1L = list1L->left;
		if(l1 > 1) {
			if (l1 & 1)
				l1++;	
			for (int i = 0; i < l1 / 2 - 1; i++) {
				list1L = list1L->left;
			}
			list1R = list1L->left;
			list1L->left = NULL;
			list1L = list1->left;
		}
		else
			list1R = NULL;
		if (l2 > 1) {
			if (l2 & 1)
				l2++;
			for (int i = 0; i < l2 / 2 - 1; i++) {
				list2L = list2L->left;
			}
			list2R = list2L->left;
			list2L->left = NULL;
			list2L = list2;
		}
		else
			list2R = NULL;
		list1->left = BuildTree(list1L, list2L);
		list1->right = BuildTree(list1R, list2R);
		return list1;
	}
	else {
		l2--;
		list2L = list2L->left;
		if (l2 > 1) {
			if (l2 & 1)
				l2++;
			for (int i = 0; i < l2 / 2 - 1; i++) {
				list2L = list2L->left;
			}
			list2R = list2L->left;
			list2L->left = NULL;
			list2L = list2->left;
		}
		else
			list2R = NULL;
		if (l1 > 1) {
			if (l1 & 1)
				l1++;
			for (int i = 0; i < l1 / 2 - 1; i++) {
				list1L = list1L->left;
			}
			list1R = list1L->left;
			list1L->left = NULL;
			list1L = list1;
		}
		else
			list1R = NULL;
		list2->left = BuildTree(list1L, list2L);
		list2->right = BuildTree(list1R, list2R);
		return list2;
	}
}
