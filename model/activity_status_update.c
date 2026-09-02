#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "activity_status_update.h"



static activity_status_update_t *activity_status_update_create_internal(
    char *status
    ) {
    activity_status_update_t *activity_status_update_local_var = malloc(sizeof(activity_status_update_t));
    if (!activity_status_update_local_var) {
        return NULL;
    }
    memset(activity_status_update_local_var, 0, sizeof(activity_status_update_t));
    activity_status_update_local_var->_library_owned = 1;
    activity_status_update_local_var->status = status;
    return activity_status_update_local_var;
}

__attribute__((deprecated)) activity_status_update_t *activity_status_update_create(
    char *status
    ) {
    activity_status_update_t *result = activity_status_update_create_internal (
        status
        );
    if (!result) {
    }
    return result;
}

void activity_status_update_free(activity_status_update_t *activity_status_update) {
    if(NULL == activity_status_update){
        return ;
    }
    if(activity_status_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "activity_status_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (activity_status_update->status) {
        free(activity_status_update->status);
        activity_status_update->status = NULL;
    }
    free(activity_status_update);
}

cJSON *activity_status_update_convertToJSON(activity_status_update_t *activity_status_update) {
    cJSON *item = cJSON_CreateObject();

    // activity_status_update->status
    if (!activity_status_update->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", activity_status_update->status) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

activity_status_update_t *activity_status_update_parseFromJSON(cJSON *activity_status_updateJSON){

    activity_status_update_t *activity_status_update_local_var = NULL;

    char *status_local_str = NULL;

    // activity_status_update->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(activity_status_updateJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }


    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);

    activity_status_update_local_var = activity_status_update_create_internal (
        status_local_str
        );

    if (!activity_status_update_local_var) {
        goto end;
    }

    return activity_status_update_local_var;
end:
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    return NULL;

}
