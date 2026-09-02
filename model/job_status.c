#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "job_status.h"


char* job_status_job_status_ToString(simplebilly_api_job_status__e job_status) {
    char *job_statusArray[] =  { "NULL", "pending", "running", "done", "failed" };
    return job_statusArray[job_status];
}

simplebilly_api_job_status__e job_status_job_status_FromString(char* job_status) {
    int stringToReturn = 0;
    char *job_statusArray[] =  { "NULL", "pending", "running", "done", "failed" };
    size_t sizeofArray = sizeof(job_statusArray) / sizeof(job_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(job_status, job_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *job_status_convertToJSON(simplebilly_api_job_status__e job_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "job_status", job_status_job_status_ToString(job_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_job_status__e job_status_parseFromJSON(cJSON *job_statusJSON) {
    if(!cJSON_IsString(job_statusJSON) || (job_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return job_status_job_status_FromString(job_statusJSON->valuestring);
}
