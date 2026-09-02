#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "model.h"



static model_t *model_create_internal(
    list_t *backup_codes,
    char *created_at,
    char *deleted_at,
    char *email,
    int *email_verified,
    char *id,
    int *is_active,
    int *is_totp_enabled,
    char *last_login,
    char *name,
    char *oauth_id,
    char *oauth_provider,
    char *password_changed_at,
    char *password_hash,
    char *picture,
    char *privacy_accepted_at,
    char *totp_secret,
    char *updated_at
    ) {
    model_t *model_local_var = malloc(sizeof(model_t));
    if (!model_local_var) {
        return NULL;
    }
    memset(model_local_var, 0, sizeof(model_t));
    model_local_var->_library_owned = 1;
    model_local_var->backup_codes = backup_codes;
    model_local_var->created_at = created_at;
    model_local_var->deleted_at = deleted_at;
    model_local_var->email = email;
    model_local_var->email_verified = email_verified;
    model_local_var->id = id;
    model_local_var->is_active = is_active;
    model_local_var->is_totp_enabled = is_totp_enabled;
    model_local_var->last_login = last_login;
    model_local_var->name = name;
    model_local_var->oauth_id = oauth_id;
    model_local_var->oauth_provider = oauth_provider;
    model_local_var->password_changed_at = password_changed_at;
    model_local_var->password_hash = password_hash;
    model_local_var->picture = picture;
    model_local_var->privacy_accepted_at = privacy_accepted_at;
    model_local_var->totp_secret = totp_secret;
    model_local_var->updated_at = updated_at;
    return model_local_var;
}

__attribute__((deprecated)) model_t *model_create(
    list_t *backup_codes,
    char *created_at,
    char *deleted_at,
    char *email,
    int *email_verified,
    char *id,
    int *is_active,
    int *is_totp_enabled,
    char *last_login,
    char *name,
    char *oauth_id,
    char *oauth_provider,
    char *password_changed_at,
    char *password_hash,
    char *picture,
    char *privacy_accepted_at,
    char *totp_secret,
    char *updated_at
    ) {
    int *email_verified_copy = NULL;
    if (email_verified) {
        email_verified_copy = malloc(sizeof(int));
        if (email_verified_copy) *email_verified_copy = *email_verified;
    }
    int *is_active_copy = NULL;
    if (is_active) {
        is_active_copy = malloc(sizeof(int));
        if (is_active_copy) *is_active_copy = *is_active;
    }
    int *is_totp_enabled_copy = NULL;
    if (is_totp_enabled) {
        is_totp_enabled_copy = malloc(sizeof(int));
        if (is_totp_enabled_copy) *is_totp_enabled_copy = *is_totp_enabled;
    }
    model_t *result = model_create_internal (
        backup_codes,
        created_at,
        deleted_at,
        email,
        email_verified_copy,
        id,
        is_active_copy,
        is_totp_enabled_copy,
        last_login,
        name,
        oauth_id,
        oauth_provider,
        password_changed_at,
        password_hash,
        picture,
        privacy_accepted_at,
        totp_secret,
        updated_at
        );
    if (!result) {
        free(email_verified_copy);
        free(is_active_copy);
        free(is_totp_enabled_copy);
    }
    return result;
}

void model_free(model_t *model) {
    if(NULL == model){
        return ;
    }
    if(model->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "model_free");
        return ;
    }
    listEntry_t *listEntry;
    if (model->backup_codes) {
        list_ForEach(listEntry, model->backup_codes) {
            free(listEntry->data);
        }
        list_freeList(model->backup_codes);
        model->backup_codes = NULL;
    }
    if (model->created_at) {
        free(model->created_at);
        model->created_at = NULL;
    }
    if (model->deleted_at) {
        free(model->deleted_at);
        model->deleted_at = NULL;
    }
    if (model->email) {
        free(model->email);
        model->email = NULL;
    }
    if (model->email_verified) {
        free(model->email_verified);
        model->email_verified = NULL;
    }
    if (model->id) {
        free(model->id);
        model->id = NULL;
    }
    if (model->is_active) {
        free(model->is_active);
        model->is_active = NULL;
    }
    if (model->is_totp_enabled) {
        free(model->is_totp_enabled);
        model->is_totp_enabled = NULL;
    }
    if (model->last_login) {
        free(model->last_login);
        model->last_login = NULL;
    }
    if (model->name) {
        free(model->name);
        model->name = NULL;
    }
    if (model->oauth_id) {
        free(model->oauth_id);
        model->oauth_id = NULL;
    }
    if (model->oauth_provider) {
        free(model->oauth_provider);
        model->oauth_provider = NULL;
    }
    if (model->password_changed_at) {
        free(model->password_changed_at);
        model->password_changed_at = NULL;
    }
    if (model->password_hash) {
        free(model->password_hash);
        model->password_hash = NULL;
    }
    if (model->picture) {
        free(model->picture);
        model->picture = NULL;
    }
    if (model->privacy_accepted_at) {
        free(model->privacy_accepted_at);
        model->privacy_accepted_at = NULL;
    }
    if (model->totp_secret) {
        free(model->totp_secret);
        model->totp_secret = NULL;
    }
    if (model->updated_at) {
        free(model->updated_at);
        model->updated_at = NULL;
    }
    free(model);
}

