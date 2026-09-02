#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/allocate_payment_request.h"
#include "../model/bwa_report.h"
#include "../model/cashflow_report.h"
#include "../model/dunning_result.h"
#include "../model/elster_status.h"
#include "../model/invoice.h"
#include "../model/liquidity_position.h"
#include "../model/plugin_error.h"
#include "../model/verfahrensdokumentation.h"


// Allocate a payment to an invoice
//
void
BookkeepingAPI_allocatePaymentApi(apiClient_t *apiClient, allocate_payment_request_t *allocate_payment_request);


// Get BWA (Betriebswirtschaftliche Auswertung) report
//
bwa_report_t*
BookkeepingAPI_bwaReportApi(apiClient_t *apiClient, int *year, int *month);


elster_status_t*
BookkeepingAPI_elsterStatusApi(apiClient_t *apiClient);


void
BookkeepingAPI_elsterValidateApi(apiClient_t *apiClient, char *zeitraum);


void
BookkeepingAPI_elsterXmlApi(apiClient_t *apiClient, char *zeitraum);


// GET /api/v1/bookkeeping/cashflow Returns operating, investing, and financing cashflow for the given period.
//
cashflow_report_t*
BookkeepingAPI_getCashflow(apiClient_t *apiClient, int *year, int *month);


// GET /api/v1/bookkeeping/liquidity Returns current liquidity position with ratios.
//
liquidity_position_t*
BookkeepingAPI_getLiquidity(apiClient_t *apiClient);


// Get open invoices for a customer
//
list_t*
BookkeepingAPI_getOpenInvoicesApi(apiClient_t *apiClient, char *customer_id);


// GET /api/v1/bookkeeping/verfahrensdokumentation Returns the complete compliance catalog of all documented modules.
//
verfahrensdokumentation_t*
BookkeepingAPI_getVerfahrensdokumentation(apiClient_t *apiClient);


dunning_result_t*
BookkeepingAPI_runDunningApi(apiClient_t *apiClient);


