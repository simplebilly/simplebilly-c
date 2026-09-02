#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "application_status_dto.h"



static application_status_dto_t *application_status_dto_create_internal(
    char *posting_id,
    char *status
    ) {
    application_status_dto_t *application_status_dto_local_var = malloc(sizeof(application_status_dto_t));
    if (!application_status_dto_local_var) {
        return NULL;
    }
    memset(application_status_dto_local_var, 0, sizeof(application_status_dto_t));
    application_status_dto_local_var->_library_owned = 1;
    application_status_dto_local_var->posting_id = posting_id;
    application_status_dto_local_var->status = status;
    return application_status_dto_local_var;
}

__attribute__((deprecated)) application_status_dto_t *application_status_dto_create(
    char *posting_id,
    char *status
    ) {
    application_status_dto_t *result = application_status_dto_create_internal (
        posting_id,
        status
        );
    if (!result) {
    }
    return result;
}

void application_status_dto_free(application_status_dto_t *application_status_dto) {
    if(NULL == application_status_dto){
        return ;
    }
    if(application_status_dto->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "application_status_dto_free");
        return ;
    }
    listEntry_t *listEntry;
    if (application_status_dto->posting_id) {
        free(application_status_dto->posting_id);
        application_status_dto->posting_id = NULL;
    }
    if (application_status_dto->status) {
        free(application_status_dto->status);
        application_status_dto->status = NULL;
    }
    free(application_status_dto);
}

cJSON *application_status_dto_convertToJSON(application_status_dto_t *application_status_dto) {
    cJSON *item = cJSON_CreateObject();

    // application_status_dto->posting_id
    if(application_status_dto->posting_id) {
    if(cJSON_AddStringToObject(item, "postingId", application_status_dto->posting_id) == NULL) {
    goto fail; //String
    }
    }


    // application_status_dto->status
    if (!application_status_dto->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", application_status_dto->status) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

application_status_dto_t *application_status_dto_parseFromJSON(cJSON *application_status_dtoJSON){

    application_status_dto_t *application_status_dto_local_var = NULL;

    char *posting_id_local_str = NULL;

    char *status_local_str = NULL;

    // application_status_dto->posting_id
    cJSON *posting_id = cJSON_GetObjectItemCaseSensitive(application_status_dtoJSON, "postingId");
    if (cJSON_IsNull(posting_id)) {
        posting_id = NULL;
    }
    if (posting_id) { 
    if(!cJSON_IsString(posting_id) && !cJSON_IsNull(posting_id))
    {
    goto end; //String
    }
    }

    // application_status_dto->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(application_status_dtoJSON, "status");
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


    if (posting_id && !cJSON_IsNull(posting_id)) posting_id_local_str = strdup(posting_id->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);

    application_status_dto_local_var = application_status_dto_create_internal (
        posting_id_local_str,
        status_local_str
        );

    if (!application_status_dto_local_var) {
        goto end;
    }

    return application_status_dto_local_var;
end:
    if (posting_id_local_str) {
        free(posting_id_local_str);
        posting_id_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    return NULL;

}
