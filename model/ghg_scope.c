#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ghg_scope.h"


char* ghg_scope_ghg_scope_ToString(simplebilly_api_ghg_scope__e ghg_scope) {
    char *ghg_scopeArray[] =  { "NULL", "1", "2", "3" };
    return ghg_scopeArray[ghg_scope];
}

simplebilly_api_ghg_scope__e ghg_scope_ghg_scope_FromString(char* ghg_scope) {
    int stringToReturn = 0;
    char *ghg_scopeArray[] =  { "NULL", "1", "2", "3" };
    size_t sizeofArray = sizeof(ghg_scopeArray) / sizeof(ghg_scopeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(ghg_scope, ghg_scopeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *ghg_scope_convertToJSON(simplebilly_api_ghg_scope__e ghg_scope) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "ghg_scope", ghg_scope_ghg_scope_ToString(ghg_scope)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_ghg_scope__e ghg_scope_parseFromJSON(cJSON *ghg_scopeJSON) {
    if(!cJSON_IsString(ghg_scopeJSON) || (ghg_scopeJSON->valuestring == NULL)) {
        return 0;
    }
    return ghg_scope_ghg_scope_FromString(ghg_scopeJSON->valuestring);
}
