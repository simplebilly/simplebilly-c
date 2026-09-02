#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "message_type.h"


char* message_type_message_type_ToString(simplebilly_api_message_type__e message_type) {
    char *message_typeArray[] =  { "NULL", "text", "html" };
    return message_typeArray[message_type];
}

simplebilly_api_message_type__e message_type_message_type_FromString(char* message_type) {
    int stringToReturn = 0;
    char *message_typeArray[] =  { "NULL", "text", "html" };
    size_t sizeofArray = sizeof(message_typeArray) / sizeof(message_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(message_type, message_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *message_type_convertToJSON(simplebilly_api_message_type__e message_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "message_type", message_type_message_type_ToString(message_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_message_type__e message_type_parseFromJSON(cJSON *message_typeJSON) {
    if(!cJSON_IsString(message_typeJSON) || (message_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return message_type_message_type_FromString(message_typeJSON->valuestring);
}
