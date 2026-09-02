#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/peppol_response.h"


peppol_response_t*
PeppolAPI_peppolApi(apiClient_t *apiClient, char *id);


