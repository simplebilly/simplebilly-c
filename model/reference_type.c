#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reference_type.h"


char* reference_type_reference_type_ToString(simplebilly_api_reference_type__e reference_type) {
    char *reference_typeArray[] =  { "NULL", "goods_receipt", "production_order", "transfer_in", "stock_transfer", "return_order", "inventory_count" };
    return reference_typeArray[reference_type];
}

simplebilly_api_reference_type__e reference_type_reference_type_FromString(char* reference_type) {
    int stringToReturn = 0;
    char *reference_typeArray[] =  { "NULL", "goods_receipt", "production_order", "transfer_in", "stock_transfer", "return_order", "inventory_count" };
    size_t sizeofArray = sizeof(reference_typeArray) / sizeof(reference_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(reference_type, reference_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *reference_type_convertToJSON(simplebilly_api_reference_type__e reference_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "reference_type", reference_type_reference_type_ToString(reference_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_reference_type__e reference_type_parseFromJSON(cJSON *reference_typeJSON) {
    if(!cJSON_IsString(reference_typeJSON) || (reference_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return reference_type_reference_type_FromString(reference_typeJSON->valuestring);
}
