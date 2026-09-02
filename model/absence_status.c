#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "absence_status.h"


char* absence_status_absence_status_ToString(simplebilly_api_absence_status__e absence_status) {
    char *absence_statusArray[] =  { "NULL", "pending", "approved", "rejected", "cancelled" };
    return absence_statusArray[absence_status];
}

simplebilly_api_absence_status__e absence_status_absence_status_FromString(char* absence_status) {
    int stringToReturn = 0;
    char *absence_statusArray[] =  { "NULL", "pending", "approved", "rejected", "cancelled" };
    size_t sizeofArray = sizeof(absence_statusArray) / sizeof(absence_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(absence_status, absence_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *absence_status_convertToJSON(simplebilly_api_absence_status__e absence_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "absence_status", absence_status_absence_status_ToString(absence_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_absence_status__e absence_status_parseFromJSON(cJSON *absence_statusJSON) {
    if(!cJSON_IsString(absence_statusJSON) || (absence_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return absence_status_absence_status_FromString(absence_statusJSON->valuestring);
}
