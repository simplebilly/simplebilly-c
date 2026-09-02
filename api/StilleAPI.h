#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/stille_export_response.h"
#include "../model/stille_report.h"


stille_export_response_t*
StilleAPI_stilleExportApi(apiClient_t *apiClient, int *year);


stille_report_t*
StilleAPI_stilleReportApi(apiClient_t *apiClient, int *year);


