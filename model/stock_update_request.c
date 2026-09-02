#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stock_update_request.h"



static stock_update_request_t *stock_update_request_create_internal(
    long *quantity
    ) {
    stock_update_request_t *stock_update_request_local_var = malloc(sizeof(stock_update_request_t));
    if (!stock_update_request_local_var) {
        return NULL;
    }
    memset(stock_update_request_local_var, 0, sizeof(stock_update_request_t));
    stock_update_request_local_var->_library_owned = 1;
    stock_update_request_local_var->quantity = quantity;
    return stock_update_request_local_var;
}

__attribute__((deprecated)) stock_update_request_t *stock_update_request_create(
    long *quantity
    ) {
    long *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(long));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    stock_update_request_t *result = stock_update_request_create_internal (
        quantity_copy
        );
    if (!result) {
        free(quantity_copy);
    }
    return result;
}

void stock_update_request_free(stock_update_request_t *stock_update_request) {
    if(NULL == stock_update_request){
        return ;
    }
    if(stock_update_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "stock_update_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (stock_update_request->quantity) {
        free(stock_update_request->quantity);
        stock_update_request->quantity = NULL;
    }
    free(stock_update_request);
}

cJSON *stock_update_request_convertToJSON(stock_update_request_t *stock_update_request) {
    cJSON *item = cJSON_CreateObject();

    // stock_update_request->quantity
    if (!stock_update_request->quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantity", *stock_update_request->quantity) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

stock_update_request_t *stock_update_request_parseFromJSON(cJSON *stock_update_requestJSON){

    stock_update_request_t *stock_update_request_local_var = NULL;

    // define the local variable for stock_update_request->quantity
    long *quantity_local_var = NULL;

    // stock_update_request->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(stock_update_requestJSON, "quantity");
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
    quantity_local_var = malloc(sizeof(long));
    if(!quantity_local_var)
    {
        goto end;
    }
    *quantity_local_var = quantity->valuedouble;



    stock_update_request_local_var = stock_update_request_create_internal (
        quantity_local_var
        );

    if (!stock_update_request_local_var) {
        goto end;
    }

    return stock_update_request_local_var;
end:
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    return NULL;

}
