#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "kst_ergebnis.h"



static kst_ergebnis_t *kst_ergebnis_create_internal(
    char *gesamt,
    char *gesamtbelastung,
    char *gewerbesteuer,
    char *gewinn,
    int *ist_kapitalgesellschaft,
    int *jahr,
    char *koerperschaftsteuer,
    char *solidaritaetszuschlag
    ) {
    kst_ergebnis_t *kst_ergebnis_local_var = malloc(sizeof(kst_ergebnis_t));
    if (!kst_ergebnis_local_var) {
        return NULL;
    }
    memset(kst_ergebnis_local_var, 0, sizeof(kst_ergebnis_t));
    kst_ergebnis_local_var->_library_owned = 1;
    kst_ergebnis_local_var->gesamt = gesamt;
    kst_ergebnis_local_var->gesamtbelastung = gesamtbelastung;
    kst_ergebnis_local_var->gewerbesteuer = gewerbesteuer;
    kst_ergebnis_local_var->gewinn = gewinn;
    kst_ergebnis_local_var->ist_kapitalgesellschaft = ist_kapitalgesellschaft;
    kst_ergebnis_local_var->jahr = jahr;
    kst_ergebnis_local_var->koerperschaftsteuer = koerperschaftsteuer;
    kst_ergebnis_local_var->solidaritaetszuschlag = solidaritaetszuschlag;
    return kst_ergebnis_local_var;
}

__attribute__((deprecated)) kst_ergebnis_t *kst_ergebnis_create(
    char *gesamt,
    char *gesamtbelastung,
    char *gewerbesteuer,
    char *gewinn,
    int *ist_kapitalgesellschaft,
    int *jahr,
    char *koerperschaftsteuer,
    char *solidaritaetszuschlag
    ) {
    int *ist_kapitalgesellschaft_copy = NULL;
    if (ist_kapitalgesellschaft) {
        ist_kapitalgesellschaft_copy = malloc(sizeof(int));
        if (ist_kapitalgesellschaft_copy) *ist_kapitalgesellschaft_copy = *ist_kapitalgesellschaft;
    }
    int *jahr_copy = NULL;
    if (jahr) {
        jahr_copy = malloc(sizeof(int));
        if (jahr_copy) *jahr_copy = *jahr;
    }
    kst_ergebnis_t *result = kst_ergebnis_create_internal (
        gesamt,
        gesamtbelastung,
        gewerbesteuer,
        gewinn,
        ist_kapitalgesellschaft_copy,
        jahr_copy,
        koerperschaftsteuer,
        solidaritaetszuschlag
        );
    if (!result) {
        free(ist_kapitalgesellschaft_copy);
        free(jahr_copy);
    }
    return result;
}

void kst_ergebnis_free(kst_ergebnis_t *kst_ergebnis) {
    if(NULL == kst_ergebnis){
        return ;
    }
    if(kst_ergebnis->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "kst_ergebnis_free");
        return ;
    }
    listEntry_t *listEntry;
    if (kst_ergebnis->gesamt) {
        free(kst_ergebnis->gesamt);
        kst_ergebnis->gesamt = NULL;
    }
    if (kst_ergebnis->gesamtbelastung) {
        free(kst_ergebnis->gesamtbelastung);
        kst_ergebnis->gesamtbelastung = NULL;
    }
    if (kst_ergebnis->gewerbesteuer) {
        free(kst_ergebnis->gewerbesteuer);
        kst_ergebnis->gewerbesteuer = NULL;
    }
    if (kst_ergebnis->gewinn) {
        free(kst_ergebnis->gewinn);
        kst_ergebnis->gewinn = NULL;
    }
    if (kst_ergebnis->ist_kapitalgesellschaft) {
        free(kst_ergebnis->ist_kapitalgesellschaft);
        kst_ergebnis->ist_kapitalgesellschaft = NULL;
    }
    if (kst_ergebnis->jahr) {
        free(kst_ergebnis->jahr);
        kst_ergebnis->jahr = NULL;
    }
    if (kst_ergebnis->koerperschaftsteuer) {
        free(kst_ergebnis->koerperschaftsteuer);
        kst_ergebnis->koerperschaftsteuer = NULL;
    }
    if (kst_ergebnis->solidaritaetszuschlag) {
        free(kst_ergebnis->solidaritaetszuschlag);
        kst_ergebnis->solidaritaetszuschlag = NULL;
    }
    free(kst_ergebnis);
}

