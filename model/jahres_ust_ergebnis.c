#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "jahres_ust_ergebnis.h"



static jahres_ust_ergebnis_t *jahres_ust_ergebnis_create_internal(
    char *bis,
    int *gespeicherte_perioden,
    int *hat_ig_transaktionen,
    int *ist_kleinunternehmer,
    int *jahr,
    char *kz_41,
    char *kz_43,
    char *kz_46,
    char *kz_47,
    char *kz_48,
    char *kz_61,
    char *kz_66,
    char *kz_67,
    char *kz_81,
    char *kz_83,
    char *kz_84,
    char *kz_85,
    char *kz_86,
    char *kz_88,
    char *kz_89,
    char *kz_93,
    char *restschuld,
    char *summe_vorauszahlungen,
    char *von,
    char *zahllast
    ) {
    jahres_ust_ergebnis_t *jahres_ust_ergebnis_local_var = malloc(sizeof(jahres_ust_ergebnis_t));
    if (!jahres_ust_ergebnis_local_var) {
        return NULL;
    }
    memset(jahres_ust_ergebnis_local_var, 0, sizeof(jahres_ust_ergebnis_t));
    jahres_ust_ergebnis_local_var->_library_owned = 1;
    jahres_ust_ergebnis_local_var->bis = bis;
    jahres_ust_ergebnis_local_var->gespeicherte_perioden = gespeicherte_perioden;
    jahres_ust_ergebnis_local_var->hat_ig_transaktionen = hat_ig_transaktionen;
    jahres_ust_ergebnis_local_var->ist_kleinunternehmer = ist_kleinunternehmer;
    jahres_ust_ergebnis_local_var->jahr = jahr;
    jahres_ust_ergebnis_local_var->kz_41 = kz_41;
    jahres_ust_ergebnis_local_var->kz_43 = kz_43;
    jahres_ust_ergebnis_local_var->kz_46 = kz_46;
    jahres_ust_ergebnis_local_var->kz_47 = kz_47;
    jahres_ust_ergebnis_local_var->kz_48 = kz_48;
    jahres_ust_ergebnis_local_var->kz_61 = kz_61;
    jahres_ust_ergebnis_local_var->kz_66 = kz_66;
    jahres_ust_ergebnis_local_var->kz_67 = kz_67;
    jahres_ust_ergebnis_local_var->kz_81 = kz_81;
    jahres_ust_ergebnis_local_var->kz_83 = kz_83;
    jahres_ust_ergebnis_local_var->kz_84 = kz_84;
    jahres_ust_ergebnis_local_var->kz_85 = kz_85;
    jahres_ust_ergebnis_local_var->kz_86 = kz_86;
    jahres_ust_ergebnis_local_var->kz_88 = kz_88;
    jahres_ust_ergebnis_local_var->kz_89 = kz_89;
    jahres_ust_ergebnis_local_var->kz_93 = kz_93;
    jahres_ust_ergebnis_local_var->restschuld = restschuld;
    jahres_ust_ergebnis_local_var->summe_vorauszahlungen = summe_vorauszahlungen;
    jahres_ust_ergebnis_local_var->von = von;
    jahres_ust_ergebnis_local_var->zahllast = zahllast;
    return jahres_ust_ergebnis_local_var;
}

