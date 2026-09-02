#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/plugin_error.h"
#include "../model/suitability_request.h"
#include "../model/suitability_result.h"


suitability_result_t*
SuitabilityAPI_shippingSuitabilityApi(apiClient_t *apiClient, suitability_request_t *suitability_request);


