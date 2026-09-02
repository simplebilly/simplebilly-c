#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "konzern_status.h"



static konzern_status_t *konzern_status_create_internal(
    int *groessenbefreit,
    int *kapitalmarktorientiert,
    int *konzernabschlusspflicht,
    int *missing_group_figures,
    int *mutterunternehmen,
    char *parent_name,
    char *parent_situs,
    list_t *participations,
    konzern_thresholds_t *thresholds,
    int *year,
    int *zwischenholding_befreit,
    char *zwischenholding_hinweis
    ) {
    konzern_status_t *konzern_status_local_var = malloc(sizeof(konzern_status_t));
    if (!konzern_status_local_var) {
        return NULL;
    }
    memset(konzern_status_local_var, 0, sizeof(konzern_status_t));
    konzern_status_local_var->_library_owned = 1;
    konzern_status_local_var->groessenbefreit = groessenbefreit;
    konzern_status_local_var->kapitalmarktorientiert = kapitalmarktorientiert;
    konzern_status_local_var->konzernabschlusspflicht = konzernabschlusspflicht;
    konzern_status_local_var->missing_group_figures = missing_group_figures;
    konzern_status_local_var->mutterunternehmen = mutterunternehmen;
    konzern_status_local_var->parent_name = parent_name;
    konzern_status_local_var->parent_situs = parent_situs;
    konzern_status_local_var->participations = participations;
    konzern_status_local_var->thresholds = thresholds;
    konzern_status_local_var->year = year;
    konzern_status_local_var->zwischenholding_befreit = zwischenholding_befreit;
    konzern_status_local_var->zwischenholding_hinweis = zwischenholding_hinweis;
    return konzern_status_local_var;
}

__attribute__((deprecated)) konzern_status_t *konzern_status_create(
    int *groessenbefreit,
    int *kapitalmarktorientiert,
    int *konzernabschlusspflicht,
    int *missing_group_figures,
    int *mutterunternehmen,
    char *parent_name,
    char *parent_situs,
    list_t *participations,
    konzern_thresholds_t *thresholds,
    int *year,
    int *zwischenholding_befreit,
    char *zwischenholding_hinweis
    ) {
    int *groessenbefreit_copy = NULL;
    if (groessenbefreit) {
        groessenbefreit_copy = malloc(sizeof(int));
        if (groessenbefreit_copy) *groessenbefreit_copy = *groessenbefreit;
    }
    int *kapitalmarktorientiert_copy = NULL;
    if (kapitalmarktorientiert) {
        kapitalmarktorientiert_copy = malloc(sizeof(int));
        if (kapitalmarktorientiert_copy) *kapitalmarktorientiert_copy = *kapitalmarktorientiert;
    }
    int *konzernabschlusspflicht_copy = NULL;
    if (konzernabschlusspflicht) {
        konzernabschlusspflicht_copy = malloc(sizeof(int));
        if (konzernabschlusspflicht_copy) *konzernabschlusspflicht_copy = *konzernabschlusspflicht;
    }
    int *missing_group_figures_copy = NULL;
    if (missing_group_figures) {
        missing_group_figures_copy = malloc(sizeof(int));
        if (missing_group_figures_copy) *missing_group_figures_copy = *missing_group_figures;
    }
    int *mutterunternehmen_copy = NULL;
    if (mutterunternehmen) {
        mutterunternehmen_copy = malloc(sizeof(int));
        if (mutterunternehmen_copy) *mutterunternehmen_copy = *mutterunternehmen;
    }
    int *year_copy = NULL;
    if (year) {
        year_copy = malloc(sizeof(int));
        if (year_copy) *year_copy = *year;
    }
    int *zwischenholding_befreit_copy = NULL;
    if (zwischenholding_befreit) {
        zwischenholding_befreit_copy = malloc(sizeof(int));
        if (zwischenholding_befreit_copy) *zwischenholding_befreit_copy = *zwischenholding_befreit;
    }
    konzern_status_t *result = konzern_status_create_internal (
        groessenbefreit_copy,
        kapitalmarktorientiert_copy,
        konzernabschlusspflicht_copy,
        missing_group_figures_copy,
        mutterunternehmen_copy,
        parent_name,
        parent_situs,
        participations,
        thresholds,
        year_copy,
        zwischenholding_befreit_copy,
        zwischenholding_hinweis
        );
    if (!result) {
        free(groessenbefreit_copy);
        free(kapitalmarktorientiert_copy);
        free(konzernabschlusspflicht_copy);
        free(missing_group_figures_copy);
        free(mutterunternehmen_copy);
        free(year_copy);
        free(zwischenholding_befreit_copy);
    }
    return result;
}

