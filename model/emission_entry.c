#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "emission_entry.h"



static emission_entry_t *emission_entry_create_internal(
    char *activity_value,
    char *category_id,
    char *description,
    char *ef_source,
    char *ef_version,
    emission_method_t *method,
    ghg_scope_t *scope,
    char *tco2e,
    char *unit,
    char *updated_at,
    int *year
    ) {
    emission_entry_t *emission_entry_local_var = malloc(sizeof(emission_entry_t));
    if (!emission_entry_local_var) {
        return NULL;
    }
    memset(emission_entry_local_var, 0, sizeof(emission_entry_t));
    emission_entry_local_var->_library_owned = 1;
    emission_entry_local_var->activity_value = activity_value;
    emission_entry_local_var->category_id = category_id;
    emission_entry_local_var->description = description;
    emission_entry_local_var->ef_source = ef_source;
    emission_entry_local_var->ef_version = ef_version;
    emission_entry_local_var->method = method;
    emission_entry_local_var->scope = scope;
    emission_entry_local_var->tco2e = tco2e;
    emission_entry_local_var->unit = unit;
    emission_entry_local_var->updated_at = updated_at;
    emission_entry_local_var->year = year;
    return emission_entry_local_var;
}

__attribute__((deprecated)) emission_entry_t *emission_entry_create(
    char *activity_value,
    char *category_id,
    char *description,
    char *ef_source,
    char *ef_version,
    emission_method_t *method,
    ghg_scope_t *scope,
    char *tco2e,
    char *unit,
    char *updated_at,
    int *year
    ) {
    int *year_copy = NULL;
    if (year) {
        year_copy = malloc(sizeof(int));
        if (year_copy) *year_copy = *year;
    }
    emission_entry_t *result = emission_entry_create_internal (
        activity_value,
        category_id,
        description,
        ef_source,
        ef_version,
        method,
        scope,
        tco2e,
        unit,
        updated_at,
        year_copy
        );
    if (!result) {
        free(year_copy);
    }
    return result;
}

void emission_entry_free(emission_entry_t *emission_entry) {
    if(NULL == emission_entry){
        return ;
    }
    if(emission_entry->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "emission_entry_free");
        return ;
    }
    listEntry_t *listEntry;
    if (emission_entry->activity_value) {
        free(emission_entry->activity_value);
        emission_entry->activity_value = NULL;
    }
    if (emission_entry->category_id) {
        free(emission_entry->category_id);
        emission_entry->category_id = NULL;
    }
    if (emission_entry->description) {
        free(emission_entry->description);
        emission_entry->description = NULL;
    }
    if (emission_entry->ef_source) {
        free(emission_entry->ef_source);
        emission_entry->ef_source = NULL;
    }
    if (emission_entry->ef_version) {
        free(emission_entry->ef_version);
        emission_entry->ef_version = NULL;
    }
    if (emission_entry->method) {
        emission_method_free(emission_entry->method);
        emission_entry->method = NULL;
    }
    if (emission_entry->scope) {
        ghg_scope_free(emission_entry->scope);
        emission_entry->scope = NULL;
    }
    if (emission_entry->tco2e) {
        free(emission_entry->tco2e);
        emission_entry->tco2e = NULL;
    }
    if (emission_entry->unit) {
        free(emission_entry->unit);
        emission_entry->unit = NULL;
    }
    if (emission_entry->updated_at) {
        free(emission_entry->updated_at);
        emission_entry->updated_at = NULL;
    }
    if (emission_entry->year) {
        free(emission_entry->year);
        emission_entry->year = NULL;
    }
    free(emission_entry);
}

cJSON *emission_entry_convertToJSON(emission_entry_t *emission_entry) {
    cJSON *item = cJSON_CreateObject();

    // emission_entry->activity_value
    if (!emission_entry->activity_value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "activityValue", emission_entry->activity_value) == NULL) {
    goto fail; //String
    }


    // emission_entry->category_id
    if (!emission_entry->category_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "categoryId", emission_entry->category_id) == NULL) {
    goto fail; //String
    }


    // emission_entry->description
    if (!emission_entry->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", emission_entry->description) == NULL) {
    goto fail; //String
    }


    // emission_entry->ef_source
    if (!emission_entry->ef_source) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "efSource", emission_entry->ef_source) == NULL) {
    goto fail; //String
    }


    // emission_entry->ef_version
    if (!emission_entry->ef_version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "efVersion", emission_entry->ef_version) == NULL) {
    goto fail; //String
    }


    // emission_entry->method
    if (!emission_entry->method) {
        goto fail;
    }
    cJSON *method_local_JSON = emission_method_convertToJSON(emission_entry->method);
    if(method_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "method", method_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // emission_entry->scope
    if (!emission_entry->scope) {
        goto fail;
    }
    cJSON *scope_local_JSON = ghg_scope_convertToJSON(emission_entry->scope);
    if(scope_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "scope", scope_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // emission_entry->tco2e
    if (!emission_entry->tco2e) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tco2e", emission_entry->tco2e) == NULL) {
    goto fail; //String
    }


    // emission_entry->unit
    if (!emission_entry->unit) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "unit", emission_entry->unit) == NULL) {
    goto fail; //String
    }


    // emission_entry->updated_at
    if(emission_entry->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", emission_entry->updated_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // emission_entry->year
    if (!emission_entry->year) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "year", *emission_entry->year) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

