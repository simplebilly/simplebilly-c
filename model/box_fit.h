/*
 * box_fit.h
 *
 * 
 */

#ifndef _box_fit_H_
#define _box_fit_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct box_fit_t box_fit_t;




typedef struct box_fit_t {
    double *height_cm; //numeric
    int *item_count; //numeric
    double *length_cm; //numeric
    double *volume_cm3; //numeric
    double *width_cm; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} box_fit_t;

__attribute__((deprecated)) box_fit_t *box_fit_create(
    double *height_cm,
    int *item_count,
    double *length_cm,
    double *volume_cm3,
    double *width_cm
);

void box_fit_free(box_fit_t *box_fit);

box_fit_t *box_fit_parseFromJSON(cJSON *box_fitJSON);

cJSON *box_fit_convertToJSON(box_fit_t *box_fit);

#endif /* _box_fit_H_ */

