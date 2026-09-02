#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "ProductAttributeAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


product_attribute_t*
ProductAttributeAPI_createProductAttribute(apiClient_t *apiClient, product_attribute_create_t *product_attribute_create)
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
    char *localVarPath = strdup("/api/v1/product-attributes");





    // Body Param
    cJSON *localVarSingleItemJSON_product_attribute_create = NULL;
    if (product_attribute_create != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_product_attribute_create = product_attribute_create_convertToJSON(product_attribute_create);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_product_attribute_create);
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
    product_attribute_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProductAttributeAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = product_attribute_parseFromJSON(ProductAttributeAPIlocalVarJSON);
        cJSON_Delete(ProductAttributeAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_product_attribute_create) {
        cJSON_Delete(localVarSingleItemJSON_product_attribute_create);
        localVarSingleItemJSON_product_attribute_create = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

void
ProductAttributeAPI_deleteProductAttribute(apiClient_t *apiClient, char *attribute_id)
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
    char *localVarPath = strdup("/api/v1/product-attributes/{attribute_id}");

    if(!attribute_id)
        goto end;


    // Path Params
    long sizeOfPathParams_attribute_id = strlen(attribute_id)+3 + sizeof("{ attribute_id }") - 1;
    if(attribute_id == NULL) {
        goto end;
    }
    char* localVarToReplace_attribute_id = malloc(sizeOfPathParams_attribute_id);
    sprintf(localVarToReplace_attribute_id, "{%s}", "attribute_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_attribute_id, attribute_id);


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
    free(localVarToReplace_attribute_id);

}

product_attribute_t*
ProductAttributeAPI_getProductAttribute(apiClient_t *apiClient, char *attribute_id)
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
    char *localVarPath = strdup("/api/v1/product-attributes/{attribute_id}");

    if(!attribute_id)
        goto end;


    // Path Params
    long sizeOfPathParams_attribute_id = strlen(attribute_id)+3 + sizeof("{ attribute_id }") - 1;
    if(attribute_id == NULL) {
        goto end;
    }
    char* localVarToReplace_attribute_id = malloc(sizeOfPathParams_attribute_id);
    sprintf(localVarToReplace_attribute_id, "{%s}", "attribute_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_attribute_id, attribute_id);


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
    product_attribute_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProductAttributeAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = product_attribute_parseFromJSON(ProductAttributeAPIlocalVarJSON);
        cJSON_Delete(ProductAttributeAPIlocalVarJSON);
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
    free(localVarToReplace_attribute_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

list_t*
ProductAttributeAPI_listProductAttributes(apiClient_t *apiClient, int *page, int *page_size, char *product_id, int *is_filterable, char *search)
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
    char *localVarPath = strdup("/api/v1/product-attributes/");





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
    char *keyQuery_product_id = NULL;
    char * valueQuery_product_id = NULL;
    keyValuePair_t *keyPairQuery_product_id = 0;
    if (product_id)
    {
        keyQuery_product_id = strdup("product_id");
        valueQuery_product_id = strdup((product_id));
        keyPairQuery_product_id = keyValuePair_create(keyQuery_product_id, valueQuery_product_id);
        list_addElement(localVarQueryParameters,keyPairQuery_product_id);
    }

    // query parameters
    char *keyQuery_is_filterable = NULL;
    char * valueQuery_is_filterable = NULL;
    keyValuePair_t *keyPairQuery_is_filterable = 0;
    if (is_filterable)
    {
        keyQuery_is_filterable = strdup("is_filterable");
        valueQuery_is_filterable = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_is_filterable, MAX_NUMBER_LENGTH, "%d", *is_filterable);
        keyPairQuery_is_filterable = keyValuePair_create(keyQuery_is_filterable, valueQuery_is_filterable);
        list_addElement(localVarQueryParameters,keyPairQuery_is_filterable);
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
        cJSON *ProductAttributeAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(ProductAttributeAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, ProductAttributeAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( ProductAttributeAPIlocalVarJSON);
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
    if(keyQuery_product_id){
        free(keyQuery_product_id);
        keyQuery_product_id = NULL;
    }
    if(valueQuery_product_id){
        free(valueQuery_product_id);
        valueQuery_product_id = NULL;
    }
    if(keyPairQuery_product_id){
        keyValuePair_free(keyPairQuery_product_id);
        keyPairQuery_product_id = NULL;
    }
    if(keyQuery_is_filterable){
        free(keyQuery_is_filterable);
        keyQuery_is_filterable = NULL;
    }
    if(valueQuery_is_filterable){
        free(valueQuery_is_filterable);
        valueQuery_is_filterable = NULL;
    }
    if(keyPairQuery_is_filterable){
        keyValuePair_free(keyPairQuery_is_filterable);
        keyPairQuery_is_filterable = NULL;
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

product_attribute_t*
ProductAttributeAPI_updateProductAttribute(apiClient_t *apiClient, char *attribute_id, product_attribute_update_t *product_attribute_update)
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
    char *localVarPath = strdup("/api/v1/product-attributes/{attribute_id}");

    if(!attribute_id)
        goto end;


    // Path Params
    long sizeOfPathParams_attribute_id = strlen(attribute_id)+3 + sizeof("{ attribute_id }") - 1;
    if(attribute_id == NULL) {
        goto end;
    }
    char* localVarToReplace_attribute_id = malloc(sizeOfPathParams_attribute_id);
    sprintf(localVarToReplace_attribute_id, "{%s}", "attribute_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_attribute_id, attribute_id);



    // Body Param
    cJSON *localVarSingleItemJSON_product_attribute_update = NULL;
    if (product_attribute_update != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_product_attribute_update = product_attribute_update_convertToJSON(product_attribute_update);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_product_attribute_update);
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
    product_attribute_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProductAttributeAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = product_attribute_parseFromJSON(ProductAttributeAPIlocalVarJSON);
        cJSON_Delete(ProductAttributeAPIlocalVarJSON);
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
    free(localVarToReplace_attribute_id);
    if (localVarSingleItemJSON_product_attribute_update) {
        cJSON_Delete(localVarSingleItemJSON_product_attribute_update);
        localVarSingleItemJSON_product_attribute_update = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

