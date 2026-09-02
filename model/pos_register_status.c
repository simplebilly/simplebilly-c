#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pos_register_status.h"


char* pos_register_status_pos_register_status_ToString(simplebilly_api_pos_register_status__e pos_register_status) {
    char *pos_register_statusArray[] =  { "NULL", "active", "disabled" };
    return pos_register_statusArray[pos_register_status];
}

simplebilly_api_pos_register_status__e pos_register_status_pos_register_status_FromString(char* pos_register_status) {
    int stringToReturn = 0;
    char *pos_register_statusArray[] =  { "NULL", "active", "disabled" };
    size_t sizeofArray = sizeof(pos_register_statusArray) / sizeof(pos_register_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(pos_register_status, pos_register_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *pos_register_status_convertToJSON(simplebilly_api_pos_register_status__e pos_register_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "pos_register_status", pos_register_status_pos_register_status_ToString(pos_register_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_pos_register_status__e pos_register_status_parseFromJSON(cJSON *pos_register_statusJSON) {
    if(!cJSON_IsString(pos_register_statusJSON) || (pos_register_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return pos_register_status_pos_register_status_FromString(pos_register_statusJSON->valuestring);
}
