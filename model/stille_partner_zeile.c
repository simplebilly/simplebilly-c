#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stille_partner_zeile.h"



static stille_partner_zeile_t *stille_partner_zeile_create_internal(
    char *auseinandersetzungsguthaben,
    char *gewinnanteil,
    char *gewinnvortrag,
    char *hinweis,
    char *instrument_type,
    char *kest,
    char *name,
    char *verlust_verrechnungskonto,
    char *verlustanteil
    ) {
    stille_partner_zeile_t *stille_partner_zeile_local_var = malloc(sizeof(stille_partner_zeile_t));
    if (!stille_partner_zeile_local_var) {
        return NULL;
    }
    memset(stille_partner_zeile_local_var, 0, sizeof(stille_partner_zeile_t));
    stille_partner_zeile_local_var->_library_owned = 1;
    stille_partner_zeile_local_var->auseinandersetzungsguthaben = auseinandersetzungsguthaben;
    stille_partner_zeile_local_var->gewinnanteil = gewinnanteil;
    stille_partner_zeile_local_var->gewinnvortrag = gewinnvortrag;
    stille_partner_zeile_local_var->hinweis = hinweis;
    stille_partner_zeile_local_var->instrument_type = instrument_type;
    stille_partner_zeile_local_var->kest = kest;
    stille_partner_zeile_local_var->name = name;
    stille_partner_zeile_local_var->verlust_verrechnungskonto = verlust_verrechnungskonto;
    stille_partner_zeile_local_var->verlustanteil = verlustanteil;
    return stille_partner_zeile_local_var;
}

__attribute__((deprecated)) stille_partner_zeile_t *stille_partner_zeile_create(
    char *auseinandersetzungsguthaben,
    char *gewinnanteil,
    char *gewinnvortrag,
    char *hinweis,
    char *instrument_type,
    char *kest,
    char *name,
    char *verlust_verrechnungskonto,
    char *verlustanteil
    ) {
    stille_partner_zeile_t *result = stille_partner_zeile_create_internal (
        auseinandersetzungsguthaben,
        gewinnanteil,
        gewinnvortrag,
        hinweis,
        instrument_type,
        kest,
        name,
        verlust_verrechnungskonto,
        verlustanteil
        );
    if (!result) {
    }
    return result;
}

void stille_partner_zeile_free(stille_partner_zeile_t *stille_partner_zeile) {
    if(NULL == stille_partner_zeile){
        return ;
    }
    if(stille_partner_zeile->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "stille_partner_zeile_free");
        return ;
    }
    listEntry_t *listEntry;
    if (stille_partner_zeile->auseinandersetzungsguthaben) {
        free(stille_partner_zeile->auseinandersetzungsguthaben);
        stille_partner_zeile->auseinandersetzungsguthaben = NULL;
    }
    if (stille_partner_zeile->gewinnanteil) {
        free(stille_partner_zeile->gewinnanteil);
        stille_partner_zeile->gewinnanteil = NULL;
    }
    if (stille_partner_zeile->gewinnvortrag) {
        free(stille_partner_zeile->gewinnvortrag);
        stille_partner_zeile->gewinnvortrag = NULL;
    }
    if (stille_partner_zeile->hinweis) {
        free(stille_partner_zeile->hinweis);
        stille_partner_zeile->hinweis = NULL;
    }
    if (stille_partner_zeile->instrument_type) {
        free(stille_partner_zeile->instrument_type);
        stille_partner_zeile->instrument_type = NULL;
    }
    if (stille_partner_zeile->kest) {
        free(stille_partner_zeile->kest);
        stille_partner_zeile->kest = NULL;
    }
    if (stille_partner_zeile->name) {
        free(stille_partner_zeile->name);
        stille_partner_zeile->name = NULL;
    }
    if (stille_partner_zeile->verlust_verrechnungskonto) {
        free(stille_partner_zeile->verlust_verrechnungskonto);
        stille_partner_zeile->verlust_verrechnungskonto = NULL;
    }
    if (stille_partner_zeile->verlustanteil) {
        free(stille_partner_zeile->verlustanteil);
        stille_partner_zeile->verlustanteil = NULL;
    }
    free(stille_partner_zeile);
}

