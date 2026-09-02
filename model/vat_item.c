#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vat_item.h"



static vat_item_t *vat_item_create_internal(
    char *net_amount,
    char *tax_amount,
    char *tax_rate
    ) {
    vat_item_t *vat_item_local_var = malloc(sizeof(vat_item_t));
    if (!vat_item_local_var) {
        return NULL;
    }
    memset(vat_item_local_var, 0, sizeof(vat_item_t));
    vat_item_local_var->_library_owned = 1;
    vat_item_local_var->net_amount = net_amount;
    vat_item_local_var->tax_amount = tax_amount;
    vat_item_local_var->tax_rate = tax_rate;
    return vat_item_local_var;
}

__attribute__((deprecated)) vat_item_t *vat_item_create(
    char *net_amount,
    char *tax_amount,
    char *tax_rate
    ) {
    vat_item_t *result = vat_item_create_internal (
        net_amount,
        tax_amount,
        tax_rate
        );
    if (!result) {
    }
    return result;
}

void vat_item_free(vat_item_t *vat_item) {
    if(NULL == vat_item){
        return ;
    }
    if(vat_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "vat_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (vat_item->net_amount) {
        free(vat_item->net_amount);
        vat_item->net_amount = NULL;
    }
    if (vat_item->tax_amount) {
        free(vat_item->tax_amount);
        vat_item->tax_amount = NULL;
    }
    if (vat_item->tax_rate) {
        free(vat_item->tax_rate);
        vat_item->tax_rate = NULL;
    }
    free(vat_item);
}

cJSON *vat_item_convertToJSON(vat_item_t *vat_item) {
    cJSON *item = cJSON_CreateObject();

    // vat_item->net_amount
    if (!vat_item->net_amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "net_amount", vat_item->net_amount) == NULL) {
    goto fail; //String
    }


    // vat_item->tax_amount
    if (!vat_item->tax_amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tax_amount", vat_item->tax_amount) == NULL) {
    goto fail; //String
    }


    // vat_item->tax_rate
    if (!vat_item->tax_rate) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tax_rate", vat_item->tax_rate) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

vat_item_t *vat_item_parseFromJSON(cJSON *vat_itemJSON){

    vat_item_t *vat_item_local_var = NULL;

    char *net_amount_local_str = NULL;

    char *tax_amount_local_str = NULL;

    char *tax_rate_local_str = NULL;

    // vat_item->net_amount
    cJSON *net_amount = cJSON_GetObjectItemCaseSensitive(vat_itemJSON, "net_amount");
    if (cJSON_IsNull(net_amount)) {
        net_amount = NULL;
    }
    if (!net_amount) {
        goto end;
    }

    
    if(!cJSON_IsString(net_amount))
    {
    goto end; //String
    }

    // vat_item->tax_amount
    cJSON *tax_amount = cJSON_GetObjectItemCaseSensitive(vat_itemJSON, "tax_amount");
    if (cJSON_IsNull(tax_amount)) {
        tax_amount = NULL;
    }
    if (!tax_amount) {
        goto end;
    }

    
    if(!cJSON_IsString(tax_amount))
    {
    goto end; //String
    }

    // vat_item->tax_rate
    cJSON *tax_rate = cJSON_GetObjectItemCaseSensitive(vat_itemJSON, "tax_rate");
    if (cJSON_IsNull(tax_rate)) {
        tax_rate = NULL;
    }
    if (!tax_rate) {
        goto end;
    }

    
    if(!cJSON_IsString(tax_rate))
    {
    goto end; //String
    }


    if (net_amount && !cJSON_IsNull(net_amount)) net_amount_local_str = strdup(net_amount->valuestring);
    if (tax_amount && !cJSON_IsNull(tax_amount)) tax_amount_local_str = strdup(tax_amount->valuestring);
    if (tax_rate && !cJSON_IsNull(tax_rate)) tax_rate_local_str = strdup(tax_rate->valuestring);

    vat_item_local_var = vat_item_create_internal (
        net_amount_local_str,
        tax_amount_local_str,
        tax_rate_local_str
        );

    if (!vat_item_local_var) {
        goto end;
    }

    return vat_item_local_var;
end:
    if (net_amount_local_str) {
        free(net_amount_local_str);
        net_amount_local_str = NULL;
    }
    if (tax_amount_local_str) {
        free(tax_amount_local_str);
        tax_amount_local_str = NULL;
    }
    if (tax_rate_local_str) {
        free(tax_rate_local_str);
        tax_rate_local_str = NULL;
    }
    return NULL;

}
