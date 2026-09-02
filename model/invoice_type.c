#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invoice_type.h"


char* invoice_type_invoice_type_ToString(simplebilly_api_invoice_type__e invoice_type) {
    char *invoice_typeArray[] =  { "NULL", "Invoice", "CreditNote", "AdvancePayment", "FinalSettlement", "SpecialBilling", "DownPaymentInvoice", "Proforma", "Recurring", "CancellationInvoice" };
    return invoice_typeArray[invoice_type];
}

simplebilly_api_invoice_type__e invoice_type_invoice_type_FromString(char* invoice_type) {
    int stringToReturn = 0;
    char *invoice_typeArray[] =  { "NULL", "Invoice", "CreditNote", "AdvancePayment", "FinalSettlement", "SpecialBilling", "DownPaymentInvoice", "Proforma", "Recurring", "CancellationInvoice" };
    size_t sizeofArray = sizeof(invoice_typeArray) / sizeof(invoice_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(invoice_type, invoice_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *invoice_type_convertToJSON(simplebilly_api_invoice_type__e invoice_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "invoice_type", invoice_type_invoice_type_ToString(invoice_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_invoice_type__e invoice_type_parseFromJSON(cJSON *invoice_typeJSON) {
    if(!cJSON_IsString(invoice_typeJSON) || (invoice_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return invoice_type_invoice_type_FromString(invoice_typeJSON->valuestring);
}
