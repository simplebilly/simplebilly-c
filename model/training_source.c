#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "training_source.h"


char* training_source_training_source_ToString(simplebilly_api_training_source__e training_source) {
    char *training_sourceArray[] =  { "NULL", "builtin", "plugin" };
    return training_sourceArray[training_source];
}

simplebilly_api_training_source__e training_source_training_source_FromString(char* training_source) {
    int stringToReturn = 0;
    char *training_sourceArray[] =  { "NULL", "builtin", "plugin" };
    size_t sizeofArray = sizeof(training_sourceArray) / sizeof(training_sourceArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(training_source, training_sourceArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *training_source_convertToJSON(simplebilly_api_training_source__e training_source) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "training_source", training_source_training_source_ToString(training_source)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_training_source__e training_source_parseFromJSON(cJSON *training_sourceJSON) {
    if(!cJSON_IsString(training_sourceJSON) || (training_sourceJSON->valuestring == NULL)) {
        return 0;
    }
    return training_source_training_source_FromString(training_sourceJSON->valuestring);
}
