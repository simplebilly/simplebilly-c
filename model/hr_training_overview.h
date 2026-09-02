/*
 * hr_training_overview.h
 *
 * 
 */

#ifndef _hr_training_overview_H_
#define _hr_training_overview_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct hr_training_overview_t hr_training_overview_t;




typedef struct hr_training_overview_t {
    long *assigned_count; //numeric
    char *code; // string
    long *completed_count; //numeric
    long *overdue_count; //numeric
    char *title; // string
    char *training_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} hr_training_overview_t;

__attribute__((deprecated)) hr_training_overview_t *hr_training_overview_create(
    long *assigned_count,
    char *code,
    long *completed_count,
    long *overdue_count,
    char *title,
    char *training_id
);

void hr_training_overview_free(hr_training_overview_t *hr_training_overview);

hr_training_overview_t *hr_training_overview_parseFromJSON(cJSON *hr_training_overviewJSON);

cJSON *hr_training_overview_convertToJSON(hr_training_overview_t *hr_training_overview);

#endif /* _hr_training_overview_H_ */

