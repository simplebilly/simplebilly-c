/*
 * pos_register_create.h
 *
 * 
 */

#ifndef _pos_register_create_H_
#define _pos_register_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pos_register_create_t pos_register_create_t;

#include "pos_register_status.h"



typedef struct pos_register_create_t {
    char *name; // string
    simplebilly_api_pos_register_status__e status; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} pos_register_create_t;

__attribute__((deprecated)) pos_register_create_t *pos_register_create_create(
    char *name,
    simplebilly_api_pos_register_status__e status
);

void pos_register_create_free(pos_register_create_t *pos_register_create);

pos_register_create_t *pos_register_create_parseFromJSON(cJSON *pos_register_createJSON);

cJSON *pos_register_create_convertToJSON(pos_register_create_t *pos_register_create);

#endif /* _pos_register_create_H_ */

