#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/jahres_ust_ergebnis.h"
#include "../model/ustva_ergebnis.h"


jahres_ust_ergebnis_t*
UstvaAPI_jahresustApi(apiClient_t *apiClient, int *year);


ustva_ergebnis_t*
UstvaAPI_ustvaApi(apiClient_t *apiClient, char *zeitraum);


