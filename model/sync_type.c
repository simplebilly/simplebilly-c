#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sync_type.h"


char* sync_type_sync_type_ToString(simplebilly_api_sync_type__e sync_type) {
    char *sync_typeArray[] =  { "NULL", "orders", "products", "inventory", "invoices", "shipments", "contacts", "prices", "config", "branding", "legal" };
    return sync_typeArray[sync_type];
}

simplebilly_api_sync_type__e sync_type_sync_type_FromString(char* sync_type) {
    int stringToReturn = 0;
    char *sync_typeArray[] =  { "NULL", "orders", "products", "inventory", "invoices", "shipments", "contacts", "prices", "config", "branding", "legal" };
    size_t sizeofArray = sizeof(sync_typeArray) / sizeof(sync_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(sync_type, sync_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *sync_type_convertToJSON(simplebilly_api_sync_type__e sync_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "sync_type", sync_type_sync_type_ToString(sync_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_sync_type__e sync_type_parseFromJSON(cJSON *sync_typeJSON) {
    if(!cJSON_IsString(sync_typeJSON) || (sync_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return sync_type_sync_type_FromString(sync_typeJSON->valuestring);
}
