#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delivery_date_status.h"


char* delivery_date_status_delivery_date_status_ToString(simplebilly_api_delivery_date_status__e delivery_date_status) {
    char *delivery_date_statusArray[] =  { "NULL", "promised", "confirmed", "rescheduled", "fulfilled", "late", "cancelled" };
    return delivery_date_statusArray[delivery_date_status];
}

simplebilly_api_delivery_date_status__e delivery_date_status_delivery_date_status_FromString(char* delivery_date_status) {
    int stringToReturn = 0;
    char *delivery_date_statusArray[] =  { "NULL", "promised", "confirmed", "rescheduled", "fulfilled", "late", "cancelled" };
    size_t sizeofArray = sizeof(delivery_date_statusArray) / sizeof(delivery_date_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(delivery_date_status, delivery_date_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *delivery_date_status_convertToJSON(simplebilly_api_delivery_date_status__e delivery_date_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "delivery_date_status", delivery_date_status_delivery_date_status_ToString(delivery_date_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_delivery_date_status__e delivery_date_status_parseFromJSON(cJSON *delivery_date_statusJSON) {
    if(!cJSON_IsString(delivery_date_statusJSON) || (delivery_date_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return delivery_date_status_delivery_date_status_FromString(delivery_date_statusJSON->valuestring);
}
