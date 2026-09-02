#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "payment_gateway.h"



static payment_gateway_t *payment_gateway_create_internal(
    any_type_t *config,
    char *created_at,
    char *deleted_at,
    int *enabled,
    char *gateway_id,
    simplebilly_api_gateway_type__e gateway_type,
    char *label,
    char *tenant_id,
    char *updated_at
    ) {
    payment_gateway_t *payment_gateway_local_var = malloc(sizeof(payment_gateway_t));
    if (!payment_gateway_local_var) {
        return NULL;
    }
    memset(payment_gateway_local_var, 0, sizeof(payment_gateway_t));
    payment_gateway_local_var->_library_owned = 1;
    payment_gateway_local_var->config = config;
    payment_gateway_local_var->created_at = created_at;
    payment_gateway_local_var->deleted_at = deleted_at;
    payment_gateway_local_var->enabled = enabled;
    payment_gateway_local_var->gateway_id = gateway_id;
    payment_gateway_local_var->gateway_type = gateway_type;
    payment_gateway_local_var->label = label;
    payment_gateway_local_var->tenant_id = tenant_id;
    payment_gateway_local_var->updated_at = updated_at;
    return payment_gateway_local_var;
}

__attribute__((deprecated)) payment_gateway_t *payment_gateway_create(
    any_type_t *config,
    char *created_at,
    char *deleted_at,
    int *enabled,
    char *gateway_id,
    simplebilly_api_gateway_type__e gateway_type,
    char *label,
    char *tenant_id,
    char *updated_at
    ) {
    int *enabled_copy = NULL;
    if (enabled) {
        enabled_copy = malloc(sizeof(int));
        if (enabled_copy) *enabled_copy = *enabled;
    }
    payment_gateway_t *result = payment_gateway_create_internal (
        config,
        created_at,
        deleted_at,
        enabled_copy,
        gateway_id,
        gateway_type,
        label,
        tenant_id,
        updated_at
        );
    if (!result) {
        free(enabled_copy);
    }
    return result;
}

void payment_gateway_free(payment_gateway_t *payment_gateway) {
    if(NULL == payment_gateway){
        return ;
    }
    if(payment_gateway->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "payment_gateway_free");
        return ;
    }
    listEntry_t *listEntry;
    if (payment_gateway->config) {
        _free(payment_gateway->config);
        payment_gateway->config = NULL;
    }
    if (payment_gateway->created_at) {
        free(payment_gateway->created_at);
        payment_gateway->created_at = NULL;
    }
    if (payment_gateway->deleted_at) {
        free(payment_gateway->deleted_at);
        payment_gateway->deleted_at = NULL;
    }
    if (payment_gateway->enabled) {
        free(payment_gateway->enabled);
        payment_gateway->enabled = NULL;
    }
    if (payment_gateway->gateway_id) {
        free(payment_gateway->gateway_id);
        payment_gateway->gateway_id = NULL;
    }
    if (payment_gateway->label) {
        free(payment_gateway->label);
        payment_gateway->label = NULL;
    }
    if (payment_gateway->tenant_id) {
        free(payment_gateway->tenant_id);
        payment_gateway->tenant_id = NULL;
    }
    if (payment_gateway->updated_at) {
        free(payment_gateway->updated_at);
        payment_gateway->updated_at = NULL;
    }
    free(payment_gateway);
}

