#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "service_assignment_status.h"


char* service_assignment_status_service_assignment_status_ToString(simplebilly_api_service_assignment_status__e service_assignment_status) {
    char *service_assignment_statusArray[] =  { "NULL", "planned", "confirmed", "en_route", "in_progress", "completed", "cancelled" };
    return service_assignment_statusArray[service_assignment_status];
}

simplebilly_api_service_assignment_status__e service_assignment_status_service_assignment_status_FromString(char* service_assignment_status) {
    int stringToReturn = 0;
    char *service_assignment_statusArray[] =  { "NULL", "planned", "confirmed", "en_route", "in_progress", "completed", "cancelled" };
    size_t sizeofArray = sizeof(service_assignment_statusArray) / sizeof(service_assignment_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(service_assignment_status, service_assignment_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *service_assignment_status_convertToJSON(simplebilly_api_service_assignment_status__e service_assignment_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "service_assignment_status", service_assignment_status_service_assignment_status_ToString(service_assignment_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_service_assignment_status__e service_assignment_status_parseFromJSON(cJSON *service_assignment_statusJSON) {
    if(!cJSON_IsString(service_assignment_statusJSON) || (service_assignment_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return service_assignment_status_service_assignment_status_FromString(service_assignment_statusJSON->valuestring);
}
