#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hebesatz_lookup.h"



static hebesatz_lookup_t *hebesatz_lookup_create_internal(
    char *bundesland,
    char *country_code,
    char *gemeinde_name,
    char *gemeindeschluessel,
    double *hebesatz_gewerbesteuer,
    double *hebesatz_grundsteuer_b,
    int *jahr,
    char *landkreis,
    char *valid_from,
    char *valid_to
    ) {
    hebesatz_lookup_t *hebesatz_lookup_local_var = malloc(sizeof(hebesatz_lookup_t));
    if (!hebesatz_lookup_local_var) {
        return NULL;
    }
    memset(hebesatz_lookup_local_var, 0, sizeof(hebesatz_lookup_t));
    hebesatz_lookup_local_var->_library_owned = 1;
    hebesatz_lookup_local_var->bundesland = bundesland;
    hebesatz_lookup_local_var->country_code = country_code;
    hebesatz_lookup_local_var->gemeinde_name = gemeinde_name;
    hebesatz_lookup_local_var->gemeindeschluessel = gemeindeschluessel;
    hebesatz_lookup_local_var->hebesatz_gewerbesteuer = hebesatz_gewerbesteuer;
    hebesatz_lookup_local_var->hebesatz_grundsteuer_b = hebesatz_grundsteuer_b;
    hebesatz_lookup_local_var->jahr = jahr;
    hebesatz_lookup_local_var->landkreis = landkreis;
    hebesatz_lookup_local_var->valid_from = valid_from;
    hebesatz_lookup_local_var->valid_to = valid_to;
    return hebesatz_lookup_local_var;
}

__attribute__((deprecated)) hebesatz_lookup_t *hebesatz_lookup_create(
    char *bundesland,
    char *country_code,
    char *gemeinde_name,
    char *gemeindeschluessel,
    double *hebesatz_gewerbesteuer,
    double *hebesatz_grundsteuer_b,
    int *jahr,
    char *landkreis,
    char *valid_from,
    char *valid_to
    ) {
    double *hebesatz_gewerbesteuer_copy = NULL;
    if (hebesatz_gewerbesteuer) {
        hebesatz_gewerbesteuer_copy = malloc(sizeof(double));
        if (hebesatz_gewerbesteuer_copy) *hebesatz_gewerbesteuer_copy = *hebesatz_gewerbesteuer;
    }
    double *hebesatz_grundsteuer_b_copy = NULL;
    if (hebesatz_grundsteuer_b) {
        hebesatz_grundsteuer_b_copy = malloc(sizeof(double));
        if (hebesatz_grundsteuer_b_copy) *hebesatz_grundsteuer_b_copy = *hebesatz_grundsteuer_b;
    }
    int *jahr_copy = NULL;
    if (jahr) {
        jahr_copy = malloc(sizeof(int));
        if (jahr_copy) *jahr_copy = *jahr;
    }
    hebesatz_lookup_t *result = hebesatz_lookup_create_internal (
        bundesland,
        country_code,
        gemeinde_name,
        gemeindeschluessel,
        hebesatz_gewerbesteuer_copy,
        hebesatz_grundsteuer_b_copy,
        jahr_copy,
        landkreis,
        valid_from,
        valid_to
        );
    if (!result) {
        free(hebesatz_gewerbesteuer_copy);
        free(hebesatz_grundsteuer_b_copy);
        free(jahr_copy);
    }
    return result;
}

