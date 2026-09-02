#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lead_status.h"


char* lead_status_lead_status_ToString(simplebilly_api_lead_status__e lead_status) {
    char *lead_statusArray[] =  { "NULL", "new", "qualified" };
    return lead_statusArray[lead_status];
}

simplebilly_api_lead_status__e lead_status_lead_status_FromString(char* lead_status) {
    int stringToReturn = 0;
    char *lead_statusArray[] =  { "NULL", "new", "qualified" };
    size_t sizeofArray = sizeof(lead_statusArray) / sizeof(lead_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(lead_status, lead_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *lead_status_convertToJSON(simplebilly_api_lead_status__e lead_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "lead_status", lead_status_lead_status_ToString(lead_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_lead_status__e lead_status_parseFromJSON(cJSON *lead_statusJSON) {
    if(!cJSON_IsString(lead_statusJSON) || (lead_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return lead_status_lead_status_FromString(lead_statusJSON->valuestring);
}
