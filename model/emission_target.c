#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "emission_target.h"



static emission_target_t *emission_target_create_internal(
    char *base_value,
    int *base_year,
    char *description,
    emission_target_scope_t *scope,
    char *target_value,
    int *target_year,
    char *updated_at
    ) {
    emission_target_t *emission_target_local_var = malloc(sizeof(emission_target_t));
    if (!emission_target_local_var) {
        return NULL;
    }
    memset(emission_target_local_var, 0, sizeof(emission_target_t));
    emission_target_local_var->_library_owned = 1;
    emission_target_local_var->base_value = base_value;
    emission_target_local_var->base_year = base_year;
    emission_target_local_var->description = description;
    emission_target_local_var->scope = scope;
    emission_target_local_var->target_value = target_value;
    emission_target_local_var->target_year = target_year;
    emission_target_local_var->updated_at = updated_at;
    return emission_target_local_var;
}

__attribute__((deprecated)) emission_target_t *emission_target_create(
    char *base_value,
    int *base_year,
    char *description,
    emission_target_scope_t *scope,
    char *target_value,
    int *target_year,
    char *updated_at
    ) {
    int *base_year_copy = NULL;
    if (base_year) {
        base_year_copy = malloc(sizeof(int));
        if (base_year_copy) *base_year_copy = *base_year;
    }
    int *target_year_copy = NULL;
    if (target_year) {
        target_year_copy = malloc(sizeof(int));
        if (target_year_copy) *target_year_copy = *target_year;
    }
    emission_target_t *result = emission_target_create_internal (
        base_value,
        base_year_copy,
        description,
        scope,
        target_value,
        target_year_copy,
        updated_at
        );
    if (!result) {
        free(base_year_copy);
        free(target_year_copy);
    }
    return result;
}

void emission_target_free(emission_target_t *emission_target) {
    if(NULL == emission_target){
        return ;
    }
    if(emission_target->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "emission_target_free");
        return ;
    }
    listEntry_t *listEntry;
    if (emission_target->base_value) {
        free(emission_target->base_value);
        emission_target->base_value = NULL;
    }
    if (emission_target->base_year) {
        free(emission_target->base_year);
        emission_target->base_year = NULL;
    }
    if (emission_target->description) {
        free(emission_target->description);
        emission_target->description = NULL;
    }
    if (emission_target->scope) {
        emission_target_scope_free(emission_target->scope);
        emission_target->scope = NULL;
    }
    if (emission_target->target_value) {
        free(emission_target->target_value);
        emission_target->target_value = NULL;
    }
    if (emission_target->target_year) {
        free(emission_target->target_year);
        emission_target->target_year = NULL;
    }
    if (emission_target->updated_at) {
        free(emission_target->updated_at);
        emission_target->updated_at = NULL;
    }
    free(emission_target);
}

