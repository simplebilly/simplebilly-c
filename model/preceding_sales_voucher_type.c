#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "preceding_sales_voucher_type.h"


char* preceding_sales_voucher_type_preceding_sales_voucher_type_ToString(simplebilly_api_preceding_sales_voucher_type__e preceding_sales_voucher_type) {
    char *preceding_sales_voucher_typeArray[] =  { "NULL", "order_confirmation", "quotation", "proforma_invoice" };
    return preceding_sales_voucher_typeArray[preceding_sales_voucher_type];
}

simplebilly_api_preceding_sales_voucher_type__e preceding_sales_voucher_type_preceding_sales_voucher_type_FromString(char* preceding_sales_voucher_type) {
    int stringToReturn = 0;
    char *preceding_sales_voucher_typeArray[] =  { "NULL", "order_confirmation", "quotation", "proforma_invoice" };
    size_t sizeofArray = sizeof(preceding_sales_voucher_typeArray) / sizeof(preceding_sales_voucher_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(preceding_sales_voucher_type, preceding_sales_voucher_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *preceding_sales_voucher_type_convertToJSON(simplebilly_api_preceding_sales_voucher_type__e preceding_sales_voucher_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "preceding_sales_voucher_type", preceding_sales_voucher_type_preceding_sales_voucher_type_ToString(preceding_sales_voucher_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_preceding_sales_voucher_type__e preceding_sales_voucher_type_parseFromJSON(cJSON *preceding_sales_voucher_typeJSON) {
    if(!cJSON_IsString(preceding_sales_voucher_typeJSON) || (preceding_sales_voucher_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return preceding_sales_voucher_type_preceding_sales_voucher_type_FromString(preceding_sales_voucher_typeJSON->valuestring);
}