void konzern_status_free(konzern_status_t *konzern_status) {
    if(NULL == konzern_status){
        return ;
    }
    if(konzern_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "konzern_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (konzern_status->groessenbefreit) {
        free(konzern_status->groessenbefreit);
        konzern_status->groessenbefreit = NULL;
    }
    if (konzern_status->kapitalmarktorientiert) {
        free(konzern_status->kapitalmarktorientiert);
        konzern_status->kapitalmarktorientiert = NULL;
    }
    if (konzern_status->konzernabschlusspflicht) {
        free(konzern_status->konzernabschlusspflicht);
        konzern_status->konzernabschlusspflicht = NULL;
    }
    if (konzern_status->missing_group_figures) {
        free(konzern_status->missing_group_figures);
        konzern_status->missing_group_figures = NULL;
    }
    if (konzern_status->mutterunternehmen) {
        free(konzern_status->mutterunternehmen);
        konzern_status->mutterunternehmen = NULL;
    }
    if (konzern_status->parent_name) {
        free(konzern_status->parent_name);
        konzern_status->parent_name = NULL;
    }
    if (konzern_status->parent_situs) {
        free(konzern_status->parent_situs);
        konzern_status->parent_situs = NULL;
    }
    if (konzern_status->participations) {
        list_ForEach(listEntry, konzern_status->participations) {
            konzern_beteiligung_free(listEntry->data);
        }
        list_freeList(konzern_status->participations);
        konzern_status->participations = NULL;
    }
    if (konzern_status->thresholds) {
        konzern_thresholds_free(konzern_status->thresholds);
        konzern_status->thresholds = NULL;
    }
    if (konzern_status->year) {
        free(konzern_status->year);
        konzern_status->year = NULL;
    }
    if (konzern_status->zwischenholding_befreit) {
        free(konzern_status->zwischenholding_befreit);
        konzern_status->zwischenholding_befreit = NULL;
    }
    if (konzern_status->zwischenholding_hinweis) {
        free(konzern_status->zwischenholding_hinweis);
        konzern_status->zwischenholding_hinweis = NULL;
    }
    free(konzern_status);
}

