#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "packing_complete_request.h"



static packing_complete_request_t *packing_complete_request_create_internal(
    char *notes,
    char *order_number,
    char *shipment_id,
    char *video_url
    ) {
    packing_complete_request_t *packing_complete_request_local_var = malloc(sizeof(packing_complete_request_t));
    if (!packing_complete_request_local_var) {
        return NULL;
    }
    memset(packing_complete_request_local_var, 0, sizeof(packing_complete_request_t));
    packing_complete_request_local_var->_library_owned = 1;
    packing_complete_request_local_var->notes = notes;
    packing_complete_request_local_var->order_number = order_number;
    packing_complete_request_local_var->shipment_id = shipment_id;
    packing_complete_request_local_var->video_url = video_url;
    return packing_complete_request_local_var;
}

__attribute__((deprecated)) packing_complete_request_t *packing_complete_request_create(
    char *notes,
    char *order_number,
    char *shipment_id,
    char *video_url
    ) {
    packing_complete_request_t *result = packing_complete_request_create_internal (
        notes,
        order_number,
        shipment_id,
        video_url
        );
    if (!result) {
    }
    return result;
}

void packing_complete_request_free(packing_complete_request_t *packing_complete_request) {
    if(NULL == packing_complete_request){
        return ;
    }
    if(packing_complete_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "packing_complete_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (packing_complete_request->notes) {
        free(packing_complete_request->notes);
        packing_complete_request->notes = NULL;
    }
    if (packing_complete_request->order_number) {
        free(packing_complete_request->order_number);
        packing_complete_request->order_number = NULL;
    }
    if (packing_complete_request->shipment_id) {
        free(packing_complete_request->shipment_id);
        packing_complete_request->shipment_id = NULL;
    }
    if (packing_complete_request->video_url) {
        free(packing_complete_request->video_url);
        packing_complete_request->video_url = NULL;
    }
    free(packing_complete_request);
}

cJSON *packing_complete_request_convertToJSON(packing_complete_request_t *packing_complete_request) {
    cJSON *item = cJSON_CreateObject();

    // packing_complete_request->notes
    if(packing_complete_request->notes) {
    if(cJSON_AddStringToObject(item, "notes", packing_complete_request->notes) == NULL) {
    goto fail; //String
    }
    }


    // packing_complete_request->order_number
    if (!packing_complete_request->order_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "order_number", packing_complete_request->order_number) == NULL) {
    goto fail; //String
    }


    // packing_complete_request->shipment_id
    if(packing_complete_request->shipment_id) {
    if(cJSON_AddStringToObject(item, "shipment_id", packing_complete_request->shipment_id) == NULL) {
    goto fail; //String
    }
    }


    // packing_complete_request->video_url
    if(packing_complete_request->video_url) {
    if(cJSON_AddStringToObject(item, "video_url", packing_complete_request->video_url) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

packing_complete_request_t *packing_complete_request_parseFromJSON(cJSON *packing_complete_requestJSON){

    packing_complete_request_t *packing_complete_request_local_var = NULL;

    char *notes_local_str = NULL;

    char *order_number_local_str = NULL;

    char *shipment_id_local_str = NULL;

    char *video_url_local_str = NULL;

    // packing_complete_request->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(packing_complete_requestJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // packing_complete_request->order_number
    cJSON *order_number = cJSON_GetObjectItemCaseSensitive(packing_complete_requestJSON, "order_number");
    if (cJSON_IsNull(order_number)) {
        order_number = NULL;
    }
    if (!order_number) {
        goto end;
    }

    
    if(!cJSON_IsString(order_number))
    {
    goto end; //String
    }

    // packing_complete_request->shipment_id
    cJSON *shipment_id = cJSON_GetObjectItemCaseSensitive(packing_complete_requestJSON, "shipment_id");
    if (cJSON_IsNull(shipment_id)) {
        shipment_id = NULL;
    }
    if (shipment_id) { 
    if(!cJSON_IsString(shipment_id) && !cJSON_IsNull(shipment_id))
    {
    goto end; //String
    }
    }

    // packing_complete_request->video_url
    cJSON *video_url = cJSON_GetObjectItemCaseSensitive(packing_complete_requestJSON, "video_url");
    if (cJSON_IsNull(video_url)) {
        video_url = NULL;
    }
    if (video_url) { 
    if(!cJSON_IsString(video_url) && !cJSON_IsNull(video_url))
    {
    goto end; //String
    }
    }


    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (order_number && !cJSON_IsNull(order_number)) order_number_local_str = strdup(order_number->valuestring);
    if (shipment_id && !cJSON_IsNull(shipment_id)) shipment_id_local_str = strdup(shipment_id->valuestring);
    if (video_url && !cJSON_IsNull(video_url)) video_url_local_str = strdup(video_url->valuestring);

    packing_complete_request_local_var = packing_complete_request_create_internal (
        notes_local_str,
        order_number_local_str,
        shipment_id_local_str,
        video_url_local_str
        );

    if (!packing_complete_request_local_var) {
        goto end;
    }

    return packing_complete_request_local_var;
end:
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (order_number_local_str) {
        free(order_number_local_str);
        order_number_local_str = NULL;
    }
    if (shipment_id_local_str) {
        free(shipment_id_local_str);
        shipment_id_local_str = NULL;
    }
    if (video_url_local_str) {
        free(video_url_local_str);
        video_url_local_str = NULL;
    }
    return NULL;

}
