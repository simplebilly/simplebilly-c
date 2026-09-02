#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "payment_gateway_update.h"



static payment_gateway_update_t *payment_gateway_update_create_internal(
    any_type_t *config,
    char *created_at,
    char *deleted_at,
    int *enabled,
    gateway_type_t *gateway_type,
    char *label,
    char *updated_at
    ) {
    payment_gateway_update_t *payment_gateway_update_local_var = malloc(sizeof(payment_gateway_update_t));
    if (!payment_gateway_update_local_var) {
        return NULL;
    }
    memset(payment_gateway_update_local_var, 0, sizeof(payment_gateway_update_t));
    payment_gateway_update_local_var->_library_owned = 1;
    payment_gateway_update_local_var->config = config;
    payment_gateway_update_local_var->created_at = created_at;
    payment_gateway_update_local_var->deleted_at = deleted_at;
    payment_gateway_update_local_var->enabled = enabled;
    payment_gateway_update_local_var->gateway_type = gateway_type;
    payment_gateway_update_local_var->label = label;
    payment_gateway_update_local_var->updated_at = updated_at;
    return payment_gateway_update_local_var;
}

__attribute__((deprecated)) payment_gateway_update_t *payment_gateway_update_create(
    any_type_t *config,
    char *created_at,
    char *deleted_at,
    int *enabled,
    gateway_type_t *gateway_type,
    char *label,
    char *updated_at
    ) {
    int *enabled_copy = NULL;
    if (enabled) {
        enabled_copy = malloc(sizeof(int));
        if (enabled_copy) *enabled_copy = *enabled;
    }
    payment_gateway_update_t *result = payment_gateway_update_create_internal (
        config,
        created_at,
        deleted_at,
        enabled_copy,
        gateway_type,
        label,
        updated_at
        );
    if (!result) {
        free(enabled_copy);
    }
    return result;
}

void payment_gateway_update_free(payment_gateway_update_t *payment_gateway_update) {
    if(NULL == payment_gateway_update){
        return ;
    }
    if(payment_gateway_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "payment_gateway_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (payment_gateway_update->config) {
        _free(payment_gateway_update->config);
        payment_gateway_update->config = NULL;
    }
    if (payment_gateway_update->created_at) {
        free(payment_gateway_update->created_at);
        payment_gateway_update->created_at = NULL;
    }
    if (payment_gateway_update->deleted_at) {
        free(payment_gateway_update->deleted_at);
        payment_gateway_update->deleted_at = NULL;
    }
    if (payment_gateway_update->enabled) {
        free(payment_gateway_update->enabled);
        payment_gateway_update->enabled = NULL;
    }
    if (payment_gateway_update->gateway_type) {
        gateway_type_free(payment_gateway_update->gateway_type);
        payment_gateway_update->gateway_type = NULL;
    }
    if (payment_gateway_update->label) {
        free(payment_gateway_update->label);
        payment_gateway_update->label = NULL;
    }
    if (payment_gateway_update->updated_at) {
        free(payment_gateway_update->updated_at);
        payment_gateway_update->updated_at = NULL;
    }
    free(payment_gateway_update);
}

