#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "proforma_invoice_status.h"


char* proforma_invoice_status_proforma_invoice_status_ToString(simplebilly_api_proforma_invoice_status__e proforma_invoice_status) {
    char *proforma_invoice_statusArray[] =  { "NULL", "draft", "sent", "converted" };
    return proforma_invoice_statusArray[proforma_invoice_status];
}

simplebilly_api_proforma_invoice_status__e proforma_invoice_status_proforma_invoice_status_FromString(char* proforma_invoice_status) {
    int stringToReturn = 0;
    char *proforma_invoice_statusArray[] =  { "NULL", "draft", "sent", "converted" };
    size_t sizeofArray = sizeof(proforma_invoice_statusArray) / sizeof(proforma_invoice_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(proforma_invoice_status, proforma_invoice_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *proforma_invoice_status_convertToJSON(simplebilly_api_proforma_invoice_status__e proforma_invoice_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "proforma_invoice_status", proforma_invoice_status_proforma_invoice_status_ToString(proforma_invoice_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_proforma_invoice_status__e proforma_invoice_status_parseFromJSON(cJSON *proforma_invoice_statusJSON) {
    if(!cJSON_IsString(proforma_invoice_statusJSON) || (proforma_invoice_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return proforma_invoice_status_proforma_invoice_status_FromString(proforma_invoice_statusJSON->valuestring);
}
