#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "CustomerCommunicationAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


customer_communication_t*
CustomerCommunicationAPI_createCommunication(apiClient_t *apiClient, customer_communication_create_t *customer_communication_create)
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
    char *localVarPath = strdup("/api/v1/communications");





    // Body Param
    cJSON *localVarSingleItemJSON_customer_communication_create = NULL;
    if (customer_communication_create != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_customer_communication_create = customer_communication_create_convertToJSON(customer_communication_create);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_customer_communication_create);
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
    customer_communication_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomerCommunicationAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = customer_communication_parseFromJSON(CustomerCommunicationAPIlocalVarJSON);
        cJSON_Delete(CustomerCommunicationAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_customer_communication_create) {
        cJSON_Delete(localVarSingleItemJSON_customer_communication_create);
        localVarSingleItemJSON_customer_communication_create = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

customer_communication_t*
CustomerCommunicationAPI_customercommunicationRestore(apiClient_t *apiClient, char *communication_id)
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
    char *localVarPath = strdup("/api/v1/communications/{communication_id}/restore");

    if(!communication_id)
        goto end;


    // Path Params
    long sizeOfPathParams_communication_id = strlen(communication_id)+3 + sizeof("{ communication_id }") - 1;
    if(communication_id == NULL) {
        goto end;
    }
    char* localVarToReplace_communication_id = malloc(sizeOfPathParams_communication_id);
    sprintf(localVarToReplace_communication_id, "{%s}", "communication_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_communication_id, communication_id);


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
    customer_communication_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomerCommunicationAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = customer_communication_parseFromJSON(CustomerCommunicationAPIlocalVarJSON);
        cJSON_Delete(CustomerCommunicationAPIlocalVarJSON);
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
    free(localVarToReplace_communication_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

void
CustomerCommunicationAPI_deleteCommunication(apiClient_t *apiClient, char *communication_id)
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
    char *localVarPath = strdup("/api/v1/communications/{communication_id}");

    if(!communication_id)
        goto end;


    // Path Params
    long sizeOfPathParams_communication_id = strlen(communication_id)+3 + sizeof("{ communication_id }") - 1;
    if(communication_id == NULL) {
        goto end;
    }
    char* localVarToReplace_communication_id = malloc(sizeOfPathParams_communication_id);
    sprintf(localVarToReplace_communication_id, "{%s}", "communication_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_communication_id, communication_id);


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
    free(localVarToReplace_communication_id);

}

customer_communication_t*
CustomerCommunicationAPI_getCommunication(apiClient_t *apiClient, char *communication_id)
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
    char *localVarPath = strdup("/api/v1/communications/{communication_id}");

    if(!communication_id)
        goto end;


    // Path Params
    long sizeOfPathParams_communication_id = strlen(communication_id)+3 + sizeof("{ communication_id }") - 1;
    if(communication_id == NULL) {
        goto end;
    }
    char* localVarToReplace_communication_id = malloc(sizeOfPathParams_communication_id);
    sprintf(localVarToReplace_communication_id, "{%s}", "communication_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_communication_id, communication_id);


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
    customer_communication_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomerCommunicationAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = customer_communication_parseFromJSON(CustomerCommunicationAPIlocalVarJSON);
        cJSON_Delete(CustomerCommunicationAPIlocalVarJSON);
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
    free(localVarToReplace_communication_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

contact_history_response_t*
CustomerCommunicationAPI_getContactHistory(apiClient_t *apiClient, char *contact_id)
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
    char *localVarPath = strdup("/api/v1/contacts/{contact_id}/communications");

    if(!contact_id)
        goto end;


    // Path Params
    long sizeOfPathParams_contact_id = strlen(contact_id)+3 + sizeof("{ contact_id }") - 1;
    if(contact_id == NULL) {
        goto end;
    }
    char* localVarToReplace_contact_id = malloc(sizeOfPathParams_contact_id);
    sprintf(localVarToReplace_contact_id, "{%s}", "contact_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_contact_id, contact_id);


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
    contact_history_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomerCommunicationAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = contact_history_response_parseFromJSON(CustomerCommunicationAPIlocalVarJSON);
        cJSON_Delete(CustomerCommunicationAPIlocalVarJSON);
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
    free(localVarToReplace_contact_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

list_t*
CustomerCommunicationAPI_listCommunications(apiClient_t *apiClient, int *page, int *page_size, char *contact_id, channel, direction, char from, char to)
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
    char *localVarPath = strdup("/api/v1/communications/");





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
    char *keyQuery_contact_id = NULL;
    char * valueQuery_contact_id = NULL;
    keyValuePair_t *keyPairQuery_contact_id = 0;
    if (contact_id)
    {
        keyQuery_contact_id = strdup("contact_id");
        valueQuery_contact_id = strdup((contact_id));
        keyPairQuery_contact_id = keyValuePair_create(keyQuery_contact_id, valueQuery_contact_id);
        list_addElement(localVarQueryParameters,keyPairQuery_contact_id);
    }

    // query parameters
    char *keyQuery_channel = NULL;
     valueQuery_channel ;
    keyValuePair_t *keyPairQuery_channel = 0;
    if (channel)
    {
        keyQuery_channel = strdup("channel");
        valueQuery_channel = (channel);
        keyPairQuery_channel = keyValuePair_create(keyQuery_channel, &valueQuery_channel);
        list_addElement(localVarQueryParameters,keyPairQuery_channel);
    }

    // query parameters
    char *keyQuery_direction = NULL;
     valueQuery_direction ;
    keyValuePair_t *keyPairQuery_direction = 0;
    if (direction)
    {
        keyQuery_direction = strdup("direction");
        valueQuery_direction = (direction);
        keyPairQuery_direction = keyValuePair_create(keyQuery_direction, &valueQuery_direction);
        list_addElement(localVarQueryParameters,keyPairQuery_direction);
    }

    // query parameters
    char *keyQuery_from = NULL;
    char valueQuery_from ;
    keyValuePair_t *keyPairQuery_from = 0;
    if (from)
    {
        keyQuery_from = strdup("from");
        valueQuery_from = (from);
        keyPairQuery_from = keyValuePair_create(keyQuery_from, &valueQuery_from);
        list_addElement(localVarQueryParameters,keyPairQuery_from);
    }

    // query parameters
    char *keyQuery_to = NULL;
    char valueQuery_to ;
    keyValuePair_t *keyPairQuery_to = 0;
    if (to)
    {
        keyQuery_to = strdup("to");
        valueQuery_to = (to);
        keyPairQuery_to = keyValuePair_create(keyQuery_to, &valueQuery_to);
        list_addElement(localVarQueryParameters,keyPairQuery_to);
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
        cJSON *CustomerCommunicationAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(CustomerCommunicationAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, CustomerCommunicationAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( CustomerCommunicationAPIlocalVarJSON);
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
    if(keyQuery_contact_id){
        free(keyQuery_contact_id);
        keyQuery_contact_id = NULL;
    }
    if(valueQuery_contact_id){
        free(valueQuery_contact_id);
        valueQuery_contact_id = NULL;
    }
    if(keyPairQuery_contact_id){
        keyValuePair_free(keyPairQuery_contact_id);
        keyPairQuery_contact_id = NULL;
    }
    if(keyQuery_channel){
        free(keyQuery_channel);
        keyQuery_channel = NULL;
    }
    if(keyPairQuery_channel){
        keyValuePair_free(keyPairQuery_channel);
        keyPairQuery_channel = NULL;
    }
    if(keyQuery_direction){
        free(keyQuery_direction);
        keyQuery_direction = NULL;
    }
    if(keyPairQuery_direction){
        keyValuePair_free(keyPairQuery_direction);
        keyPairQuery_direction = NULL;
    }
    if(keyQuery_from){
        free(keyQuery_from);
        keyQuery_from = NULL;
    }
    if(keyPairQuery_from){
        keyValuePair_free(keyPairQuery_from);
        keyPairQuery_from = NULL;
    }
    if(keyQuery_to){
        free(keyQuery_to);
        keyQuery_to = NULL;
    }
    if(keyPairQuery_to){
        keyValuePair_free(keyPairQuery_to);
        keyPairQuery_to = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

customer_communication_t*
CustomerCommunicationAPI_updateCommunication(apiClient_t *apiClient, char *communication_id, customer_communication_update_t *customer_communication_update)
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
    char *localVarPath = strdup("/api/v1/communications/{communication_id}");

    if(!communication_id)
        goto end;


    // Path Params
    long sizeOfPathParams_communication_id = strlen(communication_id)+3 + sizeof("{ communication_id }") - 1;
    if(communication_id == NULL) {
        goto end;
    }
    char* localVarToReplace_communication_id = malloc(sizeOfPathParams_communication_id);
    sprintf(localVarToReplace_communication_id, "{%s}", "communication_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_communication_id, communication_id);



    // Body Param
    cJSON *localVarSingleItemJSON_customer_communication_update = NULL;
    if (customer_communication_update != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_customer_communication_update = customer_communication_update_convertToJSON(customer_communication_update);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_customer_communication_update);
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
    customer_communication_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomerCommunicationAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = customer_communication_parseFromJSON(CustomerCommunicationAPIlocalVarJSON);
        cJSON_Delete(CustomerCommunicationAPIlocalVarJSON);
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
    free(localVarToReplace_communication_id);
    if (localVarSingleItemJSON_customer_communication_update) {
        cJSON_Delete(localVarSingleItemJSON_customer_communication_update);
        localVarSingleItemJSON_customer_communication_update = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

