#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "company_type.h"


char* company_type_company_type_ToString(simplebilly_api_company_type__e company_type) {
    char *company_typeArray[] =  { "NULL", "gmbh", "ug", "einzelhaendler", "freiberufler", "ag", "gbr" };
    return company_typeArray[company_type];
}

simplebilly_api_company_type__e company_type_company_type_FromString(char* company_type) {
    int stringToReturn = 0;
    char *company_typeArray[] =  { "NULL", "gmbh", "ug", "einzelhaendler", "freiberufler", "ag", "gbr" };
    size_t sizeofArray = sizeof(company_typeArray) / sizeof(company_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(company_type, company_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *company_type_convertToJSON(simplebilly_api_company_type__e company_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "company_type", company_type_company_type_ToString(company_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_company_type__e company_type_parseFromJSON(cJSON *company_typeJSON) {
    if(!cJSON_IsString(company_typeJSON) || (company_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return company_type_company_type_FromString(company_typeJSON->valuestring);
}
