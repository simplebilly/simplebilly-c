#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "go_bd_export_response.h"



static go_bd_export_response_t *go_bd_export_response_create_internal(
    int *booking_count,
    char *csv_content,
    char *filename
    ) {
    go_bd_export_response_t *go_bd_export_response_local_var = malloc(sizeof(go_bd_export_response_t));
    if (!go_bd_export_response_local_var) {
        return NULL;
    }
    memset(go_bd_export_response_local_var, 0, sizeof(go_bd_export_response_t));
    go_bd_export_response_local_var->_library_owned = 1;
    go_bd_export_response_local_var->booking_count = booking_count;
    go_bd_export_response_local_var->csv_content = csv_content;
    go_bd_export_response_local_var->filename = filename;
    return go_bd_export_response_local_var;
}

__attribute__((deprecated)) go_bd_export_response_t *go_bd_export_response_create(
    int *booking_count,
    char *csv_content,
    char *filename
    ) {
    int *booking_count_copy = NULL;
    if (booking_count) {
        booking_count_copy = malloc(sizeof(int));
        if (booking_count_copy) *booking_count_copy = *booking_count;
    }
    go_bd_export_response_t *result = go_bd_export_response_create_internal (
        booking_count_copy,
        csv_content,
        filename
        );
    if (!result) {
        free(booking_count_copy);
    }
    return result;
}

void go_bd_export_response_free(go_bd_export_response_t *go_bd_export_response) {
    if(NULL == go_bd_export_response){
        return ;
    }
    if(go_bd_export_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "go_bd_export_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (go_bd_export_response->booking_count) {
        free(go_bd_export_response->booking_count);
        go_bd_export_response->booking_count = NULL;
    }
    if (go_bd_export_response->csv_content) {
        free(go_bd_export_response->csv_content);
        go_bd_export_response->csv_content = NULL;
    }
    if (go_bd_export_response->filename) {
        free(go_bd_export_response->filename);
        go_bd_export_response->filename = NULL;
    }
    free(go_bd_export_response);
}

cJSON *go_bd_export_response_convertToJSON(go_bd_export_response_t *go_bd_export_response) {
    cJSON *item = cJSON_CreateObject();

    // go_bd_export_response->booking_count
    if (!go_bd_export_response->booking_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "booking_count", *go_bd_export_response->booking_count) == NULL) {
    goto fail; //Numeric
    }


    // go_bd_export_response->csv_content
    if (!go_bd_export_response->csv_content) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "csv_content", go_bd_export_response->csv_content) == NULL) {
    goto fail; //String
    }


    // go_bd_export_response->filename
    if (!go_bd_export_response->filename) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "filename", go_bd_export_response->filename) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

go_bd_export_response_t *go_bd_export_response_parseFromJSON(cJSON *go_bd_export_responseJSON){

    go_bd_export_response_t *go_bd_export_response_local_var = NULL;

    // define the local variable for go_bd_export_response->booking_count
    int *booking_count_local_var = NULL;

    char *csv_content_local_str = NULL;

    char *filename_local_str = NULL;

    // go_bd_export_response->booking_count
    cJSON *booking_count = cJSON_GetObjectItemCaseSensitive(go_bd_export_responseJSON, "booking_count");
    if (cJSON_IsNull(booking_count)) {
        booking_count = NULL;
    }
    if (!booking_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(booking_count))
    {
    goto end; //Numeric
    }
    booking_count_local_var = malloc(sizeof(int));
    if(!booking_count_local_var)
    {
        goto end;
    }
    *booking_count_local_var = booking_count->valuedouble;

    // go_bd_export_response->csv_content
    cJSON *csv_content = cJSON_GetObjectItemCaseSensitive(go_bd_export_responseJSON, "csv_content");
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

    // go_bd_export_response->filename
    cJSON *filename = cJSON_GetObjectItemCaseSensitive(go_bd_export_responseJSON, "filename");
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

    go_bd_export_response_local_var = go_bd_export_response_create_internal (
        booking_count_local_var,
        csv_content_local_str,
        filename_local_str
        );

    if (!go_bd_export_response_local_var) {
        goto end;
    }

    return go_bd_export_response_local_var;
end:
    if (booking_count_local_var) {
        free(booking_count_local_var);
        booking_count_local_var = NULL;
    }
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
