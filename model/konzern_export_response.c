#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "konzern_export_response.h"



static konzern_export_response_t *konzern_export_response_create_internal(
    char *csv_content,
    char *filename
    ) {
    konzern_export_response_t *konzern_export_response_local_var = malloc(sizeof(konzern_export_response_t));
    if (!konzern_export_response_local_var) {
        return NULL;
    }
    memset(konzern_export_response_local_var, 0, sizeof(konzern_export_response_t));
    konzern_export_response_local_var->_library_owned = 1;
    konzern_export_response_local_var->csv_content = csv_content;
    konzern_export_response_local_var->filename = filename;
    return konzern_export_response_local_var;
}

__attribute__((deprecated)) konzern_export_response_t *konzern_export_response_create(
    char *csv_content,
    char *filename
    ) {
    konzern_export_response_t *result = konzern_export_response_create_internal (
        csv_content,
        filename
        );
    if (!result) {
    }
    return result;
}

void konzern_export_response_free(konzern_export_response_t *konzern_export_response) {
    if(NULL == konzern_export_response){
        return ;
    }
    if(konzern_export_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "konzern_export_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (konzern_export_response->csv_content) {
        free(konzern_export_response->csv_content);
        konzern_export_response->csv_content = NULL;
    }
    if (konzern_export_response->filename) {
        free(konzern_export_response->filename);
        konzern_export_response->filename = NULL;
    }
    free(konzern_export_response);
}

cJSON *konzern_export_response_convertToJSON(konzern_export_response_t *konzern_export_response) {
    cJSON *item = cJSON_CreateObject();

    // konzern_export_response->csv_content
    if (!konzern_export_response->csv_content) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "csv_content", konzern_export_response->csv_content) == NULL) {
    goto fail; //String
    }


    // konzern_export_response->filename
    if (!konzern_export_response->filename) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "filename", konzern_export_response->filename) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

konzern_export_response_t *konzern_export_response_parseFromJSON(cJSON *konzern_export_responseJSON){

    konzern_export_response_t *konzern_export_response_local_var = NULL;

    char *csv_content_local_str = NULL;

    char *filename_local_str = NULL;

    // konzern_export_response->csv_content
    cJSON *csv_content = cJSON_GetObjectItemCaseSensitive(konzern_export_responseJSON, "csv_content");
    if (cJSON_IsNull(csv_content)) {
        csv_content = NULL;
    }
    if (!csv_content) {
        goto end;
    }

    
    if(!cJSON_IsString(csv_content))
    {
    goto end; //String
    }

    // konzern_export_response->filename
    cJSON *filename = cJSON_GetObjectItemCaseSensitive(konzern_export_responseJSON, "filename");
    if (cJSON_IsNull(filename)) {
        filename = NULL;
    }
    if (!filename) {
        goto end;
    }

    
    if(!cJSON_IsString(filename))
    {
    goto end; //String
    }


    if (csv_content && !cJSON_IsNull(csv_content)) csv_content_local_str = strdup(csv_content->valuestring);
    if (filename && !cJSON_IsNull(filename)) filename_local_str = strdup(filename->valuestring);

    konzern_export_response_local_var = konzern_export_response_create_internal (
        csv_content_local_str,
        filename_local_str
        );

    if (!konzern_export_response_local_var) {
        goto end;
    }

    return konzern_export_response_local_var;
end:
    if (csv_content_local_str) {
        free(csv_content_local_str);
        csv_content_local_str = NULL;
    }
    if (filename_local_str) {
        free(filename_local_str);
        filename_local_str = NULL;
    }
    return NULL;

}
