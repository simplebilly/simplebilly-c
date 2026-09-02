#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "generate_variants_request.h"



static generate_variants_request_t *generate_variants_request_create_internal(
    list_t* options,
    char *price_delta,
    char *product_id,
    char *sku_prefix
    ) {
    generate_variants_request_t *generate_variants_request_local_var = malloc(sizeof(generate_variants_request_t));
    if (!generate_variants_request_local_var) {
        return NULL;
    }
    memset(generate_variants_request_local_var, 0, sizeof(generate_variants_request_t));
    generate_variants_request_local_var->_library_owned = 1;
    generate_variants_request_local_var->options = options;
    generate_variants_request_local_var->price_delta = price_delta;
    generate_variants_request_local_var->product_id = product_id;
    generate_variants_request_local_var->sku_prefix = sku_prefix;
    return generate_variants_request_local_var;
}

__attribute__((deprecated)) generate_variants_request_t *generate_variants_request_create(
    list_t* options,
    char *price_delta,
    char *product_id,
    char *sku_prefix
    ) {
    generate_variants_request_t *result = generate_variants_request_create_internal (
        options,
        price_delta,
        product_id,
        sku_prefix
        );
    if (!result) {
    }
    return result;
}

void generate_variants_request_free(generate_variants_request_t *generate_variants_request) {
    if(NULL == generate_variants_request){
        return ;
    }
    if(generate_variants_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "generate_variants_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (generate_variants_request->options) {
        list_ForEach(listEntry, generate_variants_request->options) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(generate_variants_request->options);
        generate_variants_request->options = NULL;
    }
    if (generate_variants_request->price_delta) {
        free(generate_variants_request->price_delta);
        generate_variants_request->price_delta = NULL;
    }
    if (generate_variants_request->product_id) {
        free(generate_variants_request->product_id);
        generate_variants_request->product_id = NULL;
    }
    if (generate_variants_request->sku_prefix) {
        free(generate_variants_request->sku_prefix);
        generate_variants_request->sku_prefix = NULL;
    }
    free(generate_variants_request);
}

cJSON *generate_variants_request_convertToJSON(generate_variants_request_t *generate_variants_request) {
    cJSON *item = cJSON_CreateObject();

    // generate_variants_request->options
    if(generate_variants_request->options) {
    cJSON *options = cJSON_AddObjectToObject(item, "options");
    if(options == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = options;
    listEntry_t *optionsListEntry;
    if (generate_variants_request->options) {
    list_ForEach(optionsListEntry, generate_variants_request->options) {
        keyValuePair_t *localKeyValue = optionsListEntry->data;
    }
    }
    }


    // generate_variants_request->price_delta
    if(generate_variants_request->price_delta) {
    if(cJSON_AddStringToObject(item, "priceDelta", generate_variants_request->price_delta) == NULL) {
    goto fail; //String
    }
    }


    // generate_variants_request->product_id
    if (!generate_variants_request->product_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productId", generate_variants_request->product_id) == NULL) {
    goto fail; //String
    }


    // generate_variants_request->sku_prefix
    if(generate_variants_request->sku_prefix) {
    if(cJSON_AddStringToObject(item, "skuPrefix", generate_variants_request->sku_prefix) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

generate_variants_request_t *generate_variants_request_parseFromJSON(cJSON *generate_variants_requestJSON){

    generate_variants_request_t *generate_variants_request_local_var = NULL;

    // define the local map for generate_variants_request->options
    list_t *optionsList = NULL;

    char *price_delta_local_str = NULL;

    char *product_id_local_str = NULL;

    char *sku_prefix_local_str = NULL;

    // generate_variants_request->options
    cJSON *options = cJSON_GetObjectItemCaseSensitive(generate_variants_requestJSON, "options");
    if (cJSON_IsNull(options)) {
        options = NULL;
    }
    if (options) { 
    cJSON *options_local_map = NULL;
    if(!cJSON_IsObject(options) && !cJSON_IsNull(options))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(options))
    {
        optionsList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(options_local_map, options)
        {
            cJSON *localMapObject = options_local_map;
            list_addElement(optionsList , localMapKeyPair);
        }
    }
    }

    // generate_variants_request->price_delta
    cJSON *price_delta = cJSON_GetObjectItemCaseSensitive(generate_variants_requestJSON, "priceDelta");
    if (cJSON_IsNull(price_delta)) {
        price_delta = NULL;
    }
    if (price_delta) { 
    if(!cJSON_IsString(price_delta) && !cJSON_IsNull(price_delta))
    {
    goto end; //String
    }
    }

    // generate_variants_request->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(generate_variants_requestJSON, "productId");
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

    // generate_variants_request->sku_prefix
    cJSON *sku_prefix = cJSON_GetObjectItemCaseSensitive(generate_variants_requestJSON, "skuPrefix");
    if (cJSON_IsNull(sku_prefix)) {
        sku_prefix = NULL;
    }
    if (sku_prefix) { 
    if(!cJSON_IsString(sku_prefix) && !cJSON_IsNull(sku_prefix))
    {
    goto end; //String
    }
    }


    if (price_delta && !cJSON_IsNull(price_delta)) price_delta_local_str = strdup(price_delta->valuestring);
    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);
    if (sku_prefix && !cJSON_IsNull(sku_prefix)) sku_prefix_local_str = strdup(sku_prefix->valuestring);

    generate_variants_request_local_var = generate_variants_request_create_internal (
        options ? optionsList : NULL,
        price_delta_local_str,
        product_id_local_str,
        sku_prefix_local_str
        );

    if (!generate_variants_request_local_var) {
        goto end;
    }

    return generate_variants_request_local_var;
end:
    if (optionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, optionsList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(optionsList);
        optionsList = NULL;
    }
    if (price_delta_local_str) {
        free(price_delta_local_str);
        price_delta_local_str = NULL;
    }
    if (product_id_local_str) {
        free(product_id_local_str);
        product_id_local_str = NULL;
    }
    if (sku_prefix_local_str) {
        free(sku_prefix_local_str);
        sku_prefix_local_str = NULL;
    }
    return NULL;

}
