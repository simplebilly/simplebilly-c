#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "payment_status.h"


char* payment_status_payment_status_ToString(simplebilly_api_payment_status__e payment_status) {
    char *payment_statusArray[] =  { "NULL", "unpaid", "paid" };
    return payment_statusArray[payment_status];
}

simplebilly_api_payment_status__e payment_status_payment_status_FromString(char* payment_status) {
    int stringToReturn = 0;
    char *payment_statusArray[] =  { "NULL", "unpaid", "paid" };
    size_t sizeofArray = sizeof(payment_statusArray) / sizeof(payment_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(payment_status, payment_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *payment_status_convertToJSON(simplebilly_api_payment_status__e payment_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "payment_status", payment_status_payment_status_ToString(payment_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_payment_status__e payment_status_parseFromJSON(cJSON *payment_statusJSON) {
    if(!cJSON_IsString(payment_statusJSON) || (payment_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return payment_status_payment_status_FromString(payment_statusJSON->valuestring);
}
