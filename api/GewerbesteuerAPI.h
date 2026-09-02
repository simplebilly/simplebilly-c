#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/gewerbesteuer_ergebnis.h"


gewerbesteuer_ergebnis_t*
GewerbesteuerAPI_gewerbesteuerApi(apiClient_t *apiClient, int *year, char *hebesatz, char *gewerbeertrag, char *country, char *gemeindeschluessel);


