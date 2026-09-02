#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ustva_ergebnis.h"



static ustva_ergebnis_t *ustva_ergebnis_create_internal(
    char *bis,
    char *hinweis,
    int *ist_kleinunternehmer,
    char *kz_41,
    char *kz_43,
    char *kz_46,
    char *kz_47,
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
    char *von,
    char *zahllast,
    char *zeitraum,
    char *zeitraum_typ
    ) {
    ustva_ergebnis_t *ustva_ergebnis_local_var = malloc(sizeof(ustva_ergebnis_t));
    if (!ustva_ergebnis_local_var) {
        return NULL;
    }
    memset(ustva_ergebnis_local_var, 0, sizeof(ustva_ergebnis_t));
    ustva_ergebnis_local_var->_library_owned = 1;
    ustva_ergebnis_local_var->bis = bis;
    ustva_ergebnis_local_var->hinweis = hinweis;
    ustva_ergebnis_local_var->ist_kleinunternehmer = ist_kleinunternehmer;
    ustva_ergebnis_local_var->kz_41 = kz_41;
    ustva_ergebnis_local_var->kz_43 = kz_43;
    ustva_ergebnis_local_var->kz_46 = kz_46;
    ustva_ergebnis_local_var->kz_47 = kz_47;
    ustva_ergebnis_local_var->kz_61 = kz_61;
    ustva_ergebnis_local_var->kz_66 = kz_66;
    ustva_ergebnis_local_var->kz_67 = kz_67;
    ustva_ergebnis_local_var->kz_81 = kz_81;
    ustva_ergebnis_local_var->kz_83 = kz_83;
    ustva_ergebnis_local_var->kz_84 = kz_84;
    ustva_ergebnis_local_var->kz_85 = kz_85;
    ustva_ergebnis_local_var->kz_86 = kz_86;
    ustva_ergebnis_local_var->kz_88 = kz_88;
    ustva_ergebnis_local_var->kz_89 = kz_89;
    ustva_ergebnis_local_var->kz_93 = kz_93;
    ustva_ergebnis_local_var->von = von;
    ustva_ergebnis_local_var->zahllast = zahllast;
    ustva_ergebnis_local_var->zeitraum = zeitraum;
    ustva_ergebnis_local_var->zeitraum_typ = zeitraum_typ;
    return ustva_ergebnis_local_var;
}

__attribute__((deprecated)) ustva_ergebnis_t *ustva_ergebnis_create(
    char *bis,
    char *hinweis,
    int *ist_kleinunternehmer,
    char *kz_41,
    char *kz_43,
    char *kz_46,
    char *kz_47,
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
    char *von,
    char *zahllast,
    char *zeitraum,
    char *zeitraum_typ
    ) {
    int *ist_kleinunternehmer_copy = NULL;
    if (ist_kleinunternehmer) {
        ist_kleinunternehmer_copy = malloc(sizeof(int));
        if (ist_kleinunternehmer_copy) *ist_kleinunternehmer_copy = *ist_kleinunternehmer;
    }
    ustva_ergebnis_t *result = ustva_ergebnis_create_internal (
        bis,
        hinweis,
        ist_kleinunternehmer_copy,
        kz_41,
        kz_43,
        kz_46,
        kz_47,
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
        von,
        zahllast,
        zeitraum,
        zeitraum_typ
        );
    if (!result) {
        free(ist_kleinunternehmer_copy);
    }
    return result;
}

