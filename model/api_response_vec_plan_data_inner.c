#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "api_response_vec_plan_data_inner.h"



static api_response_vec_plan_data_inner_t *api_response_vec_plan_data_inner_create_internal(
    plan_features_t *features,
    char *id,
    plan_limits_t *limits,
    char *name,
    double *price_eur
    ) {
    api_response_vec_plan_data_inner_t *api_response_vec_plan_data_inner_local_var = malloc(sizeof(api_response_vec_plan_data_inner_t));
    if (!api_response_vec_plan_data_inner_local_var) {
        return NULL;
    }
    memset(api_response_vec_plan_data_inner_local_var, 0, sizeof(api_response_vec_plan_data_inner_t));
    api_response_vec_plan_data_inner_local_var->_library_owned = 1;
    api_response_vec_plan_data_inner_local_var->features = features;
    api_response_vec_plan_data_inner_local_var->id = id;
    api_response_vec_plan_data_inner_local_var->limits = limits;
    api_response_vec_plan_data_inner_local_var->name = name;
    api_response_vec_plan_data_inner_local_var->price_eur = price_eur;
    return api_response_vec_plan_data_inner_local_var;
}

__attribute__((deprecated)) api_response_vec_plan_data_inner_t *api_response_vec_plan_data_inner_create(
    plan_features_t *features,
    char *id,
    plan_limits_t *limits,
    char *name,
    double *price_eur
    ) {
    double *price_eur_copy = NULL;
    if (price_eur) {
        price_eur_copy = malloc(sizeof(double));
        if (price_eur_copy) *price_eur_copy = *price_eur;
    }
    api_response_vec_plan_data_inner_t *result = api_response_vec_plan_data_inner_create_internal (
        features,
        id,
        limits,
        name,
        price_eur_copy
        );
    if (!result) {
        free(price_eur_copy);
    }
    return result;
}

void api_response_vec_plan_data_inner_free(api_response_vec_plan_data_inner_t *api_response_vec_plan_data_inner) {
    if(NULL == api_response_vec_plan_data_inner){
        return ;
    }
    if(api_response_vec_plan_data_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "api_response_vec_plan_data_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (api_response_vec_plan_data_inner->features) {
        plan_features_free(api_response_vec_plan_data_inner->features);
        api_response_vec_plan_data_inner->features = NULL;
    }
    if (api_response_vec_plan_data_inner->id) {
        free(api_response_vec_plan_data_inner->id);
        api_response_vec_plan_data_inner->id = NULL;
    }
    if (api_response_vec_plan_data_inner->limits) {
        plan_limits_free(api_response_vec_plan_data_inner->limits);
        api_response_vec_plan_data_inner->limits = NULL;
    }
    if (api_response_vec_plan_data_inner->name) {
        free(api_response_vec_plan_data_inner->name);
        api_response_vec_plan_data_inner->name = NULL;
    }
    if (api_response_vec_plan_data_inner->price_eur) {
        free(api_response_vec_plan_data_inner->price_eur);
        api_response_vec_plan_data_inner->price_eur = NULL;
    }
    free(api_response_vec_plan_data_inner);
}

cJSON *api_response_vec_plan_data_inner_convertToJSON(api_response_vec_plan_data_inner_t *api_response_vec_plan_data_inner) {
    cJSON *item = cJSON_CreateObject();

    // api_response_vec_plan_data_inner->features
    if (!api_response_vec_plan_data_inner->features) {
        goto fail;
    }
    cJSON *features_local_JSON = plan_features_convertToJSON(api_response_vec_plan_data_inner->features);
    if(features_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "features", features_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // api_response_vec_plan_data_inner->id
    if (!api_response_vec_plan_data_inner->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", api_response_vec_plan_data_inner->id) == NULL) {
    goto fail; //String
    }


    // api_response_vec_plan_data_inner->limits
    if (!api_response_vec_plan_data_inner->limits) {
        goto fail;
    }
    cJSON *limits_local_JSON = plan_limits_convertToJSON(api_response_vec_plan_data_inner->limits);
    if(limits_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "limits", limits_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // api_response_vec_plan_data_inner->name
    if (!api_response_vec_plan_data_inner->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", api_response_vec_plan_data_inner->name) == NULL) {
    goto fail; //String
    }


    // api_response_vec_plan_data_inner->price_eur
    if (!api_response_vec_plan_data_inner->price_eur) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "priceEur", *api_response_vec_plan_data_inner->price_eur) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

api_response_vec_plan_data_inner_t *api_response_vec_plan_data_inner_parseFromJSON(cJSON *api_response_vec_plan_data_innerJSON){

    api_response_vec_plan_data_inner_t *api_response_vec_plan_data_inner_local_var = NULL;

    // define the local variable for api_response_vec_plan_data_inner->features
    plan_features_t *features_local_nonprim = NULL;

    char *id_local_str = NULL;

    // define the local variable for api_response_vec_plan_data_inner->limits
    plan_limits_t *limits_local_nonprim = NULL;

    char *name_local_str = NULL;

    // define the local variable for api_response_vec_plan_data_inner->price_eur
    double *price_eur_local_var = NULL;

    // api_response_vec_plan_data_inner->features
    cJSON *features = cJSON_GetObjectItemCaseSensitive(api_response_vec_plan_data_innerJSON, "features");
    if (cJSON_IsNull(features)) {
        features = NULL;
    }
    if (!features) {
        goto end;
    }

    
    features_local_nonprim = plan_features_parseFromJSON(features); //nonprimitive

    // api_response_vec_plan_data_inner->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(api_response_vec_plan_data_innerJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // api_response_vec_plan_data_inner->limits
    cJSON *limits = cJSON_GetObjectItemCaseSensitive(api_response_vec_plan_data_innerJSON, "limits");
    if (cJSON_IsNull(limits)) {
        limits = NULL;
    }
    if (!limits) {
        goto end;
    }

    
    limits_local_nonprim = plan_limits_parseFromJSON(limits); //nonprimitive

    // api_response_vec_plan_data_inner->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(api_response_vec_plan_data_innerJSON, "name");
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

    // api_response_vec_plan_data_inner->price_eur
    cJSON *price_eur = cJSON_GetObjectItemCaseSensitive(api_response_vec_plan_data_innerJSON, "priceEur");
    if (cJSON_IsNull(price_eur)) {
        price_eur = NULL;
    }
    if (!price_eur) {
        goto end;
    }

    
    if(!cJSON_IsNumber(price_eur))
    {
    goto end; //Numeric
    }
    price_eur_local_var = malloc(sizeof(double));
    if(!price_eur_local_var)
    {
        goto end;
    }
    *price_eur_local_var = price_eur->valuedouble;


    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    api_response_vec_plan_data_inner_local_var = api_response_vec_plan_data_inner_create_internal (
        features_local_nonprim,
        id_local_str,
        limits_local_nonprim,
        name_local_str,
        price_eur_local_var
        );

    if (!api_response_vec_plan_data_inner_local_var) {
        goto end;
    }

    return api_response_vec_plan_data_inner_local_var;
end:
    if (features_local_nonprim) {
        plan_features_free(features_local_nonprim);
        features_local_nonprim = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (limits_local_nonprim) {
        plan_limits_free(limits_local_nonprim);
        limits_local_nonprim = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (price_eur_local_var) {
        free(price_eur_local_var);
        price_eur_local_var = NULL;
    }
    return NULL;

}
