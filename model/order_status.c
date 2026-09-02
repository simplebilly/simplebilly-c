#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "order_status.h"


char* order_status_order_status_ToString(simplebilly_api_order_status__e order_status) {
    char *order_statusArray[] =  { "NULL", "pending", "ordered", "confirmed", "processing", "paid", "shipped", "completed", "closed", "cancelled", "refunded", "failed" };
    return order_statusArray[order_status];
}

simplebilly_api_order_status__e order_status_order_status_FromString(char* order_status) {
    int stringToReturn = 0;
    char *order_statusArray[] =  { "NULL", "pending", "ordered", "confirmed", "processing", "paid", "shipped", "completed", "closed", "cancelled", "refunded", "failed" };
    size_t sizeofArray = sizeof(order_statusArray) / sizeof(order_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(order_status, order_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *order_status_convertToJSON(simplebilly_api_order_status__e order_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "order_status", order_status_order_status_ToString(order_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_order_status__e order_status_parseFromJSON(cJSON *order_statusJSON) {
    if(!cJSON_IsString(order_statusJSON) || (order_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return order_status_order_status_FromString(order_statusJSON->valuestring);
}
