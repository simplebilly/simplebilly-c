/*
 * reorder_proposal_response.h
 *
 * The response envelope for a reorder proposal run.
 */

#ifndef _reorder_proposal_response_H_
#define _reorder_proposal_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reorder_proposal_response_t reorder_proposal_response_t;

#include "reorder_proposal_line.h"



typedef struct reorder_proposal_response_t {
    char *generated_at; //date time
    list_t *lines; //nonprimitive container
    long *total_suggested_quantity; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} reorder_proposal_response_t;

__attribute__((deprecated)) reorder_proposal_response_t *reorder_proposal_response_create(
    char *generated_at,
    list_t *lines,
    long *total_suggested_quantity
);

void reorder_proposal_response_free(reorder_proposal_response_t *reorder_proposal_response);

reorder_proposal_response_t *reorder_proposal_response_parseFromJSON(cJSON *reorder_proposal_responseJSON);

cJSON *reorder_proposal_response_convertToJSON(reorder_proposal_response_t *reorder_proposal_response);

#endif /* _reorder_proposal_response_H_ */

