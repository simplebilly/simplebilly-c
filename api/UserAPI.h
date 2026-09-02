#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_response_string.h"
#include "../model/api_response_team.h"
#include "../model/api_response_user_profile.h"
#include "../model/api_response_vec_team.h"
#include "../model/api_response_vec_user_tenant_info.h"
#include "../model/change_password_request.h"
#include "../model/invite_request.h"
#include "../model/remove_user_request.h"
#include "../model/team_create.h"
#include "../model/update_profile_request.h"


// Change the current user's password (requires the current password).
//
void
UserAPI_changePassword(apiClient_t *apiClient, change_password_request_t *change_password_request);


// Create a new team within the current tenant
//
api_response_team_t*
UserAPI_createTeam(apiClient_t *apiClient, team_create_t *team_create);


// Generate a new API key for the current user
//
api_response_string_t*
UserAPI_generateApiKey(apiClient_t *apiClient);


// Invite a user to the current tenant/organization
//
void
UserAPI_inviteUser(apiClient_t *apiClient, invite_request_t *invite_request);


// List all teams in the current tenant
//
api_response_vec_team_t*
UserAPI_listTeams(apiClient_t *apiClient);


// Remove a user from the current organization
//
void
UserAPI_removeUserFromOrg(apiClient_t *apiClient, remove_user_request_t *remove_user_request);


// Update the current user's profile
//
void
UserAPI_updateProfile(apiClient_t *apiClient, update_profile_request_t *update_profile_request);


// Get the current user's profile
//
api_response_user_profile_t*
UserAPI_userProfile(apiClient_t *apiClient);


// List all tenants (organizations) the current user belongs to
//
api_response_vec_user_tenant_info_t*
UserAPI_userTenants(apiClient_t *apiClient);


