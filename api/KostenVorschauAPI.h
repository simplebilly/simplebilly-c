#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/kosten_vorschau.h"


kosten_vorschau_t*
KostenVorschauAPI_kostenVorschauApi(apiClient_t *apiClient, int *year, int *month);


