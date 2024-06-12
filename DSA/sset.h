#include <stdbool.h>
#ifndef SSET_H
#define SSET_H

typedef struct StudentSet StudentSet;
struct StudentSet {
    char* hash_value[3571][500];   
    int nums[3571];
};

void sset_init(StudentSet *set);
void sset_destroy(StudentSet *set);
bool sset_insert(StudentSet *set, const char *value);   // return true if the insertion is successful, false otherwise
bool sset_remove(StudentSet *set, const char *value);   // return true if the removal is successful, false otherwise
bool sset_contains(const StudentSet *set, const char *value);

#endif