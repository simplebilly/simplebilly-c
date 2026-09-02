#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/plugin_error.h"
#include "../model/supplier_condition.h"
#include "../model/supplier_condition_create.h"
#include "../model/supplier_condition_update.h"


supplier_condition_t*
SupplierConditionAPI_createSupplierCondition(apiClient_t *apiClient, supplier_condition_create_t *supplier_condition_create);


void
SupplierConditionAPI_deleteSupplierCondition(apiClient_t *apiClient, char *supplier_condition_id);


supplier_condition_t*
SupplierConditionAPI_getSupplierCondition(apiClient_t *apiClient, char *supplier_condition_id);


list_t*
SupplierConditionAPI_listSupplierConditions(apiClient_t *apiClient, int *page, int *page_size, char *supplier_contact_id, char *search);


supplier_condition_t*
SupplierConditionAPI_updateSupplierCondition(apiClient_t *apiClient, char *supplier_condition_id, supplier_condition_update_t *supplier_condition_update);


