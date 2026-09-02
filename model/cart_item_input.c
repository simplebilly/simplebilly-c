#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cart_item_input.h"



static cart_item_input_t *cart_item_input_create_internal(
    char *product_id,
    int *quantity
    ) {
    cart_item_input_t *cart_item_input_local_var = malloc(sizeof(cart_item_input_t));
    if (!cart_item_input_local_var) {
        return NULL;
    }
    memset(cart_item_input_local_var, 0, sizeof(cart_item_input_t));
    cart_item_input_local_var->_library_owned = 1;
    cart_item_input_local_var->product_id = product_id;
    cart_item_input_local_var->quantity = quantity;
    return cart_item_input_local_var;
}

__attribute__((deprecated)) cart_item_input_t *cart_item_input_create(
    char *product_id,
    int *quantity
    ) {
    int *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(int));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    cart_item_input_t *result = cart_item_input_create_internal (
        product_id,
        quantity_copy
        );
    if (!result) {
        free(quantity_copy);
    }
    return result;
}

void cart_item_input_free(cart_item_input_t *cart_item_input) {
    if(NULL == cart_item_input){
        return ;
    }
    if(cart_item_input->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cart_item_input_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cart_item_input->product_id) {
        free(cart_item_input->product_id);
        cart_item_input->product_id = NULL;
    }
    if (cart_item_input->quantity) {
        free(cart_item_input->quantity);
        cart_item_input->quantity = NULL;
    }
    free(cart_item_input);
}

cJSON *cart_item_input_convertToJSON(cart_item_input_t *cart_item_input) {
    cJSON *item = cJSON_CreateObject();

    // cart_item_input->product_id
    if (!cart_item_input->product_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "product_id", cart_item_input->product_id) == NULL) {
    goto fail; //String
    }


    // cart_item_input->quantity
    if (!cart_item_input->quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantity", *cart_item_input->quantity) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cart_item_input_t *cart_item_input_parseFromJSON(cJSON *cart_item_inputJSON){

    cart_item_input_t *cart_item_input_local_var = NULL;

    char *product_id_local_str = NULL;

    // define the local variable for cart_item_input->quantity
    int *quantity_local_var = NULL;

    // cart_item_input->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(cart_item_inputJSON, "product_id");
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

    // cart_item_input->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(cart_item_inputJSON, "quantity");
    if (cJSON_IsNull(quantity)) {
        quantity = NULL;
    }
    if (!quantity) {
        goto end;
    }

    
    if(!cJSON_IsNumber(quantity))
    {
    goto end; //Numeric
    }
    quantity_local_var = malloc(sizeof(int));
    if(!quantity_local_var)
    {
        goto end;
    }
    *quantity_local_var = quantity->valuedouble;


    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);

    cart_item_input_local_var = cart_item_input_create_internal (
        product_id_local_str,
        quantity_local_var
        );

    if (!cart_item_input_local_var) {
        goto end;
    }

    return cart_item_input_local_var;
end:
    if (product_id_local_str) {
        free(product_id_local_str);
        product_id_local_str = NULL;
    }
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    return NULL;

}
