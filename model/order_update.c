#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "order_update.h"



static order_update_t *order_update_create_internal(
    any_type_t *audit_log,
    char *currency,
    char *customer_id,
    char *external_reference,
    any_type_t *invoice_address,
    any_type_t *items,
    language_code_t *language,
    order_status_t *order_status,
    payment_method_t *payment_method,
    any_type_t *shipping_address,
    char *shipping_cost,
    char *shipping_method,
    char *shipping_weight,
    list_t *tags,
    char *total_cost
    ) {
    order_update_t *order_update_local_var = malloc(sizeof(order_update_t));
    if (!order_update_local_var) {
        return NULL;
    }
    memset(order_update_local_var, 0, sizeof(order_update_t));
    order_update_local_var->_library_owned = 1;
    order_update_local_var->audit_log = audit_log;
    order_update_local_var->currency = currency;
    order_update_local_var->customer_id = customer_id;
    order_update_local_var->external_reference = external_reference;
    order_update_local_var->invoice_address = invoice_address;
    order_update_local_var->items = items;
    order_update_local_var->language = language;
    order_update_local_var->order_status = order_status;
    order_update_local_var->payment_method = payment_method;
    order_update_local_var->shipping_address = shipping_address;
    order_update_local_var->shipping_cost = shipping_cost;
    order_update_local_var->shipping_method = shipping_method;
    order_update_local_var->shipping_weight = shipping_weight;
    order_update_local_var->tags = tags;
    order_update_local_var->total_cost = total_cost;
    return order_update_local_var;
}

__attribute__((deprecated)) order_update_t *order_update_create(
    any_type_t *audit_log,
    char *currency,
    char *customer_id,
    char *external_reference,
    any_type_t *invoice_address,
    any_type_t *items,
    language_code_t *language,
    order_status_t *order_status,
    payment_method_t *payment_method,
    any_type_t *shipping_address,
    char *shipping_cost,
    char *shipping_method,
    char *shipping_weight,
    list_t *tags,
    char *total_cost
    ) {
    order_update_t *result = order_update_create_internal (
        audit_log,
        currency,
        customer_id,
        external_reference,
        invoice_address,
        items,
        language,
        order_status,
        payment_method,
        shipping_address,
        shipping_cost,
        shipping_method,
        shipping_weight,
        tags,
        total_cost
        );
    if (!result) {
    }
    return result;
}

void order_update_free(order_update_t *order_update) {
    if(NULL == order_update){
        return ;
    }
    if(order_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "order_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (order_update->audit_log) {
        _free(order_update->audit_log);
        order_update->audit_log = NULL;
    }
    if (order_update->currency) {
        free(order_update->currency);
        order_update->currency = NULL;
    }
    if (order_update->customer_id) {
        free(order_update->customer_id);
        order_update->customer_id = NULL;
    }
    if (order_update->external_reference) {
        free(order_update->external_reference);
        order_update->external_reference = NULL;
    }
    if (order_update->invoice_address) {
        _free(order_update->invoice_address);
        order_update->invoice_address = NULL;
    }
    if (order_update->items) {
        _free(order_update->items);
        order_update->items = NULL;
    }
    if (order_update->language) {
        language_code_free(order_update->language);
        order_update->language = NULL;
    }
    if (order_update->order_status) {
        order_status_free(order_update->order_status);
        order_update->order_status = NULL;
    }
    if (order_update->payment_method) {
        payment_method_free(order_update->payment_method);
        order_update->payment_method = NULL;
    }
    if (order_update->shipping_address) {
        _free(order_update->shipping_address);
        order_update->shipping_address = NULL;
    }
    if (order_update->shipping_cost) {
        free(order_update->shipping_cost);
        order_update->shipping_cost = NULL;
    }
    if (order_update->shipping_method) {
        free(order_update->shipping_method);
        order_update->shipping_method = NULL;
    }
    if (order_update->shipping_weight) {
        free(order_update->shipping_weight);
        order_update->shipping_weight = NULL;
    }
    if (order_update->tags) {
        list_ForEach(listEntry, order_update->tags) {
            free(listEntry->data);
        }
        list_freeList(order_update->tags);
        order_update->tags = NULL;
    }
    if (order_update->total_cost) {
        free(order_update->total_cost);
        order_update->total_cost = NULL;
    }
    free(order_update);
}

