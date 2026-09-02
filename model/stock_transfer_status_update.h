/*
 * stock_transfer_status_update.h
 *
 * 
 */

#ifndef _stock_transfer_status_update_H_
#define _stock_transfer_status_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct stock_transfer_status_update_t stock_transfer_status_update_t;




typedef struct stock_transfer_status_update_t {
    char *status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} stock_transfer_status_update_t;

__attribute__((deprecated)) stock_transfer_status_update_t *stock_transfer_status_update_create(
    char *status
);

void stock_transfer_status_update_free(stock_transfer_status_update_t *stock_transfer_status_update);

stock_transfer_status_update_t *stock_transfer_status_update_parseFromJSON(cJSON *stock_transfer_status_updateJSON);

cJSON *stock_transfer_status_update_convertToJSON(stock_transfer_status_update_t *stock_transfer_status_update);

#endif /* _stock_transfer_status_update_H_ */

