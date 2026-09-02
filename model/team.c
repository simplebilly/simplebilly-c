#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "team.h"



static team_t *team_create_internal(
    char *created_at,
    char *description,
    char *id,
    char *name,
    char *parent_team_id,
    char *tenant_id,
    char *updated_at
    ) {
    team_t *team_local_var = malloc(sizeof(team_t));
    if (!team_local_var) {
        return NULL;
    }
    memset(team_local_var, 0, sizeof(team_t));
    team_local_var->_library_owned = 1;
    team_local_var->created_at = created_at;
    team_local_var->description = description;
    team_local_var->id = id;
    team_local_var->name = name;
    team_local_var->parent_team_id = parent_team_id;
    team_local_var->tenant_id = tenant_id;
    team_local_var->updated_at = updated_at;
    return team_local_var;
}

__attribute__((deprecated)) team_t *team_create(
    char *created_at,
    char *description,
    char *id,
    char *name,
    char *parent_team_id,
    char *tenant_id,
    char *updated_at
    ) {
    team_t *result = team_create_internal (
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

void team_free(team_t *team) {
    if(NULL == team){
        return ;
    }
    if(team->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "team_free");
        return ;
    }
    listEntry_t *listEntry;
    if (team->created_at) {
        free(team->created_at);
        team->created_at = NULL;
    }
    if (team->description) {
        free(team->description);
        team->description = NULL;
    }
    if (team->id) {
        free(team->id);
        team->id = NULL;
    }
    if (team->name) {
        free(team->name);
        team->name = NULL;
    }
    if (team->parent_team_id) {
        free(team->parent_team_id);
        team->parent_team_id = NULL;
    }
    if (team->tenant_id) {
        free(team->tenant_id);
        team->tenant_id = NULL;
    }
    if (team->updated_at) {
        free(team->updated_at);
        team->updated_at = NULL;
    }
    free(team);
}

cJSON *team_convertToJSON(team_t *team) {
    cJSON *item = cJSON_CreateObject();

    // team->created_at
    if (!team->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "created_at", team->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // team->description
    if(team->description) {
    if(cJSON_AddStringToObject(item, "description", team->description) == NULL) {
    goto fail; //String
    }
    }


    // team->id
    if (!team->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", team->id) == NULL) {
    goto fail; //String
    }


    // team->name
    if (!team->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", team->name) == NULL) {
    goto fail; //String
    }


    // team->parent_team_id
    if(team->parent_team_id) {
    if(cJSON_AddStringToObject(item, "parent_team_id", team->parent_team_id) == NULL) {
    goto fail; //String
    }
    }


    // team->tenant_id
    if (!team->tenant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenant_id", team->tenant_id) == NULL) {
    goto fail; //String
    }


    // team->updated_at
    if (!team->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updated_at", team->updated_at) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

team_t *team_parseFromJSON(cJSON *teamJSON){

    team_t *team_local_var = NULL;

    char *created_at_local_str = NULL;

    char *description_local_str = NULL;

    char *id_local_str = NULL;

    char *name_local_str = NULL;

    char *parent_team_id_local_str = NULL;

    char *tenant_id_local_str = NULL;

    char *updated_at_local_str = NULL;

    // team->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(teamJSON, "created_at");
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

    // team->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(teamJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // team->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(teamJSON, "id");
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

    // team->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(teamJSON, "name");
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

    // team->parent_team_id
    cJSON *parent_team_id = cJSON_GetObjectItemCaseSensitive(teamJSON, "parent_team_id");
    if (cJSON_IsNull(parent_team_id)) {
        parent_team_id = NULL;
    }
    if (parent_team_id) { 
    if(!cJSON_IsString(parent_team_id) && !cJSON_IsNull(parent_team_id))
    {
    goto end; //String
    }
    }

    // team->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(teamJSON, "tenant_id");
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

    // team->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(teamJSON, "updated_at");
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

    team_local_var = team_create_internal (
        created_at_local_str,
        description_local_str,
        id_local_str,
        name_local_str,
        parent_team_id_local_str,
        tenant_id_local_str,
        updated_at_local_str
        );

    if (!team_local_var) {
        goto end;
    }

    return team_local_var;
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
