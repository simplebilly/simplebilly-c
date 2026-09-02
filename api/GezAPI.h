#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/gez_report.h"


gez_report_t*
GezAPI_gezApi(apiClient_t *apiClient, int *jahr, char *betriebsstaetten, long kfz, long hotelzimmer, long beschaefigte);


