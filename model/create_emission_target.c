#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_emission_target.h"



static create_emission_target_t *create_emission_target_create_internal(
    char *base_value,
    int *base_year,
    char *description,
    char *scope,
    char *target_value,
    int *target_year
    ) {
    create_emission_target_t *create_emission_target_local_var = malloc(sizeof(create_emission_target_t));
    if (!create_emission_target_local_var) {
        return NULL;
    }
    memset(create_emission_target_local_var, 0, sizeof(create_emission_target_t));
    create_emission_target_local_var->_library_owned = 1;
    create_emission_target_local_var->base_value = base_value;
    create_emission_target_local_var->base_year = base_year;
    create_emission_target_local_var->description = description;
    create_emission_target_local_var->scope = scope;
    create_emission_target_local_var->target_value = target_value;
    create_emission_target_local_var->target_year = target_year;
    return create_emission_target_local_var;
}

__attribute__((deprecated)) create_emission_target_t *create_emission_target_create(
    char *base_value,
    int *base_year,
    char *description,
    char *scope,
    char *target_value,
    int *target_year
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
    create_emission_target_t *result = create_emission_target_create_internal (
        base_value,
        base_year_copy,
        description,
        scope,
        target_value,
        target_year_copy
        );
    if (!result) {
        free(base_year_copy);
        free(target_year_copy);
    }
    return result;
}

void create_emission_target_free(create_emission_target_t *create_emission_target) {
    if(NULL == create_emission_target){
        return ;
    }
    if(create_emission_target->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_emission_target_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_emission_target->base_value) {
        free(create_emission_target->base_value);
        create_emission_target->base_value = NULL;
    }
    if (create_emission_target->base_year) {
        free(create_emission_target->base_year);
        create_emission_target->base_year = NULL;
    }
    if (create_emission_target->description) {
        free(create_emission_target->description);
        create_emission_target->description = NULL;
    }
    if (create_emission_target->scope) {
        free(create_emission_target->scope);
        create_emission_target->scope = NULL;
    }
    if (create_emission_target->target_value) {
        free(create_emission_target->target_value);
        create_emission_target->target_value = NULL;
    }
    if (create_emission_target->target_year) {
        free(create_emission_target->target_year);
        create_emission_target->target_year = NULL;
    }
    free(create_emission_target);
}

cJSON *create_emission_target_convertToJSON(create_emission_target_t *create_emission_target) {
    cJSON *item = cJSON_CreateObject();

    // create_emission_target->base_value
    if (!create_emission_target->base_value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "base_value", create_emission_target->base_value) == NULL) {
    goto fail; //String
    }


    // create_emission_target->base_year
    if (!create_emission_target->base_year) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "base_year", *create_emission_target->base_year) == NULL) {
    goto fail; //Numeric
    }


    // create_emission_target->description
    if (!create_emission_target->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", create_emission_target->description) == NULL) {
    goto fail; //String
    }


    // create_emission_target->scope
    if (!create_emission_target->scope) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "scope", create_emission_target->scope) == NULL) {
    goto fail; //String
    }


    // create_emission_target->target_value
    if (!create_emission_target->target_value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "target_value", create_emission_target->target_value) == NULL) {
    goto fail; //String
    }


    // create_emission_target->target_year
    if (!create_emission_target->target_year) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "target_year", *create_emission_target->target_year) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_emission_target_t *create_emission_target_parseFromJSON(cJSON *create_emission_targetJSON){

    create_emission_target_t *create_emission_target_local_var = NULL;

    char *base_value_local_str = NULL;

    // define the local variable for create_emission_target->base_year
    int *base_year_local_var = NULL;

    char *description_local_str = NULL;

    char *scope_local_str = NULL;

    char *target_value_local_str = NULL;

    // define the local variable for create_emission_target->target_year
    int *target_year_local_var = NULL;

    // create_emission_target->base_value
    cJSON *base_value = cJSON_GetObjectItemCaseSensitive(create_emission_targetJSON, "base_value");
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

    // create_emission_target->base_year
    cJSON *base_year = cJSON_GetObjectItemCaseSensitive(create_emission_targetJSON, "base_year");
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

    // create_emission_target->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(create_emission_targetJSON, "description");
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

    // create_emission_target->scope
    cJSON *scope = cJSON_GetObjectItemCaseSensitive(create_emission_targetJSON, "scope");
    if (cJSON_IsNull(scope)) {
        scope = NULL;
    }
    if (!scope) {
        goto end;
    }

    
    if(!cJSON_IsString(scope))
    {
    goto end; //String
    }

    // create_emission_target->target_value
    cJSON *target_value = cJSON_GetObjectItemCaseSensitive(create_emission_targetJSON, "target_value");
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

    // create_emission_target->target_year
    cJSON *target_year = cJSON_GetObjectItemCaseSensitive(create_emission_targetJSON, "target_year");
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


    if (base_value && !cJSON_IsNull(base_value)) base_value_local_str = strdup(base_value->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (scope && !cJSON_IsNull(scope)) scope_local_str = strdup(scope->valuestring);
    if (target_value && !cJSON_IsNull(target_value)) target_value_local_str = strdup(target_value->valuestring);

    create_emission_target_local_var = create_emission_target_create_internal (
        base_value_local_str,
        base_year_local_var,
        description_local_str,
        scope_local_str,
        target_value_local_str,
        target_year_local_var
        );

    if (!create_emission_target_local_var) {
        goto end;
    }

    return create_emission_target_local_var;
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
    if (scope_local_str) {
        free(scope_local_str);
        scope_local_str = NULL;
    }
    if (target_value_local_str) {
        free(target_value_local_str);
        target_value_local_str = NULL;
    }
    if (target_year_local_var) {
        free(target_year_local_var);
        target_year_local_var = NULL;
    }
    return NULL;

}
