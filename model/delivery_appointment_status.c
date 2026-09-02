#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delivery_appointment_status.h"


char* delivery_appointment_status_delivery_appointment_status_ToString(simplebilly_api_delivery_appointment_status__e delivery_appointment_status) {
    char *delivery_appointment_statusArray[] =  { "NULL", "requested", "confirmed", "arrived", "cancelled", "completed" };
    return delivery_appointment_statusArray[delivery_appointment_status];
}

simplebilly_api_delivery_appointment_status__e delivery_appointment_status_delivery_appointment_status_FromString(char* delivery_appointment_status) {
    int stringToReturn = 0;
    char *delivery_appointment_statusArray[] =  { "NULL", "requested", "confirmed", "arrived", "cancelled", "completed" };
    size_t sizeofArray = sizeof(delivery_appointment_statusArray) / sizeof(delivery_appointment_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(delivery_appointment_status, delivery_appointment_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *delivery_appointment_status_convertToJSON(simplebilly_api_delivery_appointment_status__e delivery_appointment_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "delivery_appointment_status", delivery_appointment_status_delivery_appointment_status_ToString(delivery_appointment_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_delivery_appointment_status__e delivery_appointment_status_parseFromJSON(cJSON *delivery_appointment_statusJSON) {
    if(!cJSON_IsString(delivery_appointment_statusJSON) || (delivery_appointment_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return delivery_appointment_status_delivery_appointment_status_FromString(delivery_appointment_statusJSON->valuestring);
}
