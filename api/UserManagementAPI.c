#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "UserManagementAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


tenant_user_t*
UserManagementAPI_getUser(apiClient_t *apiClient, char *user_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/api/v1/users/{user_id}");

    if(!user_id)
        goto end;


    // Path Params
    long sizeOfPathParams_user_id = strlen(user_id)+3 + sizeof("{ user_id }") - 1;
    if(user_id == NULL) {
        goto end;
    }
    char* localVarToReplace_user_id = malloc(sizeOfPathParams_user_id);
    sprintf(localVarToReplace_user_id, "{%s}", "user_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_user_id, user_id);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
    //}
    //nonprimitive not container
    tenant_user_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *UserManagementAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = tenant_user_parseFromJSON(UserManagementAPIlocalVarJSON);
        cJSON_Delete(UserManagementAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_user_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

list_t*
UserManagementAPI_listUsers(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/api/v1/users");




    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *UserManagementAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(UserManagementAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, UserManagementAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( UserManagementAPIlocalVarJSON);
        cJSON_Delete( VarJSON);
    }
    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

void
UserManagementAPI_removeUser(apiClient_t *apiClient, char *user_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = NULL;
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/api/v1/users/{user_id}");

    if(!user_id)
        goto end;


    // Path Params
    long sizeOfPathParams_user_id = strlen(user_id)+3 + sizeof("{ user_id }") - 1;
    if(user_id == NULL) {
        goto end;
    }
    char* localVarToReplace_user_id = malloc(sizeOfPathParams_user_id);
    sprintf(localVarToReplace_user_id, "{%s}", "user_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_user_id, user_id);


    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "DELETE");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","No Content");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    
    
    free(localVarPath);
    free(localVarToReplace_user_id);

}

void
UserManagementAPI_updateUserPermissions(apiClient_t *apiClient, char *user_id, update_permissions_payload_t *update_permissions_payload)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = NULL;
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/api/v1/users/{user_id}/permissions");

    if(!user_id)
        goto end;


    // Path Params
    long sizeOfPathParams_user_id = strlen(user_id)+3 + sizeof("{ user_id }") - 1;
    if(user_id == NULL) {
        goto end;
    }
    char* localVarToReplace_user_id = malloc(sizeOfPathParams_user_id);
    sprintf(localVarToReplace_user_id, "{%s}", "user_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_user_id, user_id);



    // Body Param
    cJSON *localVarSingleItemJSON_update_permissions_payload = NULL;
    if (update_permissions_payload != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_update_permissions_payload = update_permissions_payload_convertToJSON(update_permissions_payload);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_update_permissions_payload);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "PUT");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_user_id);
    if (localVarSingleItemJSON_update_permissions_payload) {
        cJSON_Delete(localVarSingleItemJSON_update_permissions_payload);
        localVarSingleItemJSON_update_permissions_payload = NULL;
    }
    free(localVarBodyParameters);

}

void
UserManagementAPI_updateUserRole(apiClient_t *apiClient, char *user_id, update_role_payload_t *update_role_payload)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = NULL;
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/api/v1/users/{user_id}/role");

    if(!user_id)
        goto end;


    // Path Params
    long sizeOfPathParams_user_id = strlen(user_id)+3 + sizeof("{ user_id }") - 1;
    if(user_id == NULL) {
        goto end;
    }
    char* localVarToReplace_user_id = malloc(sizeOfPathParams_user_id);
    sprintf(localVarToReplace_user_id, "{%s}", "user_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_user_id, user_id);



    // Body Param
    cJSON *localVarSingleItemJSON_update_role_payload = NULL;
    if (update_role_payload != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_update_role_payload = update_role_payload_convertToJSON(update_role_payload);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_update_role_payload);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "PUT");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_user_id);
    if (localVarSingleItemJSON_update_role_payload) {
        cJSON_Delete(localVarSingleItemJSON_update_role_payload);
        localVarSingleItemJSON_update_role_payload = NULL;
    }
    free(localVarBodyParameters);

}

