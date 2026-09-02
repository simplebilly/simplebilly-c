#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "product_category_create.h"



static product_category_create_t *product_category_create_create_internal(
    char *description,
    char *name,
    char *parent_category_id,
    int *sort_order
    ) {
    product_category_create_t *product_category_create_local_var = malloc(sizeof(product_category_create_t));
    if (!product_category_create_local_var) {
        return NULL;
    }
    memset(product_category_create_local_var, 0, sizeof(product_category_create_t));
    product_category_create_local_var->_library_owned = 1;
    product_category_create_local_var->description = description;
    product_category_create_local_var->name = name;
    product_category_create_local_var->parent_category_id = parent_category_id;
    product_category_create_local_var->sort_order = sort_order;
    return product_category_create_local_var;
}

__attribute__((deprecated)) product_category_create_t *product_category_create_create(
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
    product_category_create_t *result = product_category_create_create_internal (
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

void product_category_create_free(product_category_create_t *product_category_create) {
    if(NULL == product_category_create){
        return ;
    }
    if(product_category_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "product_category_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (product_category_create->description) {
        free(product_category_create->description);
        product_category_create->description = NULL;
    }
    if (product_category_create->name) {
        free(product_category_create->name);
        product_category_create->name = NULL;
    }
    if (product_category_create->parent_category_id) {
        free(product_category_create->parent_category_id);
        product_category_create->parent_category_id = NULL;
    }
    if (product_category_create->sort_order) {
        free(product_category_create->sort_order);
        product_category_create->sort_order = NULL;
    }
    free(product_category_create);
}

cJSON *product_category_create_convertToJSON(product_category_create_t *product_category_create) {
    cJSON *item = cJSON_CreateObject();

    // product_category_create->description
    if(product_category_create->description) {
    if(cJSON_AddStringToObject(item, "description", product_category_create->description) == NULL) {
    goto fail; //String
    }
    }


    // product_category_create->name
    if (!product_category_create->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", product_category_create->name) == NULL) {
    goto fail; //String
    }


    // product_category_create->parent_category_id
    if(product_category_create->parent_category_id) {
    if(cJSON_AddStringToObject(item, "parentCategoryId", product_category_create->parent_category_id) == NULL) {
    goto fail; //String
    }
    }


    // product_category_create->sort_order
    if (!product_category_create->sort_order) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "sortOrder", *product_category_create->sort_order) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

product_category_create_t *product_category_create_parseFromJSON(cJSON *product_category_createJSON){

    product_category_create_t *product_category_create_local_var = NULL;

    char *description_local_str = NULL;

    char *name_local_str = NULL;

    char *parent_category_id_local_str = NULL;

    // define the local variable for product_category_create->sort_order
    int *sort_order_local_var = NULL;

    // product_category_create->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(product_category_createJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // product_category_create->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(product_category_createJSON, "name");
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

    // product_category_create->parent_category_id
    cJSON *parent_category_id = cJSON_GetObjectItemCaseSensitive(product_category_createJSON, "parentCategoryId");
    if (cJSON_IsNull(parent_category_id)) {
        parent_category_id = NULL;
    }
    if (parent_category_id) { 
    if(!cJSON_IsString(parent_category_id) && !cJSON_IsNull(parent_category_id))
    {
    goto end; //String
    }
    }

    // product_category_create->sort_order
    cJSON *sort_order = cJSON_GetObjectItemCaseSensitive(product_category_createJSON, "sortOrder");
    if (cJSON_IsNull(sort_order)) {
        sort_order = NULL;
    }
    if (!sort_order) {
        goto end;
    }

    
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


    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (parent_category_id && !cJSON_IsNull(parent_category_id)) parent_category_id_local_str = strdup(parent_category_id->valuestring);

    product_category_create_local_var = product_category_create_create_internal (
        description_local_str,
        name_local_str,
        parent_category_id_local_str,
        sort_order_local_var
        );

    if (!product_category_create_local_var) {
        goto end;
    }

    return product_category_create_local_var;
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
