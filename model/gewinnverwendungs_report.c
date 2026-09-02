#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gewinnverwendungs_report.h"



static gewinnverwendungs_report_t *gewinnverwendungs_report_create_internal(
    char *bilanzgewinn,
    char *gesetzliche_ruecklage_bestand,
    char *gesetzliche_ruecklage_cap,
    char *gesetzliche_ruecklage_nach,
    char *gesetzliche_ruecklage_soll,
    char *gezeichnetes_kapital,
    char *jahresueberschuss,
    int *year,
    list_t *zeilen
    ) {
    gewinnverwendungs_report_t *gewinnverwendungs_report_local_var = malloc(sizeof(gewinnverwendungs_report_t));
    if (!gewinnverwendungs_report_local_var) {
        return NULL;
    }
    memset(gewinnverwendungs_report_local_var, 0, sizeof(gewinnverwendungs_report_t));
    gewinnverwendungs_report_local_var->_library_owned = 1;
    gewinnverwendungs_report_local_var->bilanzgewinn = bilanzgewinn;
    gewinnverwendungs_report_local_var->gesetzliche_ruecklage_bestand = gesetzliche_ruecklage_bestand;
    gewinnverwendungs_report_local_var->gesetzliche_ruecklage_cap = gesetzliche_ruecklage_cap;
    gewinnverwendungs_report_local_var->gesetzliche_ruecklage_nach = gesetzliche_ruecklage_nach;
    gewinnverwendungs_report_local_var->gesetzliche_ruecklage_soll = gesetzliche_ruecklage_soll;
    gewinnverwendungs_report_local_var->gezeichnetes_kapital = gezeichnetes_kapital;
    gewinnverwendungs_report_local_var->jahresueberschuss = jahresueberschuss;
    gewinnverwendungs_report_local_var->year = year;
    gewinnverwendungs_report_local_var->zeilen = zeilen;
    return gewinnverwendungs_report_local_var;
}

__attribute__((deprecated)) gewinnverwendungs_report_t *gewinnverwendungs_report_create(
    char *bilanzgewinn,
    char *gesetzliche_ruecklage_bestand,
    char *gesetzliche_ruecklage_cap,
    char *gesetzliche_ruecklage_nach,
    char *gesetzliche_ruecklage_soll,
    char *gezeichnetes_kapital,
    char *jahresueberschuss,
    int *year,
    list_t *zeilen
    ) {
    int *year_copy = NULL;
    if (year) {
        year_copy = malloc(sizeof(int));
        if (year_copy) *year_copy = *year;
    }
    gewinnverwendungs_report_t *result = gewinnverwendungs_report_create_internal (
        bilanzgewinn,
        gesetzliche_ruecklage_bestand,
        gesetzliche_ruecklage_cap,
        gesetzliche_ruecklage_nach,
        gesetzliche_ruecklage_soll,
        gezeichnetes_kapital,
        jahresueberschuss,
        year_copy,
        zeilen
        );
    if (!result) {
        free(year_copy);
    }
    return result;
}

void gewinnverwendungs_report_free(gewinnverwendungs_report_t *gewinnverwendungs_report) {
    if(NULL == gewinnverwendungs_report){
        return ;
    }
    if(gewinnverwendungs_report->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gewinnverwendungs_report_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gewinnverwendungs_report->bilanzgewinn) {
        free(gewinnverwendungs_report->bilanzgewinn);
        gewinnverwendungs_report->bilanzgewinn = NULL;
    }
    if (gewinnverwendungs_report->gesetzliche_ruecklage_bestand) {
        free(gewinnverwendungs_report->gesetzliche_ruecklage_bestand);
        gewinnverwendungs_report->gesetzliche_ruecklage_bestand = NULL;
    }
    if (gewinnverwendungs_report->gesetzliche_ruecklage_cap) {
        free(gewinnverwendungs_report->gesetzliche_ruecklage_cap);
        gewinnverwendungs_report->gesetzliche_ruecklage_cap = NULL;
    }
    if (gewinnverwendungs_report->gesetzliche_ruecklage_nach) {
        free(gewinnverwendungs_report->gesetzliche_ruecklage_nach);
        gewinnverwendungs_report->gesetzliche_ruecklage_nach = NULL;
    }
    if (gewinnverwendungs_report->gesetzliche_ruecklage_soll) {
        free(gewinnverwendungs_report->gesetzliche_ruecklage_soll);
        gewinnverwendungs_report->gesetzliche_ruecklage_soll = NULL;
    }
    if (gewinnverwendungs_report->gezeichnetes_kapital) {
        free(gewinnverwendungs_report->gezeichnetes_kapital);
        gewinnverwendungs_report->gezeichnetes_kapital = NULL;
    }
    if (gewinnverwendungs_report->jahresueberschuss) {
        free(gewinnverwendungs_report->jahresueberschuss);
        gewinnverwendungs_report->jahresueberschuss = NULL;
    }
    if (gewinnverwendungs_report->year) {
        free(gewinnverwendungs_report->year);
        gewinnverwendungs_report->year = NULL;
    }
    if (gewinnverwendungs_report->zeilen) {
        list_ForEach(listEntry, gewinnverwendungs_report->zeilen) {
            gewinnverwendungs_zeile_free(listEntry->data);
        }
        list_freeList(gewinnverwendungs_report->zeilen);
        gewinnverwendungs_report->zeilen = NULL;
    }
    free(gewinnverwendungs_report);
}

