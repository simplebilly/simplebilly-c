#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "employment_type.h"


char* employment_type_employment_type_ToString(simplebilly_api_employment_type__e employment_type) {
    char *employment_typeArray[] =  { "NULL", "fulltime", "parttime", "contract", "internship", "temporary" };
    return employment_typeArray[employment_type];
}

simplebilly_api_employment_type__e employment_type_employment_type_FromString(char* employment_type) {
    int stringToReturn = 0;
    char *employment_typeArray[] =  { "NULL", "fulltime", "parttime", "contract", "internship", "temporary" };
    size_t sizeofArray = sizeof(employment_typeArray) / sizeof(employment_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(employment_type, employment_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *employment_type_convertToJSON(simplebilly_api_employment_type__e employment_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "employment_type", employment_type_employment_type_ToString(employment_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_employment_type__e employment_type_parseFromJSON(cJSON *employment_typeJSON) {
    if(!cJSON_IsString(employment_typeJSON) || (employment_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return employment_type_employment_type_FromString(employment_typeJSON->valuestring);
}
