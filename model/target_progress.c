#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "target_progress.h"



static target_progress_t *target_progress_create_internal(
    double *base_value,
    int *base_year,
    char *description,
    char *id,
    double *progress_pct,
    char *scope,
    double *target_value,
    int *target_year
    ) {
    target_progress_t *target_progress_local_var = malloc(sizeof(target_progress_t));
    if (!target_progress_local_var) {
        return NULL;
    }
    memset(target_progress_local_var, 0, sizeof(target_progress_t));
    target_progress_local_var->_library_owned = 1;
    target_progress_local_var->base_value = base_value;
    target_progress_local_var->base_year = base_year;
    target_progress_local_var->description = description;
    target_progress_local_var->id = id;
    target_progress_local_var->progress_pct = progress_pct;
    target_progress_local_var->scope = scope;
    target_progress_local_var->target_value = target_value;
    target_progress_local_var->target_year = target_year;
    return target_progress_local_var;
}

__attribute__((deprecated)) target_progress_t *target_progress_create(
    double *base_value,
    int *base_year,
    char *description,
    char *id,
    double *progress_pct,
    char *scope,
    double *target_value,
    int *target_year
    ) {
    double *base_value_copy = NULL;
    if (base_value) {
        base_value_copy = malloc(sizeof(double));
        if (base_value_copy) *base_value_copy = *base_value;
    }
    int *base_year_copy = NULL;
    if (base_year) {
        base_year_copy = malloc(sizeof(int));
        if (base_year_copy) *base_year_copy = *base_year;
    }
    double *progress_pct_copy = NULL;
    if (progress_pct) {
        progress_pct_copy = malloc(sizeof(double));
        if (progress_pct_copy) *progress_pct_copy = *progress_pct;
    }
    double *target_value_copy = NULL;
    if (target_value) {
        target_value_copy = malloc(sizeof(double));
        if (target_value_copy) *target_value_copy = *target_value;
    }
    int *target_year_copy = NULL;
    if (target_year) {
        target_year_copy = malloc(sizeof(int));
        if (target_year_copy) *target_year_copy = *target_year;
    }
    target_progress_t *result = target_progress_create_internal (
        base_value_copy,
        base_year_copy,
        description,
        id,
        progress_pct_copy,
        scope,
        target_value_copy,
        target_year_copy
        );
    if (!result) {
        free(base_value_copy);
        free(base_year_copy);
        free(progress_pct_copy);
        free(target_value_copy);
        free(target_year_copy);
    }
    return result;
}

void target_progress_free(target_progress_t *target_progress) {
    if(NULL == target_progress){
        return ;
    }
    if(target_progress->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "target_progress_free");
        return ;
    }
    listEntry_t *listEntry;
    if (target_progress->base_value) {
        free(target_progress->base_value);
        target_progress->base_value = NULL;
    }
    if (target_progress->base_year) {
        free(target_progress->base_year);
        target_progress->base_year = NULL;
    }
    if (target_progress->description) {
        free(target_progress->description);
        target_progress->description = NULL;
    }
    if (target_progress->id) {
        free(target_progress->id);
        target_progress->id = NULL;
    }
    if (target_progress->progress_pct) {
        free(target_progress->progress_pct);
        target_progress->progress_pct = NULL;
    }
    if (target_progress->scope) {
        free(target_progress->scope);
        target_progress->scope = NULL;
    }
    if (target_progress->target_value) {
        free(target_progress->target_value);
        target_progress->target_value = NULL;
    }
    if (target_progress->target_year) {
        free(target_progress->target_year);
        target_progress->target_year = NULL;
    }
    free(target_progress);
}

cJSON *target_progress_convertToJSON(target_progress_t *target_progress) {
    cJSON *item = cJSON_CreateObject();

    // target_progress->base_value
    if (!target_progress->base_value) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "base_value", *target_progress->base_value) == NULL) {
    goto fail; //Numeric
    }


    // target_progress->base_year
    if (!target_progress->base_year) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "base_year", *target_progress->base_year) == NULL) {
    goto fail; //Numeric
    }


    // target_progress->description
    if (!target_progress->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", target_progress->description) == NULL) {
    goto fail; //String
    }


    // target_progress->id
    if (!target_progress->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", target_progress->id) == NULL) {
    goto fail; //String
    }


    // target_progress->progress_pct
    if(target_progress->progress_pct) {
    if(cJSON_AddNumberToObject(item, "progress_pct", *target_progress->progress_pct) == NULL) {
    goto fail; //Numeric
    }
    }


    // target_progress->scope
    if (!target_progress->scope) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "scope", target_progress->scope) == NULL) {
    goto fail; //String
    }


    // target_progress->target_value
    if (!target_progress->target_value) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "target_value", *target_progress->target_value) == NULL) {
    goto fail; //Numeric
    }


    // target_progress->target_year
    if (!target_progress->target_year) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "target_year", *target_progress->target_year) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

