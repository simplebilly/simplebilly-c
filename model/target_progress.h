/*
 * target_progress.h
 *
 * 
 */

#ifndef _target_progress_H_
#define _target_progress_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct target_progress_t target_progress_t;




typedef struct target_progress_t {
    double *base_value; //numeric
    int *base_year; //numeric
    char *description; // string
    char *id; // string
    double *progress_pct; //numeric
    char *scope; // string
    double *target_value; //numeric
    int *target_year; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} target_progress_t;

__attribute__((deprecated)) target_progress_t *target_progress_create(
    double *base_value,
    int *base_year,
    char *description,
    char *id,
    double *progress_pct,
    char *scope,
    double *target_value,
    int *target_year
);

void target_progress_free(target_progress_t *target_progress);

target_progress_t *target_progress_parseFromJSON(cJSON *target_progressJSON);

cJSON *target_progress_convertToJSON(target_progress_t *target_progress);

#endif /* _target_progress_H_ */

