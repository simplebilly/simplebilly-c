#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "coupon_validation.h"



static coupon_validation_t *coupon_validation_create_internal(
    char *code,
    char *discount_type,
    char *discount_value,
    char *discounted_amount,
    char *max_discount_amount,
    char *reason,
    int *valid
    ) {
    coupon_validation_t *coupon_validation_local_var = malloc(sizeof(coupon_validation_t));
    if (!coupon_validation_local_var) {
        return NULL;
    }
    memset(coupon_validation_local_var, 0, sizeof(coupon_validation_t));
    coupon_validation_local_var->_library_owned = 1;
    coupon_validation_local_var->code = code;
    coupon_validation_local_var->discount_type = discount_type;
    coupon_validation_local_var->discount_value = discount_value;
    coupon_validation_local_var->discounted_amount = discounted_amount;
    coupon_validation_local_var->max_discount_amount = max_discount_amount;
    coupon_validation_local_var->reason = reason;
    coupon_validation_local_var->valid = valid;
    return coupon_validation_local_var;
}

__attribute__((deprecated)) coupon_validation_t *coupon_validation_create(
    char *code,
    char *discount_type,
    char *discount_value,
    char *discounted_amount,
    char *max_discount_amount,
    char *reason,
    int *valid
    ) {
    int *valid_copy = NULL;
    if (valid) {
        valid_copy = malloc(sizeof(int));
        if (valid_copy) *valid_copy = *valid;
    }
    coupon_validation_t *result = coupon_validation_create_internal (
        code,
        discount_type,
        discount_value,
        discounted_amount,
        max_discount_amount,
        reason,
        valid_copy
        );
    if (!result) {
        free(valid_copy);
    }
    return result;
}

void coupon_validation_free(coupon_validation_t *coupon_validation) {
    if(NULL == coupon_validation){
        return ;
    }
    if(coupon_validation->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "coupon_validation_free");
        return ;
    }
    listEntry_t *listEntry;
    if (coupon_validation->code) {
        free(coupon_validation->code);
        coupon_validation->code = NULL;
    }
    if (coupon_validation->discount_type) {
        free(coupon_validation->discount_type);
        coupon_validation->discount_type = NULL;
    }
    if (coupon_validation->discount_value) {
        free(coupon_validation->discount_value);
        coupon_validation->discount_value = NULL;
    }
    if (coupon_validation->discounted_amount) {
        free(coupon_validation->discounted_amount);
        coupon_validation->discounted_amount = NULL;
    }
    if (coupon_validation->max_discount_amount) {
        free(coupon_validation->max_discount_amount);
        coupon_validation->max_discount_amount = NULL;
    }
    if (coupon_validation->reason) {
        free(coupon_validation->reason);
        coupon_validation->reason = NULL;
    }
    if (coupon_validation->valid) {
        free(coupon_validation->valid);
        coupon_validation->valid = NULL;
    }
    free(coupon_validation);
}

cJSON *coupon_validation_convertToJSON(coupon_validation_t *coupon_validation) {
    cJSON *item = cJSON_CreateObject();

    // coupon_validation->code
    if (!coupon_validation->code) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "code", coupon_validation->code) == NULL) {
    goto fail; //String
    }


    // coupon_validation->discount_type
    if (!coupon_validation->discount_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "discount_type", coupon_validation->discount_type) == NULL) {
    goto fail; //String
    }


    // coupon_validation->discount_value
    if (!coupon_validation->discount_value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "discount_value", coupon_validation->discount_value) == NULL) {
    goto fail; //String
    }


    // coupon_validation->discounted_amount
    if (!coupon_validation->discounted_amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "discounted_amount", coupon_validation->discounted_amount) == NULL) {
    goto fail; //String
    }


    // coupon_validation->max_discount_amount
    if(coupon_validation->max_discount_amount) {
    if(cJSON_AddStringToObject(item, "max_discount_amount", coupon_validation->max_discount_amount) == NULL) {
    goto fail; //String
    }
    }


    // coupon_validation->reason
    if(coupon_validation->reason) {
    if(cJSON_AddStringToObject(item, "reason", coupon_validation->reason) == NULL) {
    goto fail; //String
    }
    }


    // coupon_validation->valid
    if (!coupon_validation->valid) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "valid", *coupon_validation->valid) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

