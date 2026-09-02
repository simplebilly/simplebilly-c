#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "SupportTicketAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


support_ticket_t*
SupportTicketAPI_createTicketApi(apiClient_t *apiClient, create_ticket_request_t *create_ticket_request)
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
    char *localVarPath = strdup("/api/v1/support/tickets");





    // Body Param
    cJSON *localVarSingleItemJSON_create_ticket_request = NULL;
    if (create_ticket_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_create_ticket_request = create_ticket_request_convertToJSON(create_ticket_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_ticket_request);
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
    //    printf("%s\n","Ticket created");
    //}
    //nonprimitive not container
    support_ticket_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SupportTicketAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = support_ticket_parseFromJSON(SupportTicketAPIlocalVarJSON);
        cJSON_Delete(SupportTicketAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_create_ticket_request) {
        cJSON_Delete(localVarSingleItemJSON_create_ticket_request);
        localVarSingleItemJSON_create_ticket_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

void
SupportTicketAPI_deleteTicketApi(apiClient_t *apiClient, char *ticket_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = NULL;
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/api/v1/support/tickets/{ticket_id}");

    if(!ticket_id)
        goto end;


    // Path Params
    long sizeOfPathParams_ticket_id = strlen(ticket_id)+3 + sizeof("{ ticket_id }") - 1;
    if(ticket_id == NULL) {
        goto end;
    }
    char* localVarToReplace_ticket_id = malloc(sizeOfPathParams_ticket_id);
    sprintf(localVarToReplace_ticket_id, "{%s}", "ticket_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_ticket_id, ticket_id);


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
    //    printf("%s\n","Ticket deleted");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    
    
    free(localVarPath);
    free(localVarToReplace_ticket_id);

}

support_ticket_t*
SupportTicketAPI_getTicketApi(apiClient_t *apiClient, char *ticket_id)
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
    char *localVarPath = strdup("/api/v1/support/tickets/{ticket_id}");

    if(!ticket_id)
        goto end;


    // Path Params
    long sizeOfPathParams_ticket_id = strlen(ticket_id)+3 + sizeof("{ ticket_id }") - 1;
    if(ticket_id == NULL) {
        goto end;
    }
    char* localVarToReplace_ticket_id = malloc(sizeOfPathParams_ticket_id);
    sprintf(localVarToReplace_ticket_id, "{%s}", "ticket_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_ticket_id, ticket_id);


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
    //    printf("%s\n","Ticket detail");
    //}
    //nonprimitive not container
    support_ticket_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SupportTicketAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = support_ticket_parseFromJSON(SupportTicketAPIlocalVarJSON);
        cJSON_Delete(SupportTicketAPIlocalVarJSON);
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
    free(localVarToReplace_ticket_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

list_t*
SupportTicketAPI_listTicketsApi(apiClient_t *apiClient, char *status, char *priority, char *assigned_to, char *channel_type, char *customer_id, char *search, int *page, int *page_size)
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
    char *localVarPath = strdup("/api/v1/support/tickets");





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
    char *keyQuery_priority = NULL;
    char * valueQuery_priority = NULL;
    keyValuePair_t *keyPairQuery_priority = 0;
    if (priority)
    {
        keyQuery_priority = strdup("priority");
        valueQuery_priority = strdup((priority));
        keyPairQuery_priority = keyValuePair_create(keyQuery_priority, valueQuery_priority);
        list_addElement(localVarQueryParameters,keyPairQuery_priority);
    }

    // query parameters
    char *keyQuery_assigned_to = NULL;
    char * valueQuery_assigned_to = NULL;
    keyValuePair_t *keyPairQuery_assigned_to = 0;
    if (assigned_to)
    {
        keyQuery_assigned_to = strdup("assigned_to");
        valueQuery_assigned_to = strdup((assigned_to));
        keyPairQuery_assigned_to = keyValuePair_create(keyQuery_assigned_to, valueQuery_assigned_to);
        list_addElement(localVarQueryParameters,keyPairQuery_assigned_to);
    }

    // query parameters
    char *keyQuery_channel_type = NULL;
    char * valueQuery_channel_type = NULL;
    keyValuePair_t *keyPairQuery_channel_type = 0;
    if (channel_type)
    {
        keyQuery_channel_type = strdup("channel_type");
        valueQuery_channel_type = strdup((channel_type));
        keyPairQuery_channel_type = keyValuePair_create(keyQuery_channel_type, valueQuery_channel_type);
        list_addElement(localVarQueryParameters,keyPairQuery_channel_type);
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
    //    printf("%s\n","Tickets list");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SupportTicketAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(SupportTicketAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, SupportTicketAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( SupportTicketAPIlocalVarJSON);
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
    if(keyQuery_priority){
        free(keyQuery_priority);
        keyQuery_priority = NULL;
    }
    if(valueQuery_priority){
        free(valueQuery_priority);
        valueQuery_priority = NULL;
    }
    if(keyPairQuery_priority){
        keyValuePair_free(keyPairQuery_priority);
        keyPairQuery_priority = NULL;
    }
    if(keyQuery_assigned_to){
        free(keyQuery_assigned_to);
        keyQuery_assigned_to = NULL;
    }
    if(valueQuery_assigned_to){
        free(valueQuery_assigned_to);
        valueQuery_assigned_to = NULL;
    }
    if(keyPairQuery_assigned_to){
        keyValuePair_free(keyPairQuery_assigned_to);
        keyPairQuery_assigned_to = NULL;
    }
    if(keyQuery_channel_type){
        free(keyQuery_channel_type);
        keyQuery_channel_type = NULL;
    }
    if(valueQuery_channel_type){
        free(valueQuery_channel_type);
        valueQuery_channel_type = NULL;
    }
    if(keyPairQuery_channel_type){
        keyValuePair_free(keyPairQuery_channel_type);
        keyPairQuery_channel_type = NULL;
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

support_ticket_t*
SupportTicketAPI_updateTicketApi(apiClient_t *apiClient, char *ticket_id, support_ticket_update_t *support_ticket_update)
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
    char *localVarPath = strdup("/api/v1/support/tickets/{ticket_id}");

    if(!ticket_id)
        goto end;


    // Path Params
    long sizeOfPathParams_ticket_id = strlen(ticket_id)+3 + sizeof("{ ticket_id }") - 1;
    if(ticket_id == NULL) {
        goto end;
    }
    char* localVarToReplace_ticket_id = malloc(sizeOfPathParams_ticket_id);
    sprintf(localVarToReplace_ticket_id, "{%s}", "ticket_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_ticket_id, ticket_id);



    // Body Param
    cJSON *localVarSingleItemJSON_support_ticket_update = NULL;
    if (support_ticket_update != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_support_ticket_update = support_ticket_update_convertToJSON(support_ticket_update);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_support_ticket_update);
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
    //    printf("%s\n","Ticket updated");
    //}
    //nonprimitive not container
    support_ticket_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SupportTicketAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = support_ticket_parseFromJSON(SupportTicketAPIlocalVarJSON);
        cJSON_Delete(SupportTicketAPIlocalVarJSON);
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
    free(localVarToReplace_ticket_id);
    if (localVarSingleItemJSON_support_ticket_update) {
        cJSON_Delete(localVarSingleItemJSON_support_ticket_update);
        localVarSingleItemJSON_support_ticket_update = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

