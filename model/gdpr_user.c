#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gdpr_user.h"



static gdpr_user_t *gdpr_user_create_internal(
    char *created_at,
    char *email,
    char *id,
    char *name
    ) {
    gdpr_user_t *gdpr_user_local_var = malloc(sizeof(gdpr_user_t));
    if (!gdpr_user_local_var) {
        return NULL;
    }
    memset(gdpr_user_local_var, 0, sizeof(gdpr_user_t));
    gdpr_user_local_var->_library_owned = 1;
    gdpr_user_local_var->created_at = created_at;
    gdpr_user_local_var->email = email;
    gdpr_user_local_var->id = id;
    gdpr_user_local_var->name = name;
    return gdpr_user_local_var;
}

__attribute__((deprecated)) gdpr_user_t *gdpr_user_create(
    char *created_at,
    char *email,
    char *id,
    char *name
    ) {
    gdpr_user_t *result = gdpr_user_create_internal (
        created_at,
        email,
        id,
        name
        );
    if (!result) {
    }
    return result;
}

void gdpr_user_free(gdpr_user_t *gdpr_user) {
    if(NULL == gdpr_user){
        return ;
    }
    if(gdpr_user->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gdpr_user_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gdpr_user->created_at) {
        free(gdpr_user->created_at);
        gdpr_user->created_at = NULL;
    }
    if (gdpr_user->email) {
        free(gdpr_user->email);
        gdpr_user->email = NULL;
    }
    if (gdpr_user->id) {
        free(gdpr_user->id);
        gdpr_user->id = NULL;
    }
    if (gdpr_user->name) {
        free(gdpr_user->name);
        gdpr_user->name = NULL;
    }
    free(gdpr_user);
}

cJSON *gdpr_user_convertToJSON(gdpr_user_t *gdpr_user) {
    cJSON *item = cJSON_CreateObject();

    // gdpr_user->created_at
    if (!gdpr_user->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", gdpr_user->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // gdpr_user->email
    if (!gdpr_user->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", gdpr_user->email) == NULL) {
    goto fail; //String
    }


    // gdpr_user->id
    if (!gdpr_user->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", gdpr_user->id) == NULL) {
    goto fail; //String
    }


    // gdpr_user->name
    if (!gdpr_user->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", gdpr_user->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gdpr_user_t *gdpr_user_parseFromJSON(cJSON *gdpr_userJSON){

    gdpr_user_t *gdpr_user_local_var = NULL;

    char *created_at_local_str = NULL;

    char *email_local_str = NULL;

    char *id_local_str = NULL;

    char *name_local_str = NULL;

    // gdpr_user->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(gdpr_userJSON, "createdAt");
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

    // gdpr_user->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(gdpr_userJSON, "email");
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

    // gdpr_user->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(gdpr_userJSON, "id");
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

    // gdpr_user->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(gdpr_userJSON, "name");
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


    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    gdpr_user_local_var = gdpr_user_create_internal (
        created_at_local_str,
        email_local_str,
        id_local_str,
        name_local_str
        );

    if (!gdpr_user_local_var) {
        goto end;
    }

    return gdpr_user_local_var;
end:
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    return NULL;

}
