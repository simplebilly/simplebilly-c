#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "email_template_status.h"


char* email_template_status_email_template_status_ToString(simplebilly_api_email_template_status__e email_template_status) {
    char *email_template_statusArray[] =  { "NULL", "active", "inactive" };
    return email_template_statusArray[email_template_status];
}

simplebilly_api_email_template_status__e email_template_status_email_template_status_FromString(char* email_template_status) {
    int stringToReturn = 0;
    char *email_template_statusArray[] =  { "NULL", "active", "inactive" };
    size_t sizeofArray = sizeof(email_template_statusArray) / sizeof(email_template_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(email_template_status, email_template_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *email_template_status_convertToJSON(simplebilly_api_email_template_status__e email_template_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "email_template_status", email_template_status_email_template_status_ToString(email_template_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_email_template_status__e email_template_status_parseFromJSON(cJSON *email_template_statusJSON) {
    if(!cJSON_IsString(email_template_statusJSON) || (email_template_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return email_template_status_email_template_status_FromString(email_template_statusJSON->valuestring);
}
