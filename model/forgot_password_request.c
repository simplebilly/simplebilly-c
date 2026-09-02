#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "forgot_password_request.h"



static forgot_password_request_t *forgot_password_request_create_internal(
    char *email
    ) {
    forgot_password_request_t *forgot_password_request_local_var = malloc(sizeof(forgot_password_request_t));
    if (!forgot_password_request_local_var) {
        return NULL;
    }
    memset(forgot_password_request_local_var, 0, sizeof(forgot_password_request_t));
    forgot_password_request_local_var->_library_owned = 1;
    forgot_password_request_local_var->email = email;
    return forgot_password_request_local_var;
}

__attribute__((deprecated)) forgot_password_request_t *forgot_password_request_create(
    char *email
    ) {
    forgot_password_request_t *result = forgot_password_request_create_internal (
        email
        );
    if (!result) {
    }
    return result;
}

void forgot_password_request_free(forgot_password_request_t *forgot_password_request) {
    if(NULL == forgot_password_request){
        return ;
    }
    if(forgot_password_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "forgot_password_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (forgot_password_request->email) {
        free(forgot_password_request->email);
        forgot_password_request->email = NULL;
    }
    free(forgot_password_request);
}

cJSON *forgot_password_request_convertToJSON(forgot_password_request_t *forgot_password_request) {
    cJSON *item = cJSON_CreateObject();

    // forgot_password_request->email
    if (!forgot_password_request->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", forgot_password_request->email) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

forgot_password_request_t *forgot_password_request_parseFromJSON(cJSON *forgot_password_requestJSON){

    forgot_password_request_t *forgot_password_request_local_var = NULL;

    char *email_local_str = NULL;

    // forgot_password_request->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(forgot_password_requestJSON, "email");
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


    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);

    forgot_password_request_local_var = forgot_password_request_create_internal (
        email_local_str
        );

    if (!forgot_password_request_local_var) {
        goto end;
    }

    return forgot_password_request_local_var;
end:
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    return NULL;

}
