/*
 * compliance_training.h
 *
 * 
 */

#ifndef _compliance_training_H_
#define _compliance_training_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct compliance_training_t compliance_training_t;

#include "training_source.h"



typedef struct compliance_training_t {
    int *assignable; //boolean
    char *code; // string
    char *created_at; //date time
    char *deleted_at; //date time
    char *description; // string
    char *id; // string
    int *pass_score; //numeric
    char *plugin_platform; // string
    simplebilly_api_training_source__e source; //referenced enum
    char *tenant_id; // string
    char *title; // string
    char *updated_at; //date time
    int *validity_months; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} compliance_training_t;

__attribute__((deprecated)) compliance_training_t *compliance_training_create(
    int *assignable,
    char *code,
    char *created_at,
    char *deleted_at,
    char *description,
    char *id,
    int *pass_score,
    char *plugin_platform,
    simplebilly_api_training_source__e source,
    char *tenant_id,
    char *title,
    char *updated_at,
    int *validity_months
);

void compliance_training_free(compliance_training_t *compliance_training);

compliance_training_t *compliance_training_parseFromJSON(cJSON *compliance_trainingJSON);

cJSON *compliance_training_convertToJSON(compliance_training_t *compliance_training);

#endif /* _compliance_training_H_ */

