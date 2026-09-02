#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stille_export_response.h"



static stille_export_response_t *stille_export_response_create_internal(
    char *csv_content,
    char *filename
    ) {
    stille_export_response_t *stille_export_response_local_var = malloc(sizeof(stille_export_response_t));
    if (!stille_export_response_local_var) {
        return NULL;
    }
    memset(stille_export_response_local_var, 0, sizeof(stille_export_response_t));
    stille_export_response_local_var->_library_owned = 1;
    stille_export_response_local_var->csv_content = csv_content;
    stille_export_response_local_var->filename = filename;
    return stille_export_response_local_var;
}

__attribute__((deprecated)) stille_export_response_t *stille_export_response_create(
    char *csv_content,
    char *filename
    ) {
    stille_export_response_t *result = stille_export_response_create_internal (
        csv_content,
        filename
        );
    if (!result) {
    }
    return result;
}

void stille_export_response_free(stille_export_response_t *stille_export_response) {
    if(NULL == stille_export_response){
        return ;
    }
    if(stille_export_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "stille_export_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (stille_export_response->csv_content) {
        free(stille_export_response->csv_content);
        stille_export_response->csv_content = NULL;
    }
    if (stille_export_response->filename) {
        free(stille_export_response->filename);
        stille_export_response->filename = NULL;
    }
    free(stille_export_response);
}

cJSON *stille_export_response_convertToJSON(stille_export_response_t *stille_export_response) {
    cJSON *item = cJSON_CreateObject();

    // stille_export_response->csv_content
    if (!stille_export_response->csv_content) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "csv_content", stille_export_response->csv_content) == NULL) {
    goto fail; //String
    }


    // stille_export_response->filename
    if (!stille_export_response->filename) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "filename", stille_export_response->filename) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

stille_export_response_t *stille_export_response_parseFromJSON(cJSON *stille_export_responseJSON){

    stille_export_response_t *stille_export_response_local_var = NULL;

    char *csv_content_local_str = NULL;

    char *filename_local_str = NULL;

    // stille_export_response->csv_content
    cJSON *csv_content = cJSON_GetObjectItemCaseSensitive(stille_export_responseJSON, "csv_content");
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

    // stille_export_response->filename
    cJSON *filename = cJSON_GetObjectItemCaseSensitive(stille_export_responseJSON, "filename");
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

    stille_export_response_local_var = stille_export_response_create_internal (
        csv_content_local_str,
        filename_local_str
        );

    if (!stille_export_response_local_var) {
        goto end;
    }

    return stille_export_response_local_var;
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
