#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "order_create.h"



static order_create_t *order_create_create_internal(
    any_type_t *audit_log,
    char *currency,
    char *customer_id,
    char *external_reference,
    any_type_t *invoice_address,
    any_type_t *items,
    simplebilly_api_language_code__e language,
    simplebilly_api_order_status__e order_status,
    simplebilly_api_payment_method__e payment_method,
    any_type_t *shipping_address,
    char *shipping_cost,
    char *shipping_method,
    char *shipping_weight,
    list_t *tags,
    char *total_cost
    ) {
    order_create_t *order_create_local_var = malloc(sizeof(order_create_t));
    if (!order_create_local_var) {
        return NULL;
    }
    memset(order_create_local_var, 0, sizeof(order_create_t));
    order_create_local_var->_library_owned = 1;
    order_create_local_var->audit_log = audit_log;
    order_create_local_var->currency = currency;
    order_create_local_var->customer_id = customer_id;
    order_create_local_var->external_reference = external_reference;
    order_create_local_var->invoice_address = invoice_address;
    order_create_local_var->items = items;
    order_create_local_var->language = language;
    order_create_local_var->order_status = order_status;
    order_create_local_var->payment_method = payment_method;
    order_create_local_var->shipping_address = shipping_address;
    order_create_local_var->shipping_cost = shipping_cost;
    order_create_local_var->shipping_method = shipping_method;
    order_create_local_var->shipping_weight = shipping_weight;
    order_create_local_var->tags = tags;
    order_create_local_var->total_cost = total_cost;
    return order_create_local_var;
}

