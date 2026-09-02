#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "check_status.h"


char* check_status_check_status_ToString(simplebilly_api_check_status__e check_status) {
    char *check_statusArray[] =  { "NULL", "Ok", "Warning", "Error" };
    return check_statusArray[check_status];
}

simplebilly_api_check_status__e check_status_check_status_FromString(char* check_status) {
    int stringToReturn = 0;
    char *check_statusArray[] =  { "NULL", "Ok", "Warning", "Error" };
    size_t sizeofArray = sizeof(check_statusArray) / sizeof(check_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(check_status, check_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *check_status_convertToJSON(simplebilly_api_check_status__e check_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "check_status", check_status_check_status_ToString(check_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_check_status__e check_status_parseFromJSON(cJSON *check_statusJSON) {
    if(!cJSON_IsString(check_statusJSON) || (check_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return check_status_check_status_FromString(check_statusJSON->valuestring);
}
