/*
 * packing_queue.h
 *
 * 
 */

#ifndef _packing_queue_H_
#define _packing_queue_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct packing_queue_t packing_queue_t;

#include "packing_queue_item.h"



typedef struct packing_queue_t {
    list_t *items; //nonprimitive container
    int *page; //numeric
    int *page_size; //numeric
    long *total_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} packing_queue_t;

__attribute__((deprecated)) packing_queue_t *packing_queue_create(
    list_t *items,
    int *page,
    int *page_size,
    long *total_count
);

void packing_queue_free(packing_queue_t *packing_queue);

packing_queue_t *packing_queue_parseFromJSON(cJSON *packing_queueJSON);

cJSON *packing_queue_convertToJSON(packing_queue_t *packing_queue);

#endif /* _packing_queue_H_ */