cJSON *model_convertToJSON(model_t *model) {
    cJSON *item = cJSON_CreateObject();

    // model->backup_codes
    if (!model->backup_codes) {
        goto fail;
    }
    cJSON *backup_codes = cJSON_AddArrayToObject(item, "backup_codes");
    if(backup_codes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *backup_codesListEntry;
    list_ForEach(backup_codesListEntry, model->backup_codes) {
    if(cJSON_AddStringToObject(backup_codes, "", backup_codesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // model->created_at
    if (!model->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "created_at", model->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // model->deleted_at
    if(model->deleted_at) {
    if(cJSON_AddStringToObject(item, "deleted_at", model->deleted_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // model->email
    if (!model->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", model->email) == NULL) {
    goto fail; //String
    }


    // model->email_verified
    if (!model->email_verified) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "email_verified", *model->email_verified) == NULL) {
    goto fail; //Bool
    }


    // model->id
    if (!model->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", model->id) == NULL) {
    goto fail; //String
    }


    // model->is_active
    if (!model->is_active) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_active", *model->is_active) == NULL) {
    goto fail; //Bool
    }


    // model->is_totp_enabled
    if (!model->is_totp_enabled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_totp_enabled", *model->is_totp_enabled) == NULL) {
    goto fail; //Bool
    }


    // model->last_login
    if(model->last_login) {
    if(cJSON_AddStringToObject(item, "last_login", model->last_login) == NULL) {
    goto fail; //Date-Time
    }
    }


    // model->name
    if (!model->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", model->name) == NULL) {
    goto fail; //String
    }


    // model->oauth_id
    if(model->oauth_id) {
    if(cJSON_AddStringToObject(item, "oauth_id", model->oauth_id) == NULL) {
    goto fail; //String
    }
    }


    // model->oauth_provider
    if(model->oauth_provider) {
    if(cJSON_AddStringToObject(item, "oauth_provider", model->oauth_provider) == NULL) {
    goto fail; //String
    }
    }


    // model->password_changed_at
    if(model->password_changed_at) {
    if(cJSON_AddStringToObject(item, "password_changed_at", model->password_changed_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // model->password_hash
    if (!model->password_hash) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "password_hash", model->password_hash) == NULL) {
    goto fail; //String
    }


    // model->picture
    if(model->picture) {
    if(cJSON_AddStringToObject(item, "picture", model->picture) == NULL) {
    goto fail; //String
    }
    }


    // model->privacy_accepted_at
    if(model->privacy_accepted_at) {
    if(cJSON_AddStringToObject(item, "privacy_accepted_at", model->privacy_accepted_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // model->totp_secret
    if(model->totp_secret) {
    if(cJSON_AddStringToObject(item, "totp_secret", model->totp_secret) == NULL) {
    goto fail; //String
    }
    }


    // model->updated_at
    if (!model->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updated_at", model->updated_at) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

model_t *model_parseFromJSON(cJSON *modelJSON){

    model_t *model_local_var = NULL;

    // define the local list for model->backup_codes
    list_t *backup_codesList = NULL;

    char *created_at_local_str = NULL;

    char *deleted_at_local_str = NULL;

    char *email_local_str = NULL;

    // define the local variable for model->email_verified
    int *email_verified_local_var = NULL;

    char *id_local_str = NULL;

    // define the local variable for model->is_active
    int *is_active_local_var = NULL;

    // define the local variable for model->is_totp_enabled
    int *is_totp_enabled_local_var = NULL;

    char *last_login_local_str = NULL;

    char *name_local_str = NULL;

    char *oauth_id_local_str = NULL;

    char *oauth_provider_local_str = NULL;

    char *password_changed_at_local_str = NULL;

    char *password_hash_local_str = NULL;

    char *picture_local_str = NULL;

    char *privacy_accepted_at_local_str = NULL;

    char *totp_secret_local_str = NULL;

    char *updated_at_local_str = NULL;

    // model->backup_codes
    cJSON *backup_codes = cJSON_GetObjectItemCaseSensitive(modelJSON, "backup_codes");
    if (cJSON_IsNull(backup_codes)) {
        backup_codes = NULL;
    }
    if (!backup_codes) {
        goto end;
    }

    
    cJSON *backup_codes_local = NULL;
    if(!cJSON_IsArray(backup_codes)) {
        goto end;//primitive container
    }
    backup_codesList = list_createList();

    cJSON_ArrayForEach(backup_codes_local, backup_codes)
    {
        if(!cJSON_IsString(backup_codes_local))
        {
            goto end;
        }
        list_addElement(backup_codesList , strdup(backup_codes_local->valuestring));
    }

    // model->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(modelJSON, "created_at");
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

    // model->deleted_at
    cJSON *deleted_at = cJSON_GetObjectItemCaseSensitive(modelJSON, "deleted_at");
    if (cJSON_IsNull(deleted_at)) {
        deleted_at = NULL;
    }
    if (deleted_at) { 
    if(!cJSON_IsString(deleted_at) && !cJSON_IsNull(deleted_at))
    {
    goto end; //DateTime
    }
    }

    // model->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(modelJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (!email) {
        goto end;
    }

    
    if(!cJSON_IsString(email))
    {
    goto end; //String
    }

    // model->email_verified
    cJSON *email_verified = cJSON_GetObjectItemCaseSensitive(modelJSON, "email_verified");
    if (cJSON_IsNull(email_verified)) {
        email_verified = NULL;
    }
    if (!email_verified) {
        goto end;
    }

    
    if(!cJSON_IsBool(email_verified))
    {
    goto end; //Bool
    }
    email_verified_local_var = malloc(sizeof(int));
    if(!email_verified_local_var)
    {
        goto end;
    }
    *email_verified_local_var = email_verified->valueint;

    // model->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(modelJSON, "id");
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

    // model->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(modelJSON, "is_active");
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

    // model->is_totp_enabled
    cJSON *is_totp_enabled = cJSON_GetObjectItemCaseSensitive(modelJSON, "is_totp_enabled");
    if (cJSON_IsNull(is_totp_enabled)) {
        is_totp_enabled = NULL;
    }
    if (!is_totp_enabled) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_totp_enabled))
    {
    goto end; //Bool
    }
    is_totp_enabled_local_var = malloc(sizeof(int));
    if(!is_totp_enabled_local_var)
    {
        goto end;
    }
    *is_totp_enabled_local_var = is_totp_enabled->valueint;

    // model->last_login
    cJSON *last_login = cJSON_GetObjectItemCaseSensitive(modelJSON, "last_login");
    if (cJSON_IsNull(last_login)) {
        last_login = NULL;
    }
    if (last_login) { 
    if(!cJSON_IsString(last_login) && !cJSON_IsNull(last_login))
    {
    goto end; //DateTime
    }
    }

    // model->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(modelJSON, "name");
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

    // model->oauth_id
    cJSON *oauth_id = cJSON_GetObjectItemCaseSensitive(modelJSON, "oauth_id");
    if (cJSON_IsNull(oauth_id)) {
        oauth_id = NULL;
    }
    if (oauth_id) { 
    if(!cJSON_IsString(oauth_id) && !cJSON_IsNull(oauth_id))
    {
    goto end; //String
    }
    }

    // model->oauth_provider
    cJSON *oauth_provider = cJSON_GetObjectItemCaseSensitive(modelJSON, "oauth_provider");
    if (cJSON_IsNull(oauth_provider)) {
        oauth_provider = NULL;
    }
    if (oauth_provider) { 
    if(!cJSON_IsString(oauth_provider) && !cJSON_IsNull(oauth_provider))
    {
    goto end; //String
    }
    }

    // model->password_changed_at
    cJSON *password_changed_at = cJSON_GetObjectItemCaseSensitive(modelJSON, "password_changed_at");
    if (cJSON_IsNull(password_changed_at)) {
        password_changed_at = NULL;
    }
    if (password_changed_at) { 
    if(!cJSON_IsString(password_changed_at) && !cJSON_IsNull(password_changed_at))
    {
    goto end; //DateTime
    }
    }

    // model->password_hash
    cJSON *password_hash = cJSON_GetObjectItemCaseSensitive(modelJSON, "password_hash");
    if (cJSON_IsNull(password_hash)) {
        password_hash = NULL;
    }
    if (!password_hash) {
        goto end;
    }

    
    if(!cJSON_IsString(password_hash))
    {
    goto end; //String
    }

    // model->picture
    cJSON *picture = cJSON_GetObjectItemCaseSensitive(modelJSON, "picture");
    if (cJSON_IsNull(picture)) {
        picture = NULL;
    }
    if (picture) { 
    if(!cJSON_IsString(picture) && !cJSON_IsNull(picture))
    {
    goto end; //String
    }
    }

    // model->privacy_accepted_at
    cJSON *privacy_accepted_at = cJSON_GetObjectItemCaseSensitive(modelJSON, "privacy_accepted_at");
    if (cJSON_IsNull(privacy_accepted_at)) {
        privacy_accepted_at = NULL;
    }
    if (privacy_accepted_at) { 
    if(!cJSON_IsString(privacy_accepted_at) && !cJSON_IsNull(privacy_accepted_at))
    {
    goto end; //DateTime
    }
    }

    // model->totp_secret
    cJSON *totp_secret = cJSON_GetObjectItemCaseSensitive(modelJSON, "totp_secret");
    if (cJSON_IsNull(totp_secret)) {
        totp_secret = NULL;
    }
    if (totp_secret) { 
    if(!cJSON_IsString(totp_secret) && !cJSON_IsNull(totp_secret))
    {
    goto end; //String
    }
    }

    // model->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(modelJSON, "updated_at");
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
    if (deleted_at && !cJSON_IsNull(deleted_at)) deleted_at_local_str = strdup(deleted_at->valuestring);
    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (last_login && !cJSON_IsNull(last_login)) last_login_local_str = strdup(last_login->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (oauth_id && !cJSON_IsNull(oauth_id)) oauth_id_local_str = strdup(oauth_id->valuestring);
    if (oauth_provider && !cJSON_IsNull(oauth_provider)) oauth_provider_local_str = strdup(oauth_provider->valuestring);
    if (password_changed_at && !cJSON_IsNull(password_changed_at)) password_changed_at_local_str = strdup(password_changed_at->valuestring);
    if (password_hash && !cJSON_IsNull(password_hash)) password_hash_local_str = strdup(password_hash->valuestring);
    if (picture && !cJSON_IsNull(picture)) picture_local_str = strdup(picture->valuestring);
    if (privacy_accepted_at && !cJSON_IsNull(privacy_accepted_at)) privacy_accepted_at_local_str = strdup(privacy_accepted_at->valuestring);
    if (totp_secret && !cJSON_IsNull(totp_secret)) totp_secret_local_str = strdup(totp_secret->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);

    model_local_var = model_create_internal (
        backup_codesList,
        created_at_local_str,
        deleted_at_local_str,
        email_local_str,
        email_verified_local_var,
        id_local_str,
        is_active_local_var,
        is_totp_enabled_local_var,
        last_login_local_str,
        name_local_str,
        oauth_id_local_str,
        oauth_provider_local_str,
        password_changed_at_local_str,
        password_hash_local_str,
        picture_local_str,
        privacy_accepted_at_local_str,
        totp_secret_local_str,
        updated_at_local_str
        );

    if (!model_local_var) {
        goto end;
    }

    return model_local_var;
end:
    if (backup_codesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, backup_codesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(backup_codesList);
        backup_codesList = NULL;
    }
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (deleted_at_local_str) {
        free(deleted_at_local_str);
        deleted_at_local_str = NULL;
    }
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    if (email_verified_local_var) {
        free(email_verified_local_var);
        email_verified_local_var = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (is_active_local_var) {
        free(is_active_local_var);
        is_active_local_var = NULL;
    }
    if (is_totp_enabled_local_var) {
        free(is_totp_enabled_local_var);
        is_totp_enabled_local_var = NULL;
    }
    if (last_login_local_str) {
        free(last_login_local_str);
        last_login_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (oauth_id_local_str) {
        free(oauth_id_local_str);
        oauth_id_local_str = NULL;
    }
    if (oauth_provider_local_str) {
        free(oauth_provider_local_str);
        oauth_provider_local_str = NULL;
    }
    if (password_changed_at_local_str) {
        free(password_changed_at_local_str);
        password_changed_at_local_str = NULL;
    }
    if (password_hash_local_str) {
        free(password_hash_local_str);
        password_hash_local_str = NULL;
    }
    if (picture_local_str) {
        free(picture_local_str);
        picture_local_str = NULL;
    }
    if (privacy_accepted_at_local_str) {
        free(privacy_accepted_at_local_str);
        privacy_accepted_at_local_str = NULL;
    }
    if (totp_secret_local_str) {
        free(totp_secret_local_str);
        totp_secret_local_str = NULL;
    }
    if (updated_at_local_str) {
        free(updated_at_local_str);
        updated_at_local_str = NULL;
    }
    return NULL;

}
