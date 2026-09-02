#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instrument_type.h"


char* instrument_type_instrument_type_ToString(simplebilly_api_instrument_type__e instrument_type) {
    char *instrument_typeArray[] =  { "NULL", "typisch", "atypisch" };
    return instrument_typeArray[instrument_type];
}

simplebilly_api_instrument_type__e instrument_type_instrument_type_FromString(char* instrument_type) {
    int stringToReturn = 0;
    char *instrument_typeArray[] =  { "NULL", "typisch", "atypisch" };
    size_t sizeofArray = sizeof(instrument_typeArray) / sizeof(instrument_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(instrument_type, instrument_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *instrument_type_convertToJSON(simplebilly_api_instrument_type__e instrument_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "instrument_type", instrument_type_instrument_type_ToString(instrument_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_instrument_type__e instrument_type_parseFromJSON(cJSON *instrument_typeJSON) {
    if(!cJSON_IsString(instrument_typeJSON) || (instrument_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return instrument_type_instrument_type_FromString(instrument_typeJSON->valuestring);
}
