#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "activity_status.h"


char* activity_status_activity_status_ToString(simplebilly_api_activity_status__e activity_status) {
    char *activity_statusArray[] =  { "NULL", "open", "done", "cancelled" };
    return activity_statusArray[activity_status];
}

simplebilly_api_activity_status__e activity_status_activity_status_FromString(char* activity_status) {
    int stringToReturn = 0;
    char *activity_statusArray[] =  { "NULL", "open", "done", "cancelled" };
    size_t sizeofArray = sizeof(activity_statusArray) / sizeof(activity_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(activity_status, activity_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *activity_status_convertToJSON(simplebilly_api_activity_status__e activity_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "activity_status", activity_status_activity_status_ToString(activity_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_activity_status__e activity_status_parseFromJSON(cJSON *activity_statusJSON) {
    if(!cJSON_IsString(activity_statusJSON) || (activity_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return activity_status_activity_status_FromString(activity_statusJSON->valuestring);
}
