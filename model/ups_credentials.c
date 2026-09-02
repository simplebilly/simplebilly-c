#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ups_credentials.h"



static ups_credentials_t *ups_credentials_create_internal(
    char *client_id,
    char *client_secret,
    char *shipper_number
    ) {
    ups_credentials_t *ups_credentials_local_var = malloc(sizeof(ups_credentials_t));
    if (!ups_credentials_local_var) {
        return NULL;
    }
    memset(ups_credentials_local_var, 0, sizeof(ups_credentials_t));
    ups_credentials_local_var->_library_owned = 1;
    ups_credentials_local_var->client_id = client_id;
    ups_credentials_local_var->client_secret = client_secret;
    ups_credentials_local_var->shipper_number = shipper_number;
    return ups_credentials_local_var;
}

__attribute__((deprecated)) ups_credentials_t *ups_credentials_create(
    char *client_id,
    char *client_secret,
    char *shipper_number
    ) {
    ups_credentials_t *result = ups_credentials_create_internal (
        client_id,
        client_secret,
        shipper_number
        );
    if (!result) {
    }
    return result;
}

void ups_credentials_free(ups_credentials_t *ups_credentials) {
    if(NULL == ups_credentials){
        return ;
    }
    if(ups_credentials->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ups_credentials_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ups_credentials->client_id) {
        free(ups_credentials->client_id);
        ups_credentials->client_id = NULL;
    }
    if (ups_credentials->client_secret) {
        free(ups_credentials->client_secret);
        ups_credentials->client_secret = NULL;
    }
    if (ups_credentials->shipper_number) {
        free(ups_credentials->shipper_number);
        ups_credentials->shipper_number = NULL;
    }
    free(ups_credentials);
}

cJSON *ups_credentials_convertToJSON(ups_credentials_t *ups_credentials) {
    cJSON *item = cJSON_CreateObject();

    // ups_credentials->client_id
    if (!ups_credentials->client_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "client_id", ups_credentials->client_id) == NULL) {
    goto fail; //String
    }


    // ups_credentials->client_secret
    if (!ups_credentials->client_secret) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "client_secret", ups_credentials->client_secret) == NULL) {
    goto fail; //String
    }


    // ups_credentials->shipper_number
    if(ups_credentials->shipper_number) {
    if(cJSON_AddStringToObject(item, "shipper_number", ups_credentials->shipper_number) == NULL) {
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

ups_credentials_t *ups_credentials_parseFromJSON(cJSON *ups_credentialsJSON){

    ups_credentials_t *ups_credentials_local_var = NULL;

    char *client_id_local_str = NULL;

    char *client_secret_local_str = NULL;

    char *shipper_number_local_str = NULL;

    // ups_credentials->client_id
    cJSON *client_id = cJSON_GetObjectItemCaseSensitive(ups_credentialsJSON, "client_id");
    if (cJSON_IsNull(client_id)) {
        client_id = NULL;
    }
    if (!client_id) {
        goto end;
    }

    
    if(!cJSON_IsString(client_id))
    {
    goto end; //String
    }

    // ups_credentials->client_secret
    cJSON *client_secret = cJSON_GetObjectItemCaseSensitive(ups_credentialsJSON, "client_secret");
    if (cJSON_IsNull(client_secret)) {
        client_secret = NULL;
    }
    if (!client_secret) {
        goto end;
    }

    
    if(!cJSON_IsString(client_secret))
    {
    goto end; //String
    }

    // ups_credentials->shipper_number
    cJSON *shipper_number = cJSON_GetObjectItemCaseSensitive(ups_credentialsJSON, "shipper_number");
    if (cJSON_IsNull(shipper_number)) {
        shipper_number = NULL;
    }
    if (shipper_number) { 
    if(!cJSON_IsString(shipper_number) && !cJSON_IsNull(shipper_number))
    {
    goto end; //String
    }
    }


    if (client_id && !cJSON_IsNull(client_id)) client_id_local_str = strdup(client_id->valuestring);
    if (client_secret && !cJSON_IsNull(client_secret)) client_secret_local_str = strdup(client_secret->valuestring);
    if (shipper_number && !cJSON_IsNull(shipper_number)) shipper_number_local_str = strdup(shipper_number->valuestring);

    ups_credentials_local_var = ups_credentials_create_internal (
        client_id_local_str,
        client_secret_local_str,
        shipper_number_local_str
        );

    if (!ups_credentials_local_var) {
        goto end;
    }

    return ups_credentials_local_var;
end:
    if (client_id_local_str) {
        free(client_id_local_str);
        client_id_local_str = NULL;
    }
    if (client_secret_local_str) {
        free(client_secret_local_str);
        client_secret_local_str = NULL;
    }
    if (shipper_number_local_str) {
        free(shipper_number_local_str);
        shipper_number_local_str = NULL;
    }
    return NULL;

}
