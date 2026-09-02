#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shipping_rate.h"



static shipping_rate_t *shipping_rate_create_internal(
    char *breakdown,
    char *carrier,
    char *cross_border_surcharge,
    char *destination_country,
    int *estimated_days,
    int *from_api,
    char *insured_value,
    char *island_surcharge,
    char *origin_country,
    char *rate,
    char *service,
    char *volume_discount,
    double *weight_kg
    ) {
    shipping_rate_t *shipping_rate_local_var = malloc(sizeof(shipping_rate_t));
    if (!shipping_rate_local_var) {
        return NULL;
    }
    memset(shipping_rate_local_var, 0, sizeof(shipping_rate_t));
    shipping_rate_local_var->_library_owned = 1;
    shipping_rate_local_var->breakdown = breakdown;
    shipping_rate_local_var->carrier = carrier;
    shipping_rate_local_var->cross_border_surcharge = cross_border_surcharge;
    shipping_rate_local_var->destination_country = destination_country;
    shipping_rate_local_var->estimated_days = estimated_days;
    shipping_rate_local_var->from_api = from_api;
    shipping_rate_local_var->insured_value = insured_value;
    shipping_rate_local_var->island_surcharge = island_surcharge;
    shipping_rate_local_var->origin_country = origin_country;
    shipping_rate_local_var->rate = rate;
    shipping_rate_local_var->service = service;
    shipping_rate_local_var->volume_discount = volume_discount;
    shipping_rate_local_var->weight_kg = weight_kg;
    return shipping_rate_local_var;
}

__attribute__((deprecated)) shipping_rate_t *shipping_rate_create(
    char *breakdown,
    char *carrier,
    char *cross_border_surcharge,
    char *destination_country,
    int *estimated_days,
    int *from_api,
    char *insured_value,
    char *island_surcharge,
    char *origin_country,
    char *rate,
    char *service,
    char *volume_discount,
    double *weight_kg
    ) {
    int *estimated_days_copy = NULL;
    if (estimated_days) {
        estimated_days_copy = malloc(sizeof(int));
        if (estimated_days_copy) *estimated_days_copy = *estimated_days;
    }
    int *from_api_copy = NULL;
    if (from_api) {
        from_api_copy = malloc(sizeof(int));
        if (from_api_copy) *from_api_copy = *from_api;
    }
    double *weight_kg_copy = NULL;
    if (weight_kg) {
        weight_kg_copy = malloc(sizeof(double));
        if (weight_kg_copy) *weight_kg_copy = *weight_kg;
    }
    shipping_rate_t *result = shipping_rate_create_internal (
        breakdown,
        carrier,
        cross_border_surcharge,
        destination_country,
        estimated_days_copy,
        from_api_copy,
        insured_value,
        island_surcharge,
        origin_country,
        rate,
        service,
        volume_discount,
        weight_kg_copy
        );
    if (!result) {
        free(estimated_days_copy);
        free(from_api_copy);
        free(weight_kg_copy);
    }
    return result;
}

void shipping_rate_free(shipping_rate_t *shipping_rate) {
    if(NULL == shipping_rate){
        return ;
    }
    if(shipping_rate->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "shipping_rate_free");
        return ;
    }
    listEntry_t *listEntry;
    if (shipping_rate->breakdown) {
        free(shipping_rate->breakdown);
        shipping_rate->breakdown = NULL;
    }
    if (shipping_rate->carrier) {
        free(shipping_rate->carrier);
        shipping_rate->carrier = NULL;
    }
    if (shipping_rate->cross_border_surcharge) {
        free(shipping_rate->cross_border_surcharge);
        shipping_rate->cross_border_surcharge = NULL;
    }
    if (shipping_rate->destination_country) {
        free(shipping_rate->destination_country);
        shipping_rate->destination_country = NULL;
    }
    if (shipping_rate->estimated_days) {
        free(shipping_rate->estimated_days);
        shipping_rate->estimated_days = NULL;
    }
    if (shipping_rate->from_api) {
        free(shipping_rate->from_api);
        shipping_rate->from_api = NULL;
    }
    if (shipping_rate->insured_value) {
        free(shipping_rate->insured_value);
        shipping_rate->insured_value = NULL;
    }
    if (shipping_rate->island_surcharge) {
        free(shipping_rate->island_surcharge);
        shipping_rate->island_surcharge = NULL;
    }
    if (shipping_rate->origin_country) {
        free(shipping_rate->origin_country);
        shipping_rate->origin_country = NULL;
    }
    if (shipping_rate->rate) {
        free(shipping_rate->rate);
        shipping_rate->rate = NULL;
    }
    if (shipping_rate->service) {
        free(shipping_rate->service);
        shipping_rate->service = NULL;
    }
    if (shipping_rate->volume_discount) {
        free(shipping_rate->volume_discount);
        shipping_rate->volume_discount = NULL;
    }
    if (shipping_rate->weight_kg) {
        free(shipping_rate->weight_kg);
        shipping_rate->weight_kg = NULL;
    }
    free(shipping_rate);
}

