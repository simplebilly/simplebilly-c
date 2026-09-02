/*
 * pos_table_create.h
 *
 * 
 */

#ifndef _pos_table_create_H_
#define _pos_table_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pos_table_create_t pos_table_create_t;

#include "pos_table_status.h"



typedef struct pos_table_create_t {
    char *current_order_number; // string
    char *name; // string
    simplebilly_api_pos_table_status__e status; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} pos_table_create_t;

__attribute__((deprecated)) pos_table_create_t *pos_table_create_create(
    char *current_order_number,
    char *name,
    simplebilly_api_pos_table_status__e status
);

void pos_table_create_free(pos_table_create_t *pos_table_create);

pos_table_create_t *pos_table_create_parseFromJSON(cJSON *pos_table_createJSON);

cJSON *pos_table_create_convertToJSON(pos_table_create_t *pos_table_create);

#endif /* _pos_table_create_H_ */

