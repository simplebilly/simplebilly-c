#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "webhook_event_status.h"


char* webhook_event_status_webhook_event_status_ToString(simplebilly_api_webhook_event_status__e webhook_event_status) {
    char *webhook_event_statusArray[] =  { "NULL", "accepted", "delivered", "failed", "received" };
    return webhook_event_statusArray[webhook_event_status];
}

simplebilly_api_webhook_event_status__e webhook_event_status_webhook_event_status_FromString(char* webhook_event_status) {
    int stringToReturn = 0;
    char *webhook_event_statusArray[] =  { "NULL", "accepted", "delivered", "failed", "received" };
    size_t sizeofArray = sizeof(webhook_event_statusArray) / sizeof(webhook_event_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(webhook_event_status, webhook_event_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *webhook_event_status_convertToJSON(simplebilly_api_webhook_event_status__e webhook_event_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "webhook_event_status", webhook_event_status_webhook_event_status_ToString(webhook_event_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_webhook_event_status__e webhook_event_status_parseFromJSON(cJSON *webhook_event_statusJSON) {
    if(!cJSON_IsString(webhook_event_statusJSON) || (webhook_event_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return webhook_event_status_webhook_event_status_FromString(webhook_event_statusJSON->valuestring);
}
