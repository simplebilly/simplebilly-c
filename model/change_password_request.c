#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "change_password_request.h"



static change_password_request_t *change_password_request_create_internal(
    char *current_password,
    char *new_password
    ) {
    change_password_request_t *change_password_request_local_var = malloc(sizeof(change_password_request_t));
    if (!change_password_request_local_var) {
        return NULL;
    }
    memset(change_password_request_local_var, 0, sizeof(change_password_request_t));
    change_password_request_local_var->_library_owned = 1;
    change_password_request_local_var->current_password = current_password;
    change_password_request_local_var->new_password = new_password;
    return change_password_request_local_var;
}

__attribute__((deprecated)) change_password_request_t *change_password_request_create(
    char *current_password,
    char *new_password
    ) {
    change_password_request_t *result = change_password_request_create_internal (
        current_password,
        new_password
        );
    if (!result) {
    }
    return result;
}

void change_password_request_free(change_password_request_t *change_password_request) {
    if(NULL == change_password_request){
        return ;
    }
    if(change_password_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "change_password_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (change_password_request->current_password) {
        free(change_password_request->current_password);
        change_password_request->current_password = NULL;
    }
    if (change_password_request->new_password) {
        free(change_password_request->new_password);
        change_password_request->new_password = NULL;
    }
    free(change_password_request);
}

cJSON *change_password_request_convertToJSON(change_password_request_t *change_password_request) {
    cJSON *item = cJSON_CreateObject();

    // change_password_request->current_password
    if (!change_password_request->current_password) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "current_password", change_password_request->current_password) == NULL) {
    goto fail; //String
    }


    // change_password_request->new_password
    if (!change_password_request->new_password) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "new_password", change_password_request->new_password) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

change_password_request_t *change_password_request_parseFromJSON(cJSON *change_password_requestJSON){

    change_password_request_t *change_password_request_local_var = NULL;

    char *current_password_local_str = NULL;

    char *new_password_local_str = NULL;

    // change_password_request->current_password
    cJSON *current_password = cJSON_GetObjectItemCaseSensitive(change_password_requestJSON, "current_password");
    if (cJSON_IsNull(current_password)) {
        current_password = NULL;
    }
    if (!current_password) {
        goto end;
    }

    
    if(!cJSON_IsString(current_password))
    {
    goto end; //String
    }

    // change_password_request->new_password
    cJSON *new_password = cJSON_GetObjectItemCaseSensitive(change_password_requestJSON, "new_password");
    if (cJSON_IsNull(new_password)) {
        new_password = NULL;
    }
    if (!new_password) {
        goto end;
    }

    
    if(!cJSON_IsString(new_password))
    {
    goto end; //String
    }


    if (current_password && !cJSON_IsNull(current_password)) current_password_local_str = strdup(current_password->valuestring);
    if (new_password && !cJSON_IsNull(new_password)) new_password_local_str = strdup(new_password->valuestring);

    change_password_request_local_var = change_password_request_create_internal (
        current_password_local_str,
        new_password_local_str
        );

    if (!change_password_request_local_var) {
        goto end;
    }

    return change_password_request_local_var;
end:
    if (current_password_local_str) {
        free(current_password_local_str);
        current_password_local_str = NULL;
    }
    if (new_password_local_str) {
        free(new_password_local_str);
        new_password_local_str = NULL;
    }
    return NULL;

}
