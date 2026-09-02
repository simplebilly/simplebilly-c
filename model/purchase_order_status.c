#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "purchase_order_status.h"


char* purchase_order_status_purchase_order_status_ToString(simplebilly_api_purchase_order_status__e purchase_order_status) {
    char *purchase_order_statusArray[] =  { "NULL", "draft", "ordered", "partially_received", "received", "cancelled" };
    return purchase_order_statusArray[purchase_order_status];
}

simplebilly_api_purchase_order_status__e purchase_order_status_purchase_order_status_FromString(char* purchase_order_status) {
    int stringToReturn = 0;
    char *purchase_order_statusArray[] =  { "NULL", "draft", "ordered", "partially_received", "received", "cancelled" };
    size_t sizeofArray = sizeof(purchase_order_statusArray) / sizeof(purchase_order_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(purchase_order_status, purchase_order_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *purchase_order_status_convertToJSON(simplebilly_api_purchase_order_status__e purchase_order_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "purchase_order_status", purchase_order_status_purchase_order_status_ToString(purchase_order_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_purchase_order_status__e purchase_order_status_parseFromJSON(cJSON *purchase_order_statusJSON) {
    if(!cJSON_IsString(purchase_order_statusJSON) || (purchase_order_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return purchase_order_status_purchase_order_status_FromString(purchase_order_statusJSON->valuestring);
}
