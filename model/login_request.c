#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "login_request.h"



static login_request_t *login_request_create_internal(
    char *email,
    char *password,
    char *totp_code
    ) {
    login_request_t *login_request_local_var = malloc(sizeof(login_request_t));
    if (!login_request_local_var) {
        return NULL;
    }
    memset(login_request_local_var, 0, sizeof(login_request_t));
    login_request_local_var->_library_owned = 1;
    login_request_local_var->email = email;
    login_request_local_var->password = password;
    login_request_local_var->totp_code = totp_code;
    return login_request_local_var;
}

__attribute__((deprecated)) login_request_t *login_request_create(
    char *email,
    char *password,
    char *totp_code
    ) {
    login_request_t *result = login_request_create_internal (
        email,
        password,
        totp_code
        );
    if (!result) {
    }
    return result;
}

void login_request_free(login_request_t *login_request) {
    if(NULL == login_request){
        return ;
    }
    if(login_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "login_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (login_request->email) {
        free(login_request->email);
        login_request->email = NULL;
    }
    if (login_request->password) {
        free(login_request->password);
        login_request->password = NULL;
    }
    if (login_request->totp_code) {
        free(login_request->totp_code);
        login_request->totp_code = NULL;
    }
    free(login_request);
}

cJSON *login_request_convertToJSON(login_request_t *login_request) {
    cJSON *item = cJSON_CreateObject();

    // login_request->email
    if (!login_request->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", login_request->email) == NULL) {
    goto fail; //String
    }


    // login_request->password
    if (!login_request->password) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "password", login_request->password) == NULL) {
    goto fail; //String
    }


    // login_request->totp_code
    if(login_request->totp_code) {
    if(cJSON_AddStringToObject(item, "totp_code", login_request->totp_code) == NULL) {
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

login_request_t *login_request_parseFromJSON(cJSON *login_requestJSON){

    login_request_t *login_request_local_var = NULL;

    char *email_local_str = NULL;

    char *password_local_str = NULL;

    char *totp_code_local_str = NULL;

    // login_request->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(login_requestJSON, "email");
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

    // login_request->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(login_requestJSON, "password");
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

    // login_request->totp_code
    cJSON *totp_code = cJSON_GetObjectItemCaseSensitive(login_requestJSON, "totp_code");
    if (cJSON_IsNull(totp_code)) {
        totp_code = NULL;
    }
    if (totp_code) { 
    if(!cJSON_IsString(totp_code) && !cJSON_IsNull(totp_code))
    {
    goto end; //String
    }
    }


    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);
    if (password && !cJSON_IsNull(password)) password_local_str = strdup(password->valuestring);
    if (totp_code && !cJSON_IsNull(totp_code)) totp_code_local_str = strdup(totp_code->valuestring);

    login_request_local_var = login_request_create_internal (
        email_local_str,
        password_local_str,
        totp_code_local_str
        );

    if (!login_request_local_var) {
        goto end;
    }

    return login_request_local_var;
end:
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    if (password_local_str) {
        free(password_local_str);
        password_local_str = NULL;
    }
    if (totp_code_local_str) {
        free(totp_code_local_str);
        totp_code_local_str = NULL;
    }
    return NULL;

}