emission_entry_t *emission_entry_parseFromJSON(cJSON *emission_entryJSON){

    emission_entry_t *emission_entry_local_var = NULL;

    char *activity_value_local_str = NULL;

    char *category_id_local_str = NULL;

    char *description_local_str = NULL;

    char *ef_source_local_str = NULL;

    char *ef_version_local_str = NULL;

    // define the local variable for emission_entry->method
    emission_method_t *method_local_nonprim = NULL;

    // define the local variable for emission_entry->scope
    ghg_scope_t *scope_local_nonprim = NULL;

    char *tco2e_local_str = NULL;

    char *unit_local_str = NULL;

    char *updated_at_local_str = NULL;

    // define the local variable for emission_entry->year
    int *year_local_var = NULL;

    // emission_entry->activity_value
    cJSON *activity_value = cJSON_GetObjectItemCaseSensitive(emission_entryJSON, "activityValue");
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

    // emission_entry->category_id
    cJSON *category_id = cJSON_GetObjectItemCaseSensitive(emission_entryJSON, "categoryId");
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

    // emission_entry->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(emission_entryJSON, "description");
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

    // emission_entry->ef_source
    cJSON *ef_source = cJSON_GetObjectItemCaseSensitive(emission_entryJSON, "efSource");
    if (cJSON_IsNull(ef_source)) {
        ef_source = NULL;
    }
    if (!ef_source) {
        goto end;
    }

    
    if(!cJSON_IsString(ef_source))
    {
    goto end; //String
    }

    // emission_entry->ef_version
    cJSON *ef_version = cJSON_GetObjectItemCaseSensitive(emission_entryJSON, "efVersion");
    if (cJSON_IsNull(ef_version)) {
        ef_version = NULL;
    }
    if (!ef_version) {
        goto end;
    }

    
    if(!cJSON_IsString(ef_version))
    {
    goto end; //String
    }

    // emission_entry->method
    cJSON *method = cJSON_GetObjectItemCaseSensitive(emission_entryJSON, "method");
    if (cJSON_IsNull(method)) {
        method = NULL;
    }
    if (!method) {
        goto end;
    }

    
    method_local_nonprim = emission_method_parseFromJSON(method); //custom

    // emission_entry->scope
    cJSON *scope = cJSON_GetObjectItemCaseSensitive(emission_entryJSON, "scope");
    if (cJSON_IsNull(scope)) {
        scope = NULL;
    }
    if (!scope) {
        goto end;
    }

    
    scope_local_nonprim = ghg_scope_parseFromJSON(scope); //custom

    // emission_entry->tco2e
    cJSON *tco2e = cJSON_GetObjectItemCaseSensitive(emission_entryJSON, "tco2e");
    if (cJSON_IsNull(tco2e)) {
        tco2e = NULL;
    }
    if (!tco2e) {
        goto end;
    }

    
    if(!cJSON_IsString(tco2e))
    {
    goto end; //String
    }

    // emission_entry->unit
    cJSON *unit = cJSON_GetObjectItemCaseSensitive(emission_entryJSON, "unit");
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

    // emission_entry->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(emission_entryJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }

    // emission_entry->year
    cJSON *year = cJSON_GetObjectItemCaseSensitive(emission_entryJSON, "year");
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
    if (ef_source && !cJSON_IsNull(ef_source)) ef_source_local_str = strdup(ef_source->valuestring);
    if (ef_version && !cJSON_IsNull(ef_version)) ef_version_local_str = strdup(ef_version->valuestring);
    if (tco2e && !cJSON_IsNull(tco2e)) tco2e_local_str = strdup(tco2e->valuestring);
    if (unit && !cJSON_IsNull(unit)) unit_local_str = strdup(unit->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);

    emission_entry_local_var = emission_entry_create_internal (
        activity_value_local_str,
        category_id_local_str,
        description_local_str,
        ef_source_local_str,
        ef_version_local_str,
        method_local_nonprim,
        scope_local_nonprim,
        tco2e_local_str,
        unit_local_str,
        updated_at_local_str,
        year_local_var
        );

    if (!emission_entry_local_var) {
        goto end;
    }

    return emission_entry_local_var;
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
    if (ef_source_local_str) {
        free(ef_source_local_str);
        ef_source_local_str = NULL;
    }
    if (ef_version_local_str) {
        free(ef_version_local_str);
        ef_version_local_str = NULL;
    }
    if (method_local_nonprim) {
        emission_method_free(method_local_nonprim);
        method_local_nonprim = NULL;
    }
    if (scope_local_nonprim) {
        ghg_scope_free(scope_local_nonprim);
        scope_local_nonprim = NULL;
    }
    if (tco2e_local_str) {
        free(tco2e_local_str);
        tco2e_local_str = NULL;
    }
    if (unit_local_str) {
        free(unit_local_str);
        unit_local_str = NULL;
    }
    if (updated_at_local_str) {
        free(updated_at_local_str);
        updated_at_local_str = NULL;
    }
    if (year_local_var) {
        free(year_local_var);
        year_local_var = NULL;
    }
    return NULL;

}
