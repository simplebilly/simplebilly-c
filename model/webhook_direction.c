#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "webhook_direction.h"


char* webhook_direction_webhook_direction_ToString(simplebilly_api_webhook_direction__e webhook_direction) {
    char *webhook_directionArray[] =  { "NULL", "inbound", "outbound" };
    return webhook_directionArray[webhook_direction];
}

simplebilly_api_webhook_direction__e webhook_direction_webhook_direction_FromString(char* webhook_direction) {
    int stringToReturn = 0;
    char *webhook_directionArray[] =  { "NULL", "inbound", "outbound" };
    size_t sizeofArray = sizeof(webhook_directionArray) / sizeof(webhook_directionArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(webhook_direction, webhook_directionArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *webhook_direction_convertToJSON(simplebilly_api_webhook_direction__e webhook_direction) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "webhook_direction", webhook_direction_webhook_direction_ToString(webhook_direction)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_webhook_direction__e webhook_direction_parseFromJSON(cJSON *webhook_directionJSON) {
    if(!cJSON_IsString(webhook_directionJSON) || (webhook_directionJSON->valuestring == NULL)) {
        return 0;
    }
    return webhook_direction_webhook_direction_FromString(webhook_directionJSON->valuestring);
}
