#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "DatevAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Export bookkeeping data as DATEV CSV
//
datev_export_response_t*
DatevAPI_datevExportApi(apiClient_t *apiClient, char *account_schema, char *date_from, char *date_to, int *page, int *page_size)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/datev/export");





    // query parameters
    char *keyQuery_account_schema = NULL;
    char * valueQuery_account_schema = NULL;
    keyValuePair_t *keyPairQuery_account_schema = 0;
    if (account_schema)
    {
        keyQuery_account_schema = strdup("account_schema");
        valueQuery_account_schema = strdup((account_schema));
        keyPairQuery_account_schema = keyValuePair_create(keyQuery_account_schema, valueQuery_account_schema);
        list_addElement(localVarQueryParameters,keyPairQuery_account_schema);
    }

    // query parameters
    char *keyQuery_date_from = NULL;
    char * valueQuery_date_from = NULL;
    keyValuePair_t *keyPairQuery_date_from = 0;
    if (date_from)
    {
        keyQuery_date_from = strdup("date_from");
        valueQuery_date_from = strdup((date_from));
        keyPairQuery_date_from = keyValuePair_create(keyQuery_date_from, valueQuery_date_from);
        list_addElement(localVarQueryParameters,keyPairQuery_date_from);
    }

    // query parameters
    char *keyQuery_date_to = NULL;
    char * valueQuery_date_to = NULL;
    keyValuePair_t *keyPairQuery_date_to = 0;
    if (date_to)
    {
        keyQuery_date_to = strdup("date_to");
        valueQuery_date_to = strdup((date_to));
        keyPairQuery_date_to = keyValuePair_create(keyQuery_date_to, valueQuery_date_to);
        list_addElement(localVarQueryParameters,keyPairQuery_date_to);
    }

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
    char *keyQuery_page_size = NULL;
    char * valueQuery_page_size = NULL;
    keyValuePair_t *keyPairQuery_page_size = 0;
    if (page_size)
    {
        keyQuery_page_size = strdup("page_size");
        valueQuery_page_size = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_page_size, MAX_NUMBER_LENGTH, "%d", *page_size);
        keyPairQuery_page_size = keyValuePair_create(keyQuery_page_size, valueQuery_page_size);
        list_addElement(localVarQueryParameters,keyPairQuery_page_size);
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
    //    printf("%s\n","DATEV CSV export");
    //}
    //nonprimitive not container
    datev_export_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DatevAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = datev_export_response_parseFromJSON(DatevAPIlocalVarJSON);
        cJSON_Delete(DatevAPIlocalVarJSON);
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
    if(keyQuery_account_schema){
        free(keyQuery_account_schema);
        keyQuery_account_schema = NULL;
    }
    if(valueQuery_account_schema){
        free(valueQuery_account_schema);
        valueQuery_account_schema = NULL;
    }
    if(keyPairQuery_account_schema){
        keyValuePair_free(keyPairQuery_account_schema);
        keyPairQuery_account_schema = NULL;
    }
    if(keyQuery_date_from){
        free(keyQuery_date_from);
        keyQuery_date_from = NULL;
    }
    if(valueQuery_date_from){
        free(valueQuery_date_from);
        valueQuery_date_from = NULL;
    }
    if(keyPairQuery_date_from){
        keyValuePair_free(keyPairQuery_date_from);
        keyPairQuery_date_from = NULL;
    }
    if(keyQuery_date_to){
        free(keyQuery_date_to);
        keyQuery_date_to = NULL;
    }
    if(valueQuery_date_to){
        free(valueQuery_date_to);
        valueQuery_date_to = NULL;
    }
    if(keyPairQuery_date_to){
        keyValuePair_free(keyPairQuery_date_to);
        keyPairQuery_date_to = NULL;
    }
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
    if(keyQuery_page_size){
        free(keyQuery_page_size);
        keyQuery_page_size = NULL;
    }
    if(valueQuery_page_size){
        free(valueQuery_page_size);
        valueQuery_page_size = NULL;
    }
    if(keyPairQuery_page_size){
        keyValuePair_free(keyPairQuery_page_size);
        keyPairQuery_page_size = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Exported_datev_bookings: returns formed bookings for review
//
list_t*
DatevAPI_datevPreviewApi(apiClient_t *apiClient, char *account_schema, char *date_from, char *date_to, int *page, int *page_size)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/datev/preview");





    // query parameters
    char *keyQuery_account_schema = NULL;
    char * valueQuery_account_schema = NULL;
    keyValuePair_t *keyPairQuery_account_schema = 0;
    if (account_schema)
    {
        keyQuery_account_schema = strdup("account_schema");
        valueQuery_account_schema = strdup((account_schema));
        keyPairQuery_account_schema = keyValuePair_create(keyQuery_account_schema, valueQuery_account_schema);
        list_addElement(localVarQueryParameters,keyPairQuery_account_schema);
    }

    // query parameters
    char *keyQuery_date_from = NULL;
    char * valueQuery_date_from = NULL;
    keyValuePair_t *keyPairQuery_date_from = 0;
    if (date_from)
    {
        keyQuery_date_from = strdup("date_from");
        valueQuery_date_from = strdup((date_from));
        keyPairQuery_date_from = keyValuePair_create(keyQuery_date_from, valueQuery_date_from);
        list_addElement(localVarQueryParameters,keyPairQuery_date_from);
    }

    // query parameters
    char *keyQuery_date_to = NULL;
    char * valueQuery_date_to = NULL;
    keyValuePair_t *keyPairQuery_date_to = 0;
    if (date_to)
    {
        keyQuery_date_to = strdup("date_to");
        valueQuery_date_to = strdup((date_to));
        keyPairQuery_date_to = keyValuePair_create(keyQuery_date_to, valueQuery_date_to);
        list_addElement(localVarQueryParameters,keyPairQuery_date_to);
    }

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
    char *keyQuery_page_size = NULL;
    char * valueQuery_page_size = NULL;
    keyValuePair_t *keyPairQuery_page_size = 0;
    if (page_size)
    {
        keyQuery_page_size = strdup("page_size");
        valueQuery_page_size = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_page_size, MAX_NUMBER_LENGTH, "%d", *page_size);
        keyPairQuery_page_size = keyValuePair_create(keyQuery_page_size, valueQuery_page_size);
        list_addElement(localVarQueryParameters,keyPairQuery_page_size);
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
    //    printf("%s\n","DATEV booking preview");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DatevAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(DatevAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, DatevAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( DatevAPIlocalVarJSON);
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
    if(keyQuery_account_schema){
        free(keyQuery_account_schema);
        keyQuery_account_schema = NULL;
    }
    if(valueQuery_account_schema){
        free(valueQuery_account_schema);
        valueQuery_account_schema = NULL;
    }
    if(keyPairQuery_account_schema){
        keyValuePair_free(keyPairQuery_account_schema);
        keyPairQuery_account_schema = NULL;
    }
    if(keyQuery_date_from){
        free(keyQuery_date_from);
        keyQuery_date_from = NULL;
    }
    if(valueQuery_date_from){
        free(valueQuery_date_from);
        valueQuery_date_from = NULL;
    }
    if(keyPairQuery_date_from){
        keyValuePair_free(keyPairQuery_date_from);
        keyPairQuery_date_from = NULL;
    }
    if(keyQuery_date_to){
        free(keyQuery_date_to);
        keyQuery_date_to = NULL;
    }
    if(valueQuery_date_to){
        free(valueQuery_date_to);
        valueQuery_date_to = NULL;
    }
    if(keyPairQuery_date_to){
        keyValuePair_free(keyPairQuery_date_to);
        keyPairQuery_date_to = NULL;
    }
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
    if(keyQuery_page_size){
        free(keyQuery_page_size);
        keyQuery_page_size = NULL;
    }
    if(valueQuery_page_size){
        free(valueQuery_page_size);
        valueQuery_page_size = NULL;
    }
    if(keyPairQuery_page_size){
        keyValuePair_free(keyPairQuery_page_size);
        keyPairQuery_page_size = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

