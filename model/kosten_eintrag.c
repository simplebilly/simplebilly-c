#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "kosten_eintrag.h"



static kosten_eintrag_t *kosten_eintrag_create_internal(
    char *beschreibung,
    char *betrag,
    char *datum,
    char *typ
    ) {
    kosten_eintrag_t *kosten_eintrag_local_var = malloc(sizeof(kosten_eintrag_t));
    if (!kosten_eintrag_local_var) {
        return NULL;
    }
    memset(kosten_eintrag_local_var, 0, sizeof(kosten_eintrag_t));
    kosten_eintrag_local_var->_library_owned = 1;
    kosten_eintrag_local_var->beschreibung = beschreibung;
    kosten_eintrag_local_var->betrag = betrag;
    kosten_eintrag_local_var->datum = datum;
    kosten_eintrag_local_var->typ = typ;
    return kosten_eintrag_local_var;
}

__attribute__((deprecated)) kosten_eintrag_t *kosten_eintrag_create(
    char *beschreibung,
    char *betrag,
    char *datum,
    char *typ
    ) {
    kosten_eintrag_t *result = kosten_eintrag_create_internal (
        beschreibung,
        betrag,
        datum,
        typ
        );
    if (!result) {
    }
    return result;
}

void kosten_eintrag_free(kosten_eintrag_t *kosten_eintrag) {
    if(NULL == kosten_eintrag){
        return ;
    }
    if(kosten_eintrag->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "kosten_eintrag_free");
        return ;
    }
    listEntry_t *listEntry;
    if (kosten_eintrag->beschreibung) {
        free(kosten_eintrag->beschreibung);
        kosten_eintrag->beschreibung = NULL;
    }
    if (kosten_eintrag->betrag) {
        free(kosten_eintrag->betrag);
        kosten_eintrag->betrag = NULL;
    }
    if (kosten_eintrag->datum) {
        free(kosten_eintrag->datum);
        kosten_eintrag->datum = NULL;
    }
    if (kosten_eintrag->typ) {
        free(kosten_eintrag->typ);
        kosten_eintrag->typ = NULL;
    }
    free(kosten_eintrag);
}

cJSON *kosten_eintrag_convertToJSON(kosten_eintrag_t *kosten_eintrag) {
    cJSON *item = cJSON_CreateObject();

    // kosten_eintrag->beschreibung
    if (!kosten_eintrag->beschreibung) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "beschreibung", kosten_eintrag->beschreibung) == NULL) {
    goto fail; //String
    }


    // kosten_eintrag->betrag
    if (!kosten_eintrag->betrag) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "betrag", kosten_eintrag->betrag) == NULL) {
    goto fail; //String
    }


    // kosten_eintrag->datum
    if (!kosten_eintrag->datum) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "datum", kosten_eintrag->datum) == NULL) {
    goto fail; //String
    }


    // kosten_eintrag->typ
    if (!kosten_eintrag->typ) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "typ", kosten_eintrag->typ) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

kosten_eintrag_t *kosten_eintrag_parseFromJSON(cJSON *kosten_eintragJSON){

    kosten_eintrag_t *kosten_eintrag_local_var = NULL;

    char *beschreibung_local_str = NULL;

    char *betrag_local_str = NULL;

    char *datum_local_str = NULL;

    char *typ_local_str = NULL;

    // kosten_eintrag->beschreibung
    cJSON *beschreibung = cJSON_GetObjectItemCaseSensitive(kosten_eintragJSON, "beschreibung");
    if (cJSON_IsNull(beschreibung)) {
        beschreibung = NULL;
    }
    if (!beschreibung) {
        goto end;
    }

    
    if(!cJSON_IsString(beschreibung))
    {
    goto end; //String
    }

    // kosten_eintrag->betrag
    cJSON *betrag = cJSON_GetObjectItemCaseSensitive(kosten_eintragJSON, "betrag");
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

    // kosten_eintrag->datum
    cJSON *datum = cJSON_GetObjectItemCaseSensitive(kosten_eintragJSON, "datum");
    if (cJSON_IsNull(datum)) {
        datum = NULL;
    }
    if (!datum) {
        goto end;
    }

    
    if(!cJSON_IsString(datum))
    {
    goto end; //String
    }

    // kosten_eintrag->typ
    cJSON *typ = cJSON_GetObjectItemCaseSensitive(kosten_eintragJSON, "typ");
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


    if (beschreibung && !cJSON_IsNull(beschreibung)) beschreibung_local_str = strdup(beschreibung->valuestring);
    if (betrag && !cJSON_IsNull(betrag)) betrag_local_str = strdup(betrag->valuestring);
    if (datum && !cJSON_IsNull(datum)) datum_local_str = strdup(datum->valuestring);
    if (typ && !cJSON_IsNull(typ)) typ_local_str = strdup(typ->valuestring);

    kosten_eintrag_local_var = kosten_eintrag_create_internal (
        beschreibung_local_str,
        betrag_local_str,
        datum_local_str,
        typ_local_str
        );

    if (!kosten_eintrag_local_var) {
        goto end;
    }

    return kosten_eintrag_local_var;
end:
    if (beschreibung_local_str) {
        free(beschreibung_local_str);
        beschreibung_local_str = NULL;
    }
    if (betrag_local_str) {
        free(betrag_local_str);
        betrag_local_str = NULL;
    }
    if (datum_local_str) {
        free(datum_local_str);
        datum_local_str = NULL;
    }
    if (typ_local_str) {
        free(typ_local_str);
        typ_local_str = NULL;
    }
    return NULL;

}
