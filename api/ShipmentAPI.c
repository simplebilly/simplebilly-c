#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "ShipmentAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


shipment_t*
ShipmentAPI_createShipment(apiClient_t *apiClient, shipment_t *shipment)
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
    char *localVarPath = strdup("/api/v1/shipments");





    // Body Param
    cJSON *localVarSingleItemJSON_shipment = NULL;
    if (shipment != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_shipment = shipment_convertToJSON(shipment);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_shipment);
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
    //    printf("%s\n","Shipment created");
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
    shipment_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ShipmentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = shipment_parseFromJSON(ShipmentAPIlocalVarJSON);
        cJSON_Delete(ShipmentAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_shipment) {
        cJSON_Delete(localVarSingleItemJSON_shipment);
        localVarSingleItemJSON_shipment = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Create a real shipment for an order: calls the configured carrier's label API, stores the returned tracking/label on a new shipment row, and marks the order as shipped.
//
shipment_t*
ShipmentAPI_createShipmentFromOrder(apiClient_t *apiClient, char *order_number, create_shipment_request_t *create_shipment_request)
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
    char *localVarPath = strdup("/api/v1/orders/{order_number}/shipments");

    if(!order_number)
        goto end;


    // Path Params
    long sizeOfPathParams_order_number = strlen(order_number)+3 + sizeof("{ order_number }") - 1;
    if(order_number == NULL) {
        goto end;
    }
    char* localVarToReplace_order_number = malloc(sizeOfPathParams_order_number);
    sprintf(localVarToReplace_order_number, "{%s}", "order_number");

    localVarPath = strReplace(localVarPath, localVarToReplace_order_number, order_number);



    // Body Param
    cJSON *localVarSingleItemJSON_create_shipment_request = NULL;
    if (create_shipment_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_create_shipment_request = create_shipment_request_convertToJSON(create_shipment_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_shipment_request);
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
    //    printf("%s\n","Shipment created via carrier API");
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
    shipment_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ShipmentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = shipment_parseFromJSON(ShipmentAPIlocalVarJSON);
        cJSON_Delete(ShipmentAPIlocalVarJSON);
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
    free(localVarToReplace_order_number);
    if (localVarSingleItemJSON_create_shipment_request) {
        cJSON_Delete(localVarSingleItemJSON_create_shipment_request);
        localVarSingleItemJSON_create_shipment_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

void
ShipmentAPI_deleteShipment(apiClient_t *apiClient, char *shipment_id)
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
    char *localVarPath = strdup("/api/v1/shipments/{shipment_id}");

    if(!shipment_id)
        goto end;


    // Path Params
    long sizeOfPathParams_shipment_id = strlen(shipment_id)+3 + sizeof("{ shipment_id }") - 1;
    if(shipment_id == NULL) {
        goto end;
    }
    char* localVarToReplace_shipment_id = malloc(sizeOfPathParams_shipment_id);
    sprintf(localVarToReplace_shipment_id, "{%s}", "shipment_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_shipment_id, shipment_id);


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
    //    printf("%s\n","Shipment deleted");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Shipment not found");
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
    free(localVarToReplace_shipment_id);

}

shipment_t*
ShipmentAPI_getShipment(apiClient_t *apiClient, char *shipment_id)
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
    char *localVarPath = strdup("/api/v1/shipments/{shipment_id}");

    if(!shipment_id)
        goto end;


    // Path Params
    long sizeOfPathParams_shipment_id = strlen(shipment_id)+3 + sizeof("{ shipment_id }") - 1;
    if(shipment_id == NULL) {
        goto end;
    }
    char* localVarToReplace_shipment_id = malloc(sizeOfPathParams_shipment_id);
    sprintf(localVarToReplace_shipment_id, "{%s}", "shipment_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_shipment_id, shipment_id);


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
    //    printf("%s\n","Shipment found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Shipment not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    shipment_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ShipmentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = shipment_parseFromJSON(ShipmentAPIlocalVarJSON);
        cJSON_Delete(ShipmentAPIlocalVarJSON);
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
    free(localVarToReplace_shipment_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

list_t*
ShipmentAPI_listShipments(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted)
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
    char *localVarPath = strdup("/api/v1/shipments");





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
    char *keyQuery_include_deleted = NULL;
    char * valueQuery_include_deleted = NULL;
    keyValuePair_t *keyPairQuery_include_deleted = 0;
    if (include_deleted)
    {
        keyQuery_include_deleted = strdup("include_deleted");
        valueQuery_include_deleted = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_include_deleted, MAX_NUMBER_LENGTH, "%d", *include_deleted);
        keyPairQuery_include_deleted = keyValuePair_create(keyQuery_include_deleted, valueQuery_include_deleted);
        list_addElement(localVarQueryParameters,keyPairQuery_include_deleted);
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
    //    printf("%s\n","Shipments found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ShipmentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(ShipmentAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, ShipmentAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( ShipmentAPIlocalVarJSON);
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
    if(keyQuery_include_deleted){
        free(keyQuery_include_deleted);
        keyQuery_include_deleted = NULL;
    }
    if(valueQuery_include_deleted){
        free(valueQuery_include_deleted);
        valueQuery_include_deleted = NULL;
    }
    if(keyPairQuery_include_deleted){
        keyValuePair_free(keyPairQuery_include_deleted);
        keyPairQuery_include_deleted = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Customer-facing tracking lookup: order number + email → shipment status and live carrier events. No auth (public storefront API).
//
track_order_response_t*
ShipmentAPI_trackOrderPublic(apiClient_t *apiClient, track_order_request_t *track_order_request)
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
    char *localVarPath = strdup("/api/v1/public/track");





    // Body Param
    cJSON *localVarSingleItemJSON_track_order_request = NULL;
    if (track_order_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_track_order_request = track_order_request_convertToJSON(track_order_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_track_order_request);
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
    //    printf("%s\n","Order tracking info");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Order not found or email mismatch");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    track_order_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ShipmentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = track_order_response_parseFromJSON(ShipmentAPIlocalVarJSON);
        cJSON_Delete(ShipmentAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_track_order_request) {
        cJSON_Delete(localVarSingleItemJSON_track_order_request);
        localVarSingleItemJSON_track_order_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

tracking_info_t*
ShipmentAPI_trackShipmentApi(apiClient_t *apiClient, char *shipment_id)
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
    char *localVarPath = strdup("/api/v1/shipments/{shipment_id}/tracking");

    if(!shipment_id)
        goto end;


    // Path Params
    long sizeOfPathParams_shipment_id = strlen(shipment_id)+3 + sizeof("{ shipment_id }") - 1;
    if(shipment_id == NULL) {
        goto end;
    }
    char* localVarToReplace_shipment_id = malloc(sizeOfPathParams_shipment_id);
    sprintf(localVarToReplace_shipment_id, "{%s}", "shipment_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_shipment_id, shipment_id);


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
    //    printf("%s\n","Live tracking info");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Shipment not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    tracking_info_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ShipmentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = tracking_info_parseFromJSON(ShipmentAPIlocalVarJSON);
        cJSON_Delete(ShipmentAPIlocalVarJSON);
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
    free(localVarToReplace_shipment_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

shipment_t*
ShipmentAPI_updateShipmentStatus(apiClient_t *apiClient, char *shipment_id, shipment_status_update_t *shipment_status_update)
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
    char *localVarPath = strdup("/api/v1/shipments/{shipment_id}/status");

    if(!shipment_id)
        goto end;


    // Path Params
    long sizeOfPathParams_shipment_id = strlen(shipment_id)+3 + sizeof("{ shipment_id }") - 1;
    if(shipment_id == NULL) {
        goto end;
    }
    char* localVarToReplace_shipment_id = malloc(sizeOfPathParams_shipment_id);
    sprintf(localVarToReplace_shipment_id, "{%s}", "shipment_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_shipment_id, shipment_id);



    // Body Param
    cJSON *localVarSingleItemJSON_shipment_status_update = NULL;
    if (shipment_status_update != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_shipment_status_update = shipment_status_update_convertToJSON(shipment_status_update);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_shipment_status_update);
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
    //    printf("%s\n","Status updated");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Shipment not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    shipment_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ShipmentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = shipment_parseFromJSON(ShipmentAPIlocalVarJSON);
        cJSON_Delete(ShipmentAPIlocalVarJSON);
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
    free(localVarToReplace_shipment_id);
    if (localVarSingleItemJSON_shipment_status_update) {
        cJSON_Delete(localVarSingleItemJSON_shipment_status_update);
        localVarSingleItemJSON_shipment_status_update = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