void hebesatz_lookup_free(hebesatz_lookup_t *hebesatz_lookup) {
    if(NULL == hebesatz_lookup){
        return ;
    }
    if(hebesatz_lookup->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "hebesatz_lookup_free");
        return ;
    }
    listEntry_t *listEntry;
    if (hebesatz_lookup->bundesland) {
        free(hebesatz_lookup->bundesland);
        hebesatz_lookup->bundesland = NULL;
    }
    if (hebesatz_lookup->country_code) {
        free(hebesatz_lookup->country_code);
        hebesatz_lookup->country_code = NULL;
    }
    if (hebesatz_lookup->gemeinde_name) {
        free(hebesatz_lookup->gemeinde_name);
        hebesatz_lookup->gemeinde_name = NULL;
    }
    if (hebesatz_lookup->gemeindeschluessel) {
        free(hebesatz_lookup->gemeindeschluessel);
        hebesatz_lookup->gemeindeschluessel = NULL;
    }
    if (hebesatz_lookup->hebesatz_gewerbesteuer) {
        free(hebesatz_lookup->hebesatz_gewerbesteuer);
        hebesatz_lookup->hebesatz_gewerbesteuer = NULL;
    }
    if (hebesatz_lookup->hebesatz_grundsteuer_b) {
        free(hebesatz_lookup->hebesatz_grundsteuer_b);
        hebesatz_lookup->hebesatz_grundsteuer_b = NULL;
    }
    if (hebesatz_lookup->jahr) {
        free(hebesatz_lookup->jahr);
        hebesatz_lookup->jahr = NULL;
    }
    if (hebesatz_lookup->landkreis) {
        free(hebesatz_lookup->landkreis);
        hebesatz_lookup->landkreis = NULL;
    }
    if (hebesatz_lookup->valid_from) {
        free(hebesatz_lookup->valid_from);
        hebesatz_lookup->valid_from = NULL;
    }
    if (hebesatz_lookup->valid_to) {
        free(hebesatz_lookup->valid_to);
        hebesatz_lookup->valid_to = NULL;
    }
    free(hebesatz_lookup);
}

