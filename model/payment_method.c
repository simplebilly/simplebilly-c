#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "payment_method.h"


char* payment_method_payment_method_ToString(simplebilly_api_payment_method__e payment_method) {
    char *payment_methodArray[] =  { "NULL", "bank_transfer", "sepa_direct_debit", "cash", "credit_card", "paypal", "sumup", "viva_wallet", "reepay", "none" };
    return payment_methodArray[payment_method];
}

simplebilly_api_payment_method__e payment_method_payment_method_FromString(char* payment_method) {
    int stringToReturn = 0;
    char *payment_methodArray[] =  { "NULL", "bank_transfer", "sepa_direct_debit", "cash", "credit_card", "paypal", "sumup", "viva_wallet", "reepay", "none" };
    size_t sizeofArray = sizeof(payment_methodArray) / sizeof(payment_methodArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(payment_method, payment_methodArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *payment_method_convertToJSON(simplebilly_api_payment_method__e payment_method) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "payment_method", payment_method_payment_method_ToString(payment_method)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_payment_method__e payment_method_parseFromJSON(cJSON *payment_methodJSON) {
    if(!cJSON_IsString(payment_methodJSON) || (payment_methodJSON->valuestring == NULL)) {
        return 0;
    }
    return payment_method_payment_method_FromString(payment_methodJSON->valuestring);
}
