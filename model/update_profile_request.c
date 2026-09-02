#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_profile_request.h"



static update_profile_request_t *update_profile_request_create_internal(
    char *avatar_url,
    char *first_name,
    char *last_name,
    char *name
    ) {
    update_profile_request_t *update_profile_request_local_var = malloc(sizeof(update_profile_request_t));
    if (!update_profile_request_local_var) {
        return NULL;
    }
    memset(update_profile_request_local_var, 0, sizeof(update_profile_request_t));
    update_profile_request_local_var->_library_owned = 1;
    update_profile_request_local_var->avatar_url = avatar_url;
    update_profile_request_local_var->first_name = first_name;
    update_profile_request_local_var->last_name = last_name;
    update_profile_request_local_var->name = name;
    return update_profile_request_local_var;
}

__attribute__((deprecated)) update_profile_request_t *update_profile_request_create(
    char *avatar_url,
    char *first_name,
    char *last_name,
    char *name
    ) {
    update_profile_request_t *result = update_profile_request_create_internal (
        avatar_url,
        first_name,
        last_name,
        name
        );
    if (!result) {
    }
    return result;
}

void update_profile_request_free(update_profile_request_t *update_profile_request) {
    if(NULL == update_profile_request){
        return ;
    }
    if(update_profile_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_profile_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update_profile_request->avatar_url) {
        free(update_profile_request->avatar_url);
        update_profile_request->avatar_url = NULL;
    }
    if (update_profile_request->first_name) {
        free(update_profile_request->first_name);
        update_profile_request->first_name = NULL;
    }
    if (update_profile_request->last_name) {
        free(update_profile_request->last_name);
        update_profile_request->last_name = NULL;
    }
    if (update_profile_request->name) {
        free(update_profile_request->name);
        update_profile_request->name = NULL;
    }
    free(update_profile_request);
}

cJSON *update_profile_request_convertToJSON(update_profile_request_t *update_profile_request) {
    cJSON *item = cJSON_CreateObject();

    // update_profile_request->avatar_url
    if(update_profile_request->avatar_url) {
    if(cJSON_AddStringToObject(item, "avatar_url", update_profile_request->avatar_url) == NULL) {
    goto fail; //String
    }
    }


    // update_profile_request->first_name
    if(update_profile_request->first_name) {
    if(cJSON_AddStringToObject(item, "first_name", update_profile_request->first_name) == NULL) {
    goto fail; //String
    }
    }


    // update_profile_request->last_name
    if(update_profile_request->last_name) {
    if(cJSON_AddStringToObject(item, "last_name", update_profile_request->last_name) == NULL) {
    goto fail; //String
    }
    }


    // update_profile_request->name
    if(update_profile_request->name) {
    if(cJSON_AddStringToObject(item, "name", update_profile_request->name) == NULL) {
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

update_profile_request_t *update_profile_request_parseFromJSON(cJSON *update_profile_requestJSON){

    update_profile_request_t *update_profile_request_local_var = NULL;

    char *avatar_url_local_str = NULL;

    char *first_name_local_str = NULL;

    char *last_name_local_str = NULL;

    char *name_local_str = NULL;

    // update_profile_request->avatar_url
    cJSON *avatar_url = cJSON_GetObjectItemCaseSensitive(update_profile_requestJSON, "avatar_url");
    if (cJSON_IsNull(avatar_url)) {
        avatar_url = NULL;
    }
    if (avatar_url) { 
    if(!cJSON_IsString(avatar_url) && !cJSON_IsNull(avatar_url))
    {
    goto end; //String
    }
    }

    // update_profile_request->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(update_profile_requestJSON, "first_name");
    if (cJSON_IsNull(first_name)) {
        first_name = NULL;
    }
    if (first_name) { 
    if(!cJSON_IsString(first_name) && !cJSON_IsNull(first_name))
    {
    goto end; //String
    }
    }

    // update_profile_request->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(update_profile_requestJSON, "last_name");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (last_name) { 
    if(!cJSON_IsString(last_name) && !cJSON_IsNull(last_name))
    {
    goto end; //String
    }
    }

    // update_profile_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(update_profile_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }


    if (avatar_url && !cJSON_IsNull(avatar_url)) avatar_url_local_str = strdup(avatar_url->valuestring);
    if (first_name && !cJSON_IsNull(first_name)) first_name_local_str = strdup(first_name->valuestring);
    if (last_name && !cJSON_IsNull(last_name)) last_name_local_str = strdup(last_name->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    update_profile_request_local_var = update_profile_request_create_internal (
        avatar_url_local_str,
        first_name_local_str,
        last_name_local_str,
        name_local_str
        );

    if (!update_profile_request_local_var) {
        goto end;
    }

    return update_profile_request_local_var;
end:
    if (avatar_url_local_str) {
        free(avatar_url_local_str);
        avatar_url_local_str = NULL;
    }
    if (first_name_local_str) {
        free(first_name_local_str);
        first_name_local_str = NULL;
    }
    if (last_name_local_str) {
        free(last_name_local_str);
        last_name_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    return NULL;

}
