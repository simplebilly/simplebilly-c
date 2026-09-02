/*
 * compliance_training_update.h
 *
 * 
 */

#ifndef _compliance_training_update_H_
#define _compliance_training_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct compliance_training_update_t compliance_training_update_t;

#include "training_source.h"



typedef struct compliance_training_update_t {
    int *assignable; //boolean
    char *code; // string
    char *description; // string
    int *pass_score; //numeric
    char *plugin_platform; // string
    training_source_t *source; // custom
    char *title; // string
    int *validity_months; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} compliance_training_update_t;

__attribute__((deprecated)) compliance_training_update_t *compliance_training_update_create(
    int *assignable,
    char *code,
    char *description,
    int *pass_score,
    char *plugin_platform,
    training_source_t *source,
    char *title,
    int *validity_months
);

void compliance_training_update_free(compliance_training_update_t *compliance_training_update);

compliance_training_update_t *compliance_training_update_parseFromJSON(cJSON *compliance_training_updateJSON);

cJSON *compliance_training_update_convertToJSON(compliance_training_update_t *compliance_training_update);

#endif /* _compliance_training_update_H_ */

