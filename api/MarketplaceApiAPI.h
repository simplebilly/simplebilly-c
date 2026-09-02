#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/create_connection_request.h"
#include "../model/marketplace_connection.h"
#include "../model/o_auth_authorize_request.h"
#include "../model/o_auth_authorize_response.h"
#include "../model/o_auth_callback_request.h"
#include "../model/platform_info.h"
#include "../model/sync_log.h"
#include "../model/sync_summary.h"
#include "../model/update_connection_request.h"
#include "../model/update_sync_direction_request.h"


// Create a new connection (for API-key based platforms)
//
marketplace_connection_t*
MarketplaceApiAPI_createConnectionApi(apiClient_t *apiClient, create_connection_request_t *create_connection_request);


// Soft-delete a connection
//
void
MarketplaceApiAPI_deleteConnectionApi(apiClient_t *apiClient, char *connection_id);


// Get a single connection
//
marketplace_connection_t*
MarketplaceApiAPI_getConnectionApi(apiClient_t *apiClient, char *connection_id);


// Get current sync direction configuration for a connection
//
void
MarketplaceApiAPI_getSyncDirectionApi(apiClient_t *apiClient, char *connection_id);


// Get sync logs for a connection
//
list_t*
MarketplaceApiAPI_getSyncLogsApi(apiClient_t *apiClient, char *connection_id);


// List connections for the current tenant
//
list_t*
MarketplaceApiAPI_listConnectionsApi(apiClient_t *apiClient);


// List all supported platforms
//
list_t*
MarketplaceApiAPI_listPlatformsApi(apiClient_t *apiClient);


// OAuth: initiate authorization flow
//
o_auth_authorize_response_t*
MarketplaceApiAPI_oauthAuthorizeApi(apiClient_t *apiClient, o_auth_authorize_request_t *o_auth_authorize_request);


// OAuth: handle callback after authorization
//
marketplace_connection_t*
MarketplaceApiAPI_oauthCallbackApi(apiClient_t *apiClient, o_auth_callback_request_t *o_auth_callback_request);


// Trigger sync for a connection
//
sync_summary_t*
MarketplaceApiAPI_triggerSyncApi(apiClient_t *apiClient, char *connection_id, char *sync_type, char *direction);


// Update a connection
//
marketplace_connection_t*
MarketplaceApiAPI_updateConnectionApi(apiClient_t *apiClient, char *connection_id, update_connection_request_t *update_connection_request);


// Update per-entity sync direction configuration for a connection
//
void
MarketplaceApiAPI_updateSyncDirectionApi(apiClient_t *apiClient, char *connection_id, update_sync_direction_request_t *update_sync_direction_request);


// Webhook receiver
//
void
MarketplaceApiAPI_webhookReceiverApi(apiClient_t *apiClient, char *platform, char *connection_id);


