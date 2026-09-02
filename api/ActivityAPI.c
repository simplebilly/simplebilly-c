#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "ActivityAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


activity_t*
ActivityAPI_createActivity(apiClient_t *apiClient, activity_t *activity)
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
    char *localVarPath = strdup("/api/v1/activities");





    // Body Param
    cJSON *localVarSingleItemJSON_activity = NULL;
    if (activity != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_activity = activity_convertToJSON(activity);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_activity);
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
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    activity_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ActivityAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = activity_parseFromJSON(ActivityAPIlocalVarJSON);
        cJSON_Delete(ActivityAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_activity) {
        cJSON_Delete(localVarSingleItemJSON_activity);
        localVarSingleItemJSON_activity = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

void
ActivityAPI_deleteActivity(apiClient_t *apiClient, char *activity_id)
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
    char *localVarPath = strdup("/api/v1/activities/{activity_id}");

    if(!activity_id)
        goto end;


    // Path Params
    long sizeOfPathParams_activity_id = strlen(activity_id)+3 + sizeof("{ activity_id }") - 1;
    if(activity_id == NULL) {
        goto end;
    }
    char* localVarToReplace_activity_id = malloc(sizeOfPathParams_activity_id);
    sprintf(localVarToReplace_activity_id, "{%s}", "activity_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_activity_id, activity_id);


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
                    "DELETE");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","No Content");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_activity_id);

}

