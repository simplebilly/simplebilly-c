#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/plugin_error.h"
#include "../model/shareholder.h"
#include "../model/shareholder_create.h"
#include "../model/shareholder_update.h"


shareholder_t*
ShareholderAPI_createShareholder(apiClient_t *apiClient, shareholder_create_t *shareholder_create);


void
ShareholderAPI_deleteShareholder(apiClient_t *apiClient, char *id);


shareholder_t*
ShareholderAPI_getShareholder(apiClient_t *apiClient, char *id);


list_t*
ShareholderAPI_getShareholders(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


shareholder_t*
ShareholderAPI_updateShareholder(apiClient_t *apiClient, char *id, shareholder_update_t *shareholder_update);


