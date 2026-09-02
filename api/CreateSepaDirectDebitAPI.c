#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "CreateSepaDirectDebitAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


sepa_direct_debit_response_t*
CreateSepaDirectDebitAPI_createSepaDirectDebitApi(apiClient_t *apiClient, char *creditor_name, char *creditor_iban, char *creditor_id, char *mandate_id, char *mandate_date, char *debtor_name, char *debtor_iban, char *amount, char *collection_date, char *creditor_bic, char *debtor_bic, char *description)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/sepa-direct-debit");





    // query parameters
    char *keyQuery_creditor_name = NULL;
    char * valueQuery_creditor_name = NULL;
    keyValuePair_t *keyPairQuery_creditor_name = 0;
    if (creditor_name)
    {
        keyQuery_creditor_name = strdup("creditor_name");
        valueQuery_creditor_name = strdup((creditor_name));
        keyPairQuery_creditor_name = keyValuePair_create(keyQuery_creditor_name, valueQuery_creditor_name);
        list_addElement(localVarQueryParameters,keyPairQuery_creditor_name);
    }

    // query parameters
    char *keyQuery_creditor_iban = NULL;
    char * valueQuery_creditor_iban = NULL;
    keyValuePair_t *keyPairQuery_creditor_iban = 0;
    if (creditor_iban)
    {
        keyQuery_creditor_iban = strdup("creditor_iban");
        valueQuery_creditor_iban = strdup((creditor_iban));
        keyPairQuery_creditor_iban = keyValuePair_create(keyQuery_creditor_iban, valueQuery_creditor_iban);
        list_addElement(localVarQueryParameters,keyPairQuery_creditor_iban);
    }

    // query parameters
    char *keyQuery_creditor_bic = NULL;
    char * valueQuery_creditor_bic = NULL;
    keyValuePair_t *keyPairQuery_creditor_bic = 0;
    if (creditor_bic)
    {
        keyQuery_creditor_bic = strdup("creditor_bic");
        valueQuery_creditor_bic = strdup((creditor_bic));
        keyPairQuery_creditor_bic = keyValuePair_create(keyQuery_creditor_bic, valueQuery_creditor_bic);
        list_addElement(localVarQueryParameters,keyPairQuery_creditor_bic);
    }

    // query parameters
    char *keyQuery_creditor_id = NULL;
    char * valueQuery_creditor_id = NULL;
    keyValuePair_t *keyPairQuery_creditor_id = 0;
    if (creditor_id)
    {
        keyQuery_creditor_id = strdup("creditor_id");
        valueQuery_creditor_id = strdup((creditor_id));
        keyPairQuery_creditor_id = keyValuePair_create(keyQuery_creditor_id, valueQuery_creditor_id);
        list_addElement(localVarQueryParameters,keyPairQuery_creditor_id);
    }

    // query parameters
    char *keyQuery_mandate_id = NULL;
    char * valueQuery_mandate_id = NULL;
    keyValuePair_t *keyPairQuery_mandate_id = 0;
    if (mandate_id)
    {
        keyQuery_mandate_id = strdup("mandate_id");
        valueQuery_mandate_id = strdup((mandate_id));
        keyPairQuery_mandate_id = keyValuePair_create(keyQuery_mandate_id, valueQuery_mandate_id);
        list_addElement(localVarQueryParameters,keyPairQuery_mandate_id);
    }

    // query parameters
    char *keyQuery_mandate_date = NULL;
    char * valueQuery_mandate_date = NULL;
    keyValuePair_t *keyPairQuery_mandate_date = 0;
    if (mandate_date)
    {
        keyQuery_mandate_date = strdup("mandate_date");
        valueQuery_mandate_date = strdup((mandate_date));
        keyPairQuery_mandate_date = keyValuePair_create(keyQuery_mandate_date, valueQuery_mandate_date);
        list_addElement(localVarQueryParameters,keyPairQuery_mandate_date);
    }

    // query parameters
    char *keyQuery_debtor_name = NULL;
    char * valueQuery_debtor_name = NULL;
    keyValuePair_t *keyPairQuery_debtor_name = 0;
    if (debtor_name)
    {
        keyQuery_debtor_name = strdup("debtor_name");
        valueQuery_debtor_name = strdup((debtor_name));
        keyPairQuery_debtor_name = keyValuePair_create(keyQuery_debtor_name, valueQuery_debtor_name);
        list_addElement(localVarQueryParameters,keyPairQuery_debtor_name);
    }

    // query parameters
    char *keyQuery_debtor_iban = NULL;
    char * valueQuery_debtor_iban = NULL;
    keyValuePair_t *keyPairQuery_debtor_iban = 0;
    if (debtor_iban)
    {
        keyQuery_debtor_iban = strdup("debtor_iban");
        valueQuery_debtor_iban = strdup((debtor_iban));
        keyPairQuery_debtor_iban = keyValuePair_create(keyQuery_debtor_iban, valueQuery_debtor_iban);
        list_addElement(localVarQueryParameters,keyPairQuery_debtor_iban);
    }

    // query parameters
    char *keyQuery_debtor_bic = NULL;
    char * valueQuery_debtor_bic = NULL;
    keyValuePair_t *keyPairQuery_debtor_bic = 0;
    if (debtor_bic)
    {
        keyQuery_debtor_bic = strdup("debtor_bic");
        valueQuery_debtor_bic = strdup((debtor_bic));
        keyPairQuery_debtor_bic = keyValuePair_create(keyQuery_debtor_bic, valueQuery_debtor_bic);
        list_addElement(localVarQueryParameters,keyPairQuery_debtor_bic);
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
    char *keyQuery_collection_date = NULL;
    char * valueQuery_collection_date = NULL;
    keyValuePair_t *keyPairQuery_collection_date = 0;
    if (collection_date)
    {
        keyQuery_collection_date = strdup("collection_date");
        valueQuery_collection_date = strdup((collection_date));
        keyPairQuery_collection_date = keyValuePair_create(keyQuery_collection_date, valueQuery_collection_date);
        list_addElement(localVarQueryParameters,keyPairQuery_collection_date);
    }

    // query parameters
    char *keyQuery_description = NULL;
    char * valueQuery_description = NULL;
    keyValuePair_t *keyPairQuery_description = 0;
    if (description)
    {
        keyQuery_description = strdup("description");
        valueQuery_description = strdup((description));
        keyPairQuery_description = keyValuePair_create(keyQuery_description, valueQuery_description);
        list_addElement(localVarQueryParameters,keyPairQuery_description);
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
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","SEPA Direct Debit XML");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    sepa_direct_debit_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CreateSepaDirectDebitAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = sepa_direct_debit_response_parseFromJSON(CreateSepaDirectDebitAPIlocalVarJSON);
        cJSON_Delete(CreateSepaDirectDebitAPIlocalVarJSON);
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
    if(keyQuery_creditor_name){
        free(keyQuery_creditor_name);
        keyQuery_creditor_name = NULL;
    }
    if(valueQuery_creditor_name){
        free(valueQuery_creditor_name);
        valueQuery_creditor_name = NULL;
    }
    if(keyPairQuery_creditor_name){
        keyValuePair_free(keyPairQuery_creditor_name);
        keyPairQuery_creditor_name = NULL;
    }
    if(keyQuery_creditor_iban){
        free(keyQuery_creditor_iban);
        keyQuery_creditor_iban = NULL;
    }
    if(valueQuery_creditor_iban){
        free(valueQuery_creditor_iban);
        valueQuery_creditor_iban = NULL;
    }
    if(keyPairQuery_creditor_iban){
        keyValuePair_free(keyPairQuery_creditor_iban);
        keyPairQuery_creditor_iban = NULL;
    }
    if(keyQuery_creditor_bic){
        free(keyQuery_creditor_bic);
        keyQuery_creditor_bic = NULL;
    }
    if(valueQuery_creditor_bic){
        free(valueQuery_creditor_bic);
        valueQuery_creditor_bic = NULL;
    }
    if(keyPairQuery_creditor_bic){
        keyValuePair_free(keyPairQuery_creditor_bic);
        keyPairQuery_creditor_bic = NULL;
    }
    if(keyQuery_creditor_id){
        free(keyQuery_creditor_id);
        keyQuery_creditor_id = NULL;
    }
    if(valueQuery_creditor_id){
        free(valueQuery_creditor_id);
        valueQuery_creditor_id = NULL;
    }
    if(keyPairQuery_creditor_id){
        keyValuePair_free(keyPairQuery_creditor_id);
        keyPairQuery_creditor_id = NULL;
    }
    if(keyQuery_mandate_id){
        free(keyQuery_mandate_id);
        keyQuery_mandate_id = NULL;
    }
    if(valueQuery_mandate_id){
        free(valueQuery_mandate_id);
        valueQuery_mandate_id = NULL;
    }
    if(keyPairQuery_mandate_id){
        keyValuePair_free(keyPairQuery_mandate_id);
        keyPairQuery_mandate_id = NULL;
    }
    if(keyQuery_mandate_date){
        free(keyQuery_mandate_date);
        keyQuery_mandate_date = NULL;
    }
    if(valueQuery_mandate_date){
        free(valueQuery_mandate_date);
        valueQuery_mandate_date = NULL;
    }
    if(keyPairQuery_mandate_date){
        keyValuePair_free(keyPairQuery_mandate_date);
        keyPairQuery_mandate_date = NULL;
    }
    if(keyQuery_debtor_name){
        free(keyQuery_debtor_name);
        keyQuery_debtor_name = NULL;
    }
    if(valueQuery_debtor_name){
        free(valueQuery_debtor_name);
        valueQuery_debtor_name = NULL;
    }
    if(keyPairQuery_debtor_name){
        keyValuePair_free(keyPairQuery_debtor_name);
        keyPairQuery_debtor_name = NULL;
    }
    if(keyQuery_debtor_iban){
        free(keyQuery_debtor_iban);
        keyQuery_debtor_iban = NULL;
    }
    if(valueQuery_debtor_iban){
        free(valueQuery_debtor_iban);
        valueQuery_debtor_iban = NULL;
    }
    if(keyPairQuery_debtor_iban){
        keyValuePair_free(keyPairQuery_debtor_iban);
        keyPairQuery_debtor_iban = NULL;
    }
    if(keyQuery_debtor_bic){
        free(keyQuery_debtor_bic);
        keyQuery_debtor_bic = NULL;
    }
    if(valueQuery_debtor_bic){
        free(valueQuery_debtor_bic);
        valueQuery_debtor_bic = NULL;
    }
    if(keyPairQuery_debtor_bic){
        keyValuePair_free(keyPairQuery_debtor_bic);
        keyPairQuery_debtor_bic = NULL;
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
    if(keyQuery_collection_date){
        free(keyQuery_collection_date);
        keyQuery_collection_date = NULL;
    }
    if(valueQuery_collection_date){
        free(valueQuery_collection_date);
        valueQuery_collection_date = NULL;
    }
    if(keyPairQuery_collection_date){
        keyValuePair_free(keyPairQuery_collection_date);
        keyPairQuery_collection_date = NULL;
    }
    if(keyQuery_description){
        free(keyQuery_description);
        keyQuery_description = NULL;
    }
    if(valueQuery_description){
        free(valueQuery_description);
        valueQuery_description = NULL;
    }
    if(keyPairQuery_description){
        keyValuePair_free(keyPairQuery_description);
        keyPairQuery_description = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

