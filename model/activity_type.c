#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "activity_type.h"


char* activity_type_activity_type_ToString(simplebilly_api_activity_type__e activity_type) {
    char *activity_typeArray[] =  { "NULL", "call", "email", "meeting", "task", "note" };
    return activity_typeArray[activity_type];
}

simplebilly_api_activity_type__e activity_type_activity_type_FromString(char* activity_type) {
    int stringToReturn = 0;
    char *activity_typeArray[] =  { "NULL", "call", "email", "meeting", "task", "note" };
    size_t sizeofArray = sizeof(activity_typeArray) / sizeof(activity_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(activity_type, activity_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *activity_type_convertToJSON(simplebilly_api_activity_type__e activity_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "activity_type", activity_type_activity_type_ToString(activity_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_activity_type__e activity_type_parseFromJSON(cJSON *activity_typeJSON) {
    if(!cJSON_IsString(activity_typeJSON) || (activity_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return activity_type_activity_type_FromString(activity_typeJSON->valuestring);
}