cJSON *gewinnverwendungs_report_convertToJSON(gewinnverwendungs_report_t *gewinnverwendungs_report) {
    cJSON *item = cJSON_CreateObject();

    // gewinnverwendungs_report->bilanzgewinn
    if (!gewinnverwendungs_report->bilanzgewinn) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "bilanzgewinn", gewinnverwendungs_report->bilanzgewinn) == NULL) {
    goto fail; //String
    }


    // gewinnverwendungs_report->gesetzliche_ruecklage_bestand
    if (!gewinnverwendungs_report->gesetzliche_ruecklage_bestand) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gesetzliche_ruecklage_bestand", gewinnverwendungs_report->gesetzliche_ruecklage_bestand) == NULL) {
    goto fail; //String
    }


    // gewinnverwendungs_report->gesetzliche_ruecklage_cap
    if (!gewinnverwendungs_report->gesetzliche_ruecklage_cap) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gesetzliche_ruecklage_cap", gewinnverwendungs_report->gesetzliche_ruecklage_cap) == NULL) {
    goto fail; //String
    }


    // gewinnverwendungs_report->gesetzliche_ruecklage_nach
    if (!gewinnverwendungs_report->gesetzliche_ruecklage_nach) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gesetzliche_ruecklage_nach", gewinnverwendungs_report->gesetzliche_ruecklage_nach) == NULL) {
    goto fail; //String
    }


    // gewinnverwendungs_report->gesetzliche_ruecklage_soll
    if (!gewinnverwendungs_report->gesetzliche_ruecklage_soll) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gesetzliche_ruecklage_soll", gewinnverwendungs_report->gesetzliche_ruecklage_soll) == NULL) {
    goto fail; //String
    }


    // gewinnverwendungs_report->gezeichnetes_kapital
    if (!gewinnverwendungs_report->gezeichnetes_kapital) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gezeichnetes_kapital", gewinnverwendungs_report->gezeichnetes_kapital) == NULL) {
    goto fail; //String
    }


    // gewinnverwendungs_report->jahresueberschuss
    if (!gewinnverwendungs_report->jahresueberschuss) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "jahresueberschuss", gewinnverwendungs_report->jahresueberschuss) == NULL) {
    goto fail; //String
    }


    // gewinnverwendungs_report->year
    if (!gewinnverwendungs_report->year) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "year", *gewinnverwendungs_report->year) == NULL) {
    goto fail; //Numeric
    }


    // gewinnverwendungs_report->zeilen
    if (!gewinnverwendungs_report->zeilen) {
        goto fail;
    }
    cJSON *zeilen = cJSON_AddArrayToObject(item, "zeilen");
    if(zeilen == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *zeilenListEntry;
    if (gewinnverwendungs_report->zeilen) {
    list_ForEach(zeilenListEntry, gewinnverwendungs_report->zeilen) {
    cJSON *itemLocal = gewinnverwendungs_zeile_convertToJSON(zeilenListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(zeilen, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gewinnverwendungs_report_t *gewinnverwendungs_report_parseFromJSON(cJSON *gewinnverwendungs_reportJSON){

    gewinnverwendungs_report_t *gewinnverwendungs_report_local_var = NULL;

    char *bilanzgewinn_local_str = NULL;

    char *gesetzliche_ruecklage_bestand_local_str = NULL;

    char *gesetzliche_ruecklage_cap_local_str = NULL;

    char *gesetzliche_ruecklage_nach_local_str = NULL;

    char *gesetzliche_ruecklage_soll_local_str = NULL;

    char *gezeichnetes_kapital_local_str = NULL;

    char *jahresueberschuss_local_str = NULL;

    // define the local variable for gewinnverwendungs_report->year
    int *year_local_var = NULL;

    // define the local list for gewinnverwendungs_report->zeilen
    list_t *zeilenList = NULL;

    // gewinnverwendungs_report->bilanzgewinn
    cJSON *bilanzgewinn = cJSON_GetObjectItemCaseSensitive(gewinnverwendungs_reportJSON, "bilanzgewinn");
    if (cJSON_IsNull(bilanzgewinn)) {
        bilanzgewinn = NULL;
    }
    if (!bilanzgewinn) {
        goto end;
    }

    
    if(!cJSON_IsString(bilanzgewinn))
    {
    goto end; //String
    }

    // gewinnverwendungs_report->gesetzliche_ruecklage_bestand
    cJSON *gesetzliche_ruecklage_bestand = cJSON_GetObjectItemCaseSensitive(gewinnverwendungs_reportJSON, "gesetzliche_ruecklage_bestand");
    if (cJSON_IsNull(gesetzliche_ruecklage_bestand)) {
        gesetzliche_ruecklage_bestand = NULL;
    }
    if (!gesetzliche_ruecklage_bestand) {
        goto end;
    }

    
    if(!cJSON_IsString(gesetzliche_ruecklage_bestand))
    {
    goto end; //String
    }

    // gewinnverwendungs_report->gesetzliche_ruecklage_cap
    cJSON *gesetzliche_ruecklage_cap = cJSON_GetObjectItemCaseSensitive(gewinnverwendungs_reportJSON, "gesetzliche_ruecklage_cap");
    if (cJSON_IsNull(gesetzliche_ruecklage_cap)) {
        gesetzliche_ruecklage_cap = NULL;
    }
    if (!gesetzliche_ruecklage_cap) {
        goto end;
    }

    
    if(!cJSON_IsString(gesetzliche_ruecklage_cap))
    {
    goto end; //String
    }

    // gewinnverwendungs_report->gesetzliche_ruecklage_nach
    cJSON *gesetzliche_ruecklage_nach = cJSON_GetObjectItemCaseSensitive(gewinnverwendungs_reportJSON, "gesetzliche_ruecklage_nach");
    if (cJSON_IsNull(gesetzliche_ruecklage_nach)) {
        gesetzliche_ruecklage_nach = NULL;
    }
    if (!gesetzliche_ruecklage_nach) {
        goto end;
    }

    
    if(!cJSON_IsString(gesetzliche_ruecklage_nach))
    {
    goto end; //String
    }

    // gewinnverwendungs_report->gesetzliche_ruecklage_soll
    cJSON *gesetzliche_ruecklage_soll = cJSON_GetObjectItemCaseSensitive(gewinnverwendungs_reportJSON, "gesetzliche_ruecklage_soll");
    if (cJSON_IsNull(gesetzliche_ruecklage_soll)) {
        gesetzliche_ruecklage_soll = NULL;
    }
    if (!gesetzliche_ruecklage_soll) {
        goto end;
    }

    
    if(!cJSON_IsString(gesetzliche_ruecklage_soll))
    {
    goto end; //String
    }

    // gewinnverwendungs_report->gezeichnetes_kapital
    cJSON *gezeichnetes_kapital = cJSON_GetObjectItemCaseSensitive(gewinnverwendungs_reportJSON, "gezeichnetes_kapital");
    if (cJSON_IsNull(gezeichnetes_kapital)) {
        gezeichnetes_kapital = NULL;
    }
    if (!gezeichnetes_kapital) {
        goto end;
    }

    
    if(!cJSON_IsString(gezeichnetes_kapital))
    {
    goto end; //String
    }

    // gewinnverwendungs_report->jahresueberschuss
    cJSON *jahresueberschuss = cJSON_GetObjectItemCaseSensitive(gewinnverwendungs_reportJSON, "jahresueberschuss");
    if (cJSON_IsNull(jahresueberschuss)) {
        jahresueberschuss = NULL;
    }
    if (!jahresueberschuss) {
        goto end;
    }

    
    if(!cJSON_IsString(jahresueberschuss))
    {
    goto end; //String
    }

    // gewinnverwendungs_report->year
    cJSON *year = cJSON_GetObjectItemCaseSensitive(gewinnverwendungs_reportJSON, "year");
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

    // gewinnverwendungs_report->zeilen
    cJSON *zeilen = cJSON_GetObjectItemCaseSensitive(gewinnverwendungs_reportJSON, "zeilen");
    if (cJSON_IsNull(zeilen)) {
        zeilen = NULL;
    }
    if (!zeilen) {
        goto end;
    }

    
    cJSON *zeilen_local_nonprimitive = NULL;
    if(!cJSON_IsArray(zeilen)){
        goto end; //nonprimitive container
    }

    zeilenList = list_createList();

    cJSON_ArrayForEach(zeilen_local_nonprimitive,zeilen )
    {
        if(!cJSON_IsObject(zeilen_local_nonprimitive)){
            goto end;
        }
        gewinnverwendungs_zeile_t *zeilenItem = gewinnverwendungs_zeile_parseFromJSON(zeilen_local_nonprimitive);

        list_addElement(zeilenList, zeilenItem);
    }


    if (bilanzgewinn && !cJSON_IsNull(bilanzgewinn)) bilanzgewinn_local_str = strdup(bilanzgewinn->valuestring);
    if (gesetzliche_ruecklage_bestand && !cJSON_IsNull(gesetzliche_ruecklage_bestand)) gesetzliche_ruecklage_bestand_local_str = strdup(gesetzliche_ruecklage_bestand->valuestring);
    if (gesetzliche_ruecklage_cap && !cJSON_IsNull(gesetzliche_ruecklage_cap)) gesetzliche_ruecklage_cap_local_str = strdup(gesetzliche_ruecklage_cap->valuestring);
    if (gesetzliche_ruecklage_nach && !cJSON_IsNull(gesetzliche_ruecklage_nach)) gesetzliche_ruecklage_nach_local_str = strdup(gesetzliche_ruecklage_nach->valuestring);
    if (gesetzliche_ruecklage_soll && !cJSON_IsNull(gesetzliche_ruecklage_soll)) gesetzliche_ruecklage_soll_local_str = strdup(gesetzliche_ruecklage_soll->valuestring);
    if (gezeichnetes_kapital && !cJSON_IsNull(gezeichnetes_kapital)) gezeichnetes_kapital_local_str = strdup(gezeichnetes_kapital->valuestring);
    if (jahresueberschuss && !cJSON_IsNull(jahresueberschuss)) jahresueberschuss_local_str = strdup(jahresueberschuss->valuestring);

    gewinnverwendungs_report_local_var = gewinnverwendungs_report_create_internal (
        bilanzgewinn_local_str,
        gesetzliche_ruecklage_bestand_local_str,
        gesetzliche_ruecklage_cap_local_str,
        gesetzliche_ruecklage_nach_local_str,
        gesetzliche_ruecklage_soll_local_str,
        gezeichnetes_kapital_local_str,
        jahresueberschuss_local_str,
        year_local_var,
        zeilenList
        );

    if (!gewinnverwendungs_report_local_var) {
        goto end;
    }

    return gewinnverwendungs_report_local_var;
end:
    if (bilanzgewinn_local_str) {
        free(bilanzgewinn_local_str);
        bilanzgewinn_local_str = NULL;
    }
    if (gesetzliche_ruecklage_bestand_local_str) {
        free(gesetzliche_ruecklage_bestand_local_str);
        gesetzliche_ruecklage_bestand_local_str = NULL;
    }
    if (gesetzliche_ruecklage_cap_local_str) {
        free(gesetzliche_ruecklage_cap_local_str);
        gesetzliche_ruecklage_cap_local_str = NULL;
    }
    if (gesetzliche_ruecklage_nach_local_str) {
        free(gesetzliche_ruecklage_nach_local_str);
        gesetzliche_ruecklage_nach_local_str = NULL;
    }
    if (gesetzliche_ruecklage_soll_local_str) {
        free(gesetzliche_ruecklage_soll_local_str);
        gesetzliche_ruecklage_soll_local_str = NULL;
    }
    if (gezeichnetes_kapital_local_str) {
        free(gezeichnetes_kapital_local_str);
        gezeichnetes_kapital_local_str = NULL;
    }
    if (jahresueberschuss_local_str) {
        free(jahresueberschuss_local_str);
        jahresueberschuss_local_str = NULL;
    }
    if (year_local_var) {
        free(year_local_var);
        year_local_var = NULL;
    }
    if (zeilenList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, zeilenList) {
            gewinnverwendungs_zeile_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(zeilenList);
        zeilenList = NULL;
    }
    return NULL;

}
