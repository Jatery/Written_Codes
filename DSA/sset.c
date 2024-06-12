#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"sset.h"

int hash_func(const char* value){
    int sum = 0;
    for(int i=0;value[i]!='\0';i++){
        sum*=26;
        sum+=value[i];
        sum%=3571;
    }
    return sum;
}
void sset_init(StudentSet *set){
    for(int i=0;i<3571;i++){
        set->nums[i] = 0;
    }
    return;
}
void sset_destroy(StudentSet *set){
    if(set!=NULL) free(set);
}
bool sset_insert(StudentSet *set, const char *value){
    if(set==NULL) return false;
    int hash = hash_func(value);
    if(set->nums[hash] >= 500) return false;
    set->hash_value[hash][set->nums[hash]] = value;
    set->nums[hash]++;
    return true;
}
bool sset_remove(StudentSet *set, const char *value){
    if(set==NULL) return false;
    int hash = hash_func(value);
    for(int i=0;i<set->nums[hash];i++){
        if(strcmp(set->hash_value[hash][i],value)==0){
            set->hash_value[hash][i] = set->hash_value[hash][set->nums[hash]-1];
            set->nums[hash]--;
            return true;
        }
    }
    return false;
}
bool sset_contains(const StudentSet *set, const char *value){
    if(set==NULL) return false;
    int hash = hash_func(value);
    for(int i=0;i<set->nums[hash];i++){
        if(strcmp(set->hash_value[hash][i],value)==0){
            return true;
        }
    }
    return false;
}