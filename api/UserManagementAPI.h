#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/tenant_user.h"
#include "../model/update_permissions_payload.h"
#include "../model/update_role_payload.h"


tenant_user_t*
UserManagementAPI_getUser(apiClient_t *apiClient, char *user_id);


list_t*
UserManagementAPI_listUsers(apiClient_t *apiClient);


void
UserManagementAPI_removeUser(apiClient_t *apiClient, char *user_id);


void
UserManagementAPI_updateUserPermissions(apiClient_t *apiClient, char *user_id, update_permissions_payload_t *update_permissions_payload);


void
UserManagementAPI_updateUserRole(apiClient_t *apiClient, char *user_id, update_role_payload_t *update_role_payload);


