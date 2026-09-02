#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/customer_group.h"
#include "../model/customer_group_create.h"
#include "../model/customer_group_update.h"
#include "../model/plugin_error.h"


customer_group_t*
CustomerGroupAPI_addGroupMembers(apiClient_t *apiClient, char *customer_group_id, body);


customer_group_t*
CustomerGroupAPI_createCustomerGroup(apiClient_t *apiClient, customer_group_create_t *customer_group_create);


void
CustomerGroupAPI_deleteCustomerGroup(apiClient_t *apiClient, char *customer_group_id);


customer_group_t*
CustomerGroupAPI_getCustomerGroup(apiClient_t *apiClient, char *customer_group_id);


list_t*
CustomerGroupAPI_listCustomerGroups(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


customer_group_t*
CustomerGroupAPI_updateCustomerGroup(apiClient_t *apiClient, char *customer_group_id, customer_group_update_t *customer_group_update);


