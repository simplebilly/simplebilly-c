#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/datev_booking_preview.h"
#include "../model/datev_export_response.h"


// Export bookkeeping data as DATEV CSV
//
datev_export_response_t*
DatevAPI_datevExportApi(apiClient_t *apiClient, char *account_schema, char *date_from, char *date_to, int *page, int *page_size);


// Exported_datev_bookings: returns formed bookings for review
//
list_t*
DatevAPI_datevPreviewApi(apiClient_t *apiClient, char *account_schema, char *date_from, char *date_to, int *page, int *page_size);