cJSON *payment_gateway_update_convertToJSON(payment_gateway_update_t *payment_gateway_update) {
    cJSON *item = cJSON_CreateObject();

    // payment_gateway_update->config
    if(payment_gateway_update->config) {
    cJSON *config_local_JSON = _convertToJSON(payment_gateway_update->config);
    if(config_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // payment_gateway_update->created_at
    if(payment_gateway_update->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", payment_gateway_update->created_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // payment_gateway_update->deleted_at
    if(payment_gateway_update->deleted_at) {
    if(cJSON_AddStringToObject(item, "deletedAt", payment_gateway_update->deleted_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // payment_gateway_update->enabled
    if(payment_gateway_update->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", *payment_gateway_update->enabled) == NULL) {
    goto fail; //Bool
    }
    }


    // payment_gateway_update->gateway_type
    if(payment_gateway_update->gateway_type) {
    cJSON *gateway_type_local_JSON = gateway_type_convertToJSON(payment_gateway_update->gateway_type);
    if(gateway_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "gatewayType", gateway_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // payment_gateway_update->label
    if(payment_gateway_update->label) {
    if(cJSON_AddStringToObject(item, "label", payment_gateway_update->label) == NULL) {
    goto fail; //String
    }
    }


    // payment_gateway_update->updated_at
    if(payment_gateway_update->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", payment_gateway_update->updated_at) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

payment_gateway_update_t *payment_gateway_update_parseFromJSON(cJSON *payment_gateway_updateJSON){

    payment_gateway_update_t *payment_gateway_update_local_var = NULL;

    // define the local variable for payment_gateway_update->config
    _t *config_local_nonprim = NULL;

    char *created_at_local_str = NULL;

    char *deleted_at_local_str = NULL;

    // define the local variable for payment_gateway_update->enabled
    int *enabled_local_var = NULL;

    // define the local variable for payment_gateway_update->gateway_type
    gateway_type_t *gateway_type_local_nonprim = NULL;

    char *label_local_str = NULL;

    char *updated_at_local_str = NULL;

    // payment_gateway_update->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(payment_gateway_updateJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = _parseFromJSON(config); //custom
    }

    // payment_gateway_update->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(payment_gateway_updateJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }
    }

    // payment_gateway_update->deleted_at
    cJSON *deleted_at = cJSON_GetObjectItemCaseSensitive(payment_gateway_updateJSON, "deletedAt");
    if (cJSON_IsNull(deleted_at)) {
        deleted_at = NULL;
    }
    if (deleted_at) { 
    if(!cJSON_IsString(deleted_at) && !cJSON_IsNull(deleted_at))
    {
    goto end; //DateTime
    }
    }

    // payment_gateway_update->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(payment_gateway_updateJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (enabled) { 
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }
    enabled_local_var = malloc(sizeof(int));
    if(!enabled_local_var)
    {
        goto end;
    }
    *enabled_local_var = enabled->valueint;
    }

    // payment_gateway_update->gateway_type
    cJSON *gateway_type = cJSON_GetObjectItemCaseSensitive(payment_gateway_updateJSON, "gatewayType");
    if (cJSON_IsNull(gateway_type)) {
        gateway_type = NULL;
    }
    if (gateway_type) { 
    gateway_type_local_nonprim = gateway_type_parseFromJSON(gateway_type); //custom
    }

    // payment_gateway_update->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(payment_gateway_updateJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }

    // payment_gateway_update->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(payment_gateway_updateJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }


    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (deleted_at && !cJSON_IsNull(deleted_at)) deleted_at_local_str = strdup(deleted_at->valuestring);
    if (label && !cJSON_IsNull(label)) label_local_str = strdup(label->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);

    payment_gateway_update_local_var = payment_gateway_update_create_internal (
        config ? config_local_nonprim : NULL,
        created_at_local_str,
        deleted_at_local_str,
        enabled_local_var,
        gateway_type ? gateway_type_local_nonprim : NULL,
        label_local_str,
        updated_at_local_str
        );

    if (!payment_gateway_update_local_var) {
        goto end;
    }

    return payment_gateway_update_local_var;
end:
    if (config_local_nonprim) {
        _free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (deleted_at_local_str) {
        free(deleted_at_local_str);
        deleted_at_local_str = NULL;
    }
    if (enabled_local_var) {
        free(enabled_local_var);
        enabled_local_var = NULL;
    }
    if (gateway_type_local_nonprim) {
        gateway_type_free(gateway_type_local_nonprim);
        gateway_type_local_nonprim = NULL;
    }
    if (label_local_str) {
        free(label_local_str);
        label_local_str = NULL;
    }
    if (updated_at_local_str) {
        free(updated_at_local_str);
        updated_at_local_str = NULL;
    }
    return NULL;

}
