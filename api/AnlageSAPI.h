#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/anlage_s_ergebnis.h"


anlage_s_ergebnis_t*
AnlageSAPI_anlageSApi(apiClient_t *apiClient, int *year);


