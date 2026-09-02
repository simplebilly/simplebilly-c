#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "support_channel_type.h"


char* support_channel_type_support_channel_type_ToString(simplebilly_api_support_channel_type__e support_channel_type) {
    char *support_channel_typeArray[] =  { "NULL", "email", "chat" };
    return support_channel_typeArray[support_channel_type];
}

simplebilly_api_support_channel_type__e support_channel_type_support_channel_type_FromString(char* support_channel_type) {
    int stringToReturn = 0;
    char *support_channel_typeArray[] =  { "NULL", "email", "chat" };
    size_t sizeofArray = sizeof(support_channel_typeArray) / sizeof(support_channel_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(support_channel_type, support_channel_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *support_channel_type_convertToJSON(simplebilly_api_support_channel_type__e support_channel_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "support_channel_type", support_channel_type_support_channel_type_ToString(support_channel_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_support_channel_type__e support_channel_type_parseFromJSON(cJSON *support_channel_typeJSON) {
    if(!cJSON_IsString(support_channel_typeJSON) || (support_channel_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return support_channel_type_support_channel_type_FromString(support_channel_typeJSON->valuestring);
}
