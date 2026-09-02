#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "coupon_update.h"



static coupon_update_t *coupon_update_create_internal(
    char *code,
    char *description,
    discount_type_t *discount_type,
    char *discount_value,
    char *expires_at,
    int *is_active,
    int *is_combineable,
    char *max_discount_amount,
    int *max_uses,
    int *max_uses_per_customer,
    char *min_order_amount,
    any_type_t *product_ids,
    char *starts_at
    ) {
    coupon_update_t *coupon_update_local_var = malloc(sizeof(coupon_update_t));
    if (!coupon_update_local_var) {
        return NULL;
    }
    memset(coupon_update_local_var, 0, sizeof(coupon_update_t));
    coupon_update_local_var->_library_owned = 1;
    coupon_update_local_var->code = code;
    coupon_update_local_var->description = description;
    coupon_update_local_var->discount_type = discount_type;
    coupon_update_local_var->discount_value = discount_value;
    coupon_update_local_var->expires_at = expires_at;
    coupon_update_local_var->is_active = is_active;
    coupon_update_local_var->is_combineable = is_combineable;
    coupon_update_local_var->max_discount_amount = max_discount_amount;
    coupon_update_local_var->max_uses = max_uses;
    coupon_update_local_var->max_uses_per_customer = max_uses_per_customer;
    coupon_update_local_var->min_order_amount = min_order_amount;
    coupon_update_local_var->product_ids = product_ids;
    coupon_update_local_var->starts_at = starts_at;
    return coupon_update_local_var;
}

__attribute__((deprecated)) coupon_update_t *coupon_update_create(
    char *code,
    char *description,
    discount_type_t *discount_type,
    char *discount_value,
    char *expires_at,
    int *is_active,
    int *is_combineable,
    char *max_discount_amount,
    int *max_uses,
    int *max_uses_per_customer,
    char *min_order_amount,
    any_type_t *product_ids,
    char *starts_at
    ) {
    int *is_active_copy = NULL;
    if (is_active) {
        is_active_copy = malloc(sizeof(int));
        if (is_active_copy) *is_active_copy = *is_active;
    }
    int *is_combineable_copy = NULL;
    if (is_combineable) {
        is_combineable_copy = malloc(sizeof(int));
        if (is_combineable_copy) *is_combineable_copy = *is_combineable;
    }
    int *max_uses_copy = NULL;
    if (max_uses) {
        max_uses_copy = malloc(sizeof(int));
        if (max_uses_copy) *max_uses_copy = *max_uses;
    }
    int *max_uses_per_customer_copy = NULL;
    if (max_uses_per_customer) {
        max_uses_per_customer_copy = malloc(sizeof(int));
        if (max_uses_per_customer_copy) *max_uses_per_customer_copy = *max_uses_per_customer;
    }
    coupon_update_t *result = coupon_update_create_internal (
        code,
        description,
        discount_type,
        discount_value,
        expires_at,
        is_active_copy,
        is_combineable_copy,
        max_discount_amount,
        max_uses_copy,
        max_uses_per_customer_copy,
        min_order_amount,
        product_ids,
        starts_at
        );
    if (!result) {
        free(is_active_copy);
        free(is_combineable_copy);
        free(max_uses_copy);
        free(max_uses_per_customer_copy);
    }
    return result;
}

void coupon_update_free(coupon_update_t *coupon_update) {
    if(NULL == coupon_update){
        return ;
    }
    if(coupon_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "coupon_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (coupon_update->code) {
        free(coupon_update->code);
        coupon_update->code = NULL;
    }
    if (coupon_update->description) {
        free(coupon_update->description);
        coupon_update->description = NULL;
    }
    if (coupon_update->discount_type) {
        discount_type_free(coupon_update->discount_type);
        coupon_update->discount_type = NULL;
    }
    if (coupon_update->discount_value) {
        free(coupon_update->discount_value);
        coupon_update->discount_value = NULL;
    }
    if (coupon_update->expires_at) {
        free(coupon_update->expires_at);
        coupon_update->expires_at = NULL;
    }
    if (coupon_update->is_active) {
        free(coupon_update->is_active);
        coupon_update->is_active = NULL;
    }
    if (coupon_update->is_combineable) {
        free(coupon_update->is_combineable);
        coupon_update->is_combineable = NULL;
    }
    if (coupon_update->max_discount_amount) {
        free(coupon_update->max_discount_amount);
        coupon_update->max_discount_amount = NULL;
    }
    if (coupon_update->max_uses) {
        free(coupon_update->max_uses);
        coupon_update->max_uses = NULL;
    }
    if (coupon_update->max_uses_per_customer) {
        free(coupon_update->max_uses_per_customer);
        coupon_update->max_uses_per_customer = NULL;
    }
    if (coupon_update->min_order_amount) {
        free(coupon_update->min_order_amount);
        coupon_update->min_order_amount = NULL;
    }
    if (coupon_update->product_ids) {
        _free(coupon_update->product_ids);
        coupon_update->product_ids = NULL;
    }
    if (coupon_update->starts_at) {
        free(coupon_update->starts_at);
        coupon_update->starts_at = NULL;
    }
    free(coupon_update);
}

