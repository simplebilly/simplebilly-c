#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plan.h"



static plan_t *plan_create_internal(
    plan_features_t *features,
    char *id,
    plan_limits_t *limits,
    char *name,
    double *price_eur
    ) {
    plan_t *plan_local_var = malloc(sizeof(plan_t));
    if (!plan_local_var) {
        return NULL;
    }
    memset(plan_local_var, 0, sizeof(plan_t));
    plan_local_var->_library_owned = 1;
    plan_local_var->features = features;
    plan_local_var->id = id;
    plan_local_var->limits = limits;
    plan_local_var->name = name;
    plan_local_var->price_eur = price_eur;
    return plan_local_var;
}

__attribute__((deprecated)) plan_t *plan_create(
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
    plan_t *result = plan_create_internal (
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

void plan_free(plan_t *plan) {
    if(NULL == plan){
        return ;
    }
    if(plan->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "plan_free");
        return ;
    }
    listEntry_t *listEntry;
    if (plan->features) {
        plan_features_free(plan->features);
        plan->features = NULL;
    }
    if (plan->id) {
        free(plan->id);
        plan->id = NULL;
    }
    if (plan->limits) {
        plan_limits_free(plan->limits);
        plan->limits = NULL;
    }
    if (plan->name) {
        free(plan->name);
        plan->name = NULL;
    }
    if (plan->price_eur) {
        free(plan->price_eur);
        plan->price_eur = NULL;
    }
    free(plan);
}

cJSON *plan_convertToJSON(plan_t *plan) {
    cJSON *item = cJSON_CreateObject();

    // plan->features
    if (!plan->features) {
        goto fail;
    }
    cJSON *features_local_JSON = plan_features_convertToJSON(plan->features);
    if(features_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "features", features_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // plan->id
    if (!plan->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", plan->id) == NULL) {
    goto fail; //String
    }


    // plan->limits
    if (!plan->limits) {
        goto fail;
    }
    cJSON *limits_local_JSON = plan_limits_convertToJSON(plan->limits);
    if(limits_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "limits", limits_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // plan->name
    if (!plan->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", plan->name) == NULL) {
    goto fail; //String
    }


    // plan->price_eur
    if (!plan->price_eur) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "priceEur", *plan->price_eur) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

plan_t *plan_parseFromJSON(cJSON *planJSON){

    plan_t *plan_local_var = NULL;

    // define the local variable for plan->features
    plan_features_t *features_local_nonprim = NULL;

    char *id_local_str = NULL;

    // define the local variable for plan->limits
    plan_limits_t *limits_local_nonprim = NULL;

    char *name_local_str = NULL;

    // define the local variable for plan->price_eur
    double *price_eur_local_var = NULL;

    // plan->features
    cJSON *features = cJSON_GetObjectItemCaseSensitive(planJSON, "features");
    if (cJSON_IsNull(features)) {
        features = NULL;
    }
    if (!features) {
        goto end;
    }

    
    features_local_nonprim = plan_features_parseFromJSON(features); //nonprimitive

    // plan->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(planJSON, "id");
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

    // plan->limits
    cJSON *limits = cJSON_GetObjectItemCaseSensitive(planJSON, "limits");
    if (cJSON_IsNull(limits)) {
        limits = NULL;
    }
    if (!limits) {
        goto end;
    }

    
    limits_local_nonprim = plan_limits_parseFromJSON(limits); //nonprimitive

    // plan->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(planJSON, "name");
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

    // plan->price_eur
    cJSON *price_eur = cJSON_GetObjectItemCaseSensitive(planJSON, "priceEur");
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

    plan_local_var = plan_create_internal (
        features_local_nonprim,
        id_local_str,
        limits_local_nonprim,
        name_local_str,
        price_eur_local_var
        );

    if (!plan_local_var) {
        goto end;
    }

    return plan_local_var;
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
