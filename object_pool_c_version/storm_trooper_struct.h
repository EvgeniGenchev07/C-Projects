#ifndef STORM_TROOPER_STRUCT_H
#define STORM_TROOPER_STRUCT_H

#include "storm_trooper_type.h"

struct storm_trooper {
	short id;
	short health;
	short damage;
	enum storm_trooper_type type;
};

#endif // STORM_TROOPER_STRUCT_H