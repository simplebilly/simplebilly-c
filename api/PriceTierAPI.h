#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/plugin_error.h"
#include "../model/price_tier.h"
#include "../model/price_tier_create.h"
#include "../model/price_tier_update.h"
#include "../model/resolved_price_response.h"


price_tier_t*
PriceTierAPI_createPriceTier(apiClient_t *apiClient, price_tier_create_t *price_tier_create);


void
PriceTierAPI_deletePriceTier(apiClient_t *apiClient, char *price_tier_id);


price_tier_t*
PriceTierAPI_getPriceTier(apiClient_t *apiClient, char *price_tier_id);


resolved_price_response_t*
PriceTierAPI_getResolvedPrice(apiClient_t *apiClient, char *productId, long quantity, char *contactId);


list_t*
PriceTierAPI_listPriceTiers(apiClient_t *apiClient, int *page, int *page_size, char *product_id, char *customer_group_id);


price_tier_t*
PriceTierAPI_updatePriceTier(apiClient_t *apiClient, char *price_tier_id, price_tier_update_t *price_tier_update);


