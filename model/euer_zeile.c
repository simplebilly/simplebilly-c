#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "euer_zeile.h"



static euer_zeile_t *euer_zeile_create_internal(
    char *abschnitt,
    char *betrag,
    char *bezeichnung,
    int *zeile
    ) {
    euer_zeile_t *euer_zeile_local_var = malloc(sizeof(euer_zeile_t));
    if (!euer_zeile_local_var) {
        return NULL;
    }
    memset(euer_zeile_local_var, 0, sizeof(euer_zeile_t));
    euer_zeile_local_var->_library_owned = 1;
    euer_zeile_local_var->abschnitt = abschnitt;
    euer_zeile_local_var->betrag = betrag;
    euer_zeile_local_var->bezeichnung = bezeichnung;
    euer_zeile_local_var->zeile = zeile;
    return euer_zeile_local_var;
}

__attribute__((deprecated)) euer_zeile_t *euer_zeile_create(
    char *abschnitt,
    char *betrag,
    char *bezeichnung,
    int *zeile
    ) {
    int *zeile_copy = NULL;
    if (zeile) {
        zeile_copy = malloc(sizeof(int));
        if (zeile_copy) *zeile_copy = *zeile;
    }
    euer_zeile_t *result = euer_zeile_create_internal (
        abschnitt,
        betrag,
        bezeichnung,
        zeile_copy
        );
    if (!result) {
        free(zeile_copy);
    }
    return result;
}

void euer_zeile_free(euer_zeile_t *euer_zeile) {
    if(NULL == euer_zeile){
        return ;
    }
    if(euer_zeile->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "euer_zeile_free");
        return ;
    }
    listEntry_t *listEntry;
    if (euer_zeile->abschnitt) {
        free(euer_zeile->abschnitt);
        euer_zeile->abschnitt = NULL;
    }
    if (euer_zeile->betrag) {
        free(euer_zeile->betrag);
        euer_zeile->betrag = NULL;
    }
    if (euer_zeile->bezeichnung) {
        free(euer_zeile->bezeichnung);
        euer_zeile->bezeichnung = NULL;
    }
    if (euer_zeile->zeile) {
        free(euer_zeile->zeile);
        euer_zeile->zeile = NULL;
    }
    free(euer_zeile);
}

cJSON *euer_zeile_convertToJSON(euer_zeile_t *euer_zeile) {
    cJSON *item = cJSON_CreateObject();

    // euer_zeile->abschnitt
    if (!euer_zeile->abschnitt) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "abschnitt", euer_zeile->abschnitt) == NULL) {
    goto fail; //String
    }


    // euer_zeile->betrag
    if (!euer_zeile->betrag) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "betrag", euer_zeile->betrag) == NULL) {
    goto fail; //String
    }


    // euer_zeile->bezeichnung
    if (!euer_zeile->bezeichnung) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "bezeichnung", euer_zeile->bezeichnung) == NULL) {
    goto fail; //String
    }


    // euer_zeile->zeile
    if (!euer_zeile->zeile) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "zeile", *euer_zeile->zeile) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

euer_zeile_t *euer_zeile_parseFromJSON(cJSON *euer_zeileJSON){

    euer_zeile_t *euer_zeile_local_var = NULL;

    char *abschnitt_local_str = NULL;

    char *betrag_local_str = NULL;

    char *bezeichnung_local_str = NULL;

    // define the local variable for euer_zeile->zeile
    int *zeile_local_var = NULL;

    // euer_zeile->abschnitt
    cJSON *abschnitt = cJSON_GetObjectItemCaseSensitive(euer_zeileJSON, "abschnitt");
    if (cJSON_IsNull(abschnitt)) {
        abschnitt = NULL;
    }
    if (!abschnitt) {
        goto end;
    }

    
    if(!cJSON_IsString(abschnitt))
    {
    goto end; //String
    }

    // euer_zeile->betrag
    cJSON *betrag = cJSON_GetObjectItemCaseSensitive(euer_zeileJSON, "betrag");
    if (cJSON_IsNull(betrag)) {
        betrag = NULL;
    }
    if (!betrag) {
        goto end;
    }

    
    if(!cJSON_IsString(betrag))
    {
    goto end; //String
    }

    // euer_zeile->bezeichnung
    cJSON *bezeichnung = cJSON_GetObjectItemCaseSensitive(euer_zeileJSON, "bezeichnung");
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

    // euer_zeile->zeile
    cJSON *zeile = cJSON_GetObjectItemCaseSensitive(euer_zeileJSON, "zeile");
    if (cJSON_IsNull(zeile)) {
        zeile = NULL;
    }
    if (!zeile) {
        goto end;
    }

    
    if(!cJSON_IsNumber(zeile))
    {
    goto end; //Numeric
    }
    zeile_local_var = malloc(sizeof(int));
    if(!zeile_local_var)
    {
        goto end;
    }
    *zeile_local_var = zeile->valuedouble;


    if (abschnitt && !cJSON_IsNull(abschnitt)) abschnitt_local_str = strdup(abschnitt->valuestring);
    if (betrag && !cJSON_IsNull(betrag)) betrag_local_str = strdup(betrag->valuestring);
    if (bezeichnung && !cJSON_IsNull(bezeichnung)) bezeichnung_local_str = strdup(bezeichnung->valuestring);

    euer_zeile_local_var = euer_zeile_create_internal (
        abschnitt_local_str,
        betrag_local_str,
        bezeichnung_local_str,
        zeile_local_var
        );

    if (!euer_zeile_local_var) {
        goto end;
    }

    return euer_zeile_local_var;
end:
    if (abschnitt_local_str) {
        free(abschnitt_local_str);
        abschnitt_local_str = NULL;
    }
    if (betrag_local_str) {
        free(betrag_local_str);
        betrag_local_str = NULL;
    }
    if (bezeichnung_local_str) {
        free(bezeichnung_local_str);
        bezeichnung_local_str = NULL;
    }
    if (zeile_local_var) {
        free(zeile_local_var);
        zeile_local_var = NULL;
    }
    return NULL;

}
