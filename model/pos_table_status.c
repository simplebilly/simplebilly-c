#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pos_table_status.h"


char* pos_table_status_pos_table_status_ToString(simplebilly_api_pos_table_status__e pos_table_status) {
    char *pos_table_statusArray[] =  { "NULL", "free", "occupied" };
    return pos_table_statusArray[pos_table_status];
}

simplebilly_api_pos_table_status__e pos_table_status_pos_table_status_FromString(char* pos_table_status) {
    int stringToReturn = 0;
    char *pos_table_statusArray[] =  { "NULL", "free", "occupied" };
    size_t sizeofArray = sizeof(pos_table_statusArray) / sizeof(pos_table_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(pos_table_status, pos_table_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *pos_table_status_convertToJSON(simplebilly_api_pos_table_status__e pos_table_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "pos_table_status", pos_table_status_pos_table_status_ToString(pos_table_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_pos_table_status__e pos_table_status_parseFromJSON(cJSON *pos_table_statusJSON) {
    if(!cJSON_IsString(pos_table_statusJSON) || (pos_table_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return pos_table_status_pos_table_status_FromString(pos_table_statusJSON->valuestring);
}
