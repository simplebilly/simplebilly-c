#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "product_category_update.h"



static product_category_update_t *product_category_update_create_internal(
    char *description,
    char *name,
    char *parent_category_id,
    int *sort_order
    ) {
    product_category_update_t *product_category_update_local_var = malloc(sizeof(product_category_update_t));
    if (!product_category_update_local_var) {
        return NULL;
    }
    memset(product_category_update_local_var, 0, sizeof(product_category_update_t));
    product_category_update_local_var->_library_owned = 1;
    product_category_update_local_var->description = description;
    product_category_update_local_var->name = name;
    product_category_update_local_var->parent_category_id = parent_category_id;
    product_category_update_local_var->sort_order = sort_order;
    return product_category_update_local_var;
}

__attribute__((deprecated)) product_category_update_t *product_category_update_create(
    char *description,
    char *name,
    char *parent_category_id,
    int *sort_order
    ) {
    int *sort_order_copy = NULL;
    if (sort_order) {
        sort_order_copy = malloc(sizeof(int));
        if (sort_order_copy) *sort_order_copy = *sort_order;
    }
    product_category_update_t *result = product_category_update_create_internal (
        description,
        name,
        parent_category_id,
        sort_order_copy
        );
    if (!result) {
        free(sort_order_copy);
    }
    return result;
}

void product_category_update_free(product_category_update_t *product_category_update) {
    if(NULL == product_category_update){
        return ;
    }
    if(product_category_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "product_category_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (product_category_update->description) {
        free(product_category_update->description);
        product_category_update->description = NULL;
    }
    if (product_category_update->name) {
        free(product_category_update->name);
        product_category_update->name = NULL;
    }
    if (product_category_update->parent_category_id) {
        free(product_category_update->parent_category_id);
        product_category_update->parent_category_id = NULL;
    }
    if (product_category_update->sort_order) {
        free(product_category_update->sort_order);
        product_category_update->sort_order = NULL;
    }
    free(product_category_update);
}

cJSON *product_category_update_convertToJSON(product_category_update_t *product_category_update) {
    cJSON *item = cJSON_CreateObject();

    // product_category_update->description
    if(product_category_update->description) {
    if(cJSON_AddStringToObject(item, "description", product_category_update->description) == NULL) {
    goto fail; //String
    }
    }


    // product_category_update->name
    if(product_category_update->name) {
    if(cJSON_AddStringToObject(item, "name", product_category_update->name) == NULL) {
    goto fail; //String
    }
    }


    // product_category_update->parent_category_id
    if(product_category_update->parent_category_id) {
    if(cJSON_AddStringToObject(item, "parentCategoryId", product_category_update->parent_category_id) == NULL) {
    goto fail; //String
    }
    }


    // product_category_update->sort_order
    if(product_category_update->sort_order) {
    if(cJSON_AddNumberToObject(item, "sortOrder", *product_category_update->sort_order) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

product_category_update_t *product_category_update_parseFromJSON(cJSON *product_category_updateJSON){

    product_category_update_t *product_category_update_local_var = NULL;

    char *description_local_str = NULL;

    char *name_local_str = NULL;

    char *parent_category_id_local_str = NULL;

    // define the local variable for product_category_update->sort_order
    int *sort_order_local_var = NULL;

    // product_category_update->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(product_category_updateJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // product_category_update->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(product_category_updateJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // product_category_update->parent_category_id
    cJSON *parent_category_id = cJSON_GetObjectItemCaseSensitive(product_category_updateJSON, "parentCategoryId");
    if (cJSON_IsNull(parent_category_id)) {
        parent_category_id = NULL;
    }
    if (parent_category_id) { 
    if(!cJSON_IsString(parent_category_id) && !cJSON_IsNull(parent_category_id))
    {
    goto end; //String
    }
    }

    // product_category_update->sort_order
    cJSON *sort_order = cJSON_GetObjectItemCaseSensitive(product_category_updateJSON, "sortOrder");
    if (cJSON_IsNull(sort_order)) {
        sort_order = NULL;
    }
    if (sort_order) { 
    if(!cJSON_IsNumber(sort_order))
    {
    goto end; //Numeric
    }
    sort_order_local_var = malloc(sizeof(int));
    if(!sort_order_local_var)
    {
        goto end;
    }
    *sort_order_local_var = sort_order->valuedouble;
    }


    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (parent_category_id && !cJSON_IsNull(parent_category_id)) parent_category_id_local_str = strdup(parent_category_id->valuestring);

    product_category_update_local_var = product_category_update_create_internal (
        description_local_str,
        name_local_str,
        parent_category_id_local_str,
        sort_order_local_var
        );

    if (!product_category_update_local_var) {
        goto end;
    }

    return product_category_update_local_var;
end:
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (parent_category_id_local_str) {
        free(parent_category_id_local_str);
        parent_category_id_local_str = NULL;
    }
    if (sort_order_local_var) {
        free(sort_order_local_var);
        sort_order_local_var = NULL;
    }
    return NULL;

}
