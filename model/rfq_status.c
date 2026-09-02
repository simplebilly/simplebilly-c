#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "rfq_status.h"


char* rfq_status_rfq_status_ToString(simplebilly_api_rfq_status__e rfq_status) {
    char *rfq_statusArray[] =  { "NULL", "draft", "sent", "offer_received", "rejected", "converted" };
    return rfq_statusArray[rfq_status];
}

simplebilly_api_rfq_status__e rfq_status_rfq_status_FromString(char* rfq_status) {
    int stringToReturn = 0;
    char *rfq_statusArray[] =  { "NULL", "draft", "sent", "offer_received", "rejected", "converted" };
    size_t sizeofArray = sizeof(rfq_statusArray) / sizeof(rfq_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(rfq_status, rfq_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *rfq_status_convertToJSON(simplebilly_api_rfq_status__e rfq_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "rfq_status", rfq_status_rfq_status_ToString(rfq_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_rfq_status__e rfq_status_parseFromJSON(cJSON *rfq_statusJSON) {
    if(!cJSON_IsString(rfq_statusJSON) || (rfq_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return rfq_status_rfq_status_FromString(rfq_statusJSON->valuestring);
}
