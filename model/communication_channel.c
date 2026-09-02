#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "communication_channel.h"


char* communication_channel_communication_channel_ToString(simplebilly_api_communication_channel__e communication_channel) {
    char *communication_channelArray[] =  { "NULL", "email", "call", "meeting", "chat", "note" };
    return communication_channelArray[communication_channel];
}

simplebilly_api_communication_channel__e communication_channel_communication_channel_FromString(char* communication_channel) {
    int stringToReturn = 0;
    char *communication_channelArray[] =  { "NULL", "email", "call", "meeting", "chat", "note" };
    size_t sizeofArray = sizeof(communication_channelArray) / sizeof(communication_channelArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(communication_channel, communication_channelArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *communication_channel_convertToJSON(simplebilly_api_communication_channel__e communication_channel) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "communication_channel", communication_channel_communication_channel_ToString(communication_channel)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_communication_channel__e communication_channel_parseFromJSON(cJSON *communication_channelJSON) {
    if(!cJSON_IsString(communication_channelJSON) || (communication_channelJSON->valuestring == NULL)) {
        return 0;
    }
    return communication_channel_communication_channel_FromString(communication_channelJSON->valuestring);
}
