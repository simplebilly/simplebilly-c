#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "product_attribute_create.h"



static product_attribute_create_t *product_attribute_create_create_internal(
    int *is_filterable,
    char *name,
    int *position,
    char *product_id,
    char *unit,
    char *value
    ) {
    product_attribute_create_t *product_attribute_create_local_var = malloc(sizeof(product_attribute_create_t));
    if (!product_attribute_create_local_var) {
        return NULL;
    }
    memset(product_attribute_create_local_var, 0, sizeof(product_attribute_create_t));
    product_attribute_create_local_var->_library_owned = 1;
    product_attribute_create_local_var->is_filterable = is_filterable;
    product_attribute_create_local_var->name = name;
    product_attribute_create_local_var->position = position;
    product_attribute_create_local_var->product_id = product_id;
    product_attribute_create_local_var->unit = unit;
    product_attribute_create_local_var->value = value;
    return product_attribute_create_local_var;
}

__attribute__((deprecated)) product_attribute_create_t *product_attribute_create_create(
    int *is_filterable,
    char *name,
    int *position,
    char *product_id,
    char *unit,
    char *value
    ) {
    int *is_filterable_copy = NULL;
    if (is_filterable) {
        is_filterable_copy = malloc(sizeof(int));
        if (is_filterable_copy) *is_filterable_copy = *is_filterable;
    }
    int *position_copy = NULL;
    if (position) {
        position_copy = malloc(sizeof(int));
        if (position_copy) *position_copy = *position;
    }
    product_attribute_create_t *result = product_attribute_create_create_internal (
        is_filterable_copy,
        name,
        position_copy,
        product_id,
        unit,
        value
        );
    if (!result) {
        free(is_filterable_copy);
        free(position_copy);
    }
    return result;
}

void product_attribute_create_free(product_attribute_create_t *product_attribute_create) {
    if(NULL == product_attribute_create){
        return ;
    }
    if(product_attribute_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "product_attribute_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (product_attribute_create->is_filterable) {
        free(product_attribute_create->is_filterable);
        product_attribute_create->is_filterable = NULL;
    }
    if (product_attribute_create->name) {
        free(product_attribute_create->name);
        product_attribute_create->name = NULL;
    }
    if (product_attribute_create->position) {
        free(product_attribute_create->position);
        product_attribute_create->position = NULL;
    }
    if (product_attribute_create->product_id) {
        free(product_attribute_create->product_id);
        product_attribute_create->product_id = NULL;
    }
    if (product_attribute_create->unit) {
        free(product_attribute_create->unit);
        product_attribute_create->unit = NULL;
    }
    if (product_attribute_create->value) {
        free(product_attribute_create->value);
        product_attribute_create->value = NULL;
    }
    free(product_attribute_create);
}

cJSON *product_attribute_create_convertToJSON(product_attribute_create_t *product_attribute_create) {
    cJSON *item = cJSON_CreateObject();

    // product_attribute_create->is_filterable
    if(product_attribute_create->is_filterable) {
    if(cJSON_AddBoolToObject(item, "isFilterable", *product_attribute_create->is_filterable) == NULL) {
    goto fail; //Bool
    }
    }


    // product_attribute_create->name
    if (!product_attribute_create->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", product_attribute_create->name) == NULL) {
    goto fail; //String
    }


    // product_attribute_create->position
    if(product_attribute_create->position) {
    if(cJSON_AddNumberToObject(item, "position", *product_attribute_create->position) == NULL) {
    goto fail; //Numeric
    }
    }


    // product_attribute_create->product_id
    if (!product_attribute_create->product_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productId", product_attribute_create->product_id) == NULL) {
    goto fail; //String
    }


    // product_attribute_create->unit
    if(product_attribute_create->unit) {
    if(cJSON_AddStringToObject(item, "unit", product_attribute_create->unit) == NULL) {
    goto fail; //String
    }
    }


    // product_attribute_create->value
    if (!product_attribute_create->value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "value", product_attribute_create->value) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

product_attribute_create_t *product_attribute_create_parseFromJSON(cJSON *product_attribute_createJSON){

    product_attribute_create_t *product_attribute_create_local_var = NULL;

    // define the local variable for product_attribute_create->is_filterable
    int *is_filterable_local_var = NULL;

    char *name_local_str = NULL;

    // define the local variable for product_attribute_create->position
    int *position_local_var = NULL;

    char *product_id_local_str = NULL;

    char *unit_local_str = NULL;

    char *value_local_str = NULL;

    // product_attribute_create->is_filterable
    cJSON *is_filterable = cJSON_GetObjectItemCaseSensitive(product_attribute_createJSON, "isFilterable");
    if (cJSON_IsNull(is_filterable)) {
        is_filterable = NULL;
    }
    if (is_filterable) { 
    if(!cJSON_IsBool(is_filterable))
    {
    goto end; //Bool
    }
    is_filterable_local_var = malloc(sizeof(int));
    if(!is_filterable_local_var)
    {
        goto end;
    }
    *is_filterable_local_var = is_filterable->valueint;
    }

    // product_attribute_create->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(product_attribute_createJSON, "name");
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

    // product_attribute_create->position
    cJSON *position = cJSON_GetObjectItemCaseSensitive(product_attribute_createJSON, "position");
    if (cJSON_IsNull(position)) {
        position = NULL;
    }
    if (position) { 
    if(!cJSON_IsNumber(position))
    {
    goto end; //Numeric
    }
    position_local_var = malloc(sizeof(int));
    if(!position_local_var)
    {
        goto end;
    }
    *position_local_var = position->valuedouble;
    }

    // product_attribute_create->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(product_attribute_createJSON, "productId");
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

    // product_attribute_create->unit
    cJSON *unit = cJSON_GetObjectItemCaseSensitive(product_attribute_createJSON, "unit");
    if (cJSON_IsNull(unit)) {
        unit = NULL;
    }
    if (unit) { 
    if(!cJSON_IsString(unit) && !cJSON_IsNull(unit))
    {
    goto end; //String
    }
    }

    // product_attribute_create->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(product_attribute_createJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (!value) {
        goto end;
    }

    
    if(!cJSON_IsString(value))
    {
    goto end; //String
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);
    if (unit && !cJSON_IsNull(unit)) unit_local_str = strdup(unit->valuestring);
    if (value && !cJSON_IsNull(value)) value_local_str = strdup(value->valuestring);

    product_attribute_create_local_var = product_attribute_create_create_internal (
        is_filterable_local_var,
        name_local_str,
        position_local_var,
        product_id_local_str,
        unit_local_str,
        value_local_str
        );

    if (!product_attribute_create_local_var) {
        goto end;
    }

    return product_attribute_create_local_var;
end:
    if (is_filterable_local_var) {
        free(is_filterable_local_var);
        is_filterable_local_var = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (position_local_var) {
        free(position_local_var);
        position_local_var = NULL;
    }
    if (product_id_local_str) {
        free(product_id_local_str);
        product_id_local_str = NULL;
    }
    if (unit_local_str) {
        free(unit_local_str);
        unit_local_str = NULL;
    }
    if (value_local_str) {
        free(value_local_str);
        value_local_str = NULL;
    }
    return NULL;

}
