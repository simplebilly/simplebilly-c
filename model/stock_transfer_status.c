#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stock_transfer_status.h"


char* stock_transfer_status_stock_transfer_status_ToString(simplebilly_api_stock_transfer_status__e stock_transfer_status) {
    char *stock_transfer_statusArray[] =  { "NULL", "draft", "completed", "cancelled" };
    return stock_transfer_statusArray[stock_transfer_status];
}

simplebilly_api_stock_transfer_status__e stock_transfer_status_stock_transfer_status_FromString(char* stock_transfer_status) {
    int stringToReturn = 0;
    char *stock_transfer_statusArray[] =  { "NULL", "draft", "completed", "cancelled" };
    size_t sizeofArray = sizeof(stock_transfer_statusArray) / sizeof(stock_transfer_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(stock_transfer_status, stock_transfer_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *stock_transfer_status_convertToJSON(simplebilly_api_stock_transfer_status__e stock_transfer_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "stock_transfer_status", stock_transfer_status_stock_transfer_status_ToString(stock_transfer_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_stock_transfer_status__e stock_transfer_status_parseFromJSON(cJSON *stock_transfer_statusJSON) {
    if(!cJSON_IsString(stock_transfer_statusJSON) || (stock_transfer_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return stock_transfer_status_stock_transfer_status_FromString(stock_transfer_statusJSON->valuestring);
}