__attribute__((deprecated)) jahres_ust_ergebnis_t *jahres_ust_ergebnis_create(
    char *bis,
    int *gespeicherte_perioden,
    int *hat_ig_transaktionen,
    int *ist_kleinunternehmer,
    int *jahr,
    char *kz_41,
    char *kz_43,
    char *kz_46,
    char *kz_47,
    char *kz_48,
    char *kz_61,
    char *kz_66,
    char *kz_67,
    char *kz_81,
    char *kz_83,
    char *kz_84,
    char *kz_85,
    char *kz_86,
    char *kz_88,
    char *kz_89,
    char *kz_93,
    char *restschuld,
    char *summe_vorauszahlungen,
    char *von,
    char *zahllast
    ) {
    int *gespeicherte_perioden_copy = NULL;
    if (gespeicherte_perioden) {
        gespeicherte_perioden_copy = malloc(sizeof(int));
        if (gespeicherte_perioden_copy) *gespeicherte_perioden_copy = *gespeicherte_perioden;
    }
    int *hat_ig_transaktionen_copy = NULL;
    if (hat_ig_transaktionen) {
        hat_ig_transaktionen_copy = malloc(sizeof(int));
        if (hat_ig_transaktionen_copy) *hat_ig_transaktionen_copy = *hat_ig_transaktionen;
    }
    int *ist_kleinunternehmer_copy = NULL;
    if (ist_kleinunternehmer) {
        ist_kleinunternehmer_copy = malloc(sizeof(int));
        if (ist_kleinunternehmer_copy) *ist_kleinunternehmer_copy = *ist_kleinunternehmer;
    }
    int *jahr_copy = NULL;
    if (jahr) {
        jahr_copy = malloc(sizeof(int));
        if (jahr_copy) *jahr_copy = *jahr;
    }
    jahres_ust_ergebnis_t *result = jahres_ust_ergebnis_create_internal (
        bis,
        gespeicherte_perioden_copy,
        hat_ig_transaktionen_copy,
        ist_kleinunternehmer_copy,
        jahr_copy,
        kz_41,
        kz_43,
        kz_46,
        kz_47,
        kz_48,
        kz_61,
        kz_66,
        kz_67,
        kz_81,
        kz_83,
        kz_84,
        kz_85,
        kz_86,
        kz_88,
        kz_89,
        kz_93,
        restschuld,
        summe_vorauszahlungen,
        von,
        zahllast
        );
    if (!result) {
        free(gespeicherte_perioden_copy);
        free(hat_ig_transaktionen_copy);
        free(ist_kleinunternehmer_copy);
        free(jahr_copy);
    }
    return result;
}

void jahres_ust_ergebnis_free(jahres_ust_ergebnis_t *jahres_ust_ergebnis) {
    if(NULL == jahres_ust_ergebnis){
        return ;
    }
    if(jahres_ust_ergebnis->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "jahres_ust_ergebnis_free");
        return ;
    }
    listEntry_t *listEntry;
    if (jahres_ust_ergebnis->bis) {
        free(jahres_ust_ergebnis->bis);
        jahres_ust_ergebnis->bis = NULL;
    }
    if (jahres_ust_ergebnis->gespeicherte_perioden) {
        free(jahres_ust_ergebnis->gespeicherte_perioden);
        jahres_ust_ergebnis->gespeicherte_perioden = NULL;
    }
    if (jahres_ust_ergebnis->hat_ig_transaktionen) {
        free(jahres_ust_ergebnis->hat_ig_transaktionen);
        jahres_ust_ergebnis->hat_ig_transaktionen = NULL;
    }
    if (jahres_ust_ergebnis->ist_kleinunternehmer) {
        free(jahres_ust_ergebnis->ist_kleinunternehmer);
        jahres_ust_ergebnis->ist_kleinunternehmer = NULL;
    }
    if (jahres_ust_ergebnis->jahr) {
        free(jahres_ust_ergebnis->jahr);
        jahres_ust_ergebnis->jahr = NULL;
    }
    if (jahres_ust_ergebnis->kz_41) {
        free(jahres_ust_ergebnis->kz_41);
        jahres_ust_ergebnis->kz_41 = NULL;
    }
    if (jahres_ust_ergebnis->kz_43) {
        free(jahres_ust_ergebnis->kz_43);
        jahres_ust_ergebnis->kz_43 = NULL;
    }
    if (jahres_ust_ergebnis->kz_46) {
        free(jahres_ust_ergebnis->kz_46);
        jahres_ust_ergebnis->kz_46 = NULL;
    }
    if (jahres_ust_ergebnis->kz_47) {
        free(jahres_ust_ergebnis->kz_47);
        jahres_ust_ergebnis->kz_47 = NULL;
    }
    if (jahres_ust_ergebnis->kz_48) {
        free(jahres_ust_ergebnis->kz_48);
        jahres_ust_ergebnis->kz_48 = NULL;
    }
    if (jahres_ust_ergebnis->kz_61) {
        free(jahres_ust_ergebnis->kz_61);
        jahres_ust_ergebnis->kz_61 = NULL;
    }
    if (jahres_ust_ergebnis->kz_66) {
        free(jahres_ust_ergebnis->kz_66);
        jahres_ust_ergebnis->kz_66 = NULL;
    }
    if (jahres_ust_ergebnis->kz_67) {
        free(jahres_ust_ergebnis->kz_67);
        jahres_ust_ergebnis->kz_67 = NULL;
    }
    if (jahres_ust_ergebnis->kz_81) {
        free(jahres_ust_ergebnis->kz_81);
        jahres_ust_ergebnis->kz_81 = NULL;
    }
    if (jahres_ust_ergebnis->kz_83) {
        free(jahres_ust_ergebnis->kz_83);
        jahres_ust_ergebnis->kz_83 = NULL;
    }
    if (jahres_ust_ergebnis->kz_84) {
        free(jahres_ust_ergebnis->kz_84);
        jahres_ust_ergebnis->kz_84 = NULL;
    }
    if (jahres_ust_ergebnis->kz_85) {
        free(jahres_ust_ergebnis->kz_85);
        jahres_ust_ergebnis->kz_85 = NULL;
    }
    if (jahres_ust_ergebnis->kz_86) {
        free(jahres_ust_ergebnis->kz_86);
        jahres_ust_ergebnis->kz_86 = NULL;
    }
    if (jahres_ust_ergebnis->kz_88) {
        free(jahres_ust_ergebnis->kz_88);
        jahres_ust_ergebnis->kz_88 = NULL;
    }
    if (jahres_ust_ergebnis->kz_89) {
        free(jahres_ust_ergebnis->kz_89);
        jahres_ust_ergebnis->kz_89 = NULL;
    }
    if (jahres_ust_ergebnis->kz_93) {
        free(jahres_ust_ergebnis->kz_93);
        jahres_ust_ergebnis->kz_93 = NULL;
    }
    if (jahres_ust_ergebnis->restschuld) {
        free(jahres_ust_ergebnis->restschuld);
        jahres_ust_ergebnis->restschuld = NULL;
    }
    if (jahres_ust_ergebnis->summe_vorauszahlungen) {
        free(jahres_ust_ergebnis->summe_vorauszahlungen);
        jahres_ust_ergebnis->summe_vorauszahlungen = NULL;
    }
    if (jahres_ust_ergebnis->von) {
        free(jahres_ust_ergebnis->von);
        jahres_ust_ergebnis->von = NULL;
    }
    if (jahres_ust_ergebnis->zahllast) {
        free(jahres_ust_ergebnis->zahllast);
        jahres_ust_ergebnis->zahllast = NULL;
    }
    free(jahres_ust_ergebnis);
}

