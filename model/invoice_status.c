#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invoice_status.h"


char* invoice_status_invoice_status_ToString(simplebilly_api_invoice_status__e invoice_status) {
    char *invoice_statusArray[] =  { "NULL", "Draft", "Sent", "PartiallyPaid", "Paid", "Overdue", "Cancelled", "Credited", "Expired", "Dunning", "CollectDebt" };
    return invoice_statusArray[invoice_status];
}

simplebilly_api_invoice_status__e invoice_status_invoice_status_FromString(char* invoice_status) {
    int stringToReturn = 0;
    char *invoice_statusArray[] =  { "NULL", "Draft", "Sent", "PartiallyPaid", "Paid", "Overdue", "Cancelled", "Credited", "Expired", "Dunning", "CollectDebt" };
    size_t sizeofArray = sizeof(invoice_statusArray) / sizeof(invoice_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(invoice_status, invoice_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *invoice_status_convertToJSON(simplebilly_api_invoice_status__e invoice_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "invoice_status", invoice_status_invoice_status_ToString(invoice_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_invoice_status__e invoice_status_parseFromJSON(cJSON *invoice_statusJSON) {
    if(!cJSON_IsString(invoice_statusJSON) || (invoice_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return invoice_status_invoice_status_FromString(invoice_statusJSON->valuestring);
}
