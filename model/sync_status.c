#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sync_status.h"


char* sync_status_sync_status_ToString(simplebilly_api_sync_status__e sync_status) {
    char *sync_statusArray[] =  { "NULL", "pending", "connected", "success", "error" };
    return sync_statusArray[sync_status];
}

simplebilly_api_sync_status__e sync_status_sync_status_FromString(char* sync_status) {
    int stringToReturn = 0;
    char *sync_statusArray[] =  { "NULL", "pending", "connected", "success", "error" };
    size_t sizeofArray = sizeof(sync_statusArray) / sizeof(sync_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(sync_status, sync_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *sync_status_convertToJSON(simplebilly_api_sync_status__e sync_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "sync_status", sync_status_sync_status_ToString(sync_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_sync_status__e sync_status_parseFromJSON(cJSON *sync_statusJSON) {
    if(!cJSON_IsString(sync_statusJSON) || (sync_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return sync_status_sync_status_FromString(sync_statusJSON->valuestring);
}
