/*
 * shipping_rule.h
 *
 * 
 */

#ifndef _shipping_rule_H_
#define _shipping_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct shipping_rule_t shipping_rule_t;

#include "country_code.h"



typedef struct shipping_rule_t {
    char *carrier; // string
    country_code_t *country; // custom
    char *delivery_time; // string
    int *is_active; //boolean
    double *max_weight_kg; //numeric
    double *min_weight_kg; //numeric
    char *name; // string
    char *notes; // string
    char *price; // string
    int *priority; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} shipping_rule_t;

__attribute__((deprecated)) shipping_rule_t *shipping_rule_create(
    char *carrier,
    country_code_t *country,
    char *delivery_time,
    int *is_active,
    double *max_weight_kg,
    double *min_weight_kg,
    char *name,
    char *notes,
    char *price,
    int *priority
);

void shipping_rule_free(shipping_rule_t *shipping_rule);

shipping_rule_t *shipping_rule_parseFromJSON(cJSON *shipping_ruleJSON);

cJSON *shipping_rule_convertToJSON(shipping_rule_t *shipping_rule);

#endif /* _shipping_rule_H_ */

