#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "declaration_type.h"


char* declaration_type_declaration_type_ToString(simplebilly_api_declaration_type__e declaration_type) {
    char *declaration_typeArray[] =  { "NULL", "dcgk", "unternehmensfuehrung" };
    return declaration_typeArray[declaration_type];
}

simplebilly_api_declaration_type__e declaration_type_declaration_type_FromString(char* declaration_type) {
    int stringToReturn = 0;
    char *declaration_typeArray[] =  { "NULL", "dcgk", "unternehmensfuehrung" };
    size_t sizeofArray = sizeof(declaration_typeArray) / sizeof(declaration_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(declaration_type, declaration_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *declaration_type_convertToJSON(simplebilly_api_declaration_type__e declaration_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "declaration_type", declaration_type_declaration_type_ToString(declaration_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_declaration_type__e declaration_type_parseFromJSON(cJSON *declaration_typeJSON) {
    if(!cJSON_IsString(declaration_typeJSON) || (declaration_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return declaration_type_declaration_type_FromString(declaration_typeJSON->valuestring);
}