cJSON *jahres_ust_ergebnis_convertToJSON(jahres_ust_ergebnis_t *jahres_ust_ergebnis) {
    cJSON *item = cJSON_CreateObject();

    // jahres_ust_ergebnis->bis
    if (!jahres_ust_ergebnis->bis) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "bis", jahres_ust_ergebnis->bis) == NULL) {
    goto fail; //String
    }


    // jahres_ust_ergebnis->gespeicherte_perioden
    if (!jahres_ust_ergebnis->gespeicherte_perioden) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "gespeicherte_perioden", *jahres_ust_ergebnis->gespeicherte_perioden) == NULL) {
    goto fail; //Numeric
    }


    // jahres_ust_ergebnis->hat_ig_transaktionen
    if (!jahres_ust_ergebnis->hat_ig_transaktionen) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hat_ig_transaktionen", *jahres_ust_ergebnis->hat_ig_transaktionen) == NULL) {
    goto fail; //Bool
    }


    // jahres_ust_ergebnis->ist_kleinunternehmer
    if (!jahres_ust_ergebnis->ist_kleinunternehmer) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ist_kleinunternehmer", *jahres_ust_ergebnis->ist_kleinunternehmer) == NULL) {
    goto fail; //Bool
    }


    // jahres_ust_ergebnis->jahr
    if (!jahres_ust_ergebnis->jahr) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "jahr", *jahres_ust_ergebnis->jahr) == NULL) {
    goto fail; //Numeric
    }


    // jahres_ust_ergebnis->kz_41
    if (!jahres_ust_ergebnis->kz_41) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_41", jahres_ust_ergebnis->kz_41) == NULL) {
    goto fail; //String
    }


    // jahres_ust_ergebnis->kz_43
    if (!jahres_ust_ergebnis->kz_43) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_43", jahres_ust_ergebnis->kz_43) == NULL) {
    goto fail; //String
    }


    // jahres_ust_ergebnis->kz_46
    if (!jahres_ust_ergebnis->kz_46) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_46", jahres_ust_ergebnis->kz_46) == NULL) {
    goto fail; //String
    }


    // jahres_ust_ergebnis->kz_47
    if (!jahres_ust_ergebnis->kz_47) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_47", jahres_ust_ergebnis->kz_47) == NULL) {
    goto fail; //String
    }


    // jahres_ust_ergebnis->kz_48
    if (!jahres_ust_ergebnis->kz_48) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_48", jahres_ust_ergebnis->kz_48) == NULL) {
    goto fail; //String
    }


    // jahres_ust_ergebnis->kz_61
    if (!jahres_ust_ergebnis->kz_61) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_61", jahres_ust_ergebnis->kz_61) == NULL) {
    goto fail; //String
    }


    // jahres_ust_ergebnis->kz_66
    if (!jahres_ust_ergebnis->kz_66) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_66", jahres_ust_ergebnis->kz_66) == NULL) {
    goto fail; //String
    }


    // jahres_ust_ergebnis->kz_67
    if (!jahres_ust_ergebnis->kz_67) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_67", jahres_ust_ergebnis->kz_67) == NULL) {
    goto fail; //String
    }


    // jahres_ust_ergebnis->kz_81
    if (!jahres_ust_ergebnis->kz_81) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_81", jahres_ust_ergebnis->kz_81) == NULL) {
    goto fail; //String
    }


    // jahres_ust_ergebnis->kz_83
    if (!jahres_ust_ergebnis->kz_83) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_83", jahres_ust_ergebnis->kz_83) == NULL) {
    goto fail; //String
    }


    // jahres_ust_ergebnis->kz_84
    if (!jahres_ust_ergebnis->kz_84) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_84", jahres_ust_ergebnis->kz_84) == NULL) {
    goto fail; //String
    }


    // jahres_ust_ergebnis->kz_85
    if (!jahres_ust_ergebnis->kz_85) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_85", jahres_ust_ergebnis->kz_85) == NULL) {
    goto fail; //String
    }


    // jahres_ust_ergebnis->kz_86
    if (!jahres_ust_ergebnis->kz_86) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_86", jahres_ust_ergebnis->kz_86) == NULL) {
    goto fail; //String
    }


    // jahres_ust_ergebnis->kz_88
    if (!jahres_ust_ergebnis->kz_88) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_88", jahres_ust_ergebnis->kz_88) == NULL) {
    goto fail; //String
    }


    // jahres_ust_ergebnis->kz_89
    if (!jahres_ust_ergebnis->kz_89) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_89", jahres_ust_ergebnis->kz_89) == NULL) {
    goto fail; //String
    }


    // jahres_ust_ergebnis->kz_93
    if (!jahres_ust_ergebnis->kz_93) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_93", jahres_ust_ergebnis->kz_93) == NULL) {
    goto fail; //String
    }


    // jahres_ust_ergebnis->restschuld
    if (!jahres_ust_ergebnis->restschuld) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "restschuld", jahres_ust_ergebnis->restschuld) == NULL) {
    goto fail; //String
    }


    // jahres_ust_ergebnis->summe_vorauszahlungen
    if (!jahres_ust_ergebnis->summe_vorauszahlungen) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "summe_vorauszahlungen", jahres_ust_ergebnis->summe_vorauszahlungen) == NULL) {
    goto fail; //String
    }


    // jahres_ust_ergebnis->von
    if (!jahres_ust_ergebnis->von) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "von", jahres_ust_ergebnis->von) == NULL) {
    goto fail; //String
    }


    // jahres_ust_ergebnis->zahllast
    if (!jahres_ust_ergebnis->zahllast) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "zahllast", jahres_ust_ergebnis->zahllast) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

