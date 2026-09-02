#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "emission_factor_response.h"



static emission_factor_response_t *emission_factor_response_create_internal(
    char *category_id,
    double *kg_co2e_per_unit,
    char *name_de,
    char *source,
    char *unit,
    char *version
    ) {
    emission_factor_response_t *emission_factor_response_local_var = malloc(sizeof(emission_factor_response_t));
    if (!emission_factor_response_local_var) {
        return NULL;
    }
    memset(emission_factor_response_local_var, 0, sizeof(emission_factor_response_t));
    emission_factor_response_local_var->_library_owned = 1;
    emission_factor_response_local_var->category_id = category_id;
    emission_factor_response_local_var->kg_co2e_per_unit = kg_co2e_per_unit;
    emission_factor_response_local_var->name_de = name_de;
    emission_factor_response_local_var->source = source;
    emission_factor_response_local_var->unit = unit;
    emission_factor_response_local_var->version = version;
    return emission_factor_response_local_var;
}

__attribute__((deprecated)) emission_factor_response_t *emission_factor_response_create(
    char *category_id,
    double *kg_co2e_per_unit,
    char *name_de,
    char *source,
    char *unit,
    char *version
    ) {
    double *kg_co2e_per_unit_copy = NULL;
    if (kg_co2e_per_unit) {
        kg_co2e_per_unit_copy = malloc(sizeof(double));
        if (kg_co2e_per_unit_copy) *kg_co2e_per_unit_copy = *kg_co2e_per_unit;
    }
    emission_factor_response_t *result = emission_factor_response_create_internal (
        category_id,
        kg_co2e_per_unit_copy,
        name_de,
        source,
        unit,
        version
        );
    if (!result) {
        free(kg_co2e_per_unit_copy);
    }
    return result;
}

void emission_factor_response_free(emission_factor_response_t *emission_factor_response) {
    if(NULL == emission_factor_response){
        return ;
    }
    if(emission_factor_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "emission_factor_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (emission_factor_response->category_id) {
        free(emission_factor_response->category_id);
        emission_factor_response->category_id = NULL;
    }
    if (emission_factor_response->kg_co2e_per_unit) {
        free(emission_factor_response->kg_co2e_per_unit);
        emission_factor_response->kg_co2e_per_unit = NULL;
    }
    if (emission_factor_response->name_de) {
        free(emission_factor_response->name_de);
        emission_factor_response->name_de = NULL;
    }
    if (emission_factor_response->source) {
        free(emission_factor_response->source);
        emission_factor_response->source = NULL;
    }
    if (emission_factor_response->unit) {
        free(emission_factor_response->unit);
        emission_factor_response->unit = NULL;
    }
    if (emission_factor_response->version) {
        free(emission_factor_response->version);
        emission_factor_response->version = NULL;
    }
    free(emission_factor_response);
}

cJSON *emission_factor_response_convertToJSON(emission_factor_response_t *emission_factor_response) {
    cJSON *item = cJSON_CreateObject();

    // emission_factor_response->category_id
    if (!emission_factor_response->category_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "category_id", emission_factor_response->category_id) == NULL) {
    goto fail; //String
    }


    // emission_factor_response->kg_co2e_per_unit
    if (!emission_factor_response->kg_co2e_per_unit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "kg_co2e_per_unit", *emission_factor_response->kg_co2e_per_unit) == NULL) {
    goto fail; //Numeric
    }


    // emission_factor_response->name_de
    if (!emission_factor_response->name_de) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name_de", emission_factor_response->name_de) == NULL) {
    goto fail; //String
    }


    // emission_factor_response->source
    if (!emission_factor_response->source) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "source", emission_factor_response->source) == NULL) {
    goto fail; //String
    }


    // emission_factor_response->unit
    if (!emission_factor_response->unit) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "unit", emission_factor_response->unit) == NULL) {
    goto fail; //String
    }


    // emission_factor_response->version
    if (!emission_factor_response->version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "version", emission_factor_response->version) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

