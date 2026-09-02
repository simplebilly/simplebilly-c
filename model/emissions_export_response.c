#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "emissions_export_response.h"



static emissions_export_response_t *emissions_export_response_create_internal(
    char *csv_content,
    char *filename
    ) {
    emissions_export_response_t *emissions_export_response_local_var = malloc(sizeof(emissions_export_response_t));
    if (!emissions_export_response_local_var) {
        return NULL;
    }
    memset(emissions_export_response_local_var, 0, sizeof(emissions_export_response_t));
    emissions_export_response_local_var->_library_owned = 1;
    emissions_export_response_local_var->csv_content = csv_content;
    emissions_export_response_local_var->filename = filename;
    return emissions_export_response_local_var;
}

__attribute__((deprecated)) emissions_export_response_t *emissions_export_response_create(
    char *csv_content,
    char *filename
    ) {
    emissions_export_response_t *result = emissions_export_response_create_internal (
        csv_content,
        filename
        );
    if (!result) {
    }
    return result;
}

void emissions_export_response_free(emissions_export_response_t *emissions_export_response) {
    if(NULL == emissions_export_response){
        return ;
    }
    if(emissions_export_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "emissions_export_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (emissions_export_response->csv_content) {
        free(emissions_export_response->csv_content);
        emissions_export_response->csv_content = NULL;
    }
    if (emissions_export_response->filename) {
        free(emissions_export_response->filename);
        emissions_export_response->filename = NULL;
    }
    free(emissions_export_response);
}

cJSON *emissions_export_response_convertToJSON(emissions_export_response_t *emissions_export_response) {
    cJSON *item = cJSON_CreateObject();

    // emissions_export_response->csv_content
    if (!emissions_export_response->csv_content) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "csv_content", emissions_export_response->csv_content) == NULL) {
    goto fail; //String
    }


    // emissions_export_response->filename
    if (!emissions_export_response->filename) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "filename", emissions_export_response->filename) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

emissions_export_response_t *emissions_export_response_parseFromJSON(cJSON *emissions_export_responseJSON){

    emissions_export_response_t *emissions_export_response_local_var = NULL;

    char *csv_content_local_str = NULL;

    char *filename_local_str = NULL;

    // emissions_export_response->csv_content
    cJSON *csv_content = cJSON_GetObjectItemCaseSensitive(emissions_export_responseJSON, "csv_content");
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

    // emissions_export_response->filename
    cJSON *filename = cJSON_GetObjectItemCaseSensitive(emissions_export_responseJSON, "filename");
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

    emissions_export_response_local_var = emissions_export_response_create_internal (
        csv_content_local_str,
        filename_local_str
        );

    if (!emissions_export_response_local_var) {
        goto end;
    }

    return emissions_export_response_local_var;
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
