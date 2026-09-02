#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "severity.h"


char* severity_severity_ToString(simplebilly_api_severity__e severity) {
    char *severityArray[] =  { "NULL", "Info", "Warning", "Critical" };
    return severityArray[severity];
}

simplebilly_api_severity__e severity_severity_FromString(char* severity) {
    int stringToReturn = 0;
    char *severityArray[] =  { "NULL", "Info", "Warning", "Critical" };
    size_t sizeofArray = sizeof(severityArray) / sizeof(severityArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(severity, severityArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *severity_convertToJSON(simplebilly_api_severity__e severity) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "severity", severity_severity_ToString(severity)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_severity__e severity_parseFromJSON(cJSON *severityJSON) {
    if(!cJSON_IsString(severityJSON) || (severityJSON->valuestring == NULL)) {
        return 0;
    }
    return severity_severity_FromString(severityJSON->valuestring);
}
