#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/kst_ergebnis.h"


kst_ergebnis_t*
KstAPI_kstApi(apiClient_t *apiClient, int *year, char *gewinn);


