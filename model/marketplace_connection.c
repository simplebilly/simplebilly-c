#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "marketplace_connection.h"



static marketplace_connection_t *marketplace_connection_create_internal(
    any_type_t *config,
    char *connection_id,
    simplebilly_api_connector_type__e connector_type,
    char *created_at,
    int *is_active,
    char *label,
    char *last_sync_at,
    char *platform,
    char *platform_user_id,
    char *scopes,
    char *shop_domain,
    char *shop_name,
    char *sync_status,
    char *tenant_id,
    char *updated_at
    ) {
    marketplace_connection_t *marketplace_connection_local_var = malloc(sizeof(marketplace_connection_t));
    if (!marketplace_connection_local_var) {
        return NULL;
    }
    memset(marketplace_connection_local_var, 0, sizeof(marketplace_connection_t));
    marketplace_connection_local_var->_library_owned = 1;
    marketplace_connection_local_var->config = config;
    marketplace_connection_local_var->connection_id = connection_id;
    marketplace_connection_local_var->connector_type = connector_type;
    marketplace_connection_local_var->created_at = created_at;
    marketplace_connection_local_var->is_active = is_active;
    marketplace_connection_local_var->label = label;
    marketplace_connection_local_var->last_sync_at = last_sync_at;
    marketplace_connection_local_var->platform = platform;
    marketplace_connection_local_var->platform_user_id = platform_user_id;
    marketplace_connection_local_var->scopes = scopes;
    marketplace_connection_local_var->shop_domain = shop_domain;
    marketplace_connection_local_var->shop_name = shop_name;
    marketplace_connection_local_var->sync_status = sync_status;
    marketplace_connection_local_var->tenant_id = tenant_id;
    marketplace_connection_local_var->updated_at = updated_at;
    return marketplace_connection_local_var;
}

__attribute__((deprecated)) marketplace_connection_t *marketplace_connection_create(
    any_type_t *config,
    char *connection_id,
    simplebilly_api_connector_type__e connector_type,
    char *created_at,
    int *is_active,
    char *label,
    char *last_sync_at,
    char *platform,
    char *platform_user_id,
    char *scopes,
    char *shop_domain,
    char *shop_name,
    char *sync_status,
    char *tenant_id,
    char *updated_at
    ) {
    int *is_active_copy = NULL;
    if (is_active) {
        is_active_copy = malloc(sizeof(int));
        if (is_active_copy) *is_active_copy = *is_active;
    }
    marketplace_connection_t *result = marketplace_connection_create_internal (
        config,
        connection_id,
        connector_type,
        created_at,
        is_active_copy,
        label,
        last_sync_at,
        platform,
        platform_user_id,
        scopes,
        shop_domain,
        shop_name,
        sync_status,
        tenant_id,
        updated_at
        );
    if (!result) {
        free(is_active_copy);
    }
    return result;
}

void marketplace_connection_free(marketplace_connection_t *marketplace_connection) {
    if(NULL == marketplace_connection){
        return ;
    }
    if(marketplace_connection->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "marketplace_connection_free");
        return ;
    }
    listEntry_t *listEntry;
    if (marketplace_connection->config) {
        _free(marketplace_connection->config);
        marketplace_connection->config = NULL;
    }
    if (marketplace_connection->connection_id) {
        free(marketplace_connection->connection_id);
        marketplace_connection->connection_id = NULL;
    }
    if (marketplace_connection->created_at) {
        free(marketplace_connection->created_at);
        marketplace_connection->created_at = NULL;
    }
    if (marketplace_connection->is_active) {
        free(marketplace_connection->is_active);
        marketplace_connection->is_active = NULL;
    }
    if (marketplace_connection->label) {
        free(marketplace_connection->label);
        marketplace_connection->label = NULL;
    }
    if (marketplace_connection->last_sync_at) {
        free(marketplace_connection->last_sync_at);
        marketplace_connection->last_sync_at = NULL;
    }
    if (marketplace_connection->platform) {
        free(marketplace_connection->platform);
        marketplace_connection->platform = NULL;
    }
    if (marketplace_connection->platform_user_id) {
        free(marketplace_connection->platform_user_id);
        marketplace_connection->platform_user_id = NULL;
    }
    if (marketplace_connection->scopes) {
        free(marketplace_connection->scopes);
        marketplace_connection->scopes = NULL;
    }
    if (marketplace_connection->shop_domain) {
        free(marketplace_connection->shop_domain);
        marketplace_connection->shop_domain = NULL;
    }
    if (marketplace_connection->shop_name) {
        free(marketplace_connection->shop_name);
        marketplace_connection->shop_name = NULL;
    }
    if (marketplace_connection->sync_status) {
        free(marketplace_connection->sync_status);
        marketplace_connection->sync_status = NULL;
    }
    if (marketplace_connection->tenant_id) {
        free(marketplace_connection->tenant_id);
        marketplace_connection->tenant_id = NULL;
    }
    if (marketplace_connection->updated_at) {
        free(marketplace_connection->updated_at);
        marketplace_connection->updated_at = NULL;
    }
    free(marketplace_connection);
}

