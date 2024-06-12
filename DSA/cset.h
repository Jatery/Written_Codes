#include <stdbool.h>
#ifndef CSET_H
#define CSET_H

typedef struct CodeSet CodeSet;
struct CodeSet {
    /* define any field you need here */
	char code[1000000];
};

void cset_init(CodeSet *set);
void cset_destroy(CodeSet *set);
bool cset_insert(CodeSet *set, const char *value);   // return true if the insertion is successful, false otherwise
bool cset_remove(CodeSet *set, const char *value);   // return true if the removal is successful, false otherwise
bool cset_contains(const CodeSet *set, const char *value);

#endif
