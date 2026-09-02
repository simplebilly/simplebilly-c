#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shipping_rule_update.h"



static shipping_rule_update_t *shipping_rule_update_create_internal(
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
    shipping_rule_update_t *shipping_rule_update_local_var = malloc(sizeof(shipping_rule_update_t));
    if (!shipping_rule_update_local_var) {
        return NULL;
    }
    memset(shipping_rule_update_local_var, 0, sizeof(shipping_rule_update_t));
    shipping_rule_update_local_var->_library_owned = 1;
    shipping_rule_update_local_var->carrier = carrier;
    shipping_rule_update_local_var->country = country;
    shipping_rule_update_local_var->delivery_time = delivery_time;
    shipping_rule_update_local_var->is_active = is_active;
    shipping_rule_update_local_var->max_weight_kg = max_weight_kg;
    shipping_rule_update_local_var->min_weight_kg = min_weight_kg;
    shipping_rule_update_local_var->name = name;
    shipping_rule_update_local_var->notes = notes;
    shipping_rule_update_local_var->price = price;
    shipping_rule_update_local_var->priority = priority;
    return shipping_rule_update_local_var;
}

__attribute__((deprecated)) shipping_rule_update_t *shipping_rule_update_create(
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
    shipping_rule_update_t *result = shipping_rule_update_create_internal (
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

void shipping_rule_update_free(shipping_rule_update_t *shipping_rule_update) {
    if(NULL == shipping_rule_update){
        return ;
    }
    if(shipping_rule_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "shipping_rule_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (shipping_rule_update->carrier) {
        free(shipping_rule_update->carrier);
        shipping_rule_update->carrier = NULL;
    }
    if (shipping_rule_update->country) {
        country_code_free(shipping_rule_update->country);
        shipping_rule_update->country = NULL;
    }
    if (shipping_rule_update->delivery_time) {
        free(shipping_rule_update->delivery_time);
        shipping_rule_update->delivery_time = NULL;
    }
    if (shipping_rule_update->is_active) {
        free(shipping_rule_update->is_active);
        shipping_rule_update->is_active = NULL;
    }
    if (shipping_rule_update->max_weight_kg) {
        free(shipping_rule_update->max_weight_kg);
        shipping_rule_update->max_weight_kg = NULL;
    }
    if (shipping_rule_update->min_weight_kg) {
        free(shipping_rule_update->min_weight_kg);
        shipping_rule_update->min_weight_kg = NULL;
    }
    if (shipping_rule_update->name) {
        free(shipping_rule_update->name);
        shipping_rule_update->name = NULL;
    }
    if (shipping_rule_update->notes) {
        free(shipping_rule_update->notes);
        shipping_rule_update->notes = NULL;
    }
    if (shipping_rule_update->price) {
        free(shipping_rule_update->price);
        shipping_rule_update->price = NULL;
    }
    if (shipping_rule_update->priority) {
        free(shipping_rule_update->priority);
        shipping_rule_update->priority = NULL;
    }
    free(shipping_rule_update);
}

cJSON *shipping_rule_update_convertToJSON(shipping_rule_update_t *shipping_rule_update) {
    cJSON *item = cJSON_CreateObject();

    // shipping_rule_update->carrier
    if(shipping_rule_update->carrier) {
    if(cJSON_AddStringToObject(item, "carrier", shipping_rule_update->carrier) == NULL) {
    goto fail; //String
    }
    }


    // shipping_rule_update->country
    if(shipping_rule_update->country) {
    cJSON *country_local_JSON = country_code_convertToJSON(shipping_rule_update->country);
    if(country_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "country", country_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // shipping_rule_update->delivery_time
    if(shipping_rule_update->delivery_time) {
    if(cJSON_AddStringToObject(item, "deliveryTime", shipping_rule_update->delivery_time) == NULL) {
    goto fail; //String
    }
    }


    // shipping_rule_update->is_active
    if(shipping_rule_update->is_active) {
    if(cJSON_AddBoolToObject(item, "isActive", *shipping_rule_update->is_active) == NULL) {
    goto fail; //Bool
    }
    }


    // shipping_rule_update->max_weight_kg
    if(shipping_rule_update->max_weight_kg) {
    if(cJSON_AddNumberToObject(item, "maxWeightKg", *shipping_rule_update->max_weight_kg) == NULL) {
    goto fail; //Numeric
    }
    }


    // shipping_rule_update->min_weight_kg
    if(shipping_rule_update->min_weight_kg) {
    if(cJSON_AddNumberToObject(item, "minWeightKg", *shipping_rule_update->min_weight_kg) == NULL) {
    goto fail; //Numeric
    }
    }


    // shipping_rule_update->name
    if(shipping_rule_update->name) {
    if(cJSON_AddStringToObject(item, "name", shipping_rule_update->name) == NULL) {
    goto fail; //String
    }
    }


    // shipping_rule_update->notes
    if(shipping_rule_update->notes) {
    if(cJSON_AddStringToObject(item, "notes", shipping_rule_update->notes) == NULL) {
    goto fail; //String
    }
    }


    // shipping_rule_update->price
    if(shipping_rule_update->price) {
    if(cJSON_AddStringToObject(item, "price", shipping_rule_update->price) == NULL) {
    goto fail; //String
    }
    }


    // shipping_rule_update->priority
    if(shipping_rule_update->priority) {
    if(cJSON_AddNumberToObject(item, "priority", *shipping_rule_update->priority) == NULL) {
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

shipping_rule_update_t *shipping_rule_update_parseFromJSON(cJSON *shipping_rule_updateJSON){

    shipping_rule_update_t *shipping_rule_update_local_var = NULL;

    char *carrier_local_str = NULL;

    // define the local variable for shipping_rule_update->country
    country_code_t *country_local_nonprim = NULL;

    char *delivery_time_local_str = NULL;

    // define the local variable for shipping_rule_update->is_active
    int *is_active_local_var = NULL;

    // define the local variable for shipping_rule_update->max_weight_kg
    double *max_weight_kg_local_var = NULL;

    // define the local variable for shipping_rule_update->min_weight_kg
    double *min_weight_kg_local_var = NULL;

    char *name_local_str = NULL;

    char *notes_local_str = NULL;

    char *price_local_str = NULL;

    // define the local variable for shipping_rule_update->priority
    int *priority_local_var = NULL;

    // shipping_rule_update->carrier
    cJSON *carrier = cJSON_GetObjectItemCaseSensitive(shipping_rule_updateJSON, "carrier");
    if (cJSON_IsNull(carrier)) {
        carrier = NULL;
    }
    if (carrier) { 
    if(!cJSON_IsString(carrier) && !cJSON_IsNull(carrier))
    {
    goto end; //String
    }
    }

    // shipping_rule_update->country
    cJSON *country = cJSON_GetObjectItemCaseSensitive(shipping_rule_updateJSON, "country");
    if (cJSON_IsNull(country)) {
        country = NULL;
    }
    if (country) { 
    country_local_nonprim = country_code_parseFromJSON(country); //custom
    }

    // shipping_rule_update->delivery_time
    cJSON *delivery_time = cJSON_GetObjectItemCaseSensitive(shipping_rule_updateJSON, "deliveryTime");
    if (cJSON_IsNull(delivery_time)) {
        delivery_time = NULL;
    }
    if (delivery_time) { 
    if(!cJSON_IsString(delivery_time) && !cJSON_IsNull(delivery_time))
    {
    goto end; //String
    }
    }

    // shipping_rule_update->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(shipping_rule_updateJSON, "isActive");
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

    // shipping_rule_update->max_weight_kg
    cJSON *max_weight_kg = cJSON_GetObjectItemCaseSensitive(shipping_rule_updateJSON, "maxWeightKg");
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

    // shipping_rule_update->min_weight_kg
    cJSON *min_weight_kg = cJSON_GetObjectItemCaseSensitive(shipping_rule_updateJSON, "minWeightKg");
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

    // shipping_rule_update->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(shipping_rule_updateJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // shipping_rule_update->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(shipping_rule_updateJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // shipping_rule_update->price
    cJSON *price = cJSON_GetObjectItemCaseSensitive(shipping_rule_updateJSON, "price");
    if (cJSON_IsNull(price)) {
        price = NULL;
    }
    if (price) { 
    if(!cJSON_IsString(price) && !cJSON_IsNull(price))
    {
    goto end; //String
    }
    }

    // shipping_rule_update->priority
    cJSON *priority = cJSON_GetObjectItemCaseSensitive(shipping_rule_updateJSON, "priority");
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

    shipping_rule_update_local_var = shipping_rule_update_create_internal (
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

    if (!shipping_rule_update_local_var) {
        goto end;
    }

    return shipping_rule_update_local_var;
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
