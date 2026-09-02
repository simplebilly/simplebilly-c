#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "team_create.h"



static team_create_t *team_create_create_internal(
    char *description,
    char *name,
    char *parent_team_id
    ) {
    team_create_t *team_create_local_var = malloc(sizeof(team_create_t));
    if (!team_create_local_var) {
        return NULL;
    }
    memset(team_create_local_var, 0, sizeof(team_create_t));
    team_create_local_var->_library_owned = 1;
    team_create_local_var->description = description;
    team_create_local_var->name = name;
    team_create_local_var->parent_team_id = parent_team_id;
    return team_create_local_var;
}

__attribute__((deprecated)) team_create_t *team_create_create(
    char *description,
    char *name,
    char *parent_team_id
    ) {
    team_create_t *result = team_create_create_internal (
        description,
        name,
        parent_team_id
        );
    if (!result) {
    }
    return result;
}

void team_create_free(team_create_t *team_create) {
    if(NULL == team_create){
        return ;
    }
    if(team_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "team_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (team_create->description) {
        free(team_create->description);
        team_create->description = NULL;
    }
    if (team_create->name) {
        free(team_create->name);
        team_create->name = NULL;
    }
    if (team_create->parent_team_id) {
        free(team_create->parent_team_id);
        team_create->parent_team_id = NULL;
    }
    free(team_create);
}

cJSON *team_create_convertToJSON(team_create_t *team_create) {
    cJSON *item = cJSON_CreateObject();

    // team_create->description
    if(team_create->description) {
    if(cJSON_AddStringToObject(item, "description", team_create->description) == NULL) {
    goto fail; //String
    }
    }


    // team_create->name
    if (!team_create->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", team_create->name) == NULL) {
    goto fail; //String
    }


    // team_create->parent_team_id
    if(team_create->parent_team_id) {
    if(cJSON_AddStringToObject(item, "parentTeamId", team_create->parent_team_id) == NULL) {
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

team_create_t *team_create_parseFromJSON(cJSON *team_createJSON){

    team_create_t *team_create_local_var = NULL;

    char *description_local_str = NULL;

    char *name_local_str = NULL;

    char *parent_team_id_local_str = NULL;

    // team_create->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(team_createJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // team_create->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(team_createJSON, "name");
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

    // team_create->parent_team_id
    cJSON *parent_team_id = cJSON_GetObjectItemCaseSensitive(team_createJSON, "parentTeamId");
    if (cJSON_IsNull(parent_team_id)) {
        parent_team_id = NULL;
    }
    if (parent_team_id) { 
    if(!cJSON_IsString(parent_team_id) && !cJSON_IsNull(parent_team_id))
    {
    goto end; //String
    }
    }


    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (parent_team_id && !cJSON_IsNull(parent_team_id)) parent_team_id_local_str = strdup(parent_team_id->valuestring);

    team_create_local_var = team_create_create_internal (
        description_local_str,
        name_local_str,
        parent_team_id_local_str
        );

    if (!team_create_local_var) {
        goto end;
    }

    return team_create_local_var;
end:
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (parent_team_id_local_str) {
        free(parent_team_id_local_str);
        parent_team_id_local_str = NULL;
    }
    return NULL;

}
