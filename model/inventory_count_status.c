#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inventory_count_status.h"


char* inventory_count_status_inventory_count_status_ToString(simplebilly_api_inventory_count_status__e inventory_count_status) {
    char *inventory_count_statusArray[] =  { "NULL", "draft", "counting", "reviewed", "posted" };
    return inventory_count_statusArray[inventory_count_status];
}

simplebilly_api_inventory_count_status__e inventory_count_status_inventory_count_status_FromString(char* inventory_count_status) {
    int stringToReturn = 0;
    char *inventory_count_statusArray[] =  { "NULL", "draft", "counting", "reviewed", "posted" };
    size_t sizeofArray = sizeof(inventory_count_statusArray) / sizeof(inventory_count_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(inventory_count_status, inventory_count_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *inventory_count_status_convertToJSON(simplebilly_api_inventory_count_status__e inventory_count_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "inventory_count_status", inventory_count_status_inventory_count_status_ToString(inventory_count_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_inventory_count_status__e inventory_count_status_parseFromJSON(cJSON *inventory_count_statusJSON) {
    if(!cJSON_IsString(inventory_count_statusJSON) || (inventory_count_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return inventory_count_status_inventory_count_status_FromString(inventory_count_statusJSON->valuestring);
}
