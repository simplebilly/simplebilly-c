#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "execution_status.h"


char* execution_status_execution_status_ToString(simplebilly_api_execution_status__e execution_status) {
    char *execution_statusArray[] =  { "NULL", "ACTIVE", "PAUSED", "COMPLETED" };
    return execution_statusArray[execution_status];
}

simplebilly_api_execution_status__e execution_status_execution_status_FromString(char* execution_status) {
    int stringToReturn = 0;
    char *execution_statusArray[] =  { "NULL", "ACTIVE", "PAUSED", "COMPLETED" };
    size_t sizeofArray = sizeof(execution_statusArray) / sizeof(execution_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(execution_status, execution_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *execution_status_convertToJSON(simplebilly_api_execution_status__e execution_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "execution_status", execution_status_execution_status_ToString(execution_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_execution_status__e execution_status_parseFromJSON(cJSON *execution_statusJSON) {
    if(!cJSON_IsString(execution_statusJSON) || (execution_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return execution_status_execution_status_FromString(execution_statusJSON->valuestring);
}
