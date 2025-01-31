#ifndef STORM_TROOPER_POOL_STRUCT_H
#define STORM_TROOPER_POOL_STRUCT_H

#include "storm_trooper_struct.h"

struct storm_trooper_pool {
	struct storm_trooper* troopers;
	int active_index;
	int capacity;
};

#endif // STORM_TROOPER_POOL_STRUCT_H