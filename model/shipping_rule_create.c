#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shipping_rule_create.h"



static shipping_rule_create_t *shipping_rule_create_create_internal(
    char *carrier,
    country_code_t *country,
    char *delivery_time,
    int *is_active,
    double *max_weight_kg,
    double *min_weight_kg,
    char *name,
    char *notes,
    char *price,
    int *priority
    ) {
    shipping_rule_create_t *shipping_rule_create_local_var = malloc(sizeof(shipping_rule_create_t));
    if (!shipping_rule_create_local_var) {
        return NULL;
    }
    memset(shipping_rule_create_local_var, 0, sizeof(shipping_rule_create_t));
    shipping_rule_create_local_var->_library_owned = 1;
    shipping_rule_create_local_var->carrier = carrier;
    shipping_rule_create_local_var->country = country;
    shipping_rule_create_local_var->delivery_time = delivery_time;
    shipping_rule_create_local_var->is_active = is_active;
    shipping_rule_create_local_var->max_weight_kg = max_weight_kg;
    shipping_rule_create_local_var->min_weight_kg = min_weight_kg;
    shipping_rule_create_local_var->name = name;
    shipping_rule_create_local_var->notes = notes;
    shipping_rule_create_local_var->price = price;
    shipping_rule_create_local_var->priority = priority;
    return shipping_rule_create_local_var;
}

__attribute__((deprecated)) shipping_rule_create_t *shipping_rule_create_create(
    char *carrier,
    country_code_t *country,
    char *delivery_time,
    int *is_active,
    double *max_weight_kg,
    double *min_weight_kg,
    char *name,
    char *notes,
    char *price,
    int *priority
    ) {
    int *is_active_copy = NULL;
    if (is_active) {
        is_active_copy = malloc(sizeof(int));
        if (is_active_copy) *is_active_copy = *is_active;
    }
    double *max_weight_kg_copy = NULL;
    if (max_weight_kg) {
        max_weight_kg_copy = malloc(sizeof(double));
        if (max_weight_kg_copy) *max_weight_kg_copy = *max_weight_kg;
    }
    double *min_weight_kg_copy = NULL;
    if (min_weight_kg) {
        min_weight_kg_copy = malloc(sizeof(double));
        if (min_weight_kg_copy) *min_weight_kg_copy = *min_weight_kg;
    }
    int *priority_copy = NULL;
    if (priority) {
        priority_copy = malloc(sizeof(int));
        if (priority_copy) *priority_copy = *priority;
    }
    shipping_rule_create_t *result = shipping_rule_create_create_internal (
        carrier,
        country,
        delivery_time,
        is_active_copy,
        max_weight_kg_copy,
        min_weight_kg_copy,
        name,
        notes,
        price,
        priority_copy
        );
    if (!result) {
        free(is_active_copy);
        free(max_weight_kg_copy);
        free(min_weight_kg_copy);
        free(priority_copy);
    }
    return result;
}

void shipping_rule_create_free(shipping_rule_create_t *shipping_rule_create) {
    if(NULL == shipping_rule_create){
        return ;
    }
    if(shipping_rule_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "shipping_rule_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (shipping_rule_create->carrier) {
        free(shipping_rule_create->carrier);
        shipping_rule_create->carrier = NULL;
    }
    if (shipping_rule_create->country) {
        country_code_free(shipping_rule_create->country);
        shipping_rule_create->country = NULL;
    }
    if (shipping_rule_create->delivery_time) {
        free(shipping_rule_create->delivery_time);
        shipping_rule_create->delivery_time = NULL;
    }
    if (shipping_rule_create->is_active) {
        free(shipping_rule_create->is_active);
        shipping_rule_create->is_active = NULL;
    }
    if (shipping_rule_create->max_weight_kg) {
        free(shipping_rule_create->max_weight_kg);
        shipping_rule_create->max_weight_kg = NULL;
    }
    if (shipping_rule_create->min_weight_kg) {
        free(shipping_rule_create->min_weight_kg);
        shipping_rule_create->min_weight_kg = NULL;
    }
    if (shipping_rule_create->name) {
        free(shipping_rule_create->name);
        shipping_rule_create->name = NULL;
    }
    if (shipping_rule_create->notes) {
        free(shipping_rule_create->notes);
        shipping_rule_create->notes = NULL;
    }
    if (shipping_rule_create->price) {
        free(shipping_rule_create->price);
        shipping_rule_create->price = NULL;
    }
    if (shipping_rule_create->priority) {
        free(shipping_rule_create->priority);
        shipping_rule_create->priority = NULL;
    }
    free(shipping_rule_create);
}

