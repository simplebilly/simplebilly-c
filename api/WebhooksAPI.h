#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/create_subscription_request.h"
#include "../model/emit_event_request.h"
#include "../model/plugin_error.h"
#include "../model/update_subscription_request.h"
#include "../model/webhook_event.h"
#include "../model/webhook_subscription.h"


// Create a webhook subscription (outbound hook).
//
webhook_subscription_t*
WebhooksAPI_createSubscription(apiClient_t *apiClient, create_subscription_request_t *create_subscription_request);


// Delete a webhook subscription.
//
void
WebhooksAPI_deleteSubscription(apiClient_t *apiClient, char *subscription_id);


// Manually fire an event against matching hooks (for testing/flows).
//
void
WebhooksAPI_emitApi(apiClient_t *apiClient, emit_event_request_t *emit_event_request);


// List webhook events (inbound + outbound log).
//
list_t*
WebhooksAPI_listEvent(apiClient_t *apiClient);


// List webhook subscriptions for the tenant.
//
list_t*
WebhooksAPI_listSubscriptions(apiClient_t *apiClient);


// Update a webhook subscription.
//
webhook_subscription_t*
WebhooksAPI_updateSubscription(apiClient_t *apiClient, char *subscription_id, update_subscription_request_t *update_subscription_request);