cJSON *hebesatz_lookup_convertToJSON(hebesatz_lookup_t *hebesatz_lookup) {
    cJSON *item = cJSON_CreateObject();

    // hebesatz_lookup->bundesland
    if (!hebesatz_lookup->bundesland) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "bundesland", hebesatz_lookup->bundesland) == NULL) {
    goto fail; //String
    }


    // hebesatz_lookup->country_code
    if (!hebesatz_lookup->country_code) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "country_code", hebesatz_lookup->country_code) == NULL) {
    goto fail; //String
    }


    // hebesatz_lookup->gemeinde_name
    if (!hebesatz_lookup->gemeinde_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gemeinde_name", hebesatz_lookup->gemeinde_name) == NULL) {
    goto fail; //String
    }


    // hebesatz_lookup->gemeindeschluessel
    if (!hebesatz_lookup->gemeindeschluessel) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gemeindeschluessel", hebesatz_lookup->gemeindeschluessel) == NULL) {
    goto fail; //String
    }


    // hebesatz_lookup->hebesatz_gewerbesteuer
    if (!hebesatz_lookup->hebesatz_gewerbesteuer) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "hebesatz_gewerbesteuer", *hebesatz_lookup->hebesatz_gewerbesteuer) == NULL) {
    goto fail; //Numeric
    }


    // hebesatz_lookup->hebesatz_grundsteuer_b
    if(hebesatz_lookup->hebesatz_grundsteuer_b) {
    if(cJSON_AddNumberToObject(item, "hebesatz_grundsteuer_b", *hebesatz_lookup->hebesatz_grundsteuer_b) == NULL) {
    goto fail; //Numeric
    }
    }


    // hebesatz_lookup->jahr
    if (!hebesatz_lookup->jahr) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "jahr", *hebesatz_lookup->jahr) == NULL) {
    goto fail; //Numeric
    }


    // hebesatz_lookup->landkreis
    if(hebesatz_lookup->landkreis) {
    if(cJSON_AddStringToObject(item, "landkreis", hebesatz_lookup->landkreis) == NULL) {
    goto fail; //String
    }
    }


    // hebesatz_lookup->valid_from
    if (!hebesatz_lookup->valid_from) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "valid_from", hebesatz_lookup->valid_from) == NULL) {
    goto fail; //String
    }


    // hebesatz_lookup->valid_to
    if(hebesatz_lookup->valid_to) {
    if(cJSON_AddStringToObject(item, "valid_to", hebesatz_lookup->valid_to) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

hebesatz_lookup_t *hebesatz_lookup_parseFromJSON(cJSON *hebesatz_lookupJSON){

    hebesatz_lookup_t *hebesatz_lookup_local_var = NULL;

    char *bundesland_local_str = NULL;

    char *country_code_local_str = NULL;

    char *gemeinde_name_local_str = NULL;

    char *gemeindeschluessel_local_str = NULL;

    // define the local variable for hebesatz_lookup->hebesatz_gewerbesteuer
    double *hebesatz_gewerbesteuer_local_var = NULL;

    // define the local variable for hebesatz_lookup->hebesatz_grundsteuer_b
    double *hebesatz_grundsteuer_b_local_var = NULL;

    // define the local variable for hebesatz_lookup->jahr
    int *jahr_local_var = NULL;

    char *landkreis_local_str = NULL;

    char *valid_from_local_str = NULL;

    char *valid_to_local_str = NULL;

    // hebesatz_lookup->bundesland
    cJSON *bundesland = cJSON_GetObjectItemCaseSensitive(hebesatz_lookupJSON, "bundesland");
    if (cJSON_IsNull(bundesland)) {
        bundesland = NULL;
    }
    if (!bundesland) {
        goto end;
    }

    
    if(!cJSON_IsString(bundesland))
    {
    goto end; //String
    }

    // hebesatz_lookup->country_code
    cJSON *country_code = cJSON_GetObjectItemCaseSensitive(hebesatz_lookupJSON, "country_code");
    if (cJSON_IsNull(country_code)) {
        country_code = NULL;
    }
    if (!country_code) {
        goto end;
    }

    
    if(!cJSON_IsString(country_code))
    {
    goto end; //String
    }

    // hebesatz_lookup->gemeinde_name
    cJSON *gemeinde_name = cJSON_GetObjectItemCaseSensitive(hebesatz_lookupJSON, "gemeinde_name");
    if (cJSON_IsNull(gemeinde_name)) {
        gemeinde_name = NULL;
    }
    if (!gemeinde_name) {
        goto end;
    }

    
    if(!cJSON_IsString(gemeinde_name))
    {
    goto end; //String
    }

    // hebesatz_lookup->gemeindeschluessel
    cJSON *gemeindeschluessel = cJSON_GetObjectItemCaseSensitive(hebesatz_lookupJSON, "gemeindeschluessel");
    if (cJSON_IsNull(gemeindeschluessel)) {
        gemeindeschluessel = NULL;
    }
    if (!gemeindeschluessel) {
        goto end;
    }

    
    if(!cJSON_IsString(gemeindeschluessel))
    {
    goto end; //String
    }

    // hebesatz_lookup->hebesatz_gewerbesteuer
    cJSON *hebesatz_gewerbesteuer = cJSON_GetObjectItemCaseSensitive(hebesatz_lookupJSON, "hebesatz_gewerbesteuer");
    if (cJSON_IsNull(hebesatz_gewerbesteuer)) {
        hebesatz_gewerbesteuer = NULL;
    }
    if (!hebesatz_gewerbesteuer) {
        goto end;
    }

    
    if(!cJSON_IsNumber(hebesatz_gewerbesteuer))
    {
    goto end; //Numeric
    }
    hebesatz_gewerbesteuer_local_var = malloc(sizeof(double));
    if(!hebesatz_gewerbesteuer_local_var)
    {
        goto end;
    }
    *hebesatz_gewerbesteuer_local_var = hebesatz_gewerbesteuer->valuedouble;

    // hebesatz_lookup->hebesatz_grundsteuer_b
    cJSON *hebesatz_grundsteuer_b = cJSON_GetObjectItemCaseSensitive(hebesatz_lookupJSON, "hebesatz_grundsteuer_b");
    if (cJSON_IsNull(hebesatz_grundsteuer_b)) {
        hebesatz_grundsteuer_b = NULL;
    }
    if (hebesatz_grundsteuer_b) { 
    if(!cJSON_IsNumber(hebesatz_grundsteuer_b))
    {
    goto end; //Numeric
    }
    hebesatz_grundsteuer_b_local_var = malloc(sizeof(double));
    if(!hebesatz_grundsteuer_b_local_var)
    {
        goto end;
    }
    *hebesatz_grundsteuer_b_local_var = hebesatz_grundsteuer_b->valuedouble;
    }

    // hebesatz_lookup->jahr
    cJSON *jahr = cJSON_GetObjectItemCaseSensitive(hebesatz_lookupJSON, "jahr");
    if (cJSON_IsNull(jahr)) {
        jahr = NULL;
    }
    if (!jahr) {
        goto end;
    }

    
    if(!cJSON_IsNumber(jahr))
    {
    goto end; //Numeric
    }
    jahr_local_var = malloc(sizeof(int));
    if(!jahr_local_var)
    {
        goto end;
    }
    *jahr_local_var = jahr->valuedouble;

    // hebesatz_lookup->landkreis
    cJSON *landkreis = cJSON_GetObjectItemCaseSensitive(hebesatz_lookupJSON, "landkreis");
    if (cJSON_IsNull(landkreis)) {
        landkreis = NULL;
    }
    if (landkreis) { 
    if(!cJSON_IsString(landkreis) && !cJSON_IsNull(landkreis))
    {
    goto end; //String
    }
    }

    // hebesatz_lookup->valid_from
    cJSON *valid_from = cJSON_GetObjectItemCaseSensitive(hebesatz_lookupJSON, "valid_from");
    if (cJSON_IsNull(valid_from)) {
        valid_from = NULL;
    }
    if (!valid_from) {
        goto end;
    }

    
    if(!cJSON_IsString(valid_from))
    {
    goto end; //String
    }

    // hebesatz_lookup->valid_to
    cJSON *valid_to = cJSON_GetObjectItemCaseSensitive(hebesatz_lookupJSON, "valid_to");
    if (cJSON_IsNull(valid_to)) {
        valid_to = NULL;
    }
    if (valid_to) { 
    if(!cJSON_IsString(valid_to) && !cJSON_IsNull(valid_to))
    {
    goto end; //String
    }
    }


    if (bundesland && !cJSON_IsNull(bundesland)) bundesland_local_str = strdup(bundesland->valuestring);
    if (country_code && !cJSON_IsNull(country_code)) country_code_local_str = strdup(country_code->valuestring);
    if (gemeinde_name && !cJSON_IsNull(gemeinde_name)) gemeinde_name_local_str = strdup(gemeinde_name->valuestring);
    if (gemeindeschluessel && !cJSON_IsNull(gemeindeschluessel)) gemeindeschluessel_local_str = strdup(gemeindeschluessel->valuestring);
    if (landkreis && !cJSON_IsNull(landkreis)) landkreis_local_str = strdup(landkreis->valuestring);
    if (valid_from && !cJSON_IsNull(valid_from)) valid_from_local_str = strdup(valid_from->valuestring);
    if (valid_to && !cJSON_IsNull(valid_to)) valid_to_local_str = strdup(valid_to->valuestring);

    hebesatz_lookup_local_var = hebesatz_lookup_create_internal (
        bundesland_local_str,
        country_code_local_str,
        gemeinde_name_local_str,
        gemeindeschluessel_local_str,
        hebesatz_gewerbesteuer_local_var,
        hebesatz_grundsteuer_b_local_var,
        jahr_local_var,
        landkreis_local_str,
        valid_from_local_str,
        valid_to_local_str
        );

    if (!hebesatz_lookup_local_var) {
        goto end;
    }

    return hebesatz_lookup_local_var;
end:
    if (bundesland_local_str) {
        free(bundesland_local_str);
        bundesland_local_str = NULL;
    }
    if (country_code_local_str) {
        free(country_code_local_str);
        country_code_local_str = NULL;
    }
    if (gemeinde_name_local_str) {
        free(gemeinde_name_local_str);
        gemeinde_name_local_str = NULL;
    }
    if (gemeindeschluessel_local_str) {
        free(gemeindeschluessel_local_str);
        gemeindeschluessel_local_str = NULL;
    }
    if (hebesatz_gewerbesteuer_local_var) {
        free(hebesatz_gewerbesteuer_local_var);
        hebesatz_gewerbesteuer_local_var = NULL;
    }
    if (hebesatz_grundsteuer_b_local_var) {
        free(hebesatz_grundsteuer_b_local_var);
        hebesatz_grundsteuer_b_local_var = NULL;
    }
    if (jahr_local_var) {
        free(jahr_local_var);
        jahr_local_var = NULL;
    }
    if (landkreis_local_str) {
        free(landkreis_local_str);
        landkreis_local_str = NULL;
    }
    if (valid_from_local_str) {
        free(valid_from_local_str);
        valid_from_local_str = NULL;
    }
    if (valid_to_local_str) {
        free(valid_to_local_str);
        valid_to_local_str = NULL;
    }
    return NULL;

}