cJSON *shipping_rate_convertToJSON(shipping_rate_t *shipping_rate) {
    cJSON *item = cJSON_CreateObject();

    // shipping_rate->breakdown
    if(shipping_rate->breakdown) {
    if(cJSON_AddStringToObject(item, "breakdown", shipping_rate->breakdown) == NULL) {
    goto fail; //String
    }
    }


    // shipping_rate->carrier
    if (!shipping_rate->carrier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "carrier", shipping_rate->carrier) == NULL) {
    goto fail; //String
    }


    // shipping_rate->cross_border_surcharge
    if(shipping_rate->cross_border_surcharge) {
    if(cJSON_AddStringToObject(item, "cross_border_surcharge", shipping_rate->cross_border_surcharge) == NULL) {
    goto fail; //String
    }
    }


    // shipping_rate->destination_country
    if (!shipping_rate->destination_country) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "destination_country", shipping_rate->destination_country) == NULL) {
    goto fail; //String
    }


    // shipping_rate->estimated_days
    if(shipping_rate->estimated_days) {
    if(cJSON_AddNumberToObject(item, "estimated_days", *shipping_rate->estimated_days) == NULL) {
    goto fail; //Numeric
    }
    }


    // shipping_rate->from_api
    if (!shipping_rate->from_api) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "from_api", *shipping_rate->from_api) == NULL) {
    goto fail; //Bool
    }


    // shipping_rate->insured_value
    if(shipping_rate->insured_value) {
    if(cJSON_AddStringToObject(item, "insured_value", shipping_rate->insured_value) == NULL) {
    goto fail; //String
    }
    }


    // shipping_rate->island_surcharge
    if(shipping_rate->island_surcharge) {
    if(cJSON_AddStringToObject(item, "island_surcharge", shipping_rate->island_surcharge) == NULL) {
    goto fail; //String
    }
    }


    // shipping_rate->origin_country
    if (!shipping_rate->origin_country) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "origin_country", shipping_rate->origin_country) == NULL) {
    goto fail; //String
    }


    // shipping_rate->rate
    if (!shipping_rate->rate) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "rate", shipping_rate->rate) == NULL) {
    goto fail; //String
    }


    // shipping_rate->service
    if (!shipping_rate->service) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "service", shipping_rate->service) == NULL) {
    goto fail; //String
    }


    // shipping_rate->volume_discount
    if(shipping_rate->volume_discount) {
    if(cJSON_AddStringToObject(item, "volume_discount", shipping_rate->volume_discount) == NULL) {
    goto fail; //String
    }
    }


    // shipping_rate->weight_kg
    if (!shipping_rate->weight_kg) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "weight_kg", *shipping_rate->weight_kg) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

