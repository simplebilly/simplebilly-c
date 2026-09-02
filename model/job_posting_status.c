#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "job_posting_status.h"


char* job_posting_status_job_posting_status_ToString(simplebilly_api_job_posting_status__e job_posting_status) {
    char *job_posting_statusArray[] =  { "NULL", "draft", "published", "closed" };
    return job_posting_statusArray[job_posting_status];
}

simplebilly_api_job_posting_status__e job_posting_status_job_posting_status_FromString(char* job_posting_status) {
    int stringToReturn = 0;
    char *job_posting_statusArray[] =  { "NULL", "draft", "published", "closed" };
    size_t sizeofArray = sizeof(job_posting_statusArray) / sizeof(job_posting_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(job_posting_status, job_posting_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *job_posting_status_convertToJSON(simplebilly_api_job_posting_status__e job_posting_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "job_posting_status", job_posting_status_job_posting_status_ToString(job_posting_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_job_posting_status__e job_posting_status_parseFromJSON(cJSON *job_posting_statusJSON) {
    if(!cJSON_IsString(job_posting_statusJSON) || (job_posting_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return job_posting_status_job_posting_status_FromString(job_posting_statusJSON->valuestring);
}
