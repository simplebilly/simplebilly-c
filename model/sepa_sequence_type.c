#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sepa_sequence_type.h"


char* sepa_sequence_type_sepa_sequence_type_ToString(simplebilly_api_sepa_sequence_type__e sepa_sequence_type) {
    char *sepa_sequence_typeArray[] =  { "NULL", "FRST", "RCUR", "FNAL", "OOFF" };
    return sepa_sequence_typeArray[sepa_sequence_type];
}

simplebilly_api_sepa_sequence_type__e sepa_sequence_type_sepa_sequence_type_FromString(char* sepa_sequence_type) {
    int stringToReturn = 0;
    char *sepa_sequence_typeArray[] =  { "NULL", "FRST", "RCUR", "FNAL", "OOFF" };
    size_t sizeofArray = sizeof(sepa_sequence_typeArray) / sizeof(sepa_sequence_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(sepa_sequence_type, sepa_sequence_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *sepa_sequence_type_convertToJSON(simplebilly_api_sepa_sequence_type__e sepa_sequence_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "sepa_sequence_type", sepa_sequence_type_sepa_sequence_type_ToString(sepa_sequence_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_sepa_sequence_type__e sepa_sequence_type_parseFromJSON(cJSON *sepa_sequence_typeJSON) {
    if(!cJSON_IsString(sepa_sequence_typeJSON) || (sepa_sequence_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return sepa_sequence_type_sepa_sequence_type_FromString(sepa_sequence_typeJSON->valuestring);
}
