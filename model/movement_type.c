#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "movement_type.h"


char* movement_type_movement_type_ToString(simplebilly_api_movement_type__e movement_type) {
    char *movement_typeArray[] =  { "NULL", "goods_receipt", "goods_receipt_reversal", "transfer_in", "transfer_out", "return_restock", "production_consumption", "production_completion", "inventory_adjustment", "sale", "other" };
    return movement_typeArray[movement_type];
}

simplebilly_api_movement_type__e movement_type_movement_type_FromString(char* movement_type) {
    int stringToReturn = 0;
    char *movement_typeArray[] =  { "NULL", "goods_receipt", "goods_receipt_reversal", "transfer_in", "transfer_out", "return_restock", "production_consumption", "production_completion", "inventory_adjustment", "sale", "other" };
    size_t sizeofArray = sizeof(movement_typeArray) / sizeof(movement_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(movement_type, movement_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *movement_type_convertToJSON(simplebilly_api_movement_type__e movement_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "movement_type", movement_type_movement_type_ToString(movement_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_movement_type__e movement_type_parseFromJSON(cJSON *movement_typeJSON) {
    if(!cJSON_IsString(movement_typeJSON) || (movement_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return movement_type_movement_type_FromString(movement_typeJSON->valuestring);
}
