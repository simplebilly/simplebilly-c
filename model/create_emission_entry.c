#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_emission_entry.h"



static create_emission_entry_t *create_emission_entry_create_internal(
    char *activity_value,
    char *category_id,
    char *description,
    char *method,
    char *scope,
    char *unit,
    int *year
    ) {
    create_emission_entry_t *create_emission_entry_local_var = malloc(sizeof(create_emission_entry_t));
    if (!create_emission_entry_local_var) {
        return NULL;
    }
    memset(create_emission_entry_local_var, 0, sizeof(create_emission_entry_t));
    create_emission_entry_local_var->_library_owned = 1;
    create_emission_entry_local_var->activity_value = activity_value;
    create_emission_entry_local_var->category_id = category_id;
    create_emission_entry_local_var->description = description;
    create_emission_entry_local_var->method = method;
    create_emission_entry_local_var->scope = scope;
    create_emission_entry_local_var->unit = unit;
    create_emission_entry_local_var->year = year;
    return create_emission_entry_local_var;
}

__attribute__((deprecated)) create_emission_entry_t *create_emission_entry_create(
    char *activity_value,
    char *category_id,
    char *description,
    char *method,
    char *scope,
    char *unit,
    int *year
    ) {
    int *year_copy = NULL;
    if (year) {
        year_copy = malloc(sizeof(int));
        if (year_copy) *year_copy = *year;
    }
    create_emission_entry_t *result = create_emission_entry_create_internal (
        activity_value,
        category_id,
        description,
        method,
        scope,
        unit,
        year_copy
        );
    if (!result) {
        free(year_copy);
    }
    return result;
}

void create_emission_entry_free(create_emission_entry_t *create_emission_entry) {
    if(NULL == create_emission_entry){
        return ;
    }
    if(create_emission_entry->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_emission_entry_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_emission_entry->activity_value) {
        free(create_emission_entry->activity_value);
        create_emission_entry->activity_value = NULL;
    }
    if (create_emission_entry->category_id) {
        free(create_emission_entry->category_id);
        create_emission_entry->category_id = NULL;
    }
    if (create_emission_entry->description) {
        free(create_emission_entry->description);
        create_emission_entry->description = NULL;
    }
    if (create_emission_entry->method) {
        free(create_emission_entry->method);
        create_emission_entry->method = NULL;
    }
    if (create_emission_entry->scope) {
        free(create_emission_entry->scope);
        create_emission_entry->scope = NULL;
    }
    if (create_emission_entry->unit) {
        free(create_emission_entry->unit);
        create_emission_entry->unit = NULL;
    }
    if (create_emission_entry->year) {
        free(create_emission_entry->year);
        create_emission_entry->year = NULL;
    }
    free(create_emission_entry);
}