void ustva_ergebnis_free(ustva_ergebnis_t *ustva_ergebnis) {
    if(NULL == ustva_ergebnis){
        return ;
    }
    if(ustva_ergebnis->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ustva_ergebnis_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ustva_ergebnis->bis) {
        free(ustva_ergebnis->bis);
        ustva_ergebnis->bis = NULL;
    }
    if (ustva_ergebnis->hinweis) {
        free(ustva_ergebnis->hinweis);
        ustva_ergebnis->hinweis = NULL;
    }
    if (ustva_ergebnis->ist_kleinunternehmer) {
        free(ustva_ergebnis->ist_kleinunternehmer);
        ustva_ergebnis->ist_kleinunternehmer = NULL;
    }
    if (ustva_ergebnis->kz_41) {
        free(ustva_ergebnis->kz_41);
        ustva_ergebnis->kz_41 = NULL;
    }
    if (ustva_ergebnis->kz_43) {
        free(ustva_ergebnis->kz_43);
        ustva_ergebnis->kz_43 = NULL;
    }
    if (ustva_ergebnis->kz_46) {
        free(ustva_ergebnis->kz_46);
        ustva_ergebnis->kz_46 = NULL;
    }
    if (ustva_ergebnis->kz_47) {
        free(ustva_ergebnis->kz_47);
        ustva_ergebnis->kz_47 = NULL;
    }
    if (ustva_ergebnis->kz_61) {
        free(ustva_ergebnis->kz_61);
        ustva_ergebnis->kz_61 = NULL;
    }
    if (ustva_ergebnis->kz_66) {
        free(ustva_ergebnis->kz_66);
        ustva_ergebnis->kz_66 = NULL;
    }
    if (ustva_ergebnis->kz_67) {
        free(ustva_ergebnis->kz_67);
        ustva_ergebnis->kz_67 = NULL;
    }
    if (ustva_ergebnis->kz_81) {
        free(ustva_ergebnis->kz_81);
        ustva_ergebnis->kz_81 = NULL;
    }
    if (ustva_ergebnis->kz_83) {
        free(ustva_ergebnis->kz_83);
        ustva_ergebnis->kz_83 = NULL;
    }
    if (ustva_ergebnis->kz_84) {
        free(ustva_ergebnis->kz_84);
        ustva_ergebnis->kz_84 = NULL;
    }
    if (ustva_ergebnis->kz_85) {
        free(ustva_ergebnis->kz_85);
        ustva_ergebnis->kz_85 = NULL;
    }
    if (ustva_ergebnis->kz_86) {
        free(ustva_ergebnis->kz_86);
        ustva_ergebnis->kz_86 = NULL;
    }
    if (ustva_ergebnis->kz_88) {
        free(ustva_ergebnis->kz_88);
        ustva_ergebnis->kz_88 = NULL;
    }
    if (ustva_ergebnis->kz_89) {
        free(ustva_ergebnis->kz_89);
        ustva_ergebnis->kz_89 = NULL;
    }
    if (ustva_ergebnis->kz_93) {
        free(ustva_ergebnis->kz_93);
        ustva_ergebnis->kz_93 = NULL;
    }
    if (ustva_ergebnis->von) {
        free(ustva_ergebnis->von);
        ustva_ergebnis->von = NULL;
    }
    if (ustva_ergebnis->zahllast) {
        free(ustva_ergebnis->zahllast);
        ustva_ergebnis->zahllast = NULL;
    }
    if (ustva_ergebnis->zeitraum) {
        free(ustva_ergebnis->zeitraum);
        ustva_ergebnis->zeitraum = NULL;
    }
    if (ustva_ergebnis->zeitraum_typ) {
        free(ustva_ergebnis->zeitraum_typ);
        ustva_ergebnis->zeitraum_typ = NULL;
    }
    free(ustva_ergebnis);
}

