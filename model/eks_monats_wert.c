#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "eks_monats_wert.h"



static eks_monats_wert_t *eks_monats_wert_create_internal(
    char *ausgaben,
    char *einnahmen,
    char *ergebnis,
    char *monat
    ) {
    eks_monats_wert_t *eks_monats_wert_local_var = malloc(sizeof(eks_monats_wert_t));
    if (!eks_monats_wert_local_var) {
        return NULL;
    }
    memset(eks_monats_wert_local_var, 0, sizeof(eks_monats_wert_t));
    eks_monats_wert_local_var->_library_owned = 1;
    eks_monats_wert_local_var->ausgaben = ausgaben;
    eks_monats_wert_local_var->einnahmen = einnahmen;
    eks_monats_wert_local_var->ergebnis = ergebnis;
    eks_monats_wert_local_var->monat = monat;
    return eks_monats_wert_local_var;
}

__attribute__((deprecated)) eks_monats_wert_t *eks_monats_wert_create(
    char *ausgaben,
    char *einnahmen,
    char *ergebnis,
    char *monat
    ) {
    eks_monats_wert_t *result = eks_monats_wert_create_internal (
        ausgaben,
        einnahmen,
        ergebnis,
        monat
        );
    if (!result) {
    }
    return result;
}

void eks_monats_wert_free(eks_monats_wert_t *eks_monats_wert) {
    if(NULL == eks_monats_wert){
        return ;
    }
    if(eks_monats_wert->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "eks_monats_wert_free");
        return ;
    }
    listEntry_t *listEntry;
    if (eks_monats_wert->ausgaben) {
        free(eks_monats_wert->ausgaben);
        eks_monats_wert->ausgaben = NULL;
    }
    if (eks_monats_wert->einnahmen) {
        free(eks_monats_wert->einnahmen);
        eks_monats_wert->einnahmen = NULL;
    }
    if (eks_monats_wert->ergebnis) {
        free(eks_monats_wert->ergebnis);
        eks_monats_wert->ergebnis = NULL;
    }
    if (eks_monats_wert->monat) {
        free(eks_monats_wert->monat);
        eks_monats_wert->monat = NULL;
    }
    free(eks_monats_wert);
}

cJSON *eks_monats_wert_convertToJSON(eks_monats_wert_t *eks_monats_wert) {
    cJSON *item = cJSON_CreateObject();

    // eks_monats_wert->ausgaben
    if (!eks_monats_wert->ausgaben) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ausgaben", eks_monats_wert->ausgaben) == NULL) {
    goto fail; //String
    }


    // eks_monats_wert->einnahmen
    if (!eks_monats_wert->einnahmen) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "einnahmen", eks_monats_wert->einnahmen) == NULL) {
    goto fail; //String
    }


    // eks_monats_wert->ergebnis
    if (!eks_monats_wert->ergebnis) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ergebnis", eks_monats_wert->ergebnis) == NULL) {
    goto fail; //String
    }


    // eks_monats_wert->monat
    if (!eks_monats_wert->monat) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "monat", eks_monats_wert->monat) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

eks_monats_wert_t *eks_monats_wert_parseFromJSON(cJSON *eks_monats_wertJSON){

    eks_monats_wert_t *eks_monats_wert_local_var = NULL;

    char *ausgaben_local_str = NULL;

    char *einnahmen_local_str = NULL;

    char *ergebnis_local_str = NULL;

    char *monat_local_str = NULL;

    // eks_monats_wert->ausgaben
    cJSON *ausgaben = cJSON_GetObjectItemCaseSensitive(eks_monats_wertJSON, "ausgaben");
    if (cJSON_IsNull(ausgaben)) {
        ausgaben = NULL;
    }
    if (!ausgaben) {
        goto end;
    }

    
    if(!cJSON_IsString(ausgaben))
    {
    goto end; //String
    }

    // eks_monats_wert->einnahmen
    cJSON *einnahmen = cJSON_GetObjectItemCaseSensitive(eks_monats_wertJSON, "einnahmen");
    if (cJSON_IsNull(einnahmen)) {
        einnahmen = NULL;
    }
    if (!einnahmen) {
        goto end;
    }

    
    if(!cJSON_IsString(einnahmen))
    {
    goto end; //String
    }

    // eks_monats_wert->ergebnis
    cJSON *ergebnis = cJSON_GetObjectItemCaseSensitive(eks_monats_wertJSON, "ergebnis");
    if (cJSON_IsNull(ergebnis)) {
        ergebnis = NULL;
    }
    if (!ergebnis) {
        goto end;
    }

    
    if(!cJSON_IsString(ergebnis))
    {
    goto end; //String
    }

    // eks_monats_wert->monat
    cJSON *monat = cJSON_GetObjectItemCaseSensitive(eks_monats_wertJSON, "monat");
    if (cJSON_IsNull(monat)) {
        monat = NULL;
    }
    if (!monat) {
        goto end;
    }

    
    if(!cJSON_IsString(monat))
    {
    goto end; //String
    }


    if (ausgaben && !cJSON_IsNull(ausgaben)) ausgaben_local_str = strdup(ausgaben->valuestring);
    if (einnahmen && !cJSON_IsNull(einnahmen)) einnahmen_local_str = strdup(einnahmen->valuestring);
    if (ergebnis && !cJSON_IsNull(ergebnis)) ergebnis_local_str = strdup(ergebnis->valuestring);
    if (monat && !cJSON_IsNull(monat)) monat_local_str = strdup(monat->valuestring);

    eks_monats_wert_local_var = eks_monats_wert_create_internal (
        ausgaben_local_str,
        einnahmen_local_str,
        ergebnis_local_str,
        monat_local_str
        );

    if (!eks_monats_wert_local_var) {
        goto end;
    }

    return eks_monats_wert_local_var;
end:
    if (ausgaben_local_str) {
        free(ausgaben_local_str);
        ausgaben_local_str = NULL;
    }
    if (einnahmen_local_str) {
        free(einnahmen_local_str);
        einnahmen_local_str = NULL;
    }
    if (ergebnis_local_str) {
        free(ergebnis_local_str);
        ergebnis_local_str = NULL;
    }
    if (monat_local_str) {
        free(monat_local_str);
        monat_local_str = NULL;
    }
    return NULL;

}