cJSON *kst_ergebnis_convertToJSON(kst_ergebnis_t *kst_ergebnis) {
    cJSON *item = cJSON_CreateObject();

    // kst_ergebnis->gesamt
    if (!kst_ergebnis->gesamt) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gesamt", kst_ergebnis->gesamt) == NULL) {
    goto fail; //String
    }


    // kst_ergebnis->gesamtbelastung
    if (!kst_ergebnis->gesamtbelastung) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gesamtbelastung", kst_ergebnis->gesamtbelastung) == NULL) {
    goto fail; //String
    }


    // kst_ergebnis->gewerbesteuer
    if (!kst_ergebnis->gewerbesteuer) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gewerbesteuer", kst_ergebnis->gewerbesteuer) == NULL) {
    goto fail; //String
    }


    // kst_ergebnis->gewinn
    if (!kst_ergebnis->gewinn) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gewinn", kst_ergebnis->gewinn) == NULL) {
    goto fail; //String
    }


    // kst_ergebnis->ist_kapitalgesellschaft
    if (!kst_ergebnis->ist_kapitalgesellschaft) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ist_kapitalgesellschaft", *kst_ergebnis->ist_kapitalgesellschaft) == NULL) {
    goto fail; //Bool
    }


    // kst_ergebnis->jahr
    if (!kst_ergebnis->jahr) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "jahr", *kst_ergebnis->jahr) == NULL) {
    goto fail; //Numeric
    }


    // kst_ergebnis->koerperschaftsteuer
    if (!kst_ergebnis->koerperschaftsteuer) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "koerperschaftsteuer", kst_ergebnis->koerperschaftsteuer) == NULL) {
    goto fail; //String
    }


    // kst_ergebnis->solidaritaetszuschlag
    if (!kst_ergebnis->solidaritaetszuschlag) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "solidaritaetszuschlag", kst_ergebnis->solidaritaetszuschlag) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

