#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/invoice.h"
#include "../model/invoice_create.h"
#include "../model/invoice_pdf_url_response.h"
#include "../model/plugin_error.h"


invoice_t*
InvoiceAPI_createInvoice(apiClient_t *apiClient, invoice_create_t *invoice_create);


void
InvoiceAPI_deleteInvoice(apiClient_t *apiClient, char *id);


void
InvoiceAPI_downloadInvoicePdf(apiClient_t *apiClient, char *id);


invoice_t*
InvoiceAPI_getInvoice(apiClient_t *apiClient, char *id);


invoice_pdf_url_response_t*
InvoiceAPI_getInvoicePdfUrl(apiClient_t *apiClient, char *id);


list_t*
InvoiceAPI_getInvoices(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


invoice_t*
InvoiceAPI_invoiceRestore(apiClient_t *apiClient, char *id);


invoice_t*
InvoiceAPI_updateInvoice(apiClient_t *apiClient, char *id, body);


