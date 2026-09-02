#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/import_job_status.h"
#include "../model/import_start_request.h"
#include "../model/import_start_response.h"
#include "../model/import_test_request.h"
#include "../model/import_test_response.h"
#include "../model/plugin_error.h"


import_job_status_t*
ImportRunnerAPI_getImportStatus(apiClient_t *apiClient, char *job_id);


import_start_response_t*
ImportRunnerAPI_startImport(apiClient_t *apiClient, import_start_request_t *import_start_request);


import_test_response_t*
ImportRunnerAPI_testImportConnection(apiClient_t *apiClient, import_test_request_t *import_test_request);


