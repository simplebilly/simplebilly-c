#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "recurring_template_type.h"


char* recurring_template_type_recurring_template_type_ToString(simplebilly_api_recurring_template_type__e recurring_template_type) {
    char *recurring_template_typeArray[] =  { "NULL", "invoice", "report" };
    return recurring_template_typeArray[recurring_template_type];
}

simplebilly_api_recurring_template_type__e recurring_template_type_recurring_template_type_FromString(char* recurring_template_type) {
    int stringToReturn = 0;
    char *recurring_template_typeArray[] =  { "NULL", "invoice", "report" };
    size_t sizeofArray = sizeof(recurring_template_typeArray) / sizeof(recurring_template_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(recurring_template_type, recurring_template_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *recurring_template_type_convertToJSON(simplebilly_api_recurring_template_type__e recurring_template_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "recurring_template_type", recurring_template_type_recurring_template_type_ToString(recurring_template_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_recurring_template_type__e recurring_template_type_parseFromJSON(cJSON *recurring_template_typeJSON) {
    if(!cJSON_IsString(recurring_template_typeJSON) || (recurring_template_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return recurring_template_type_recurring_template_type_FromString(recurring_template_typeJSON->valuestring);
}
