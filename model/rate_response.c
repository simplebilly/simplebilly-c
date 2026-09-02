#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "rate_response.h"



static rate_response_t *rate_response_create_internal(
    list_t *rates
    ) {
    rate_response_t *rate_response_local_var = malloc(sizeof(rate_response_t));
    if (!rate_response_local_var) {
        return NULL;
    }
    memset(rate_response_local_var, 0, sizeof(rate_response_t));
    rate_response_local_var->_library_owned = 1;
    rate_response_local_var->rates = rates;
    return rate_response_local_var;
}

__attribute__((deprecated)) rate_response_t *rate_response_create(
    list_t *rates
    ) {
    rate_response_t *result = rate_response_create_internal (
        rates
        );
    if (!result) {
    }
    return result;
}

void rate_response_free(rate_response_t *rate_response) {
    if(NULL == rate_response){
        return ;
    }
    if(rate_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "rate_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (rate_response->rates) {
        list_ForEach(listEntry, rate_response->rates) {
            shipping_rate_free(listEntry->data);
        }
        list_freeList(rate_response->rates);
        rate_response->rates = NULL;
    }
    free(rate_response);
}

cJSON *rate_response_convertToJSON(rate_response_t *rate_response) {
    cJSON *item = cJSON_CreateObject();

    // rate_response->rates
    if (!rate_response->rates) {
        goto fail;
    }
    cJSON *rates = cJSON_AddArrayToObject(item, "rates");
    if(rates == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ratesListEntry;
    if (rate_response->rates) {
    list_ForEach(ratesListEntry, rate_response->rates) {
    cJSON *itemLocal = shipping_rate_convertToJSON(ratesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(rates, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

rate_response_t *rate_response_parseFromJSON(cJSON *rate_responseJSON){

    rate_response_t *rate_response_local_var = NULL;

    // define the local list for rate_response->rates
    list_t *ratesList = NULL;

    // rate_response->rates
    cJSON *rates = cJSON_GetObjectItemCaseSensitive(rate_responseJSON, "rates");
    if (cJSON_IsNull(rates)) {
        rates = NULL;
    }
    if (!rates) {
        goto end;
    }

    
    cJSON *rates_local_nonprimitive = NULL;
    if(!cJSON_IsArray(rates)){
        goto end; //nonprimitive container
    }

    ratesList = list_createList();

    cJSON_ArrayForEach(rates_local_nonprimitive,rates )
    {
        if(!cJSON_IsObject(rates_local_nonprimitive)){
            goto end;
        }
        shipping_rate_t *ratesItem = shipping_rate_parseFromJSON(rates_local_nonprimitive);

        list_addElement(ratesList, ratesItem);
    }



    rate_response_local_var = rate_response_create_internal (
        ratesList
        );

    if (!rate_response_local_var) {
        goto end;
    }

    return rate_response_local_var;
end:
    if (ratesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, ratesList) {
            shipping_rate_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(ratesList);
        ratesList = NULL;
    }
    return NULL;

}
