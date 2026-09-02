#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "group_figure_create.h"



static group_figure_create_t *group_figure_create_create_internal(
    char *bilanzsumme,
    int *exemption_claimed,
    long *mitarbeiter,
    char *netto_umsatz,
    char *parent_name,
    char *parent_situs
    ) {
    group_figure_create_t *group_figure_create_local_var = malloc(sizeof(group_figure_create_t));
    if (!group_figure_create_local_var) {
        return NULL;
    }
    memset(group_figure_create_local_var, 0, sizeof(group_figure_create_t));
    group_figure_create_local_var->_library_owned = 1;
    group_figure_create_local_var->bilanzsumme = bilanzsumme;
    group_figure_create_local_var->exemption_claimed = exemption_claimed;
    group_figure_create_local_var->mitarbeiter = mitarbeiter;
    group_figure_create_local_var->netto_umsatz = netto_umsatz;
    group_figure_create_local_var->parent_name = parent_name;
    group_figure_create_local_var->parent_situs = parent_situs;
    return group_figure_create_local_var;
}

__attribute__((deprecated)) group_figure_create_t *group_figure_create_create(
    char *bilanzsumme,
    int *exemption_claimed,
    long *mitarbeiter,
    char *netto_umsatz,
    char *parent_name,
    char *parent_situs
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
    group_figure_create_t *result = group_figure_create_create_internal (
        bilanzsumme,
        exemption_claimed_copy,
        mitarbeiter_copy,
        netto_umsatz,
        parent_name,
        parent_situs
        );
    if (!result) {
        free(exemption_claimed_copy);
        free(mitarbeiter_copy);
    }
    return result;
}

void group_figure_create_free(group_figure_create_t *group_figure_create) {
    if(NULL == group_figure_create){
        return ;
    }
    if(group_figure_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "group_figure_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (group_figure_create->bilanzsumme) {
        free(group_figure_create->bilanzsumme);
        group_figure_create->bilanzsumme = NULL;
    }
    if (group_figure_create->exemption_claimed) {
        free(group_figure_create->exemption_claimed);
        group_figure_create->exemption_claimed = NULL;
    }
    if (group_figure_create->mitarbeiter) {
        free(group_figure_create->mitarbeiter);
        group_figure_create->mitarbeiter = NULL;
    }
    if (group_figure_create->netto_umsatz) {
        free(group_figure_create->netto_umsatz);
        group_figure_create->netto_umsatz = NULL;
    }
    if (group_figure_create->parent_name) {
        free(group_figure_create->parent_name);
        group_figure_create->parent_name = NULL;
    }
    if (group_figure_create->parent_situs) {
        free(group_figure_create->parent_situs);
        group_figure_create->parent_situs = NULL;
    }
    free(group_figure_create);
}

