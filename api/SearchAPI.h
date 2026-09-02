#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"


// GET /api/v1/search?q=...
//
any_type_t*
SearchAPI_globalSearch(apiClient_t *apiClient, char *q);


// GET /api/v1/me/permissions — resolved permissions from the auth token, used by the frontend to show/hide admin navigation.
//
any_type_t*
SearchAPI_myPermissions(apiClient_t *apiClient);


