#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "frist_eintrag.h"



static frist_eintrag_t *frist_eintrag_create_internal(
    char *bezeichnung,
    char *faellig,
    char *faellig_original,
    char *hinweis,
    char *typ,
    char *zeitraum
    ) {
    frist_eintrag_t *frist_eintrag_local_var = malloc(sizeof(frist_eintrag_t));
    if (!frist_eintrag_local_var) {
        return NULL;
    }
    memset(frist_eintrag_local_var, 0, sizeof(frist_eintrag_t));
    frist_eintrag_local_var->_library_owned = 1;
    frist_eintrag_local_var->bezeichnung = bezeichnung;
    frist_eintrag_local_var->faellig = faellig;
    frist_eintrag_local_var->faellig_original = faellig_original;
    frist_eintrag_local_var->hinweis = hinweis;
    frist_eintrag_local_var->typ = typ;
    frist_eintrag_local_var->zeitraum = zeitraum;
    return frist_eintrag_local_var;
}

__attribute__((deprecated)) frist_eintrag_t *frist_eintrag_create(
    char *bezeichnung,
    char *faellig,
    char *faellig_original,
    char *hinweis,
    char *typ,
    char *zeitraum
    ) {
    frist_eintrag_t *result = frist_eintrag_create_internal (
        bezeichnung,
        faellig,
        faellig_original,
        hinweis,
        typ,
        zeitraum
        );
    if (!result) {
    }
    return result;
}

void frist_eintrag_free(frist_eintrag_t *frist_eintrag) {
    if(NULL == frist_eintrag){
        return ;
    }
    if(frist_eintrag->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "frist_eintrag_free");
        return ;
    }
    listEntry_t *listEntry;
    if (frist_eintrag->bezeichnung) {
        free(frist_eintrag->bezeichnung);
        frist_eintrag->bezeichnung = NULL;
    }
    if (frist_eintrag->faellig) {
        free(frist_eintrag->faellig);
        frist_eintrag->faellig = NULL;
    }
    if (frist_eintrag->faellig_original) {
        free(frist_eintrag->faellig_original);
        frist_eintrag->faellig_original = NULL;
    }
    if (frist_eintrag->hinweis) {
        free(frist_eintrag->hinweis);
        frist_eintrag->hinweis = NULL;
    }
    if (frist_eintrag->typ) {
        free(frist_eintrag->typ);
        frist_eintrag->typ = NULL;
    }
    if (frist_eintrag->zeitraum) {
        free(frist_eintrag->zeitraum);
        frist_eintrag->zeitraum = NULL;
    }
    free(frist_eintrag);
}

cJSON *frist_eintrag_convertToJSON(frist_eintrag_t *frist_eintrag) {
    cJSON *item = cJSON_CreateObject();

    // frist_eintrag->bezeichnung
    if (!frist_eintrag->bezeichnung) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "bezeichnung", frist_eintrag->bezeichnung) == NULL) {
    goto fail; //String
    }


    // frist_eintrag->faellig
    if (!frist_eintrag->faellig) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "faellig", frist_eintrag->faellig) == NULL) {
    goto fail; //String
    }


    // frist_eintrag->faellig_original
    if (!frist_eintrag->faellig_original) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "faellig_original", frist_eintrag->faellig_original) == NULL) {
    goto fail; //String
    }


    // frist_eintrag->hinweis
    if(frist_eintrag->hinweis) {
    if(cJSON_AddStringToObject(item, "hinweis", frist_eintrag->hinweis) == NULL) {
    goto fail; //String
    }
    }


    // frist_eintrag->typ
    if (!frist_eintrag->typ) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "typ", frist_eintrag->typ) == NULL) {
    goto fail; //String
    }


    // frist_eintrag->zeitraum
    if (!frist_eintrag->zeitraum) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "zeitraum", frist_eintrag->zeitraum) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