cJSON *stille_partner_zeile_convertToJSON(stille_partner_zeile_t *stille_partner_zeile) {
    cJSON *item = cJSON_CreateObject();

    // stille_partner_zeile->auseinandersetzungsguthaben
    if (!stille_partner_zeile->auseinandersetzungsguthaben) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "auseinandersetzungsguthaben", stille_partner_zeile->auseinandersetzungsguthaben) == NULL) {
    goto fail; //String
    }


    // stille_partner_zeile->gewinnanteil
    if (!stille_partner_zeile->gewinnanteil) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gewinnanteil", stille_partner_zeile->gewinnanteil) == NULL) {
    goto fail; //String
    }


    // stille_partner_zeile->gewinnvortrag
    if (!stille_partner_zeile->gewinnvortrag) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gewinnvortrag", stille_partner_zeile->gewinnvortrag) == NULL) {
    goto fail; //String
    }


    // stille_partner_zeile->hinweis
    if(stille_partner_zeile->hinweis) {
    if(cJSON_AddStringToObject(item, "hinweis", stille_partner_zeile->hinweis) == NULL) {
    goto fail; //String
    }
    }


    // stille_partner_zeile->instrument_type
    if (!stille_partner_zeile->instrument_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "instrument_type", stille_partner_zeile->instrument_type) == NULL) {
    goto fail; //String
    }


    // stille_partner_zeile->kest
    if (!stille_partner_zeile->kest) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kest", stille_partner_zeile->kest) == NULL) {
    goto fail; //String
    }


    // stille_partner_zeile->name
    if (!stille_partner_zeile->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", stille_partner_zeile->name) == NULL) {
    goto fail; //String
    }


    // stille_partner_zeile->verlust_verrechnungskonto
    if (!stille_partner_zeile->verlust_verrechnungskonto) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "verlust_verrechnungskonto", stille_partner_zeile->verlust_verrechnungskonto) == NULL) {
    goto fail; //String
    }


    // stille_partner_zeile->verlustanteil
    if (!stille_partner_zeile->verlustanteil) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "verlustanteil", stille_partner_zeile->verlustanteil) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

