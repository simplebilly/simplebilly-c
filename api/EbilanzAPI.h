#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/e_bilanz_report.h"


e_bilanz_report_t*
EbilanzAPI_ebilanzReportApi(apiClient_t *apiClient, int *year, char *date_from, char *date_to);


void
EbilanzAPI_ebilanzXbrlExportApi(apiClient_t *apiClient, int *year, char *date_from, char *date_to);


