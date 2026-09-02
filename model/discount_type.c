#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "discount_type.h"


char* discount_type_discount_type_ToString(simplebilly_api_discount_type__e discount_type) {
    char *discount_typeArray[] =  { "NULL", "percentage", "fixed_amount" };
    return discount_typeArray[discount_type];
}

simplebilly_api_discount_type__e discount_type_discount_type_FromString(char* discount_type) {
    int stringToReturn = 0;
    char *discount_typeArray[] =  { "NULL", "percentage", "fixed_amount" };
    size_t sizeofArray = sizeof(discount_typeArray) / sizeof(discount_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(discount_type, discount_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *discount_type_convertToJSON(simplebilly_api_discount_type__e discount_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "discount_type", discount_type_discount_type_ToString(discount_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_discount_type__e discount_type_parseFromJSON(cJSON *discount_typeJSON) {
    if(!cJSON_IsString(discount_typeJSON) || (discount_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return discount_type_discount_type_FromString(discount_typeJSON->valuestring);
}
