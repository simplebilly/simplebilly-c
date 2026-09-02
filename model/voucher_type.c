#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "voucher_type.h"


char* voucher_type_voucher_type_ToString(simplebilly_api_voucher_type__e voucher_type) {
    char *voucher_typeArray[] =  { "NULL", "invoice" };
    return voucher_typeArray[voucher_type];
}

simplebilly_api_voucher_type__e voucher_type_voucher_type_FromString(char* voucher_type) {
    int stringToReturn = 0;
    char *voucher_typeArray[] =  { "NULL", "invoice" };
    size_t sizeofArray = sizeof(voucher_typeArray) / sizeof(voucher_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(voucher_type, voucher_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *voucher_type_convertToJSON(simplebilly_api_voucher_type__e voucher_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "voucher_type", voucher_type_voucher_type_ToString(voucher_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_voucher_type__e voucher_type_parseFromJSON(cJSON *voucher_typeJSON) {
    if(!cJSON_IsString(voucher_typeJSON) || (voucher_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return voucher_type_voucher_type_FromString(voucher_typeJSON->valuestring);
}