cJSON *konzern_status_convertToJSON(konzern_status_t *konzern_status) {
    cJSON *item = cJSON_CreateObject();

    // konzern_status->groessenbefreit
    if (!konzern_status->groessenbefreit) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "groessenbefreit", *konzern_status->groessenbefreit) == NULL) {
    goto fail; //Bool
    }


    // konzern_status->kapitalmarktorientiert
    if (!konzern_status->kapitalmarktorientiert) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "kapitalmarktorientiert", *konzern_status->kapitalmarktorientiert) == NULL) {
    goto fail; //Bool
    }


    // konzern_status->konzernabschlusspflicht
    if (!konzern_status->konzernabschlusspflicht) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "konzernabschlusspflicht", *konzern_status->konzernabschlusspflicht) == NULL) {
    goto fail; //Bool
    }


    // konzern_status->missing_group_figures
    if (!konzern_status->missing_group_figures) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "missing_group_figures", *konzern_status->missing_group_figures) == NULL) {
    goto fail; //Bool
    }


    // konzern_status->mutterunternehmen
    if (!konzern_status->mutterunternehmen) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "mutterunternehmen", *konzern_status->mutterunternehmen) == NULL) {
    goto fail; //Bool
    }


    // konzern_status->parent_name
    if(konzern_status->parent_name) {
    if(cJSON_AddStringToObject(item, "parent_name", konzern_status->parent_name) == NULL) {
    goto fail; //String
    }
    }


    // konzern_status->parent_situs
    if(konzern_status->parent_situs) {
    if(cJSON_AddStringToObject(item, "parent_situs", konzern_status->parent_situs) == NULL) {
    goto fail; //String
    }
    }


    // konzern_status->participations
    if (!konzern_status->participations) {
        goto fail;
    }
    cJSON *participations = cJSON_AddArrayToObject(item, "participations");
    if(participations == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *participationsListEntry;
    if (konzern_status->participations) {
    list_ForEach(participationsListEntry, konzern_status->participations) {
    cJSON *itemLocal = konzern_beteiligung_convertToJSON(participationsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(participations, itemLocal);
    }
    }


    // konzern_status->thresholds
    if (!konzern_status->thresholds) {
        goto fail;
    }
    cJSON *thresholds_local_JSON = konzern_thresholds_convertToJSON(konzern_status->thresholds);
    if(thresholds_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "thresholds", thresholds_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // konzern_status->year
    if (!konzern_status->year) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "year", *konzern_status->year) == NULL) {
    goto fail; //Numeric
    }


    // konzern_status->zwischenholding_befreit
    if (!konzern_status->zwischenholding_befreit) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "zwischenholding_befreit", *konzern_status->zwischenholding_befreit) == NULL) {
    goto fail; //Bool
    }


    // konzern_status->zwischenholding_hinweis
    if(konzern_status->zwischenholding_hinweis) {
    if(cJSON_AddStringToObject(item, "zwischenholding_hinweis", konzern_status->zwischenholding_hinweis) == NULL) {
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

konzern_status_t *konzern_status_parseFromJSON(cJSON *konzern_statusJSON){

    konzern_status_t *konzern_status_local_var = NULL;

    // define the local variable for konzern_status->groessenbefreit
    int *groessenbefreit_local_var = NULL;

    // define the local variable for konzern_status->kapitalmarktorientiert
    int *kapitalmarktorientiert_local_var = NULL;

    // define the local variable for konzern_status->konzernabschlusspflicht
    int *konzernabschlusspflicht_local_var = NULL;

    // define the local variable for konzern_status->missing_group_figures
    int *missing_group_figures_local_var = NULL;

    // define the local variable for konzern_status->mutterunternehmen
    int *mutterunternehmen_local_var = NULL;

    char *parent_name_local_str = NULL;

    char *parent_situs_local_str = NULL;

    // define the local list for konzern_status->participations
    list_t *participationsList = NULL;

    // define the local variable for konzern_status->thresholds
    konzern_thresholds_t *thresholds_local_nonprim = NULL;

    // define the local variable for konzern_status->year
    int *year_local_var = NULL;

    // define the local variable for konzern_status->zwischenholding_befreit
    int *zwischenholding_befreit_local_var = NULL;

    char *zwischenholding_hinweis_local_str = NULL;

    // konzern_status->groessenbefreit
    cJSON *groessenbefreit = cJSON_GetObjectItemCaseSensitive(konzern_statusJSON, "groessenbefreit");
    if (cJSON_IsNull(groessenbefreit)) {
        groessenbefreit = NULL;
    }
    if (!groessenbefreit) {
        goto end;
    }

    
    if(!cJSON_IsBool(groessenbefreit))
    {
    goto end; //Bool
    }
    groessenbefreit_local_var = malloc(sizeof(int));
    if(!groessenbefreit_local_var)
    {
        goto end;
    }
    *groessenbefreit_local_var = groessenbefreit->valueint;

    // konzern_status->kapitalmarktorientiert
    cJSON *kapitalmarktorientiert = cJSON_GetObjectItemCaseSensitive(konzern_statusJSON, "kapitalmarktorientiert");
    if (cJSON_IsNull(kapitalmarktorientiert)) {
        kapitalmarktorientiert = NULL;
    }
    if (!kapitalmarktorientiert) {
        goto end;
    }

    
    if(!cJSON_IsBool(kapitalmarktorientiert))
    {
    goto end; //Bool
    }
    kapitalmarktorientiert_local_var = malloc(sizeof(int));
    if(!kapitalmarktorientiert_local_var)
    {
        goto end;
    }
    *kapitalmarktorientiert_local_var = kapitalmarktorientiert->valueint;

    // konzern_status->konzernabschlusspflicht
    cJSON *konzernabschlusspflicht = cJSON_GetObjectItemCaseSensitive(konzern_statusJSON, "konzernabschlusspflicht");
    if (cJSON_IsNull(konzernabschlusspflicht)) {
        konzernabschlusspflicht = NULL;
    }
    if (!konzernabschlusspflicht) {
        goto end;
    }

    
    if(!cJSON_IsBool(konzernabschlusspflicht))
    {
    goto end; //Bool
    }
    konzernabschlusspflicht_local_var = malloc(sizeof(int));
    if(!konzernabschlusspflicht_local_var)
    {
        goto end;
    }
    *konzernabschlusspflicht_local_var = konzernabschlusspflicht->valueint;

    // konzern_status->missing_group_figures
    cJSON *missing_group_figures = cJSON_GetObjectItemCaseSensitive(konzern_statusJSON, "missing_group_figures");
    if (cJSON_IsNull(missing_group_figures)) {
        missing_group_figures = NULL;
    }
    if (!missing_group_figures) {
        goto end;
    }

    
    if(!cJSON_IsBool(missing_group_figures))
    {
    goto end; //Bool
    }
    missing_group_figures_local_var = malloc(sizeof(int));
    if(!missing_group_figures_local_var)
    {
        goto end;
    }
    *missing_group_figures_local_var = missing_group_figures->valueint;

    // konzern_status->mutterunternehmen
    cJSON *mutterunternehmen = cJSON_GetObjectItemCaseSensitive(konzern_statusJSON, "mutterunternehmen");
    if (cJSON_IsNull(mutterunternehmen)) {
        mutterunternehmen = NULL;
    }
    if (!mutterunternehmen) {
        goto end;
    }

    
    if(!cJSON_IsBool(mutterunternehmen))
    {
    goto end; //Bool
    }
    mutterunternehmen_local_var = malloc(sizeof(int));
    if(!mutterunternehmen_local_var)
    {
        goto end;
    }
    *mutterunternehmen_local_var = mutterunternehmen->valueint;

    // konzern_status->parent_name
    cJSON *parent_name = cJSON_GetObjectItemCaseSensitive(konzern_statusJSON, "parent_name");
    if (cJSON_IsNull(parent_name)) {
        parent_name = NULL;
    }
    if (parent_name) { 
    if(!cJSON_IsString(parent_name) && !cJSON_IsNull(parent_name))
    {
    goto end; //String
    }
    }

    // konzern_status->parent_situs
    cJSON *parent_situs = cJSON_GetObjectItemCaseSensitive(konzern_statusJSON, "parent_situs");
    if (cJSON_IsNull(parent_situs)) {
        parent_situs = NULL;
    }
    if (parent_situs) { 
    if(!cJSON_IsString(parent_situs) && !cJSON_IsNull(parent_situs))
    {
    goto end; //String
    }
    }

    // konzern_status->participations
    cJSON *participations = cJSON_GetObjectItemCaseSensitive(konzern_statusJSON, "participations");
    if (cJSON_IsNull(participations)) {
        participations = NULL;
    }
    if (!participations) {
        goto end;
    }

    
    cJSON *participations_local_nonprimitive = NULL;
    if(!cJSON_IsArray(participations)){
        goto end; //nonprimitive container
    }

    participationsList = list_createList();

    cJSON_ArrayForEach(participations_local_nonprimitive,participations )
    {
        if(!cJSON_IsObject(participations_local_nonprimitive)){
            goto end;
        }
        konzern_beteiligung_t *participationsItem = konzern_beteiligung_parseFromJSON(participations_local_nonprimitive);

        list_addElement(participationsList, participationsItem);
    }

    // konzern_status->thresholds
    cJSON *thresholds = cJSON_GetObjectItemCaseSensitive(konzern_statusJSON, "thresholds");
    if (cJSON_IsNull(thresholds)) {
        thresholds = NULL;
    }
    if (!thresholds) {
        goto end;
    }

    
    thresholds_local_nonprim = konzern_thresholds_parseFromJSON(thresholds); //nonprimitive

    // konzern_status->year
    cJSON *year = cJSON_GetObjectItemCaseSensitive(konzern_statusJSON, "year");
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

    // konzern_status->zwischenholding_befreit
    cJSON *zwischenholding_befreit = cJSON_GetObjectItemCaseSensitive(konzern_statusJSON, "zwischenholding_befreit");
    if (cJSON_IsNull(zwischenholding_befreit)) {
        zwischenholding_befreit = NULL;
    }
    if (!zwischenholding_befreit) {
        goto end;
    }

    
    if(!cJSON_IsBool(zwischenholding_befreit))
    {
    goto end; //Bool
    }
    zwischenholding_befreit_local_var = malloc(sizeof(int));
    if(!zwischenholding_befreit_local_var)
    {
        goto end;
    }
    *zwischenholding_befreit_local_var = zwischenholding_befreit->valueint;

    // konzern_status->zwischenholding_hinweis
    cJSON *zwischenholding_hinweis = cJSON_GetObjectItemCaseSensitive(konzern_statusJSON, "zwischenholding_hinweis");
    if (cJSON_IsNull(zwischenholding_hinweis)) {
        zwischenholding_hinweis = NULL;
    }
    if (zwischenholding_hinweis) { 
    if(!cJSON_IsString(zwischenholding_hinweis) && !cJSON_IsNull(zwischenholding_hinweis))
    {
    goto end; //String
    }
    }


    if (parent_name && !cJSON_IsNull(parent_name)) parent_name_local_str = strdup(parent_name->valuestring);
    if (parent_situs && !cJSON_IsNull(parent_situs)) parent_situs_local_str = strdup(parent_situs->valuestring);
    if (zwischenholding_hinweis && !cJSON_IsNull(zwischenholding_hinweis)) zwischenholding_hinweis_local_str = strdup(zwischenholding_hinweis->valuestring);

    konzern_status_local_var = konzern_status_create_internal (
        groessenbefreit_local_var,
        kapitalmarktorientiert_local_var,
        konzernabschlusspflicht_local_var,
        missing_group_figures_local_var,
        mutterunternehmen_local_var,
        parent_name_local_str,
        parent_situs_local_str,
        participationsList,
        thresholds_local_nonprim,
        year_local_var,
        zwischenholding_befreit_local_var,
        zwischenholding_hinweis_local_str
        );

    if (!konzern_status_local_var) {
        goto end;
    }

    return konzern_status_local_var;
end:
    if (groessenbefreit_local_var) {
        free(groessenbefreit_local_var);
        groessenbefreit_local_var = NULL;
    }
    if (kapitalmarktorientiert_local_var) {
        free(kapitalmarktorientiert_local_var);
        kapitalmarktorientiert_local_var = NULL;
    }
    if (konzernabschlusspflicht_local_var) {
        free(konzernabschlusspflicht_local_var);
        konzernabschlusspflicht_local_var = NULL;
    }
    if (missing_group_figures_local_var) {
        free(missing_group_figures_local_var);
        missing_group_figures_local_var = NULL;
    }
    if (mutterunternehmen_local_var) {
        free(mutterunternehmen_local_var);
        mutterunternehmen_local_var = NULL;
    }
    if (parent_name_local_str) {
        free(parent_name_local_str);
        parent_name_local_str = NULL;
    }
    if (parent_situs_local_str) {
        free(parent_situs_local_str);
        parent_situs_local_str = NULL;
    }
    if (participationsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, participationsList) {
            konzern_beteiligung_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(participationsList);
        participationsList = NULL;
    }
    if (thresholds_local_nonprim) {
        konzern_thresholds_free(thresholds_local_nonprim);
        thresholds_local_nonprim = NULL;
    }
    if (year_local_var) {
        free(year_local_var);
        year_local_var = NULL;
    }
    if (zwischenholding_befreit_local_var) {
        free(zwischenholding_befreit_local_var);
        zwischenholding_befreit_local_var = NULL;
    }
    if (zwischenholding_hinweis_local_str) {
        free(zwischenholding_hinweis_local_str);
        zwischenholding_hinweis_local_str = NULL;
    }
    return NULL;

}
