#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "supplier_invoice_status.h"


char* supplier_invoice_status_supplier_invoice_status_ToString(simplebilly_api_supplier_invoice_status__e supplier_invoice_status) {
    char *supplier_invoice_statusArray[] =  { "NULL", "draft", "matched", "has_variances", "posted", "cancelled" };
    return supplier_invoice_statusArray[supplier_invoice_status];
}

simplebilly_api_supplier_invoice_status__e supplier_invoice_status_supplier_invoice_status_FromString(char* supplier_invoice_status) {
    int stringToReturn = 0;
    char *supplier_invoice_statusArray[] =  { "NULL", "draft", "matched", "has_variances", "posted", "cancelled" };
    size_t sizeofArray = sizeof(supplier_invoice_statusArray) / sizeof(supplier_invoice_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(supplier_invoice_status, supplier_invoice_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *supplier_invoice_status_convertToJSON(simplebilly_api_supplier_invoice_status__e supplier_invoice_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "supplier_invoice_status", supplier_invoice_status_supplier_invoice_status_ToString(supplier_invoice_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_supplier_invoice_status__e supplier_invoice_status_parseFromJSON(cJSON *supplier_invoice_statusJSON) {
    if(!cJSON_IsString(supplier_invoice_statusJSON) || (supplier_invoice_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return supplier_invoice_status_supplier_invoice_status_FromString(supplier_invoice_statusJSON->valuestring);
}
