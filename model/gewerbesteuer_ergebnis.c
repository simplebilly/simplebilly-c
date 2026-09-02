#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gewerbesteuer_ergebnis.h"



static gewerbesteuer_ergebnis_t *gewerbesteuer_ergebnis_create_internal(
    char *freibetrag,
    char *gesamtbelastung,
    char *gewerbeertrag,
    char *hebesatz,
    int *jahr,
    char *koerperschaftsteuer,
    char *land,
    char *messbetrag,
    char *steuer,
    char *steuer_art
    ) {
    gewerbesteuer_ergebnis_t *gewerbesteuer_ergebnis_local_var = malloc(sizeof(gewerbesteuer_ergebnis_t));
    if (!gewerbesteuer_ergebnis_local_var) {
        return NULL;
    }
    memset(gewerbesteuer_ergebnis_local_var, 0, sizeof(gewerbesteuer_ergebnis_t));
    gewerbesteuer_ergebnis_local_var->_library_owned = 1;
    gewerbesteuer_ergebnis_local_var->freibetrag = freibetrag;
    gewerbesteuer_ergebnis_local_var->gesamtbelastung = gesamtbelastung;
    gewerbesteuer_ergebnis_local_var->gewerbeertrag = gewerbeertrag;
    gewerbesteuer_ergebnis_local_var->hebesatz = hebesatz;
    gewerbesteuer_ergebnis_local_var->jahr = jahr;
    gewerbesteuer_ergebnis_local_var->koerperschaftsteuer = koerperschaftsteuer;
    gewerbesteuer_ergebnis_local_var->land = land;
    gewerbesteuer_ergebnis_local_var->messbetrag = messbetrag;
    gewerbesteuer_ergebnis_local_var->steuer = steuer;
    gewerbesteuer_ergebnis_local_var->steuer_art = steuer_art;
    return gewerbesteuer_ergebnis_local_var;
}

__attribute__((deprecated)) gewerbesteuer_ergebnis_t *gewerbesteuer_ergebnis_create(
    char *freibetrag,
    char *gesamtbelastung,
    char *gewerbeertrag,
    char *hebesatz,
    int *jahr,
    char *koerperschaftsteuer,
    char *land,
    char *messbetrag,
    char *steuer,
    char *steuer_art
    ) {
    int *jahr_copy = NULL;
    if (jahr) {
        jahr_copy = malloc(sizeof(int));
        if (jahr_copy) *jahr_copy = *jahr;
    }
    gewerbesteuer_ergebnis_t *result = gewerbesteuer_ergebnis_create_internal (
        freibetrag,
        gesamtbelastung,
        gewerbeertrag,
        hebesatz,
        jahr_copy,
        koerperschaftsteuer,
        land,
        messbetrag,
        steuer,
        steuer_art
        );
    if (!result) {
        free(jahr_copy);
    }
    return result;
}

