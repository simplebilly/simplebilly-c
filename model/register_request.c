#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "register_request.h"



static register_request_t *register_request_create_internal(
    char *company_name,
    char *email,
    char *first_name,
    char *last_name,
    char *password,
    int *privacy_accepted
    ) {
    register_request_t *register_request_local_var = malloc(sizeof(register_request_t));
    if (!register_request_local_var) {
        return NULL;
    }
    memset(register_request_local_var, 0, sizeof(register_request_t));
    register_request_local_var->_library_owned = 1;
    register_request_local_var->company_name = company_name;
    register_request_local_var->email = email;
    register_request_local_var->first_name = first_name;
    register_request_local_var->last_name = last_name;
    register_request_local_var->password = password;
    register_request_local_var->privacy_accepted = privacy_accepted;
    return register_request_local_var;
}

__attribute__((deprecated)) register_request_t *register_request_create(
    char *company_name,
    char *email,
    char *first_name,
    char *last_name,
    char *password,
    int *privacy_accepted
    ) {
    int *privacy_accepted_copy = NULL;
    if (privacy_accepted) {
        privacy_accepted_copy = malloc(sizeof(int));
        if (privacy_accepted_copy) *privacy_accepted_copy = *privacy_accepted;
    }
    register_request_t *result = register_request_create_internal (
        company_name,
        email,
        first_name,
        last_name,
        password,
        privacy_accepted_copy
        );
    if (!result) {
        free(privacy_accepted_copy);
    }
    return result;
}

void register_request_free(register_request_t *register_request) {
    if(NULL == register_request){
        return ;
    }
    if(register_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "register_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (register_request->company_name) {
        free(register_request->company_name);
        register_request->company_name = NULL;
    }
    if (register_request->email) {
        free(register_request->email);
        register_request->email = NULL;
    }
    if (register_request->first_name) {
        free(register_request->first_name);
        register_request->first_name = NULL;
    }
    if (register_request->last_name) {
        free(register_request->last_name);
        register_request->last_name = NULL;
    }
    if (register_request->password) {
        free(register_request->password);
        register_request->password = NULL;
    }
    if (register_request->privacy_accepted) {
        free(register_request->privacy_accepted);
        register_request->privacy_accepted = NULL;
    }
    free(register_request);
}

cJSON *register_request_convertToJSON(register_request_t *register_request) {
    cJSON *item = cJSON_CreateObject();

    // register_request->company_name
    if (!register_request->company_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "company_name", register_request->company_name) == NULL) {
    goto fail; //String
    }


    // register_request->email
    if (!register_request->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", register_request->email) == NULL) {
    goto fail; //String
    }


    // register_request->first_name
    if (!register_request->first_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "first_name", register_request->first_name) == NULL) {
    goto fail; //String
    }


    // register_request->last_name
    if (!register_request->last_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "last_name", register_request->last_name) == NULL) {
    goto fail; //String
    }


    // register_request->password
    if (!register_request->password) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "password", register_request->password) == NULL) {
    goto fail; //String
    }


    // register_request->privacy_accepted
    if (!register_request->privacy_accepted) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "privacy_accepted", *register_request->privacy_accepted) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

register_request_t *register_request_parseFromJSON(cJSON *register_requestJSON){

    register_request_t *register_request_local_var = NULL;

    char *company_name_local_str = NULL;

    char *email_local_str = NULL;

    char *first_name_local_str = NULL;

    char *last_name_local_str = NULL;

    char *password_local_str = NULL;

    // define the local variable for register_request->privacy_accepted
    int *privacy_accepted_local_var = NULL;

    // register_request->company_name
    cJSON *company_name = cJSON_GetObjectItemCaseSensitive(register_requestJSON, "company_name");
    if (cJSON_IsNull(company_name)) {
        company_name = NULL;
    }
    if (!company_name) {
        goto end;
    }

    
    if(!cJSON_IsString(company_name))
    {
    goto end; //String
    }

    // register_request->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(register_requestJSON, "email");
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

    // register_request->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(register_requestJSON, "first_name");
    if (cJSON_IsNull(first_name)) {
        first_name = NULL;
    }
    if (!first_name) {
        goto end;
    }

    
    if(!cJSON_IsString(first_name))
    {
    goto end; //String
    }

    // register_request->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(register_requestJSON, "last_name");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (!last_name) {
        goto end;
    }

    
    if(!cJSON_IsString(last_name))
    {
    goto end; //String
    }

    // register_request->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(register_requestJSON, "password");
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

    // register_request->privacy_accepted
    cJSON *privacy_accepted = cJSON_GetObjectItemCaseSensitive(register_requestJSON, "privacy_accepted");
    if (cJSON_IsNull(privacy_accepted)) {
        privacy_accepted = NULL;
    }
    if (!privacy_accepted) {
        goto end;
    }

    
    if(!cJSON_IsBool(privacy_accepted))
    {
    goto end; //Bool
    }
    privacy_accepted_local_var = malloc(sizeof(int));
    if(!privacy_accepted_local_var)
    {
        goto end;
    }
    *privacy_accepted_local_var = privacy_accepted->valueint;


    if (company_name && !cJSON_IsNull(company_name)) company_name_local_str = strdup(company_name->valuestring);
    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);
    if (first_name && !cJSON_IsNull(first_name)) first_name_local_str = strdup(first_name->valuestring);
    if (last_name && !cJSON_IsNull(last_name)) last_name_local_str = strdup(last_name->valuestring);
    if (password && !cJSON_IsNull(password)) password_local_str = strdup(password->valuestring);

    register_request_local_var = register_request_create_internal (
        company_name_local_str,
        email_local_str,
        first_name_local_str,
        last_name_local_str,
        password_local_str,
        privacy_accepted_local_var
        );

    if (!register_request_local_var) {
        goto end;
    }

    return register_request_local_var;
end:
    if (company_name_local_str) {
        free(company_name_local_str);
        company_name_local_str = NULL;
    }
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    if (first_name_local_str) {
        free(first_name_local_str);
        first_name_local_str = NULL;
    }
    if (last_name_local_str) {
        free(last_name_local_str);
        last_name_local_str = NULL;
    }
    if (password_local_str) {
        free(password_local_str);
        password_local_str = NULL;
    }
    if (privacy_accepted_local_var) {
        free(privacy_accepted_local_var);
        privacy_accepted_local_var = NULL;
    }
    return NULL;

}
