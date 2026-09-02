/*
 * suitability_result.h
 *
 * 
 */

#ifndef _suitability_result_H_
#define _suitability_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct suitability_result_t suitability_result_t;

#include "box_fit.h"
#include "method_suitability.h"



typedef struct suitability_result_t {
    list_t *methods; //nonprimitive container
    struct box_fit_t *recommended_box; //model
    int *requires_insurance; //boolean
    char *total_value; // string
    double *total_weight_kg; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} suitability_result_t;

__attribute__((deprecated)) suitability_result_t *suitability_result_create(
    list_t *methods,
    box_fit_t *recommended_box,
    int *requires_insurance,
    char *total_value,
    double *total_weight_kg
);

void suitability_result_free(suitability_result_t *suitability_result);

suitability_result_t *suitability_result_parseFromJSON(cJSON *suitability_resultJSON);

cJSON *suitability_result_convertToJSON(suitability_result_t *suitability_result);

#endif /* _suitability_result_H_ */

