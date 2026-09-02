#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "datev_export_response.h"



static datev_export_response_t *datev_export_response_create_internal(
    int *booking_count,
    char *csv_content,
    char *filename
    ) {
    datev_export_response_t *datev_export_response_local_var = malloc(sizeof(datev_export_response_t));
    if (!datev_export_response_local_var) {
        return NULL;
    }
    memset(datev_export_response_local_var, 0, sizeof(datev_export_response_t));
    datev_export_response_local_var->_library_owned = 1;
    datev_export_response_local_var->booking_count = booking_count;
    datev_export_response_local_var->csv_content = csv_content;
    datev_export_response_local_var->filename = filename;
    return datev_export_response_local_var;
}

__attribute__((deprecated)) datev_export_response_t *datev_export_response_create(
    int *booking_count,
    char *csv_content,
    char *filename
    ) {
    int *booking_count_copy = NULL;
    if (booking_count) {
        booking_count_copy = malloc(sizeof(int));
        if (booking_count_copy) *booking_count_copy = *booking_count;
    }
    datev_export_response_t *result = datev_export_response_create_internal (
        booking_count_copy,
        csv_content,
        filename
        );
    if (!result) {
        free(booking_count_copy);
    }
    return result;
}

void datev_export_response_free(datev_export_response_t *datev_export_response) {
    if(NULL == datev_export_response){
        return ;
    }
    if(datev_export_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "datev_export_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (datev_export_response->booking_count) {
        free(datev_export_response->booking_count);
        datev_export_response->booking_count = NULL;
    }
    if (datev_export_response->csv_content) {
        free(datev_export_response->csv_content);
        datev_export_response->csv_content = NULL;
    }
    if (datev_export_response->filename) {
        free(datev_export_response->filename);
        datev_export_response->filename = NULL;
    }
    free(datev_export_response);
}

cJSON *datev_export_response_convertToJSON(datev_export_response_t *datev_export_response) {
    cJSON *item = cJSON_CreateObject();

    // datev_export_response->booking_count
    if (!datev_export_response->booking_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "booking_count", *datev_export_response->booking_count) == NULL) {
    goto fail; //Numeric
    }


    // datev_export_response->csv_content
    if (!datev_export_response->csv_content) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "csv_content", datev_export_response->csv_content) == NULL) {
    goto fail; //String
    }


    // datev_export_response->filename
    if (!datev_export_response->filename) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "filename", datev_export_response->filename) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

datev_export_response_t *datev_export_response_parseFromJSON(cJSON *datev_export_responseJSON){

    datev_export_response_t *datev_export_response_local_var = NULL;

    // define the local variable for datev_export_response->booking_count
    int *booking_count_local_var = NULL;

    char *csv_content_local_str = NULL;

    char *filename_local_str = NULL;

    // datev_export_response->booking_count
    cJSON *booking_count = cJSON_GetObjectItemCaseSensitive(datev_export_responseJSON, "booking_count");
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

    // datev_export_response->csv_content
    cJSON *csv_content = cJSON_GetObjectItemCaseSensitive(datev_export_responseJSON, "csv_content");
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

    // datev_export_response->filename
    cJSON *filename = cJSON_GetObjectItemCaseSensitive(datev_export_responseJSON, "filename");
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

    datev_export_response_local_var = datev_export_response_create_internal (
        booking_count_local_var,
        csv_content_local_str,
        filename_local_str
        );

    if (!datev_export_response_local_var) {
        goto end;
    }

    return datev_export_response_local_var;
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
