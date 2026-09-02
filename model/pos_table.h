/*
 * pos_table.h
 *
 * A physical table at a restaurant/cafe POS. &#x60;current_order_number&#x60; links the open order occupying the table; &#x60;None&#x60; means free.
 */

#ifndef _pos_table_H_
#define _pos_table_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pos_table_t pos_table_t;

#include "pos_table_status.h"



typedef struct pos_table_t {
    char *current_order_number; // string
    char *name; // string
    simplebilly_api_pos_table_status__e status; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} pos_table_t;

__attribute__((deprecated)) pos_table_t *pos_table_create(
    char *current_order_number,
    char *name,
    simplebilly_api_pos_table_status__e status
);

void pos_table_free(pos_table_t *pos_table);

pos_table_t *pos_table_parseFromJSON(cJSON *pos_tableJSON);

cJSON *pos_table_convertToJSON(pos_table_t *pos_table);

#endif /* _pos_table_H_ */

