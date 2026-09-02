#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "production_order_status.h"


char* production_order_status_production_order_status_ToString(simplebilly_api_production_order_status__e production_order_status) {
    char *production_order_statusArray[] =  { "NULL", "planned", "in_production", "completed", "cancelled" };
    return production_order_statusArray[production_order_status];
}

simplebilly_api_production_order_status__e production_order_status_production_order_status_FromString(char* production_order_status) {
    int stringToReturn = 0;
    char *production_order_statusArray[] =  { "NULL", "planned", "in_production", "completed", "cancelled" };
    size_t sizeofArray = sizeof(production_order_statusArray) / sizeof(production_order_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(production_order_status, production_order_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *production_order_status_convertToJSON(simplebilly_api_production_order_status__e production_order_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "production_order_status", production_order_status_production_order_status_ToString(production_order_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_production_order_status__e production_order_status_parseFromJSON(cJSON *production_order_statusJSON) {
    if(!cJSON_IsString(production_order_statusJSON) || (production_order_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return production_order_status_production_order_status_FromString(production_order_statusJSON->valuestring);
}
