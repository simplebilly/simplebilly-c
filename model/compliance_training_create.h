/*
 * compliance_training_create.h
 *
 * 
 */

#ifndef _compliance_training_create_H_
#define _compliance_training_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct compliance_training_create_t compliance_training_create_t;

#include "training_source.h"



typedef struct compliance_training_create_t {
    int *assignable; //boolean
    char *code; // string
    char *description; // string
    int *pass_score; //numeric
    char *plugin_platform; // string
    simplebilly_api_training_source__e source; //referenced enum
    char *title; // string
    int *validity_months; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} compliance_training_create_t;

__attribute__((deprecated)) compliance_training_create_t *compliance_training_create_create(
    int *assignable,
    char *code,
    char *description,
    int *pass_score,
    char *plugin_platform,
    simplebilly_api_training_source__e source,
    char *title,
    int *validity_months
);

void compliance_training_create_free(compliance_training_create_t *compliance_training_create);

compliance_training_create_t *compliance_training_create_parseFromJSON(cJSON *compliance_training_createJSON);

cJSON *compliance_training_create_convertToJSON(compliance_training_create_t *compliance_training_create);

#endif /* _compliance_training_create_H_ */

