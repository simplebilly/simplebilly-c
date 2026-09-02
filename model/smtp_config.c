#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "smtp_config.h"



static smtp_config_t *smtp_config_create_internal(
    simplebilly_api_smtp_encryption__e encryption,
    char *from_address,
    char *from_name,
    char *host,
    char *password,
    int *port,
    long *timeout_seconds,
    char *username
    ) {
    smtp_config_t *smtp_config_local_var = malloc(sizeof(smtp_config_t));
    if (!smtp_config_local_var) {
        return NULL;
    }
    memset(smtp_config_local_var, 0, sizeof(smtp_config_t));
    smtp_config_local_var->_library_owned = 1;
    smtp_config_local_var->encryption = encryption;
    smtp_config_local_var->from_address = from_address;
    smtp_config_local_var->from_name = from_name;
    smtp_config_local_var->host = host;
    smtp_config_local_var->password = password;
    smtp_config_local_var->port = port;
    smtp_config_local_var->timeout_seconds = timeout_seconds;
    smtp_config_local_var->username = username;
    return smtp_config_local_var;
}

__attribute__((deprecated)) smtp_config_t *smtp_config_create(
    simplebilly_api_smtp_encryption__e encryption,
    char *from_address,
    char *from_name,
    char *host,
    char *password,
    int *port,
    long *timeout_seconds,
    char *username
    ) {
    int *port_copy = NULL;
    if (port) {
        port_copy = malloc(sizeof(int));
        if (port_copy) *port_copy = *port;
    }
    long *timeout_seconds_copy = NULL;
    if (timeout_seconds) {
        timeout_seconds_copy = malloc(sizeof(long));
        if (timeout_seconds_copy) *timeout_seconds_copy = *timeout_seconds;
    }
    smtp_config_t *result = smtp_config_create_internal (
        encryption,
        from_address,
        from_name,
        host,
        password,
        port_copy,
        timeout_seconds_copy,
        username
        );
    if (!result) {
        free(port_copy);
        free(timeout_seconds_copy);
    }
    return result;
}

void smtp_config_free(smtp_config_t *smtp_config) {
    if(NULL == smtp_config){
        return ;
    }
    if(smtp_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "smtp_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (smtp_config->from_address) {
        free(smtp_config->from_address);
        smtp_config->from_address = NULL;
    }
    if (smtp_config->from_name) {
        free(smtp_config->from_name);
        smtp_config->from_name = NULL;
    }
    if (smtp_config->host) {
        free(smtp_config->host);
        smtp_config->host = NULL;
    }
    if (smtp_config->password) {
        free(smtp_config->password);
        smtp_config->password = NULL;
    }
    if (smtp_config->port) {
        free(smtp_config->port);
        smtp_config->port = NULL;
    }
    if (smtp_config->timeout_seconds) {
        free(smtp_config->timeout_seconds);
        smtp_config->timeout_seconds = NULL;
    }
    if (smtp_config->username) {
        free(smtp_config->username);
        smtp_config->username = NULL;
    }
    free(smtp_config);
}

