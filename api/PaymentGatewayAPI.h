#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/gateway_o_auth_authorize_request.h"
#include "../model/gateway_o_auth_authorize_response.h"
#include "../model/gateway_o_auth_callback_request.h"
#include "../model/payment_gateway.h"
#include "../model/plugin_error.h"


payment_gateway_t*
PaymentGatewayAPI_createPaymentGatewayApi(apiClient_t *apiClient, body);


void
PaymentGatewayAPI_deletePaymentGatewayApi(apiClient_t *apiClient, char *gateway_id);


list_t*
PaymentGatewayAPI_listPaymentGatewaysApi(apiClient_t *apiClient);


gateway_o_auth_authorize_response_t*
PaymentGatewayAPI_oauthAuthorizeApi(apiClient_t *apiClient, gateway_o_auth_authorize_request_t *gateway_o_auth_authorize_request);


payment_gateway_t*
PaymentGatewayAPI_oauthCallbackApi(apiClient_t *apiClient, gateway_o_auth_callback_request_t *gateway_o_auth_callback_request);


payment_gateway_t*
PaymentGatewayAPI_updatePaymentGatewayApi(apiClient_t *apiClient, char *gateway_id, body);


