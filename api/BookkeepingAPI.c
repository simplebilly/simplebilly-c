#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "BookkeepingAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Allocate a payment to an invoice
//
void
BookkeepingAPI_allocatePaymentApi(apiClient_t *apiClient, allocate_payment_request_t *allocate_payment_request)
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
    char *localVarPath = strdup("/api/v1/payments/allocate");





    // Body Param
    cJSON *localVarSingleItemJSON_allocate_payment_request = NULL;
    if (allocate_payment_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_allocate_payment_request = allocate_payment_request_convertToJSON(allocate_payment_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_allocate_payment_request);
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
    //    printf("%s\n","Payment allocated successfully");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Payment or invoice not found");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_allocate_payment_request) {
        cJSON_Delete(localVarSingleItemJSON_allocate_payment_request);
        localVarSingleItemJSON_allocate_payment_request = NULL;
    }
    free(localVarBodyParameters);

}

// Get BWA (Betriebswirtschaftliche Auswertung) report
//
bwa_report_t*
BookkeepingAPI_bwaReportApi(apiClient_t *apiClient, int *year, int *month)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/bwa");





    // query parameters
    char *keyQuery_year = NULL;
    char * valueQuery_year = NULL;
    keyValuePair_t *keyPairQuery_year = 0;
    if (year)
    {
        keyQuery_year = strdup("year");
        valueQuery_year = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_year, MAX_NUMBER_LENGTH, "%d", *year);
        keyPairQuery_year = keyValuePair_create(keyQuery_year, valueQuery_year);
        list_addElement(localVarQueryParameters,keyPairQuery_year);
    }

    // query parameters
    char *keyQuery_month = NULL;
    char * valueQuery_month = NULL;
    keyValuePair_t *keyPairQuery_month = 0;
    if (month)
    {
        keyQuery_month = strdup("month");
        valueQuery_month = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_month, MAX_NUMBER_LENGTH, "%d", *month);
        keyPairQuery_month = keyValuePair_create(keyQuery_month, valueQuery_month);
        list_addElement(localVarQueryParameters,keyPairQuery_month);
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
    //    printf("%s\n","BWA Report");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    bwa_report_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *BookkeepingAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = bwa_report_parseFromJSON(BookkeepingAPIlocalVarJSON);
        cJSON_Delete(BookkeepingAPIlocalVarJSON);
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
    if(keyQuery_year){
        free(keyQuery_year);
        keyQuery_year = NULL;
    }
    if(valueQuery_year){
        free(valueQuery_year);
        valueQuery_year = NULL;
    }
    if(keyPairQuery_year){
        keyValuePair_free(keyPairQuery_year);
        keyPairQuery_year = NULL;
    }
    if(keyQuery_month){
        free(keyQuery_month);
        keyQuery_month = NULL;
    }
    if(valueQuery_month){
        free(valueQuery_month);
        valueQuery_month = NULL;
    }
    if(keyPairQuery_month){
        keyValuePair_free(keyPairQuery_month);
        keyPairQuery_month = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

elster_status_t*
BookkeepingAPI_elsterStatusApi(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/elster/status");




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
    //    printf("%s\n","ELSTER integration status");
    //}
    //nonprimitive not container
    elster_status_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *BookkeepingAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = elster_status_parseFromJSON(BookkeepingAPIlocalVarJSON);
        cJSON_Delete(BookkeepingAPIlocalVarJSON);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

void
BookkeepingAPI_elsterValidateApi(apiClient_t *apiClient, char *zeitraum)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = NULL;
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/api/v1/bookkeeping/ustva/elster-validate");





    // query parameters
    char *keyQuery_zeitraum = NULL;
    char * valueQuery_zeitraum = NULL;
    keyValuePair_t *keyPairQuery_zeitraum = 0;
    if (zeitraum)
    {
        keyQuery_zeitraum = strdup("zeitraum");
        valueQuery_zeitraum = strdup((zeitraum));
        keyPairQuery_zeitraum = keyValuePair_create(keyQuery_zeitraum, valueQuery_zeitraum);
        list_addElement(localVarQueryParameters,keyPairQuery_zeitraum);
    }
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
    //    printf("%s\n","Validate UStVA XML (mock or ERiC)");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    
    
    free(localVarPath);
    if(keyQuery_zeitraum){
        free(keyQuery_zeitraum);
        keyQuery_zeitraum = NULL;
    }
    if(valueQuery_zeitraum){
        free(valueQuery_zeitraum);
        valueQuery_zeitraum = NULL;
    }
    if(keyPairQuery_zeitraum){
        keyValuePair_free(keyPairQuery_zeitraum);
        keyPairQuery_zeitraum = NULL;
    }
    if(keyQuery_zeitraum){
        free(keyQuery_zeitraum);
        keyQuery_zeitraum = NULL;
    }
    if(keyPairQuery_zeitraum){
        keyValuePair_free(keyPairQuery_zeitraum);
        keyPairQuery_zeitraum = NULL;
    }

}

void
BookkeepingAPI_elsterXmlApi(apiClient_t *apiClient, char *zeitraum)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = NULL;
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/api/v1/bookkeeping/ustva/elster-xml");





    // query parameters
    char *keyQuery_zeitraum = NULL;
    char * valueQuery_zeitraum = NULL;
    keyValuePair_t *keyPairQuery_zeitraum = 0;
    if (zeitraum)
    {
        keyQuery_zeitraum = strdup("zeitraum");
        valueQuery_zeitraum = strdup((zeitraum));
        keyPairQuery_zeitraum = keyValuePair_create(keyQuery_zeitraum, valueQuery_zeitraum);
        list_addElement(localVarQueryParameters,keyPairQuery_zeitraum);
    }
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
    //    printf("%s\n","ELSTER UStVA XML template (manual upload)");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    
    
    free(localVarPath);
    if(keyQuery_zeitraum){
        free(keyQuery_zeitraum);
        keyQuery_zeitraum = NULL;
    }
    if(valueQuery_zeitraum){
        free(valueQuery_zeitraum);
        valueQuery_zeitraum = NULL;
    }
    if(keyPairQuery_zeitraum){
        keyValuePair_free(keyPairQuery_zeitraum);
        keyPairQuery_zeitraum = NULL;
    }
    if(keyQuery_zeitraum){
        free(keyQuery_zeitraum);
        keyQuery_zeitraum = NULL;
    }
    if(keyPairQuery_zeitraum){
        keyValuePair_free(keyPairQuery_zeitraum);
        keyPairQuery_zeitraum = NULL;
    }

}