target_progress_t *target_progress_parseFromJSON(cJSON *target_progressJSON){

    target_progress_t *target_progress_local_var = NULL;

    // define the local variable for target_progress->base_value
    double *base_value_local_var = NULL;

    // define the local variable for target_progress->base_year
    int *base_year_local_var = NULL;

    char *description_local_str = NULL;

    char *id_local_str = NULL;

    // define the local variable for target_progress->progress_pct
    double *progress_pct_local_var = NULL;

    char *scope_local_str = NULL;

    // define the local variable for target_progress->target_value
    double *target_value_local_var = NULL;

    // define the local variable for target_progress->target_year
    int *target_year_local_var = NULL;

    // target_progress->base_value
    cJSON *base_value = cJSON_GetObjectItemCaseSensitive(target_progressJSON, "base_value");
    if (cJSON_IsNull(base_value)) {
        base_value = NULL;
    }
    if (!base_value) {
        goto end;
    }

    
    if(!cJSON_IsNumber(base_value))
    {
    goto end; //Numeric
    }
    base_value_local_var = malloc(sizeof(double));
    if(!base_value_local_var)
    {
        goto end;
    }
    *base_value_local_var = base_value->valuedouble;

    // target_progress->base_year
    cJSON *base_year = cJSON_GetObjectItemCaseSensitive(target_progressJSON, "base_year");
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

    // target_progress->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(target_progressJSON, "description");
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

    // target_progress->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(target_progressJSON, "id");
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

    // target_progress->progress_pct
    cJSON *progress_pct = cJSON_GetObjectItemCaseSensitive(target_progressJSON, "progress_pct");
    if (cJSON_IsNull(progress_pct)) {
        progress_pct = NULL;
    }
    if (progress_pct) { 
    if(!cJSON_IsNumber(progress_pct))
    {
    goto end; //Numeric
    }
    progress_pct_local_var = malloc(sizeof(double));
    if(!progress_pct_local_var)
    {
        goto end;
    }
    *progress_pct_local_var = progress_pct->valuedouble;
    }

    // target_progress->scope
    cJSON *scope = cJSON_GetObjectItemCaseSensitive(target_progressJSON, "scope");
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

    // target_progress->target_value
    cJSON *target_value = cJSON_GetObjectItemCaseSensitive(target_progressJSON, "target_value");
    if (cJSON_IsNull(target_value)) {
        target_value = NULL;
    }
    if (!target_value) {
        goto end;
    }

    
    if(!cJSON_IsNumber(target_value))
    {
    goto end; //Numeric
    }
    target_value_local_var = malloc(sizeof(double));
    if(!target_value_local_var)
    {
        goto end;
    }
    *target_value_local_var = target_value->valuedouble;

    // target_progress->target_year
    cJSON *target_year = cJSON_GetObjectItemCaseSensitive(target_progressJSON, "target_year");
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


    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (scope && !cJSON_IsNull(scope)) scope_local_str = strdup(scope->valuestring);

    target_progress_local_var = target_progress_create_internal (
        base_value_local_var,
        base_year_local_var,
        description_local_str,
        id_local_str,
        progress_pct_local_var,
        scope_local_str,
        target_value_local_var,
        target_year_local_var
        );

    if (!target_progress_local_var) {
        goto end;
    }

    return target_progress_local_var;
end:
    if (base_value_local_var) {
        free(base_value_local_var);
        base_value_local_var = NULL;
    }
    if (base_year_local_var) {
        free(base_year_local_var);
        base_year_local_var = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (progress_pct_local_var) {
        free(progress_pct_local_var);
        progress_pct_local_var = NULL;
    }
    if (scope_local_str) {
        free(scope_local_str);
        scope_local_str = NULL;
    }
    if (target_value_local_var) {
        free(target_value_local_var);
        target_value_local_var = NULL;
    }
    if (target_year_local_var) {
        free(target_year_local_var);
        target_year_local_var = NULL;
    }
    return NULL;

}
