#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gender.h"


char* gender_gender_ToString(simplebilly_api_gender__e gender) {
    char *genderArray[] =  { "NULL", "male", "female", "diverse" };
    return genderArray[gender];
}

simplebilly_api_gender__e gender_gender_FromString(char* gender) {
    int stringToReturn = 0;
    char *genderArray[] =  { "NULL", "male", "female", "diverse" };
    size_t sizeofArray = sizeof(genderArray) / sizeof(genderArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(gender, genderArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *gender_convertToJSON(simplebilly_api_gender__e gender) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "gender", gender_gender_ToString(gender)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_gender__e gender_parseFromJSON(cJSON *genderJSON) {
    if(!cJSON_IsString(genderJSON) || (genderJSON->valuestring == NULL)) {
        return 0;
    }
    return gender_gender_FromString(genderJSON->valuestring);
}
