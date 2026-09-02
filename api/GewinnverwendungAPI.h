#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/gewinnverwendungs_export_response.h"
#include "../model/gewinnverwendungs_report.h"


gewinnverwendungs_report_t*
GewinnverwendungAPI_gewinnverwendungApi(apiClient_t *apiClient, int *year);


gewinnverwendungs_export_response_t*
GewinnverwendungAPI_gewinnverwendungExportApi(apiClient_t *apiClient, int *year);


