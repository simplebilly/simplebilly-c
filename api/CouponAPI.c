#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "CouponAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


coupon_t*
CouponAPI_couponRestore(apiClient_t *apiClient, char *coupon_id)
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
    char *localVarPath = strdup("/api/v1/coupons/{coupon_id}/restore");

    if(!coupon_id)
        goto end;


    // Path Params
    long sizeOfPathParams_coupon_id = strlen(coupon_id)+3 + sizeof("{ coupon_id }") - 1;
    if(coupon_id == NULL) {
        goto end;
    }
    char* localVarToReplace_coupon_id = malloc(sizeOfPathParams_coupon_id);
    sprintf(localVarToReplace_coupon_id, "{%s}", "coupon_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_coupon_id, coupon_id);


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
    coupon_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CouponAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = coupon_parseFromJSON(CouponAPIlocalVarJSON);
        cJSON_Delete(CouponAPIlocalVarJSON);
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
    free(localVarToReplace_coupon_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

coupon_t*
CouponAPI_createCoupon(apiClient_t *apiClient, coupon_create_t *coupon_create)
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
    char *localVarPath = strdup("/api/v1/coupons");





    // Body Param
    cJSON *localVarSingleItemJSON_coupon_create = NULL;
    if (coupon_create != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_coupon_create = coupon_create_convertToJSON(coupon_create);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_coupon_create);
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
    coupon_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CouponAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = coupon_parseFromJSON(CouponAPIlocalVarJSON);
        cJSON_Delete(CouponAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_coupon_create) {
        cJSON_Delete(localVarSingleItemJSON_coupon_create);
        localVarSingleItemJSON_coupon_create = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

void
CouponAPI_deleteCoupon(apiClient_t *apiClient, char *coupon_id)
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
    char *localVarPath = strdup("/api/v1/coupons/{coupon_id}");

    if(!coupon_id)
        goto end;


    // Path Params
    long sizeOfPathParams_coupon_id = strlen(coupon_id)+3 + sizeof("{ coupon_id }") - 1;
    if(coupon_id == NULL) {
        goto end;
    }
    char* localVarToReplace_coupon_id = malloc(sizeOfPathParams_coupon_id);
    sprintf(localVarToReplace_coupon_id, "{%s}", "coupon_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_coupon_id, coupon_id);


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
    free(localVarToReplace_coupon_id);

}

coupon_t*
CouponAPI_getCoupon(apiClient_t *apiClient, char *coupon_id)
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
    char *localVarPath = strdup("/api/v1/coupons/{coupon_id}");

    if(!coupon_id)
        goto end;


    // Path Params
    long sizeOfPathParams_coupon_id = strlen(coupon_id)+3 + sizeof("{ coupon_id }") - 1;
    if(coupon_id == NULL) {
        goto end;
    }
    char* localVarToReplace_coupon_id = malloc(sizeOfPathParams_coupon_id);
    sprintf(localVarToReplace_coupon_id, "{%s}", "coupon_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_coupon_id, coupon_id);


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
    coupon_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CouponAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = coupon_parseFromJSON(CouponAPIlocalVarJSON);
        cJSON_Delete(CouponAPIlocalVarJSON);
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
    free(localVarToReplace_coupon_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

list_t*
CouponAPI_listCoupons(apiClient_t *apiClient, int *page, int *page_size, int *is_active, char *code, char *discount_type)
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
    char *localVarPath = strdup("/api/v1/coupons/");





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
    char *keyQuery_is_active = NULL;
    char * valueQuery_is_active = NULL;
    keyValuePair_t *keyPairQuery_is_active = 0;
    if (is_active)
    {
        keyQuery_is_active = strdup("is_active");
        valueQuery_is_active = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_is_active, MAX_NUMBER_LENGTH, "%d", *is_active);
        keyPairQuery_is_active = keyValuePair_create(keyQuery_is_active, valueQuery_is_active);
        list_addElement(localVarQueryParameters,keyPairQuery_is_active);
    }

    // query parameters
    char *keyQuery_code = NULL;
    char * valueQuery_code = NULL;
    keyValuePair_t *keyPairQuery_code = 0;
    if (code)
    {
        keyQuery_code = strdup("code");
        valueQuery_code = strdup((code));
        keyPairQuery_code = keyValuePair_create(keyQuery_code, valueQuery_code);
        list_addElement(localVarQueryParameters,keyPairQuery_code);
    }

    // query parameters
    char *keyQuery_discount_type = NULL;
    char * valueQuery_discount_type = NULL;
    keyValuePair_t *keyPairQuery_discount_type = 0;
    if (discount_type)
    {
        keyQuery_discount_type = strdup("discount_type");
        valueQuery_discount_type = strdup((discount_type));
        keyPairQuery_discount_type = keyValuePair_create(keyQuery_discount_type, valueQuery_discount_type);
        list_addElement(localVarQueryParameters,keyPairQuery_discount_type);
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
        cJSON *CouponAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(CouponAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, CouponAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( CouponAPIlocalVarJSON);
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
    if(keyQuery_is_active){
        free(keyQuery_is_active);
        keyQuery_is_active = NULL;
    }
    if(valueQuery_is_active){
        free(valueQuery_is_active);
        valueQuery_is_active = NULL;
    }
    if(keyPairQuery_is_active){
        keyValuePair_free(keyPairQuery_is_active);
        keyPairQuery_is_active = NULL;
    }
    if(keyQuery_code){
        free(keyQuery_code);
        keyQuery_code = NULL;
    }
    if(valueQuery_code){
        free(valueQuery_code);
        valueQuery_code = NULL;
    }
    if(keyPairQuery_code){
        keyValuePair_free(keyPairQuery_code);
        keyPairQuery_code = NULL;
    }
    if(keyQuery_discount_type){
        free(keyQuery_discount_type);
        keyQuery_discount_type = NULL;
    }
    if(valueQuery_discount_type){
        free(valueQuery_discount_type);
        valueQuery_discount_type = NULL;
    }
    if(keyPairQuery_discount_type){
        keyValuePair_free(keyPairQuery_discount_type);
        keyPairQuery_discount_type = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

coupon_t*
CouponAPI_updateCoupon(apiClient_t *apiClient, char *coupon_id, coupon_update_t *coupon_update)
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
    char *localVarPath = strdup("/api/v1/coupons/{coupon_id}");

    if(!coupon_id)
        goto end;


    // Path Params
    long sizeOfPathParams_coupon_id = strlen(coupon_id)+3 + sizeof("{ coupon_id }") - 1;
    if(coupon_id == NULL) {
        goto end;
    }
    char* localVarToReplace_coupon_id = malloc(sizeOfPathParams_coupon_id);
    sprintf(localVarToReplace_coupon_id, "{%s}", "coupon_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_coupon_id, coupon_id);



    // Body Param
    cJSON *localVarSingleItemJSON_coupon_update = NULL;
    if (coupon_update != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_coupon_update = coupon_update_convertToJSON(coupon_update);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_coupon_update);
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
    coupon_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CouponAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = coupon_parseFromJSON(CouponAPIlocalVarJSON);
        cJSON_Delete(CouponAPIlocalVarJSON);
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
    free(localVarToReplace_coupon_id);
    if (localVarSingleItemJSON_coupon_update) {
        cJSON_Delete(localVarSingleItemJSON_coupon_update);
        localVarSingleItemJSON_coupon_update = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