emission_factor_response_t *emission_factor_response_parseFromJSON(cJSON *emission_factor_responseJSON){

    emission_factor_response_t *emission_factor_response_local_var = NULL;

    char *category_id_local_str = NULL;

    // define the local variable for emission_factor_response->kg_co2e_per_unit
    double *kg_co2e_per_unit_local_var = NULL;

    char *name_de_local_str = NULL;

    char *source_local_str = NULL;

    char *unit_local_str = NULL;

    char *version_local_str = NULL;

    // emission_factor_response->category_id
    cJSON *category_id = cJSON_GetObjectItemCaseSensitive(emission_factor_responseJSON, "category_id");
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

    // emission_factor_response->kg_co2e_per_unit
    cJSON *kg_co2e_per_unit = cJSON_GetObjectItemCaseSensitive(emission_factor_responseJSON, "kg_co2e_per_unit");
    if (cJSON_IsNull(kg_co2e_per_unit)) {
        kg_co2e_per_unit = NULL;
    }
    if (!kg_co2e_per_unit) {
        goto end;
    }

    
    if(!cJSON_IsNumber(kg_co2e_per_unit))
    {
    goto end; //Numeric
    }
    kg_co2e_per_unit_local_var = malloc(sizeof(double));
    if(!kg_co2e_per_unit_local_var)
    {
        goto end;
    }
    *kg_co2e_per_unit_local_var = kg_co2e_per_unit->valuedouble;

    // emission_factor_response->name_de
    cJSON *name_de = cJSON_GetObjectItemCaseSensitive(emission_factor_responseJSON, "name_de");
    if (cJSON_IsNull(name_de)) {
        name_de = NULL;
    }
    if (!name_de) {
        goto end;
    }

    
    if(!cJSON_IsString(name_de))
    {
    goto end; //String
    }

    // emission_factor_response->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(emission_factor_responseJSON, "source");
    if (cJSON_IsNull(source)) {
        source = NULL;
    }
    if (!source) {
        goto end;
    }

    
    if(!cJSON_IsString(source))
    {
    goto end; //String
    }

    // emission_factor_response->unit
    cJSON *unit = cJSON_GetObjectItemCaseSensitive(emission_factor_responseJSON, "unit");
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

    // emission_factor_response->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(emission_factor_responseJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (!version) {
        goto end;
    }

    
    if(!cJSON_IsString(version))
    {
    goto end; //String
    }


    if (category_id && !cJSON_IsNull(category_id)) category_id_local_str = strdup(category_id->valuestring);
    if (name_de && !cJSON_IsNull(name_de)) name_de_local_str = strdup(name_de->valuestring);
    if (source && !cJSON_IsNull(source)) source_local_str = strdup(source->valuestring);
    if (unit && !cJSON_IsNull(unit)) unit_local_str = strdup(unit->valuestring);
    if (version && !cJSON_IsNull(version)) version_local_str = strdup(version->valuestring);

    emission_factor_response_local_var = emission_factor_response_create_internal (
        category_id_local_str,
        kg_co2e_per_unit_local_var,
        name_de_local_str,
        source_local_str,
        unit_local_str,
        version_local_str
        );

    if (!emission_factor_response_local_var) {
        goto end;
    }

    return emission_factor_response_local_var;
end:
    if (category_id_local_str) {
        free(category_id_local_str);
        category_id_local_str = NULL;
    }
    if (kg_co2e_per_unit_local_var) {
        free(kg_co2e_per_unit_local_var);
        kg_co2e_per_unit_local_var = NULL;
    }
    if (name_de_local_str) {
        free(name_de_local_str);
        name_de_local_str = NULL;
    }
    if (source_local_str) {
        free(source_local_str);
        source_local_str = NULL;
    }
    if (unit_local_str) {
        free(unit_local_str);
        unit_local_str = NULL;
    }
    if (version_local_str) {
        free(version_local_str);
        version_local_str = NULL;
    }
    return NULL;

}
