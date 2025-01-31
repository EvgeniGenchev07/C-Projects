#include <stdlib.h>
#include <stdio.h>
#include "storm_trooper_pool.h"

int main(int argc, char **argv)
{
	struct storm_trooper_pool* pool = pool_alloc(4);
	printf("%d",is_pool_alloc());
  	 // printf("\n\r%d",`set_max_size(2));
	struct storm_trooper* cur1 = acquire();
	cur1->id = 10;
	struct storm_trooper* cur2 = acquire();
	cur2->id = 20;
	struct storm_trooper* cur3 = acquire();
	cur3->id = 30;
	struct storm_trooper* cur4 = acquire();
	cur4->id = 40;
	struct storm_trooper* cur5 = acquire();
	struct storm_trooper* cur6 = acquire();
	struct storm_trooper* cur7 = acquire();    

	cur5->id = 60;
	cur6->id = 70;
	cur7->id = 90;
	cur7->damage = 100;
	
	print();
	release(1);
    printf("\n----------------------------------\n");
	print();
    char** data = get_troopers();
    printf("\n----------------------------------\n");

    for (size_t i = 0; i < pool->capacity; i++)
    {
        printf("%s",data[i]);
        free(data[i]);
    }

    free(data);
    printf("\n-----------------------------------\n");
    printf("%s", get_troopers_hardcore());
	free_pool();
	return 0;
}
