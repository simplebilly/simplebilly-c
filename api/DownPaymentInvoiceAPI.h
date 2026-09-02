#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/down_payment_invoice.h"
#include "../model/plugin_error.h"


void
DownPaymentInvoiceAPI_downloadDownPaymentInvoicePdf(apiClient_t *apiClient, char *id);


down_payment_invoice_t*
DownPaymentInvoiceAPI_getDownPaymentInvoice(apiClient_t *apiClient, char *id);


list_t*
DownPaymentInvoiceAPI_listDownPaymentInvoices(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


