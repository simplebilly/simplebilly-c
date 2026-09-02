#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "employee_status.h"


char* employee_status_employee_status_ToString(simplebilly_api_employee_status__e employee_status) {
    char *employee_statusArray[] =  { "NULL", "active", "inactive", "terminated" };
    return employee_statusArray[employee_status];
}

simplebilly_api_employee_status__e employee_status_employee_status_FromString(char* employee_status) {
    int stringToReturn = 0;
    char *employee_statusArray[] =  { "NULL", "active", "inactive", "terminated" };
    size_t sizeofArray = sizeof(employee_statusArray) / sizeof(employee_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(employee_status, employee_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *employee_status_convertToJSON(simplebilly_api_employee_status__e employee_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "employee_status", employee_status_employee_status_ToString(employee_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_employee_status__e employee_status_parseFromJSON(cJSON *employee_statusJSON) {
    if(!cJSON_IsString(employee_statusJSON) || (employee_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return employee_status_employee_status_FromString(employee_statusJSON->valuestring);
}
