#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "GenerateQrcodeAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


qr_code_response_t*
GenerateQrcodeAPI_generateQrcodeApi(apiClient_t *apiClient, char *iban, char *id, char *holder_name, char *bic, char *amount, char *reference, char *purpose)
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
    char *localVarPath = strdup("/api/v1/invoices/{id}/qrcode");

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
    char *keyQuery_iban = NULL;
    char * valueQuery_iban = NULL;
    keyValuePair_t *keyPairQuery_iban = 0;
    if (iban)
    {
        keyQuery_iban = strdup("iban");
        valueQuery_iban = strdup((iban));
        keyPairQuery_iban = keyValuePair_create(keyQuery_iban, valueQuery_iban);
        list_addElement(localVarQueryParameters,keyPairQuery_iban);
    }

    // query parameters
    char *keyQuery_holder_name = NULL;
    char * valueQuery_holder_name = NULL;
    keyValuePair_t *keyPairQuery_holder_name = 0;
    if (holder_name)
    {
        keyQuery_holder_name = strdup("holder_name");
        valueQuery_holder_name = strdup((holder_name));
        keyPairQuery_holder_name = keyValuePair_create(keyQuery_holder_name, valueQuery_holder_name);
        list_addElement(localVarQueryParameters,keyPairQuery_holder_name);
    }

    // query parameters
    char *keyQuery_bic = NULL;
    char * valueQuery_bic = NULL;
    keyValuePair_t *keyPairQuery_bic = 0;
    if (bic)
    {
        keyQuery_bic = strdup("bic");
        valueQuery_bic = strdup((bic));
        keyPairQuery_bic = keyValuePair_create(keyQuery_bic, valueQuery_bic);
        list_addElement(localVarQueryParameters,keyPairQuery_bic);
    }

    // query parameters
    char *keyQuery_amount = NULL;
    char * valueQuery_amount = NULL;
    keyValuePair_t *keyPairQuery_amount = 0;
    if (amount)
    {
        keyQuery_amount = strdup("amount");
        valueQuery_amount = strdup((amount));
        keyPairQuery_amount = keyValuePair_create(keyQuery_amount, valueQuery_amount);
        list_addElement(localVarQueryParameters,keyPairQuery_amount);
    }

    // query parameters
    char *keyQuery_reference = NULL;
    char * valueQuery_reference = NULL;
    keyValuePair_t *keyPairQuery_reference = 0;
    if (reference)
    {
        keyQuery_reference = strdup("reference");
        valueQuery_reference = strdup((reference));
        keyPairQuery_reference = keyValuePair_create(keyQuery_reference, valueQuery_reference);
        list_addElement(localVarQueryParameters,keyPairQuery_reference);
    }

    // query parameters
    char *keyQuery_purpose = NULL;
    char * valueQuery_purpose = NULL;
    keyValuePair_t *keyPairQuery_purpose = 0;
    if (purpose)
    {
        keyQuery_purpose = strdup("purpose");
        valueQuery_purpose = strdup((purpose));
        keyPairQuery_purpose = keyValuePair_create(keyQuery_purpose, valueQuery_purpose);
        list_addElement(localVarQueryParameters,keyPairQuery_purpose);
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
    //    printf("%s\n","QR Code for invoice payment");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Invoice not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    qr_code_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *GenerateQrcodeAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = qr_code_response_parseFromJSON(GenerateQrcodeAPIlocalVarJSON);
        cJSON_Delete(GenerateQrcodeAPIlocalVarJSON);
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
    free(localVarToReplace_id);
    if(keyQuery_iban){
        free(keyQuery_iban);
        keyQuery_iban = NULL;
    }
    if(valueQuery_iban){
        free(valueQuery_iban);
        valueQuery_iban = NULL;
    }
    if(keyPairQuery_iban){
        keyValuePair_free(keyPairQuery_iban);
        keyPairQuery_iban = NULL;
    }
    if(keyQuery_holder_name){
        free(keyQuery_holder_name);
        keyQuery_holder_name = NULL;
    }
    if(valueQuery_holder_name){
        free(valueQuery_holder_name);
        valueQuery_holder_name = NULL;
    }
    if(keyPairQuery_holder_name){
        keyValuePair_free(keyPairQuery_holder_name);
        keyPairQuery_holder_name = NULL;
    }
    if(keyQuery_bic){
        free(keyQuery_bic);
        keyQuery_bic = NULL;
    }
    if(valueQuery_bic){
        free(valueQuery_bic);
        valueQuery_bic = NULL;
    }
    if(keyPairQuery_bic){
        keyValuePair_free(keyPairQuery_bic);
        keyPairQuery_bic = NULL;
    }
    if(keyQuery_amount){
        free(keyQuery_amount);
        keyQuery_amount = NULL;
    }
    if(valueQuery_amount){
        free(valueQuery_amount);
        valueQuery_amount = NULL;
    }
    if(keyPairQuery_amount){
        keyValuePair_free(keyPairQuery_amount);
        keyPairQuery_amount = NULL;
    }
    if(keyQuery_reference){
        free(keyQuery_reference);
        keyQuery_reference = NULL;
    }
    if(valueQuery_reference){
        free(valueQuery_reference);
        valueQuery_reference = NULL;
    }
    if(keyPairQuery_reference){
        keyValuePair_free(keyPairQuery_reference);
        keyPairQuery_reference = NULL;
    }
    if(keyQuery_purpose){
        free(keyQuery_purpose);
        keyQuery_purpose = NULL;
    }
    if(valueQuery_purpose){
        free(valueQuery_purpose);
        valueQuery_purpose = NULL;
    }
    if(keyPairQuery_purpose){
        keyValuePair_free(keyPairQuery_purpose);
        keyPairQuery_purpose = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

