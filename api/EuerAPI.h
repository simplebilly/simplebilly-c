#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/euer_detail_ergebnis.h"
#include "../model/euer_ergebnis.h"


euer_ergebnis_t*
EuerAPI_euerApi(apiClient_t *apiClient, int *year);


euer_detail_ergebnis_t*
EuerAPI_euerKategorienApi(apiClient_t *apiClient, int *year);


