#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invite_request.h"



static invite_request_t *invite_request_create_internal(
    char *email
    ) {
    invite_request_t *invite_request_local_var = malloc(sizeof(invite_request_t));
    if (!invite_request_local_var) {
        return NULL;
    }
    memset(invite_request_local_var, 0, sizeof(invite_request_t));
    invite_request_local_var->_library_owned = 1;
    invite_request_local_var->email = email;
    return invite_request_local_var;
}

__attribute__((deprecated)) invite_request_t *invite_request_create(
    char *email
    ) {
    invite_request_t *result = invite_request_create_internal (
        email
        );
    if (!result) {
    }
    return result;
}

void invite_request_free(invite_request_t *invite_request) {
    if(NULL == invite_request){
        return ;
    }
    if(invite_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invite_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invite_request->email) {
        free(invite_request->email);
        invite_request->email = NULL;
    }
    free(invite_request);
}

cJSON *invite_request_convertToJSON(invite_request_t *invite_request) {
    cJSON *item = cJSON_CreateObject();

    // invite_request->email
    if (!invite_request->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", invite_request->email) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

invite_request_t *invite_request_parseFromJSON(cJSON *invite_requestJSON){

    invite_request_t *invite_request_local_var = NULL;

    char *email_local_str = NULL;

    // invite_request->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(invite_requestJSON, "email");
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

    invite_request_local_var = invite_request_create_internal (
        email_local_str
        );

    if (!invite_request_local_var) {
        goto end;
    }

    return invite_request_local_var;
end:
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    return NULL;

}