cJSON *group_figure_create_convertToJSON(group_figure_create_t *group_figure_create) {
    cJSON *item = cJSON_CreateObject();

    // group_figure_create->bilanzsumme
    if(group_figure_create->bilanzsumme) {
    if(cJSON_AddStringToObject(item, "bilanzsumme", group_figure_create->bilanzsumme) == NULL) {
    goto fail; //String
    }
    }


    // group_figure_create->exemption_claimed
    if(group_figure_create->exemption_claimed) {
    if(cJSON_AddBoolToObject(item, "exemptionClaimed", *group_figure_create->exemption_claimed) == NULL) {
    goto fail; //Bool
    }
    }


    // group_figure_create->mitarbeiter
    if(group_figure_create->mitarbeiter) {
    if(cJSON_AddNumberToObject(item, "mitarbeiter", *group_figure_create->mitarbeiter) == NULL) {
    goto fail; //Numeric
    }
    }


    // group_figure_create->netto_umsatz
    if(group_figure_create->netto_umsatz) {
    if(cJSON_AddStringToObject(item, "nettoUmsatz", group_figure_create->netto_umsatz) == NULL) {
    goto fail; //String
    }
    }


    // group_figure_create->parent_name
    if(group_figure_create->parent_name) {
    if(cJSON_AddStringToObject(item, "parentName", group_figure_create->parent_name) == NULL) {
    goto fail; //String
    }
    }


    // group_figure_create->parent_situs
    if(group_figure_create->parent_situs) {
    if(cJSON_AddStringToObject(item, "parentSitus", group_figure_create->parent_situs) == NULL) {
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

group_figure_create_t *group_figure_create_parseFromJSON(cJSON *group_figure_createJSON){

    group_figure_create_t *group_figure_create_local_var = NULL;

    char *bilanzsumme_local_str = NULL;

    // define the local variable for group_figure_create->exemption_claimed
    int *exemption_claimed_local_var = NULL;

    // define the local variable for group_figure_create->mitarbeiter
    long *mitarbeiter_local_var = NULL;

    char *netto_umsatz_local_str = NULL;

    char *parent_name_local_str = NULL;

    char *parent_situs_local_str = NULL;

    // group_figure_create->bilanzsumme
    cJSON *bilanzsumme = cJSON_GetObjectItemCaseSensitive(group_figure_createJSON, "bilanzsumme");
    if (cJSON_IsNull(bilanzsumme)) {
        bilanzsumme = NULL;
    }
    if (bilanzsumme) { 
    if(!cJSON_IsString(bilanzsumme) && !cJSON_IsNull(bilanzsumme))
    {
    goto end; //String
    }
    }

    // group_figure_create->exemption_claimed
    cJSON *exemption_claimed = cJSON_GetObjectItemCaseSensitive(group_figure_createJSON, "exemptionClaimed");
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

    // group_figure_create->mitarbeiter
    cJSON *mitarbeiter = cJSON_GetObjectItemCaseSensitive(group_figure_createJSON, "mitarbeiter");
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

    // group_figure_create->netto_umsatz
    cJSON *netto_umsatz = cJSON_GetObjectItemCaseSensitive(group_figure_createJSON, "nettoUmsatz");
    if (cJSON_IsNull(netto_umsatz)) {
        netto_umsatz = NULL;
    }
    if (netto_umsatz) { 
    if(!cJSON_IsString(netto_umsatz) && !cJSON_IsNull(netto_umsatz))
    {
    goto end; //String
    }
    }

    // group_figure_create->parent_name
    cJSON *parent_name = cJSON_GetObjectItemCaseSensitive(group_figure_createJSON, "parentName");
    if (cJSON_IsNull(parent_name)) {
        parent_name = NULL;
    }
    if (parent_name) { 
    if(!cJSON_IsString(parent_name) && !cJSON_IsNull(parent_name))
    {
    goto end; //String
    }
    }

    // group_figure_create->parent_situs
    cJSON *parent_situs = cJSON_GetObjectItemCaseSensitive(group_figure_createJSON, "parentSitus");
    if (cJSON_IsNull(parent_situs)) {
        parent_situs = NULL;
    }
    if (parent_situs) { 
    if(!cJSON_IsString(parent_situs) && !cJSON_IsNull(parent_situs))
    {
    goto end; //String
    }
    }


    if (bilanzsumme && !cJSON_IsNull(bilanzsumme)) bilanzsumme_local_str = strdup(bilanzsumme->valuestring);
    if (netto_umsatz && !cJSON_IsNull(netto_umsatz)) netto_umsatz_local_str = strdup(netto_umsatz->valuestring);
    if (parent_name && !cJSON_IsNull(parent_name)) parent_name_local_str = strdup(parent_name->valuestring);
    if (parent_situs && !cJSON_IsNull(parent_situs)) parent_situs_local_str = strdup(parent_situs->valuestring);

    group_figure_create_local_var = group_figure_create_create_internal (
        bilanzsumme_local_str,
        exemption_claimed_local_var,
        mitarbeiter_local_var,
        netto_umsatz_local_str,
        parent_name_local_str,
        parent_situs_local_str
        );

    if (!group_figure_create_local_var) {
        goto end;
    }

    return group_figure_create_local_var;
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
    return NULL;

}
