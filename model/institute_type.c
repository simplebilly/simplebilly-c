#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "institute_type.h"


char* institute_type_institute_type_ToString(simplebilly_api_institute_type__e institute_type) {
    char *institute_typeArray[] =  { "NULL", "kein", "kreditinstitut", "finanzdienstleistungsinstitut", "finanzunternehmen", "versicherung" };
    return institute_typeArray[institute_type];
}

simplebilly_api_institute_type__e institute_type_institute_type_FromString(char* institute_type) {
    int stringToReturn = 0;
    char *institute_typeArray[] =  { "NULL", "kein", "kreditinstitut", "finanzdienstleistungsinstitut", "finanzunternehmen", "versicherung" };
    size_t sizeofArray = sizeof(institute_typeArray) / sizeof(institute_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(institute_type, institute_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *institute_type_convertToJSON(simplebilly_api_institute_type__e institute_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "institute_type", institute_type_institute_type_ToString(institute_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_institute_type__e institute_type_parseFromJSON(cJSON *institute_typeJSON) {
    if(!cJSON_IsString(institute_typeJSON) || (institute_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return institute_type_institute_type_FromString(institute_typeJSON->valuestring);
}