stille_partner_zeile_t *stille_partner_zeile_parseFromJSON(cJSON *stille_partner_zeileJSON){

    stille_partner_zeile_t *stille_partner_zeile_local_var = NULL;

    char *auseinandersetzungsguthaben_local_str = NULL;

    char *gewinnanteil_local_str = NULL;

    char *gewinnvortrag_local_str = NULL;

    char *hinweis_local_str = NULL;

    char *instrument_type_local_str = NULL;

    char *kest_local_str = NULL;

    char *name_local_str = NULL;

    char *verlust_verrechnungskonto_local_str = NULL;

    char *verlustanteil_local_str = NULL;

    // stille_partner_zeile->auseinandersetzungsguthaben
    cJSON *auseinandersetzungsguthaben = cJSON_GetObjectItemCaseSensitive(stille_partner_zeileJSON, "auseinandersetzungsguthaben");
    if (cJSON_IsNull(auseinandersetzungsguthaben)) {
        auseinandersetzungsguthaben = NULL;
    }
    if (!auseinandersetzungsguthaben) {
        goto end;
    }

    
    if(!cJSON_IsString(auseinandersetzungsguthaben))
    {
    goto end; //String
    }

    // stille_partner_zeile->gewinnanteil
    cJSON *gewinnanteil = cJSON_GetObjectItemCaseSensitive(stille_partner_zeileJSON, "gewinnanteil");
    if (cJSON_IsNull(gewinnanteil)) {
        gewinnanteil = NULL;
    }
    if (!gewinnanteil) {
        goto end;
    }

    
    if(!cJSON_IsString(gewinnanteil))
    {
    goto end; //String
    }

    // stille_partner_zeile->gewinnvortrag
    cJSON *gewinnvortrag = cJSON_GetObjectItemCaseSensitive(stille_partner_zeileJSON, "gewinnvortrag");
    if (cJSON_IsNull(gewinnvortrag)) {
        gewinnvortrag = NULL;
    }
    if (!gewinnvortrag) {
        goto end;
    }

    
    if(!cJSON_IsString(gewinnvortrag))
    {
    goto end; //String
    }

    // stille_partner_zeile->hinweis
    cJSON *hinweis = cJSON_GetObjectItemCaseSensitive(stille_partner_zeileJSON, "hinweis");
    if (cJSON_IsNull(hinweis)) {
        hinweis = NULL;
    }
    if (hinweis) { 
    if(!cJSON_IsString(hinweis) && !cJSON_IsNull(hinweis))
    {
    goto end; //String
    }
    }

    // stille_partner_zeile->instrument_type
    cJSON *instrument_type = cJSON_GetObjectItemCaseSensitive(stille_partner_zeileJSON, "instrument_type");
    if (cJSON_IsNull(instrument_type)) {
        instrument_type = NULL;
    }
    if (!instrument_type) {
        goto end;
    }

    
    if(!cJSON_IsString(instrument_type))
    {
    goto end; //String
    }

    // stille_partner_zeile->kest
    cJSON *kest = cJSON_GetObjectItemCaseSensitive(stille_partner_zeileJSON, "kest");
    if (cJSON_IsNull(kest)) {
        kest = NULL;
    }
    if (!kest) {
        goto end;
    }

    
    if(!cJSON_IsString(kest))
    {
    goto end; //String
    }

    // stille_partner_zeile->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(stille_partner_zeileJSON, "name");
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

    // stille_partner_zeile->verlust_verrechnungskonto
    cJSON *verlust_verrechnungskonto = cJSON_GetObjectItemCaseSensitive(stille_partner_zeileJSON, "verlust_verrechnungskonto");
    if (cJSON_IsNull(verlust_verrechnungskonto)) {
        verlust_verrechnungskonto = NULL;
    }
    if (!verlust_verrechnungskonto) {
        goto end;
    }

    
    if(!cJSON_IsString(verlust_verrechnungskonto))
    {
    goto end; //String
    }

    // stille_partner_zeile->verlustanteil
    cJSON *verlustanteil = cJSON_GetObjectItemCaseSensitive(stille_partner_zeileJSON, "verlustanteil");
    if (cJSON_IsNull(verlustanteil)) {
        verlustanteil = NULL;
    }
    if (!verlustanteil) {
        goto end;
    }

    
    if(!cJSON_IsString(verlustanteil))
    {
    goto end; //String
    }


    if (auseinandersetzungsguthaben && !cJSON_IsNull(auseinandersetzungsguthaben)) auseinandersetzungsguthaben_local_str = strdup(auseinandersetzungsguthaben->valuestring);
    if (gewinnanteil && !cJSON_IsNull(gewinnanteil)) gewinnanteil_local_str = strdup(gewinnanteil->valuestring);
    if (gewinnvortrag && !cJSON_IsNull(gewinnvortrag)) gewinnvortrag_local_str = strdup(gewinnvortrag->valuestring);
    if (hinweis && !cJSON_IsNull(hinweis)) hinweis_local_str = strdup(hinweis->valuestring);
    if (instrument_type && !cJSON_IsNull(instrument_type)) instrument_type_local_str = strdup(instrument_type->valuestring);
    if (kest && !cJSON_IsNull(kest)) kest_local_str = strdup(kest->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (verlust_verrechnungskonto && !cJSON_IsNull(verlust_verrechnungskonto)) verlust_verrechnungskonto_local_str = strdup(verlust_verrechnungskonto->valuestring);
    if (verlustanteil && !cJSON_IsNull(verlustanteil)) verlustanteil_local_str = strdup(verlustanteil->valuestring);

    stille_partner_zeile_local_var = stille_partner_zeile_create_internal (
        auseinandersetzungsguthaben_local_str,
        gewinnanteil_local_str,
        gewinnvortrag_local_str,
        hinweis_local_str,
        instrument_type_local_str,
        kest_local_str,
        name_local_str,
        verlust_verrechnungskonto_local_str,
        verlustanteil_local_str
        );

    if (!stille_partner_zeile_local_var) {
        goto end;
    }

    return stille_partner_zeile_local_var;
end:
    if (auseinandersetzungsguthaben_local_str) {
        free(auseinandersetzungsguthaben_local_str);
        auseinandersetzungsguthaben_local_str = NULL;
    }
    if (gewinnanteil_local_str) {
        free(gewinnanteil_local_str);
        gewinnanteil_local_str = NULL;
    }
    if (gewinnvortrag_local_str) {
        free(gewinnvortrag_local_str);
        gewinnvortrag_local_str = NULL;
    }
    if (hinweis_local_str) {
        free(hinweis_local_str);
        hinweis_local_str = NULL;
    }
    if (instrument_type_local_str) {
        free(instrument_type_local_str);
        instrument_type_local_str = NULL;
    }
    if (kest_local_str) {
        free(kest_local_str);
        kest_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (verlust_verrechnungskonto_local_str) {
        free(verlust_verrechnungskonto_local_str);
        verlust_verrechnungskonto_local_str = NULL;
    }
    if (verlustanteil_local_str) {
        free(verlustanteil_local_str);
        verlustanteil_local_str = NULL;
    }
    return NULL;

}
