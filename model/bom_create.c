#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bom_create.h"



static bom_create_t *bom_create_create_internal(
    any_type_t *components,
    char *description,
    char *name,
    long *output_quantity,
    char *product_id,
    bom_status_t *status
    ) {
    bom_create_t *bom_create_local_var = malloc(sizeof(bom_create_t));
    if (!bom_create_local_var) {
        return NULL;
    }
    memset(bom_create_local_var, 0, sizeof(bom_create_t));
    bom_create_local_var->_library_owned = 1;
    bom_create_local_var->components = components;
    bom_create_local_var->description = description;
    bom_create_local_var->name = name;
    bom_create_local_var->output_quantity = output_quantity;
    bom_create_local_var->product_id = product_id;
    bom_create_local_var->status = status;
    return bom_create_local_var;
}

__attribute__((deprecated)) bom_create_t *bom_create_create(
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
    bom_create_t *result = bom_create_create_internal (
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

void bom_create_free(bom_create_t *bom_create) {
    if(NULL == bom_create){
        return ;
    }
    if(bom_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "bom_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (bom_create->components) {
        _free(bom_create->components);
        bom_create->components = NULL;
    }
    if (bom_create->description) {
        free(bom_create->description);
        bom_create->description = NULL;
    }
    if (bom_create->name) {
        free(bom_create->name);
        bom_create->name = NULL;
    }
    if (bom_create->output_quantity) {
        free(bom_create->output_quantity);
        bom_create->output_quantity = NULL;
    }
    if (bom_create->product_id) {
        free(bom_create->product_id);
        bom_create->product_id = NULL;
    }
    if (bom_create->status) {
        bom_status_free(bom_create->status);
        bom_create->status = NULL;
    }
    free(bom_create);
}

cJSON *bom_create_convertToJSON(bom_create_t *bom_create) {
    cJSON *item = cJSON_CreateObject();

    // bom_create->components
    if(bom_create->components) {
    cJSON *components_local_JSON = _convertToJSON(bom_create->components);
    if(components_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "components", components_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // bom_create->description
    if(bom_create->description) {
    if(cJSON_AddStringToObject(item, "description", bom_create->description) == NULL) {
    goto fail; //String
    }
    }


    // bom_create->name
    if (!bom_create->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", bom_create->name) == NULL) {
    goto fail; //String
    }


    // bom_create->output_quantity
    if(bom_create->output_quantity) {
    if(cJSON_AddNumberToObject(item, "outputQuantity", *bom_create->output_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // bom_create->product_id
    if (!bom_create->product_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productId", bom_create->product_id) == NULL) {
    goto fail; //String
    }


    // bom_create->status
    if(bom_create->status) {
    cJSON *status_local_JSON = bom_status_convertToJSON(bom_create->status);
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

bom_create_t *bom_create_parseFromJSON(cJSON *bom_createJSON){

    bom_create_t *bom_create_local_var = NULL;

    // define the local variable for bom_create->components
    _t *components_local_nonprim = NULL;

    char *description_local_str = NULL;

    char *name_local_str = NULL;

    // define the local variable for bom_create->output_quantity
    long *output_quantity_local_var = NULL;

    char *product_id_local_str = NULL;

    // define the local variable for bom_create->status
    bom_status_t *status_local_nonprim = NULL;

    // bom_create->components
    cJSON *components = cJSON_GetObjectItemCaseSensitive(bom_createJSON, "components");
    if (cJSON_IsNull(components)) {
        components = NULL;
    }
    if (components) { 
    components_local_nonprim = _parseFromJSON(components); //custom
    }

    // bom_create->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(bom_createJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // bom_create->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(bom_createJSON, "name");
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

    // bom_create->output_quantity
    cJSON *output_quantity = cJSON_GetObjectItemCaseSensitive(bom_createJSON, "outputQuantity");
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

    // bom_create->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(bom_createJSON, "productId");
    if (cJSON_IsNull(product_id)) {
        product_id = NULL;
    }
    if (!product_id) {
        goto end;
    }

    
    if(!cJSON_IsString(product_id))
    {
    goto end; //String
    }

    // bom_create->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(bom_createJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = bom_status_parseFromJSON(status); //custom
    }


    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);

    bom_create_local_var = bom_create_create_internal (
        components ? components_local_nonprim : NULL,
        description_local_str,
        name_local_str,
        output_quantity_local_var,
        product_id_local_str,
        status ? status_local_nonprim : NULL
        );

    if (!bom_create_local_var) {
        goto end;
    }

    return bom_create_local_var;
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
