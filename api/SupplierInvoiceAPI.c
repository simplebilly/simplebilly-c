#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "SupplierInvoiceAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


supplier_invoice_t*
SupplierInvoiceAPI_createSupplierInvoice(apiClient_t *apiClient, supplier_invoice_t *supplier_invoice)
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
    char *localVarPath = strdup("/api/v1/supplier-invoices");





    // Body Param
    cJSON *localVarSingleItemJSON_supplier_invoice = NULL;
    if (supplier_invoice != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_supplier_invoice = supplier_invoice_convertToJSON(supplier_invoice);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_supplier_invoice);
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
    supplier_invoice_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SupplierInvoiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = supplier_invoice_parseFromJSON(SupplierInvoiceAPIlocalVarJSON);
        cJSON_Delete(SupplierInvoiceAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_supplier_invoice) {
        cJSON_Delete(localVarSingleItemJSON_supplier_invoice);
        localVarSingleItemJSON_supplier_invoice = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

void
SupplierInvoiceAPI_deleteSupplierInvoice(apiClient_t *apiClient, char *supplier_invoice_id)
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
    char *localVarPath = strdup("/api/v1/supplier-invoices/{supplier_invoice_id}");

    if(!supplier_invoice_id)
        goto end;


    // Path Params
    long sizeOfPathParams_supplier_invoice_id = strlen(supplier_invoice_id)+3 + sizeof("{ supplier_invoice_id }") - 1;
    if(supplier_invoice_id == NULL) {
        goto end;
    }
    char* localVarToReplace_supplier_invoice_id = malloc(sizeOfPathParams_supplier_invoice_id);
    sprintf(localVarToReplace_supplier_invoice_id, "{%s}", "supplier_invoice_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_supplier_invoice_id, supplier_invoice_id);


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
    free(localVarToReplace_supplier_invoice_id);

}

supplier_invoice_t*
SupplierInvoiceAPI_getSupplierInvoice(apiClient_t *apiClient, char *supplier_invoice_id)
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
    char *localVarPath = strdup("/api/v1/supplier-invoices/{supplier_invoice_id}");

    if(!supplier_invoice_id)
        goto end;


    // Path Params
    long sizeOfPathParams_supplier_invoice_id = strlen(supplier_invoice_id)+3 + sizeof("{ supplier_invoice_id }") - 1;
    if(supplier_invoice_id == NULL) {
        goto end;
    }
    char* localVarToReplace_supplier_invoice_id = malloc(sizeOfPathParams_supplier_invoice_id);
    sprintf(localVarToReplace_supplier_invoice_id, "{%s}", "supplier_invoice_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_supplier_invoice_id, supplier_invoice_id);


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
    supplier_invoice_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SupplierInvoiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = supplier_invoice_parseFromJSON(SupplierInvoiceAPIlocalVarJSON);
        cJSON_Delete(SupplierInvoiceAPIlocalVarJSON);
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
    free(localVarToReplace_supplier_invoice_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

list_t*
SupplierInvoiceAPI_listSupplierInvoices(apiClient_t *apiClient, int *page, int *page_size, char *status, char *purchase_order_id, char *supplier_name)
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
    char *localVarPath = strdup("/api/v1/supplier-invoices/");





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
    char *keyQuery_purchase_order_id = NULL;
    char * valueQuery_purchase_order_id = NULL;
    keyValuePair_t *keyPairQuery_purchase_order_id = 0;
    if (purchase_order_id)
    {
        keyQuery_purchase_order_id = strdup("purchase_order_id");
        valueQuery_purchase_order_id = strdup((purchase_order_id));
        keyPairQuery_purchase_order_id = keyValuePair_create(keyQuery_purchase_order_id, valueQuery_purchase_order_id);
        list_addElement(localVarQueryParameters,keyPairQuery_purchase_order_id);
    }

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
        cJSON *SupplierInvoiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(SupplierInvoiceAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, SupplierInvoiceAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( SupplierInvoiceAPIlocalVarJSON);
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
    if(keyQuery_purchase_order_id){
        free(keyQuery_purchase_order_id);
        keyQuery_purchase_order_id = NULL;
    }
    if(valueQuery_purchase_order_id){
        free(valueQuery_purchase_order_id);
        valueQuery_purchase_order_id = NULL;
    }
    if(keyPairQuery_purchase_order_id){
        keyValuePair_free(keyPairQuery_purchase_order_id);
        keyPairQuery_purchase_order_id = NULL;
    }
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

supplier_invoice_t*
SupplierInvoiceAPI_updateSupplierInvoice(apiClient_t *apiClient, char *supplier_invoice_id, body)
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
    char *localVarPath = strdup("/api/v1/supplier-invoices/{supplier_invoice_id}");

    if(!supplier_invoice_id)
        goto end;


    // Path Params
    long sizeOfPathParams_supplier_invoice_id = strlen(supplier_invoice_id)+3 + sizeof("{ supplier_invoice_id }") - 1;
    if(supplier_invoice_id == NULL) {
        goto end;
    }
    char* localVarToReplace_supplier_invoice_id = malloc(sizeOfPathParams_supplier_invoice_id);
    sprintf(localVarToReplace_supplier_invoice_id, "{%s}", "supplier_invoice_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_supplier_invoice_id, supplier_invoice_id);



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
    supplier_invoice_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SupplierInvoiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = supplier_invoice_parseFromJSON(SupplierInvoiceAPIlocalVarJSON);
        cJSON_Delete(SupplierInvoiceAPIlocalVarJSON);
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
    free(localVarToReplace_supplier_invoice_id);
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

supplier_invoice_t*
SupplierInvoiceAPI_updateSupplierInvoiceStatus(apiClient_t *apiClient, char *supplier_invoice_id, supplier_invoice_status_update_t *supplier_invoice_status_update)
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
    char *localVarPath = strdup("/api/v1/supplier-invoices/{supplier_invoice_id}/status");

    if(!supplier_invoice_id)
        goto end;


    // Path Params
    long sizeOfPathParams_supplier_invoice_id = strlen(supplier_invoice_id)+3 + sizeof("{ supplier_invoice_id }") - 1;
    if(supplier_invoice_id == NULL) {
        goto end;
    }
    char* localVarToReplace_supplier_invoice_id = malloc(sizeOfPathParams_supplier_invoice_id);
    sprintf(localVarToReplace_supplier_invoice_id, "{%s}", "supplier_invoice_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_supplier_invoice_id, supplier_invoice_id);



    // Body Param
    cJSON *localVarSingleItemJSON_supplier_invoice_status_update = NULL;
    if (supplier_invoice_status_update != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_supplier_invoice_status_update = supplier_invoice_status_update_convertToJSON(supplier_invoice_status_update);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_supplier_invoice_status_update);
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
    supplier_invoice_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SupplierInvoiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = supplier_invoice_parseFromJSON(SupplierInvoiceAPIlocalVarJSON);
        cJSON_Delete(SupplierInvoiceAPIlocalVarJSON);
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
    free(localVarToReplace_supplier_invoice_id);
    if (localVarSingleItemJSON_supplier_invoice_status_update) {
        cJSON_Delete(localVarSingleItemJSON_supplier_invoice_status_update);
        localVarSingleItemJSON_supplier_invoice_status_update = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

