#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shipment_status_update.h"



static shipment_status_update_t *shipment_status_update_create_internal(
    char *delivered_at,
    char *signed_by,
    char *status,
    char *tracking_number
    ) {
    shipment_status_update_t *shipment_status_update_local_var = malloc(sizeof(shipment_status_update_t));
    if (!shipment_status_update_local_var) {
        return NULL;
    }
    memset(shipment_status_update_local_var, 0, sizeof(shipment_status_update_t));
    shipment_status_update_local_var->_library_owned = 1;
    shipment_status_update_local_var->delivered_at = delivered_at;
    shipment_status_update_local_var->signed_by = signed_by;
    shipment_status_update_local_var->status = status;
    shipment_status_update_local_var->tracking_number = tracking_number;
    return shipment_status_update_local_var;
}

__attribute__((deprecated)) shipment_status_update_t *shipment_status_update_create(
    char *delivered_at,
    char *signed_by,
    char *status,
    char *tracking_number
    ) {
    shipment_status_update_t *result = shipment_status_update_create_internal (
        delivered_at,
        signed_by,
        status,
        tracking_number
        );
    if (!result) {
    }
    return result;
}

void shipment_status_update_free(shipment_status_update_t *shipment_status_update) {
    if(NULL == shipment_status_update){
        return ;
    }
    if(shipment_status_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "shipment_status_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (shipment_status_update->delivered_at) {
        free(shipment_status_update->delivered_at);
        shipment_status_update->delivered_at = NULL;
    }
    if (shipment_status_update->signed_by) {
        free(shipment_status_update->signed_by);
        shipment_status_update->signed_by = NULL;
    }
    if (shipment_status_update->status) {
        free(shipment_status_update->status);
        shipment_status_update->status = NULL;
    }
    if (shipment_status_update->tracking_number) {
        free(shipment_status_update->tracking_number);
        shipment_status_update->tracking_number = NULL;
    }
    free(shipment_status_update);
}

cJSON *shipment_status_update_convertToJSON(shipment_status_update_t *shipment_status_update) {
    cJSON *item = cJSON_CreateObject();

    // shipment_status_update->delivered_at
    if(shipment_status_update->delivered_at) {
    if(cJSON_AddStringToObject(item, "delivered_at", shipment_status_update->delivered_at) == NULL) {
    goto fail; //String
    }
    }


    // shipment_status_update->signed_by
    if(shipment_status_update->signed_by) {
    if(cJSON_AddStringToObject(item, "signed_by", shipment_status_update->signed_by) == NULL) {
    goto fail; //String
    }
    }


    // shipment_status_update->status
    if (!shipment_status_update->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", shipment_status_update->status) == NULL) {
    goto fail; //String
    }


    // shipment_status_update->tracking_number
    if(shipment_status_update->tracking_number) {
    if(cJSON_AddStringToObject(item, "tracking_number", shipment_status_update->tracking_number) == NULL) {
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

shipment_status_update_t *shipment_status_update_parseFromJSON(cJSON *shipment_status_updateJSON){

    shipment_status_update_t *shipment_status_update_local_var = NULL;

    char *delivered_at_local_str = NULL;

    char *signed_by_local_str = NULL;

    char *status_local_str = NULL;

    char *tracking_number_local_str = NULL;

    // shipment_status_update->delivered_at
    cJSON *delivered_at = cJSON_GetObjectItemCaseSensitive(shipment_status_updateJSON, "delivered_at");
    if (cJSON_IsNull(delivered_at)) {
        delivered_at = NULL;
    }
    if (delivered_at) { 
    if(!cJSON_IsString(delivered_at) && !cJSON_IsNull(delivered_at))
    {
    goto end; //String
    }
    }

    // shipment_status_update->signed_by
    cJSON *signed_by = cJSON_GetObjectItemCaseSensitive(shipment_status_updateJSON, "signed_by");
    if (cJSON_IsNull(signed_by)) {
        signed_by = NULL;
    }
    if (signed_by) { 
    if(!cJSON_IsString(signed_by) && !cJSON_IsNull(signed_by))
    {
    goto end; //String
    }
    }

    // shipment_status_update->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(shipment_status_updateJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // shipment_status_update->tracking_number
    cJSON *tracking_number = cJSON_GetObjectItemCaseSensitive(shipment_status_updateJSON, "tracking_number");
    if (cJSON_IsNull(tracking_number)) {
        tracking_number = NULL;
    }
    if (tracking_number) { 
    if(!cJSON_IsString(tracking_number) && !cJSON_IsNull(tracking_number))
    {
    goto end; //String
    }
    }


    if (delivered_at && !cJSON_IsNull(delivered_at)) delivered_at_local_str = strdup(delivered_at->valuestring);
    if (signed_by && !cJSON_IsNull(signed_by)) signed_by_local_str = strdup(signed_by->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);
    if (tracking_number && !cJSON_IsNull(tracking_number)) tracking_number_local_str = strdup(tracking_number->valuestring);

    shipment_status_update_local_var = shipment_status_update_create_internal (
        delivered_at_local_str,
        signed_by_local_str,
        status_local_str,
        tracking_number_local_str
        );

    if (!shipment_status_update_local_var) {
        goto end;
    }

    return shipment_status_update_local_var;
end:
    if (delivered_at_local_str) {
        free(delivered_at_local_str);
        delivered_at_local_str = NULL;
    }
    if (signed_by_local_str) {
        free(signed_by_local_str);
        signed_by_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (tracking_number_local_str) {
        free(tracking_number_local_str);
        tracking_number_local_str = NULL;
    }
    return NULL;

}
