#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "contact_info.h"



static contact_info_t *contact_info_create_internal(
    char *hint,
    char *hint_en,
    char *role,
    char *role_en
    ) {
    contact_info_t *contact_info_local_var = malloc(sizeof(contact_info_t));
    if (!contact_info_local_var) {
        return NULL;
    }
    memset(contact_info_local_var, 0, sizeof(contact_info_t));
    contact_info_local_var->_library_owned = 1;
    contact_info_local_var->hint = hint;
    contact_info_local_var->hint_en = hint_en;
    contact_info_local_var->role = role;
    contact_info_local_var->role_en = role_en;
    return contact_info_local_var;
}

__attribute__((deprecated)) contact_info_t *contact_info_create(
    char *hint,
    char *hint_en,
    char *role,
    char *role_en
    ) {
    contact_info_t *result = contact_info_create_internal (
        hint,
        hint_en,
        role,
        role_en
        );
    if (!result) {
    }
    return result;
}

void contact_info_free(contact_info_t *contact_info) {
    if(NULL == contact_info){
        return ;
    }
    if(contact_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "contact_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (contact_info->hint) {
        free(contact_info->hint);
        contact_info->hint = NULL;
    }
    if (contact_info->hint_en) {
        free(contact_info->hint_en);
        contact_info->hint_en = NULL;
    }
    if (contact_info->role) {
        free(contact_info->role);
        contact_info->role = NULL;
    }
    if (contact_info->role_en) {
        free(contact_info->role_en);
        contact_info->role_en = NULL;
    }
    free(contact_info);
}

cJSON *contact_info_convertToJSON(contact_info_t *contact_info) {
    cJSON *item = cJSON_CreateObject();

    // contact_info->hint
    if (!contact_info->hint) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "hint", contact_info->hint) == NULL) {
    goto fail; //String
    }


    // contact_info->hint_en
    if (!contact_info->hint_en) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "hintEn", contact_info->hint_en) == NULL) {
    goto fail; //String
    }


    // contact_info->role
    if (!contact_info->role) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "role", contact_info->role) == NULL) {
    goto fail; //String
    }


    // contact_info->role_en
    if (!contact_info->role_en) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "roleEn", contact_info->role_en) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

contact_info_t *contact_info_parseFromJSON(cJSON *contact_infoJSON){

    contact_info_t *contact_info_local_var = NULL;

    char *hint_local_str = NULL;

    char *hint_en_local_str = NULL;

    char *role_local_str = NULL;

    char *role_en_local_str = NULL;

    // contact_info->hint
    cJSON *hint = cJSON_GetObjectItemCaseSensitive(contact_infoJSON, "hint");
    if (cJSON_IsNull(hint)) {
        hint = NULL;
    }
    if (!hint) {
        goto end;
    }

    
    if(!cJSON_IsString(hint))
    {
    goto end; //String
    }

    // contact_info->hint_en
    cJSON *hint_en = cJSON_GetObjectItemCaseSensitive(contact_infoJSON, "hintEn");
    if (cJSON_IsNull(hint_en)) {
        hint_en = NULL;
    }
    if (!hint_en) {
        goto end;
    }

    
    if(!cJSON_IsString(hint_en))
    {
    goto end; //String
    }

    // contact_info->role
    cJSON *role = cJSON_GetObjectItemCaseSensitive(contact_infoJSON, "role");
    if (cJSON_IsNull(role)) {
        role = NULL;
    }
    if (!role) {
        goto end;
    }

    
    if(!cJSON_IsString(role))
    {
    goto end; //String
    }

    // contact_info->role_en
    cJSON *role_en = cJSON_GetObjectItemCaseSensitive(contact_infoJSON, "roleEn");
    if (cJSON_IsNull(role_en)) {
        role_en = NULL;
    }
    if (!role_en) {
        goto end;
    }

    
    if(!cJSON_IsString(role_en))
    {
    goto end; //String
    }


    if (hint && !cJSON_IsNull(hint)) hint_local_str = strdup(hint->valuestring);
    if (hint_en && !cJSON_IsNull(hint_en)) hint_en_local_str = strdup(hint_en->valuestring);
    if (role && !cJSON_IsNull(role)) role_local_str = strdup(role->valuestring);
    if (role_en && !cJSON_IsNull(role_en)) role_en_local_str = strdup(role_en->valuestring);

    contact_info_local_var = contact_info_create_internal (
        hint_local_str,
        hint_en_local_str,
        role_local_str,
        role_en_local_str
        );

    if (!contact_info_local_var) {
        goto end;
    }

    return contact_info_local_var;
end:
    if (hint_local_str) {
        free(hint_local_str);
        hint_local_str = NULL;
    }
    if (hint_en_local_str) {
        free(hint_en_local_str);
        hint_en_local_str = NULL;
    }
    if (role_local_str) {
        free(role_local_str);
        role_local_str = NULL;
    }
    if (role_en_local_str) {
        free(role_en_local_str);
        role_en_local_str = NULL;
    }
    return NULL;

}
