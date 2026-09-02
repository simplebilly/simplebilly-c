#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/event_subscription.h"
#include "../model/plugin_error.h"


event_subscription_t*
EventSubscriptionAPI_createEventSubscription(apiClient_t *apiClient, body);


void
EventSubscriptionAPI_deleteEventSubscription(apiClient_t *apiClient, char *subscription_id);


list_t*
EventSubscriptionAPI_listEventSubscriptions(apiClient_t *apiClient);


