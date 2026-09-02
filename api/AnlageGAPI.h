#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/anlage_g_ergebnis.h"


anlage_g_ergebnis_t*
AnlageGAPI_anlageGApi(apiClient_t *apiClient, int *year);


