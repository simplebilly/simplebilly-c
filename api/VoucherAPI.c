#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "VoucherAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


voucher_t*
VoucherAPI_createVoucher(apiClient_t *apiClient, voucher_create_t *voucher_create)
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
    char *localVarPath = strdup("/api/v1/vouchers");





    // Body Param
    cJSON *localVarSingleItemJSON_voucher_create = NULL;
    if (voucher_create != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_voucher_create = voucher_create_convertToJSON(voucher_create);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_voucher_create);
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
    voucher_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *VoucherAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = voucher_parseFromJSON(VoucherAPIlocalVarJSON);
        cJSON_Delete(VoucherAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_voucher_create) {
        cJSON_Delete(localVarSingleItemJSON_voucher_create);
        localVarSingleItemJSON_voucher_create = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

void
VoucherAPI_deleteVoucher(apiClient_t *apiClient, char *voucher_id)
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
    char *localVarPath = strdup("/api/v1/vouchers/{voucher_id}");

    if(!voucher_id)
        goto end;


    // Path Params
    long sizeOfPathParams_voucher_id = strlen(voucher_id)+3 + sizeof("{ voucher_id }") - 1;
    if(voucher_id == NULL) {
        goto end;
    }
    char* localVarToReplace_voucher_id = malloc(sizeOfPathParams_voucher_id);
    sprintf(localVarToReplace_voucher_id, "{%s}", "voucher_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_voucher_id, voucher_id);


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
    free(localVarToReplace_voucher_id);

}

voucher_t*
VoucherAPI_getVoucher(apiClient_t *apiClient, char *voucher_id)
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
    char *localVarPath = strdup("/api/v1/vouchers/{voucher_id}");

    if(!voucher_id)
        goto end;


    // Path Params
    long sizeOfPathParams_voucher_id = strlen(voucher_id)+3 + sizeof("{ voucher_id }") - 1;
    if(voucher_id == NULL) {
        goto end;
    }
    char* localVarToReplace_voucher_id = malloc(sizeOfPathParams_voucher_id);
    sprintf(localVarToReplace_voucher_id, "{%s}", "voucher_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_voucher_id, voucher_id);


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
    voucher_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *VoucherAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = voucher_parseFromJSON(VoucherAPIlocalVarJSON);
        cJSON_Delete(VoucherAPIlocalVarJSON);
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
    free(localVarToReplace_voucher_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

list_t*
VoucherAPI_listVouchers(apiClient_t *apiClient, int *page, int *page_size, char *voucher_type, char *voucher_status, char *contact_name, char date_from, char date_to)
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
    char *localVarPath = strdup("/api/v1/vouchers/");





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
    char *keyQuery_voucher_type = NULL;
    char * valueQuery_voucher_type = NULL;
    keyValuePair_t *keyPairQuery_voucher_type = 0;
    if (voucher_type)
    {
        keyQuery_voucher_type = strdup("voucher_type");
        valueQuery_voucher_type = strdup((voucher_type));
        keyPairQuery_voucher_type = keyValuePair_create(keyQuery_voucher_type, valueQuery_voucher_type);
        list_addElement(localVarQueryParameters,keyPairQuery_voucher_type);
    }

    // query parameters
    char *keyQuery_voucher_status = NULL;
    char * valueQuery_voucher_status = NULL;
    keyValuePair_t *keyPairQuery_voucher_status = 0;
    if (voucher_status)
    {
        keyQuery_voucher_status = strdup("voucher_status");
        valueQuery_voucher_status = strdup((voucher_status));
        keyPairQuery_voucher_status = keyValuePair_create(keyQuery_voucher_status, valueQuery_voucher_status);
        list_addElement(localVarQueryParameters,keyPairQuery_voucher_status);
    }

    // query parameters
    char *keyQuery_contact_name = NULL;
    char * valueQuery_contact_name = NULL;
    keyValuePair_t *keyPairQuery_contact_name = 0;
    if (contact_name)
    {
        keyQuery_contact_name = strdup("contact_name");
        valueQuery_contact_name = strdup((contact_name));
        keyPairQuery_contact_name = keyValuePair_create(keyQuery_contact_name, valueQuery_contact_name);
        list_addElement(localVarQueryParameters,keyPairQuery_contact_name);
    }

    // query parameters
    char *keyQuery_date_from = NULL;
    char valueQuery_date_from ;
    keyValuePair_t *keyPairQuery_date_from = 0;
    if (date_from)
    {
        keyQuery_date_from = strdup("date_from");
        valueQuery_date_from = (date_from);
        keyPairQuery_date_from = keyValuePair_create(keyQuery_date_from, &valueQuery_date_from);
        list_addElement(localVarQueryParameters,keyPairQuery_date_from);
    }

    // query parameters
    char *keyQuery_date_to = NULL;
    char valueQuery_date_to ;
    keyValuePair_t *keyPairQuery_date_to = 0;
    if (date_to)
    {
        keyQuery_date_to = strdup("date_to");
        valueQuery_date_to = (date_to);
        keyPairQuery_date_to = keyValuePair_create(keyQuery_date_to, &valueQuery_date_to);
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
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *VoucherAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(VoucherAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, VoucherAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( VoucherAPIlocalVarJSON);
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
    if(keyQuery_voucher_type){
        free(keyQuery_voucher_type);
        keyQuery_voucher_type = NULL;
    }
    if(valueQuery_voucher_type){
        free(valueQuery_voucher_type);
        valueQuery_voucher_type = NULL;
    }
    if(keyPairQuery_voucher_type){
        keyValuePair_free(keyPairQuery_voucher_type);
        keyPairQuery_voucher_type = NULL;
    }
    if(keyQuery_voucher_status){
        free(keyQuery_voucher_status);
        keyQuery_voucher_status = NULL;
    }
    if(valueQuery_voucher_status){
        free(valueQuery_voucher_status);
        valueQuery_voucher_status = NULL;
    }
    if(keyPairQuery_voucher_status){
        keyValuePair_free(keyPairQuery_voucher_status);
        keyPairQuery_voucher_status = NULL;
    }
    if(keyQuery_contact_name){
        free(keyQuery_contact_name);
        keyQuery_contact_name = NULL;
    }
    if(valueQuery_contact_name){
        free(valueQuery_contact_name);
        valueQuery_contact_name = NULL;
    }
    if(keyPairQuery_contact_name){
        keyValuePair_free(keyPairQuery_contact_name);
        keyPairQuery_contact_name = NULL;
    }
    if(keyQuery_date_from){
        free(keyQuery_date_from);
        keyQuery_date_from = NULL;
    }
    if(keyPairQuery_date_from){
        keyValuePair_free(keyPairQuery_date_from);
        keyPairQuery_date_from = NULL;
    }
    if(keyQuery_date_to){
        free(keyQuery_date_to);
        keyQuery_date_to = NULL;
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

voucher_t*
VoucherAPI_updateVoucher(apiClient_t *apiClient, char *voucher_id, body)
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
    char *localVarPath = strdup("/api/v1/vouchers/{voucher_id}");

    if(!voucher_id)
        goto end;


    // Path Params
    long sizeOfPathParams_voucher_id = strlen(voucher_id)+3 + sizeof("{ voucher_id }") - 1;
    if(voucher_id == NULL) {
        goto end;
    }
    char* localVarToReplace_voucher_id = malloc(sizeOfPathParams_voucher_id);
    sprintf(localVarToReplace_voucher_id, "{%s}", "voucher_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_voucher_id, voucher_id);



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
    //    printf("%s\n","Voucher not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    voucher_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *VoucherAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = voucher_parseFromJSON(VoucherAPIlocalVarJSON);
        cJSON_Delete(VoucherAPIlocalVarJSON);
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
    free(localVarToReplace_voucher_id);
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

voucher_t*
VoucherAPI_voucherRestore(apiClient_t *apiClient, char *voucher_id)
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
    char *localVarPath = strdup("/api/v1/vouchers/{voucher_id}/restore");

    if(!voucher_id)
        goto end;


    // Path Params
    long sizeOfPathParams_voucher_id = strlen(voucher_id)+3 + sizeof("{ voucher_id }") - 1;
    if(voucher_id == NULL) {
        goto end;
    }
    char* localVarToReplace_voucher_id = malloc(sizeOfPathParams_voucher_id);
    sprintf(localVarToReplace_voucher_id, "{%s}", "voucher_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_voucher_id, voucher_id);


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
    //    printf("%s\n","Restored");
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
    voucher_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *VoucherAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = voucher_parseFromJSON(VoucherAPIlocalVarJSON);
        cJSON_Delete(VoucherAPIlocalVarJSON);
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
    free(localVarToReplace_voucher_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

