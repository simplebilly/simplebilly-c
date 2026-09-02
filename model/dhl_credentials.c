#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dhl_credentials.h"



static dhl_credentials_t *dhl_credentials_create_internal(
    char *api_key,
    char *client_id,
    char *client_secret
    ) {
    dhl_credentials_t *dhl_credentials_local_var = malloc(sizeof(dhl_credentials_t));
    if (!dhl_credentials_local_var) {
        return NULL;
    }
    memset(dhl_credentials_local_var, 0, sizeof(dhl_credentials_t));
    dhl_credentials_local_var->_library_owned = 1;
    dhl_credentials_local_var->api_key = api_key;
    dhl_credentials_local_var->client_id = client_id;
    dhl_credentials_local_var->client_secret = client_secret;
    return dhl_credentials_local_var;
}

__attribute__((deprecated)) dhl_credentials_t *dhl_credentials_create(
    char *api_key,
    char *client_id,
    char *client_secret
    ) {
    dhl_credentials_t *result = dhl_credentials_create_internal (
        api_key,
        client_id,
        client_secret
        );
    if (!result) {
    }
    return result;
}

void dhl_credentials_free(dhl_credentials_t *dhl_credentials) {
    if(NULL == dhl_credentials){
        return ;
    }
    if(dhl_credentials->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "dhl_credentials_free");
        return ;
    }
    listEntry_t *listEntry;
    if (dhl_credentials->api_key) {
        free(dhl_credentials->api_key);
        dhl_credentials->api_key = NULL;
    }
    if (dhl_credentials->client_id) {
        free(dhl_credentials->client_id);
        dhl_credentials->client_id = NULL;
    }
    if (dhl_credentials->client_secret) {
        free(dhl_credentials->client_secret);
        dhl_credentials->client_secret = NULL;
    }
    free(dhl_credentials);
}

cJSON *dhl_credentials_convertToJSON(dhl_credentials_t *dhl_credentials) {
    cJSON *item = cJSON_CreateObject();

    // dhl_credentials->api_key
    if (!dhl_credentials->api_key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "api_key", dhl_credentials->api_key) == NULL) {
    goto fail; //String
    }


    // dhl_credentials->client_id
    if(dhl_credentials->client_id) {
    if(cJSON_AddStringToObject(item, "client_id", dhl_credentials->client_id) == NULL) {
    goto fail; //String
    }
    }


    // dhl_credentials->client_secret
    if(dhl_credentials->client_secret) {
    if(cJSON_AddStringToObject(item, "client_secret", dhl_credentials->client_secret) == NULL) {
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

dhl_credentials_t *dhl_credentials_parseFromJSON(cJSON *dhl_credentialsJSON){

    dhl_credentials_t *dhl_credentials_local_var = NULL;

    char *api_key_local_str = NULL;

    char *client_id_local_str = NULL;

    char *client_secret_local_str = NULL;

    // dhl_credentials->api_key
    cJSON *api_key = cJSON_GetObjectItemCaseSensitive(dhl_credentialsJSON, "api_key");
    if (cJSON_IsNull(api_key)) {
        api_key = NULL;
    }
    if (!api_key) {
        goto end;
    }

    
    if(!cJSON_IsString(api_key))
    {
    goto end; //String
    }

    // dhl_credentials->client_id
    cJSON *client_id = cJSON_GetObjectItemCaseSensitive(dhl_credentialsJSON, "client_id");
    if (cJSON_IsNull(client_id)) {
        client_id = NULL;
    }
    if (client_id) { 
    if(!cJSON_IsString(client_id) && !cJSON_IsNull(client_id))
    {
    goto end; //String
    }
    }

    // dhl_credentials->client_secret
    cJSON *client_secret = cJSON_GetObjectItemCaseSensitive(dhl_credentialsJSON, "client_secret");
    if (cJSON_IsNull(client_secret)) {
        client_secret = NULL;
    }
    if (client_secret) { 
    if(!cJSON_IsString(client_secret) && !cJSON_IsNull(client_secret))
    {
    goto end; //String
    }
    }


    if (api_key && !cJSON_IsNull(api_key)) api_key_local_str = strdup(api_key->valuestring);
    if (client_id && !cJSON_IsNull(client_id)) client_id_local_str = strdup(client_id->valuestring);
    if (client_secret && !cJSON_IsNull(client_secret)) client_secret_local_str = strdup(client_secret->valuestring);

    dhl_credentials_local_var = dhl_credentials_create_internal (
        api_key_local_str,
        client_id_local_str,
        client_secret_local_str
        );

    if (!dhl_credentials_local_var) {
        goto end;
    }

    return dhl_credentials_local_var;
end:
    if (api_key_local_str) {
        free(api_key_local_str);
        api_key_local_str = NULL;
    }
    if (client_id_local_str) {
        free(client_id_local_str);
        client_id_local_str = NULL;
    }
    if (client_secret_local_str) {
        free(client_secret_local_str);
        client_secret_local_str = NULL;
    }
    return NULL;

}
