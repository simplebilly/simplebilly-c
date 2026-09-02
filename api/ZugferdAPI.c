#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "ZugferdAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


void
ZugferdAPI_generateZugferdApi(apiClient_t *apiClient, char *id, char *supplier_name, char *supplier_street, char *supplier_city, char *supplier_zip, char *supplier_country, char *supplier_vat_id)
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
    char *localVarPath = strdup("/api/v1/invoices/{id}/zugferd");

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



    // query parameters
    char *keyQuery_supplier_name = NULL;
    char * valueQuery_supplier_name = NULL;
    keyValuePair_t *keyPairQuery_supplier_name = 0;
    if (supplier_name)
    {
        keyQuery_supplier_name = strdup("supplier_name");
        valueQuery_supplier_name = strdup((supplier_name));
        keyPairQuery_supplier_name = keyValuePair_create(keyQuery_supplier_name, valueQuery_supplier_name);
        list_addElement(localVarQueryParameters,keyPairQuery_supplier_name);
    }

    // query parameters
    char *keyQuery_supplier_street = NULL;
    char * valueQuery_supplier_street = NULL;
    keyValuePair_t *keyPairQuery_supplier_street = 0;
    if (supplier_street)
    {
        keyQuery_supplier_street = strdup("supplier_street");
        valueQuery_supplier_street = strdup((supplier_street));
        keyPairQuery_supplier_street = keyValuePair_create(keyQuery_supplier_street, valueQuery_supplier_street);
        list_addElement(localVarQueryParameters,keyPairQuery_supplier_street);
    }

    // query parameters
    char *keyQuery_supplier_city = NULL;
    char * valueQuery_supplier_city = NULL;
    keyValuePair_t *keyPairQuery_supplier_city = 0;
    if (supplier_city)
    {
        keyQuery_supplier_city = strdup("supplier_city");
        valueQuery_supplier_city = strdup((supplier_city));
        keyPairQuery_supplier_city = keyValuePair_create(keyQuery_supplier_city, valueQuery_supplier_city);
        list_addElement(localVarQueryParameters,keyPairQuery_supplier_city);
    }

    // query parameters
    char *keyQuery_supplier_zip = NULL;
    char * valueQuery_supplier_zip = NULL;
    keyValuePair_t *keyPairQuery_supplier_zip = 0;
    if (supplier_zip)
    {
        keyQuery_supplier_zip = strdup("supplier_zip");
        valueQuery_supplier_zip = strdup((supplier_zip));
        keyPairQuery_supplier_zip = keyValuePair_create(keyQuery_supplier_zip, valueQuery_supplier_zip);
        list_addElement(localVarQueryParameters,keyPairQuery_supplier_zip);
    }

    // query parameters
    char *keyQuery_supplier_country = NULL;
    char * valueQuery_supplier_country = NULL;
    keyValuePair_t *keyPairQuery_supplier_country = 0;
    if (supplier_country)
    {
        keyQuery_supplier_country = strdup("supplier_country");
        valueQuery_supplier_country = strdup((supplier_country));
        keyPairQuery_supplier_country = keyValuePair_create(keyQuery_supplier_country, valueQuery_supplier_country);
        list_addElement(localVarQueryParameters,keyPairQuery_supplier_country);
    }

    // query parameters
    char *keyQuery_supplier_vat_id = NULL;
    char * valueQuery_supplier_vat_id = NULL;
    keyValuePair_t *keyPairQuery_supplier_vat_id = 0;
    if (supplier_vat_id)
    {
        keyQuery_supplier_vat_id = strdup("supplier_vat_id");
        valueQuery_supplier_vat_id = strdup((supplier_vat_id));
        keyPairQuery_supplier_vat_id = keyValuePair_create(keyQuery_supplier_vat_id, valueQuery_supplier_vat_id);
        list_addElement(localVarQueryParameters,keyPairQuery_supplier_vat_id);
    }
    list_addElement(localVarHeaderType,"application/pdf"); //produces
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
    //    printf("%s\n","ZUGFeRD/Factur-X hybrid PDF (PDF/A-3 with embedded EN 16931 XML)");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Invoice not found");
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
    free(localVarToReplace_id);
    if(keyQuery_supplier_name){
        free(keyQuery_supplier_name);
        keyQuery_supplier_name = NULL;
    }
    if(valueQuery_supplier_name){
        free(valueQuery_supplier_name);
        valueQuery_supplier_name = NULL;
    }
    if(keyPairQuery_supplier_name){
        keyValuePair_free(keyPairQuery_supplier_name);
        keyPairQuery_supplier_name = NULL;
    }
    if(keyQuery_supplier_name){
        free(keyQuery_supplier_name);
        keyQuery_supplier_name = NULL;
    }
    if(keyPairQuery_supplier_name){
        keyValuePair_free(keyPairQuery_supplier_name);
        keyPairQuery_supplier_name = NULL;
    }
    if(keyQuery_supplier_street){
        free(keyQuery_supplier_street);
        keyQuery_supplier_street = NULL;
    }
    if(valueQuery_supplier_street){
        free(valueQuery_supplier_street);
        valueQuery_supplier_street = NULL;
    }
    if(keyPairQuery_supplier_street){
        keyValuePair_free(keyPairQuery_supplier_street);
        keyPairQuery_supplier_street = NULL;
    }
    if(keyQuery_supplier_street){
        free(keyQuery_supplier_street);
        keyQuery_supplier_street = NULL;
    }
    if(keyPairQuery_supplier_street){
        keyValuePair_free(keyPairQuery_supplier_street);
        keyPairQuery_supplier_street = NULL;
    }
    if(keyQuery_supplier_city){
        free(keyQuery_supplier_city);
        keyQuery_supplier_city = NULL;
    }
    if(valueQuery_supplier_city){
        free(valueQuery_supplier_city);
        valueQuery_supplier_city = NULL;
    }
    if(keyPairQuery_supplier_city){
        keyValuePair_free(keyPairQuery_supplier_city);
        keyPairQuery_supplier_city = NULL;
    }
    if(keyQuery_supplier_city){
        free(keyQuery_supplier_city);
        keyQuery_supplier_city = NULL;
    }
    if(keyPairQuery_supplier_city){
        keyValuePair_free(keyPairQuery_supplier_city);
        keyPairQuery_supplier_city = NULL;
    }
    if(keyQuery_supplier_zip){
        free(keyQuery_supplier_zip);
        keyQuery_supplier_zip = NULL;
    }
    if(valueQuery_supplier_zip){
        free(valueQuery_supplier_zip);
        valueQuery_supplier_zip = NULL;
    }
    if(keyPairQuery_supplier_zip){
        keyValuePair_free(keyPairQuery_supplier_zip);
        keyPairQuery_supplier_zip = NULL;
    }
    if(keyQuery_supplier_zip){
        free(keyQuery_supplier_zip);
        keyQuery_supplier_zip = NULL;
    }
    if(keyPairQuery_supplier_zip){
        keyValuePair_free(keyPairQuery_supplier_zip);
        keyPairQuery_supplier_zip = NULL;
    }
    if(keyQuery_supplier_country){
        free(keyQuery_supplier_country);
        keyQuery_supplier_country = NULL;
    }
    if(valueQuery_supplier_country){
        free(valueQuery_supplier_country);
        valueQuery_supplier_country = NULL;
    }
    if(keyPairQuery_supplier_country){
        keyValuePair_free(keyPairQuery_supplier_country);
        keyPairQuery_supplier_country = NULL;
    }
    if(keyQuery_supplier_country){
        free(keyQuery_supplier_country);
        keyQuery_supplier_country = NULL;
    }
    if(keyPairQuery_supplier_country){
        keyValuePair_free(keyPairQuery_supplier_country);
        keyPairQuery_supplier_country = NULL;
    }
    if(keyQuery_supplier_vat_id){
        free(keyQuery_supplier_vat_id);
        keyQuery_supplier_vat_id = NULL;
    }
    if(valueQuery_supplier_vat_id){
        free(valueQuery_supplier_vat_id);
        valueQuery_supplier_vat_id = NULL;
    }
    if(keyPairQuery_supplier_vat_id){
        keyValuePair_free(keyPairQuery_supplier_vat_id);
        keyPairQuery_supplier_vat_id = NULL;
    }
    if(keyQuery_supplier_vat_id){
        free(keyQuery_supplier_vat_id);
        keyQuery_supplier_vat_id = NULL;
    }
    if(keyPairQuery_supplier_vat_id){
        keyValuePair_free(keyPairQuery_supplier_vat_id);
        keyPairQuery_supplier_vat_id = NULL;
    }

}

