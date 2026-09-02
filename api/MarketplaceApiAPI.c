#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "MarketplaceApiAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Create a new connection (for API-key based platforms)
//
marketplace_connection_t*
MarketplaceApiAPI_createConnectionApi(apiClient_t *apiClient, create_connection_request_t *create_connection_request)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/api/v1/marketplace/connections");





    // Body Param
    cJSON *localVarSingleItemJSON_create_connection_request = NULL;
    if (create_connection_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_create_connection_request = create_connection_request_convertToJSON(create_connection_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_connection_request);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
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
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 201) {
    //    printf("%s\n","Created");
    //}
    //nonprimitive not container
    marketplace_connection_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketplaceApiAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = marketplace_connection_parseFromJSON(MarketplaceApiAPIlocalVarJSON);
        cJSON_Delete(MarketplaceApiAPIlocalVarJSON);
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
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_create_connection_request) {
        cJSON_Delete(localVarSingleItemJSON_create_connection_request);
        localVarSingleItemJSON_create_connection_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Soft-delete a connection
//
void
MarketplaceApiAPI_deleteConnectionApi(apiClient_t *apiClient, char *connection_id)
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
    char *localVarPath = strdup("/api/v1/marketplace/connections/{connection_id}");

    if(!connection_id)
        goto end;


    // Path Params
    long sizeOfPathParams_connection_id = strlen(connection_id)+3 + sizeof("{ connection_id }") - 1;
    if(connection_id == NULL) {
        goto end;
    }
    char* localVarToReplace_connection_id = malloc(sizeOfPathParams_connection_id);
    sprintf(localVarToReplace_connection_id, "{%s}", "connection_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_connection_id, connection_id);


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
    //    printf("%s\n","Deleted");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    
    
    free(localVarPath);
    free(localVarToReplace_connection_id);

}

// Get a single connection
//
marketplace_connection_t*
MarketplaceApiAPI_getConnectionApi(apiClient_t *apiClient, char *connection_id)
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
    char *localVarPath = strdup("/api/v1/marketplace/connections/{connection_id}");

    if(!connection_id)
        goto end;


    // Path Params
    long sizeOfPathParams_connection_id = strlen(connection_id)+3 + sizeof("{ connection_id }") - 1;
    if(connection_id == NULL) {
        goto end;
    }
    char* localVarToReplace_connection_id = malloc(sizeOfPathParams_connection_id);
    sprintf(localVarToReplace_connection_id, "{%s}", "connection_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_connection_id, connection_id);


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
    //    printf("%s\n","Connection details");
    //}
    //nonprimitive not container
    marketplace_connection_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketplaceApiAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = marketplace_connection_parseFromJSON(MarketplaceApiAPIlocalVarJSON);
        cJSON_Delete(MarketplaceApiAPIlocalVarJSON);
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
    free(localVarToReplace_connection_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get current sync direction configuration for a connection
//
void
MarketplaceApiAPI_getSyncDirectionApi(apiClient_t *apiClient, char *connection_id)
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
    char *localVarPath = strdup("/api/v1/marketplace/connections/{connection_id}/directions");

    if(!connection_id)
        goto end;


    // Path Params
    long sizeOfPathParams_connection_id = strlen(connection_id)+3 + sizeof("{ connection_id }") - 1;
    if(connection_id == NULL) {
        goto end;
    }
    char* localVarToReplace_connection_id = malloc(sizeOfPathParams_connection_id);
    sprintf(localVarToReplace_connection_id, "{%s}", "connection_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_connection_id, connection_id);


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
    //    printf("%s\n","Current sync directions");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    
    
    free(localVarPath);
    free(localVarToReplace_connection_id);

}

// Get sync logs for a connection
//
list_t*
MarketplaceApiAPI_getSyncLogsApi(apiClient_t *apiClient, char *connection_id)
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
    char *localVarPath = strdup("/api/v1/marketplace/connections/{connection_id}/logs");

    if(!connection_id)
        goto end;


    // Path Params
    long sizeOfPathParams_connection_id = strlen(connection_id)+3 + sizeof("{ connection_id }") - 1;
    if(connection_id == NULL) {
        goto end;
    }
    char* localVarToReplace_connection_id = malloc(sizeOfPathParams_connection_id);
    sprintf(localVarToReplace_connection_id, "{%s}", "connection_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_connection_id, connection_id);


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
    //    printf("%s\n","Sync logs");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketplaceApiAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(MarketplaceApiAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, MarketplaceApiAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( MarketplaceApiAPIlocalVarJSON);
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
    free(localVarToReplace_connection_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List connections for the current tenant
//
list_t*
MarketplaceApiAPI_listConnectionsApi(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/api/v1/marketplace/connections");




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
    //    printf("%s\n","List of connections");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketplaceApiAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(MarketplaceApiAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, MarketplaceApiAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( MarketplaceApiAPIlocalVarJSON);
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

// List all supported platforms
//
list_t*
MarketplaceApiAPI_listPlatformsApi(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/api/v1/marketplace/platforms");




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
    //    printf("%s\n","Supported platforms");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketplaceApiAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(MarketplaceApiAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, MarketplaceApiAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( MarketplaceApiAPIlocalVarJSON);
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

// OAuth: initiate authorization flow
//
o_auth_authorize_response_t*
MarketplaceApiAPI_oauthAuthorizeApi(apiClient_t *apiClient, o_auth_authorize_request_t *o_auth_authorize_request)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/api/v1/marketplace/oauth/authorize");





    // Body Param
    cJSON *localVarSingleItemJSON_o_auth_authorize_request = NULL;
    if (o_auth_authorize_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_o_auth_authorize_request = o_auth_authorize_request_convertToJSON(o_auth_authorize_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_o_auth_authorize_request);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
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
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Authorization URL");
    //}
    //nonprimitive not container
    o_auth_authorize_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketplaceApiAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = o_auth_authorize_response_parseFromJSON(MarketplaceApiAPIlocalVarJSON);
        cJSON_Delete(MarketplaceApiAPIlocalVarJSON);
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
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_o_auth_authorize_request) {
        cJSON_Delete(localVarSingleItemJSON_o_auth_authorize_request);
        localVarSingleItemJSON_o_auth_authorize_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// OAuth: handle callback after authorization
//
marketplace_connection_t*
MarketplaceApiAPI_oauthCallbackApi(apiClient_t *apiClient, o_auth_callback_request_t *o_auth_callback_request)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/api/v1/marketplace/oauth/callback");





    // Body Param
    cJSON *localVarSingleItemJSON_o_auth_callback_request = NULL;
    if (o_auth_callback_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_o_auth_callback_request = o_auth_callback_request_convertToJSON(o_auth_callback_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_o_auth_callback_request);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
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
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Connection created/updated");
    //}
    //nonprimitive not container
    marketplace_connection_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketplaceApiAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = marketplace_connection_parseFromJSON(MarketplaceApiAPIlocalVarJSON);
        cJSON_Delete(MarketplaceApiAPIlocalVarJSON);
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
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_o_auth_callback_request) {
        cJSON_Delete(localVarSingleItemJSON_o_auth_callback_request);
        localVarSingleItemJSON_o_auth_callback_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Trigger sync for a connection
//
sync_summary_t*
MarketplaceApiAPI_triggerSyncApi(apiClient_t *apiClient, char *connection_id, char *sync_type, char *direction)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/api/v1/marketplace/connections/{connection_id}/sync");

    if(!connection_id)
        goto end;


    // Path Params
    long sizeOfPathParams_connection_id = strlen(connection_id)+3 + sizeof("{ connection_id }") - 1;
    if(connection_id == NULL) {
        goto end;
    }
    char* localVarToReplace_connection_id = malloc(sizeOfPathParams_connection_id);
    sprintf(localVarToReplace_connection_id, "{%s}", "connection_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_connection_id, connection_id);



    // query parameters
    char *keyQuery_sync_type = NULL;
    char * valueQuery_sync_type = NULL;
    keyValuePair_t *keyPairQuery_sync_type = 0;
    if (sync_type)
    {
        keyQuery_sync_type = strdup("sync_type");
        valueQuery_sync_type = strdup((sync_type));
        keyPairQuery_sync_type = keyValuePair_create(keyQuery_sync_type, valueQuery_sync_type);
        list_addElement(localVarQueryParameters,keyPairQuery_sync_type);
    }

    // query parameters
    char *keyQuery_direction = NULL;
    char * valueQuery_direction = NULL;
    keyValuePair_t *keyPairQuery_direction = 0;
    if (direction)
    {
        keyQuery_direction = strdup("direction");
        valueQuery_direction = strdup((direction));
        keyPairQuery_direction = keyValuePair_create(keyQuery_direction, valueQuery_direction);
        list_addElement(localVarQueryParameters,keyPairQuery_direction);
    }
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
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Sync triggered");
    //}
    //nonprimitive not container
    sync_summary_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketplaceApiAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = sync_summary_parseFromJSON(MarketplaceApiAPIlocalVarJSON);
        cJSON_Delete(MarketplaceApiAPIlocalVarJSON);
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
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_connection_id);
    if(keyQuery_sync_type){
        free(keyQuery_sync_type);
        keyQuery_sync_type = NULL;
    }
    if(valueQuery_sync_type){
        free(valueQuery_sync_type);
        valueQuery_sync_type = NULL;
    }
    if(keyPairQuery_sync_type){
        keyValuePair_free(keyPairQuery_sync_type);
        keyPairQuery_sync_type = NULL;
    }
    if(keyQuery_direction){
        free(keyQuery_direction);
        keyQuery_direction = NULL;
    }
    if(valueQuery_direction){
        free(valueQuery_direction);
        valueQuery_direction = NULL;
    }
    if(keyPairQuery_direction){
        keyValuePair_free(keyPairQuery_direction);
        keyPairQuery_direction = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Update a connection
//
marketplace_connection_t*
MarketplaceApiAPI_updateConnectionApi(apiClient_t *apiClient, char *connection_id, update_connection_request_t *update_connection_request)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/api/v1/marketplace/connections/{connection_id}");

    if(!connection_id)
        goto end;


    // Path Params
    long sizeOfPathParams_connection_id = strlen(connection_id)+3 + sizeof("{ connection_id }") - 1;
    if(connection_id == NULL) {
        goto end;
    }
    char* localVarToReplace_connection_id = malloc(sizeOfPathParams_connection_id);
    sprintf(localVarToReplace_connection_id, "{%s}", "connection_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_connection_id, connection_id);



    // Body Param
    cJSON *localVarSingleItemJSON_update_connection_request = NULL;
    if (update_connection_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_update_connection_request = update_connection_request_convertToJSON(update_connection_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_update_connection_request);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
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
    //    printf("%s\n","Updated");
    //}
    //nonprimitive not container
    marketplace_connection_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketplaceApiAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = marketplace_connection_parseFromJSON(MarketplaceApiAPIlocalVarJSON);
        cJSON_Delete(MarketplaceApiAPIlocalVarJSON);
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
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_connection_id);
    if (localVarSingleItemJSON_update_connection_request) {
        cJSON_Delete(localVarSingleItemJSON_update_connection_request);
        localVarSingleItemJSON_update_connection_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Update per-entity sync direction configuration for a connection
//
void
MarketplaceApiAPI_updateSyncDirectionApi(apiClient_t *apiClient, char *connection_id, update_sync_direction_request_t *update_sync_direction_request)
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
    char *localVarPath = strdup("/api/v1/marketplace/connections/{connection_id}/directions");

    if(!connection_id)
        goto end;


    // Path Params
    long sizeOfPathParams_connection_id = strlen(connection_id)+3 + sizeof("{ connection_id }") - 1;
    if(connection_id == NULL) {
        goto end;
    }
    char* localVarToReplace_connection_id = malloc(sizeOfPathParams_connection_id);
    sprintf(localVarToReplace_connection_id, "{%s}", "connection_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_connection_id, connection_id);



    // Body Param
    cJSON *localVarSingleItemJSON_update_sync_direction_request = NULL;
    if (update_sync_direction_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_update_sync_direction_request = update_sync_direction_request_convertToJSON(update_sync_direction_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_update_sync_direction_request);
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
    //    printf("%s\n","Sync directions updated");
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
    free(localVarToReplace_connection_id);
    if (localVarSingleItemJSON_update_sync_direction_request) {
        cJSON_Delete(localVarSingleItemJSON_update_sync_direction_request);
        localVarSingleItemJSON_update_sync_direction_request = NULL;
    }
    free(localVarBodyParameters);

}

// Webhook receiver
//
void
MarketplaceApiAPI_webhookReceiverApi(apiClient_t *apiClient, char *platform, char *connection_id)
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
    char *localVarPath = strdup("/api/v1/marketplace/webhook/{platform}/{connection_id}");

    if(!platform)
        goto end;
    if(!connection_id)
        goto end;


    // Path Params
    long sizeOfPathParams_platform = strlen(platform)+3 + strlen(connection_id)+3 + sizeof("{ platform }") - 1;
    if(platform == NULL) {
        goto end;
    }
    char* localVarToReplace_platform = malloc(sizeOfPathParams_platform);
    sprintf(localVarToReplace_platform, "{%s}", "platform");

    localVarPath = strReplace(localVarPath, localVarToReplace_platform, platform);

    // Path Params
    long sizeOfPathParams_connection_id = strlen(platform)+3 + strlen(connection_id)+3 + sizeof("{ connection_id }") - 1;
    if(connection_id == NULL) {
        goto end;
    }
    char* localVarToReplace_connection_id = malloc(sizeOfPathParams_connection_id);
    sprintf(localVarToReplace_connection_id, "{%s}", "connection_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_connection_id, connection_id);


    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Webhook received");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Invalid signature");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    
    
    free(localVarPath);
    free(localVarToReplace_platform);
    free(localVarToReplace_connection_id);

}

