#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/plugin_error.h"
#include "../model/shipping_rule.h"
#include "../model/shipping_rule_create.h"
#include "../model/shipping_rule_update.h"


shipping_rule_t*
ShippingRuleAPI_createShippingRule(apiClient_t *apiClient, shipping_rule_create_t *shipping_rule_create);


void
ShippingRuleAPI_deleteShippingRule(apiClient_t *apiClient, char *rule_id);


shipping_rule_t*
ShippingRuleAPI_getShippingRule(apiClient_t *apiClient, char *rule_id);


list_t*
ShippingRuleAPI_listShippingRules(apiClient_t *apiClient, int *page, int *page_size, char *country);


shipping_rule_t*
ShippingRuleAPI_updateShippingRule(apiClient_t *apiClient, char *rule_id, shipping_rule_update_t *shipping_rule_update);