__attribute__((deprecated)) order_create_t *order_create_create(
    any_type_t *audit_log,
    char *currency,
    char *customer_id,
    char *external_reference,
    any_type_t *invoice_address,
    any_type_t *items,
    simplebilly_api_language_code__e language,
    simplebilly_api_order_status__e order_status,
    simplebilly_api_payment_method__e payment_method,
    any_type_t *shipping_address,
    char *shipping_cost,
    char *shipping_method,
    char *shipping_weight,
    list_t *tags,
    char *total_cost
    ) {
    order_create_t *result = order_create_create_internal (
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

void order_create_free(order_create_t *order_create) {
    if(NULL == order_create){
        return ;
    }
    if(order_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "order_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (order_create->audit_log) {
        _free(order_create->audit_log);
        order_create->audit_log = NULL;
    }
    if (order_create->currency) {
        free(order_create->currency);
        order_create->currency = NULL;
    }
    if (order_create->customer_id) {
        free(order_create->customer_id);
        order_create->customer_id = NULL;
    }
    if (order_create->external_reference) {
        free(order_create->external_reference);
        order_create->external_reference = NULL;
    }
    if (order_create->invoice_address) {
        _free(order_create->invoice_address);
        order_create->invoice_address = NULL;
    }
    if (order_create->items) {
        _free(order_create->items);
        order_create->items = NULL;
    }
    if (order_create->shipping_address) {
        _free(order_create->shipping_address);
        order_create->shipping_address = NULL;
    }
    if (order_create->shipping_cost) {
        free(order_create->shipping_cost);
        order_create->shipping_cost = NULL;
    }
    if (order_create->shipping_method) {
        free(order_create->shipping_method);
        order_create->shipping_method = NULL;
    }
    if (order_create->shipping_weight) {
        free(order_create->shipping_weight);
        order_create->shipping_weight = NULL;
    }
    if (order_create->tags) {
        list_ForEach(listEntry, order_create->tags) {
            free(listEntry->data);
        }
        list_freeList(order_create->tags);
        order_create->tags = NULL;
    }
    if (order_create->total_cost) {
        free(order_create->total_cost);
        order_create->total_cost = NULL;
    }
    free(order_create);
}

cJSON *order_create_convertToJSON(order_create_t *order_create) {
    cJSON *item = cJSON_CreateObject();

    // order_create->audit_log
    if(order_create->audit_log) {
    cJSON *audit_log_local_JSON = _convertToJSON(order_create->audit_log);
    if(audit_log_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "auditLog", audit_log_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // order_create->currency
    if (!order_create->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", order_create->currency) == NULL) {
    goto fail; //String
    }


    // order_create->customer_id
    if (!order_create->customer_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "customerId", order_create->customer_id) == NULL) {
    goto fail; //String
    }


    // order_create->external_reference
    if(order_create->external_reference) {
    if(cJSON_AddStringToObject(item, "externalReference", order_create->external_reference) == NULL) {
    goto fail; //String
    }
    }


    // order_create->invoice_address
    if(order_create->invoice_address) {
    cJSON *invoice_address_local_JSON = _convertToJSON(order_create->invoice_address);
    if(invoice_address_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "invoiceAddress", invoice_address_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // order_create->items
    if(order_create->items) {
    cJSON *items_local_JSON = _convertToJSON(order_create->items);
    if(items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "items", items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // order_create->language
    if(order_create->language != simplebilly_api_language_code__NULL) {
    cJSON *language_local_JSON = language_code_convertToJSON(order_create->language);
    if(language_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "language", language_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // order_create->order_status
    if (simplebilly_api_order_status__NULL == order_create->order_status) {
        goto fail;
    }
    cJSON *order_status_local_JSON = order_status_convertToJSON(order_create->order_status);
    if(order_status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "orderStatus", order_status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // order_create->payment_method
    if (simplebilly_api_payment_method__NULL == order_create->payment_method) {
        goto fail;
    }
    cJSON *payment_method_local_JSON = payment_method_convertToJSON(order_create->payment_method);
    if(payment_method_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "paymentMethod", payment_method_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // order_create->shipping_address
    if(order_create->shipping_address) {
    cJSON *shipping_address_local_JSON = _convertToJSON(order_create->shipping_address);
    if(shipping_address_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "shippingAddress", shipping_address_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // order_create->shipping_cost
    if (!order_create->shipping_cost) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "shippingCost", order_create->shipping_cost) == NULL) {
    goto fail; //String
    }


    // order_create->shipping_method
    if (!order_create->shipping_method) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "shippingMethod", order_create->shipping_method) == NULL) {
    goto fail; //String
    }


    // order_create->shipping_weight
    if (!order_create->shipping_weight) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "shippingWeight", order_create->shipping_weight) == NULL) {
    goto fail; //String
    }


    // order_create->tags
    if (!order_create->tags) {
        goto fail;
    }
    cJSON *tags = cJSON_AddArrayToObject(item, "tags");
    if(tags == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *tagsListEntry;
    list_ForEach(tagsListEntry, order_create->tags) {
    if(cJSON_AddStringToObject(tags, "", tagsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // order_create->total_cost
    if (!order_create->total_cost) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "totalCost", order_create->total_cost) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

order_create_t *order_create_parseFromJSON(cJSON *order_createJSON){

    order_create_t *order_create_local_var = NULL;

    // define the local variable for order_create->audit_log
    _t *audit_log_local_nonprim = NULL;

    char *currency_local_str = NULL;

    char *customer_id_local_str = NULL;

    char *external_reference_local_str = NULL;

    // define the local variable for order_create->invoice_address
    _t *invoice_address_local_nonprim = NULL;

    // define the local variable for order_create->items
    _t *items_local_nonprim = NULL;

    // define the local variable for order_create->language
    simplebilly_api_language_code__e language_local_nonprim = 0;

    // define the local variable for order_create->order_status
    simplebilly_api_order_status__e order_status_local_nonprim = 0;

    // define the local variable for order_create->payment_method
    simplebilly_api_payment_method__e payment_method_local_nonprim = 0;

    // define the local variable for order_create->shipping_address
    _t *shipping_address_local_nonprim = NULL;

    char *shipping_cost_local_str = NULL;

    char *shipping_method_local_str = NULL;

    char *shipping_weight_local_str = NULL;

    // define the local list for order_create->tags
    list_t *tagsList = NULL;

    char *total_cost_local_str = NULL;

    // order_create->audit_log
    cJSON *audit_log = cJSON_GetObjectItemCaseSensitive(order_createJSON, "auditLog");
    if (cJSON_IsNull(audit_log)) {
        audit_log = NULL;
    }
    if (audit_log) { 
    audit_log_local_nonprim = _parseFromJSON(audit_log); //custom
    }

    // order_create->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(order_createJSON, "currency");
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

    // order_create->customer_id
    cJSON *customer_id = cJSON_GetObjectItemCaseSensitive(order_createJSON, "customerId");
    if (cJSON_IsNull(customer_id)) {
        customer_id = NULL;
    }
    if (!customer_id) {
        goto end;
    }

    
    if(!cJSON_IsString(customer_id))
    {
    goto end; //String
    }

    // order_create->external_reference
    cJSON *external_reference = cJSON_GetObjectItemCaseSensitive(order_createJSON, "externalReference");
    if (cJSON_IsNull(external_reference)) {
        external_reference = NULL;
    }
    if (external_reference) { 
    if(!cJSON_IsString(external_reference) && !cJSON_IsNull(external_reference))
    {
    goto end; //String
    }
    }

    // order_create->invoice_address
    cJSON *invoice_address = cJSON_GetObjectItemCaseSensitive(order_createJSON, "invoiceAddress");
    if (cJSON_IsNull(invoice_address)) {
        invoice_address = NULL;
    }
    if (invoice_address) { 
    invoice_address_local_nonprim = _parseFromJSON(invoice_address); //custom
    }

    // order_create->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(order_createJSON, "items");
    if (cJSON_IsNull(items)) {
        items = NULL;
    }
    if (items) { 
    items_local_nonprim = _parseFromJSON(items); //custom
    }

    // order_create->language
    cJSON *language = cJSON_GetObjectItemCaseSensitive(order_createJSON, "language");
    if (cJSON_IsNull(language)) {
        language = NULL;
    }
    if (language) { 
    language_local_nonprim = language_code_parseFromJSON(language); //custom
    }

    // order_create->order_status
    cJSON *order_status = cJSON_GetObjectItemCaseSensitive(order_createJSON, "orderStatus");
    if (cJSON_IsNull(order_status)) {
        order_status = NULL;
    }
    if (!order_status) {
        goto end;
    }

    
    order_status_local_nonprim = order_status_parseFromJSON(order_status); //custom

    // order_create->payment_method
    cJSON *payment_method = cJSON_GetObjectItemCaseSensitive(order_createJSON, "paymentMethod");
    if (cJSON_IsNull(payment_method)) {
        payment_method = NULL;
    }
    if (!payment_method) {
        goto end;
    }

    
    payment_method_local_nonprim = payment_method_parseFromJSON(payment_method); //custom

    // order_create->shipping_address
    cJSON *shipping_address = cJSON_GetObjectItemCaseSensitive(order_createJSON, "shippingAddress");
    if (cJSON_IsNull(shipping_address)) {
        shipping_address = NULL;
    }
    if (shipping_address) { 
    shipping_address_local_nonprim = _parseFromJSON(shipping_address); //custom
    }

    // order_create->shipping_cost
    cJSON *shipping_cost = cJSON_GetObjectItemCaseSensitive(order_createJSON, "shippingCost");
    if (cJSON_IsNull(shipping_cost)) {
        shipping_cost = NULL;
    }
    if (!shipping_cost) {
        goto end;
    }

    
    if(!cJSON_IsString(shipping_cost))
    {
    goto end; //String
    }

    // order_create->shipping_method
    cJSON *shipping_method = cJSON_GetObjectItemCaseSensitive(order_createJSON, "shippingMethod");
    if (cJSON_IsNull(shipping_method)) {
        shipping_method = NULL;
    }
    if (!shipping_method) {
        goto end;
    }

    
    if(!cJSON_IsString(shipping_method))
    {
    goto end; //String
    }

    // order_create->shipping_weight
    cJSON *shipping_weight = cJSON_GetObjectItemCaseSensitive(order_createJSON, "shippingWeight");
    if (cJSON_IsNull(shipping_weight)) {
        shipping_weight = NULL;
    }
    if (!shipping_weight) {
        goto end;
    }

    
    if(!cJSON_IsString(shipping_weight))
    {
    goto end; //String
    }

    // order_create->tags
    cJSON *tags = cJSON_GetObjectItemCaseSensitive(order_createJSON, "tags");
    if (cJSON_IsNull(tags)) {
        tags = NULL;
    }
    if (!tags) {
        goto end;
    }

    
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

    // order_create->total_cost
    cJSON *total_cost = cJSON_GetObjectItemCaseSensitive(order_createJSON, "totalCost");
    if (cJSON_IsNull(total_cost)) {
        total_cost = NULL;
    }
    if (!total_cost) {
        goto end;
    }

    
    if(!cJSON_IsString(total_cost))
    {
    goto end; //String
    }


    if (currency && !cJSON_IsNull(currency)) currency_local_str = strdup(currency->valuestring);
    if (customer_id && !cJSON_IsNull(customer_id)) customer_id_local_str = strdup(customer_id->valuestring);
    if (external_reference && !cJSON_IsNull(external_reference)) external_reference_local_str = strdup(external_reference->valuestring);
    if (shipping_cost && !cJSON_IsNull(shipping_cost)) shipping_cost_local_str = strdup(shipping_cost->valuestring);
    if (shipping_method && !cJSON_IsNull(shipping_method)) shipping_method_local_str = strdup(shipping_method->valuestring);
    if (shipping_weight && !cJSON_IsNull(shipping_weight)) shipping_weight_local_str = strdup(shipping_weight->valuestring);
    if (total_cost && !cJSON_IsNull(total_cost)) total_cost_local_str = strdup(total_cost->valuestring);

    order_create_local_var = order_create_create_internal (
        audit_log ? audit_log_local_nonprim : NULL,
        currency_local_str,
        customer_id_local_str,
        external_reference_local_str,
        invoice_address ? invoice_address_local_nonprim : NULL,
        items ? items_local_nonprim : NULL,
        language ? language_local_nonprim : 0,
        order_status_local_nonprim,
        payment_method_local_nonprim,
        shipping_address ? shipping_address_local_nonprim : NULL,
        shipping_cost_local_str,
        shipping_method_local_str,
        shipping_weight_local_str,
        tagsList,
        total_cost_local_str
        );

    if (!order_create_local_var) {
        goto end;
    }

    return order_create_local_var;
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
        language_local_nonprim = 0;
    }
    if (order_status_local_nonprim) {
        order_status_local_nonprim = 0;
    }
    if (payment_method_local_nonprim) {
        payment_method_local_nonprim = 0;
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
