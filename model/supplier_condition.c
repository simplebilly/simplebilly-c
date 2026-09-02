#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "supplier_condition.h"



static supplier_condition_t *supplier_condition_create_internal(
    char *currency,
    char *delivery_terms,
    char *early_payment_discount_percent,
    int *is_default,
    char *minimum_order_value,
    char *notes,
    int *payment_due_days,
    char *payment_terms,
    char *supplier_contact_id,
    char *supplier_name,
    any_type_t *volume_discount_tiers
    ) {
    supplier_condition_t *supplier_condition_local_var = malloc(sizeof(supplier_condition_t));
    if (!supplier_condition_local_var) {
        return NULL;
    }
    memset(supplier_condition_local_var, 0, sizeof(supplier_condition_t));
    supplier_condition_local_var->_library_owned = 1;
    supplier_condition_local_var->currency = currency;
    supplier_condition_local_var->delivery_terms = delivery_terms;
    supplier_condition_local_var->early_payment_discount_percent = early_payment_discount_percent;
    supplier_condition_local_var->is_default = is_default;
    supplier_condition_local_var->minimum_order_value = minimum_order_value;
    supplier_condition_local_var->notes = notes;
    supplier_condition_local_var->payment_due_days = payment_due_days;
    supplier_condition_local_var->payment_terms = payment_terms;
    supplier_condition_local_var->supplier_contact_id = supplier_contact_id;
    supplier_condition_local_var->supplier_name = supplier_name;
    supplier_condition_local_var->volume_discount_tiers = volume_discount_tiers;
    return supplier_condition_local_var;
}

__attribute__((deprecated)) supplier_condition_t *supplier_condition_create(
    char *currency,
    char *delivery_terms,
    char *early_payment_discount_percent,
    int *is_default,
    char *minimum_order_value,
    char *notes,
    int *payment_due_days,
    char *payment_terms,
    char *supplier_contact_id,
    char *supplier_name,
    any_type_t *volume_discount_tiers
    ) {
    int *is_default_copy = NULL;
    if (is_default) {
        is_default_copy = malloc(sizeof(int));
        if (is_default_copy) *is_default_copy = *is_default;
    }
    int *payment_due_days_copy = NULL;
    if (payment_due_days) {
        payment_due_days_copy = malloc(sizeof(int));
        if (payment_due_days_copy) *payment_due_days_copy = *payment_due_days;
    }
    supplier_condition_t *result = supplier_condition_create_internal (
        currency,
        delivery_terms,
        early_payment_discount_percent,
        is_default_copy,
        minimum_order_value,
        notes,
        payment_due_days_copy,
        payment_terms,
        supplier_contact_id,
        supplier_name,
        volume_discount_tiers
        );
    if (!result) {
        free(is_default_copy);
        free(payment_due_days_copy);
    }
    return result;
}

void supplier_condition_free(supplier_condition_t *supplier_condition) {
    if(NULL == supplier_condition){
        return ;
    }
    if(supplier_condition->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "supplier_condition_free");
        return ;
    }
    listEntry_t *listEntry;
    if (supplier_condition->currency) {
        free(supplier_condition->currency);
        supplier_condition->currency = NULL;
    }
    if (supplier_condition->delivery_terms) {
        free(supplier_condition->delivery_terms);
        supplier_condition->delivery_terms = NULL;
    }
    if (supplier_condition->early_payment_discount_percent) {
        free(supplier_condition->early_payment_discount_percent);
        supplier_condition->early_payment_discount_percent = NULL;
    }
    if (supplier_condition->is_default) {
        free(supplier_condition->is_default);
        supplier_condition->is_default = NULL;
    }
    if (supplier_condition->minimum_order_value) {
        free(supplier_condition->minimum_order_value);
        supplier_condition->minimum_order_value = NULL;
    }
    if (supplier_condition->notes) {
        free(supplier_condition->notes);
        supplier_condition->notes = NULL;
    }
    if (supplier_condition->payment_due_days) {
        free(supplier_condition->payment_due_days);
        supplier_condition->payment_due_days = NULL;
    }
    if (supplier_condition->payment_terms) {
        free(supplier_condition->payment_terms);
        supplier_condition->payment_terms = NULL;
    }
    if (supplier_condition->supplier_contact_id) {
        free(supplier_condition->supplier_contact_id);
        supplier_condition->supplier_contact_id = NULL;
    }
    if (supplier_condition->supplier_name) {
        free(supplier_condition->supplier_name);
        supplier_condition->supplier_name = NULL;
    }
    if (supplier_condition->volume_discount_tiers) {
        _free(supplier_condition->volume_discount_tiers);
        supplier_condition->volume_discount_tiers = NULL;
    }
    free(supplier_condition);
}

