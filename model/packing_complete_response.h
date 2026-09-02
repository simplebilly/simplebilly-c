/*
 * packing_complete_response.h
 *
 * 
 */

#ifndef _packing_complete_response_H_
#define _packing_complete_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct packing_complete_response_t packing_complete_response_t;




typedef struct packing_complete_response_t {
    char *message; // string
    char *new_state; // string
    char *order_number; // string
    int *success; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} packing_complete_response_t;

__attribute__((deprecated)) packing_complete_response_t *packing_complete_response_create(
    char *message,
    char *new_state,
    char *order_number,
    int *success
);

void packing_complete_response_free(packing_complete_response_t *packing_complete_response);

packing_complete_response_t *packing_complete_response_parseFromJSON(cJSON *packing_complete_responseJSON);

cJSON *packing_complete_response_convertToJSON(packing_complete_response_t *packing_complete_response);

#endif /* _packing_complete_response_H_ */

