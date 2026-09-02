/*
 * customer_group_create.h
 *
 * 
 */

#ifndef _customer_group_create_H_
#define _customer_group_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct customer_group_create_t customer_group_create_t;




typedef struct customer_group_create_t {
    char *description; // string
    list_t *member_ids; //primitive container
    char *membership_filter; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} customer_group_create_t;

__attribute__((deprecated)) customer_group_create_t *customer_group_create_create(
    char *description,
    list_t *member_ids,
    char *membership_filter,
    char *name
);

void customer_group_create_free(customer_group_create_t *customer_group_create);

customer_group_create_t *customer_group_create_parseFromJSON(cJSON *customer_group_createJSON);

cJSON *customer_group_create_convertToJSON(customer_group_create_t *customer_group_create);

#endif /* _customer_group_create_H_ */

