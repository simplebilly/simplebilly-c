#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "ProformaInvoiceAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


convert_response_t*
ProformaInvoiceAPI_convertProformaToInvoice(apiClient_t *apiClient, char *proforma_id)
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
    char *localVarPath = strdup("/api/v1/proforma-invoices/{proforma_id}/convert");

    if(!proforma_id)
        goto end;


    // Path Params
    long sizeOfPathParams_proforma_id = strlen(proforma_id)+3 + sizeof("{ proforma_id }") - 1;
    if(proforma_id == NULL) {
        goto end;
    }
    char* localVarToReplace_proforma_id = malloc(sizeOfPathParams_proforma_id);
    sprintf(localVarToReplace_proforma_id, "{%s}", "proforma_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_proforma_id, proforma_id);


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
    convert_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProformaInvoiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = convert_response_parseFromJSON(ProformaInvoiceAPIlocalVarJSON);
        cJSON_Delete(ProformaInvoiceAPIlocalVarJSON);
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
    free(localVarToReplace_proforma_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

proforma_invoice_t*
ProformaInvoiceAPI_createProformaInvoice(apiClient_t *apiClient, proforma_invoice_t *proforma_invoice)
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
    char *localVarPath = strdup("/api/v1/proforma-invoices");





    // Body Param
    cJSON *localVarSingleItemJSON_proforma_invoice = NULL;
    if (proforma_invoice != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_proforma_invoice = proforma_invoice_convertToJSON(proforma_invoice);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_proforma_invoice);
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
    proforma_invoice_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProformaInvoiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = proforma_invoice_parseFromJSON(ProformaInvoiceAPIlocalVarJSON);
        cJSON_Delete(ProformaInvoiceAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_proforma_invoice) {
        cJSON_Delete(localVarSingleItemJSON_proforma_invoice);
        localVarSingleItemJSON_proforma_invoice = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

void
ProformaInvoiceAPI_deleteProformaInvoice(apiClient_t *apiClient, char *proforma_id)
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
    char *localVarPath = strdup("/api/v1/proforma-invoices/{proforma_id}");

    if(!proforma_id)
        goto end;


    // Path Params
    long sizeOfPathParams_proforma_id = strlen(proforma_id)+3 + sizeof("{ proforma_id }") - 1;
    if(proforma_id == NULL) {
        goto end;
    }
    char* localVarToReplace_proforma_id = malloc(sizeOfPathParams_proforma_id);
    sprintf(localVarToReplace_proforma_id, "{%s}", "proforma_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_proforma_id, proforma_id);


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
    free(localVarToReplace_proforma_id);

}

proforma_invoice_t*
ProformaInvoiceAPI_getProformaInvoice(apiClient_t *apiClient, char *proforma_id)
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
    char *localVarPath = strdup("/api/v1/proforma-invoices/{proforma_id}");

    if(!proforma_id)
        goto end;


    // Path Params
    long sizeOfPathParams_proforma_id = strlen(proforma_id)+3 + sizeof("{ proforma_id }") - 1;
    if(proforma_id == NULL) {
        goto end;
    }
    char* localVarToReplace_proforma_id = malloc(sizeOfPathParams_proforma_id);
    sprintf(localVarToReplace_proforma_id, "{%s}", "proforma_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_proforma_id, proforma_id);


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
    proforma_invoice_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProformaInvoiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = proforma_invoice_parseFromJSON(ProformaInvoiceAPIlocalVarJSON);
        cJSON_Delete(ProformaInvoiceAPIlocalVarJSON);
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
    free(localVarToReplace_proforma_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

list_t*
ProformaInvoiceAPI_listProformaInvoices(apiClient_t *apiClient, int *page, int *page_size, char *status, char *customer_id, char *order_number)
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
    char *localVarPath = strdup("/api/v1/proforma-invoices/");





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
    char *keyQuery_customer_id = NULL;
    char * valueQuery_customer_id = NULL;
    keyValuePair_t *keyPairQuery_customer_id = 0;
    if (customer_id)
    {
        keyQuery_customer_id = strdup("customer_id");
        valueQuery_customer_id = strdup((customer_id));
        keyPairQuery_customer_id = keyValuePair_create(keyQuery_customer_id, valueQuery_customer_id);
        list_addElement(localVarQueryParameters,keyPairQuery_customer_id);
    }

    // query parameters
    char *keyQuery_order_number = NULL;
    char * valueQuery_order_number = NULL;
    keyValuePair_t *keyPairQuery_order_number = 0;
    if (order_number)
    {
        keyQuery_order_number = strdup("order_number");
        valueQuery_order_number = strdup((order_number));
        keyPairQuery_order_number = keyValuePair_create(keyQuery_order_number, valueQuery_order_number);
        list_addElement(localVarQueryParameters,keyPairQuery_order_number);
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
        cJSON *ProformaInvoiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(ProformaInvoiceAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, ProformaInvoiceAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( ProformaInvoiceAPIlocalVarJSON);
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
    if(keyQuery_customer_id){
        free(keyQuery_customer_id);
        keyQuery_customer_id = NULL;
    }
    if(valueQuery_customer_id){
        free(valueQuery_customer_id);
        valueQuery_customer_id = NULL;
    }
    if(keyPairQuery_customer_id){
        keyValuePair_free(keyPairQuery_customer_id);
        keyPairQuery_customer_id = NULL;
    }
    if(keyQuery_order_number){
        free(keyQuery_order_number);
        keyQuery_order_number = NULL;
    }
    if(valueQuery_order_number){
        free(valueQuery_order_number);
        valueQuery_order_number = NULL;
    }
    if(keyPairQuery_order_number){
        keyValuePair_free(keyPairQuery_order_number);
        keyPairQuery_order_number = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

proforma_invoice_t*
ProformaInvoiceAPI_updateProformaInvoice(apiClient_t *apiClient, char *proforma_id, body)
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
    char *localVarPath = strdup("/api/v1/proforma-invoices/{proforma_id}");

    if(!proforma_id)
        goto end;


    // Path Params
    long sizeOfPathParams_proforma_id = strlen(proforma_id)+3 + sizeof("{ proforma_id }") - 1;
    if(proforma_id == NULL) {
        goto end;
    }
    char* localVarToReplace_proforma_id = malloc(sizeOfPathParams_proforma_id);
    sprintf(localVarToReplace_proforma_id, "{%s}", "proforma_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_proforma_id, proforma_id);



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
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    proforma_invoice_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProformaInvoiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = proforma_invoice_parseFromJSON(ProformaInvoiceAPIlocalVarJSON);
        cJSON_Delete(ProformaInvoiceAPIlocalVarJSON);
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
    free(localVarToReplace_proforma_id);
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

