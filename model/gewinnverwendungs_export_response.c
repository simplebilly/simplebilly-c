#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gewinnverwendungs_export_response.h"



static gewinnverwendungs_export_response_t *gewinnverwendungs_export_response_create_internal(
    char *csv_content,
    char *filename
    ) {
    gewinnverwendungs_export_response_t *gewinnverwendungs_export_response_local_var = malloc(sizeof(gewinnverwendungs_export_response_t));
    if (!gewinnverwendungs_export_response_local_var) {
        return NULL;
    }
    memset(gewinnverwendungs_export_response_local_var, 0, sizeof(gewinnverwendungs_export_response_t));
    gewinnverwendungs_export_response_local_var->_library_owned = 1;
    gewinnverwendungs_export_response_local_var->csv_content = csv_content;
    gewinnverwendungs_export_response_local_var->filename = filename;
    return gewinnverwendungs_export_response_local_var;
}

__attribute__((deprecated)) gewinnverwendungs_export_response_t *gewinnverwendungs_export_response_create(
    char *csv_content,
    char *filename
    ) {
    gewinnverwendungs_export_response_t *result = gewinnverwendungs_export_response_create_internal (
        csv_content,
        filename
        );
    if (!result) {
    }
    return result;
}

void gewinnverwendungs_export_response_free(gewinnverwendungs_export_response_t *gewinnverwendungs_export_response) {
    if(NULL == gewinnverwendungs_export_response){
        return ;
    }
    if(gewinnverwendungs_export_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gewinnverwendungs_export_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gewinnverwendungs_export_response->csv_content) {
        free(gewinnverwendungs_export_response->csv_content);
        gewinnverwendungs_export_response->csv_content = NULL;
    }
    if (gewinnverwendungs_export_response->filename) {
        free(gewinnverwendungs_export_response->filename);
        gewinnverwendungs_export_response->filename = NULL;
    }
    free(gewinnverwendungs_export_response);
}

cJSON *gewinnverwendungs_export_response_convertToJSON(gewinnverwendungs_export_response_t *gewinnverwendungs_export_response) {
    cJSON *item = cJSON_CreateObject();

    // gewinnverwendungs_export_response->csv_content
    if (!gewinnverwendungs_export_response->csv_content) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "csv_content", gewinnverwendungs_export_response->csv_content) == NULL) {
    goto fail; //String
    }


    // gewinnverwendungs_export_response->filename
    if (!gewinnverwendungs_export_response->filename) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "filename", gewinnverwendungs_export_response->filename) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gewinnverwendungs_export_response_t *gewinnverwendungs_export_response_parseFromJSON(cJSON *gewinnverwendungs_export_responseJSON){

    gewinnverwendungs_export_response_t *gewinnverwendungs_export_response_local_var = NULL;

    char *csv_content_local_str = NULL;

    char *filename_local_str = NULL;

    // gewinnverwendungs_export_response->csv_content
    cJSON *csv_content = cJSON_GetObjectItemCaseSensitive(gewinnverwendungs_export_responseJSON, "csv_content");
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

    // gewinnverwendungs_export_response->filename
    cJSON *filename = cJSON_GetObjectItemCaseSensitive(gewinnverwendungs_export_responseJSON, "filename");
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

    gewinnverwendungs_export_response_local_var = gewinnverwendungs_export_response_create_internal (
        csv_content_local_str,
        filename_local_str
        );

    if (!gewinnverwendungs_export_response_local_var) {
        goto end;
    }

    return gewinnverwendungs_export_response_local_var;
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
