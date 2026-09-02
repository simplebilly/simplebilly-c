#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shipping_credentials.h"



static shipping_credentials_t *shipping_credentials_create_internal(
    dhl_credentials_t *dhl,
    ups_credentials_t *ups
    ) {
    shipping_credentials_t *shipping_credentials_local_var = malloc(sizeof(shipping_credentials_t));
    if (!shipping_credentials_local_var) {
        return NULL;
    }
    memset(shipping_credentials_local_var, 0, sizeof(shipping_credentials_t));
    shipping_credentials_local_var->_library_owned = 1;
    shipping_credentials_local_var->dhl = dhl;
    shipping_credentials_local_var->ups = ups;
    return shipping_credentials_local_var;
}

__attribute__((deprecated)) shipping_credentials_t *shipping_credentials_create(
    dhl_credentials_t *dhl,
    ups_credentials_t *ups
    ) {
    shipping_credentials_t *result = shipping_credentials_create_internal (
        dhl,
        ups
        );
    if (!result) {
    }
    return result;
}

void shipping_credentials_free(shipping_credentials_t *shipping_credentials) {
    if(NULL == shipping_credentials){
        return ;
    }
    if(shipping_credentials->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "shipping_credentials_free");
        return ;
    }
    listEntry_t *listEntry;
    if (shipping_credentials->dhl) {
        dhl_credentials_free(shipping_credentials->dhl);
        shipping_credentials->dhl = NULL;
    }
    if (shipping_credentials->ups) {
        ups_credentials_free(shipping_credentials->ups);
        shipping_credentials->ups = NULL;
    }
    free(shipping_credentials);
}

cJSON *shipping_credentials_convertToJSON(shipping_credentials_t *shipping_credentials) {
    cJSON *item = cJSON_CreateObject();

    // shipping_credentials->dhl
    if(shipping_credentials->dhl) {
    cJSON *dhl_local_JSON = dhl_credentials_convertToJSON(shipping_credentials->dhl);
    if(dhl_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "dhl", dhl_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // shipping_credentials->ups
    if(shipping_credentials->ups) {
    cJSON *ups_local_JSON = ups_credentials_convertToJSON(shipping_credentials->ups);
    if(ups_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ups", ups_local_JSON);
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

shipping_credentials_t *shipping_credentials_parseFromJSON(cJSON *shipping_credentialsJSON){

    shipping_credentials_t *shipping_credentials_local_var = NULL;

    // define the local variable for shipping_credentials->dhl
    dhl_credentials_t *dhl_local_nonprim = NULL;

    // define the local variable for shipping_credentials->ups
    ups_credentials_t *ups_local_nonprim = NULL;

    // shipping_credentials->dhl
    cJSON *dhl = cJSON_GetObjectItemCaseSensitive(shipping_credentialsJSON, "dhl");
    if (cJSON_IsNull(dhl)) {
        dhl = NULL;
    }
    if (dhl) { 
    dhl_local_nonprim = dhl_credentials_parseFromJSON(dhl); //nonprimitive
    }

    // shipping_credentials->ups
    cJSON *ups = cJSON_GetObjectItemCaseSensitive(shipping_credentialsJSON, "ups");
    if (cJSON_IsNull(ups)) {
        ups = NULL;
    }
    if (ups) { 
    ups_local_nonprim = ups_credentials_parseFromJSON(ups); //nonprimitive
    }



    shipping_credentials_local_var = shipping_credentials_create_internal (
        dhl ? dhl_local_nonprim : NULL,
        ups ? ups_local_nonprim : NULL
        );

    if (!shipping_credentials_local_var) {
        goto end;
    }

    return shipping_credentials_local_var;
end:
    if (dhl_local_nonprim) {
        dhl_credentials_free(dhl_local_nonprim);
        dhl_local_nonprim = NULL;
    }
    if (ups_local_nonprim) {
        ups_credentials_free(ups_local_nonprim);
        ups_local_nonprim = NULL;
    }
    return NULL;

}
