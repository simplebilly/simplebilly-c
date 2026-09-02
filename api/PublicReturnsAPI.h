#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/plugin_error.h"
#include "../model/public_return_request.h"
#include "../model/public_return_response.h"
#include "../model/public_return_status_response.h"


// Customer checks the status of a return (public, no auth). The return is only revealed when its linked order's email matches.
//
public_return_status_response_t*
PublicReturnsAPI_getPublicReturnStatus(apiClient_t *apiClient, char *email, char *returnNumber, char *returnOrderId, char *orderNumber);


// List all returns for an order (public, no auth).
//
list_t*
PublicReturnsAPI_listPublicReturns(apiClient_t *apiClient, char *orderNumber, char *email);


// Customer requests a return for an order (public, no auth).
//
public_return_response_t*
PublicReturnsAPI_requestPublicReturn(apiClient_t *apiClient, public_return_request_t *public_return_request);


