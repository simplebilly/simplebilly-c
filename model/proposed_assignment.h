/*
 * proposed_assignment.h
 *
 * 
 */

#ifndef _proposed_assignment_H_
#define _proposed_assignment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct proposed_assignment_t proposed_assignment_t;




typedef struct proposed_assignment_t {
    char *amount_paid; // string
    double *confidence; //numeric
    char *customer_id; // string
    char *invoice_id; // string
    char *invoice_number; // string
    char *open_amount; // string
    char *payment_date; // string
    char *payment_id; // string
    char *reason; // string
    char *reference; // string

    int _library_owned; // Is the library responsible for freeing this object?
} proposed_assignment_t;

__attribute__((deprecated)) proposed_assignment_t *proposed_assignment_create(
    char *amount_paid,
    double *confidence,
    char *customer_id,
    char *invoice_id,
    char *invoice_number,
    char *open_amount,
    char *payment_date,
    char *payment_id,
    char *reason,
    char *reference
);

void proposed_assignment_free(proposed_assignment_t *proposed_assignment);

proposed_assignment_t *proposed_assignment_parseFromJSON(cJSON *proposed_assignmentJSON);

cJSON *proposed_assignment_convertToJSON(proposed_assignment_t *proposed_assignment);

#endif /* _proposed_assignment_H_ */

