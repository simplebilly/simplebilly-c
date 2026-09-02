#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "TicketMessageAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


list_t*
TicketMessageAPI_listMessagesApi(apiClient_t *apiClient, char *ticket_id)
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
    char *localVarPath = strdup("/api/v1/support/tickets/{ticket_id}/messages");

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
    //    printf("%s\n","Messages for a ticket");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *TicketMessageAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(TicketMessageAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, TicketMessageAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( TicketMessageAPIlocalVarJSON);
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
    free(localVarToReplace_ticket_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

ticket_message_t*
TicketMessageAPI_sendMessageApi(apiClient_t *apiClient, char *ticket_id, send_message_dto_t *send_message_dto)
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
    char *localVarPath = strdup("/api/v1/support/tickets/{ticket_id}/messages");

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
    cJSON *localVarSingleItemJSON_send_message_dto = NULL;
    if (send_message_dto != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_send_message_dto = send_message_dto_convertToJSON(send_message_dto);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_send_message_dto);
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
    //    printf("%s\n","Message sent");
    //}
    //nonprimitive not container
    ticket_message_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *TicketMessageAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = ticket_message_parseFromJSON(TicketMessageAPIlocalVarJSON);
        cJSON_Delete(TicketMessageAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_send_message_dto) {
        cJSON_Delete(localVarSingleItemJSON_send_message_dto);
        localVarSingleItemJSON_send_message_dto = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

