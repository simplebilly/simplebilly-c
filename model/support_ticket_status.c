#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "support_ticket_status.h"


char* support_ticket_status_support_ticket_status_ToString(simplebilly_api_support_ticket_status__e support_ticket_status) {
    char *support_ticket_statusArray[] =  { "NULL", "open", "awaiting_reply", "resolved", "closed" };
    return support_ticket_statusArray[support_ticket_status];
}

simplebilly_api_support_ticket_status__e support_ticket_status_support_ticket_status_FromString(char* support_ticket_status) {
    int stringToReturn = 0;
    char *support_ticket_statusArray[] =  { "NULL", "open", "awaiting_reply", "resolved", "closed" };
    size_t sizeofArray = sizeof(support_ticket_statusArray) / sizeof(support_ticket_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(support_ticket_status, support_ticket_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *support_ticket_status_convertToJSON(simplebilly_api_support_ticket_status__e support_ticket_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "support_ticket_status", support_ticket_status_support_ticket_status_ToString(support_ticket_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_support_ticket_status__e support_ticket_status_parseFromJSON(cJSON *support_ticket_statusJSON) {
    if(!cJSON_IsString(support_ticket_statusJSON) || (support_ticket_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return support_ticket_status_support_ticket_status_FromString(support_ticket_statusJSON->valuestring);
}
