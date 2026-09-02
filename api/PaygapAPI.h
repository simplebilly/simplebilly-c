#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/pay_gap_export_response.h"
#include "../model/pay_gap_info_response.h"
#include "../model/pay_gap_report.h"
#include "../model/plugin_error.h"


pay_gap_info_response_t*
PaygapAPI_paygapAuskunftApi(apiClient_t *apiClient, char *employee_id);


pay_gap_export_response_t*
PaygapAPI_paygapExportApi(apiClient_t *apiClient);


pay_gap_report_t*
PaygapAPI_paygapReportApi(apiClient_t *apiClient);