cJSON *order_update_convertToJSON(order_update_t *order_update) {
    cJSON *item = cJSON_CreateObject();

    // order_update->audit_log
    if(order_update->audit_log) {
    cJSON *audit_log_local_JSON = _convertToJSON(order_update->audit_log);
    if(audit_log_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "auditLog", audit_log_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // order_update->currency
    if(order_update->currency) {
    if(cJSON_AddStringToObject(item, "currency", order_update->currency) == NULL) {
    goto fail; //String
    }
    }


    // order_update->customer_id
    if(order_update->customer_id) {
    if(cJSON_AddStringToObject(item, "customerId", order_update->customer_id) == NULL) {
    goto fail; //String
    }
    }


    // order_update->external_reference
    if(order_update->external_reference) {
    if(cJSON_AddStringToObject(item, "externalReference", order_update->external_reference) == NULL) {
    goto fail; //String
    }
    }


    // order_update->invoice_address
    if(order_update->invoice_address) {
    cJSON *invoice_address_local_JSON = _convertToJSON(order_update->invoice_address);
    if(invoice_address_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "invoiceAddress", invoice_address_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // order_update->items
    if(order_update->items) {
    cJSON *items_local_JSON = _convertToJSON(order_update->items);
    if(items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "items", items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // order_update->language
    if(order_update->language) {
    cJSON *language_local_JSON = language_code_convertToJSON(order_update->language);
    if(language_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "language", language_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // order_update->order_status
    if(order_update->order_status) {
    cJSON *order_status_local_JSON = order_status_convertToJSON(order_update->order_status);
    if(order_status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "orderStatus", order_status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // order_update->payment_method
    if(order_update->payment_method) {
    cJSON *payment_method_local_JSON = payment_method_convertToJSON(order_update->payment_method);
    if(payment_method_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "paymentMethod", payment_method_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // order_update->shipping_address
    if(order_update->shipping_address) {
    cJSON *shipping_address_local_JSON = _convertToJSON(order_update->shipping_address);
    if(shipping_address_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "shippingAddress", shipping_address_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // order_update->shipping_cost
    if(order_update->shipping_cost) {
    if(cJSON_AddStringToObject(item, "shippingCost", order_update->shipping_cost) == NULL) {
    goto fail; //String
    }
    }


    // order_update->shipping_method
    if(order_update->shipping_method) {
    if(cJSON_AddStringToObject(item, "shippingMethod", order_update->shipping_method) == NULL) {
    goto fail; //String
    }
    }


    // order_update->shipping_weight
    if(order_update->shipping_weight) {
    if(cJSON_AddStringToObject(item, "shippingWeight", order_update->shipping_weight) == NULL) {
    goto fail; //String
    }
    }


    // order_update->tags
    if(order_update->tags) {
    cJSON *tags = cJSON_AddArrayToObject(item, "tags");
    if(tags == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *tagsListEntry;
    list_ForEach(tagsListEntry, order_update->tags) {
    if(cJSON_AddStringToObject(tags, "", tagsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // order_update->total_cost
    if(order_update->total_cost) {
    if(cJSON_AddStringToObject(item, "totalCost", order_update->total_cost) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

order_update_t *order_update_parseFromJSON(cJSON *order_updateJSON){

    order_update_t *order_update_local_var = NULL;

    // define the local variable for order_update->audit_log
    _t *audit_log_local_nonprim = NULL;

    char *currency_local_str = NULL;

    char *customer_id_local_str = NULL;

    char *external_reference_local_str = NULL;

    // define the local variable for order_update->invoice_address
    _t *invoice_address_local_nonprim = NULL;

    // define the local variable for order_update->items
    _t *items_local_nonprim = NULL;

    // define the local variable for order_update->language
    language_code_t *language_local_nonprim = NULL;

    // define the local variable for order_update->order_status
    order_status_t *order_status_local_nonprim = NULL;

    // define the local variable for order_update->payment_method
    payment_method_t *payment_method_local_nonprim = NULL;

    // define the local variable for order_update->shipping_address
    _t *shipping_address_local_nonprim = NULL;

    char *shipping_cost_local_str = NULL;

    char *shipping_method_local_str = NULL;

    char *shipping_weight_local_str = NULL;

    // define the local list for order_update->tags
    list_t *tagsList = NULL;

    char *total_cost_local_str = NULL;

    // order_update->audit_log
    cJSON *audit_log = cJSON_GetObjectItemCaseSensitive(order_updateJSON, "auditLog");
    if (cJSON_IsNull(audit_log)) {
        audit_log = NULL;
    }
    if (audit_log) { 
    audit_log_local_nonprim = _parseFromJSON(audit_log); //custom
    }

    // order_update->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(order_updateJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (currency) { 
    if(!cJSON_IsString(currency) && !cJSON_IsNull(currency))
    {
    goto end; //String
    }
    }

    // order_update->customer_id
    cJSON *customer_id = cJSON_GetObjectItemCaseSensitive(order_updateJSON, "customerId");
    if (cJSON_IsNull(customer_id)) {
        customer_id = NULL;
    }
    if (customer_id) { 
    if(!cJSON_IsString(customer_id) && !cJSON_IsNull(customer_id))
    {
    goto end; //String
    }
    }

    // order_update->external_reference
    cJSON *external_reference = cJSON_GetObjectItemCaseSensitive(order_updateJSON, "externalReference");
    if (cJSON_IsNull(external_reference)) {
        external_reference = NULL;
    }
    if (external_reference) { 
    if(!cJSON_IsString(external_reference) && !cJSON_IsNull(external_reference))
    {
    goto end; //String
    }
    }

    // order_update->invoice_address
    cJSON *invoice_address = cJSON_GetObjectItemCaseSensitive(order_updateJSON, "invoiceAddress");
    if (cJSON_IsNull(invoice_address)) {
        invoice_address = NULL;
    }
    if (invoice_address) { 
    invoice_address_local_nonprim = _parseFromJSON(invoice_address); //custom
    }

    // order_update->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(order_updateJSON, "items");
    if (cJSON_IsNull(items)) {
        items = NULL;
    }
    if (items) { 
    items_local_nonprim = _parseFromJSON(items); //custom
    }

    // order_update->language
    cJSON *language = cJSON_GetObjectItemCaseSensitive(order_updateJSON, "language");
    if (cJSON_IsNull(language)) {
        language = NULL;
    }
    if (language) { 
    language_local_nonprim = language_code_parseFromJSON(language); //custom
    }

    // order_update->order_status
    cJSON *order_status = cJSON_GetObjectItemCaseSensitive(order_updateJSON, "orderStatus");
    if (cJSON_IsNull(order_status)) {
        order_status = NULL;
    }
    if (order_status) { 
    order_status_local_nonprim = order_status_parseFromJSON(order_status); //custom
    }

    // order_update->payment_method
    cJSON *payment_method = cJSON_GetObjectItemCaseSensitive(order_updateJSON, "paymentMethod");
    if (cJSON_IsNull(payment_method)) {
        payment_method = NULL;
    }
    if (payment_method) { 
    payment_method_local_nonprim = payment_method_parseFromJSON(payment_method); //custom
    }

    // order_update->shipping_address
    cJSON *shipping_address = cJSON_GetObjectItemCaseSensitive(order_updateJSON, "shippingAddress");
    if (cJSON_IsNull(shipping_address)) {
        shipping_address = NULL;
    }
    if (shipping_address) { 
    shipping_address_local_nonprim = _parseFromJSON(shipping_address); //custom
    }

    // order_update->shipping_cost
    cJSON *shipping_cost = cJSON_GetObjectItemCaseSensitive(order_updateJSON, "shippingCost");
    if (cJSON_IsNull(shipping_cost)) {
        shipping_cost = NULL;
    }
    if (shipping_cost) { 
    if(!cJSON_IsString(shipping_cost) && !cJSON_IsNull(shipping_cost))
    {
    goto end; //String
    }
    }

    // order_update->shipping_method
    cJSON *shipping_method = cJSON_GetObjectItemCaseSensitive(order_updateJSON, "shippingMethod");
    if (cJSON_IsNull(shipping_method)) {
        shipping_method = NULL;
    }
    if (shipping_method) { 
    if(!cJSON_IsString(shipping_method) && !cJSON_IsNull(shipping_method))
    {
    goto end; //String
    }
    }

    // order_update->shipping_weight
    cJSON *shipping_weight = cJSON_GetObjectItemCaseSensitive(order_updateJSON, "shippingWeight");
    if (cJSON_IsNull(shipping_weight)) {
        shipping_weight = NULL;
    }
    if (shipping_weight) { 
    if(!cJSON_IsString(shipping_weight) && !cJSON_IsNull(shipping_weight))
    {
    goto end; //String
    }
    }

    // order_update->tags
    cJSON *tags = cJSON_GetObjectItemCaseSensitive(order_updateJSON, "tags");
    if (cJSON_IsNull(tags)) {
        tags = NULL;
    }
    if (tags) { 
    cJSON *tags_local = NULL;
    if(!cJSON_IsArray(tags)) {
        goto end;//primitive container
    }
    tagsList = list_createList();

    cJSON_ArrayForEach(tags_local, tags)
    {
        if(!cJSON_IsString(tags_local))
        {
            goto end;
        }
        list_addElement(tagsList , strdup(tags_local->valuestring));
    }
    }

    // order_update->total_cost
    cJSON *total_cost = cJSON_GetObjectItemCaseSensitive(order_updateJSON, "totalCost");
    if (cJSON_IsNull(total_cost)) {
        total_cost = NULL;
    }
    if (total_cost) { 
    if(!cJSON_IsString(total_cost) && !cJSON_IsNull(total_cost))
    {
    goto end; //String
    }
    }


    if (currency && !cJSON_IsNull(currency)) currency_local_str = strdup(currency->valuestring);
    if (customer_id && !cJSON_IsNull(customer_id)) customer_id_local_str = strdup(customer_id->valuestring);
    if (external_reference && !cJSON_IsNull(external_reference)) external_reference_local_str = strdup(external_reference->valuestring);
    if (shipping_cost && !cJSON_IsNull(shipping_cost)) shipping_cost_local_str = strdup(shipping_cost->valuestring);
    if (shipping_method && !cJSON_IsNull(shipping_method)) shipping_method_local_str = strdup(shipping_method->valuestring);
    if (shipping_weight && !cJSON_IsNull(shipping_weight)) shipping_weight_local_str = strdup(shipping_weight->valuestring);
    if (total_cost && !cJSON_IsNull(total_cost)) total_cost_local_str = strdup(total_cost->valuestring);

    order_update_local_var = order_update_create_internal (
        audit_log ? audit_log_local_nonprim : NULL,
        currency_local_str,
        customer_id_local_str,
        external_reference_local_str,
        invoice_address ? invoice_address_local_nonprim : NULL,
        items ? items_local_nonprim : NULL,
        language ? language_local_nonprim : NULL,
        order_status ? order_status_local_nonprim : NULL,
        payment_method ? payment_method_local_nonprim : NULL,
        shipping_address ? shipping_address_local_nonprim : NULL,
        shipping_cost_local_str,
        shipping_method_local_str,
        shipping_weight_local_str,
        tags ? tagsList : NULL,
        total_cost_local_str
        );

    if (!order_update_local_var) {
        goto end;
    }

    return order_update_local_var;
end:
    if (audit_log_local_nonprim) {
        _free(audit_log_local_nonprim);
        audit_log_local_nonprim = NULL;
    }
    if (currency_local_str) {
        free(currency_local_str);
        currency_local_str = NULL;
    }
    if (customer_id_local_str) {
        free(customer_id_local_str);
        customer_id_local_str = NULL;
    }
    if (external_reference_local_str) {
        free(external_reference_local_str);
        external_reference_local_str = NULL;
    }
    if (invoice_address_local_nonprim) {
        _free(invoice_address_local_nonprim);
        invoice_address_local_nonprim = NULL;
    }
    if (items_local_nonprim) {
        _free(items_local_nonprim);
        items_local_nonprim = NULL;
    }
    if (language_local_nonprim) {
        language_code_free(language_local_nonprim);
        language_local_nonprim = NULL;
    }
    if (order_status_local_nonprim) {
        order_status_free(order_status_local_nonprim);
        order_status_local_nonprim = NULL;
    }
    if (payment_method_local_nonprim) {
        payment_method_free(payment_method_local_nonprim);
        payment_method_local_nonprim = NULL;
    }
    if (shipping_address_local_nonprim) {
        _free(shipping_address_local_nonprim);
        shipping_address_local_nonprim = NULL;
    }
    if (shipping_cost_local_str) {
        free(shipping_cost_local_str);
        shipping_cost_local_str = NULL;
    }
    if (shipping_method_local_str) {
        free(shipping_method_local_str);
        shipping_method_local_str = NULL;
    }
    if (shipping_weight_local_str) {
        free(shipping_weight_local_str);
        shipping_weight_local_str = NULL;
    }
    if (tagsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, tagsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(tagsList);
        tagsList = NULL;
    }
    if (total_cost_local_str) {
        free(total_cost_local_str);
        total_cost_local_str = NULL;
    }
    return NULL;

}