kst_ergebnis_t *kst_ergebnis_parseFromJSON(cJSON *kst_ergebnisJSON){

    kst_ergebnis_t *kst_ergebnis_local_var = NULL;

    char *gesamt_local_str = NULL;

    char *gesamtbelastung_local_str = NULL;

    char *gewerbesteuer_local_str = NULL;

    char *gewinn_local_str = NULL;

    // define the local variable for kst_ergebnis->ist_kapitalgesellschaft
    int *ist_kapitalgesellschaft_local_var = NULL;

    // define the local variable for kst_ergebnis->jahr
    int *jahr_local_var = NULL;

    char *koerperschaftsteuer_local_str = NULL;

    char *solidaritaetszuschlag_local_str = NULL;

    // kst_ergebnis->gesamt
    cJSON *gesamt = cJSON_GetObjectItemCaseSensitive(kst_ergebnisJSON, "gesamt");
    if (cJSON_IsNull(gesamt)) {
        gesamt = NULL;
    }
    if (!gesamt) {
        goto end;
    }

    
    if(!cJSON_IsString(gesamt))
    {
    goto end; //String
    }

    // kst_ergebnis->gesamtbelastung
    cJSON *gesamtbelastung = cJSON_GetObjectItemCaseSensitive(kst_ergebnisJSON, "gesamtbelastung");
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

    // kst_ergebnis->gewerbesteuer
    cJSON *gewerbesteuer = cJSON_GetObjectItemCaseSensitive(kst_ergebnisJSON, "gewerbesteuer");
    if (cJSON_IsNull(gewerbesteuer)) {
        gewerbesteuer = NULL;
    }
    if (!gewerbesteuer) {
        goto end;
    }

    
    if(!cJSON_IsString(gewerbesteuer))
    {
    goto end; //String
    }

    // kst_ergebnis->gewinn
    cJSON *gewinn = cJSON_GetObjectItemCaseSensitive(kst_ergebnisJSON, "gewinn");
    if (cJSON_IsNull(gewinn)) {
        gewinn = NULL;
    }
    if (!gewinn) {
        goto end;
    }

    
    if(!cJSON_IsString(gewinn))
    {
    goto end; //String
    }

    // kst_ergebnis->ist_kapitalgesellschaft
    cJSON *ist_kapitalgesellschaft = cJSON_GetObjectItemCaseSensitive(kst_ergebnisJSON, "ist_kapitalgesellschaft");
    if (cJSON_IsNull(ist_kapitalgesellschaft)) {
        ist_kapitalgesellschaft = NULL;
    }
    if (!ist_kapitalgesellschaft) {
        goto end;
    }

    
    if(!cJSON_IsBool(ist_kapitalgesellschaft))
    {
    goto end; //Bool
    }
    ist_kapitalgesellschaft_local_var = malloc(sizeof(int));
    if(!ist_kapitalgesellschaft_local_var)
    {
        goto end;
    }
    *ist_kapitalgesellschaft_local_var = ist_kapitalgesellschaft->valueint;

    // kst_ergebnis->jahr
    cJSON *jahr = cJSON_GetObjectItemCaseSensitive(kst_ergebnisJSON, "jahr");
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

    // kst_ergebnis->koerperschaftsteuer
    cJSON *koerperschaftsteuer = cJSON_GetObjectItemCaseSensitive(kst_ergebnisJSON, "koerperschaftsteuer");
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

    // kst_ergebnis->solidaritaetszuschlag
    cJSON *solidaritaetszuschlag = cJSON_GetObjectItemCaseSensitive(kst_ergebnisJSON, "solidaritaetszuschlag");
    if (cJSON_IsNull(solidaritaetszuschlag)) {
        solidaritaetszuschlag = NULL;
    }
    if (!solidaritaetszuschlag) {
        goto end;
    }

    
    if(!cJSON_IsString(solidaritaetszuschlag))
    {
    goto end; //String
    }


    if (gesamt && !cJSON_IsNull(gesamt)) gesamt_local_str = strdup(gesamt->valuestring);
    if (gesamtbelastung && !cJSON_IsNull(gesamtbelastung)) gesamtbelastung_local_str = strdup(gesamtbelastung->valuestring);
    if (gewerbesteuer && !cJSON_IsNull(gewerbesteuer)) gewerbesteuer_local_str = strdup(gewerbesteuer->valuestring);
    if (gewinn && !cJSON_IsNull(gewinn)) gewinn_local_str = strdup(gewinn->valuestring);
    if (koerperschaftsteuer && !cJSON_IsNull(koerperschaftsteuer)) koerperschaftsteuer_local_str = strdup(koerperschaftsteuer->valuestring);
    if (solidaritaetszuschlag && !cJSON_IsNull(solidaritaetszuschlag)) solidaritaetszuschlag_local_str = strdup(solidaritaetszuschlag->valuestring);

    kst_ergebnis_local_var = kst_ergebnis_create_internal (
        gesamt_local_str,
        gesamtbelastung_local_str,
        gewerbesteuer_local_str,
        gewinn_local_str,
        ist_kapitalgesellschaft_local_var,
        jahr_local_var,
        koerperschaftsteuer_local_str,
        solidaritaetszuschlag_local_str
        );

    if (!kst_ergebnis_local_var) {
        goto end;
    }

    return kst_ergebnis_local_var;
end:
    if (gesamt_local_str) {
        free(gesamt_local_str);
        gesamt_local_str = NULL;
    }
    if (gesamtbelastung_local_str) {
        free(gesamtbelastung_local_str);
        gesamtbelastung_local_str = NULL;
    }
    if (gewerbesteuer_local_str) {
        free(gewerbesteuer_local_str);
        gewerbesteuer_local_str = NULL;
    }
    if (gewinn_local_str) {
        free(gewinn_local_str);
        gewinn_local_str = NULL;
    }
    if (ist_kapitalgesellschaft_local_var) {
        free(ist_kapitalgesellschaft_local_var);
        ist_kapitalgesellschaft_local_var = NULL;
    }
    if (jahr_local_var) {
        free(jahr_local_var);
        jahr_local_var = NULL;
    }
    if (koerperschaftsteuer_local_str) {
        free(koerperschaftsteuer_local_str);
        koerperschaftsteuer_local_str = NULL;
    }
    if (solidaritaetszuschlag_local_str) {
        free(solidaritaetszuschlag_local_str);
        solidaritaetszuschlag_local_str = NULL;
    }
    return NULL;

}
