#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/plugin_error.h"
#include "../model/provider_info.h"
#include "../model/rate_request.h"
#include "../model/rate_response.h"
#include "../model/shipping_credentials.h"


shipping_credentials_t*
ShippingAPI_getCredentialsApi(apiClient_t *apiClient);


rate_response_t*
ShippingAPI_getRatesApi(apiClient_t *apiClient, rate_request_t *rate_request);


list_t*
ShippingAPI_listProvidersApi(apiClient_t *apiClient);


shipping_credentials_t*
ShippingAPI_saveCredentialsApi(apiClient_t *apiClient, shipping_credentials_t *shipping_credentials);


