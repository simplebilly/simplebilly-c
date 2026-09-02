#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sync_log_status.h"


char* sync_log_status_sync_log_status_ToString(simplebilly_api_sync_log_status__e sync_log_status) {
    char *sync_log_statusArray[] =  { "NULL", "running", "success", "error" };
    return sync_log_statusArray[sync_log_status];
}

simplebilly_api_sync_log_status__e sync_log_status_sync_log_status_FromString(char* sync_log_status) {
    int stringToReturn = 0;
    char *sync_log_statusArray[] =  { "NULL", "running", "success", "error" };
    size_t sizeofArray = sizeof(sync_log_statusArray) / sizeof(sync_log_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(sync_log_status, sync_log_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *sync_log_status_convertToJSON(simplebilly_api_sync_log_status__e sync_log_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "sync_log_status", sync_log_status_sync_log_status_ToString(sync_log_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_sync_log_status__e sync_log_status_parseFromJSON(cJSON *sync_log_statusJSON) {
    if(!cJSON_IsString(sync_log_statusJSON) || (sync_log_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return sync_log_status_sync_log_status_FromString(sync_log_statusJSON->valuestring);
}
