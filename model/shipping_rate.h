/*
 * shipping_rate.h
 *
 * 
 */

#ifndef _shipping_rate_H_
#define _shipping_rate_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct shipping_rate_t shipping_rate_t;




typedef struct shipping_rate_t {
    char *breakdown; // string
    char *carrier; // string
    char *cross_border_surcharge; // string
    char *destination_country; // string
    int *estimated_days; //numeric
    int *from_api; //boolean
    char *insured_value; // string
    char *island_surcharge; // string
    char *origin_country; // string
    char *rate; // string
    char *service; // string
    char *volume_discount; // string
    double *weight_kg; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} shipping_rate_t;

__attribute__((deprecated)) shipping_rate_t *shipping_rate_create(
    char *breakdown,
    char *carrier,
    char *cross_border_surcharge,
    char *destination_country,
    int *estimated_days,
    int *from_api,
    char *insured_value,
    char *island_surcharge,
    char *origin_country,
    char *rate,
    char *service,
    char *volume_discount,
    double *weight_kg
);

void shipping_rate_free(shipping_rate_t *shipping_rate);

shipping_rate_t *shipping_rate_parseFromJSON(cJSON *shipping_rateJSON);

cJSON *shipping_rate_convertToJSON(shipping_rate_t *shipping_rate);

#endif /* _shipping_rate_H_ */