void gewerbesteuer_ergebnis_free(gewerbesteuer_ergebnis_t *gewerbesteuer_ergebnis) {
    if(NULL == gewerbesteuer_ergebnis){
        return ;
    }
    if(gewerbesteuer_ergebnis->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gewerbesteuer_ergebnis_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gewerbesteuer_ergebnis->freibetrag) {
        free(gewerbesteuer_ergebnis->freibetrag);
        gewerbesteuer_ergebnis->freibetrag = NULL;
    }
    if (gewerbesteuer_ergebnis->gesamtbelastung) {
        free(gewerbesteuer_ergebnis->gesamtbelastung);
        gewerbesteuer_ergebnis->gesamtbelastung = NULL;
    }
    if (gewerbesteuer_ergebnis->gewerbeertrag) {
        free(gewerbesteuer_ergebnis->gewerbeertrag);
        gewerbesteuer_ergebnis->gewerbeertrag = NULL;
    }
    if (gewerbesteuer_ergebnis->hebesatz) {
        free(gewerbesteuer_ergebnis->hebesatz);
        gewerbesteuer_ergebnis->hebesatz = NULL;
    }
    if (gewerbesteuer_ergebnis->jahr) {
        free(gewerbesteuer_ergebnis->jahr);
        gewerbesteuer_ergebnis->jahr = NULL;
    }
    if (gewerbesteuer_ergebnis->koerperschaftsteuer) {
        free(gewerbesteuer_ergebnis->koerperschaftsteuer);
        gewerbesteuer_ergebnis->koerperschaftsteuer = NULL;
    }
    if (gewerbesteuer_ergebnis->land) {
        free(gewerbesteuer_ergebnis->land);
        gewerbesteuer_ergebnis->land = NULL;
    }
    if (gewerbesteuer_ergebnis->messbetrag) {
        free(gewerbesteuer_ergebnis->messbetrag);
        gewerbesteuer_ergebnis->messbetrag = NULL;
    }
    if (gewerbesteuer_ergebnis->steuer) {
        free(gewerbesteuer_ergebnis->steuer);
        gewerbesteuer_ergebnis->steuer = NULL;
    }
    if (gewerbesteuer_ergebnis->steuer_art) {
        free(gewerbesteuer_ergebnis->steuer_art);
        gewerbesteuer_ergebnis->steuer_art = NULL;
    }
    free(gewerbesteuer_ergebnis);
}

