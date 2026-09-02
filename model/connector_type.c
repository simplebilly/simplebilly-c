#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "connector_type.h"


char* connector_type_connector_type_ToString(simplebilly_api_connector_type__e connector_type) {
    char *connector_typeArray[] =  { "NULL", "apikey", "oauth" };
    return connector_typeArray[connector_type];
}

simplebilly_api_connector_type__e connector_type_connector_type_FromString(char* connector_type) {
    int stringToReturn = 0;
    char *connector_typeArray[] =  { "NULL", "apikey", "oauth" };
    size_t sizeofArray = sizeof(connector_typeArray) / sizeof(connector_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(connector_type, connector_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *connector_type_convertToJSON(simplebilly_api_connector_type__e connector_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "connector_type", connector_type_connector_type_ToString(connector_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_connector_type__e connector_type_parseFromJSON(cJSON *connector_typeJSON) {
    if(!cJSON_IsString(connector_typeJSON) || (connector_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return connector_type_connector_type_FromString(connector_typeJSON->valuestring);
}
