#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "return_order_status.h"


char* return_order_status_return_order_status_ToString(simplebilly_api_return_order_status__e return_order_status) {
    char *return_order_statusArray[] =  { "NULL", "requested", "received", "inspected", "restocked", "closed" };
    return return_order_statusArray[return_order_status];
}

simplebilly_api_return_order_status__e return_order_status_return_order_status_FromString(char* return_order_status) {
    int stringToReturn = 0;
    char *return_order_statusArray[] =  { "NULL", "requested", "received", "inspected", "restocked", "closed" };
    size_t sizeofArray = sizeof(return_order_statusArray) / sizeof(return_order_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(return_order_status, return_order_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *return_order_status_convertToJSON(simplebilly_api_return_order_status__e return_order_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "return_order_status", return_order_status_return_order_status_ToString(return_order_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_return_order_status__e return_order_status_parseFromJSON(cJSON *return_order_statusJSON) {
    if(!cJSON_IsString(return_order_statusJSON) || (return_order_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return return_order_status_return_order_status_FromString(return_order_statusJSON->valuestring);
}
