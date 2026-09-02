#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "group_figure.h"



static group_figure_t *group_figure_create_internal(
    char *bilanzsumme,
    int *exemption_claimed,
    long *mitarbeiter,
    char *netto_umsatz,
    char *parent_name,
    char *parent_situs,
    int *year
    ) {
    group_figure_t *group_figure_local_var = malloc(sizeof(group_figure_t));
    if (!group_figure_local_var) {
        return NULL;
    }
    memset(group_figure_local_var, 0, sizeof(group_figure_t));
    group_figure_local_var->_library_owned = 1;
    group_figure_local_var->bilanzsumme = bilanzsumme;
    group_figure_local_var->exemption_claimed = exemption_claimed;
    group_figure_local_var->mitarbeiter = mitarbeiter;
    group_figure_local_var->netto_umsatz = netto_umsatz;
    group_figure_local_var->parent_name = parent_name;
    group_figure_local_var->parent_situs = parent_situs;
    group_figure_local_var->year = year;
    return group_figure_local_var;
}

__attribute__((deprecated)) group_figure_t *group_figure_create(
    char *bilanzsumme,
    int *exemption_claimed,
    long *mitarbeiter,
    char *netto_umsatz,
    char *parent_name,
    char *parent_situs,
    int *year
    ) {
    int *exemption_claimed_copy = NULL;
    if (exemption_claimed) {
        exemption_claimed_copy = malloc(sizeof(int));
        if (exemption_claimed_copy) *exemption_claimed_copy = *exemption_claimed;
    }
    long *mitarbeiter_copy = NULL;
    if (mitarbeiter) {
        mitarbeiter_copy = malloc(sizeof(long));
        if (mitarbeiter_copy) *mitarbeiter_copy = *mitarbeiter;
    }
    int *year_copy = NULL;
    if (year) {
        year_copy = malloc(sizeof(int));
        if (year_copy) *year_copy = *year;
    }
    group_figure_t *result = group_figure_create_internal (
        bilanzsumme,
        exemption_claimed_copy,
        mitarbeiter_copy,
        netto_umsatz,
        parent_name,
        parent_situs,
        year_copy
        );
    if (!result) {
        free(exemption_claimed_copy);
        free(mitarbeiter_copy);
        free(year_copy);
    }
    return result;
}

void group_figure_free(group_figure_t *group_figure) {
    if(NULL == group_figure){
        return ;
    }
    if(group_figure->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "group_figure_free");
        return ;
    }
    listEntry_t *listEntry;
    if (group_figure->bilanzsumme) {
        free(group_figure->bilanzsumme);
        group_figure->bilanzsumme = NULL;
    }
    if (group_figure->exemption_claimed) {
        free(group_figure->exemption_claimed);
        group_figure->exemption_claimed = NULL;
    }
    if (group_figure->mitarbeiter) {
        free(group_figure->mitarbeiter);
        group_figure->mitarbeiter = NULL;
    }
    if (group_figure->netto_umsatz) {
        free(group_figure->netto_umsatz);
        group_figure->netto_umsatz = NULL;
    }
    if (group_figure->parent_name) {
        free(group_figure->parent_name);
        group_figure->parent_name = NULL;
    }
    if (group_figure->parent_situs) {
        free(group_figure->parent_situs);
        group_figure->parent_situs = NULL;
    }
    if (group_figure->year) {
        free(group_figure->year);
        group_figure->year = NULL;
    }
    free(group_figure);
}

cJSON *group_figure_convertToJSON(group_figure_t *group_figure) {
    cJSON *item = cJSON_CreateObject();

    // group_figure->bilanzsumme
    if(group_figure->bilanzsumme) {
    if(cJSON_AddStringToObject(item, "bilanzsumme", group_figure->bilanzsumme) == NULL) {
    goto fail; //String
    }
    }


    // group_figure->exemption_claimed
    if(group_figure->exemption_claimed) {
    if(cJSON_AddBoolToObject(item, "exemptionClaimed", *group_figure->exemption_claimed) == NULL) {
    goto fail; //Bool
    }
    }


    // group_figure->mitarbeiter
    if(group_figure->mitarbeiter) {
    if(cJSON_AddNumberToObject(item, "mitarbeiter", *group_figure->mitarbeiter) == NULL) {
    goto fail; //Numeric
    }
    }


    // group_figure->netto_umsatz
    if(group_figure->netto_umsatz) {
    if(cJSON_AddStringToObject(item, "nettoUmsatz", group_figure->netto_umsatz) == NULL) {
    goto fail; //String
    }
    }


    // group_figure->parent_name
    if(group_figure->parent_name) {
    if(cJSON_AddStringToObject(item, "parentName", group_figure->parent_name) == NULL) {
    goto fail; //String
    }
    }


    // group_figure->parent_situs
    if(group_figure->parent_situs) {
    if(cJSON_AddStringToObject(item, "parentSitus", group_figure->parent_situs) == NULL) {
    goto fail; //String
    }
    }


    // group_figure->year
    if (!group_figure->year) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "year", *group_figure->year) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

