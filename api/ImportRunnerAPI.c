#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "ImportRunnerAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


import_job_status_t*
ImportRunnerAPI_getImportStatus(apiClient_t *apiClient, char *job_id)
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
    char *localVarPath = strdup("/api/v1/import/{job_id}");

    if(!job_id)
        goto end;


    // Path Params
    long sizeOfPathParams_job_id = strlen(job_id)+3 + sizeof("{ job_id }") - 1;
    if(job_id == NULL) {
        goto end;
    }
    char* localVarToReplace_job_id = malloc(sizeOfPathParams_job_id);
    sprintf(localVarToReplace_job_id, "{%s}", "job_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_job_id, job_id);


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
    //    printf("%s\n","Import job status");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Job not found");
    //}
    //nonprimitive not container
    import_job_status_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ImportRunnerAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = import_job_status_parseFromJSON(ImportRunnerAPIlocalVarJSON);
        cJSON_Delete(ImportRunnerAPIlocalVarJSON);
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
    free(localVarToReplace_job_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

import_start_response_t*
ImportRunnerAPI_startImport(apiClient_t *apiClient, import_start_request_t *import_start_request)
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
    char *localVarPath = strdup("/api/v1/import/start");





    // Body Param
    cJSON *localVarSingleItemJSON_import_start_request = NULL;
    if (import_start_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_import_start_request = import_start_request_convertToJSON(import_start_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_import_start_request);
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
    //    printf("%s\n","Import job queued");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad request");
    //}
    //nonprimitive not container
    import_start_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ImportRunnerAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = import_start_response_parseFromJSON(ImportRunnerAPIlocalVarJSON);
        cJSON_Delete(ImportRunnerAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_import_start_request) {
        cJSON_Delete(localVarSingleItemJSON_import_start_request);
        localVarSingleItemJSON_import_start_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

import_test_response_t*
ImportRunnerAPI_testImportConnection(apiClient_t *apiClient, import_test_request_t *import_test_request)
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
    char *localVarPath = strdup("/api/v1/import/test");





    // Body Param
    cJSON *localVarSingleItemJSON_import_test_request = NULL;
    if (import_test_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_import_test_request = import_test_request_convertToJSON(import_test_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_import_test_request);
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
    //    printf("%s\n","Connection test result");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad request");
    //}
    //nonprimitive not container
    import_test_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ImportRunnerAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = import_test_response_parseFromJSON(ImportRunnerAPIlocalVarJSON);
        cJSON_Delete(ImportRunnerAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_import_test_request) {
        cJSON_Delete(localVarSingleItemJSON_import_test_request);
        localVarSingleItemJSON_import_test_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