cJSON *coupon_update_convertToJSON(coupon_update_t *coupon_update) {
    cJSON *item = cJSON_CreateObject();

    // coupon_update->code
    if(coupon_update->code) {
    if(cJSON_AddStringToObject(item, "code", coupon_update->code) == NULL) {
    goto fail; //String
    }
    }


    // coupon_update->description
    if(coupon_update->description) {
    if(cJSON_AddStringToObject(item, "description", coupon_update->description) == NULL) {
    goto fail; //String
    }
    }


    // coupon_update->discount_type
    if(coupon_update->discount_type) {
    cJSON *discount_type_local_JSON = discount_type_convertToJSON(coupon_update->discount_type);
    if(discount_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "discountType", discount_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // coupon_update->discount_value
    if(coupon_update->discount_value) {
    if(cJSON_AddStringToObject(item, "discountValue", coupon_update->discount_value) == NULL) {
    goto fail; //String
    }
    }


    // coupon_update->expires_at
    if(coupon_update->expires_at) {
    if(cJSON_AddStringToObject(item, "expiresAt", coupon_update->expires_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // coupon_update->is_active
    if(coupon_update->is_active) {
    if(cJSON_AddBoolToObject(item, "isActive", *coupon_update->is_active) == NULL) {
    goto fail; //Bool
    }
    }


    // coupon_update->is_combineable
    if(coupon_update->is_combineable) {
    if(cJSON_AddBoolToObject(item, "isCombineable", *coupon_update->is_combineable) == NULL) {
    goto fail; //Bool
    }
    }


    // coupon_update->max_discount_amount
    if(coupon_update->max_discount_amount) {
    if(cJSON_AddStringToObject(item, "maxDiscountAmount", coupon_update->max_discount_amount) == NULL) {
    goto fail; //String
    }
    }


    // coupon_update->max_uses
    if(coupon_update->max_uses) {
    if(cJSON_AddNumberToObject(item, "maxUses", *coupon_update->max_uses) == NULL) {
    goto fail; //Numeric
    }
    }


    // coupon_update->max_uses_per_customer
    if(coupon_update->max_uses_per_customer) {
    if(cJSON_AddNumberToObject(item, "maxUsesPerCustomer", *coupon_update->max_uses_per_customer) == NULL) {
    goto fail; //Numeric
    }
    }


    // coupon_update->min_order_amount
    if(coupon_update->min_order_amount) {
    if(cJSON_AddStringToObject(item, "minOrderAmount", coupon_update->min_order_amount) == NULL) {
    goto fail; //String
    }
    }


    // coupon_update->product_ids
    if(coupon_update->product_ids) {
    cJSON *product_ids_local_JSON = _convertToJSON(coupon_update->product_ids);
    if(product_ids_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "productIds", product_ids_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // coupon_update->starts_at
    if(coupon_update->starts_at) {
    if(cJSON_AddStringToObject(item, "startsAt", coupon_update->starts_at) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

coupon_update_t *coupon_update_parseFromJSON(cJSON *coupon_updateJSON){

    coupon_update_t *coupon_update_local_var = NULL;

    char *code_local_str = NULL;

    char *description_local_str = NULL;

    // define the local variable for coupon_update->discount_type
    discount_type_t *discount_type_local_nonprim = NULL;

    char *discount_value_local_str = NULL;

    char *expires_at_local_str = NULL;

    // define the local variable for coupon_update->is_active
    int *is_active_local_var = NULL;

    // define the local variable for coupon_update->is_combineable
    int *is_combineable_local_var = NULL;

    char *max_discount_amount_local_str = NULL;

    // define the local variable for coupon_update->max_uses
    int *max_uses_local_var = NULL;

    // define the local variable for coupon_update->max_uses_per_customer
    int *max_uses_per_customer_local_var = NULL;

    char *min_order_amount_local_str = NULL;

    // define the local variable for coupon_update->product_ids
    _t *product_ids_local_nonprim = NULL;

    char *starts_at_local_str = NULL;

    // coupon_update->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(coupon_updateJSON, "code");
    if (cJSON_IsNull(code)) {
        code = NULL;
    }
    if (code) { 
    if(!cJSON_IsString(code) && !cJSON_IsNull(code))
    {
    goto end; //String
    }
    }

    // coupon_update->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(coupon_updateJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // coupon_update->discount_type
    cJSON *discount_type = cJSON_GetObjectItemCaseSensitive(coupon_updateJSON, "discountType");
    if (cJSON_IsNull(discount_type)) {
        discount_type = NULL;
    }
    if (discount_type) { 
    discount_type_local_nonprim = discount_type_parseFromJSON(discount_type); //custom
    }

    // coupon_update->discount_value
    cJSON *discount_value = cJSON_GetObjectItemCaseSensitive(coupon_updateJSON, "discountValue");
    if (cJSON_IsNull(discount_value)) {
        discount_value = NULL;
    }
    if (discount_value) { 
    if(!cJSON_IsString(discount_value) && !cJSON_IsNull(discount_value))
    {
    goto end; //String
    }
    }

    // coupon_update->expires_at
    cJSON *expires_at = cJSON_GetObjectItemCaseSensitive(coupon_updateJSON, "expiresAt");
    if (cJSON_IsNull(expires_at)) {
        expires_at = NULL;
    }
    if (expires_at) { 
    if(!cJSON_IsString(expires_at) && !cJSON_IsNull(expires_at))
    {
    goto end; //DateTime
    }
    }

    // coupon_update->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(coupon_updateJSON, "isActive");
    if (cJSON_IsNull(is_active)) {
        is_active = NULL;
    }
    if (is_active) { 
    if(!cJSON_IsBool(is_active))
    {
    goto end; //Bool
    }
    is_active_local_var = malloc(sizeof(int));
    if(!is_active_local_var)
    {
        goto end;
    }
    *is_active_local_var = is_active->valueint;
    }

    // coupon_update->is_combineable
    cJSON *is_combineable = cJSON_GetObjectItemCaseSensitive(coupon_updateJSON, "isCombineable");
    if (cJSON_IsNull(is_combineable)) {
        is_combineable = NULL;
    }
    if (is_combineable) { 
    if(!cJSON_IsBool(is_combineable))
    {
    goto end; //Bool
    }
    is_combineable_local_var = malloc(sizeof(int));
    if(!is_combineable_local_var)
    {
        goto end;
    }
    *is_combineable_local_var = is_combineable->valueint;
    }

    // coupon_update->max_discount_amount
    cJSON *max_discount_amount = cJSON_GetObjectItemCaseSensitive(coupon_updateJSON, "maxDiscountAmount");
    if (cJSON_IsNull(max_discount_amount)) {
        max_discount_amount = NULL;
    }
    if (max_discount_amount) { 
    if(!cJSON_IsString(max_discount_amount) && !cJSON_IsNull(max_discount_amount))
    {
    goto end; //String
    }
    }

    // coupon_update->max_uses
    cJSON *max_uses = cJSON_GetObjectItemCaseSensitive(coupon_updateJSON, "maxUses");
    if (cJSON_IsNull(max_uses)) {
        max_uses = NULL;
    }
    if (max_uses) { 
    if(!cJSON_IsNumber(max_uses))
    {
    goto end; //Numeric
    }
    max_uses_local_var = malloc(sizeof(int));
    if(!max_uses_local_var)
    {
        goto end;
    }
    *max_uses_local_var = max_uses->valuedouble;
    }

    // coupon_update->max_uses_per_customer
    cJSON *max_uses_per_customer = cJSON_GetObjectItemCaseSensitive(coupon_updateJSON, "maxUsesPerCustomer");
    if (cJSON_IsNull(max_uses_per_customer)) {
        max_uses_per_customer = NULL;
    }
    if (max_uses_per_customer) { 
    if(!cJSON_IsNumber(max_uses_per_customer))
    {
    goto end; //Numeric
    }
    max_uses_per_customer_local_var = malloc(sizeof(int));
    if(!max_uses_per_customer_local_var)
    {
        goto end;
    }
    *max_uses_per_customer_local_var = max_uses_per_customer->valuedouble;
    }

    // coupon_update->min_order_amount
    cJSON *min_order_amount = cJSON_GetObjectItemCaseSensitive(coupon_updateJSON, "minOrderAmount");
    if (cJSON_IsNull(min_order_amount)) {
        min_order_amount = NULL;
    }
    if (min_order_amount) { 
    if(!cJSON_IsString(min_order_amount) && !cJSON_IsNull(min_order_amount))
    {
    goto end; //String
    }
    }

    // coupon_update->product_ids
    cJSON *product_ids = cJSON_GetObjectItemCaseSensitive(coupon_updateJSON, "productIds");
    if (cJSON_IsNull(product_ids)) {
        product_ids = NULL;
    }
    if (product_ids) { 
    product_ids_local_nonprim = _parseFromJSON(product_ids); //custom
    }

    // coupon_update->starts_at
    cJSON *starts_at = cJSON_GetObjectItemCaseSensitive(coupon_updateJSON, "startsAt");
    if (cJSON_IsNull(starts_at)) {
        starts_at = NULL;
    }
    if (starts_at) { 
    if(!cJSON_IsString(starts_at) && !cJSON_IsNull(starts_at))
    {
    goto end; //DateTime
    }
    }


    if (code && !cJSON_IsNull(code)) code_local_str = strdup(code->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (discount_value && !cJSON_IsNull(discount_value)) discount_value_local_str = strdup(discount_value->valuestring);
    if (expires_at && !cJSON_IsNull(expires_at)) expires_at_local_str = strdup(expires_at->valuestring);
    if (max_discount_amount && !cJSON_IsNull(max_discount_amount)) max_discount_amount_local_str = strdup(max_discount_amount->valuestring);
    if (min_order_amount && !cJSON_IsNull(min_order_amount)) min_order_amount_local_str = strdup(min_order_amount->valuestring);
    if (starts_at && !cJSON_IsNull(starts_at)) starts_at_local_str = strdup(starts_at->valuestring);

    coupon_update_local_var = coupon_update_create_internal (
        code_local_str,
        description_local_str,
        discount_type ? discount_type_local_nonprim : NULL,
        discount_value_local_str,
        expires_at_local_str,
        is_active_local_var,
        is_combineable_local_var,
        max_discount_amount_local_str,
        max_uses_local_var,
        max_uses_per_customer_local_var,
        min_order_amount_local_str,
        product_ids ? product_ids_local_nonprim : NULL,
        starts_at_local_str
        );

    if (!coupon_update_local_var) {
        goto end;
    }

    return coupon_update_local_var;
end:
    if (code_local_str) {
        free(code_local_str);
        code_local_str = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (discount_type_local_nonprim) {
        discount_type_free(discount_type_local_nonprim);
        discount_type_local_nonprim = NULL;
    }
    if (discount_value_local_str) {
        free(discount_value_local_str);
        discount_value_local_str = NULL;
    }
    if (expires_at_local_str) {
        free(expires_at_local_str);
        expires_at_local_str = NULL;
    }
    if (is_active_local_var) {
        free(is_active_local_var);
        is_active_local_var = NULL;
    }
    if (is_combineable_local_var) {
        free(is_combineable_local_var);
        is_combineable_local_var = NULL;
    }
    if (max_discount_amount_local_str) {
        free(max_discount_amount_local_str);
        max_discount_amount_local_str = NULL;
    }
    if (max_uses_local_var) {
        free(max_uses_local_var);
        max_uses_local_var = NULL;
    }
    if (max_uses_per_customer_local_var) {
        free(max_uses_per_customer_local_var);
        max_uses_per_customer_local_var = NULL;
    }
    if (min_order_amount_local_str) {
        free(min_order_amount_local_str);
        min_order_amount_local_str = NULL;
    }
    if (product_ids_local_nonprim) {
        _free(product_ids_local_nonprim);
        product_ids_local_nonprim = NULL;
    }
    if (starts_at_local_str) {
        free(starts_at_local_str);
        starts_at_local_str = NULL;
    }
    return NULL;

}