group_figure_t *group_figure_parseFromJSON(cJSON *group_figureJSON){

    group_figure_t *group_figure_local_var = NULL;

    char *bilanzsumme_local_str = NULL;

    // define the local variable for group_figure->exemption_claimed
    int *exemption_claimed_local_var = NULL;

    // define the local variable for group_figure->mitarbeiter
    long *mitarbeiter_local_var = NULL;

    char *netto_umsatz_local_str = NULL;

    char *parent_name_local_str = NULL;

    char *parent_situs_local_str = NULL;

    // define the local variable for group_figure->year
    int *year_local_var = NULL;

    // group_figure->bilanzsumme
    cJSON *bilanzsumme = cJSON_GetObjectItemCaseSensitive(group_figureJSON, "bilanzsumme");
    if (cJSON_IsNull(bilanzsumme)) {
        bilanzsumme = NULL;
    }
    if (bilanzsumme) { 
    if(!cJSON_IsString(bilanzsumme) && !cJSON_IsNull(bilanzsumme))
    {
    goto end; //String
    }
    }

    // group_figure->exemption_claimed
    cJSON *exemption_claimed = cJSON_GetObjectItemCaseSensitive(group_figureJSON, "exemptionClaimed");
    if (cJSON_IsNull(exemption_claimed)) {
        exemption_claimed = NULL;
    }
    if (exemption_claimed) { 
    if(!cJSON_IsBool(exemption_claimed))
    {
    goto end; //Bool
    }
    exemption_claimed_local_var = malloc(sizeof(int));
    if(!exemption_claimed_local_var)
    {
        goto end;
    }
    *exemption_claimed_local_var = exemption_claimed->valueint;
    }

    // group_figure->mitarbeiter
    cJSON *mitarbeiter = cJSON_GetObjectItemCaseSensitive(group_figureJSON, "mitarbeiter");
    if (cJSON_IsNull(mitarbeiter)) {
        mitarbeiter = NULL;
    }
    if (mitarbeiter) { 
    if(!cJSON_IsNumber(mitarbeiter))
    {
    goto end; //Numeric
    }
    mitarbeiter_local_var = malloc(sizeof(long));
    if(!mitarbeiter_local_var)
    {
        goto end;
    }
    *mitarbeiter_local_var = mitarbeiter->valuedouble;
    }

    // group_figure->netto_umsatz
    cJSON *netto_umsatz = cJSON_GetObjectItemCaseSensitive(group_figureJSON, "nettoUmsatz");
    if (cJSON_IsNull(netto_umsatz)) {
        netto_umsatz = NULL;
    }
    if (netto_umsatz) { 
    if(!cJSON_IsString(netto_umsatz) && !cJSON_IsNull(netto_umsatz))
    {
    goto end; //String
    }
    }

    // group_figure->parent_name
    cJSON *parent_name = cJSON_GetObjectItemCaseSensitive(group_figureJSON, "parentName");
    if (cJSON_IsNull(parent_name)) {
        parent_name = NULL;
    }
    if (parent_name) { 
    if(!cJSON_IsString(parent_name) && !cJSON_IsNull(parent_name))
    {
    goto end; //String
    }
    }

    // group_figure->parent_situs
    cJSON *parent_situs = cJSON_GetObjectItemCaseSensitive(group_figureJSON, "parentSitus");
    if (cJSON_IsNull(parent_situs)) {
        parent_situs = NULL;
    }
    if (parent_situs) { 
    if(!cJSON_IsString(parent_situs) && !cJSON_IsNull(parent_situs))
    {
    goto end; //String
    }
    }

    // group_figure->year
    cJSON *year = cJSON_GetObjectItemCaseSensitive(group_figureJSON, "year");
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


    if (bilanzsumme && !cJSON_IsNull(bilanzsumme)) bilanzsumme_local_str = strdup(bilanzsumme->valuestring);
    if (netto_umsatz && !cJSON_IsNull(netto_umsatz)) netto_umsatz_local_str = strdup(netto_umsatz->valuestring);
    if (parent_name && !cJSON_IsNull(parent_name)) parent_name_local_str = strdup(parent_name->valuestring);
    if (parent_situs && !cJSON_IsNull(parent_situs)) parent_situs_local_str = strdup(parent_situs->valuestring);

    group_figure_local_var = group_figure_create_internal (
        bilanzsumme_local_str,
        exemption_claimed_local_var,
        mitarbeiter_local_var,
        netto_umsatz_local_str,
        parent_name_local_str,
        parent_situs_local_str,
        year_local_var
        );

    if (!group_figure_local_var) {
        goto end;
    }

    return group_figure_local_var;
end:
    if (bilanzsumme_local_str) {
        free(bilanzsumme_local_str);
        bilanzsumme_local_str = NULL;
    }
    if (exemption_claimed_local_var) {
        free(exemption_claimed_local_var);
        exemption_claimed_local_var = NULL;
    }
    if (mitarbeiter_local_var) {
        free(mitarbeiter_local_var);
        mitarbeiter_local_var = NULL;
    }
    if (netto_umsatz_local_str) {
        free(netto_umsatz_local_str);
        netto_umsatz_local_str = NULL;
    }
    if (parent_name_local_str) {
        free(parent_name_local_str);
        parent_name_local_str = NULL;
    }
    if (parent_situs_local_str) {
        free(parent_situs_local_str);
        parent_situs_local_str = NULL;
    }
    if (year_local_var) {
        free(year_local_var);
        year_local_var = NULL;
    }
    return NULL;

}
