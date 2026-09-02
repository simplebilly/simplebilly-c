#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "document_type.h"


char* document_type_document_type_ToString(simplebilly_api_document_type__e document_type) {
    char *document_typeArray[] =  { "NULL", "invoice", "creditnote", "advancepayment", "downpaymentinvoice", "deliverynote", "orderconfirmation", "quotation", "proformainvoice" };
    return document_typeArray[document_type];
}

simplebilly_api_document_type__e document_type_document_type_FromString(char* document_type) {
    int stringToReturn = 0;
    char *document_typeArray[] =  { "NULL", "invoice", "creditnote", "advancepayment", "downpaymentinvoice", "deliverynote", "orderconfirmation", "quotation", "proformainvoice" };
    size_t sizeofArray = sizeof(document_typeArray) / sizeof(document_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(document_type, document_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *document_type_convertToJSON(simplebilly_api_document_type__e document_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "document_type", document_type_document_type_ToString(document_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_document_type__e document_type_parseFromJSON(cJSON *document_typeJSON) {
    if(!cJSON_IsString(document_typeJSON) || (document_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return document_type_document_type_FromString(document_typeJSON->valuestring);
}