cJSON *shipping_rule_create_convertToJSON(shipping_rule_create_t *shipping_rule_create) {
    cJSON *item = cJSON_CreateObject();

    // shipping_rule_create->carrier
    if(shipping_rule_create->carrier) {
    if(cJSON_AddStringToObject(item, "carrier", shipping_rule_create->carrier) == NULL) {
    goto fail; //String
    }
    }


    // shipping_rule_create->country
    if(shipping_rule_create->country) {
    cJSON *country_local_JSON = country_code_convertToJSON(shipping_rule_create->country);
    if(country_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "country", country_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // shipping_rule_create->delivery_time
    if(shipping_rule_create->delivery_time) {
    if(cJSON_AddStringToObject(item, "deliveryTime", shipping_rule_create->delivery_time) == NULL) {
    goto fail; //String
    }
    }


    // shipping_rule_create->is_active
    if(shipping_rule_create->is_active) {
    if(cJSON_AddBoolToObject(item, "isActive", *shipping_rule_create->is_active) == NULL) {
    goto fail; //Bool
    }
    }


    // shipping_rule_create->max_weight_kg
    if(shipping_rule_create->max_weight_kg) {
    if(cJSON_AddNumberToObject(item, "maxWeightKg", *shipping_rule_create->max_weight_kg) == NULL) {
    goto fail; //Numeric
    }
    }


    // shipping_rule_create->min_weight_kg
    if(shipping_rule_create->min_weight_kg) {
    if(cJSON_AddNumberToObject(item, "minWeightKg", *shipping_rule_create->min_weight_kg) == NULL) {
    goto fail; //Numeric
    }
    }


    // shipping_rule_create->name
    if (!shipping_rule_create->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", shipping_rule_create->name) == NULL) {
    goto fail; //String
    }


    // shipping_rule_create->notes
    if(shipping_rule_create->notes) {
    if(cJSON_AddStringToObject(item, "notes", shipping_rule_create->notes) == NULL) {
    goto fail; //String
    }
    }


    // shipping_rule_create->price
    if (!shipping_rule_create->price) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "price", shipping_rule_create->price) == NULL) {
    goto fail; //String
    }


    // shipping_rule_create->priority
    if(shipping_rule_create->priority) {
    if(cJSON_AddNumberToObject(item, "priority", *shipping_rule_create->priority) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

shipping_rule_create_t *shipping_rule_create_parseFromJSON(cJSON *shipping_rule_createJSON){

    shipping_rule_create_t *shipping_rule_create_local_var = NULL;

    char *carrier_local_str = NULL;

    // define the local variable for shipping_rule_create->country
    country_code_t *country_local_nonprim = NULL;

    char *delivery_time_local_str = NULL;

    // define the local variable for shipping_rule_create->is_active
    int *is_active_local_var = NULL;

    // define the local variable for shipping_rule_create->max_weight_kg
    double *max_weight_kg_local_var = NULL;

    // define the local variable for shipping_rule_create->min_weight_kg
    double *min_weight_kg_local_var = NULL;

    char *name_local_str = NULL;

    char *notes_local_str = NULL;

    char *price_local_str = NULL;

    // define the local variable for shipping_rule_create->priority
    int *priority_local_var = NULL;

    // shipping_rule_create->carrier
    cJSON *carrier = cJSON_GetObjectItemCaseSensitive(shipping_rule_createJSON, "carrier");
    if (cJSON_IsNull(carrier)) {
        carrier = NULL;
    }
    if (carrier) { 
    if(!cJSON_IsString(carrier) && !cJSON_IsNull(carrier))
    {
    goto end; //String
    }
    }

    // shipping_rule_create->country
    cJSON *country = cJSON_GetObjectItemCaseSensitive(shipping_rule_createJSON, "country");
    if (cJSON_IsNull(country)) {
        country = NULL;
    }
    if (country) { 
    country_local_nonprim = country_code_parseFromJSON(country); //custom
    }

    // shipping_rule_create->delivery_time
    cJSON *delivery_time = cJSON_GetObjectItemCaseSensitive(shipping_rule_createJSON, "deliveryTime");
    if (cJSON_IsNull(delivery_time)) {
        delivery_time = NULL;
    }
    if (delivery_time) { 
    if(!cJSON_IsString(delivery_time) && !cJSON_IsNull(delivery_time))
    {
    goto end; //String
    }
    }

    // shipping_rule_create->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(shipping_rule_createJSON, "isActive");
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

    // shipping_rule_create->max_weight_kg
    cJSON *max_weight_kg = cJSON_GetObjectItemCaseSensitive(shipping_rule_createJSON, "maxWeightKg");
    if (cJSON_IsNull(max_weight_kg)) {
        max_weight_kg = NULL;
    }
    if (max_weight_kg) { 
    if(!cJSON_IsNumber(max_weight_kg))
    {
    goto end; //Numeric
    }
    max_weight_kg_local_var = malloc(sizeof(double));
    if(!max_weight_kg_local_var)
    {
        goto end;
    }
    *max_weight_kg_local_var = max_weight_kg->valuedouble;
    }

    // shipping_rule_create->min_weight_kg
    cJSON *min_weight_kg = cJSON_GetObjectItemCaseSensitive(shipping_rule_createJSON, "minWeightKg");
    if (cJSON_IsNull(min_weight_kg)) {
        min_weight_kg = NULL;
    }
    if (min_weight_kg) { 
    if(!cJSON_IsNumber(min_weight_kg))
    {
    goto end; //Numeric
    }
    min_weight_kg_local_var = malloc(sizeof(double));
    if(!min_weight_kg_local_var)
    {
        goto end;
    }
    *min_weight_kg_local_var = min_weight_kg->valuedouble;
    }

    // shipping_rule_create->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(shipping_rule_createJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // shipping_rule_create->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(shipping_rule_createJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // shipping_rule_create->price
    cJSON *price = cJSON_GetObjectItemCaseSensitive(shipping_rule_createJSON, "price");
    if (cJSON_IsNull(price)) {
        price = NULL;
    }
    if (!price) {
        goto end;
    }

    
    if(!cJSON_IsString(price))
    {
    goto end; //String
    }

    // shipping_rule_create->priority
    cJSON *priority = cJSON_GetObjectItemCaseSensitive(shipping_rule_createJSON, "priority");
    if (cJSON_IsNull(priority)) {
        priority = NULL;
    }
    if (priority) { 
    if(!cJSON_IsNumber(priority))
    {
    goto end; //Numeric
    }
    priority_local_var = malloc(sizeof(int));
    if(!priority_local_var)
    {
        goto end;
    }
    *priority_local_var = priority->valuedouble;
    }


    if (carrier && !cJSON_IsNull(carrier)) carrier_local_str = strdup(carrier->valuestring);
    if (delivery_time && !cJSON_IsNull(delivery_time)) delivery_time_local_str = strdup(delivery_time->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (price && !cJSON_IsNull(price)) price_local_str = strdup(price->valuestring);

    shipping_rule_create_local_var = shipping_rule_create_create_internal (
        carrier_local_str,
        country ? country_local_nonprim : NULL,
        delivery_time_local_str,
        is_active_local_var,
        max_weight_kg_local_var,
        min_weight_kg_local_var,
        name_local_str,
        notes_local_str,
        price_local_str,
        priority_local_var
        );

    if (!shipping_rule_create_local_var) {
        goto end;
    }

    return shipping_rule_create_local_var;
end:
    if (carrier_local_str) {
        free(carrier_local_str);
        carrier_local_str = NULL;
    }
    if (country_local_nonprim) {
        country_code_free(country_local_nonprim);
        country_local_nonprim = NULL;
    }
    if (delivery_time_local_str) {
        free(delivery_time_local_str);
        delivery_time_local_str = NULL;
    }
    if (is_active_local_var) {
        free(is_active_local_var);
        is_active_local_var = NULL;
    }
    if (max_weight_kg_local_var) {
        free(max_weight_kg_local_var);
        max_weight_kg_local_var = NULL;
    }
    if (min_weight_kg_local_var) {
        free(min_weight_kg_local_var);
        min_weight_kg_local_var = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (price_local_str) {
        free(price_local_str);
        price_local_str = NULL;
    }
    if (priority_local_var) {
        free(priority_local_var);
        priority_local_var = NULL;
    }
    return NULL;

}
