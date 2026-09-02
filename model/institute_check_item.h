/*
 * institute_check_item.h
 *
 * 
 */

#ifndef _institute_check_item_H_
#define _institute_check_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct institute_check_item_t institute_check_item_t;




typedef struct institute_check_item_t {
    int *exists; //boolean
    char *name; // string
    char *source; // string

    int _library_owned; // Is the library responsible for freeing this object?
} institute_check_item_t;

__attribute__((deprecated)) institute_check_item_t *institute_check_item_create(
    int *exists,
    char *name,
    char *source
);

void institute_check_item_free(institute_check_item_t *institute_check_item);

institute_check_item_t *institute_check_item_parseFromJSON(cJSON *institute_check_itemJSON);

cJSON *institute_check_item_convertToJSON(institute_check_item_t *institute_check_item);

#endif /* _institute_check_item_H_ */

