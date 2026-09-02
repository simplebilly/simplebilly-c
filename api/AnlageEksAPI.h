#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/eks_ergebnis.h"


eks_ergebnis_t*
AnlageEksAPI_eksApi(apiClient_t *apiClient, int *year);