cJSON *gewerbesteuer_ergebnis_convertToJSON(gewerbesteuer_ergebnis_t *gewerbesteuer_ergebnis) {
    cJSON *item = cJSON_CreateObject();

    // gewerbesteuer_ergebnis->freibetrag
    if (!gewerbesteuer_ergebnis->freibetrag) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "freibetrag", gewerbesteuer_ergebnis->freibetrag) == NULL) {
    goto fail; //String
    }


    // gewerbesteuer_ergebnis->gesamtbelastung
    if (!gewerbesteuer_ergebnis->gesamtbelastung) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gesamtbelastung", gewerbesteuer_ergebnis->gesamtbelastung) == NULL) {
    goto fail; //String
    }


    // gewerbesteuer_ergebnis->gewerbeertrag
    if (!gewerbesteuer_ergebnis->gewerbeertrag) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gewerbeertrag", gewerbesteuer_ergebnis->gewerbeertrag) == NULL) {
    goto fail; //String
    }


    // gewerbesteuer_ergebnis->hebesatz
    if (!gewerbesteuer_ergebnis->hebesatz) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "hebesatz", gewerbesteuer_ergebnis->hebesatz) == NULL) {
    goto fail; //String
    }


    // gewerbesteuer_ergebnis->jahr
    if (!gewerbesteuer_ergebnis->jahr) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "jahr", *gewerbesteuer_ergebnis->jahr) == NULL) {
    goto fail; //Numeric
    }


    // gewerbesteuer_ergebnis->koerperschaftsteuer
    if (!gewerbesteuer_ergebnis->koerperschaftsteuer) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "koerperschaftsteuer", gewerbesteuer_ergebnis->koerperschaftsteuer) == NULL) {
    goto fail; //String
    }


    // gewerbesteuer_ergebnis->land
    if (!gewerbesteuer_ergebnis->land) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "land", gewerbesteuer_ergebnis->land) == NULL) {
    goto fail; //String
    }


    // gewerbesteuer_ergebnis->messbetrag
    if (!gewerbesteuer_ergebnis->messbetrag) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "messbetrag", gewerbesteuer_ergebnis->messbetrag) == NULL) {
    goto fail; //String
    }


    // gewerbesteuer_ergebnis->steuer
    if (!gewerbesteuer_ergebnis->steuer) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "steuer", gewerbesteuer_ergebnis->steuer) == NULL) {
    goto fail; //String
    }


    // gewerbesteuer_ergebnis->steuer_art
    if (!gewerbesteuer_ergebnis->steuer_art) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "steuer_art", gewerbesteuer_ergebnis->steuer_art) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gewerbesteuer_ergebnis_t *gewerbesteuer_ergebnis_parseFromJSON(cJSON *gewerbesteuer_ergebnisJSON){

    gewerbesteuer_ergebnis_t *gewerbesteuer_ergebnis_local_var = NULL;

    char *freibetrag_local_str = NULL;

    char *gesamtbelastung_local_str = NULL;

    char *gewerbeertrag_local_str = NULL;

    char *hebesatz_local_str = NULL;

    // define the local variable for gewerbesteuer_ergebnis->jahr
    int *jahr_local_var = NULL;

    char *koerperschaftsteuer_local_str = NULL;

    char *land_local_str = NULL;

    char *messbetrag_local_str = NULL;

    char *steuer_local_str = NULL;

    char *steuer_art_local_str = NULL;

    // gewerbesteuer_ergebnis->freibetrag
    cJSON *freibetrag = cJSON_GetObjectItemCaseSensitive(gewerbesteuer_ergebnisJSON, "freibetrag");
    if (cJSON_IsNull(freibetrag)) {
        freibetrag = NULL;
    }
    if (!freibetrag) {
        goto end;
    }

    
    if(!cJSON_IsString(freibetrag))
    {
    goto end; //String
    }

    // gewerbesteuer_ergebnis->gesamtbelastung
    cJSON *gesamtbelastung = cJSON_GetObjectItemCaseSensitive(gewerbesteuer_ergebnisJSON, "gesamtbelastung");
    if (cJSON_IsNull(gesamtbelastung)) {
        gesamtbelastung = NULL;
    }
    if (!gesamtbelastung) {
        goto end;
    }

    
    if(!cJSON_IsString(gesamtbelastung))
    {
    goto end; //String
    }

    // gewerbesteuer_ergebnis->gewerbeertrag
    cJSON *gewerbeertrag = cJSON_GetObjectItemCaseSensitive(gewerbesteuer_ergebnisJSON, "gewerbeertrag");
    if (cJSON_IsNull(gewerbeertrag)) {
        gewerbeertrag = NULL;
    }
    if (!gewerbeertrag) {
        goto end;
    }

    
    if(!cJSON_IsString(gewerbeertrag))
    {
    goto end; //String
    }

    // gewerbesteuer_ergebnis->hebesatz
    cJSON *hebesatz = cJSON_GetObjectItemCaseSensitive(gewerbesteuer_ergebnisJSON, "hebesatz");
    if (cJSON_IsNull(hebesatz)) {
        hebesatz = NULL;
    }
    if (!hebesatz) {
        goto end;
    }

    
    if(!cJSON_IsString(hebesatz))
    {
    goto end; //String
    }

    // gewerbesteuer_ergebnis->jahr
    cJSON *jahr = cJSON_GetObjectItemCaseSensitive(gewerbesteuer_ergebnisJSON, "jahr");
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

    // gewerbesteuer_ergebnis->koerperschaftsteuer
    cJSON *koerperschaftsteuer = cJSON_GetObjectItemCaseSensitive(gewerbesteuer_ergebnisJSON, "koerperschaftsteuer");
    if (cJSON_IsNull(koerperschaftsteuer)) {
        koerperschaftsteuer = NULL;
    }
    if (!koerperschaftsteuer) {
        goto end;
    }

    
    if(!cJSON_IsString(koerperschaftsteuer))
    {
    goto end; //String
    }

    // gewerbesteuer_ergebnis->land
    cJSON *land = cJSON_GetObjectItemCaseSensitive(gewerbesteuer_ergebnisJSON, "land");
    if (cJSON_IsNull(land)) {
        land = NULL;
    }
    if (!land) {
        goto end;
    }

    
    if(!cJSON_IsString(land))
    {
    goto end; //String
    }

    // gewerbesteuer_ergebnis->messbetrag
    cJSON *messbetrag = cJSON_GetObjectItemCaseSensitive(gewerbesteuer_ergebnisJSON, "messbetrag");
    if (cJSON_IsNull(messbetrag)) {
        messbetrag = NULL;
    }
    if (!messbetrag) {
        goto end;
    }

    
    if(!cJSON_IsString(messbetrag))
    {
    goto end; //String
    }

    // gewerbesteuer_ergebnis->steuer
    cJSON *steuer = cJSON_GetObjectItemCaseSensitive(gewerbesteuer_ergebnisJSON, "steuer");
    if (cJSON_IsNull(steuer)) {
        steuer = NULL;
    }
    if (!steuer) {
        goto end;
    }

    
    if(!cJSON_IsString(steuer))
    {
    goto end; //String
    }

    // gewerbesteuer_ergebnis->steuer_art
    cJSON *steuer_art = cJSON_GetObjectItemCaseSensitive(gewerbesteuer_ergebnisJSON, "steuer_art");
    if (cJSON_IsNull(steuer_art)) {
        steuer_art = NULL;
    }
    if (!steuer_art) {
        goto end;
    }

    
    if(!cJSON_IsString(steuer_art))
    {
    goto end; //String
    }


    if (freibetrag && !cJSON_IsNull(freibetrag)) freibetrag_local_str = strdup(freibetrag->valuestring);
    if (gesamtbelastung && !cJSON_IsNull(gesamtbelastung)) gesamtbelastung_local_str = strdup(gesamtbelastung->valuestring);
    if (gewerbeertrag && !cJSON_IsNull(gewerbeertrag)) gewerbeertrag_local_str = strdup(gewerbeertrag->valuestring);
    if (hebesatz && !cJSON_IsNull(hebesatz)) hebesatz_local_str = strdup(hebesatz->valuestring);
    if (koerperschaftsteuer && !cJSON_IsNull(koerperschaftsteuer)) koerperschaftsteuer_local_str = strdup(koerperschaftsteuer->valuestring);
    if (land && !cJSON_IsNull(land)) land_local_str = strdup(land->valuestring);
    if (messbetrag && !cJSON_IsNull(messbetrag)) messbetrag_local_str = strdup(messbetrag->valuestring);
    if (steuer && !cJSON_IsNull(steuer)) steuer_local_str = strdup(steuer->valuestring);
    if (steuer_art && !cJSON_IsNull(steuer_art)) steuer_art_local_str = strdup(steuer_art->valuestring);

    gewerbesteuer_ergebnis_local_var = gewerbesteuer_ergebnis_create_internal (
        freibetrag_local_str,
        gesamtbelastung_local_str,
        gewerbeertrag_local_str,
        hebesatz_local_str,
        jahr_local_var,
        koerperschaftsteuer_local_str,
        land_local_str,
        messbetrag_local_str,
        steuer_local_str,
        steuer_art_local_str
        );

    if (!gewerbesteuer_ergebnis_local_var) {
        goto end;
    }

    return gewerbesteuer_ergebnis_local_var;
end:
    if (freibetrag_local_str) {
        free(freibetrag_local_str);
        freibetrag_local_str = NULL;
    }
    if (gesamtbelastung_local_str) {
        free(gesamtbelastung_local_str);
        gesamtbelastung_local_str = NULL;
    }
    if (gewerbeertrag_local_str) {
        free(gewerbeertrag_local_str);
        gewerbeertrag_local_str = NULL;
    }
    if (hebesatz_local_str) {
        free(hebesatz_local_str);
        hebesatz_local_str = NULL;
    }
    if (jahr_local_var) {
        free(jahr_local_var);
        jahr_local_var = NULL;
    }
    if (koerperschaftsteuer_local_str) {
        free(koerperschaftsteuer_local_str);
        koerperschaftsteuer_local_str = NULL;
    }
    if (land_local_str) {
        free(land_local_str);
        land_local_str = NULL;
    }
    if (messbetrag_local_str) {
        free(messbetrag_local_str);
        messbetrag_local_str = NULL;
    }
    if (steuer_local_str) {
        free(steuer_local_str);
        steuer_local_str = NULL;
    }
    if (steuer_art_local_str) {
        free(steuer_art_local_str);
        steuer_art_local_str = NULL;
    }
    return NULL;

}
