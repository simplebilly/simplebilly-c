/*
 * shipping_rule_update.h
 *
 * 
 */

#ifndef _shipping_rule_update_H_
#define _shipping_rule_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct shipping_rule_update_t shipping_rule_update_t;

#include "country_code.h"



typedef struct shipping_rule_update_t {
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
} shipping_rule_update_t;

__attribute__((deprecated)) shipping_rule_update_t *shipping_rule_update_create(
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

void shipping_rule_update_free(shipping_rule_update_t *shipping_rule_update);

shipping_rule_update_t *shipping_rule_update_parseFromJSON(cJSON *shipping_rule_updateJSON);

cJSON *shipping_rule_update_convertToJSON(shipping_rule_update_t *shipping_rule_update);

#endif /* _shipping_rule_update_H_ */