jahres_ust_ergebnis_t *jahres_ust_ergebnis_parseFromJSON(cJSON *jahres_ust_ergebnisJSON){

    jahres_ust_ergebnis_t *jahres_ust_ergebnis_local_var = NULL;

    char *bis_local_str = NULL;

    // define the local variable for jahres_ust_ergebnis->gespeicherte_perioden
    int *gespeicherte_perioden_local_var = NULL;

    // define the local variable for jahres_ust_ergebnis->hat_ig_transaktionen
    int *hat_ig_transaktionen_local_var = NULL;

    // define the local variable for jahres_ust_ergebnis->ist_kleinunternehmer
    int *ist_kleinunternehmer_local_var = NULL;

    // define the local variable for jahres_ust_ergebnis->jahr
    int *jahr_local_var = NULL;

    char *kz_41_local_str = NULL;

    char *kz_43_local_str = NULL;

    char *kz_46_local_str = NULL;

    char *kz_47_local_str = NULL;

    char *kz_48_local_str = NULL;

    char *kz_61_local_str = NULL;

    char *kz_66_local_str = NULL;

    char *kz_67_local_str = NULL;

    char *kz_81_local_str = NULL;

    char *kz_83_local_str = NULL;

    char *kz_84_local_str = NULL;

    char *kz_85_local_str = NULL;

    char *kz_86_local_str = NULL;

    char *kz_88_local_str = NULL;

    char *kz_89_local_str = NULL;

    char *kz_93_local_str = NULL;

    char *restschuld_local_str = NULL;

    char *summe_vorauszahlungen_local_str = NULL;

    char *von_local_str = NULL;

    char *zahllast_local_str = NULL;

    // jahres_ust_ergebnis->bis
    cJSON *bis = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "bis");
    if (cJSON_IsNull(bis)) {
        bis = NULL;
    }
    if (!bis) {
        goto end;
    }

    
    if(!cJSON_IsString(bis))
    {
    goto end; //String
    }

    // jahres_ust_ergebnis->gespeicherte_perioden
    cJSON *gespeicherte_perioden = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "gespeicherte_perioden");
    if (cJSON_IsNull(gespeicherte_perioden)) {
        gespeicherte_perioden = NULL;
    }
    if (!gespeicherte_perioden) {
        goto end;
    }

    
    if(!cJSON_IsNumber(gespeicherte_perioden))
    {
    goto end; //Numeric
    }
    gespeicherte_perioden_local_var = malloc(sizeof(int));
    if(!gespeicherte_perioden_local_var)
    {
        goto end;
    }
    *gespeicherte_perioden_local_var = gespeicherte_perioden->valuedouble;

    // jahres_ust_ergebnis->hat_ig_transaktionen
    cJSON *hat_ig_transaktionen = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "hat_ig_transaktionen");
    if (cJSON_IsNull(hat_ig_transaktionen)) {
        hat_ig_transaktionen = NULL;
    }
    if (!hat_ig_transaktionen) {
        goto end;
    }

    
    if(!cJSON_IsBool(hat_ig_transaktionen))
    {
    goto end; //Bool
    }
    hat_ig_transaktionen_local_var = malloc(sizeof(int));
    if(!hat_ig_transaktionen_local_var)
    {
        goto end;
    }
    *hat_ig_transaktionen_local_var = hat_ig_transaktionen->valueint;

    // jahres_ust_ergebnis->ist_kleinunternehmer
    cJSON *ist_kleinunternehmer = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "ist_kleinunternehmer");
    if (cJSON_IsNull(ist_kleinunternehmer)) {
        ist_kleinunternehmer = NULL;
    }
    if (!ist_kleinunternehmer) {
        goto end;
    }

    
    if(!cJSON_IsBool(ist_kleinunternehmer))
    {
    goto end; //Bool
    }
    ist_kleinunternehmer_local_var = malloc(sizeof(int));
    if(!ist_kleinunternehmer_local_var)
    {
        goto end;
    }
    *ist_kleinunternehmer_local_var = ist_kleinunternehmer->valueint;

    // jahres_ust_ergebnis->jahr
    cJSON *jahr = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "jahr");
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

    // jahres_ust_ergebnis->kz_41
    cJSON *kz_41 = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "kz_41");
    if (cJSON_IsNull(kz_41)) {
        kz_41 = NULL;
    }
    if (!kz_41) {
        goto end;
    }

    
    if(!cJSON_IsString(kz_41))
    {
    goto end; //String
    }

    // jahres_ust_ergebnis->kz_43
    cJSON *kz_43 = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "kz_43");
    if (cJSON_IsNull(kz_43)) {
        kz_43 = NULL;
    }
    if (!kz_43) {
        goto end;
    }

    
    if(!cJSON_IsString(kz_43))
    {
    goto end; //String
    }

    // jahres_ust_ergebnis->kz_46
    cJSON *kz_46 = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "kz_46");
    if (cJSON_IsNull(kz_46)) {
        kz_46 = NULL;
    }
    if (!kz_46) {
        goto end;
    }

    
    if(!cJSON_IsString(kz_46))
    {
    goto end; //String
    }

    // jahres_ust_ergebnis->kz_47
    cJSON *kz_47 = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "kz_47");
    if (cJSON_IsNull(kz_47)) {
        kz_47 = NULL;
    }
    if (!kz_47) {
        goto end;
    }

    
    if(!cJSON_IsString(kz_47))
    {
    goto end; //String
    }

    // jahres_ust_ergebnis->kz_48
    cJSON *kz_48 = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "kz_48");
    if (cJSON_IsNull(kz_48)) {
        kz_48 = NULL;
    }
    if (!kz_48) {
        goto end;
    }

    
    if(!cJSON_IsString(kz_48))
    {
    goto end; //String
    }

    // jahres_ust_ergebnis->kz_61
    cJSON *kz_61 = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "kz_61");
    if (cJSON_IsNull(kz_61)) {
        kz_61 = NULL;
    }
    if (!kz_61) {
        goto end;
    }

    
    if(!cJSON_IsString(kz_61))
    {
    goto end; //String
    }

    // jahres_ust_ergebnis->kz_66
    cJSON *kz_66 = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "kz_66");
    if (cJSON_IsNull(kz_66)) {
        kz_66 = NULL;
    }
    if (!kz_66) {
        goto end;
    }

    
    if(!cJSON_IsString(kz_66))
    {
    goto end; //String
    }

    // jahres_ust_ergebnis->kz_67
    cJSON *kz_67 = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "kz_67");
    if (cJSON_IsNull(kz_67)) {
        kz_67 = NULL;
    }
    if (!kz_67) {
        goto end;
    }

    
    if(!cJSON_IsString(kz_67))
    {
    goto end; //String
    }

    // jahres_ust_ergebnis->kz_81
    cJSON *kz_81 = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "kz_81");
    if (cJSON_IsNull(kz_81)) {
        kz_81 = NULL;
    }
    if (!kz_81) {
        goto end;
    }

    
    if(!cJSON_IsString(kz_81))
    {
    goto end; //String
    }

    // jahres_ust_ergebnis->kz_83
    cJSON *kz_83 = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "kz_83");
    if (cJSON_IsNull(kz_83)) {
        kz_83 = NULL;
    }
    if (!kz_83) {
        goto end;
    }

    
    if(!cJSON_IsString(kz_83))
    {
    goto end; //String
    }

    // jahres_ust_ergebnis->kz_84
    cJSON *kz_84 = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "kz_84");
    if (cJSON_IsNull(kz_84)) {
        kz_84 = NULL;
    }
    if (!kz_84) {
        goto end;
    }

    
    if(!cJSON_IsString(kz_84))
    {
    goto end; //String
    }

    // jahres_ust_ergebnis->kz_85
    cJSON *kz_85 = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "kz_85");
    if (cJSON_IsNull(kz_85)) {
        kz_85 = NULL;
    }
    if (!kz_85) {
        goto end;
    }

    
    if(!cJSON_IsString(kz_85))
    {
    goto end; //String
    }

    // jahres_ust_ergebnis->kz_86
    cJSON *kz_86 = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "kz_86");
    if (cJSON_IsNull(kz_86)) {
        kz_86 = NULL;
    }
    if (!kz_86) {
        goto end;
    }

    
    if(!cJSON_IsString(kz_86))
    {
    goto end; //String
    }

    // jahres_ust_ergebnis->kz_88
    cJSON *kz_88 = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "kz_88");
    if (cJSON_IsNull(kz_88)) {
        kz_88 = NULL;
    }
    if (!kz_88) {
        goto end;
    }

    
    if(!cJSON_IsString(kz_88))
    {
    goto end; //String
    }

    // jahres_ust_ergebnis->kz_89
    cJSON *kz_89 = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "kz_89");
    if (cJSON_IsNull(kz_89)) {
        kz_89 = NULL;
    }
    if (!kz_89) {
        goto end;
    }

    
    if(!cJSON_IsString(kz_89))
    {
    goto end; //String
    }

    // jahres_ust_ergebnis->kz_93
    cJSON *kz_93 = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "kz_93");
    if (cJSON_IsNull(kz_93)) {
        kz_93 = NULL;
    }
    if (!kz_93) {
        goto end;
    }

    
    if(!cJSON_IsString(kz_93))
    {
    goto end; //String
    }

    // jahres_ust_ergebnis->restschuld
    cJSON *restschuld = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "restschuld");
    if (cJSON_IsNull(restschuld)) {
        restschuld = NULL;
    }
    if (!restschuld) {
        goto end;
    }

    
    if(!cJSON_IsString(restschuld))
    {
    goto end; //String
    }

    // jahres_ust_ergebnis->summe_vorauszahlungen
    cJSON *summe_vorauszahlungen = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "summe_vorauszahlungen");
    if (cJSON_IsNull(summe_vorauszahlungen)) {
        summe_vorauszahlungen = NULL;
    }
    if (!summe_vorauszahlungen) {
        goto end;
    }

    
    if(!cJSON_IsString(summe_vorauszahlungen))
    {
    goto end; //String
    }

    // jahres_ust_ergebnis->von
    cJSON *von = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "von");
    if (cJSON_IsNull(von)) {
        von = NULL;
    }
    if (!von) {
        goto end;
    }

    
    if(!cJSON_IsString(von))
    {
    goto end; //String
    }

    // jahres_ust_ergebnis->zahllast
    cJSON *zahllast = cJSON_GetObjectItemCaseSensitive(jahres_ust_ergebnisJSON, "zahllast");
    if (cJSON_IsNull(zahllast)) {
        zahllast = NULL;
    }
    if (!zahllast) {
        goto end;
    }

    
    if(!cJSON_IsString(zahllast))
    {
    goto end; //String
    }


    if (bis && !cJSON_IsNull(bis)) bis_local_str = strdup(bis->valuestring);
    if (kz_41 && !cJSON_IsNull(kz_41)) kz_41_local_str = strdup(kz_41->valuestring);
    if (kz_43 && !cJSON_IsNull(kz_43)) kz_43_local_str = strdup(kz_43->valuestring);
    if (kz_46 && !cJSON_IsNull(kz_46)) kz_46_local_str = strdup(kz_46->valuestring);
    if (kz_47 && !cJSON_IsNull(kz_47)) kz_47_local_str = strdup(kz_47->valuestring);
    if (kz_48 && !cJSON_IsNull(kz_48)) kz_48_local_str = strdup(kz_48->valuestring);
    if (kz_61 && !cJSON_IsNull(kz_61)) kz_61_local_str = strdup(kz_61->valuestring);
    if (kz_66 && !cJSON_IsNull(kz_66)) kz_66_local_str = strdup(kz_66->valuestring);
    if (kz_67 && !cJSON_IsNull(kz_67)) kz_67_local_str = strdup(kz_67->valuestring);
    if (kz_81 && !cJSON_IsNull(kz_81)) kz_81_local_str = strdup(kz_81->valuestring);
    if (kz_83 && !cJSON_IsNull(kz_83)) kz_83_local_str = strdup(kz_83->valuestring);
    if (kz_84 && !cJSON_IsNull(kz_84)) kz_84_local_str = strdup(kz_84->valuestring);
    if (kz_85 && !cJSON_IsNull(kz_85)) kz_85_local_str = strdup(kz_85->valuestring);
    if (kz_86 && !cJSON_IsNull(kz_86)) kz_86_local_str = strdup(kz_86->valuestring);
    if (kz_88 && !cJSON_IsNull(kz_88)) kz_88_local_str = strdup(kz_88->valuestring);
    if (kz_89 && !cJSON_IsNull(kz_89)) kz_89_local_str = strdup(kz_89->valuestring);
    if (kz_93 && !cJSON_IsNull(kz_93)) kz_93_local_str = strdup(kz_93->valuestring);
    if (restschuld && !cJSON_IsNull(restschuld)) restschuld_local_str = strdup(restschuld->valuestring);
    if (summe_vorauszahlungen && !cJSON_IsNull(summe_vorauszahlungen)) summe_vorauszahlungen_local_str = strdup(summe_vorauszahlungen->valuestring);
    if (von && !cJSON_IsNull(von)) von_local_str = strdup(von->valuestring);
    if (zahllast && !cJSON_IsNull(zahllast)) zahllast_local_str = strdup(zahllast->valuestring);

    jahres_ust_ergebnis_local_var = jahres_ust_ergebnis_create_internal (
        bis_local_str,
        gespeicherte_perioden_local_var,
        hat_ig_transaktionen_local_var,
        ist_kleinunternehmer_local_var,
        jahr_local_var,
        kz_41_local_str,
        kz_43_local_str,
        kz_46_local_str,
        kz_47_local_str,
        kz_48_local_str,
        kz_61_local_str,
        kz_66_local_str,
        kz_67_local_str,
        kz_81_local_str,
        kz_83_local_str,
        kz_84_local_str,
        kz_85_local_str,
        kz_86_local_str,
        kz_88_local_str,
        kz_89_local_str,
        kz_93_local_str,
        restschuld_local_str,
        summe_vorauszahlungen_local_str,
        von_local_str,
        zahllast_local_str
        );

    if (!jahres_ust_ergebnis_local_var) {
        goto end;
    }

    return jahres_ust_ergebnis_local_var;