cJSON *supplier_condition_convertToJSON(supplier_condition_t *supplier_condition) {
    cJSON *item = cJSON_CreateObject();

    // supplier_condition->currency
    if (!supplier_condition->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", supplier_condition->currency) == NULL) {
    goto fail; //String
    }


    // supplier_condition->delivery_terms
    if(supplier_condition->delivery_terms) {
    if(cJSON_AddStringToObject(item, "deliveryTerms", supplier_condition->delivery_terms) == NULL) {
    goto fail; //String
    }
    }


    // supplier_condition->early_payment_discount_percent
    if(supplier_condition->early_payment_discount_percent) {
    if(cJSON_AddStringToObject(item, "earlyPaymentDiscountPercent", supplier_condition->early_payment_discount_percent) == NULL) {
    goto fail; //String
    }
    }


    // supplier_condition->is_default
    if(supplier_condition->is_default) {
    if(cJSON_AddBoolToObject(item, "isDefault", *supplier_condition->is_default) == NULL) {
    goto fail; //Bool
    }
    }


    // supplier_condition->minimum_order_value
    if(supplier_condition->minimum_order_value) {
    if(cJSON_AddStringToObject(item, "minimumOrderValue", supplier_condition->minimum_order_value) == NULL) {
    goto fail; //String
    }
    }


    // supplier_condition->notes
    if(supplier_condition->notes) {
    if(cJSON_AddStringToObject(item, "notes", supplier_condition->notes) == NULL) {
    goto fail; //String
    }
    }


    // supplier_condition->payment_due_days
    if(supplier_condition->payment_due_days) {
    if(cJSON_AddNumberToObject(item, "paymentDueDays", *supplier_condition->payment_due_days) == NULL) {
    goto fail; //Numeric
    }
    }


    // supplier_condition->payment_terms
    if(supplier_condition->payment_terms) {
    if(cJSON_AddStringToObject(item, "paymentTerms", supplier_condition->payment_terms) == NULL) {
    goto fail; //String
    }
    }


    // supplier_condition->supplier_contact_id
    if (!supplier_condition->supplier_contact_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "supplierContactId", supplier_condition->supplier_contact_id) == NULL) {
    goto fail; //String
    }


    // supplier_condition->supplier_name
    if(supplier_condition->supplier_name) {
    if(cJSON_AddStringToObject(item, "supplierName", supplier_condition->supplier_name) == NULL) {
    goto fail; //String
    }
    }


    // supplier_condition->volume_discount_tiers
    if(supplier_condition->volume_discount_tiers) {
    cJSON *volume_discount_tiers_local_JSON = _convertToJSON(supplier_condition->volume_discount_tiers);
    if(volume_discount_tiers_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "volumeDiscountTiers", volume_discount_tiers_local_JSON);
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

supplier_condition_t *supplier_condition_parseFromJSON(cJSON *supplier_conditionJSON){

    supplier_condition_t *supplier_condition_local_var = NULL;

    char *currency_local_str = NULL;

    char *delivery_terms_local_str = NULL;

    char *early_payment_discount_percent_local_str = NULL;

    // define the local variable for supplier_condition->is_default
    int *is_default_local_var = NULL;

    char *minimum_order_value_local_str = NULL;

    char *notes_local_str = NULL;

    // define the local variable for supplier_condition->payment_due_days
    int *payment_due_days_local_var = NULL;

    char *payment_terms_local_str = NULL;

    char *supplier_contact_id_local_str = NULL;

    char *supplier_name_local_str = NULL;

    // define the local variable for supplier_condition->volume_discount_tiers
    _t *volume_discount_tiers_local_nonprim = NULL;

    // supplier_condition->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(supplier_conditionJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (!currency) {
        goto end;
    }

    
    if(!cJSON_IsString(currency))
    {
    goto end; //String
    }

    // supplier_condition->delivery_terms
    cJSON *delivery_terms = cJSON_GetObjectItemCaseSensitive(supplier_conditionJSON, "deliveryTerms");
    if (cJSON_IsNull(delivery_terms)) {
        delivery_terms = NULL;
    }
    if (delivery_terms) { 
    if(!cJSON_IsString(delivery_terms) && !cJSON_IsNull(delivery_terms))
    {
    goto end; //String
    }
    }

    // supplier_condition->early_payment_discount_percent
    cJSON *early_payment_discount_percent = cJSON_GetObjectItemCaseSensitive(supplier_conditionJSON, "earlyPaymentDiscountPercent");
    if (cJSON_IsNull(early_payment_discount_percent)) {
        early_payment_discount_percent = NULL;
    }
    if (early_payment_discount_percent) { 
    if(!cJSON_IsString(early_payment_discount_percent) && !cJSON_IsNull(early_payment_discount_percent))
    {
    goto end; //String
    }
    }

    // supplier_condition->is_default
    cJSON *is_default = cJSON_GetObjectItemCaseSensitive(supplier_conditionJSON, "isDefault");
    if (cJSON_IsNull(is_default)) {
        is_default = NULL;
    }
    if (is_default) { 
    if(!cJSON_IsBool(is_default))
    {
    goto end; //Bool
    }
    is_default_local_var = malloc(sizeof(int));
    if(!is_default_local_var)
    {
        goto end;
    }
    *is_default_local_var = is_default->valueint;
    }

    // supplier_condition->minimum_order_value
    cJSON *minimum_order_value = cJSON_GetObjectItemCaseSensitive(supplier_conditionJSON, "minimumOrderValue");
    if (cJSON_IsNull(minimum_order_value)) {
        minimum_order_value = NULL;
    }
    if (minimum_order_value) { 
    if(!cJSON_IsString(minimum_order_value) && !cJSON_IsNull(minimum_order_value))
    {
    goto end; //String
    }
    }

    // supplier_condition->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(supplier_conditionJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // supplier_condition->payment_due_days
    cJSON *payment_due_days = cJSON_GetObjectItemCaseSensitive(supplier_conditionJSON, "paymentDueDays");
    if (cJSON_IsNull(payment_due_days)) {
        payment_due_days = NULL;
    }
    if (payment_due_days) { 
    if(!cJSON_IsNumber(payment_due_days))
    {
    goto end; //Numeric
    }
    payment_due_days_local_var = malloc(sizeof(int));
    if(!payment_due_days_local_var)
    {
        goto end;
    }
    *payment_due_days_local_var = payment_due_days->valuedouble;
    }

    // supplier_condition->payment_terms
    cJSON *payment_terms = cJSON_GetObjectItemCaseSensitive(supplier_conditionJSON, "paymentTerms");
    if (cJSON_IsNull(payment_terms)) {
        payment_terms = NULL;
    }
    if (payment_terms) { 
    if(!cJSON_IsString(payment_terms) && !cJSON_IsNull(payment_terms))
    {
    goto end; //String
    }
    }

    // supplier_condition->supplier_contact_id
    cJSON *supplier_contact_id = cJSON_GetObjectItemCaseSensitive(supplier_conditionJSON, "supplierContactId");
    if (cJSON_IsNull(supplier_contact_id)) {
        supplier_contact_id = NULL;
    }
    if (!supplier_contact_id) {
        goto end;
    }

    
    if(!cJSON_IsString(supplier_contact_id))
    {
    goto end; //String
    }

    // supplier_condition->supplier_name
    cJSON *supplier_name = cJSON_GetObjectItemCaseSensitive(supplier_conditionJSON, "supplierName");
    if (cJSON_IsNull(supplier_name)) {
        supplier_name = NULL;
    }
    if (supplier_name) { 
    if(!cJSON_IsString(supplier_name) && !cJSON_IsNull(supplier_name))
    {
    goto end; //String
    }
    }

    // supplier_condition->volume_discount_tiers
    cJSON *volume_discount_tiers = cJSON_GetObjectItemCaseSensitive(supplier_conditionJSON, "volumeDiscountTiers");
    if (cJSON_IsNull(volume_discount_tiers)) {
        volume_discount_tiers = NULL;
    }
    if (volume_discount_tiers) { 
    volume_discount_tiers_local_nonprim = _parseFromJSON(volume_discount_tiers); //custom
    }


    if (currency && !cJSON_IsNull(currency)) currency_local_str = strdup(currency->valuestring);
    if (delivery_terms && !cJSON_IsNull(delivery_terms)) delivery_terms_local_str = strdup(delivery_terms->valuestring);
    if (early_payment_discount_percent && !cJSON_IsNull(early_payment_discount_percent)) early_payment_discount_percent_local_str = strdup(early_payment_discount_percent->valuestring);
    if (minimum_order_value && !cJSON_IsNull(minimum_order_value)) minimum_order_value_local_str = strdup(minimum_order_value->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (payment_terms && !cJSON_IsNull(payment_terms)) payment_terms_local_str = strdup(payment_terms->valuestring);
    if (supplier_contact_id && !cJSON_IsNull(supplier_contact_id)) supplier_contact_id_local_str = strdup(supplier_contact_id->valuestring);
    if (supplier_name && !cJSON_IsNull(supplier_name)) supplier_name_local_str = strdup(supplier_name->valuestring);

    supplier_condition_local_var = supplier_condition_create_internal (
        currency_local_str,
        delivery_terms_local_str,
        early_payment_discount_percent_local_str,
        is_default_local_var,
        minimum_order_value_local_str,
        notes_local_str,
        payment_due_days_local_var,
        payment_terms_local_str,
        supplier_contact_id_local_str,
        supplier_name_local_str,
        volume_discount_tiers ? volume_discount_tiers_local_nonprim : NULL
        );

    if (!supplier_condition_local_var) {
        goto end;
    }

    return supplier_condition_local_var;
end:
    if (currency_local_str) {
        free(currency_local_str);
        currency_local_str = NULL;
    }
    if (delivery_terms_local_str) {
        free(delivery_terms_local_str);
        delivery_terms_local_str = NULL;
    }
    if (early_payment_discount_percent_local_str) {
        free(early_payment_discount_percent_local_str);
        early_payment_discount_percent_local_str = NULL;
    }
    if (is_default_local_var) {
        free(is_default_local_var);
        is_default_local_var = NULL;
    }
    if (minimum_order_value_local_str) {
        free(minimum_order_value_local_str);
        minimum_order_value_local_str = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (payment_due_days_local_var) {
        free(payment_due_days_local_var);
        payment_due_days_local_var = NULL;
    }
    if (payment_terms_local_str) {
        free(payment_terms_local_str);
        payment_terms_local_str = NULL;
    }
    if (supplier_contact_id_local_str) {
        free(supplier_contact_id_local_str);
        supplier_contact_id_local_str = NULL;
    }
    if (supplier_name_local_str) {
        free(supplier_name_local_str);
        supplier_name_local_str = NULL;
    }
    if (volume_discount_tiers_local_nonprim) {
        _free(volume_discount_tiers_local_nonprim);
        volume_discount_tiers_local_nonprim = NULL;
    }
    return NULL;

}
