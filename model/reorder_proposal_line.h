/*
 * reorder_proposal_line.h
 *
 * A single reorder proposal line.
 */

#ifndef _reorder_proposal_line_H_
#define _reorder_proposal_line_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reorder_proposal_line_t reorder_proposal_line_t;




typedef struct reorder_proposal_line_t {
    long *current_stock; //numeric
    long *max_stock; //numeric
    long *min_stock; //numeric
    char *product_id; // string
    char *product_name; // string
    long *reorder_quantity; //numeric
    char *sku; // string
    long *suggested_quantity; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} reorder_proposal_line_t;

__attribute__((deprecated)) reorder_proposal_line_t *reorder_proposal_line_create(
    long *current_stock,
    long *max_stock,
    long *min_stock,
    char *product_id,
    char *product_name,
    long *reorder_quantity,
    char *sku,
    long *suggested_quantity
);

void reorder_proposal_line_free(reorder_proposal_line_t *reorder_proposal_line);

reorder_proposal_line_t *reorder_proposal_line_parseFromJSON(cJSON *reorder_proposal_lineJSON);

cJSON *reorder_proposal_line_convertToJSON(reorder_proposal_line_t *reorder_proposal_line);

#endif /* _reorder_proposal_line_H_ */

