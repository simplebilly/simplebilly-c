#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "LegalDocumentAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// List all legal documents of the tenant. Missing documents are seeded from the default texts (with tenant placeholders replaced) on first access.
//
list_t*
LegalDocumentAPI_getLegalDocuments(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/api/v1/legal/documents");




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
    //    printf("%s\n","All legal documents of the tenant");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *LegalDocumentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(LegalDocumentAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, LegalDocumentAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( LegalDocumentAPIlocalVarJSON);
        cJSON_Delete( VarJSON);
    }
    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Restore default texts for all documents (or a single doc_type/lang when the optional filter is given). Returns the full tenant list.
//
list_t*
LegalDocumentAPI_resetLegalDocuments(apiClient_t *apiClient, legal_document_reset_t *legal_document_reset)
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
    char *localVarPath = strdup("/api/v1/legal/documents/reset");





    // Body Param
    cJSON *localVarSingleItemJSON_legal_document_reset = NULL;
    if (legal_document_reset != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_legal_document_reset = legal_document_reset_convertToJSON(legal_document_reset);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_legal_document_reset);
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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Reset legal documents");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *LegalDocumentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(LegalDocumentAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, LegalDocumentAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( LegalDocumentAPIlocalVarJSON);
        cJSON_Delete( VarJSON);
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
    if (localVarSingleItemJSON_legal_document_reset) {
        cJSON_Delete(localVarSingleItemJSON_legal_document_reset);
        localVarSingleItemJSON_legal_document_reset = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Upsert legal documents per (doc_type, lang). Returns the full tenant list.
//
list_t*
LegalDocumentAPI_upsertLegalDocuments(apiClient_t *apiClient, list_t *legal_document_upsert)
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
    char *localVarPath = strdup("/api/v1/legal/documents");





    // Body Param
    //notstring
    cJSON *localVar_legal_document_upsert = NULL;
    cJSON *localVarItemJSON_legal_document_upsert = NULL;
    cJSON *localVarSingleItemJSON_legal_document_upsert = NULL;
    if (legal_document_upsert != NULL)
    {
        localVarItemJSON_legal_document_upsert = cJSON_CreateObject();
        localVarSingleItemJSON_legal_document_upsert = cJSON_AddArrayToObject(localVarItemJSON_legal_document_upsert, "legal_document_upsert");
        if (localVarSingleItemJSON_legal_document_upsert == NULL)
        {
            // nonprimitive container

            goto end;
        }
    }

    listEntry_t *legal_document_upsertBodyListEntry;
    list_ForEach(legal_document_upsertBodyListEntry, legal_document_upsert)
    {
        localVar_legal_document_upsert = legal_document_upsert_convertToJSON(legal_document_upsertBodyListEntry->data);
        if(localVar_legal_document_upsert == NULL)
        {
            goto end;
        }
        cJSON_AddItemToArray(localVarSingleItemJSON_legal_document_upsert, localVar_legal_document_upsert);
        localVarBodyParameters = cJSON_Print(localVarItemJSON_legal_document_upsert);
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
    //    printf("%s\n","Saved legal documents");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *LegalDocumentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(LegalDocumentAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, LegalDocumentAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( LegalDocumentAPIlocalVarJSON);
        cJSON_Delete( VarJSON);
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
    if (localVarItemJSON_legal_document_upsert) {
        cJSON_Delete(localVarItemJSON_legal_document_upsert);
        localVarItemJSON_legal_document_upsert = NULL;
    }
    if (localVarSingleItemJSON_legal_document_upsert) {
        cJSON_Delete(localVarSingleItemJSON_legal_document_upsert);
        localVarSingleItemJSON_legal_document_upsert = NULL;
    }
    if (localVar_legal_document_upsert) {
        cJSON_Delete(localVar_legal_document_upsert);
        localVar_legal_document_upsert = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