cJSON *emission_target_convertToJSON(emission_target_t *emission_target) {
    cJSON *item = cJSON_CreateObject();

    // emission_target->base_value
    if (!emission_target->base_value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "baseValue", emission_target->base_value) == NULL) {
    goto fail; //String
    }


    // emission_target->base_year
    if (!emission_target->base_year) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "baseYear", *emission_target->base_year) == NULL) {
    goto fail; //Numeric
    }


    // emission_target->description
    if (!emission_target->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", emission_target->description) == NULL) {
    goto fail; //String
    }


    // emission_target->scope
    if (!emission_target->scope) {
        goto fail;
    }
    cJSON *scope_local_JSON = emission_target_scope_convertToJSON(emission_target->scope);
    if(scope_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "scope", scope_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // emission_target->target_value
    if (!emission_target->target_value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "targetValue", emission_target->target_value) == NULL) {
    goto fail; //String
    }


    // emission_target->target_year
    if (!emission_target->target_year) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "targetYear", *emission_target->target_year) == NULL) {
    goto fail; //Numeric
    }


    // emission_target->updated_at
    if(emission_target->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", emission_target->updated_at) == NULL) {
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

emission_target_t *emission_target_parseFromJSON(cJSON *emission_targetJSON){

    emission_target_t *emission_target_local_var = NULL;

    char *base_value_local_str = NULL;

    // define the local variable for emission_target->base_year
    int *base_year_local_var = NULL;

    char *description_local_str = NULL;

    // define the local variable for emission_target->scope
    emission_target_scope_t *scope_local_nonprim = NULL;

    char *target_value_local_str = NULL;

    // define the local variable for emission_target->target_year
    int *target_year_local_var = NULL;

    char *updated_at_local_str = NULL;

    // emission_target->base_value
    cJSON *base_value = cJSON_GetObjectItemCaseSensitive(emission_targetJSON, "baseValue");
    if (cJSON_IsNull(base_value)) {
        base_value = NULL;
    }
    if (!base_value) {
        goto end;
    }

    
    if(!cJSON_IsString(base_value))
    {
    goto end; //String
    }

    // emission_target->base_year
    cJSON *base_year = cJSON_GetObjectItemCaseSensitive(emission_targetJSON, "baseYear");
    if (cJSON_IsNull(base_year)) {
        base_year = NULL;
    }
    if (!base_year) {
        goto end;
    }

    
    if(!cJSON_IsNumber(base_year))
    {
    goto end; //Numeric
    }
    base_year_local_var = malloc(sizeof(int));
    if(!base_year_local_var)
    {
        goto end;
    }
    *base_year_local_var = base_year->valuedouble;

    // emission_target->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(emission_targetJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (!description) {
        goto end;
    }

    
    if(!cJSON_IsString(description))
    {
    goto end; //String
    }

    // emission_target->scope
    cJSON *scope = cJSON_GetObjectItemCaseSensitive(emission_targetJSON, "scope");
    if (cJSON_IsNull(scope)) {
        scope = NULL;
    }
    if (!scope) {
        goto end;
    }

    
    scope_local_nonprim = emission_target_scope_parseFromJSON(scope); //custom

    // emission_target->target_value
    cJSON *target_value = cJSON_GetObjectItemCaseSensitive(emission_targetJSON, "targetValue");
    if (cJSON_IsNull(target_value)) {
        target_value = NULL;
    }
    if (!target_value) {
        goto end;
    }

    
    if(!cJSON_IsString(target_value))
    {
    goto end; //String
    }

    // emission_target->target_year
    cJSON *target_year = cJSON_GetObjectItemCaseSensitive(emission_targetJSON, "targetYear");
    if (cJSON_IsNull(target_year)) {
        target_year = NULL;
    }
    if (!target_year) {
        goto end;
    }

    
    if(!cJSON_IsNumber(target_year))
    {
    goto end; //Numeric
    }
    target_year_local_var = malloc(sizeof(int));
    if(!target_year_local_var)
    {
        goto end;
    }
    *target_year_local_var = target_year->valuedouble;

    // emission_target->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(emission_targetJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }


    if (base_value && !cJSON_IsNull(base_value)) base_value_local_str = strdup(base_value->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (target_value && !cJSON_IsNull(target_value)) target_value_local_str = strdup(target_value->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);

    emission_target_local_var = emission_target_create_internal (
        base_value_local_str,
        base_year_local_var,
        description_local_str,
        scope_local_nonprim,
        target_value_local_str,
        target_year_local_var,
        updated_at_local_str
        );

    if (!emission_target_local_var) {
        goto end;
    }

    return emission_target_local_var;
end:
    if (base_value_local_str) {
        free(base_value_local_str);
        base_value_local_str = NULL;
    }
    if (base_year_local_var) {
        free(base_year_local_var);
        base_year_local_var = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (scope_local_nonprim) {
        emission_target_scope_free(scope_local_nonprim);
        scope_local_nonprim = NULL;
    }
    if (target_value_local_str) {
        free(target_value_local_str);
        target_value_local_str = NULL;
    }
    if (target_year_local_var) {
        free(target_year_local_var);
        target_year_local_var = NULL;
    }
    if (updated_at_local_str) {
        free(updated_at_local_str);
        updated_at_local_str = NULL;
    }
    return NULL;

}
