#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/customer.h"
#include "../model/customer_create.h"
#include "../model/customer_update.h"
#include "../model/plugin_error.h"


customer_t*
CustomerAPI_createCustomer(apiClient_t *apiClient, customer_create_t *customer_create);


customer_t*
CustomerAPI_customerRestore(apiClient_t *apiClient, char *customer_id);


void
CustomerAPI_deleteCustomer(apiClient_t *apiClient, char *customer_id);


customer_t*
CustomerAPI_getCustomer(apiClient_t *apiClient, char *customer_id);


list_t*
CustomerAPI_getCustomers(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


customer_t*
CustomerAPI_updateCustomer(apiClient_t *apiClient, char *customer_id, customer_update_t *customer_update);