cJSON *smtp_config_convertToJSON(smtp_config_t *smtp_config) {
    cJSON *item = cJSON_CreateObject();

    // smtp_config->encryption
    if (simplebilly_api_smtp_encryption__NULL == smtp_config->encryption) {
        goto fail;
    }
    cJSON *encryption_local_JSON = smtp_encryption_convertToJSON(smtp_config->encryption);
    if(encryption_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "encryption", encryption_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // smtp_config->from_address
    if (!smtp_config->from_address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "from_address", smtp_config->from_address) == NULL) {
    goto fail; //String
    }


    // smtp_config->from_name
    if(smtp_config->from_name) {
    if(cJSON_AddStringToObject(item, "from_name", smtp_config->from_name) == NULL) {
    goto fail; //String
    }
    }


    // smtp_config->host
    if (!smtp_config->host) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "host", smtp_config->host) == NULL) {
    goto fail; //String
    }


    // smtp_config->password
    if (!smtp_config->password) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "password", smtp_config->password) == NULL) {
    goto fail; //String
    }


    // smtp_config->port
    if (!smtp_config->port) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "port", *smtp_config->port) == NULL) {
    goto fail; //Numeric
    }


    // smtp_config->timeout_seconds
    if(smtp_config->timeout_seconds) {
    if(cJSON_AddNumberToObject(item, "timeout_seconds", *smtp_config->timeout_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // smtp_config->username
    if (!smtp_config->username) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "username", smtp_config->username) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

smtp_config_t *smtp_config_parseFromJSON(cJSON *smtp_configJSON){

    smtp_config_t *smtp_config_local_var = NULL;

    // define the local variable for smtp_config->encryption
    simplebilly_api_smtp_encryption__e encryption_local_nonprim = 0;

    char *from_address_local_str = NULL;

    char *from_name_local_str = NULL;

    char *host_local_str = NULL;

    char *password_local_str = NULL;

    // define the local variable for smtp_config->port
    int *port_local_var = NULL;

    // define the local variable for smtp_config->timeout_seconds
    long *timeout_seconds_local_var = NULL;

    char *username_local_str = NULL;

    // smtp_config->encryption
    cJSON *encryption = cJSON_GetObjectItemCaseSensitive(smtp_configJSON, "encryption");
    if (cJSON_IsNull(encryption)) {
        encryption = NULL;
    }
    if (!encryption) {
        goto end;
    }

    
    encryption_local_nonprim = smtp_encryption_parseFromJSON(encryption); //custom

    // smtp_config->from_address
    cJSON *from_address = cJSON_GetObjectItemCaseSensitive(smtp_configJSON, "from_address");
    if (cJSON_IsNull(from_address)) {
        from_address = NULL;
    }
    if (!from_address) {
        goto end;
    }

    
    if(!cJSON_IsString(from_address))
    {
    goto end; //String
    }

    // smtp_config->from_name
    cJSON *from_name = cJSON_GetObjectItemCaseSensitive(smtp_configJSON, "from_name");
    if (cJSON_IsNull(from_name)) {
        from_name = NULL;
    }
    if (from_name) { 
    if(!cJSON_IsString(from_name) && !cJSON_IsNull(from_name))
    {
    goto end; //String
    }
    }

    // smtp_config->host
    cJSON *host = cJSON_GetObjectItemCaseSensitive(smtp_configJSON, "host");
    if (cJSON_IsNull(host)) {
        host = NULL;
    }
    if (!host) {
        goto end;
    }

    
    if(!cJSON_IsString(host))
    {
    goto end; //String
    }

    // smtp_config->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(smtp_configJSON, "password");
    if (cJSON_IsNull(password)) {
        password = NULL;
    }
    if (!password) {
        goto end;
    }

    
    if(!cJSON_IsString(password))
    {
    goto end; //String
    }

    // smtp_config->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(smtp_configJSON, "port");
    if (cJSON_IsNull(port)) {
        port = NULL;
    }
    if (!port) {
        goto end;
    }

    
    if(!cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }
    port_local_var = malloc(sizeof(int));
    if(!port_local_var)
    {
        goto end;
    }
    *port_local_var = port->valuedouble;

    // smtp_config->timeout_seconds
    cJSON *timeout_seconds = cJSON_GetObjectItemCaseSensitive(smtp_configJSON, "timeout_seconds");
    if (cJSON_IsNull(timeout_seconds)) {
        timeout_seconds = NULL;
    }
    if (timeout_seconds) { 
    if(!cJSON_IsNumber(timeout_seconds))
    {
    goto end; //Numeric
    }
    timeout_seconds_local_var = malloc(sizeof(long));
    if(!timeout_seconds_local_var)
    {
        goto end;
    }
    *timeout_seconds_local_var = timeout_seconds->valuedouble;
    }

    // smtp_config->username
    cJSON *username = cJSON_GetObjectItemCaseSensitive(smtp_configJSON, "username");
    if (cJSON_IsNull(username)) {
        username = NULL;
    }
    if (!username) {
        goto end;
    }

    
    if(!cJSON_IsString(username))
    {
    goto end; //String
    }


    if (from_address && !cJSON_IsNull(from_address)) from_address_local_str = strdup(from_address->valuestring);
    if (from_name && !cJSON_IsNull(from_name)) from_name_local_str = strdup(from_name->valuestring);
    if (host && !cJSON_IsNull(host)) host_local_str = strdup(host->valuestring);
    if (password && !cJSON_IsNull(password)) password_local_str = strdup(password->valuestring);
    if (username && !cJSON_IsNull(username)) username_local_str = strdup(username->valuestring);

    smtp_config_local_var = smtp_config_create_internal (
        encryption_local_nonprim,
        from_address_local_str,
        from_name_local_str,
        host_local_str,
        password_local_str,
        port_local_var,
        timeout_seconds_local_var,
        username_local_str
        );

    if (!smtp_config_local_var) {
        goto end;
    }

    return smtp_config_local_var;
end:
    if (encryption_local_nonprim) {
        encryption_local_nonprim = 0;
    }
    if (from_address_local_str) {
        free(from_address_local_str);
        from_address_local_str = NULL;
    }
    if (from_name_local_str) {
        free(from_name_local_str);
        from_name_local_str = NULL;
    }
    if (host_local_str) {
        free(host_local_str);
        host_local_str = NULL;
    }
    if (password_local_str) {
        free(password_local_str);
        password_local_str = NULL;
    }
    if (port_local_var) {
        free(port_local_var);
        port_local_var = NULL;
    }
    if (timeout_seconds_local_var) {
        free(timeout_seconds_local_var);
        timeout_seconds_local_var = NULL;
    }
    if (username_local_str) {
        free(username_local_str);
        username_local_str = NULL;
    }
    return NULL;

}