coupon_validation_t *coupon_validation_parseFromJSON(cJSON *coupon_validationJSON){

    coupon_validation_t *coupon_validation_local_var = NULL;

    char *code_local_str = NULL;

    char *discount_type_local_str = NULL;

    char *discount_value_local_str = NULL;

    char *discounted_amount_local_str = NULL;

    char *max_discount_amount_local_str = NULL;

    char *reason_local_str = NULL;

    // define the local variable for coupon_validation->valid
    int *valid_local_var = NULL;

    // coupon_validation->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(coupon_validationJSON, "code");
    if (cJSON_IsNull(code)) {
        code = NULL;
    }
    if (!code) {
        goto end;
    }

    
    if(!cJSON_IsString(code))
    {
    goto end; //String
    }

    // coupon_validation->discount_type
    cJSON *discount_type = cJSON_GetObjectItemCaseSensitive(coupon_validationJSON, "discount_type");
    if (cJSON_IsNull(discount_type)) {
        discount_type = NULL;
    }
    if (!discount_type) {
        goto end;
    }

    
    if(!cJSON_IsString(discount_type))
    {
    goto end; //String
    }

    // coupon_validation->discount_value
    cJSON *discount_value = cJSON_GetObjectItemCaseSensitive(coupon_validationJSON, "discount_value");
    if (cJSON_IsNull(discount_value)) {
        discount_value = NULL;
    }
    if (!discount_value) {
        goto end;
    }

    
    if(!cJSON_IsString(discount_value))
    {
    goto end; //String
    }

    // coupon_validation->discounted_amount
    cJSON *discounted_amount = cJSON_GetObjectItemCaseSensitive(coupon_validationJSON, "discounted_amount");
    if (cJSON_IsNull(discounted_amount)) {
        discounted_amount = NULL;
    }
    if (!discounted_amount) {
        goto end;
    }

    
    if(!cJSON_IsString(discounted_amount))
    {
    goto end; //String
    }

    // coupon_validation->max_discount_amount
    cJSON *max_discount_amount = cJSON_GetObjectItemCaseSensitive(coupon_validationJSON, "max_discount_amount");
    if (cJSON_IsNull(max_discount_amount)) {
        max_discount_amount = NULL;
    }
    if (max_discount_amount) { 
    if(!cJSON_IsString(max_discount_amount) && !cJSON_IsNull(max_discount_amount))
    {
    goto end; //String
    }
    }

    // coupon_validation->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(coupon_validationJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }

    // coupon_validation->valid
    cJSON *valid = cJSON_GetObjectItemCaseSensitive(coupon_validationJSON, "valid");
    if (cJSON_IsNull(valid)) {
        valid = NULL;
    }
    if (!valid) {
        goto end;
    }

    
    if(!cJSON_IsBool(valid))
    {
    goto end; //Bool
    }
    valid_local_var = malloc(sizeof(int));
    if(!valid_local_var)
    {
        goto end;
    }
    *valid_local_var = valid->valueint;


    if (code && !cJSON_IsNull(code)) code_local_str = strdup(code->valuestring);
    if (discount_type && !cJSON_IsNull(discount_type)) discount_type_local_str = strdup(discount_type->valuestring);
    if (discount_value && !cJSON_IsNull(discount_value)) discount_value_local_str = strdup(discount_value->valuestring);
    if (discounted_amount && !cJSON_IsNull(discounted_amount)) discounted_amount_local_str = strdup(discounted_amount->valuestring);
    if (max_discount_amount && !cJSON_IsNull(max_discount_amount)) max_discount_amount_local_str = strdup(max_discount_amount->valuestring);
    if (reason && !cJSON_IsNull(reason)) reason_local_str = strdup(reason->valuestring);

    coupon_validation_local_var = coupon_validation_create_internal (
        code_local_str,
        discount_type_local_str,
        discount_value_local_str,
        discounted_amount_local_str,
        max_discount_amount_local_str,
        reason_local_str,
        valid_local_var
        );

    if (!coupon_validation_local_var) {
        goto end;
    }

    return coupon_validation_local_var;
end:
    if (code_local_str) {
        free(code_local_str);
        code_local_str = NULL;
    }
    if (discount_type_local_str) {
        free(discount_type_local_str);
        discount_type_local_str = NULL;
    }
    if (discount_value_local_str) {
        free(discount_value_local_str);
        discount_value_local_str = NULL;
    }
    if (discounted_amount_local_str) {
        free(discounted_amount_local_str);
        discounted_amount_local_str = NULL;
    }
    if (max_discount_amount_local_str) {
        free(max_discount_amount_local_str);
        max_discount_amount_local_str = NULL;
    }
    if (reason_local_str) {
        free(reason_local_str);
        reason_local_str = NULL;
    }
    if (valid_local_var) {
        free(valid_local_var);
        valid_local_var = NULL;
    }
    return NULL;

}
