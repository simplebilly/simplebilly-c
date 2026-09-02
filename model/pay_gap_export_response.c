#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pay_gap_export_response.h"



static pay_gap_export_response_t *pay_gap_export_response_create_internal(
    char *csv_content,
    char *filename
    ) {
    pay_gap_export_response_t *pay_gap_export_response_local_var = malloc(sizeof(pay_gap_export_response_t));
    if (!pay_gap_export_response_local_var) {
        return NULL;
    }
    memset(pay_gap_export_response_local_var, 0, sizeof(pay_gap_export_response_t));
    pay_gap_export_response_local_var->_library_owned = 1;
    pay_gap_export_response_local_var->csv_content = csv_content;
    pay_gap_export_response_local_var->filename = filename;
    return pay_gap_export_response_local_var;
}

__attribute__((deprecated)) pay_gap_export_response_t *pay_gap_export_response_create(
    char *csv_content,
    char *filename
    ) {
    pay_gap_export_response_t *result = pay_gap_export_response_create_internal (
        csv_content,
        filename
        );
    if (!result) {
    }
    return result;
}

void pay_gap_export_response_free(pay_gap_export_response_t *pay_gap_export_response) {
    if(NULL == pay_gap_export_response){
        return ;
    }
    if(pay_gap_export_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "pay_gap_export_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (pay_gap_export_response->csv_content) {
        free(pay_gap_export_response->csv_content);
        pay_gap_export_response->csv_content = NULL;
    }
    if (pay_gap_export_response->filename) {
        free(pay_gap_export_response->filename);
        pay_gap_export_response->filename = NULL;
    }
    free(pay_gap_export_response);
}

cJSON *pay_gap_export_response_convertToJSON(pay_gap_export_response_t *pay_gap_export_response) {
    cJSON *item = cJSON_CreateObject();

    // pay_gap_export_response->csv_content
    if (!pay_gap_export_response->csv_content) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "csv_content", pay_gap_export_response->csv_content) == NULL) {
    goto fail; //String
    }


    // pay_gap_export_response->filename
    if (!pay_gap_export_response->filename) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "filename", pay_gap_export_response->filename) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

pay_gap_export_response_t *pay_gap_export_response_parseFromJSON(cJSON *pay_gap_export_responseJSON){

    pay_gap_export_response_t *pay_gap_export_response_local_var = NULL;

    char *csv_content_local_str = NULL;

    char *filename_local_str = NULL;

    // pay_gap_export_response->csv_content
    cJSON *csv_content = cJSON_GetObjectItemCaseSensitive(pay_gap_export_responseJSON, "csv_content");
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

    // pay_gap_export_response->filename
    cJSON *filename = cJSON_GetObjectItemCaseSensitive(pay_gap_export_responseJSON, "filename");
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

    pay_gap_export_response_local_var = pay_gap_export_response_create_internal (
        csv_content_local_str,
        filename_local_str
        );

    if (!pay_gap_export_response_local_var) {
        goto end;
    }

    return pay_gap_export_response_local_var;
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
