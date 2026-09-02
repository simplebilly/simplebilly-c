#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bom.h"



static bom_t *bom_create_internal(
    any_type_t *components,
    char *description,
    char *name,
    long *output_quantity,
    char *product_id,
    bom_status_t *status
    ) {
    bom_t *bom_local_var = malloc(sizeof(bom_t));
    if (!bom_local_var) {
        return NULL;
    }
    memset(bom_local_var, 0, sizeof(bom_t));
    bom_local_var->_library_owned = 1;
    bom_local_var->components = components;
    bom_local_var->description = description;
    bom_local_var->name = name;
    bom_local_var->output_quantity = output_quantity;
    bom_local_var->product_id = product_id;
    bom_local_var->status = status;
    return bom_local_var;
}

__attribute__((deprecated)) bom_t *bom_create(
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
    bom_t *result = bom_create_internal (
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

void bom_free(bom_t *bom) {
    if(NULL == bom){
        return ;
    }
    if(bom->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "bom_free");
        return ;
    }
    listEntry_t *listEntry;
    if (bom->components) {
        _free(bom->components);
        bom->components = NULL;
    }
    if (bom->description) {
        free(bom->description);
        bom->description = NULL;
    }
    if (bom->name) {
        free(bom->name);
        bom->name = NULL;
    }
    if (bom->output_quantity) {
        free(bom->output_quantity);
        bom->output_quantity = NULL;
    }
    if (bom->product_id) {
        free(bom->product_id);
        bom->product_id = NULL;
    }
    if (bom->status) {
        bom_status_free(bom->status);
        bom->status = NULL;
    }
    free(bom);
}

cJSON *bom_convertToJSON(bom_t *bom) {
    cJSON *item = cJSON_CreateObject();

    // bom->components
    if(bom->components) {
    cJSON *components_local_JSON = _convertToJSON(bom->components);
    if(components_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "components", components_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // bom->description
    if(bom->description) {
    if(cJSON_AddStringToObject(item, "description", bom->description) == NULL) {
    goto fail; //String
    }
    }


    // bom->name
    if (!bom->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", bom->name) == NULL) {
    goto fail; //String
    }


    // bom->output_quantity
    if(bom->output_quantity) {
    if(cJSON_AddNumberToObject(item, "outputQuantity", *bom->output_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // bom->product_id
    if (!bom->product_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productId", bom->product_id) == NULL) {
    goto fail; //String
    }


    // bom->status
    if(bom->status) {
    cJSON *status_local_JSON = bom_status_convertToJSON(bom->status);
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

bom_t *bom_parseFromJSON(cJSON *bomJSON){

    bom_t *bom_local_var = NULL;

    // define the local variable for bom->components
    _t *components_local_nonprim = NULL;

    char *description_local_str = NULL;

    char *name_local_str = NULL;

    // define the local variable for bom->output_quantity
    long *output_quantity_local_var = NULL;

    char *product_id_local_str = NULL;

    // define the local variable for bom->status
    bom_status_t *status_local_nonprim = NULL;

    // bom->components
    cJSON *components = cJSON_GetObjectItemCaseSensitive(bomJSON, "components");
    if (cJSON_IsNull(components)) {
        components = NULL;
    }
    if (components) { 
    components_local_nonprim = _parseFromJSON(components); //custom
    }

    // bom->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(bomJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // bom->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(bomJSON, "name");
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

    // bom->output_quantity
    cJSON *output_quantity = cJSON_GetObjectItemCaseSensitive(bomJSON, "outputQuantity");
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

    // bom->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(bomJSON, "productId");
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

    // bom->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(bomJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = bom_status_parseFromJSON(status); //custom
    }


    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);

    bom_local_var = bom_create_internal (
        components ? components_local_nonprim : NULL,
        description_local_str,
        name_local_str,
        output_quantity_local_var,
        product_id_local_str,
        status ? status_local_nonprim : NULL
        );

    if (!bom_local_var) {
        goto end;
    }

    return bom_local_var;
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
