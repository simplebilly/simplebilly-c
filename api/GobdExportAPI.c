#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "GobdExportAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


go_bd_export_response_t*
GobdExportAPI_buchhalterCsvApi(apiClient_t *apiClient, char *date_from, char *date_to)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/buchhalter-csv");





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
    //    printf("%s\n","Buchhalter CSV");
    //}
    //nonprimitive not container
    go_bd_export_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *GobdExportAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = go_bd_export_response_parseFromJSON(GobdExportAPIlocalVarJSON);
        cJSON_Delete(GobdExportAPIlocalVarJSON);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// GoBD/GDPdU export. Default: ZIP archive (`index.xml` + CSV tables, IDEA format). `?format=csv` returns the legacy single-journal CSV as JSON.
//
void
GobdExportAPI_gobdExportApi(apiClient_t *apiClient, int *year, char *format)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/gobd");





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
    char *keyQuery_format = NULL;
    char * valueQuery_format = NULL;
    keyValuePair_t *keyPairQuery_format = 0;
    if (format)
    {
        keyQuery_format = strdup("format");
        valueQuery_format = strdup((format));
        keyPairQuery_format = keyValuePair_create(keyQuery_format, valueQuery_format);
        list_addElement(localVarQueryParameters,keyPairQuery_format);
    }
    list_addElement(localVarHeaderType,"application/zip"); //produces
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
    //    printf("%s\n","GoBD/GDPdU export: ZIP (application/zip) with index.xml (IDEA table specification) and one UTF-8 CSV per tax-relevant table; legacy single-journal CSV JSON via ?format&#x3D;csv");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad request");
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
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    if(keyQuery_format){
        free(keyQuery_format);
        keyQuery_format = NULL;
    }
    if(valueQuery_format){
        free(valueQuery_format);
        valueQuery_format = NULL;
    }
    if(keyPairQuery_format){
        keyValuePair_free(keyPairQuery_format);
        keyPairQuery_format = NULL;
    }
    if(keyQuery_format){
        free(keyQuery_format);
        keyQuery_format = NULL;
    }
    if(keyPairQuery_format){
        keyValuePair_free(keyPairQuery_format);
        keyPairQuery_format = NULL;
    }

}

