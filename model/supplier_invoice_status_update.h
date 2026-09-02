/*
 * supplier_invoice_status_update.h
 *
 * 
 */

#ifndef _supplier_invoice_status_update_H_
#define _supplier_invoice_status_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct supplier_invoice_status_update_t supplier_invoice_status_update_t;




typedef struct supplier_invoice_status_update_t {
    char *status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} supplier_invoice_status_update_t;

__attribute__((deprecated)) supplier_invoice_status_update_t *supplier_invoice_status_update_create(
    char *status
);

void supplier_invoice_status_update_free(supplier_invoice_status_update_t *supplier_invoice_status_update);

supplier_invoice_status_update_t *supplier_invoice_status_update_parseFromJSON(cJSON *supplier_invoice_status_updateJSON);

cJSON *supplier_invoice_status_update_convertToJSON(supplier_invoice_status_update_t *supplier_invoice_status_update);

#endif /* _supplier_invoice_status_update_H_ */

