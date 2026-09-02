#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/fristen_ergebnis.h"


fristen_ergebnis_t*
FristenAPI_fristenApi(apiClient_t *apiClient, char *bundesland, char *voranmeldungsrhythmus, int *dauerfristverlaengerung, int *est_aktiv, int *gewst_aktiv, int *monate);


