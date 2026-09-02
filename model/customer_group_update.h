/*
 * customer_group_update.h
 *
 * 
 */

#ifndef _customer_group_update_H_
#define _customer_group_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct customer_group_update_t customer_group_update_t;




typedef struct customer_group_update_t {
    char *description; // string
    list_t *member_ids; //primitive container
    char *membership_filter; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} customer_group_update_t;

__attribute__((deprecated)) customer_group_update_t *customer_group_update_create(
    char *description,
    list_t *member_ids,
    char *membership_filter,
    char *name
);

void customer_group_update_free(customer_group_update_t *customer_group_update);

customer_group_update_t *customer_group_update_parseFromJSON(cJSON *customer_group_updateJSON);

cJSON *customer_group_update_convertToJSON(customer_group_update_t *customer_group_update);

#endif /* _customer_group_update_H_ */

