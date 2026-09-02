/*
 * payment_condition.h
 *
 * 
 */

#ifndef _payment_condition_H_
#define _payment_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct payment_condition_t payment_condition_t;




typedef struct payment_condition_t {
    int *discount_days; //numeric
    double *discount_percentage; //numeric
    char *id; // string
    char *name; // string
    int *payment_term_days; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} payment_condition_t;

__attribute__((deprecated)) payment_condition_t *payment_condition_create(
    int *discount_days,
    double *discount_percentage,
    char *id,
    char *name,
    int *payment_term_days
);

void payment_condition_free(payment_condition_t *payment_condition);

payment_condition_t *payment_condition_parseFromJSON(cJSON *payment_conditionJSON);

cJSON *payment_condition_convertToJSON(payment_condition_t *payment_condition);

#endif /* _payment_condition_H_ */

