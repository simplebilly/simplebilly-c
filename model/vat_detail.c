#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vat_detail.h"



static vat_detail_t *vat_detail_create_internal(
    long *count,
    char *net_amount,
    char *tax_amount,
    char *tax_rate
    ) {
    vat_detail_t *vat_detail_local_var = malloc(sizeof(vat_detail_t));
    if (!vat_detail_local_var) {
        return NULL;
    }
    memset(vat_detail_local_var, 0, sizeof(vat_detail_t));
    vat_detail_local_var->_library_owned = 1;
    vat_detail_local_var->count = count;
    vat_detail_local_var->net_amount = net_amount;
    vat_detail_local_var->tax_amount = tax_amount;
    vat_detail_local_var->tax_rate = tax_rate;
    return vat_detail_local_var;
}

__attribute__((deprecated)) vat_detail_t *vat_detail_create(
    long *count,
    char *net_amount,
    char *tax_amount,
    char *tax_rate
    ) {
    long *count_copy = NULL;
    if (count) {
        count_copy = malloc(sizeof(long));
        if (count_copy) *count_copy = *count;
    }
    vat_detail_t *result = vat_detail_create_internal (
        count_copy,
        net_amount,
        tax_amount,
        tax_rate
        );
    if (!result) {
        free(count_copy);
    }
    return result;
}

void vat_detail_free(vat_detail_t *vat_detail) {
    if(NULL == vat_detail){
        return ;
    }
    if(vat_detail->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "vat_detail_free");
        return ;
    }
    listEntry_t *listEntry;
    if (vat_detail->count) {
        free(vat_detail->count);
        vat_detail->count = NULL;
    }
    if (vat_detail->net_amount) {
        free(vat_detail->net_amount);
        vat_detail->net_amount = NULL;
    }
    if (vat_detail->tax_amount) {
        free(vat_detail->tax_amount);
        vat_detail->tax_amount = NULL;
    }
    if (vat_detail->tax_rate) {
        free(vat_detail->tax_rate);
        vat_detail->tax_rate = NULL;
    }
    free(vat_detail);
}

cJSON *vat_detail_convertToJSON(vat_detail_t *vat_detail) {
    cJSON *item = cJSON_CreateObject();

    // vat_detail->count
    if (!vat_detail->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", *vat_detail->count) == NULL) {
    goto fail; //Numeric
    }


    // vat_detail->net_amount
    if (!vat_detail->net_amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "net_amount", vat_detail->net_amount) == NULL) {
    goto fail; //String
    }


    // vat_detail->tax_amount
    if (!vat_detail->tax_amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tax_amount", vat_detail->tax_amount) == NULL) {
    goto fail; //String
    }


    // vat_detail->tax_rate
    if (!vat_detail->tax_rate) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tax_rate", vat_detail->tax_rate) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

vat_detail_t *vat_detail_parseFromJSON(cJSON *vat_detailJSON){

    vat_detail_t *vat_detail_local_var = NULL;

    // define the local variable for vat_detail->count
    long *count_local_var = NULL;

    char *net_amount_local_str = NULL;

    char *tax_amount_local_str = NULL;

    char *tax_rate_local_str = NULL;

    // vat_detail->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(vat_detailJSON, "count");
    if (cJSON_IsNull(count)) {
        count = NULL;
    }
    if (!count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }
    count_local_var = malloc(sizeof(long));
    if(!count_local_var)
    {
        goto end;
    }
    *count_local_var = count->valuedouble;

    // vat_detail->net_amount
    cJSON *net_amount = cJSON_GetObjectItemCaseSensitive(vat_detailJSON, "net_amount");
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

    // vat_detail->tax_amount
    cJSON *tax_amount = cJSON_GetObjectItemCaseSensitive(vat_detailJSON, "tax_amount");
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

    // vat_detail->tax_rate
    cJSON *tax_rate = cJSON_GetObjectItemCaseSensitive(vat_detailJSON, "tax_rate");
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

    vat_detail_local_var = vat_detail_create_internal (
        count_local_var,
        net_amount_local_str,
        tax_amount_local_str,
        tax_rate_local_str
        );

    if (!vat_detail_local_var) {
        goto end;
    }

    return vat_detail_local_var;
end:
    if (count_local_var) {
        free(count_local_var);
        count_local_var = NULL;
    }
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
