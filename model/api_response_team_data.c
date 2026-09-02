#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "api_response_team_data.h"



static api_response_team_data_t *api_response_team_data_create_internal(
    char *created_at,
    char *description,
    char *id,
    char *name,
    char *parent_team_id,
    char *tenant_id,
    char *updated_at
    ) {
    api_response_team_data_t *api_response_team_data_local_var = malloc(sizeof(api_response_team_data_t));
    if (!api_response_team_data_local_var) {
        return NULL;
    }
    memset(api_response_team_data_local_var, 0, sizeof(api_response_team_data_t));
    api_response_team_data_local_var->_library_owned = 1;
    api_response_team_data_local_var->created_at = created_at;
    api_response_team_data_local_var->description = description;
    api_response_team_data_local_var->id = id;
    api_response_team_data_local_var->name = name;
    api_response_team_data_local_var->parent_team_id = parent_team_id;
    api_response_team_data_local_var->tenant_id = tenant_id;
    api_response_team_data_local_var->updated_at = updated_at;
    return api_response_team_data_local_var;
}

__attribute__((deprecated)) api_response_team_data_t *api_response_team_data_create(
    char *created_at,
    char *description,
    char *id,
    char *name,
    char *parent_team_id,
    char *tenant_id,
    char *updated_at
    ) {
    api_response_team_data_t *result = api_response_team_data_create_internal (
        created_at,
        description,
        id,
        name,
        parent_team_id,
        tenant_id,
        updated_at
        );
    if (!result) {
    }
    return result;
}

void api_response_team_data_free(api_response_team_data_t *api_response_team_data) {
    if(NULL == api_response_team_data){
        return ;
    }
    if(api_response_team_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "api_response_team_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (api_response_team_data->created_at) {
        free(api_response_team_data->created_at);
        api_response_team_data->created_at = NULL;
    }
    if (api_response_team_data->description) {
        free(api_response_team_data->description);
        api_response_team_data->description = NULL;
    }
    if (api_response_team_data->id) {
        free(api_response_team_data->id);
        api_response_team_data->id = NULL;
    }
    if (api_response_team_data->name) {
        free(api_response_team_data->name);
        api_response_team_data->name = NULL;
    }
    if (api_response_team_data->parent_team_id) {
        free(api_response_team_data->parent_team_id);
        api_response_team_data->parent_team_id = NULL;
    }
    if (api_response_team_data->tenant_id) {
        free(api_response_team_data->tenant_id);
        api_response_team_data->tenant_id = NULL;
    }
    if (api_response_team_data->updated_at) {
        free(api_response_team_data->updated_at);
        api_response_team_data->updated_at = NULL;
    }
    free(api_response_team_data);
}

cJSON *api_response_team_data_convertToJSON(api_response_team_data_t *api_response_team_data) {
    cJSON *item = cJSON_CreateObject();

    // api_response_team_data->created_at
    if (!api_response_team_data->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "created_at", api_response_team_data->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // api_response_team_data->description
    if(api_response_team_data->description) {
    if(cJSON_AddStringToObject(item, "description", api_response_team_data->description) == NULL) {
    goto fail; //String
    }
    }


    // api_response_team_data->id
    if (!api_response_team_data->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", api_response_team_data->id) == NULL) {
    goto fail; //String
    }


    // api_response_team_data->name
    if (!api_response_team_data->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", api_response_team_data->name) == NULL) {
    goto fail; //String
    }


    // api_response_team_data->parent_team_id
    if(api_response_team_data->parent_team_id) {
    if(cJSON_AddStringToObject(item, "parent_team_id", api_response_team_data->parent_team_id) == NULL) {
    goto fail; //String
    }
    }


    // api_response_team_data->tenant_id
    if (!api_response_team_data->tenant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenant_id", api_response_team_data->tenant_id) == NULL) {
    goto fail; //String
    }


    // api_response_team_data->updated_at
    if (!api_response_team_data->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updated_at", api_response_team_data->updated_at) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

api_response_team_data_t *api_response_team_data_parseFromJSON(cJSON *api_response_team_dataJSON){

    api_response_team_data_t *api_response_team_data_local_var = NULL;

    char *created_at_local_str = NULL;

    char *description_local_str = NULL;

    char *id_local_str = NULL;

    char *name_local_str = NULL;

    char *parent_team_id_local_str = NULL;

    char *tenant_id_local_str = NULL;

    char *updated_at_local_str = NULL;

    // api_response_team_data->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(api_response_team_dataJSON, "created_at");
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

    // api_response_team_data->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(api_response_team_dataJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // api_response_team_data->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(api_response_team_dataJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // api_response_team_data->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(api_response_team_dataJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // api_response_team_data->parent_team_id
    cJSON *parent_team_id = cJSON_GetObjectItemCaseSensitive(api_response_team_dataJSON, "parent_team_id");
    if (cJSON_IsNull(parent_team_id)) {
        parent_team_id = NULL;
    }
    if (parent_team_id) { 
    if(!cJSON_IsString(parent_team_id) && !cJSON_IsNull(parent_team_id))
    {
    goto end; //String
    }
    }

    // api_response_team_data->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(api_response_team_dataJSON, "tenant_id");
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

    // api_response_team_data->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(api_response_team_dataJSON, "updated_at");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (!updated_at) {
        goto end;
    }

    
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }


    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (parent_team_id && !cJSON_IsNull(parent_team_id)) parent_team_id_local_str = strdup(parent_team_id->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);

    api_response_team_data_local_var = api_response_team_data_create_internal (
        created_at_local_str,
        description_local_str,
        id_local_str,
        name_local_str,
        parent_team_id_local_str,
        tenant_id_local_str,
        updated_at_local_str
        );

    if (!api_response_team_data_local_var) {
        goto end;
    }

    return api_response_team_data_local_var;
end:
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (parent_team_id_local_str) {
        free(parent_team_id_local_str);
        parent_team_id_local_str = NULL;
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
