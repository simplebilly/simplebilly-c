#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "legal_doc_type.h"


char* legal_doc_type_legal_doc_type_ToString(simplebilly_api_legal_doc_type__e legal_doc_type) {
    char *legal_doc_typeArray[] =  { "NULL", "imprint", "privacy", "terms", "withdrawal", "refund", "shipping", "gpsr", "cookie_notice" };
    return legal_doc_typeArray[legal_doc_type];
}

simplebilly_api_legal_doc_type__e legal_doc_type_legal_doc_type_FromString(char* legal_doc_type) {
    int stringToReturn = 0;
    char *legal_doc_typeArray[] =  { "NULL", "imprint", "privacy", "terms", "withdrawal", "refund", "shipping", "gpsr", "cookie_notice" };
    size_t sizeofArray = sizeof(legal_doc_typeArray) / sizeof(legal_doc_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(legal_doc_type, legal_doc_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *legal_doc_type_convertToJSON(simplebilly_api_legal_doc_type__e legal_doc_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "legal_doc_type", legal_doc_type_legal_doc_type_ToString(legal_doc_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_legal_doc_type__e legal_doc_type_parseFromJSON(cJSON *legal_doc_typeJSON) {
    if(!cJSON_IsString(legal_doc_typeJSON) || (legal_doc_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return legal_doc_type_legal_doc_type_FromString(legal_doc_typeJSON->valuestring);
}
