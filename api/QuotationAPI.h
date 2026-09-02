#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/order_confirmation.h"
#include "../model/plugin_error.h"
#include "../model/quotation.h"
#include "../model/quotation_create.h"


quotation_t*
QuotationAPI_createQuotation(apiClient_t *apiClient, quotation_create_t *quotation_create);


void
QuotationAPI_deleteQuotation(apiClient_t *apiClient, char *quotation_id);


void
QuotationAPI_downloadQuotationPdf(apiClient_t *apiClient, char *quotation_id);


quotation_t*
QuotationAPI_getQuotation(apiClient_t *apiClient, char *quotation_id);


list_t*
QuotationAPI_listQuotations(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


order_confirmation_t*
QuotationAPI_pursueQuotation(apiClient_t *apiClient, char *quotation_id);


quotation_t*
QuotationAPI_quotationRestore(apiClient_t *apiClient, char *quotation_id);


quotation_t*
QuotationAPI_updateQuotation(apiClient_t *apiClient, char *quotation_id, body);


