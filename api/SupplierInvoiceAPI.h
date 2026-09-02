#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/plugin_error.h"
#include "../model/supplier_invoice.h"
#include "../model/supplier_invoice_status_update.h"


supplier_invoice_t*
SupplierInvoiceAPI_createSupplierInvoice(apiClient_t *apiClient, supplier_invoice_t *supplier_invoice);


void
SupplierInvoiceAPI_deleteSupplierInvoice(apiClient_t *apiClient, char *supplier_invoice_id);


supplier_invoice_t*
SupplierInvoiceAPI_getSupplierInvoice(apiClient_t *apiClient, char *supplier_invoice_id);


list_t*
SupplierInvoiceAPI_listSupplierInvoices(apiClient_t *apiClient, int *page, int *page_size, char *status, char *purchase_order_id, char *supplier_name);


supplier_invoice_t*
SupplierInvoiceAPI_updateSupplierInvoice(apiClient_t *apiClient, char *supplier_invoice_id, body);


supplier_invoice_t*
SupplierInvoiceAPI_updateSupplierInvoiceStatus(apiClient_t *apiClient, char *supplier_invoice_id, supplier_invoice_status_update_t *supplier_invoice_status_update);


