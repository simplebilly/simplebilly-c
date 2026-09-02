#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "SupportChannelAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


support_channel_t*
SupportChannelAPI_createChannelApi(apiClient_t *apiClient, create_channel_dto_t *create_channel_dto)
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
    char *localVarPath = strdup("/api/v1/support/channels");





    // Body Param
    cJSON *localVarSingleItemJSON_create_channel_dto = NULL;
    if (create_channel_dto != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_create_channel_dto = create_channel_dto_convertToJSON(create_channel_dto);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_channel_dto);
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
    //    printf("%s\n","Channel created");
    //}
    //nonprimitive not container
    support_channel_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SupportChannelAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = support_channel_parseFromJSON(SupportChannelAPIlocalVarJSON);
        cJSON_Delete(SupportChannelAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_create_channel_dto) {
        cJSON_Delete(localVarSingleItemJSON_create_channel_dto);
        localVarSingleItemJSON_create_channel_dto = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

void
SupportChannelAPI_deleteChannelApi(apiClient_t *apiClient, char *channel_id)
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
    char *localVarPath = strdup("/api/v1/support/channels/{channel_id}");

    if(!channel_id)
        goto end;


    // Path Params
    long sizeOfPathParams_channel_id = strlen(channel_id)+3 + sizeof("{ channel_id }") - 1;
    if(channel_id == NULL) {
        goto end;
    }
    char* localVarToReplace_channel_id = malloc(sizeOfPathParams_channel_id);
    sprintf(localVarToReplace_channel_id, "{%s}", "channel_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_channel_id, channel_id);


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
    //    printf("%s\n","Channel deleted");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    
    
    free(localVarPath);
    free(localVarToReplace_channel_id);

}

list_t*
SupportChannelAPI_listChannelsApi(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/api/v1/support/channels");




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
    //    printf("%s\n","List of channels");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SupportChannelAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(SupportChannelAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, SupportChannelAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( SupportChannelAPIlocalVarJSON);
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

support_channel_t*
SupportChannelAPI_updateChannelApi(apiClient_t *apiClient, char *channel_id, update_channel_dto_t *update_channel_dto)
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
    char *localVarPath = strdup("/api/v1/support/channels/{channel_id}");

    if(!channel_id)
        goto end;


    // Path Params
    long sizeOfPathParams_channel_id = strlen(channel_id)+3 + sizeof("{ channel_id }") - 1;
    if(channel_id == NULL) {
        goto end;
    }
    char* localVarToReplace_channel_id = malloc(sizeOfPathParams_channel_id);
    sprintf(localVarToReplace_channel_id, "{%s}", "channel_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_channel_id, channel_id);



    // Body Param
    cJSON *localVarSingleItemJSON_update_channel_dto = NULL;
    if (update_channel_dto != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_update_channel_dto = update_channel_dto_convertToJSON(update_channel_dto);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_update_channel_dto);
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
    //    printf("%s\n","Channel updated");
    //}
    //nonprimitive not container
    support_channel_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SupportChannelAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = support_channel_parseFromJSON(SupportChannelAPIlocalVarJSON);
        cJSON_Delete(SupportChannelAPIlocalVarJSON);
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
    free(localVarToReplace_channel_id);
    if (localVarSingleItemJSON_update_channel_dto) {
        cJSON_Delete(localVarSingleItemJSON_update_channel_dto);
        localVarSingleItemJSON_update_channel_dto = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

