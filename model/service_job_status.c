#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "service_job_status.h"


char* service_job_status_service_job_status_ToString(simplebilly_api_service_job_status__e service_job_status) {
    char *service_job_statusArray[] =  { "NULL", "pending", "assigned", "en_route", "in_progress", "completed", "cancelled" };
    return service_job_statusArray[service_job_status];
}

simplebilly_api_service_job_status__e service_job_status_service_job_status_FromString(char* service_job_status) {
    int stringToReturn = 0;
    char *service_job_statusArray[] =  { "NULL", "pending", "assigned", "en_route", "in_progress", "completed", "cancelled" };
    size_t sizeofArray = sizeof(service_job_statusArray) / sizeof(service_job_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(service_job_status, service_job_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *service_job_status_convertToJSON(simplebilly_api_service_job_status__e service_job_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "service_job_status", service_job_status_service_job_status_ToString(service_job_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_service_job_status__e service_job_status_parseFromJSON(cJSON *service_job_statusJSON) {
    if(!cJSON_IsString(service_job_statusJSON) || (service_job_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return service_job_status_service_job_status_FromString(service_job_statusJSON->valuestring);
}
