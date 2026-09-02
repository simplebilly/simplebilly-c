#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "ReportsAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Bilanz (Balance Sheet)
//
bilanz_report_t*
ReportsAPI_bilanzReportApi(apiClient_t *apiClient, int *year, int *month, char *date_from, char *date_to, int *page, int *page_size)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/reports/bilanz");





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
    //    printf("%s\n","Balance sheet");
    //}
    //nonprimitive not container
    bilanz_report_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ReportsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = bilanz_report_parseFromJSON(ReportsAPIlocalVarJSON);
        cJSON_Delete(ReportsAPIlocalVarJSON);
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

// Gewinn- und Verlustrechnung (P&L statement)
//
gu_v_report_t*
ReportsAPI_guvReportApi(apiClient_t *apiClient, int *year, int *month, char *date_from, char *date_to, int *page, int *page_size)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/reports/guv");





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
    //    printf("%s\n","GuV report");
    //}
    //nonprimitive not container
    gu_v_report_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ReportsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = gu_v_report_parseFromJSON(ReportsAPIlocalVarJSON);
        cJSON_Delete(ReportsAPIlocalVarJSON);
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

// Kontenansicht (Account Overview)
//
konto_report_t*
ReportsAPI_kontenansichtReportApi(apiClient_t *apiClient, int *year, int *month, char *date_from, char *date_to, int *page, int *page_size)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/reports/kontenansicht");





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
    //    printf("%s\n","Account overview");
    //}
    //nonprimitive not container
    konto_report_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ReportsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = konto_report_parseFromJSON(ReportsAPIlocalVarJSON);
        cJSON_Delete(ReportsAPIlocalVarJSON);
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

// Umsatzsteuer-Voranmeldung (VAT report)
//
umsatzsteuer_report_t*
ReportsAPI_umsatzsteuerReportApi(apiClient_t *apiClient, int *year, int *month, char *date_from, char *date_to, int *page, int *page_size)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/reports/umsatzsteuer");





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
    //    printf("%s\n","VAT report");
    //}
    //nonprimitive not container
    umsatzsteuer_report_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ReportsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = umsatzsteuer_report_parseFromJSON(ReportsAPIlocalVarJSON);
        cJSON_Delete(ReportsAPIlocalVarJSON);
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

