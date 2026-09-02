#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "SupplierConditionAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


supplier_condition_t*
SupplierConditionAPI_createSupplierCondition(apiClient_t *apiClient, supplier_condition_create_t *supplier_condition_create)
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
    char *localVarPath = strdup("/api/v1/supplier-conditions");





    // Body Param
    cJSON *localVarSingleItemJSON_supplier_condition_create = NULL;
    if (supplier_condition_create != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_supplier_condition_create = supplier_condition_create_convertToJSON(supplier_condition_create);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_supplier_condition_create);
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
    supplier_condition_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SupplierConditionAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = supplier_condition_parseFromJSON(SupplierConditionAPIlocalVarJSON);
        cJSON_Delete(SupplierConditionAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_supplier_condition_create) {
        cJSON_Delete(localVarSingleItemJSON_supplier_condition_create);
        localVarSingleItemJSON_supplier_condition_create = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

void
SupplierConditionAPI_deleteSupplierCondition(apiClient_t *apiClient, char *supplier_condition_id)
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
    char *localVarPath = strdup("/api/v1/supplier-conditions/{supplier_condition_id}");

    if(!supplier_condition_id)
        goto end;


    // Path Params
    long sizeOfPathParams_supplier_condition_id = strlen(supplier_condition_id)+3 + sizeof("{ supplier_condition_id }") - 1;
    if(supplier_condition_id == NULL) {
        goto end;
    }
    char* localVarToReplace_supplier_condition_id = malloc(sizeOfPathParams_supplier_condition_id);
    sprintf(localVarToReplace_supplier_condition_id, "{%s}", "supplier_condition_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_supplier_condition_id, supplier_condition_id);


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
    free(localVarToReplace_supplier_condition_id);

}

supplier_condition_t*
SupplierConditionAPI_getSupplierCondition(apiClient_t *apiClient, char *supplier_condition_id)
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
    char *localVarPath = strdup("/api/v1/supplier-conditions/{supplier_condition_id}");

    if(!supplier_condition_id)
        goto end;


    // Path Params
    long sizeOfPathParams_supplier_condition_id = strlen(supplier_condition_id)+3 + sizeof("{ supplier_condition_id }") - 1;
    if(supplier_condition_id == NULL) {
        goto end;
    }
    char* localVarToReplace_supplier_condition_id = malloc(sizeOfPathParams_supplier_condition_id);
    sprintf(localVarToReplace_supplier_condition_id, "{%s}", "supplier_condition_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_supplier_condition_id, supplier_condition_id);


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
    supplier_condition_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SupplierConditionAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = supplier_condition_parseFromJSON(SupplierConditionAPIlocalVarJSON);
        cJSON_Delete(SupplierConditionAPIlocalVarJSON);
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
    free(localVarToReplace_supplier_condition_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

list_t*
SupplierConditionAPI_listSupplierConditions(apiClient_t *apiClient, int *page, int *page_size, char *supplier_contact_id, char *search)
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
    char *localVarPath = strdup("/api/v1/supplier-conditions/");





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
    char *keyQuery_supplier_contact_id = NULL;
    char * valueQuery_supplier_contact_id = NULL;
    keyValuePair_t *keyPairQuery_supplier_contact_id = 0;
    if (supplier_contact_id)
    {
        keyQuery_supplier_contact_id = strdup("supplier_contact_id");
        valueQuery_supplier_contact_id = strdup((supplier_contact_id));
        keyPairQuery_supplier_contact_id = keyValuePair_create(keyQuery_supplier_contact_id, valueQuery_supplier_contact_id);
        list_addElement(localVarQueryParameters,keyPairQuery_supplier_contact_id);
    }

    // query parameters
    char *keyQuery_search = NULL;
    char * valueQuery_search = NULL;
    keyValuePair_t *keyPairQuery_search = 0;
    if (search)
    {
        keyQuery_search = strdup("search");
        valueQuery_search = strdup((search));
        keyPairQuery_search = keyValuePair_create(keyQuery_search, valueQuery_search);
        list_addElement(localVarQueryParameters,keyPairQuery_search);
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
        cJSON *SupplierConditionAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(SupplierConditionAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, SupplierConditionAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( SupplierConditionAPIlocalVarJSON);
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
    if(keyQuery_supplier_contact_id){
        free(keyQuery_supplier_contact_id);
        keyQuery_supplier_contact_id = NULL;
    }
    if(valueQuery_supplier_contact_id){
        free(valueQuery_supplier_contact_id);
        valueQuery_supplier_contact_id = NULL;
    }
    if(keyPairQuery_supplier_contact_id){
        keyValuePair_free(keyPairQuery_supplier_contact_id);
        keyPairQuery_supplier_contact_id = NULL;
    }
    if(keyQuery_search){
        free(keyQuery_search);
        keyQuery_search = NULL;
    }
    if(valueQuery_search){
        free(valueQuery_search);
        valueQuery_search = NULL;
    }
    if(keyPairQuery_search){
        keyValuePair_free(keyPairQuery_search);
        keyPairQuery_search = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

supplier_condition_t*
SupplierConditionAPI_updateSupplierCondition(apiClient_t *apiClient, char *supplier_condition_id, supplier_condition_update_t *supplier_condition_update)
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
    char *localVarPath = strdup("/api/v1/supplier-conditions/{supplier_condition_id}");

    if(!supplier_condition_id)
        goto end;


    // Path Params
    long sizeOfPathParams_supplier_condition_id = strlen(supplier_condition_id)+3 + sizeof("{ supplier_condition_id }") - 1;
    if(supplier_condition_id == NULL) {
        goto end;
    }
    char* localVarToReplace_supplier_condition_id = malloc(sizeOfPathParams_supplier_condition_id);
    sprintf(localVarToReplace_supplier_condition_id, "{%s}", "supplier_condition_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_supplier_condition_id, supplier_condition_id);



    // Body Param
    cJSON *localVarSingleItemJSON_supplier_condition_update = NULL;
    if (supplier_condition_update != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_supplier_condition_update = supplier_condition_update_convertToJSON(supplier_condition_update);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_supplier_condition_update);
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
    supplier_condition_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SupplierConditionAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = supplier_condition_parseFromJSON(SupplierConditionAPIlocalVarJSON);
        cJSON_Delete(SupplierConditionAPIlocalVarJSON);
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
    free(localVarToReplace_supplier_condition_id);
    if (localVarSingleItemJSON_supplier_condition_update) {
        cJSON_Delete(localVarSingleItemJSON_supplier_condition_update);
        localVarSingleItemJSON_supplier_condition_update = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

