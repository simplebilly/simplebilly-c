#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bom_update.h"



static bom_update_t *bom_update_create_internal(
    any_type_t *components,
    char *description,
    char *name,
    long *output_quantity,
    char *product_id,
    bom_status_t *status
    ) {
    bom_update_t *bom_update_local_var = malloc(sizeof(bom_update_t));
    if (!bom_update_local_var) {
        return NULL;
    }
    memset(bom_update_local_var, 0, sizeof(bom_update_t));
    bom_update_local_var->_library_owned = 1;
    bom_update_local_var->components = components;
    bom_update_local_var->description = description;
    bom_update_local_var->name = name;
    bom_update_local_var->output_quantity = output_quantity;
    bom_update_local_var->product_id = product_id;
    bom_update_local_var->status = status;
    return bom_update_local_var;
}

__attribute__((deprecated)) bom_update_t *bom_update_create(
    any_type_t *components,
    char *description,
    char *name,
    long *output_quantity,
    char *product_id,
    bom_status_t *status
    ) {
    long *output_quantity_copy = NULL;
    if (output_quantity) {
        output_quantity_copy = malloc(sizeof(long));
        if (output_quantity_copy) *output_quantity_copy = *output_quantity;
    }
    bom_update_t *result = bom_update_create_internal (
        components,
        description,
        name,
        output_quantity_copy,
        product_id,
        status
        );
    if (!result) {
        free(output_quantity_copy);
    }
    return result;
}

void bom_update_free(bom_update_t *bom_update) {
    if(NULL == bom_update){
        return ;
    }
    if(bom_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "bom_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (bom_update->components) {
        _free(bom_update->components);
        bom_update->components = NULL;
    }
    if (bom_update->description) {
        free(bom_update->description);
        bom_update->description = NULL;
    }
    if (bom_update->name) {
        free(bom_update->name);
        bom_update->name = NULL;
    }
    if (bom_update->output_quantity) {
        free(bom_update->output_quantity);
        bom_update->output_quantity = NULL;
    }
    if (bom_update->product_id) {
        free(bom_update->product_id);
        bom_update->product_id = NULL;
    }
    if (bom_update->status) {
        bom_status_free(bom_update->status);
        bom_update->status = NULL;
    }
    free(bom_update);
}

cJSON *bom_update_convertToJSON(bom_update_t *bom_update) {
    cJSON *item = cJSON_CreateObject();

    // bom_update->components
    if(bom_update->components) {
    cJSON *components_local_JSON = _convertToJSON(bom_update->components);
    if(components_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "components", components_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // bom_update->description
    if(bom_update->description) {
    if(cJSON_AddStringToObject(item, "description", bom_update->description) == NULL) {
    goto fail; //String
    }
    }


    // bom_update->name
    if(bom_update->name) {
    if(cJSON_AddStringToObject(item, "name", bom_update->name) == NULL) {
    goto fail; //String
    }
    }


    // bom_update->output_quantity
    if(bom_update->output_quantity) {
    if(cJSON_AddNumberToObject(item, "outputQuantity", *bom_update->output_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // bom_update->product_id
    if(bom_update->product_id) {
    if(cJSON_AddStringToObject(item, "productId", bom_update->product_id) == NULL) {
    goto fail; //String
    }
    }


    // bom_update->status
    if(bom_update->status) {
    cJSON *status_local_JSON = bom_status_convertToJSON(bom_update->status);
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

bom_update_t *bom_update_parseFromJSON(cJSON *bom_updateJSON){

    bom_update_t *bom_update_local_var = NULL;

    // define the local variable for bom_update->components
    _t *components_local_nonprim = NULL;

    char *description_local_str = NULL;

    char *name_local_str = NULL;

    // define the local variable for bom_update->output_quantity
    long *output_quantity_local_var = NULL;

    char *product_id_local_str = NULL;

    // define the local variable for bom_update->status
    bom_status_t *status_local_nonprim = NULL;

    // bom_update->components
    cJSON *components = cJSON_GetObjectItemCaseSensitive(bom_updateJSON, "components");
    if (cJSON_IsNull(components)) {
        components = NULL;
    }
    if (components) { 
    components_local_nonprim = _parseFromJSON(components); //custom
    }

    // bom_update->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(bom_updateJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // bom_update->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(bom_updateJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // bom_update->output_quantity
    cJSON *output_quantity = cJSON_GetObjectItemCaseSensitive(bom_updateJSON, "outputQuantity");
    if (cJSON_IsNull(output_quantity)) {
        output_quantity = NULL;
    }
    if (output_quantity) { 
    if(!cJSON_IsNumber(output_quantity))
    {
    goto end; //Numeric
    }
    output_quantity_local_var = malloc(sizeof(long));
    if(!output_quantity_local_var)
    {
        goto end;
    }
    *output_quantity_local_var = output_quantity->valuedouble;
    }

    // bom_update->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(bom_updateJSON, "productId");
    if (cJSON_IsNull(product_id)) {
        product_id = NULL;
    }
    if (product_id) { 
    if(!cJSON_IsString(product_id) && !cJSON_IsNull(product_id))
    {
    goto end; //String
    }
    }

    // bom_update->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(bom_updateJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = bom_status_parseFromJSON(status); //custom
    }


    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);

    bom_update_local_var = bom_update_create_internal (
        components ? components_local_nonprim : NULL,
        description_local_str,
        name_local_str,
        output_quantity_local_var,
        product_id_local_str,
        status ? status_local_nonprim : NULL
        );

    if (!bom_update_local_var) {
        goto end;
    }

    return bom_update_local_var;
end:
    if (components_local_nonprim) {
        _free(components_local_nonprim);
        components_local_nonprim = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (output_quantity_local_var) {
        free(output_quantity_local_var);
        output_quantity_local_var = NULL;
    }
    if (product_id_local_str) {
        free(product_id_local_str);
        product_id_local_str = NULL;
    }
    if (status_local_nonprim) {
        bom_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
