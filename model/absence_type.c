#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "absence_type.h"


char* absence_type_absence_type_ToString(simplebilly_api_absence_type__e absence_type) {
    char *absence_typeArray[] =  { "NULL", "vacation", "sick", "sabbatical", "parental", "other" };
    return absence_typeArray[absence_type];
}

simplebilly_api_absence_type__e absence_type_absence_type_FromString(char* absence_type) {
    int stringToReturn = 0;
    char *absence_typeArray[] =  { "NULL", "vacation", "sick", "sabbatical", "parental", "other" };
    size_t sizeofArray = sizeof(absence_typeArray) / sizeof(absence_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(absence_type, absence_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *absence_type_convertToJSON(simplebilly_api_absence_type__e absence_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "absence_type", absence_type_absence_type_ToString(absence_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_absence_type__e absence_type_parseFromJSON(cJSON *absence_typeJSON) {
    if(!cJSON_IsString(absence_typeJSON) || (absence_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return absence_type_absence_type_FromString(absence_typeJSON->valuestring);
}
