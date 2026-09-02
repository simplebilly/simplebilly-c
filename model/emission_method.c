#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "emission_method.h"


char* emission_method_emission_method_ToString(simplebilly_api_emission_method__e emission_method) {
    char *emission_methodArray[] =  { "NULL", "activity", "spend", "supplier" };
    return emission_methodArray[emission_method];
}

simplebilly_api_emission_method__e emission_method_emission_method_FromString(char* emission_method) {
    int stringToReturn = 0;
    char *emission_methodArray[] =  { "NULL", "activity", "spend", "supplier" };
    size_t sizeofArray = sizeof(emission_methodArray) / sizeof(emission_methodArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(emission_method, emission_methodArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *emission_method_convertToJSON(simplebilly_api_emission_method__e emission_method) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "emission_method", emission_method_emission_method_ToString(emission_method)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_emission_method__e emission_method_parseFromJSON(cJSON *emission_methodJSON) {
    if(!cJSON_IsString(emission_methodJSON) || (emission_methodJSON->valuestring == NULL)) {
        return 0;
    }
    return emission_method_emission_method_FromString(emission_methodJSON->valuestring);
}
