#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bom_status.h"


char* bom_status_bom_status_ToString(simplebilly_api_bom_status__e bom_status) {
    char *bom_statusArray[] =  { "NULL", "draft", "active", "archived" };
    return bom_statusArray[bom_status];
}

simplebilly_api_bom_status__e bom_status_bom_status_FromString(char* bom_status) {
    int stringToReturn = 0;
    char *bom_statusArray[] =  { "NULL", "draft", "active", "archived" };
    size_t sizeofArray = sizeof(bom_statusArray) / sizeof(bom_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(bom_status, bom_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *bom_status_convertToJSON(simplebilly_api_bom_status__e bom_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "bom_status", bom_status_bom_status_ToString(bom_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_bom_status__e bom_status_parseFromJSON(cJSON *bom_statusJSON) {
    if(!cJSON_IsString(bom_statusJSON) || (bom_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return bom_status_bom_status_FromString(bom_statusJSON->valuestring);
}
