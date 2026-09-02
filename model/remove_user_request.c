#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "remove_user_request.h"



static remove_user_request_t *remove_user_request_create_internal(
    char *email
    ) {
    remove_user_request_t *remove_user_request_local_var = malloc(sizeof(remove_user_request_t));
    if (!remove_user_request_local_var) {
        return NULL;
    }
    memset(remove_user_request_local_var, 0, sizeof(remove_user_request_t));
    remove_user_request_local_var->_library_owned = 1;
    remove_user_request_local_var->email = email;
    return remove_user_request_local_var;
}

__attribute__((deprecated)) remove_user_request_t *remove_user_request_create(
    char *email
    ) {
    remove_user_request_t *result = remove_user_request_create_internal (
        email
        );
    if (!result) {
    }
    return result;
}

void remove_user_request_free(remove_user_request_t *remove_user_request) {
    if(NULL == remove_user_request){
        return ;
    }
    if(remove_user_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "remove_user_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (remove_user_request->email) {
        free(remove_user_request->email);
        remove_user_request->email = NULL;
    }
    free(remove_user_request);
}

cJSON *remove_user_request_convertToJSON(remove_user_request_t *remove_user_request) {
    cJSON *item = cJSON_CreateObject();

    // remove_user_request->email
    if (!remove_user_request->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", remove_user_request->email) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

remove_user_request_t *remove_user_request_parseFromJSON(cJSON *remove_user_requestJSON){

    remove_user_request_t *remove_user_request_local_var = NULL;

    char *email_local_str = NULL;

    // remove_user_request->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(remove_user_requestJSON, "email");
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

    remove_user_request_local_var = remove_user_request_create_internal (
        email_local_str
        );

    if (!remove_user_request_local_var) {
        goto end;
    }

    return remove_user_request_local_var;
end:
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    return NULL;

}