frist_eintrag_t *frist_eintrag_parseFromJSON(cJSON *frist_eintragJSON){

    frist_eintrag_t *frist_eintrag_local_var = NULL;

    char *bezeichnung_local_str = NULL;

    char *faellig_local_str = NULL;

    char *faellig_original_local_str = NULL;

    char *hinweis_local_str = NULL;

    char *typ_local_str = NULL;

    char *zeitraum_local_str = NULL;

    // frist_eintrag->bezeichnung
    cJSON *bezeichnung = cJSON_GetObjectItemCaseSensitive(frist_eintragJSON, "bezeichnung");
    if (cJSON_IsNull(bezeichnung)) {
        bezeichnung = NULL;
    }
    if (!bezeichnung) {
        goto end;
    }

    
    if(!cJSON_IsString(bezeichnung))
    {
    goto end; //String
    }

    // frist_eintrag->faellig
    cJSON *faellig = cJSON_GetObjectItemCaseSensitive(frist_eintragJSON, "faellig");
    if (cJSON_IsNull(faellig)) {
        faellig = NULL;
    }
    if (!faellig) {
        goto end;
    }

    
    if(!cJSON_IsString(faellig))
    {
    goto end; //String
    }

    // frist_eintrag->faellig_original
    cJSON *faellig_original = cJSON_GetObjectItemCaseSensitive(frist_eintragJSON, "faellig_original");
    if (cJSON_IsNull(faellig_original)) {
        faellig_original = NULL;
    }
    if (!faellig_original) {
        goto end;
    }

    
    if(!cJSON_IsString(faellig_original))
    {
    goto end; //String
    }

    // frist_eintrag->hinweis
    cJSON *hinweis = cJSON_GetObjectItemCaseSensitive(frist_eintragJSON, "hinweis");
    if (cJSON_IsNull(hinweis)) {
        hinweis = NULL;
    }
    if (hinweis) { 
    if(!cJSON_IsString(hinweis) && !cJSON_IsNull(hinweis))
    {
    goto end; //String
    }
    }

    // frist_eintrag->typ
    cJSON *typ = cJSON_GetObjectItemCaseSensitive(frist_eintragJSON, "typ");
    if (cJSON_IsNull(typ)) {
        typ = NULL;
    }
    if (!typ) {
        goto end;
    }

    
    if(!cJSON_IsString(typ))
    {
    goto end; //String
    }

    // frist_eintrag->zeitraum
    cJSON *zeitraum = cJSON_GetObjectItemCaseSensitive(frist_eintragJSON, "zeitraum");
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


    if (bezeichnung && !cJSON_IsNull(bezeichnung)) bezeichnung_local_str = strdup(bezeichnung->valuestring);
    if (faellig && !cJSON_IsNull(faellig)) faellig_local_str = strdup(faellig->valuestring);
    if (faellig_original && !cJSON_IsNull(faellig_original)) faellig_original_local_str = strdup(faellig_original->valuestring);
    if (hinweis && !cJSON_IsNull(hinweis)) hinweis_local_str = strdup(hinweis->valuestring);
    if (typ && !cJSON_IsNull(typ)) typ_local_str = strdup(typ->valuestring);
    if (zeitraum && !cJSON_IsNull(zeitraum)) zeitraum_local_str = strdup(zeitraum->valuestring);

    frist_eintrag_local_var = frist_eintrag_create_internal (
        bezeichnung_local_str,
        faellig_local_str,
        faellig_original_local_str,
        hinweis_local_str,
        typ_local_str,
        zeitraum_local_str
        );

    if (!frist_eintrag_local_var) {
        goto end;
    }

    return frist_eintrag_local_var;
end:
    if (bezeichnung_local_str) {
        free(bezeichnung_local_str);
        bezeichnung_local_str = NULL;
    }
    if (faellig_local_str) {
        free(faellig_local_str);
        faellig_local_str = NULL;
    }
    if (faellig_original_local_str) {
        free(faellig_original_local_str);
        faellig_original_local_str = NULL;
    }
    if (hinweis_local_str) {
        free(hinweis_local_str);
        hinweis_local_str = NULL;
    }
    if (typ_local_str) {
        free(typ_local_str);
        typ_local_str = NULL;
    }
    if (zeitraum_local_str) {
        free(zeitraum_local_str);
        zeitraum_local_str = NULL;
    }
    return NULL;

}
