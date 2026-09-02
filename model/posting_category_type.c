#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "posting_category_type.h"


char* posting_category_type_posting_category_type_ToString(simplebilly_api_posting_category_type__e posting_category_type) {
    char *posting_category_typeArray[] =  { "NULL", "income", "expense" };
    return posting_category_typeArray[posting_category_type];
}

simplebilly_api_posting_category_type__e posting_category_type_posting_category_type_FromString(char* posting_category_type) {
    int stringToReturn = 0;
    char *posting_category_typeArray[] =  { "NULL", "income", "expense" };
    size_t sizeofArray = sizeof(posting_category_typeArray) / sizeof(posting_category_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(posting_category_type, posting_category_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *posting_category_type_convertToJSON(simplebilly_api_posting_category_type__e posting_category_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "posting_category_type", posting_category_type_posting_category_type_ToString(posting_category_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_posting_category_type__e posting_category_type_parseFromJSON(cJSON *posting_category_typeJSON) {
    if(!cJSON_IsString(posting_category_typeJSON) || (posting_category_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return posting_category_type_posting_category_type_FromString(posting_category_typeJSON->valuestring);
}
