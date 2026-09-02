#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pos_table.h"



static pos_table_t *pos_table_create_internal(
    char *current_order_number,
    char *name,
    simplebilly_api_pos_table_status__e status
    ) {
    pos_table_t *pos_table_local_var = malloc(sizeof(pos_table_t));
    if (!pos_table_local_var) {
        return NULL;
    }
    memset(pos_table_local_var, 0, sizeof(pos_table_t));
    pos_table_local_var->_library_owned = 1;
    pos_table_local_var->current_order_number = current_order_number;
    pos_table_local_var->name = name;
    pos_table_local_var->status = status;
    return pos_table_local_var;
}

__attribute__((deprecated)) pos_table_t *pos_table_create(
    char *current_order_number,
    char *name,
    simplebilly_api_pos_table_status__e status
    ) {
    pos_table_t *result = pos_table_create_internal (
        current_order_number,
        name,
        status
        );
    if (!result) {
    }
    return result;
}

void pos_table_free(pos_table_t *pos_table) {
    if(NULL == pos_table){
        return ;
    }
    if(pos_table->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "pos_table_free");
        return ;
    }
    listEntry_t *listEntry;
    if (pos_table->current_order_number) {
        free(pos_table->current_order_number);
        pos_table->current_order_number = NULL;
    }
    if (pos_table->name) {
        free(pos_table->name);
        pos_table->name = NULL;
    }
    free(pos_table);
}

cJSON *pos_table_convertToJSON(pos_table_t *pos_table) {
    cJSON *item = cJSON_CreateObject();

    // pos_table->current_order_number
    if(pos_table->current_order_number) {
    if(cJSON_AddStringToObject(item, "currentOrderNumber", pos_table->current_order_number) == NULL) {
    goto fail; //String
    }
    }


    // pos_table->name
    if (!pos_table->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", pos_table->name) == NULL) {
    goto fail; //String
    }


    // pos_table->status
    if(pos_table->status != simplebilly_api_pos_table_status__NULL) {
    cJSON *status_local_JSON = pos_table_status_convertToJSON(pos_table->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

pos_table_t *pos_table_parseFromJSON(cJSON *pos_tableJSON){

    pos_table_t *pos_table_local_var = NULL;

    char *current_order_number_local_str = NULL;

    char *name_local_str = NULL;

    // define the local variable for pos_table->status
    simplebilly_api_pos_table_status__e status_local_nonprim = 0;

    // pos_table->current_order_number
    cJSON *current_order_number = cJSON_GetObjectItemCaseSensitive(pos_tableJSON, "currentOrderNumber");
    if (cJSON_IsNull(current_order_number)) {
        current_order_number = NULL;
    }
    if (current_order_number) { 
    if(!cJSON_IsString(current_order_number) && !cJSON_IsNull(current_order_number))
    {
    goto end; //String
    }
    }

    // pos_table->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pos_tableJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // pos_table->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(pos_tableJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = pos_table_status_parseFromJSON(status); //custom
    }


    if (current_order_number && !cJSON_IsNull(current_order_number)) current_order_number_local_str = strdup(current_order_number->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    pos_table_local_var = pos_table_create_internal (
        current_order_number_local_str,
        name_local_str,
        status ? status_local_nonprim : 0
        );

    if (!pos_table_local_var) {
        goto end;
    }

    return pos_table_local_var;
end:
    if (current_order_number_local_str) {
        free(current_order_number_local_str);
        current_order_number_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (status_local_nonprim) {
        status_local_nonprim = 0;
    }
    return NULL;

}
