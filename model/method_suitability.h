/*
 * method_suitability.h
 *
 * 
 */

#ifndef _method_suitability_H_
#define _method_suitability_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct method_suitability_t method_suitability_t;

#include "shipping_rate.h"



typedef struct method_suitability_t {
    char *carrier; // string
    struct shipping_rate_t *rate; //model
    list_t *reasons; //primitive container
    char *service; // string
    int *suitable; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} method_suitability_t;

__attribute__((deprecated)) method_suitability_t *method_suitability_create(
    char *carrier,
    shipping_rate_t *rate,
    list_t *reasons,
    char *service,
    int *suitable
);

void method_suitability_free(method_suitability_t *method_suitability);

method_suitability_t *method_suitability_parseFromJSON(cJSON *method_suitabilityJSON);

cJSON *method_suitability_convertToJSON(method_suitability_t *method_suitability);

#endif /* _method_suitability_H_ */

