#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "emission_target_scope.h"


char* emission_target_scope_emission_target_scope_ToString(simplebilly_api_emission_target_scope__e emission_target_scope) {
    char *emission_target_scopeArray[] =  { "NULL", "total", "1", "2", "3" };
    return emission_target_scopeArray[emission_target_scope];
}

simplebilly_api_emission_target_scope__e emission_target_scope_emission_target_scope_FromString(char* emission_target_scope) {
    int stringToReturn = 0;
    char *emission_target_scopeArray[] =  { "NULL", "total", "1", "2", "3" };
    size_t sizeofArray = sizeof(emission_target_scopeArray) / sizeof(emission_target_scopeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(emission_target_scope, emission_target_scopeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *emission_target_scope_convertToJSON(simplebilly_api_emission_target_scope__e emission_target_scope) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "emission_target_scope", emission_target_scope_emission_target_scope_ToString(emission_target_scope)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_emission_target_scope__e emission_target_scope_parseFromJSON(cJSON *emission_target_scopeJSON) {
    if(!cJSON_IsString(emission_target_scopeJSON) || (emission_target_scopeJSON->valuestring == NULL)) {
        return 0;
    }
    return emission_target_scope_emission_target_scope_FromString(emission_target_scopeJSON->valuestring);
}
