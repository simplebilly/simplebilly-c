#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assignment_status.h"


char* assignment_status_assignment_status_ToString(simplebilly_api_assignment_status__e assignment_status) {
    char *assignment_statusArray[] =  { "NULL", "required", "completed", "overdue", "waived" };
    return assignment_statusArray[assignment_status];
}

simplebilly_api_assignment_status__e assignment_status_assignment_status_FromString(char* assignment_status) {
    int stringToReturn = 0;
    char *assignment_statusArray[] =  { "NULL", "required", "completed", "overdue", "waived" };
    size_t sizeofArray = sizeof(assignment_statusArray) / sizeof(assignment_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(assignment_status, assignment_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *assignment_status_convertToJSON(simplebilly_api_assignment_status__e assignment_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "assignment_status", assignment_status_assignment_status_ToString(assignment_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_assignment_status__e assignment_status_parseFromJSON(cJSON *assignment_statusJSON) {
    if(!cJSON_IsString(assignment_statusJSON) || (assignment_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return assignment_status_assignment_status_FromString(assignment_statusJSON->valuestring);
}
