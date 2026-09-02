#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "application_status.h"


char* application_status_application_status_ToString(simplebilly_api_application_status__e application_status) {
    char *application_statusArray[] =  { "NULL", "new", "reviewing", "interview", "hired", "rejected" };
    return application_statusArray[application_status];
}

simplebilly_api_application_status__e application_status_application_status_FromString(char* application_status) {
    int stringToReturn = 0;
    char *application_statusArray[] =  { "NULL", "new", "reviewing", "interview", "hired", "rejected" };
    size_t sizeofArray = sizeof(application_statusArray) / sizeof(application_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(application_status, application_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *application_status_convertToJSON(simplebilly_api_application_status__e application_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "application_status", application_status_application_status_ToString(application_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_application_status__e application_status_parseFromJSON(cJSON *application_statusJSON) {
    if(!cJSON_IsString(application_statusJSON) || (application_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return application_status_application_status_FromString(application_statusJSON->valuestring);
}
