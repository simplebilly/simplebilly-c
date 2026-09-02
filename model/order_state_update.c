#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "order_state_update.h"



static order_state_update_t *order_state_update_create_internal(
    int *send_state_to_shop,
    char *state
    ) {
    order_state_update_t *order_state_update_local_var = malloc(sizeof(order_state_update_t));
    if (!order_state_update_local_var) {
        return NULL;
    }
    memset(order_state_update_local_var, 0, sizeof(order_state_update_t));
    order_state_update_local_var->_library_owned = 1;
    order_state_update_local_var->send_state_to_shop = send_state_to_shop;
    order_state_update_local_var->state = state;
    return order_state_update_local_var;
}

__attribute__((deprecated)) order_state_update_t *order_state_update_create(
    int *send_state_to_shop,
    char *state
    ) {
    int *send_state_to_shop_copy = NULL;
    if (send_state_to_shop) {
        send_state_to_shop_copy = malloc(sizeof(int));
        if (send_state_to_shop_copy) *send_state_to_shop_copy = *send_state_to_shop;
    }
    order_state_update_t *result = order_state_update_create_internal (
        send_state_to_shop_copy,
        state
        );
    if (!result) {
        free(send_state_to_shop_copy);
    }
    return result;
}

void order_state_update_free(order_state_update_t *order_state_update) {
    if(NULL == order_state_update){
        return ;
    }
    if(order_state_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "order_state_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (order_state_update->send_state_to_shop) {
        free(order_state_update->send_state_to_shop);
        order_state_update->send_state_to_shop = NULL;
    }
    if (order_state_update->state) {
        free(order_state_update->state);
        order_state_update->state = NULL;
    }
    free(order_state_update);
}

cJSON *order_state_update_convertToJSON(order_state_update_t *order_state_update) {
    cJSON *item = cJSON_CreateObject();

    // order_state_update->send_state_to_shop
    if(order_state_update->send_state_to_shop) {
    if(cJSON_AddBoolToObject(item, "send_state_to_shop", *order_state_update->send_state_to_shop) == NULL) {
    goto fail; //Bool
    }
    }


    // order_state_update->state
    if (!order_state_update->state) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "state", order_state_update->state) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

order_state_update_t *order_state_update_parseFromJSON(cJSON *order_state_updateJSON){

    order_state_update_t *order_state_update_local_var = NULL;

    // define the local variable for order_state_update->send_state_to_shop
    int *send_state_to_shop_local_var = NULL;

    char *state_local_str = NULL;

    // order_state_update->send_state_to_shop
    cJSON *send_state_to_shop = cJSON_GetObjectItemCaseSensitive(order_state_updateJSON, "send_state_to_shop");
    if (cJSON_IsNull(send_state_to_shop)) {
        send_state_to_shop = NULL;
    }
    if (send_state_to_shop) { 
    if(!cJSON_IsBool(send_state_to_shop))
    {
    goto end; //Bool
    }
    send_state_to_shop_local_var = malloc(sizeof(int));
    if(!send_state_to_shop_local_var)
    {
        goto end;
    }
    *send_state_to_shop_local_var = send_state_to_shop->valueint;
    }

    // order_state_update->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(order_state_updateJSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    if (!state) {
        goto end;
    }

    
    if(!cJSON_IsString(state))
    {
    goto end; //String
    }


    if (state && !cJSON_IsNull(state)) state_local_str = strdup(state->valuestring);

    order_state_update_local_var = order_state_update_create_internal (
        send_state_to_shop_local_var,
        state_local_str
        );

    if (!order_state_update_local_var) {
        goto end;
    }

    return order_state_update_local_var;
end:
    if (send_state_to_shop_local_var) {
        free(send_state_to_shop_local_var);
        send_state_to_shop_local_var = NULL;
    }
    if (state_local_str) {
        free(state_local_str);
        state_local_str = NULL;
    }
    return NULL;

}
