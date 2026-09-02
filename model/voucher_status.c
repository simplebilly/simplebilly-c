#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "voucher_status.h"


char* voucher_status_voucher_status_ToString(simplebilly_api_voucher_status__e voucher_status) {
    char *voucher_statusArray[] =  { "NULL", "open", "paid", "invoiced" };
    return voucher_statusArray[voucher_status];
}

simplebilly_api_voucher_status__e voucher_status_voucher_status_FromString(char* voucher_status) {
    int stringToReturn = 0;
    char *voucher_statusArray[] =  { "NULL", "open", "paid", "invoiced" };
    size_t sizeofArray = sizeof(voucher_statusArray) / sizeof(voucher_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(voucher_status, voucher_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *voucher_status_convertToJSON(simplebilly_api_voucher_status__e voucher_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "voucher_status", voucher_status_voucher_status_ToString(voucher_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_voucher_status__e voucher_status_parseFromJSON(cJSON *voucher_statusJSON) {
    if(!cJSON_IsString(voucher_statusJSON) || (voucher_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return voucher_status_voucher_status_FromString(voucher_statusJSON->valuestring);
}
