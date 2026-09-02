#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pos_register_create.h"



static pos_register_create_t *pos_register_create_create_internal(
    char *name,
    simplebilly_api_pos_register_status__e status
    ) {
    pos_register_create_t *pos_register_create_local_var = malloc(sizeof(pos_register_create_t));
    if (!pos_register_create_local_var) {
        return NULL;
    }
    memset(pos_register_create_local_var, 0, sizeof(pos_register_create_t));
    pos_register_create_local_var->_library_owned = 1;
    pos_register_create_local_var->name = name;
    pos_register_create_local_var->status = status;
    return pos_register_create_local_var;
}

__attribute__((deprecated)) pos_register_create_t *pos_register_create_create(
    char *name,
    simplebilly_api_pos_register_status__e status
    ) {
    pos_register_create_t *result = pos_register_create_create_internal (
        name,
        status
        );
    if (!result) {
    }
    return result;
}

void pos_register_create_free(pos_register_create_t *pos_register_create) {
    if(NULL == pos_register_create){
        return ;
    }
    if(pos_register_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "pos_register_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (pos_register_create->name) {
        free(pos_register_create->name);
        pos_register_create->name = NULL;
    }
    free(pos_register_create);
}

cJSON *pos_register_create_convertToJSON(pos_register_create_t *pos_register_create) {
    cJSON *item = cJSON_CreateObject();

    // pos_register_create->name
    if (!pos_register_create->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", pos_register_create->name) == NULL) {
    goto fail; //String
    }


    // pos_register_create->status
    if(pos_register_create->status != simplebilly_api_pos_register_status__NULL) {
    cJSON *status_local_JSON = pos_register_status_convertToJSON(pos_register_create->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

pos_register_create_t *pos_register_create_parseFromJSON(cJSON *pos_register_createJSON){

    pos_register_create_t *pos_register_create_local_var = NULL;

    char *name_local_str = NULL;

    // define the local variable for pos_register_create->status
    simplebilly_api_pos_register_status__e status_local_nonprim = 0;

    // pos_register_create->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pos_register_createJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // pos_register_create->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(pos_register_createJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = pos_register_status_parseFromJSON(status); //custom
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    pos_register_create_local_var = pos_register_create_create_internal (
        name_local_str,
        status ? status_local_nonprim : 0
        );

    if (!pos_register_create_local_var) {
        goto end;
    }

    return pos_register_create_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (status_local_nonprim) {
        status_local_nonprim = 0;
    }
    return NULL;

}
