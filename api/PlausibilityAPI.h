#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/plausibility_report.h"


plausibility_report_t*
PlausibilityAPI_plausibilityCheckApi(apiClient_t *apiClient, char *date_from, char *date_to);