cJSON *payment_gateway_convertToJSON(payment_gateway_t *payment_gateway) {
    cJSON *item = cJSON_CreateObject();

    // payment_gateway->config
    if (!payment_gateway->config) {
        goto fail;
    }
    cJSON *config_local_JSON = _convertToJSON(payment_gateway->config);
    if(config_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // payment_gateway->created_at
    if (!payment_gateway->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", payment_gateway->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // payment_gateway->deleted_at
    if(payment_gateway->deleted_at) {
    if(cJSON_AddStringToObject(item, "deletedAt", payment_gateway->deleted_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // payment_gateway->enabled
    if (!payment_gateway->enabled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "enabled", *payment_gateway->enabled) == NULL) {
    goto fail; //Bool
    }


    // payment_gateway->gateway_id
    if (!payment_gateway->gateway_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gatewayId", payment_gateway->gateway_id) == NULL) {
    goto fail; //String
    }


    // payment_gateway->gateway_type
    if (simplebilly_api_gateway_type__NULL == payment_gateway->gateway_type) {
        goto fail;
    }
    cJSON *gateway_type_local_JSON = gateway_type_convertToJSON(payment_gateway->gateway_type);
    if(gateway_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "gatewayType", gateway_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // payment_gateway->label
    if (!payment_gateway->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", payment_gateway->label) == NULL) {
    goto fail; //String
    }


    // payment_gateway->tenant_id
    if (!payment_gateway->tenant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenantId", payment_gateway->tenant_id) == NULL) {
    goto fail; //String
    }


    // payment_gateway->updated_at
    if(payment_gateway->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", payment_gateway->updated_at) == NULL) {
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

payment_gateway_t *payment_gateway_parseFromJSON(cJSON *payment_gatewayJSON){

    payment_gateway_t *payment_gateway_local_var = NULL;

    // define the local variable for payment_gateway->config
    _t *config_local_nonprim = NULL;

    char *created_at_local_str = NULL;

    char *deleted_at_local_str = NULL;

    // define the local variable for payment_gateway->enabled
    int *enabled_local_var = NULL;

    char *gateway_id_local_str = NULL;

    // define the local variable for payment_gateway->gateway_type
    simplebilly_api_gateway_type__e gateway_type_local_nonprim = 0;

    char *label_local_str = NULL;

    char *tenant_id_local_str = NULL;

    char *updated_at_local_str = NULL;

    // payment_gateway->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(payment_gatewayJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (!config) {
        goto end;
    }

    
    config_local_nonprim = _parseFromJSON(config); //custom

    // payment_gateway->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(payment_gatewayJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }

    // payment_gateway->deleted_at
    cJSON *deleted_at = cJSON_GetObjectItemCaseSensitive(payment_gatewayJSON, "deletedAt");
    if (cJSON_IsNull(deleted_at)) {
        deleted_at = NULL;
    }
    if (deleted_at) { 
    if(!cJSON_IsString(deleted_at) && !cJSON_IsNull(deleted_at))
    {
    goto end; //DateTime
    }
    }

    // payment_gateway->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(payment_gatewayJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (!enabled) {
        goto end;
    }

    
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

    // payment_gateway->gateway_id
    cJSON *gateway_id = cJSON_GetObjectItemCaseSensitive(payment_gatewayJSON, "gatewayId");
    if (cJSON_IsNull(gateway_id)) {
        gateway_id = NULL;
    }
    if (!gateway_id) {
        goto end;
    }

    
    if(!cJSON_IsString(gateway_id))
    {
    goto end; //String
    }

    // payment_gateway->gateway_type
    cJSON *gateway_type = cJSON_GetObjectItemCaseSensitive(payment_gatewayJSON, "gatewayType");
    if (cJSON_IsNull(gateway_type)) {
        gateway_type = NULL;
    }
    if (!gateway_type) {
        goto end;
    }

    
    gateway_type_local_nonprim = gateway_type_parseFromJSON(gateway_type); //custom

    // payment_gateway->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(payment_gatewayJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (!label) {
        goto end;
    }

    
    if(!cJSON_IsString(label))
    {
    goto end; //String
    }

    // payment_gateway->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(payment_gatewayJSON, "tenantId");
    if (cJSON_IsNull(tenant_id)) {
        tenant_id = NULL;
    }
    if (!tenant_id) {
        goto end;
    }

    
    if(!cJSON_IsString(tenant_id))
    {
    goto end; //String
    }

    // payment_gateway->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(payment_gatewayJSON, "updatedAt");
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
    if (gateway_id && !cJSON_IsNull(gateway_id)) gateway_id_local_str = strdup(gateway_id->valuestring);
    if (label && !cJSON_IsNull(label)) label_local_str = strdup(label->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);

    payment_gateway_local_var = payment_gateway_create_internal (
        config_local_nonprim,
        created_at_local_str,
        deleted_at_local_str,
        enabled_local_var,
        gateway_id_local_str,
        gateway_type_local_nonprim,
        label_local_str,
        tenant_id_local_str,
        updated_at_local_str
        );

    if (!payment_gateway_local_var) {
        goto end;
    }

    return payment_gateway_local_var;
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
    if (gateway_id_local_str) {
        free(gateway_id_local_str);
        gateway_id_local_str = NULL;
    }
    if (gateway_type_local_nonprim) {
        gateway_type_local_nonprim = 0;
    }
    if (label_local_str) {
        free(label_local_str);
        label_local_str = NULL;
    }
    if (tenant_id_local_str) {
        free(tenant_id_local_str);
        tenant_id_local_str = NULL;
    }
    if (updated_at_local_str) {
        free(updated_at_local_str);
        updated_at_local_str = NULL;
    }
    return NULL;

}