shipping_rate_t *shipping_rate_parseFromJSON(cJSON *shipping_rateJSON){

    shipping_rate_t *shipping_rate_local_var = NULL;

    char *breakdown_local_str = NULL;

    char *carrier_local_str = NULL;

    char *cross_border_surcharge_local_str = NULL;

    char *destination_country_local_str = NULL;

    // define the local variable for shipping_rate->estimated_days
    int *estimated_days_local_var = NULL;

    // define the local variable for shipping_rate->from_api
    int *from_api_local_var = NULL;

    char *insured_value_local_str = NULL;

    char *island_surcharge_local_str = NULL;

    char *origin_country_local_str = NULL;

    char *rate_local_str = NULL;

    char *service_local_str = NULL;

    char *volume_discount_local_str = NULL;

    // define the local variable for shipping_rate->weight_kg
    double *weight_kg_local_var = NULL;

    // shipping_rate->breakdown
    cJSON *breakdown = cJSON_GetObjectItemCaseSensitive(shipping_rateJSON, "breakdown");
    if (cJSON_IsNull(breakdown)) {
        breakdown = NULL;
    }
    if (breakdown) { 
    if(!cJSON_IsString(breakdown) && !cJSON_IsNull(breakdown))
    {
    goto end; //String
    }
    }

    // shipping_rate->carrier
    cJSON *carrier = cJSON_GetObjectItemCaseSensitive(shipping_rateJSON, "carrier");
    if (cJSON_IsNull(carrier)) {
        carrier = NULL;
    }
    if (!carrier) {
        goto end;
    }

    
    if(!cJSON_IsString(carrier))
    {
    goto end; //String
    }

    // shipping_rate->cross_border_surcharge
    cJSON *cross_border_surcharge = cJSON_GetObjectItemCaseSensitive(shipping_rateJSON, "cross_border_surcharge");
    if (cJSON_IsNull(cross_border_surcharge)) {
        cross_border_surcharge = NULL;
    }
    if (cross_border_surcharge) { 
    if(!cJSON_IsString(cross_border_surcharge) && !cJSON_IsNull(cross_border_surcharge))
    {
    goto end; //String
    }
    }

    // shipping_rate->destination_country
    cJSON *destination_country = cJSON_GetObjectItemCaseSensitive(shipping_rateJSON, "destination_country");
    if (cJSON_IsNull(destination_country)) {
        destination_country = NULL;
    }
    if (!destination_country) {
        goto end;
    }

    
    if(!cJSON_IsString(destination_country))
    {
    goto end; //String
    }

    // shipping_rate->estimated_days
    cJSON *estimated_days = cJSON_GetObjectItemCaseSensitive(shipping_rateJSON, "estimated_days");
    if (cJSON_IsNull(estimated_days)) {
        estimated_days = NULL;
    }
    if (estimated_days) { 
    if(!cJSON_IsNumber(estimated_days))
    {
    goto end; //Numeric
    }
    estimated_days_local_var = malloc(sizeof(int));
    if(!estimated_days_local_var)
    {
        goto end;
    }
    *estimated_days_local_var = estimated_days->valuedouble;
    }

    // shipping_rate->from_api
    cJSON *from_api = cJSON_GetObjectItemCaseSensitive(shipping_rateJSON, "from_api");
    if (cJSON_IsNull(from_api)) {
        from_api = NULL;
    }
    if (!from_api) {
        goto end;
    }

    
    if(!cJSON_IsBool(from_api))
    {
    goto end; //Bool
    }
    from_api_local_var = malloc(sizeof(int));
    if(!from_api_local_var)
    {
        goto end;
    }
    *from_api_local_var = from_api->valueint;

    // shipping_rate->insured_value
    cJSON *insured_value = cJSON_GetObjectItemCaseSensitive(shipping_rateJSON, "insured_value");
    if (cJSON_IsNull(insured_value)) {
        insured_value = NULL;
    }
    if (insured_value) { 
    if(!cJSON_IsString(insured_value) && !cJSON_IsNull(insured_value))
    {
    goto end; //String
    }
    }

    // shipping_rate->island_surcharge
    cJSON *island_surcharge = cJSON_GetObjectItemCaseSensitive(shipping_rateJSON, "island_surcharge");
    if (cJSON_IsNull(island_surcharge)) {
        island_surcharge = NULL;
    }
    if (island_surcharge) { 
    if(!cJSON_IsString(island_surcharge) && !cJSON_IsNull(island_surcharge))
    {
    goto end; //String
    }
    }

    // shipping_rate->origin_country
    cJSON *origin_country = cJSON_GetObjectItemCaseSensitive(shipping_rateJSON, "origin_country");
    if (cJSON_IsNull(origin_country)) {
        origin_country = NULL;
    }
    if (!origin_country) {
        goto end;
    }

    
    if(!cJSON_IsString(origin_country))
    {
    goto end; //String
    }

    // shipping_rate->rate
    cJSON *rate = cJSON_GetObjectItemCaseSensitive(shipping_rateJSON, "rate");
    if (cJSON_IsNull(rate)) {
        rate = NULL;
    }
    if (!rate) {
        goto end;
    }

    
    if(!cJSON_IsString(rate))
    {
    goto end; //String
    }

    // shipping_rate->service
    cJSON *service = cJSON_GetObjectItemCaseSensitive(shipping_rateJSON, "service");
    if (cJSON_IsNull(service)) {
        service = NULL;
    }
    if (!service) {
        goto end;
    }

    
    if(!cJSON_IsString(service))
    {
    goto end; //String
    }

    // shipping_rate->volume_discount
    cJSON *volume_discount = cJSON_GetObjectItemCaseSensitive(shipping_rateJSON, "volume_discount");
    if (cJSON_IsNull(volume_discount)) {
        volume_discount = NULL;
    }
    if (volume_discount) { 
    if(!cJSON_IsString(volume_discount) && !cJSON_IsNull(volume_discount))
    {
    goto end; //String
    }
    }

    // shipping_rate->weight_kg
    cJSON *weight_kg = cJSON_GetObjectItemCaseSensitive(shipping_rateJSON, "weight_kg");
    if (cJSON_IsNull(weight_kg)) {
        weight_kg = NULL;
    }
    if (!weight_kg) {
        goto end;
    }

    
    if(!cJSON_IsNumber(weight_kg))
    {
    goto end; //Numeric
    }
    weight_kg_local_var = malloc(sizeof(double));
    if(!weight_kg_local_var)
    {
        goto end;
    }
    *weight_kg_local_var = weight_kg->valuedouble;


    if (breakdown && !cJSON_IsNull(breakdown)) breakdown_local_str = strdup(breakdown->valuestring);
    if (carrier && !cJSON_IsNull(carrier)) carrier_local_str = strdup(carrier->valuestring);
    if (cross_border_surcharge && !cJSON_IsNull(cross_border_surcharge)) cross_border_surcharge_local_str = strdup(cross_border_surcharge->valuestring);
    if (destination_country && !cJSON_IsNull(destination_country)) destination_country_local_str = strdup(destination_country->valuestring);
    if (insured_value && !cJSON_IsNull(insured_value)) insured_value_local_str = strdup(insured_value->valuestring);
    if (island_surcharge && !cJSON_IsNull(island_surcharge)) island_surcharge_local_str = strdup(island_surcharge->valuestring);
    if (origin_country && !cJSON_IsNull(origin_country)) origin_country_local_str = strdup(origin_country->valuestring);
    if (rate && !cJSON_IsNull(rate)) rate_local_str = strdup(rate->valuestring);
    if (service && !cJSON_IsNull(service)) service_local_str = strdup(service->valuestring);
    if (volume_discount && !cJSON_IsNull(volume_discount)) volume_discount_local_str = strdup(volume_discount->valuestring);

    shipping_rate_local_var = shipping_rate_create_internal (
        breakdown_local_str,
        carrier_local_str,
        cross_border_surcharge_local_str,
        destination_country_local_str,
        estimated_days_local_var,
        from_api_local_var,
        insured_value_local_str,
        island_surcharge_local_str,
        origin_country_local_str,
        rate_local_str,
        service_local_str,
        volume_discount_local_str,
        weight_kg_local_var
        );

    if (!shipping_rate_local_var) {
        goto end;
    }

    return shipping_rate_local_var;
end:
    if (breakdown_local_str) {
        free(breakdown_local_str);
        breakdown_local_str = NULL;
    }
    if (carrier_local_str) {
        free(carrier_local_str);
        carrier_local_str = NULL;
    }
    if (cross_border_surcharge_local_str) {
        free(cross_border_surcharge_local_str);
        cross_border_surcharge_local_str = NULL;
    }
    if (destination_country_local_str) {
        free(destination_country_local_str);
        destination_country_local_str = NULL;
    }
    if (estimated_days_local_var) {
        free(estimated_days_local_var);
        estimated_days_local_var = NULL;
    }
    if (from_api_local_var) {
        free(from_api_local_var);
        from_api_local_var = NULL;
    }
    if (insured_value_local_str) {
        free(insured_value_local_str);
        insured_value_local_str = NULL;
    }
    if (island_surcharge_local_str) {
        free(island_surcharge_local_str);
        island_surcharge_local_str = NULL;
    }
    if (origin_country_local_str) {
        free(origin_country_local_str);
        origin_country_local_str = NULL;
    }
    if (rate_local_str) {
        free(rate_local_str);
        rate_local_str = NULL;
    }
    if (service_local_str) {
        free(service_local_str);
        service_local_str = NULL;
    }
    if (volume_discount_local_str) {
        free(volume_discount_local_str);
        volume_discount_local_str = NULL;
    }
    if (weight_kg_local_var) {
        free(weight_kg_local_var);
        weight_kg_local_var = NULL;
    }
    return NULL;

}
