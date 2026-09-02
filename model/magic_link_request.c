#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "magic_link_request.h"



static magic_link_request_t *magic_link_request_create_internal(
    char *email
    ) {
    magic_link_request_t *magic_link_request_local_var = malloc(sizeof(magic_link_request_t));
    if (!magic_link_request_local_var) {
        return NULL;
    }
    memset(magic_link_request_local_var, 0, sizeof(magic_link_request_t));
    magic_link_request_local_var->_library_owned = 1;
    magic_link_request_local_var->email = email;
    return magic_link_request_local_var;
}

__attribute__((deprecated)) magic_link_request_t *magic_link_request_create(
    char *email
    ) {
    magic_link_request_t *result = magic_link_request_create_internal (
        email
        );
    if (!result) {
    }
    return result;
}

void magic_link_request_free(magic_link_request_t *magic_link_request) {
    if(NULL == magic_link_request){
        return ;
    }
    if(magic_link_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "magic_link_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (magic_link_request->email) {
        free(magic_link_request->email);
        magic_link_request->email = NULL;
    }
    free(magic_link_request);
}

cJSON *magic_link_request_convertToJSON(magic_link_request_t *magic_link_request) {
    cJSON *item = cJSON_CreateObject();

    // magic_link_request->email
    if (!magic_link_request->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", magic_link_request->email) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

magic_link_request_t *magic_link_request_parseFromJSON(cJSON *magic_link_requestJSON){

    magic_link_request_t *magic_link_request_local_var = NULL;

    char *email_local_str = NULL;

    // magic_link_request->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(magic_link_requestJSON, "email");
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

    magic_link_request_local_var = magic_link_request_create_internal (
        email_local_str
        );

    if (!magic_link_request_local_var) {
        goto end;
    }

    return magic_link_request_local_var;
end:
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    return NULL;

}
