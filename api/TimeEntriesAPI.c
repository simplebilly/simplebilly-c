#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "TimeEntriesAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Clock in for the authenticated user (resolved via their employee profile).
//
time_entry_dto_t*
TimeEntriesAPI_clockInTimeEntry(apiClient_t *apiClient, time_entry_clock_in_t *time_entry_clock_in)
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
    char *localVarPath = strdup("/api/v1/time-entries");





    // Body Param
    cJSON *localVarSingleItemJSON_time_entry_clock_in = NULL;
    if (time_entry_clock_in != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_time_entry_clock_in = time_entry_clock_in_convertToJSON(time_entry_clock_in);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_time_entry_clock_in);
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
    //    printf("%s\n","No employee profile for this user");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    time_entry_dto_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *TimeEntriesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = time_entry_dto_parseFromJSON(TimeEntriesAPIlocalVarJSON);
        cJSON_Delete(TimeEntriesAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_time_entry_clock_in) {
        cJSON_Delete(localVarSingleItemJSON_time_entry_clock_in);
        localVarSingleItemJSON_time_entry_clock_in = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Clock out an entry: the entry's owner, or anyone with `time_entries:write`.
//
time_entry_dto_t*
TimeEntriesAPI_clockOutTimeEntry(apiClient_t *apiClient, char *id, time_entry_clock_out_t *time_entry_clock_out)
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
    char *localVarPath = strdup("/api/v1/time-entries/{id}");

    if(!id)
        goto end;


    // Path Params
    long sizeOfPathParams_id = strlen(id)+3 + sizeof("{ id }") - 1;
    if(id == NULL) {
        goto end;
    }
    char* localVarToReplace_id = malloc(sizeOfPathParams_id);
    sprintf(localVarToReplace_id, "{%s}", "id");

    localVarPath = strReplace(localVarPath, localVarToReplace_id, id);



    // Body Param
    cJSON *localVarSingleItemJSON_time_entry_clock_out = NULL;
    if (time_entry_clock_out != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_time_entry_clock_out = time_entry_clock_out_convertToJSON(time_entry_clock_out);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_time_entry_clock_out);
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
                    "PATCH");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
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
    time_entry_dto_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *TimeEntriesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = time_entry_dto_parseFromJSON(TimeEntriesAPIlocalVarJSON);
        cJSON_Delete(TimeEntriesAPIlocalVarJSON);
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
    free(localVarToReplace_id);
    if (localVarSingleItemJSON_time_entry_clock_out) {
        cJSON_Delete(localVarSingleItemJSON_time_entry_clock_out);
        localVarSingleItemJSON_time_entry_clock_out = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Labor-cost report: worked hours aggregated per employee / order / day, valued at the employee's hourly cost rate.
//
list_t*
TimeEntriesAPI_getLaborCosts(apiClient_t *apiClient, char from, char to, char *group_by)
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
    char *localVarPath = strdup("/api/v1/labor-costs");





    // query parameters
    char *keyQuery_from = NULL;
    char valueQuery_from ;
    keyValuePair_t *keyPairQuery_from = 0;
    if (from)
    {
        keyQuery_from = strdup("from");
        valueQuery_from = (from);
        keyPairQuery_from = keyValuePair_create(keyQuery_from, &valueQuery_from);
        list_addElement(localVarQueryParameters,keyPairQuery_from);
    }

    // query parameters
    char *keyQuery_to = NULL;
    char valueQuery_to ;
    keyValuePair_t *keyPairQuery_to = 0;
    if (to)
    {
        keyQuery_to = strdup("to");
        valueQuery_to = (to);
        keyPairQuery_to = keyValuePair_create(keyQuery_to, &valueQuery_to);
        list_addElement(localVarQueryParameters,keyPairQuery_to);
    }

    // query parameters
    char *keyQuery_group_by = NULL;
    char * valueQuery_group_by = NULL;
    keyValuePair_t *keyPairQuery_group_by = 0;
    if (group_by)
    {
        keyQuery_group_by = strdup("group_by");
        valueQuery_group_by = strdup((group_by));
        keyPairQuery_group_by = keyValuePair_create(keyQuery_group_by, valueQuery_group_by);
        list_addElement(localVarQueryParameters,keyPairQuery_group_by);
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
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *TimeEntriesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(TimeEntriesAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, TimeEntriesAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( TimeEntriesAPIlocalVarJSON);
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
    if(keyQuery_from){
        free(keyQuery_from);
        keyQuery_from = NULL;
    }
    if(keyPairQuery_from){
        keyValuePair_free(keyPairQuery_from);
        keyPairQuery_from = NULL;
    }
    if(keyQuery_to){
        free(keyQuery_to);
        keyQuery_to = NULL;
    }
    if(keyPairQuery_to){
        keyValuePair_free(keyPairQuery_to);
        keyPairQuery_to = NULL;
    }
    if(keyQuery_group_by){
        free(keyQuery_group_by);
        keyQuery_group_by = NULL;
    }
    if(valueQuery_group_by){
        free(valueQuery_group_by);
        valueQuery_group_by = NULL;
    }
    if(keyPairQuery_group_by){
        keyValuePair_free(keyPairQuery_group_by);
        keyPairQuery_group_by = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List time entries with optional date-range / active / employee filters.
//
list_t*
TimeEntriesAPI_listTimeEntries(apiClient_t *apiClient, char from, char to, int *active, char *employee_id)
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
    char *localVarPath = strdup("/api/v1/time-entries");





    // query parameters
    char *keyQuery_from = NULL;
    char valueQuery_from ;
    keyValuePair_t *keyPairQuery_from = 0;
    if (from)
    {
        keyQuery_from = strdup("from");
        valueQuery_from = (from);
        keyPairQuery_from = keyValuePair_create(keyQuery_from, &valueQuery_from);
        list_addElement(localVarQueryParameters,keyPairQuery_from);
    }

    // query parameters
    char *keyQuery_to = NULL;
    char valueQuery_to ;
    keyValuePair_t *keyPairQuery_to = 0;
    if (to)
    {
        keyQuery_to = strdup("to");
        valueQuery_to = (to);
        keyPairQuery_to = keyValuePair_create(keyQuery_to, &valueQuery_to);
        list_addElement(localVarQueryParameters,keyPairQuery_to);
    }

    // query parameters
    char *keyQuery_active = NULL;
    char * valueQuery_active = NULL;
    keyValuePair_t *keyPairQuery_active = 0;
    if (active)
    {
        keyQuery_active = strdup("active");
        valueQuery_active = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_active, MAX_NUMBER_LENGTH, "%d", *active);
        keyPairQuery_active = keyValuePair_create(keyQuery_active, valueQuery_active);
        list_addElement(localVarQueryParameters,keyPairQuery_active);
    }

    // query parameters
    char *keyQuery_employee_id = NULL;
    char * valueQuery_employee_id = NULL;
    keyValuePair_t *keyPairQuery_employee_id = 0;
    if (employee_id)
    {
        keyQuery_employee_id = strdup("employee_id");
        valueQuery_employee_id = strdup((employee_id));
        keyPairQuery_employee_id = keyValuePair_create(keyQuery_employee_id, valueQuery_employee_id);
        list_addElement(localVarQueryParameters,keyPairQuery_employee_id);
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
        cJSON *TimeEntriesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(TimeEntriesAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, TimeEntriesAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( TimeEntriesAPIlocalVarJSON);
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
    if(keyQuery_from){
        free(keyQuery_from);
        keyQuery_from = NULL;
    }
    if(keyPairQuery_from){
        keyValuePair_free(keyPairQuery_from);
        keyPairQuery_from = NULL;
    }
    if(keyQuery_to){
        free(keyQuery_to);
        keyQuery_to = NULL;
    }
    if(keyPairQuery_to){
        keyValuePair_free(keyPairQuery_to);
        keyPairQuery_to = NULL;
    }
    if(keyQuery_active){
        free(keyQuery_active);
        keyQuery_active = NULL;
    }
    if(valueQuery_active){
        free(valueQuery_active);
        valueQuery_active = NULL;
    }
    if(keyPairQuery_active){
        keyValuePair_free(keyPairQuery_active);
        keyPairQuery_active = NULL;
    }
    if(keyQuery_employee_id){
        free(keyQuery_employee_id);
        keyQuery_employee_id = NULL;
    }
    if(valueQuery_employee_id){
        free(valueQuery_employee_id);
        valueQuery_employee_id = NULL;
    }
    if(keyPairQuery_employee_id){
        keyValuePair_free(keyPairQuery_employee_id);
        keyPairQuery_employee_id = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