// GET /api/v1/bookkeeping/cashflow Returns operating, investing, and financing cashflow for the given period.
//
cashflow_report_t*
BookkeepingAPI_getCashflow(apiClient_t *apiClient, int *year, int *month)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/cashflow");





    // query parameters
    char *keyQuery_year = NULL;
    char * valueQuery_year = NULL;
    keyValuePair_t *keyPairQuery_year = 0;
    if (year)
    {
        keyQuery_year = strdup("year");
        valueQuery_year = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_year, MAX_NUMBER_LENGTH, "%d", *year);
        keyPairQuery_year = keyValuePair_create(keyQuery_year, valueQuery_year);
        list_addElement(localVarQueryParameters,keyPairQuery_year);
    }

    // query parameters
    char *keyQuery_month = NULL;
    char * valueQuery_month = NULL;
    keyValuePair_t *keyPairQuery_month = 0;
    if (month)
    {
        keyQuery_month = strdup("month");
        valueQuery_month = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_month, MAX_NUMBER_LENGTH, "%d", *month);
        keyPairQuery_month = keyValuePair_create(keyQuery_month, valueQuery_month);
        list_addElement(localVarQueryParameters,keyPairQuery_month);
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
    //    printf("%s\n","Cashflow report");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    cashflow_report_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *BookkeepingAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = cashflow_report_parseFromJSON(BookkeepingAPIlocalVarJSON);
        cJSON_Delete(BookkeepingAPIlocalVarJSON);
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
    if(keyQuery_year){
        free(keyQuery_year);
        keyQuery_year = NULL;
    }
    if(valueQuery_year){
        free(valueQuery_year);
        valueQuery_year = NULL;
    }
    if(keyPairQuery_year){
        keyValuePair_free(keyPairQuery_year);
        keyPairQuery_year = NULL;
    }
    if(keyQuery_month){
        free(keyQuery_month);
        keyQuery_month = NULL;
    }
    if(valueQuery_month){
        free(valueQuery_month);
        valueQuery_month = NULL;
    }
    if(keyPairQuery_month){
        keyValuePair_free(keyPairQuery_month);
        keyPairQuery_month = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// GET /api/v1/bookkeeping/liquidity Returns current liquidity position with ratios.
//
liquidity_position_t*
BookkeepingAPI_getLiquidity(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/liquidity");




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
    //    printf("%s\n","Liquidity position");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    liquidity_position_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *BookkeepingAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = liquidity_position_parseFromJSON(BookkeepingAPIlocalVarJSON);
        cJSON_Delete(BookkeepingAPIlocalVarJSON);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get open invoices for a customer
//
list_t*
BookkeepingAPI_getOpenInvoicesApi(apiClient_t *apiClient, char *customer_id)
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
    char *localVarPath = strdup("/api/v1/payments/open-invoices/{customer_id}");

    if(!customer_id)
        goto end;


    // Path Params
    long sizeOfPathParams_customer_id = strlen(customer_id)+3 + sizeof("{ customer_id }") - 1;
    if(customer_id == NULL) {
        goto end;
    }
    char* localVarToReplace_customer_id = malloc(sizeOfPathParams_customer_id);
    sprintf(localVarToReplace_customer_id, "{%s}", "customer_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_customer_id, customer_id);


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
    //    printf("%s\n","Open invoices list");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Customer not found");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *BookkeepingAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(BookkeepingAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, BookkeepingAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( BookkeepingAPIlocalVarJSON);
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
    free(localVarToReplace_customer_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// GET /api/v1/bookkeeping/verfahrensdokumentation Returns the complete compliance catalog of all documented modules.
//
verfahrensdokumentation_t*
BookkeepingAPI_getVerfahrensdokumentation(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/verfahrensdokumentation");




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
    //    printf("%s\n","Verfahrensdokumentation");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    verfahrensdokumentation_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *BookkeepingAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = verfahrensdokumentation_parseFromJSON(BookkeepingAPIlocalVarJSON);
        cJSON_Delete(BookkeepingAPIlocalVarJSON);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

dunning_result_t*
BookkeepingAPI_runDunningApi(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/dunning");




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
    //    printf("%s\n","Dunning run completed successfully");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    dunning_result_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *BookkeepingAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = dunning_result_parseFromJSON(BookkeepingAPIlocalVarJSON);
        cJSON_Delete(BookkeepingAPIlocalVarJSON);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

