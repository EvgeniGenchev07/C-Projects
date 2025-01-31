#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "storm_trooper_pool.h"

static struct storm_trooper_pool *pool;

struct storm_trooper_pool *pool_alloc(int capacity)
{
	if (pool) free_pool();

	pool = malloc(sizeof *pool);
	if (!pool) assert(0);

	pool->active_index = 0;
	pool->troopers = malloc(sizeof *pool->troopers * capacity);
	if (!pool->troopers) assert(0);

	pool->capacity = capacity;
	return pool;
}

void free_pool(void)
{
	free(pool->troopers);
	free(pool);
}

char is_pool_alloc(void)
{
	return pool ? 1 : 0;
}

void set_max_size(int new_capacity)
{
	if (pool->capacity > new_capacity) return;

	struct storm_trooper *troopers = realloc(pool->troopers, sizeof *troopers * new_capacity);
	if (!troopers) {
		free_pool();
		assert(0);
	}

	pool->capacity = new_capacity;
	pool->troopers = troopers;
}

struct storm_trooper *acquire(void)
{
	if (pool->active_index == pool->capacity) set_max_size(pool->capacity * 2);
   	return &pool->troopers[pool->active_index++];
}

void release(int resting_index)
{
	struct storm_trooper swap = pool->troopers[pool->active_index];
	pool->troopers[pool->active_index--] = pool->troopers[resting_index];
	pool->troopers[resting_index] = swap;
}

// Just for temporary printing. Will use the last two methods!
#include <stdio.h>
void print(void)
{
	printf("Capacity: %d; Active Index: %d\n", pool->capacity, pool->active_index);
	printf("Address of the troopers array (for resizing check): %p\n", pool->troopers);
	for (int i = 0; i < pool->capacity; i++)
		printf("trooper[%d]: id = %d; damage = %d\n", i, pool->troopers[i].id, pool->troopers[i].damage);
}


char** get_troopers(void)
{
	// return the information about each storm trooper without using printf, as a large string!
	char** matrix = malloc(sizeof *matrix * pool->active_index);
	for (size_t i = 0; i < pool->capacity; i++){
		u_int16_t id = pool->troopers[i].id;
		u_int8_t len = 0;
		u_int8_t index = 0;
		u_int8_t devision = 0;
		while(id!=devision){
			len++;
			devision = id % (int)pow(10,index++);
		}
		u_int16_t damage = pool->troopers[i].damage;
		index = 0;
		while(id!=devision){
			len++;
			devision = damage % (int)pow(10,index++);
		}
		char *buffer = malloc(sizeof *buffer * (28+len));
		sprintf(buffer,"trooper[%d]: id = %d; damage = %d\n", i, pool->troopers[i].id, pool->troopers[i].damage);
		matrix[i] = buffer;
	}
	
	return matrix;
}

char* get_troopers_hardcore(void)
{
	char **temp_buffer = get_troopers();
	int len = 0;
	for (size_t i = 0; i < pool->capacity; i++)
	{
		len += strlen(temp_buffer[i]);
	}
	char *buffer = malloc(sizeof *buffer * len);
	for (size_t i = 0; i < pool->capacity; i++)
	{
		strcat(buffer,temp_buffer[i]);
		free(temp_buffer[i]);
	}
	free(temp_buffer);
	return buffer;
}