cJSON *ustva_ergebnis_convertToJSON(ustva_ergebnis_t *ustva_ergebnis) {
    cJSON *item = cJSON_CreateObject();

    // ustva_ergebnis->bis
    if (!ustva_ergebnis->bis) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "bis", ustva_ergebnis->bis) == NULL) {
    goto fail; //String
    }


    // ustva_ergebnis->hinweis
    if(ustva_ergebnis->hinweis) {
    if(cJSON_AddStringToObject(item, "hinweis", ustva_ergebnis->hinweis) == NULL) {
    goto fail; //String
    }
    }


    // ustva_ergebnis->ist_kleinunternehmer
    if (!ustva_ergebnis->ist_kleinunternehmer) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ist_kleinunternehmer", *ustva_ergebnis->ist_kleinunternehmer) == NULL) {
    goto fail; //Bool
    }


    // ustva_ergebnis->kz_41
    if (!ustva_ergebnis->kz_41) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_41", ustva_ergebnis->kz_41) == NULL) {
    goto fail; //String
    }


    // ustva_ergebnis->kz_43
    if (!ustva_ergebnis->kz_43) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_43", ustva_ergebnis->kz_43) == NULL) {
    goto fail; //String
    }


    // ustva_ergebnis->kz_46
    if (!ustva_ergebnis->kz_46) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_46", ustva_ergebnis->kz_46) == NULL) {
    goto fail; //String
    }


    // ustva_ergebnis->kz_47
    if (!ustva_ergebnis->kz_47) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_47", ustva_ergebnis->kz_47) == NULL) {
    goto fail; //String
    }


    // ustva_ergebnis->kz_61
    if (!ustva_ergebnis->kz_61) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_61", ustva_ergebnis->kz_61) == NULL) {
    goto fail; //String
    }


    // ustva_ergebnis->kz_66
    if (!ustva_ergebnis->kz_66) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_66", ustva_ergebnis->kz_66) == NULL) {
    goto fail; //String
    }


    // ustva_ergebnis->kz_67
    if (!ustva_ergebnis->kz_67) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_67", ustva_ergebnis->kz_67) == NULL) {
    goto fail; //String
    }


    // ustva_ergebnis->kz_81
    if (!ustva_ergebnis->kz_81) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_81", ustva_ergebnis->kz_81) == NULL) {
    goto fail; //String
    }


    // ustva_ergebnis->kz_83
    if (!ustva_ergebnis->kz_83) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_83", ustva_ergebnis->kz_83) == NULL) {
    goto fail; //String
    }


    // ustva_ergebnis->kz_84
    if (!ustva_ergebnis->kz_84) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_84", ustva_ergebnis->kz_84) == NULL) {
    goto fail; //String
    }


    // ustva_ergebnis->kz_85
    if (!ustva_ergebnis->kz_85) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_85", ustva_ergebnis->kz_85) == NULL) {
    goto fail; //String
    }


    // ustva_ergebnis->kz_86
    if (!ustva_ergebnis->kz_86) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_86", ustva_ergebnis->kz_86) == NULL) {
    goto fail; //String
    }


    // ustva_ergebnis->kz_88
    if (!ustva_ergebnis->kz_88) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_88", ustva_ergebnis->kz_88) == NULL) {
    goto fail; //String
    }


    // ustva_ergebnis->kz_89
    if (!ustva_ergebnis->kz_89) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_89", ustva_ergebnis->kz_89) == NULL) {
    goto fail; //String
    }


    // ustva_ergebnis->kz_93
    if (!ustva_ergebnis->kz_93) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kz_93", ustva_ergebnis->kz_93) == NULL) {
    goto fail; //String
    }


    // ustva_ergebnis->von
    if (!ustva_ergebnis->von) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "von", ustva_ergebnis->von) == NULL) {
    goto fail; //String
    }


    // ustva_ergebnis->zahllast
    if (!ustva_ergebnis->zahllast) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "zahllast", ustva_ergebnis->zahllast) == NULL) {
    goto fail; //String
    }


    // ustva_ergebnis->zeitraum
    if (!ustva_ergebnis->zeitraum) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "zeitraum", ustva_ergebnis->zeitraum) == NULL) {
    goto fail; //String
    }


    // ustva_ergebnis->zeitraum_typ
    if (!ustva_ergebnis->zeitraum_typ) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "zeitraum_typ", ustva_ergebnis->zeitraum_typ) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ustva_ergebnis_t *ustva_ergebnis_parseFromJSON(cJSON *ustva_ergebnisJSON){

    ustva_ergebnis_t *ustva_ergebnis_local_var = NULL;

    char *bis_local_str = NULL;

    char *hinweis_local_str = NULL;

    // define the local variable for ustva_ergebnis->ist_kleinunternehmer
    int *ist_kleinunternehmer_local_var = NULL;

    char *kz_41_local_str = NULL;

    char *kz_43_local_str = NULL;

    char *kz_46_local_str = NULL;

    char *kz_47_local_str = NULL;

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

    char *von_local_str = NULL;

    char *zahllast_local_str = NULL;

    char *zeitraum_local_str = NULL;

    char *zeitraum_typ_local_str = NULL;

    // ustva_ergebnis->bis
    cJSON *bis = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "bis");
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

    // ustva_ergebnis->hinweis
    cJSON *hinweis = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "hinweis");
    if (cJSON_IsNull(hinweis)) {
        hinweis = NULL;
    }
    if (hinweis) { 
    if(!cJSON_IsString(hinweis) && !cJSON_IsNull(hinweis))
    {
    goto end; //String
    }
    }

    // ustva_ergebnis->ist_kleinunternehmer
    cJSON *ist_kleinunternehmer = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "ist_kleinunternehmer");
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

    // ustva_ergebnis->kz_41
    cJSON *kz_41 = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "kz_41");
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

    // ustva_ergebnis->kz_43
    cJSON *kz_43 = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "kz_43");
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

    // ustva_ergebnis->kz_46
    cJSON *kz_46 = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "kz_46");
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

    // ustva_ergebnis->kz_47
    cJSON *kz_47 = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "kz_47");
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

    // ustva_ergebnis->kz_61
    cJSON *kz_61 = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "kz_61");
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

    // ustva_ergebnis->kz_66
    cJSON *kz_66 = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "kz_66");
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

    // ustva_ergebnis->kz_67
    cJSON *kz_67 = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "kz_67");
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

    // ustva_ergebnis->kz_81
    cJSON *kz_81 = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "kz_81");
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

    // ustva_ergebnis->kz_83
    cJSON *kz_83 = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "kz_83");
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

    // ustva_ergebnis->kz_84
    cJSON *kz_84 = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "kz_84");
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

    // ustva_ergebnis->kz_85
    cJSON *kz_85 = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "kz_85");
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

    // ustva_ergebnis->kz_86
    cJSON *kz_86 = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "kz_86");
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

    // ustva_ergebnis->kz_88
    cJSON *kz_88 = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "kz_88");
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

    // ustva_ergebnis->kz_89
    cJSON *kz_89 = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "kz_89");
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

    // ustva_ergebnis->kz_93
    cJSON *kz_93 = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "kz_93");
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

    // ustva_ergebnis->von
    cJSON *von = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "von");
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

    // ustva_ergebnis->zahllast
    cJSON *zahllast = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "zahllast");
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

    // ustva_ergebnis->zeitraum
    cJSON *zeitraum = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "zeitraum");
    if (cJSON_IsNull(zeitraum)) {
        zeitraum = NULL;
    }
    if (!zeitraum) {
        goto end;
    }

    
    if(!cJSON_IsString(zeitraum))
    {
    goto end; //String
    }

    // ustva_ergebnis->zeitraum_typ
    cJSON *zeitraum_typ = cJSON_GetObjectItemCaseSensitive(ustva_ergebnisJSON, "zeitraum_typ");
    if (cJSON_IsNull(zeitraum_typ)) {
        zeitraum_typ = NULL;
    }
    if (!zeitraum_typ) {
        goto end;
    }

    
    if(!cJSON_IsString(zeitraum_typ))
    {
    goto end; //String
    }


    if (bis && !cJSON_IsNull(bis)) bis_local_str = strdup(bis->valuestring);
    if (hinweis && !cJSON_IsNull(hinweis)) hinweis_local_str = strdup(hinweis->valuestring);
    if (kz_41 && !cJSON_IsNull(kz_41)) kz_41_local_str = strdup(kz_41->valuestring);
    if (kz_43 && !cJSON_IsNull(kz_43)) kz_43_local_str = strdup(kz_43->valuestring);
    if (kz_46 && !cJSON_IsNull(kz_46)) kz_46_local_str = strdup(kz_46->valuestring);
    if (kz_47 && !cJSON_IsNull(kz_47)) kz_47_local_str = strdup(kz_47->valuestring);
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
    if (von && !cJSON_IsNull(von)) von_local_str = strdup(von->valuestring);
    if (zahllast && !cJSON_IsNull(zahllast)) zahllast_local_str = strdup(zahllast->valuestring);
    if (zeitraum && !cJSON_IsNull(zeitraum)) zeitraum_local_str = strdup(zeitraum->valuestring);
    if (zeitraum_typ && !cJSON_IsNull(zeitraum_typ)) zeitraum_typ_local_str = strdup(zeitraum_typ->valuestring);

    ustva_ergebnis_local_var = ustva_ergebnis_create_internal (
        bis_local_str,
        hinweis_local_str,
        ist_kleinunternehmer_local_var,
        kz_41_local_str,
        kz_43_local_str,
        kz_46_local_str,
        kz_47_local_str,
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
        von_local_str,
        zahllast_local_str,
        zeitraum_local_str,
        zeitraum_typ_local_str
        );

    if (!ustva_ergebnis_local_var) {
        goto end;
    }

    return ustva_ergebnis_local_var;
end:
    if (bis_local_str) {
        free(bis_local_str);
        bis_local_str = NULL;
    }
    if (hinweis_local_str) {
        free(hinweis_local_str);
        hinweis_local_str = NULL;
    }
    if (ist_kleinunternehmer_local_var) {
        free(ist_kleinunternehmer_local_var);
        ist_kleinunternehmer_local_var = NULL;
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
    if (von_local_str) {
        free(von_local_str);
        von_local_str = NULL;
    }
    if (zahllast_local_str) {
        free(zahllast_local_str);
        zahllast_local_str = NULL;
    }
    if (zeitraum_local_str) {
        free(zeitraum_local_str);
        zeitraum_local_str = NULL;
    }
    if (zeitraum_typ_local_str) {
        free(zeitraum_typ_local_str);
        zeitraum_typ_local_str = NULL;
    }
    return NULL;

}