cJSON *create_emission_entry_convertToJSON(create_emission_entry_t *create_emission_entry) {
    cJSON *item = cJSON_CreateObject();

    // create_emission_entry->activity_value
    if (!create_emission_entry->activity_value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "activity_value", create_emission_entry->activity_value) == NULL) {
    goto fail; //String
    }


    // create_emission_entry->category_id
    if (!create_emission_entry->category_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "category_id", create_emission_entry->category_id) == NULL) {
    goto fail; //String
    }


    // create_emission_entry->description
    if (!create_emission_entry->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", create_emission_entry->description) == NULL) {
    goto fail; //String
    }


    // create_emission_entry->method
    if (!create_emission_entry->method) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "method", create_emission_entry->method) == NULL) {
    goto fail; //String
    }


    // create_emission_entry->scope
    if (!create_emission_entry->scope) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "scope", create_emission_entry->scope) == NULL) {
    goto fail; //String
    }


    // create_emission_entry->unit
    if (!create_emission_entry->unit) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "unit", create_emission_entry->unit) == NULL) {
    goto fail; //String
    }


    // create_emission_entry->year
    if (!create_emission_entry->year) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "year", *create_emission_entry->year) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_emission_entry_t *create_emission_entry_parseFromJSON(cJSON *create_emission_entryJSON){

    create_emission_entry_t *create_emission_entry_local_var = NULL;

    char *activity_value_local_str = NULL;

    char *category_id_local_str = NULL;

    char *description_local_str = NULL;

    char *method_local_str = NULL;

    char *scope_local_str = NULL;

    char *unit_local_str = NULL;

    // define the local variable for create_emission_entry->year
    int *year_local_var = NULL;

    // create_emission_entry->activity_value
    cJSON *activity_value = cJSON_GetObjectItemCaseSensitive(create_emission_entryJSON, "activity_value");
    if (cJSON_IsNull(activity_value)) {
        activity_value = NULL;
    }
    if (!activity_value) {
        goto end;
    }

    
    if(!cJSON_IsString(activity_value))
    {
    goto end; //String
    }

    // create_emission_entry->category_id
    cJSON *category_id = cJSON_GetObjectItemCaseSensitive(create_emission_entryJSON, "category_id");
    if (cJSON_IsNull(category_id)) {
        category_id = NULL;
    }
    if (!category_id) {
        goto end;
    }

    
    if(!cJSON_IsString(category_id))
    {
    goto end; //String
    }

    // create_emission_entry->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(create_emission_entryJSON, "description");
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

    // create_emission_entry->method
    cJSON *method = cJSON_GetObjectItemCaseSensitive(create_emission_entryJSON, "method");
    if (cJSON_IsNull(method)) {
        method = NULL;
    }
    if (!method) {
        goto end;
    }

    
    if(!cJSON_IsString(method))
    {
    goto end; //String
    }

    // create_emission_entry->scope
    cJSON *scope = cJSON_GetObjectItemCaseSensitive(create_emission_entryJSON, "scope");
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

    // create_emission_entry->unit
    cJSON *unit = cJSON_GetObjectItemCaseSensitive(create_emission_entryJSON, "unit");
    if (cJSON_IsNull(unit)) {
        unit = NULL;
    }
    if (!unit) {
        goto end;
    }

    
    if(!cJSON_IsString(unit))
    {
    goto end; //String
    }

    // create_emission_entry->year
    cJSON *year = cJSON_GetObjectItemCaseSensitive(create_emission_entryJSON, "year");
    if (cJSON_IsNull(year)) {
        year = NULL;
    }
    if (!year) {
        goto end;
    }

    
    if(!cJSON_IsNumber(year))
    {
    goto end; //Numeric
    }
    year_local_var = malloc(sizeof(int));
    if(!year_local_var)
    {
        goto end;
    }
    *year_local_var = year->valuedouble;


    if (activity_value && !cJSON_IsNull(activity_value)) activity_value_local_str = strdup(activity_value->valuestring);
    if (category_id && !cJSON_IsNull(category_id)) category_id_local_str = strdup(category_id->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (method && !cJSON_IsNull(method)) method_local_str = strdup(method->valuestring);
    if (scope && !cJSON_IsNull(scope)) scope_local_str = strdup(scope->valuestring);
    if (unit && !cJSON_IsNull(unit)) unit_local_str = strdup(unit->valuestring);

    create_emission_entry_local_var = create_emission_entry_create_internal (
        activity_value_local_str,
        category_id_local_str,
        description_local_str,
        method_local_str,
        scope_local_str,
        unit_local_str,
        year_local_var
        );

    if (!create_emission_entry_local_var) {
        goto end;
    }

    return create_emission_entry_local_var;
end:
    if (activity_value_local_str) {
        free(activity_value_local_str);
        activity_value_local_str = NULL;
    }
    if (category_id_local_str) {
        free(category_id_local_str);
        category_id_local_str = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (method_local_str) {
        free(method_local_str);
        method_local_str = NULL;
    }
    if (scope_local_str) {
        free(scope_local_str);
        scope_local_str = NULL;
    }
    if (unit_local_str) {
        free(unit_local_str);
        unit_local_str = NULL;
    }
    if (year_local_var) {
        free(year_local_var);
        year_local_var = NULL;
    }
    return NULL;

}
