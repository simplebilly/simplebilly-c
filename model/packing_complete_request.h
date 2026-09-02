/*
 * packing_complete_request.h
 *
 * 
 */

#ifndef _packing_complete_request_H_
#define _packing_complete_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct packing_complete_request_t packing_complete_request_t;




typedef struct packing_complete_request_t {
    char *notes; // string
    char *order_number; // string
    char *shipment_id; // string
    char *video_url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} packing_complete_request_t;

__attribute__((deprecated)) packing_complete_request_t *packing_complete_request_create(
    char *notes,
    char *order_number,
    char *shipment_id,
    char *video_url
);

void packing_complete_request_free(packing_complete_request_t *packing_complete_request);

packing_complete_request_t *packing_complete_request_parseFromJSON(cJSON *packing_complete_requestJSON);

cJSON *packing_complete_request_convertToJSON(packing_complete_request_t *packing_complete_request);

#endif /* _packing_complete_request_H_ */