end:
    if (bis_local_str) {
        free(bis_local_str);
        bis_local_str = NULL;
    }
    if (gespeicherte_perioden_local_var) {
        free(gespeicherte_perioden_local_var);
        gespeicherte_perioden_local_var = NULL;
    }
    if (hat_ig_transaktionen_local_var) {
        free(hat_ig_transaktionen_local_var);
        hat_ig_transaktionen_local_var = NULL;
    }
    if (ist_kleinunternehmer_local_var) {
        free(ist_kleinunternehmer_local_var);
        ist_kleinunternehmer_local_var = NULL;
    }
    if (jahr_local_var) {
        free(jahr_local_var);
        jahr_local_var = NULL;
    }
    if (kz_41_local_str) {
        free(kz_41_local_str);
        kz_41_local_str = NULL;
    }
    if (kz_43_local_str) {
        free(kz_43_local_str);
        kz_43_local_str = NULL;
    }
    if (kz_46_local_str) {
        free(kz_46_local_str);
        kz_46_local_str = NULL;
    }
    if (kz_47_local_str) {
        free(kz_47_local_str);
        kz_47_local_str = NULL;
    }
    if (kz_48_local_str) {
        free(kz_48_local_str);
        kz_48_local_str = NULL;
    }
    if (kz_61_local_str) {
        free(kz_61_local_str);
        kz_61_local_str = NULL;
    }
    if (kz_66_local_str) {
        free(kz_66_local_str);
        kz_66_local_str = NULL;
    }
    if (kz_67_local_str) {
        free(kz_67_local_str);
        kz_67_local_str = NULL;
    }
    if (kz_81_local_str) {
        free(kz_81_local_str);
        kz_81_local_str = NULL;
    }
    if (kz_83_local_str) {
        free(kz_83_local_str);
        kz_83_local_str = NULL;
    }
    if (kz_84_local_str) {
        free(kz_84_local_str);
        kz_84_local_str = NULL;
    }
    if (kz_85_local_str) {
        free(kz_85_local_str);
        kz_85_local_str = NULL;
    }
    if (kz_86_local_str) {
        free(kz_86_local_str);
        kz_86_local_str = NULL;
    }
    if (kz_88_local_str) {
        free(kz_88_local_str);
        kz_88_local_str = NULL;
    }
    if (kz_89_local_str) {
        free(kz_89_local_str);
        kz_89_local_str = NULL;
    }
    if (kz_93_local_str) {
        free(kz_93_local_str);
        kz_93_local_str = NULL;
    }
    if (restschuld_local_str) {
        free(restschuld_local_str);
        restschuld_local_str = NULL;
    }
    if (summe_vorauszahlungen_local_str) {
        free(summe_vorauszahlungen_local_str);
        summe_vorauszahlungen_local_str = NULL;
    }
    if (von_local_str) {
        free(von_local_str);
        von_local_str = NULL;
    }
    if (zahllast_local_str) {
        free(zahllast_local_str);
        zahllast_local_str = NULL;
    }
    return NULL;

}
