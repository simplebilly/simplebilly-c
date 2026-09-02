/*
 * packing_queue_item.h
 *
 * 
 */

#ifndef _packing_queue_item_H_
#define _packing_queue_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct packing_queue_item_t packing_queue_item_t;

#include "any_type.h"



typedef struct packing_queue_item_t {
    char *created_at; // string
    char *customer_id; // string
    int *delivery_note_printed; //boolean
    any_type_t *items; // custom
    int *items_count; //numeric
    int *label_printed; //boolean
    char *order_number; // string
    char *order_status; // string
    char *shipment_id; // string
    any_type_t *shipping_address; // custom
    char *shipping_method; // string
    char *tracking_number; // string
    char *video_recording; // string

    int _library_owned; // Is the library responsible for freeing this object?
} packing_queue_item_t;

__attribute__((deprecated)) packing_queue_item_t *packing_queue_item_create(
    char *created_at,
    char *customer_id,
    int *delivery_note_printed,
    any_type_t *items,
    int *items_count,
    int *label_printed,
    char *order_number,
    char *order_status,
    char *shipment_id,
    any_type_t *shipping_address,
    char *shipping_method,
    char *tracking_number,
    char *video_recording
);

void packing_queue_item_free(packing_queue_item_t *packing_queue_item);

packing_queue_item_t *packing_queue_item_parseFromJSON(cJSON *packing_queue_itemJSON);

cJSON *packing_queue_item_convertToJSON(packing_queue_item_t *packing_queue_item);

#endif /* _packing_queue_item_H_ */