activity_t*
ActivityAPI_getActivity(apiClient_t *apiClient, char *activity_id)
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
    char *localVarPath = strdup("/api/v1/activities/{activity_id}");

    if(!activity_id)
        goto end;


    // Path Params
    long sizeOfPathParams_activity_id = strlen(activity_id)+3 + sizeof("{ activity_id }") - 1;
    if(activity_id == NULL) {
        goto end;
    }
    char* localVarToReplace_activity_id = malloc(sizeOfPathParams_activity_id);
    sprintf(localVarToReplace_activity_id, "{%s}", "activity_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_activity_id, activity_id);


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
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    activity_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ActivityAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = activity_parseFromJSON(ActivityAPIlocalVarJSON);
        cJSON_Delete(ActivityAPIlocalVarJSON);
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
    free(localVarToReplace_activity_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

list_t*
ActivityAPI_listActivities(apiClient_t *apiClient, int *page, int *pageSize, char *contactId, char *activityType, char *status, char *assignedTo, int *overdueOnly)
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
    char *localVarPath = strdup("/api/v1/activities/");





    // query parameters
    char *keyQuery_page = NULL;
    char * valueQuery_page = NULL;
    keyValuePair_t *keyPairQuery_page = 0;
    if (page)
    {
        keyQuery_page = strdup("page");
        valueQuery_page = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_page, MAX_NUMBER_LENGTH, "%d", *page);
        keyPairQuery_page = keyValuePair_create(keyQuery_page, valueQuery_page);
        list_addElement(localVarQueryParameters,keyPairQuery_page);
    }

    // query parameters
    char *keyQuery_pageSize = NULL;
    char * valueQuery_pageSize = NULL;
    keyValuePair_t *keyPairQuery_pageSize = 0;
    if (pageSize)
    {
        keyQuery_pageSize = strdup("pageSize");
        valueQuery_pageSize = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_pageSize, MAX_NUMBER_LENGTH, "%d", *pageSize);
        keyPairQuery_pageSize = keyValuePair_create(keyQuery_pageSize, valueQuery_pageSize);
        list_addElement(localVarQueryParameters,keyPairQuery_pageSize);
    }

    // query parameters
    char *keyQuery_contactId = NULL;
    char * valueQuery_contactId = NULL;
    keyValuePair_t *keyPairQuery_contactId = 0;
    if (contactId)
    {
        keyQuery_contactId = strdup("contactId");
        valueQuery_contactId = strdup((contactId));
        keyPairQuery_contactId = keyValuePair_create(keyQuery_contactId, valueQuery_contactId);
        list_addElement(localVarQueryParameters,keyPairQuery_contactId);
    }

    // query parameters
    char *keyQuery_activityType = NULL;
    char * valueQuery_activityType = NULL;
    keyValuePair_t *keyPairQuery_activityType = 0;
    if (activityType)
    {
        keyQuery_activityType = strdup("activityType");
        valueQuery_activityType = strdup((activityType));
        keyPairQuery_activityType = keyValuePair_create(keyQuery_activityType, valueQuery_activityType);
        list_addElement(localVarQueryParameters,keyPairQuery_activityType);
    }

    // query parameters
    char *keyQuery_status = NULL;
    char * valueQuery_status = NULL;
    keyValuePair_t *keyPairQuery_status = 0;
    if (status)
    {
        keyQuery_status = strdup("status");
        valueQuery_status = strdup((status));
        keyPairQuery_status = keyValuePair_create(keyQuery_status, valueQuery_status);
        list_addElement(localVarQueryParameters,keyPairQuery_status);
    }

    // query parameters
    char *keyQuery_assignedTo = NULL;
    char * valueQuery_assignedTo = NULL;
    keyValuePair_t *keyPairQuery_assignedTo = 0;
    if (assignedTo)
    {
        keyQuery_assignedTo = strdup("assignedTo");
        valueQuery_assignedTo = strdup((assignedTo));
        keyPairQuery_assignedTo = keyValuePair_create(keyQuery_assignedTo, valueQuery_assignedTo);
        list_addElement(localVarQueryParameters,keyPairQuery_assignedTo);
    }

    // query parameters
    char *keyQuery_overdueOnly = NULL;
    char * valueQuery_overdueOnly = NULL;
    keyValuePair_t *keyPairQuery_overdueOnly = 0;
    if (overdueOnly)
    {
        keyQuery_overdueOnly = strdup("overdueOnly");
        valueQuery_overdueOnly = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_overdueOnly, MAX_NUMBER_LENGTH, "%d", *overdueOnly);
        keyPairQuery_overdueOnly = keyValuePair_create(keyQuery_overdueOnly, valueQuery_overdueOnly);
        list_addElement(localVarQueryParameters,keyPairQuery_overdueOnly);
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
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ActivityAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(ActivityAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, ActivityAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( ActivityAPIlocalVarJSON);
        cJSON_Delete( VarJSON);
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
    if(keyQuery_page){
        free(keyQuery_page);
        keyQuery_page = NULL;
    }
    if(valueQuery_page){
        free(valueQuery_page);
        valueQuery_page = NULL;
    }
    if(keyPairQuery_page){
        keyValuePair_free(keyPairQuery_page);
        keyPairQuery_page = NULL;
    }
    if(keyQuery_pageSize){
        free(keyQuery_pageSize);
        keyQuery_pageSize = NULL;
    }
    if(valueQuery_pageSize){
        free(valueQuery_pageSize);
        valueQuery_pageSize = NULL;
    }
    if(keyPairQuery_pageSize){
        keyValuePair_free(keyPairQuery_pageSize);
        keyPairQuery_pageSize = NULL;
    }
    if(keyQuery_contactId){
        free(keyQuery_contactId);
        keyQuery_contactId = NULL;
    }
    if(valueQuery_contactId){
        free(valueQuery_contactId);
        valueQuery_contactId = NULL;
    }
    if(keyPairQuery_contactId){
        keyValuePair_free(keyPairQuery_contactId);
        keyPairQuery_contactId = NULL;
    }
    if(keyQuery_activityType){
        free(keyQuery_activityType);
        keyQuery_activityType = NULL;
    }
    if(valueQuery_activityType){
        free(valueQuery_activityType);
        valueQuery_activityType = NULL;
    }
    if(keyPairQuery_activityType){
        keyValuePair_free(keyPairQuery_activityType);
        keyPairQuery_activityType = NULL;
    }
    if(keyQuery_status){
        free(keyQuery_status);
        keyQuery_status = NULL;
    }
    if(valueQuery_status){
        free(valueQuery_status);
        valueQuery_status = NULL;
    }
    if(keyPairQuery_status){
        keyValuePair_free(keyPairQuery_status);
        keyPairQuery_status = NULL;
    }
    if(keyQuery_assignedTo){
        free(keyQuery_assignedTo);
        keyQuery_assignedTo = NULL;
    }
    if(valueQuery_assignedTo){
        free(valueQuery_assignedTo);
        valueQuery_assignedTo = NULL;
    }
    if(keyPairQuery_assignedTo){
        keyValuePair_free(keyPairQuery_assignedTo);
        keyPairQuery_assignedTo = NULL;
    }
    if(keyQuery_overdueOnly){
        free(keyQuery_overdueOnly);
        keyQuery_overdueOnly = NULL;
    }
    if(valueQuery_overdueOnly){
        free(valueQuery_overdueOnly);
        valueQuery_overdueOnly = NULL;
    }
    if(keyPairQuery_overdueOnly){
        keyValuePair_free(keyPairQuery_overdueOnly);
        keyPairQuery_overdueOnly = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

activity_t*
ActivityAPI_updateActivity(apiClient_t *apiClient, char *activity_id, body)
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
    char *localVarPath = strdup("/api/v1/activities/{activity_id}");

    if(!activity_id)
        goto end;


    // Path Params
    long sizeOfPathParams_activity_id = strlen(activity_id)+3 + sizeof("{ activity_id }") - 1;
    if(activity_id == NULL) {
        goto end;
    }
    char* localVarToReplace_activity_id = malloc(sizeOfPathParams_activity_id);
    sprintf(localVarToReplace_activity_id, "{%s}", "activity_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_activity_id, activity_id);



    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_body = any_type_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
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
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    activity_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ActivityAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = activity_parseFromJSON(ActivityAPIlocalVarJSON);
        cJSON_Delete(ActivityAPIlocalVarJSON);
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
    free(localVarToReplace_activity_id);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

activity_t*
ActivityAPI_updateActivityStatus(apiClient_t *apiClient, char *activity_id, activity_status_update_t *activity_status_update)
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
    char *localVarPath = strdup("/api/v1/activities/{activity_id}/status");

    if(!activity_id)
        goto end;


    // Path Params
    long sizeOfPathParams_activity_id = strlen(activity_id)+3 + sizeof("{ activity_id }") - 1;
    if(activity_id == NULL) {
        goto end;
    }
    char* localVarToReplace_activity_id = malloc(sizeOfPathParams_activity_id);
    sprintf(localVarToReplace_activity_id, "{%s}", "activity_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_activity_id, activity_id);



    // Body Param
    cJSON *localVarSingleItemJSON_activity_status_update = NULL;
    if (activity_status_update != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_activity_status_update = activity_status_update_convertToJSON(activity_status_update);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_activity_status_update);
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
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    activity_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ActivityAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = activity_parseFromJSON(ActivityAPIlocalVarJSON);
        cJSON_Delete(ActivityAPIlocalVarJSON);
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
    free(localVarToReplace_activity_id);
    if (localVarSingleItemJSON_activity_status_update) {
        cJSON_Delete(localVarSingleItemJSON_activity_status_update);
        localVarSingleItemJSON_activity_status_update = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

