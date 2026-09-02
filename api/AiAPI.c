#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "AiAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


ai_suggestion_t*
AiAPI_aiSuggestApi(apiClient_t *apiClient, ai_suggestion_request_t *ai_suggestion_request)
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
    char *localVarPath = strdup("/api/v1/support/ai/suggest");





    // Body Param
    cJSON *localVarSingleItemJSON_ai_suggestion_request = NULL;
    if (ai_suggestion_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_ai_suggestion_request = ai_suggestion_request_convertToJSON(ai_suggestion_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_ai_suggestion_request);
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
    //    printf("%s\n","AI suggestion");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","AI error");
    //}
    //nonprimitive not container
    ai_suggestion_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AiAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = ai_suggestion_parseFromJSON(AiAPIlocalVarJSON);
        cJSON_Delete(AiAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_ai_suggestion_request) {
        cJSON_Delete(localVarSingleItemJSON_ai_suggestion_request);
        localVarSingleItemJSON_ai_suggestion_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

ai_worker_config_t*
AiAPI_createWorkerApi(apiClient_t *apiClient, ai_config_dto_t *ai_config_dto)
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
    char *localVarPath = strdup("/api/v1/support/ai/workers");





    // Body Param
    cJSON *localVarSingleItemJSON_ai_config_dto = NULL;
    if (ai_config_dto != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_ai_config_dto = ai_config_dto_convertToJSON(ai_config_dto);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_ai_config_dto);
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
    //    printf("%s\n","Worker created");
    //}
    //nonprimitive not container
    ai_worker_config_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AiAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = ai_worker_config_parseFromJSON(AiAPIlocalVarJSON);
        cJSON_Delete(AiAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_ai_config_dto) {
        cJSON_Delete(localVarSingleItemJSON_ai_config_dto);
        localVarSingleItemJSON_ai_config_dto = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

list_t*
AiAPI_listWorkersApi(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/api/v1/support/ai/workers");




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
    //    printf("%s\n","List AI workers");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AiAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(AiAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, AiAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( AiAPIlocalVarJSON);
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

ai_suggestion_t*
AiAPI_runWorkerApi(apiClient_t *apiClient, char *worker_id, ai_suggestion_request_t *ai_suggestion_request)
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
    char *localVarPath = strdup("/api/v1/support/ai/workers/{worker_id}/run");

    if(!worker_id)
        goto end;


    // Path Params
    long sizeOfPathParams_worker_id = strlen(worker_id)+3 + sizeof("{ worker_id }") - 1;
    if(worker_id == NULL) {
        goto end;
    }
    char* localVarToReplace_worker_id = malloc(sizeOfPathParams_worker_id);
    sprintf(localVarToReplace_worker_id, "{%s}", "worker_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_worker_id, worker_id);



    // Body Param
    cJSON *localVarSingleItemJSON_ai_suggestion_request = NULL;
    if (ai_suggestion_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_ai_suggestion_request = ai_suggestion_request_convertToJSON(ai_suggestion_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_ai_suggestion_request);
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
    //    printf("%s\n","Worker executed");
    //}
    //nonprimitive not container
    ai_suggestion_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AiAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = ai_suggestion_parseFromJSON(AiAPIlocalVarJSON);
        cJSON_Delete(AiAPIlocalVarJSON);
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
    free(localVarToReplace_worker_id);
    if (localVarSingleItemJSON_ai_suggestion_request) {
        cJSON_Delete(localVarSingleItemJSON_ai_suggestion_request);
        localVarSingleItemJSON_ai_suggestion_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

