#ifndef STORM_TROOPER_POOL_H
#define STORM_TROOPER_POOL_H

#include "storm_trooper_pool_struct.h"
#include "storm_trooper_struct.h"

struct storm_trooper_pool* pool_alloc(int capacity);
void free_pool(void);
char is_pool_alloc(void);
void set_max_size(int new_capacity);
void release(int resting_index);
struct storm_trooper* acquire(void);
void print(void);
char** get_troopers(void);
char* get_troopers_hardcore(void);

#endif // STORM_TROOPER_POOL_H