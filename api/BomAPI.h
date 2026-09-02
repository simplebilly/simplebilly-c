#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/bom.h"
#include "../model/bom_create.h"
#include "../model/bom_update.h"
#include "../model/plugin_error.h"


bom_t*
BomAPI_createBom(apiClient_t *apiClient, bom_create_t *bom_create);


void
BomAPI_deleteBom(apiClient_t *apiClient, char *bom_id);


bom_t*
BomAPI_getBom(apiClient_t *apiClient, char *bom_id);


list_t*
BomAPI_listBoms(apiClient_t *apiClient, int *page, int *pageSize, char *search, char *productId);


bom_t*
BomAPI_updateBom(apiClient_t *apiClient, char *bom_id, bom_update_t *bom_update);


