#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "communication_direction.h"


char* communication_direction_communication_direction_ToString(simplebilly_api_communication_direction__e communication_direction) {
    char *communication_directionArray[] =  { "NULL", "inbound", "outbound" };
    return communication_directionArray[communication_direction];
}

simplebilly_api_communication_direction__e communication_direction_communication_direction_FromString(char* communication_direction) {
    int stringToReturn = 0;
    char *communication_directionArray[] =  { "NULL", "inbound", "outbound" };
    size_t sizeofArray = sizeof(communication_directionArray) / sizeof(communication_directionArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(communication_direction, communication_directionArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *communication_direction_convertToJSON(simplebilly_api_communication_direction__e communication_direction) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "communication_direction", communication_direction_communication_direction_ToString(communication_direction)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_communication_direction__e communication_direction_parseFromJSON(cJSON *communication_directionJSON) {
    if(!cJSON_IsString(communication_directionJSON) || (communication_directionJSON->valuestring == NULL)) {
        return 0;
    }
    return communication_direction_communication_direction_FromString(communication_directionJSON->valuestring);
}
