#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "datev_import_response.h"



static datev_import_response_t *datev_import_response_create_internal(
    int *count,
    char *filename,
    list_t *rows
    ) {
    datev_import_response_t *datev_import_response_local_var = malloc(sizeof(datev_import_response_t));
    if (!datev_import_response_local_var) {
        return NULL;
    }
    memset(datev_import_response_local_var, 0, sizeof(datev_import_response_t));
    datev_import_response_local_var->_library_owned = 1;
    datev_import_response_local_var->count = count;
    datev_import_response_local_var->filename = filename;
    datev_import_response_local_var->rows = rows;
    return datev_import_response_local_var;
}

__attribute__((deprecated)) datev_import_response_t *datev_import_response_create(
    int *count,
    char *filename,
    list_t *rows
    ) {
    int *count_copy = NULL;
    if (count) {
        count_copy = malloc(sizeof(int));
        if (count_copy) *count_copy = *count;
    }
    datev_import_response_t *result = datev_import_response_create_internal (
        count_copy,
        filename,
        rows
        );
    if (!result) {
        free(count_copy);
    }
    return result;
}

void datev_import_response_free(datev_import_response_t *datev_import_response) {
    if(NULL == datev_import_response){
        return ;
    }
    if(datev_import_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "datev_import_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (datev_import_response->count) {
        free(datev_import_response->count);
        datev_import_response->count = NULL;
    }
    if (datev_import_response->filename) {
        free(datev_import_response->filename);
        datev_import_response->filename = NULL;
    }
    if (datev_import_response->rows) {
        list_ForEach(listEntry, datev_import_response->rows) {
            datev_import_row_free(listEntry->data);
        }
        list_freeList(datev_import_response->rows);
        datev_import_response->rows = NULL;
    }
    free(datev_import_response);
}

cJSON *datev_import_response_convertToJSON(datev_import_response_t *datev_import_response) {
    cJSON *item = cJSON_CreateObject();

    // datev_import_response->count
    if (!datev_import_response->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", *datev_import_response->count) == NULL) {
    goto fail; //Numeric
    }


    // datev_import_response->filename
    if (!datev_import_response->filename) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "filename", datev_import_response->filename) == NULL) {
    goto fail; //String
    }


    // datev_import_response->rows
    if (!datev_import_response->rows) {
        goto fail;
    }
    cJSON *rows = cJSON_AddArrayToObject(item, "rows");
    if(rows == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *rowsListEntry;
    if (datev_import_response->rows) {
    list_ForEach(rowsListEntry, datev_import_response->rows) {
    cJSON *itemLocal = datev_import_row_convertToJSON(rowsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(rows, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

datev_import_response_t *datev_import_response_parseFromJSON(cJSON *datev_import_responseJSON){

    datev_import_response_t *datev_import_response_local_var = NULL;

    // define the local variable for datev_import_response->count
    int *count_local_var = NULL;

    char *filename_local_str = NULL;

    // define the local list for datev_import_response->rows
    list_t *rowsList = NULL;

    // datev_import_response->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(datev_import_responseJSON, "count");
    if (cJSON_IsNull(count)) {
        count = NULL;
    }
    if (!count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }
    count_local_var = malloc(sizeof(int));
    if(!count_local_var)
    {
        goto end;
    }
    *count_local_var = count->valuedouble;

    // datev_import_response->filename
    cJSON *filename = cJSON_GetObjectItemCaseSensitive(datev_import_responseJSON, "filename");
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

    // datev_import_response->rows
    cJSON *rows = cJSON_GetObjectItemCaseSensitive(datev_import_responseJSON, "rows");
    if (cJSON_IsNull(rows)) {
        rows = NULL;
    }
    if (!rows) {
        goto end;
    }

    
    cJSON *rows_local_nonprimitive = NULL;
    if(!cJSON_IsArray(rows)){
        goto end; //nonprimitive container
    }

    rowsList = list_createList();

    cJSON_ArrayForEach(rows_local_nonprimitive,rows )
    {
        if(!cJSON_IsObject(rows_local_nonprimitive)){
            goto end;
        }
        datev_import_row_t *rowsItem = datev_import_row_parseFromJSON(rows_local_nonprimitive);

        list_addElement(rowsList, rowsItem);
    }


    if (filename && !cJSON_IsNull(filename)) filename_local_str = strdup(filename->valuestring);

    datev_import_response_local_var = datev_import_response_create_internal (
        count_local_var,
        filename_local_str,
        rowsList
        );

    if (!datev_import_response_local_var) {
        goto end;
    }

    return datev_import_response_local_var;
end:
    if (count_local_var) {
        free(count_local_var);
        count_local_var = NULL;
    }
    if (filename_local_str) {
        free(filename_local_str);
        filename_local_str = NULL;
    }
    if (rowsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, rowsList) {
            datev_import_row_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(rowsList);
        rowsList = NULL;
    }
    return NULL;

}
