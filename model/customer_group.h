/*
 * customer_group.h
 *
 * 
 */

#ifndef _customer_group_H_
#define _customer_group_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct customer_group_t customer_group_t;




typedef struct customer_group_t {
    char *description; // string
    list_t *member_ids; //primitive container
    char *membership_filter; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} customer_group_t;

__attribute__((deprecated)) customer_group_t *customer_group_create(
    char *description,
    list_t *member_ids,
    char *membership_filter,
    char *name
);

void customer_group_free(customer_group_t *customer_group);

customer_group_t *customer_group_parseFromJSON(cJSON *customer_groupJSON);

cJSON *customer_group_convertToJSON(customer_group_t *customer_group);

#endif /* _customer_group_H_ */

