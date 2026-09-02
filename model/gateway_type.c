#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gateway_type.h"


char* gateway_type_gateway_type_ToString(simplebilly_api_gateway_type__e gateway_type) {
    char *gateway_typeArray[] =  { "NULL", "stripe", "paypal", "klarna", "sofort", "bancontact", "ideal", "bank_transfer", "mollie", "bitpay", "braintree", "adyen", "paddle", "viva_wallet", "reepay", "sumup", "test" };
    return gateway_typeArray[gateway_type];
}

simplebilly_api_gateway_type__e gateway_type_gateway_type_FromString(char* gateway_type) {
    int stringToReturn = 0;
    char *gateway_typeArray[] =  { "NULL", "stripe", "paypal", "klarna", "sofort", "bancontact", "ideal", "bank_transfer", "mollie", "bitpay", "braintree", "adyen", "paddle", "viva_wallet", "reepay", "sumup", "test" };
    size_t sizeofArray = sizeof(gateway_typeArray) / sizeof(gateway_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(gateway_type, gateway_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *gateway_type_convertToJSON(simplebilly_api_gateway_type__e gateway_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "gateway_type", gateway_type_gateway_type_ToString(gateway_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_gateway_type__e gateway_type_parseFromJSON(cJSON *gateway_typeJSON) {
    if(!cJSON_IsString(gateway_typeJSON) || (gateway_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return gateway_type_gateway_type_FromString(gateway_typeJSON->valuestring);
}
