#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "totp_setup_response.h"



static totp_setup_response_t *totp_setup_response_create_internal(
    list_t *backup_codes,
    char *qr_code_url,
    char *secret
    ) {
    totp_setup_response_t *totp_setup_response_local_var = malloc(sizeof(totp_setup_response_t));
    if (!totp_setup_response_local_var) {
        return NULL;
    }
    memset(totp_setup_response_local_var, 0, sizeof(totp_setup_response_t));
    totp_setup_response_local_var->_library_owned = 1;
    totp_setup_response_local_var->backup_codes = backup_codes;
    totp_setup_response_local_var->qr_code_url = qr_code_url;
    totp_setup_response_local_var->secret = secret;
    return totp_setup_response_local_var;
}

__attribute__((deprecated)) totp_setup_response_t *totp_setup_response_create(
    list_t *backup_codes,
    char *qr_code_url,
    char *secret
    ) {
    totp_setup_response_t *result = totp_setup_response_create_internal (
        backup_codes,
        qr_code_url,
        secret
        );
    if (!result) {
    }
    return result;
}

void totp_setup_response_free(totp_setup_response_t *totp_setup_response) {
    if(NULL == totp_setup_response){
        return ;
    }
    if(totp_setup_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "totp_setup_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (totp_setup_response->backup_codes) {
        list_ForEach(listEntry, totp_setup_response->backup_codes) {
            free(listEntry->data);
        }
        list_freeList(totp_setup_response->backup_codes);
        totp_setup_response->backup_codes = NULL;
    }
    if (totp_setup_response->qr_code_url) {
        free(totp_setup_response->qr_code_url);
        totp_setup_response->qr_code_url = NULL;
    }
    if (totp_setup_response->secret) {
        free(totp_setup_response->secret);
        totp_setup_response->secret = NULL;
    }
    free(totp_setup_response);
}

cJSON *totp_setup_response_convertToJSON(totp_setup_response_t *totp_setup_response) {
    cJSON *item = cJSON_CreateObject();

    // totp_setup_response->backup_codes
    if (!totp_setup_response->backup_codes) {
        goto fail;
    }
    cJSON *backup_codes = cJSON_AddArrayToObject(item, "backup_codes");
    if(backup_codes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *backup_codesListEntry;
    list_ForEach(backup_codesListEntry, totp_setup_response->backup_codes) {
    if(cJSON_AddStringToObject(backup_codes, "", backup_codesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // totp_setup_response->qr_code_url
    if (!totp_setup_response->qr_code_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "qr_code_url", totp_setup_response->qr_code_url) == NULL) {
    goto fail; //String
    }


    // totp_setup_response->secret
    if (!totp_setup_response->secret) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "secret", totp_setup_response->secret) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

totp_setup_response_t *totp_setup_response_parseFromJSON(cJSON *totp_setup_responseJSON){

    totp_setup_response_t *totp_setup_response_local_var = NULL;

    // define the local list for totp_setup_response->backup_codes
    list_t *backup_codesList = NULL;

    char *qr_code_url_local_str = NULL;

    char *secret_local_str = NULL;

    // totp_setup_response->backup_codes
    cJSON *backup_codes = cJSON_GetObjectItemCaseSensitive(totp_setup_responseJSON, "backup_codes");
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

    // totp_setup_response->qr_code_url
    cJSON *qr_code_url = cJSON_GetObjectItemCaseSensitive(totp_setup_responseJSON, "qr_code_url");
    if (cJSON_IsNull(qr_code_url)) {
        qr_code_url = NULL;
    }
    if (!qr_code_url) {
        goto end;
    }

    
    if(!cJSON_IsString(qr_code_url))
    {
    goto end; //String
    }

    // totp_setup_response->secret
    cJSON *secret = cJSON_GetObjectItemCaseSensitive(totp_setup_responseJSON, "secret");
    if (cJSON_IsNull(secret)) {
        secret = NULL;
    }
    if (!secret) {
        goto end;
    }

    
    if(!cJSON_IsString(secret))
    {
    goto end; //String
    }


    if (qr_code_url && !cJSON_IsNull(qr_code_url)) qr_code_url_local_str = strdup(qr_code_url->valuestring);
    if (secret && !cJSON_IsNull(secret)) secret_local_str = strdup(secret->valuestring);

    totp_setup_response_local_var = totp_setup_response_create_internal (
        backup_codesList,
        qr_code_url_local_str,
        secret_local_str
        );

    if (!totp_setup_response_local_var) {
        goto end;
    }

    return totp_setup_response_local_var;
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
    if (qr_code_url_local_str) {
        free(qr_code_url_local_str);
        qr_code_url_local_str = NULL;
    }
    if (secret_local_str) {
        free(secret_local_str);
        secret_local_str = NULL;
    }
    return NULL;

}
