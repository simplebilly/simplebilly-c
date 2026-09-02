#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "euer_kat_summe.h"



static euer_kat_summe_t *euer_kat_summe_create_internal(
    char *betrag,
    char *name
    ) {
    euer_kat_summe_t *euer_kat_summe_local_var = malloc(sizeof(euer_kat_summe_t));
    if (!euer_kat_summe_local_var) {
        return NULL;
    }
    memset(euer_kat_summe_local_var, 0, sizeof(euer_kat_summe_t));
    euer_kat_summe_local_var->_library_owned = 1;
    euer_kat_summe_local_var->betrag = betrag;
    euer_kat_summe_local_var->name = name;
    return euer_kat_summe_local_var;
}

__attribute__((deprecated)) euer_kat_summe_t *euer_kat_summe_create(
    char *betrag,
    char *name
    ) {
    euer_kat_summe_t *result = euer_kat_summe_create_internal (
        betrag,
        name
        );
    if (!result) {
    }
    return result;
}

void euer_kat_summe_free(euer_kat_summe_t *euer_kat_summe) {
    if(NULL == euer_kat_summe){
        return ;
    }
    if(euer_kat_summe->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "euer_kat_summe_free");
        return ;
    }
    listEntry_t *listEntry;
    if (euer_kat_summe->betrag) {
        free(euer_kat_summe->betrag);
        euer_kat_summe->betrag = NULL;
    }
    if (euer_kat_summe->name) {
        free(euer_kat_summe->name);
        euer_kat_summe->name = NULL;
    }
    free(euer_kat_summe);
}

cJSON *euer_kat_summe_convertToJSON(euer_kat_summe_t *euer_kat_summe) {
    cJSON *item = cJSON_CreateObject();

    // euer_kat_summe->betrag
    if (!euer_kat_summe->betrag) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "betrag", euer_kat_summe->betrag) == NULL) {
    goto fail; //String
    }


    // euer_kat_summe->name
    if (!euer_kat_summe->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", euer_kat_summe->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

euer_kat_summe_t *euer_kat_summe_parseFromJSON(cJSON *euer_kat_summeJSON){

    euer_kat_summe_t *euer_kat_summe_local_var = NULL;

    char *betrag_local_str = NULL;

    char *name_local_str = NULL;

    // euer_kat_summe->betrag
    cJSON *betrag = cJSON_GetObjectItemCaseSensitive(euer_kat_summeJSON, "betrag");
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

    // euer_kat_summe->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(euer_kat_summeJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    if (betrag && !cJSON_IsNull(betrag)) betrag_local_str = strdup(betrag->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    euer_kat_summe_local_var = euer_kat_summe_create_internal (
        betrag_local_str,
        name_local_str
        );

    if (!euer_kat_summe_local_var) {
        goto end;
    }

    return euer_kat_summe_local_var;
end:
    if (betrag_local_str) {
        free(betrag_local_str);
        betrag_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    return NULL;

}
