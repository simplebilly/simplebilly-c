#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/konzern_export_response.h"
#include "../model/konzern_status.h"


konzern_export_response_t*
KonzernAPI_konzernExportApi(apiClient_t *apiClient, int *year);


konzern_status_t*
KonzernAPI_konzernStatusApi(apiClient_t *apiClient, int *year);


