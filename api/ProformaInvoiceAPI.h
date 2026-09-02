#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/convert_response.h"
#include "../model/plugin_error.h"
#include "../model/proforma_invoice.h"


convert_response_t*
ProformaInvoiceAPI_convertProformaToInvoice(apiClient_t *apiClient, char *proforma_id);


proforma_invoice_t*
ProformaInvoiceAPI_createProformaInvoice(apiClient_t *apiClient, proforma_invoice_t *proforma_invoice);


void
ProformaInvoiceAPI_deleteProformaInvoice(apiClient_t *apiClient, char *proforma_id);


proforma_invoice_t*
ProformaInvoiceAPI_getProformaInvoice(apiClient_t *apiClient, char *proforma_id);


list_t*
ProformaInvoiceAPI_listProformaInvoices(apiClient_t *apiClient, int *page, int *page_size, char *status, char *customer_id, char *order_number);


proforma_invoice_t*
ProformaInvoiceAPI_updateProformaInvoice(apiClient_t *apiClient, char *proforma_id, body);