cJSON *marketplace_connection_convertToJSON(marketplace_connection_t *marketplace_connection) {
    cJSON *item = cJSON_CreateObject();

    // marketplace_connection->config
    if (!marketplace_connection->config) {
        goto fail;
    }
    cJSON *config_local_JSON = _convertToJSON(marketplace_connection->config);
    if(config_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // marketplace_connection->connection_id
    if (!marketplace_connection->connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "connection_id", marketplace_connection->connection_id) == NULL) {
    goto fail; //String
    }


    // marketplace_connection->connector_type
    if (simplebilly_api_connector_type__NULL == marketplace_connection->connector_type) {
        goto fail;
    }
    cJSON *connector_type_local_JSON = connector_type_convertToJSON(marketplace_connection->connector_type);
    if(connector_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "connector_type", connector_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // marketplace_connection->created_at
    if (!marketplace_connection->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "created_at", marketplace_connection->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // marketplace_connection->is_active
    if (!marketplace_connection->is_active) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_active", *marketplace_connection->is_active) == NULL) {
    goto fail; //Bool
    }


    // marketplace_connection->label
    if (!marketplace_connection->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", marketplace_connection->label) == NULL) {
    goto fail; //String
    }


    // marketplace_connection->last_sync_at
    if(marketplace_connection->last_sync_at) {
    if(cJSON_AddStringToObject(item, "last_sync_at", marketplace_connection->last_sync_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // marketplace_connection->platform
    if (!marketplace_connection->platform) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "platform", marketplace_connection->platform) == NULL) {
    goto fail; //String
    }


    // marketplace_connection->platform_user_id
    if(marketplace_connection->platform_user_id) {
    if(cJSON_AddStringToObject(item, "platform_user_id", marketplace_connection->platform_user_id) == NULL) {
    goto fail; //String
    }
    }


    // marketplace_connection->scopes
    if(marketplace_connection->scopes) {
    if(cJSON_AddStringToObject(item, "scopes", marketplace_connection->scopes) == NULL) {
    goto fail; //String
    }
    }


    // marketplace_connection->shop_domain
    if(marketplace_connection->shop_domain) {
    if(cJSON_AddStringToObject(item, "shop_domain", marketplace_connection->shop_domain) == NULL) {
    goto fail; //String
    }
    }


    // marketplace_connection->shop_name
    if(marketplace_connection->shop_name) {
    if(cJSON_AddStringToObject(item, "shop_name", marketplace_connection->shop_name) == NULL) {
    goto fail; //String
    }
    }


    // marketplace_connection->sync_status
    if(marketplace_connection->sync_status) {
    if(cJSON_AddStringToObject(item, "sync_status", marketplace_connection->sync_status) == NULL) {
    goto fail; //String
    }
    }


    // marketplace_connection->tenant_id
    if (!marketplace_connection->tenant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenant_id", marketplace_connection->tenant_id) == NULL) {
    goto fail; //String
    }


    // marketplace_connection->updated_at
    if(marketplace_connection->updated_at) {
    if(cJSON_AddStringToObject(item, "updated_at", marketplace_connection->updated_at) == NULL) {
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

marketplace_connection_t *marketplace_connection_parseFromJSON(cJSON *marketplace_connectionJSON){

    marketplace_connection_t *marketplace_connection_local_var = NULL;

    // define the local variable for marketplace_connection->config
    _t *config_local_nonprim = NULL;

    char *connection_id_local_str = NULL;

    // define the local variable for marketplace_connection->connector_type
    simplebilly_api_connector_type__e connector_type_local_nonprim = 0;

    char *created_at_local_str = NULL;

    // define the local variable for marketplace_connection->is_active
    int *is_active_local_var = NULL;

    char *label_local_str = NULL;

    char *last_sync_at_local_str = NULL;

    char *platform_local_str = NULL;

    char *platform_user_id_local_str = NULL;

    char *scopes_local_str = NULL;

    char *shop_domain_local_str = NULL;

    char *shop_name_local_str = NULL;

    char *sync_status_local_str = NULL;

    char *tenant_id_local_str = NULL;

    char *updated_at_local_str = NULL;

    // marketplace_connection->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(marketplace_connectionJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (!config) {
        goto end;
    }

    
    config_local_nonprim = _parseFromJSON(config); //custom

    // marketplace_connection->connection_id
    cJSON *connection_id = cJSON_GetObjectItemCaseSensitive(marketplace_connectionJSON, "connection_id");
    if (cJSON_IsNull(connection_id)) {
        connection_id = NULL;
    }
    if (!connection_id) {
        goto end;
    }

    
    if(!cJSON_IsString(connection_id))
    {
    goto end; //String
    }

    // marketplace_connection->connector_type
    cJSON *connector_type = cJSON_GetObjectItemCaseSensitive(marketplace_connectionJSON, "connector_type");
    if (cJSON_IsNull(connector_type)) {
        connector_type = NULL;
    }
    if (!connector_type) {
        goto end;
    }

    
    connector_type_local_nonprim = connector_type_parseFromJSON(connector_type); //custom

    // marketplace_connection->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(marketplace_connectionJSON, "created_at");
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

    // marketplace_connection->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(marketplace_connectionJSON, "is_active");
    if (cJSON_IsNull(is_active)) {
        is_active = NULL;
    }
    if (!is_active) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_active))
    {
    goto end; //Bool
    }
    is_active_local_var = malloc(sizeof(int));
    if(!is_active_local_var)
    {
        goto end;
    }
    *is_active_local_var = is_active->valueint;

    // marketplace_connection->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(marketplace_connectionJSON, "label");
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

    // marketplace_connection->last_sync_at
    cJSON *last_sync_at = cJSON_GetObjectItemCaseSensitive(marketplace_connectionJSON, "last_sync_at");
    if (cJSON_IsNull(last_sync_at)) {
        last_sync_at = NULL;
    }
    if (last_sync_at) { 
    if(!cJSON_IsString(last_sync_at) && !cJSON_IsNull(last_sync_at))
    {
    goto end; //DateTime
    }
    }

    // marketplace_connection->platform
    cJSON *platform = cJSON_GetObjectItemCaseSensitive(marketplace_connectionJSON, "platform");
    if (cJSON_IsNull(platform)) {
        platform = NULL;
    }
    if (!platform) {
        goto end;
    }

    
    if(!cJSON_IsString(platform))
    {
    goto end; //String
    }

    // marketplace_connection->platform_user_id
    cJSON *platform_user_id = cJSON_GetObjectItemCaseSensitive(marketplace_connectionJSON, "platform_user_id");
    if (cJSON_IsNull(platform_user_id)) {
        platform_user_id = NULL;
    }
    if (platform_user_id) { 
    if(!cJSON_IsString(platform_user_id) && !cJSON_IsNull(platform_user_id))
    {
    goto end; //String
    }
    }

    // marketplace_connection->scopes
    cJSON *scopes = cJSON_GetObjectItemCaseSensitive(marketplace_connectionJSON, "scopes");
    if (cJSON_IsNull(scopes)) {
        scopes = NULL;
    }
    if (scopes) { 
    if(!cJSON_IsString(scopes) && !cJSON_IsNull(scopes))
    {
    goto end; //String
    }
    }

    // marketplace_connection->shop_domain
    cJSON *shop_domain = cJSON_GetObjectItemCaseSensitive(marketplace_connectionJSON, "shop_domain");
    if (cJSON_IsNull(shop_domain)) {
        shop_domain = NULL;
    }
    if (shop_domain) { 
    if(!cJSON_IsString(shop_domain) && !cJSON_IsNull(shop_domain))
    {
    goto end; //String
    }
    }

    // marketplace_connection->shop_name
    cJSON *shop_name = cJSON_GetObjectItemCaseSensitive(marketplace_connectionJSON, "shop_name");
    if (cJSON_IsNull(shop_name)) {
        shop_name = NULL;
    }
    if (shop_name) { 
    if(!cJSON_IsString(shop_name) && !cJSON_IsNull(shop_name))
    {
    goto end; //String
    }
    }

    // marketplace_connection->sync_status
    cJSON *sync_status = cJSON_GetObjectItemCaseSensitive(marketplace_connectionJSON, "sync_status");
    if (cJSON_IsNull(sync_status)) {
        sync_status = NULL;
    }
    if (sync_status) { 
    if(!cJSON_IsString(sync_status) && !cJSON_IsNull(sync_status))
    {
    goto end; //String
    }
    }

    // marketplace_connection->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(marketplace_connectionJSON, "tenant_id");
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

    // marketplace_connection->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(marketplace_connectionJSON, "updated_at");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }


    if (connection_id && !cJSON_IsNull(connection_id)) connection_id_local_str = strdup(connection_id->valuestring);
    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (label && !cJSON_IsNull(label)) label_local_str = strdup(label->valuestring);
    if (last_sync_at && !cJSON_IsNull(last_sync_at)) last_sync_at_local_str = strdup(last_sync_at->valuestring);
    if (platform && !cJSON_IsNull(platform)) platform_local_str = strdup(platform->valuestring);
    if (platform_user_id && !cJSON_IsNull(platform_user_id)) platform_user_id_local_str = strdup(platform_user_id->valuestring);
    if (scopes && !cJSON_IsNull(scopes)) scopes_local_str = strdup(scopes->valuestring);
    if (shop_domain && !cJSON_IsNull(shop_domain)) shop_domain_local_str = strdup(shop_domain->valuestring);
    if (shop_name && !cJSON_IsNull(shop_name)) shop_name_local_str = strdup(shop_name->valuestring);
    if (sync_status && !cJSON_IsNull(sync_status)) sync_status_local_str = strdup(sync_status->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);

    marketplace_connection_local_var = marketplace_connection_create_internal (
        config_local_nonprim,
        connection_id_local_str,
        connector_type_local_nonprim,
        created_at_local_str,
        is_active_local_var,
        label_local_str,
        last_sync_at_local_str,
        platform_local_str,
        platform_user_id_local_str,
        scopes_local_str,
        shop_domain_local_str,
        shop_name_local_str,
        sync_status_local_str,
        tenant_id_local_str,
        updated_at_local_str
        );

    if (!marketplace_connection_local_var) {
        goto end;
    }

    return marketplace_connection_local_var;
end:
    if (config_local_nonprim) {
        _free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    if (connection_id_local_str) {
        free(connection_id_local_str);
        connection_id_local_str = NULL;
    }
    if (connector_type_local_nonprim) {
        connector_type_local_nonprim = 0;
    }
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (is_active_local_var) {
        free(is_active_local_var);
        is_active_local_var = NULL;
    }
    if (label_local_str) {
        free(label_local_str);
        label_local_str = NULL;
    }
    if (last_sync_at_local_str) {
        free(last_sync_at_local_str);
        last_sync_at_local_str = NULL;
    }
    if (platform_local_str) {
        free(platform_local_str);
        platform_local_str = NULL;
    }
    if (platform_user_id_local_str) {
        free(platform_user_id_local_str);
        platform_user_id_local_str = NULL;
    }
    if (scopes_local_str) {
        free(scopes_local_str);
        scopes_local_str = NULL;
    }
    if (shop_domain_local_str) {
        free(shop_domain_local_str);
        shop_domain_local_str = NULL;
    }
    if (shop_name_local_str) {
        free(shop_name_local_str);
        shop_name_local_str = NULL;
    }
    if (sync_status_local_str) {
        free(sync_status_local_str);
        sync_status_local_str = NULL;
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
