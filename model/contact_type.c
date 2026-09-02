#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "contact_type.h"


char* contact_type_contact_type_ToString(simplebilly_api_contact_type__e contact_type) {
    char *contact_typeArray[] =  { "NULL", "customer", "supplier" };
    return contact_typeArray[contact_type];
}

simplebilly_api_contact_type__e contact_type_contact_type_FromString(char* contact_type) {
    int stringToReturn = 0;
    char *contact_typeArray[] =  { "NULL", "customer", "supplier" };
    size_t sizeofArray = sizeof(contact_typeArray) / sizeof(contact_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(contact_type, contact_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *contact_type_convertToJSON(simplebilly_api_contact_type__e contact_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "contact_type", contact_type_contact_type_ToString(contact_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_contact_type__e contact_type_parseFromJSON(cJSON *contact_typeJSON) {
    if(!cJSON_IsString(contact_typeJSON) || (contact_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return contact_type_contact_type_FromString(contact_typeJSON->valuestring);
}
