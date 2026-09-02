#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "message_direction.h"


char* message_direction_message_direction_ToString(simplebilly_api_message_direction__e message_direction) {
    char *message_directionArray[] =  { "NULL", "inbound", "outbound", "internal" };
    return message_directionArray[message_direction];
}

simplebilly_api_message_direction__e message_direction_message_direction_FromString(char* message_direction) {
    int stringToReturn = 0;
    char *message_directionArray[] =  { "NULL", "inbound", "outbound", "internal" };
    size_t sizeofArray = sizeof(message_directionArray) / sizeof(message_directionArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(message_direction, message_directionArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *message_direction_convertToJSON(simplebilly_api_message_direction__e message_direction) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "message_direction", message_direction_message_direction_ToString(message_direction)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_message_direction__e message_direction_parseFromJSON(cJSON *message_directionJSON) {
    if(!cJSON_IsString(message_directionJSON) || (message_directionJSON->valuestring == NULL)) {
        return 0;
    }
    return message_direction_message_direction_FromString(message_directionJSON->valuestring);
}
