#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "konto_item.h"



static konto_item_t *konto_item_create_internal(
    char *anfangsbestand,
    char *haben_umsatz,
    char *konto,
    char *name,
    char *saldo,
    char *soll_umsatz
    ) {
    konto_item_t *konto_item_local_var = malloc(sizeof(konto_item_t));
    if (!konto_item_local_var) {
        return NULL;
    }
    memset(konto_item_local_var, 0, sizeof(konto_item_t));
    konto_item_local_var->_library_owned = 1;
    konto_item_local_var->anfangsbestand = anfangsbestand;
    konto_item_local_var->haben_umsatz = haben_umsatz;
    konto_item_local_var->konto = konto;
    konto_item_local_var->name = name;
    konto_item_local_var->saldo = saldo;
    konto_item_local_var->soll_umsatz = soll_umsatz;
    return konto_item_local_var;
}

__attribute__((deprecated)) konto_item_t *konto_item_create(
    char *anfangsbestand,
    char *haben_umsatz,
    char *konto,
    char *name,
    char *saldo,
    char *soll_umsatz
    ) {
    konto_item_t *result = konto_item_create_internal (
        anfangsbestand,
        haben_umsatz,
        konto,
        name,
        saldo,
        soll_umsatz
        );
    if (!result) {
    }
    return result;
}

void konto_item_free(konto_item_t *konto_item) {
    if(NULL == konto_item){
        return ;
    }
    if(konto_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "konto_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (konto_item->anfangsbestand) {
        free(konto_item->anfangsbestand);
        konto_item->anfangsbestand = NULL;
    }
    if (konto_item->haben_umsatz) {
        free(konto_item->haben_umsatz);
        konto_item->haben_umsatz = NULL;
    }
    if (konto_item->konto) {
        free(konto_item->konto);
        konto_item->konto = NULL;
    }
    if (konto_item->name) {
        free(konto_item->name);
        konto_item->name = NULL;
    }
    if (konto_item->saldo) {
        free(konto_item->saldo);
        konto_item->saldo = NULL;
    }
    if (konto_item->soll_umsatz) {
        free(konto_item->soll_umsatz);
        konto_item->soll_umsatz = NULL;
    }
    free(konto_item);
}

cJSON *konto_item_convertToJSON(konto_item_t *konto_item) {
    cJSON *item = cJSON_CreateObject();

    // konto_item->anfangsbestand
    if (!konto_item->anfangsbestand) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "anfangsbestand", konto_item->anfangsbestand) == NULL) {
    goto fail; //String
    }


    // konto_item->haben_umsatz
    if (!konto_item->haben_umsatz) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "haben_umsatz", konto_item->haben_umsatz) == NULL) {
    goto fail; //String
    }


    // konto_item->konto
    if (!konto_item->konto) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "konto", konto_item->konto) == NULL) {
    goto fail; //String
    }


    // konto_item->name
    if (!konto_item->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", konto_item->name) == NULL) {
    goto fail; //String
    }


    // konto_item->saldo
    if (!konto_item->saldo) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "saldo", konto_item->saldo) == NULL) {
    goto fail; //String
    }


    // konto_item->soll_umsatz
    if (!konto_item->soll_umsatz) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "soll_umsatz", konto_item->soll_umsatz) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

konto_item_t *konto_item_parseFromJSON(cJSON *konto_itemJSON){

    konto_item_t *konto_item_local_var = NULL;

    char *anfangsbestand_local_str = NULL;

    char *haben_umsatz_local_str = NULL;

    char *konto_local_str = NULL;

    char *name_local_str = NULL;

    char *saldo_local_str = NULL;

    char *soll_umsatz_local_str = NULL;

    // konto_item->anfangsbestand
    cJSON *anfangsbestand = cJSON_GetObjectItemCaseSensitive(konto_itemJSON, "anfangsbestand");
    if (cJSON_IsNull(anfangsbestand)) {
        anfangsbestand = NULL;
    }
    if (!anfangsbestand) {
        goto end;
    }

    
    if(!cJSON_IsString(anfangsbestand))
    {
    goto end; //String
    }

    // konto_item->haben_umsatz
    cJSON *haben_umsatz = cJSON_GetObjectItemCaseSensitive(konto_itemJSON, "haben_umsatz");
    if (cJSON_IsNull(haben_umsatz)) {
        haben_umsatz = NULL;
    }
    if (!haben_umsatz) {
        goto end;
    }

    
    if(!cJSON_IsString(haben_umsatz))
    {
    goto end; //String
    }

    // konto_item->konto
    cJSON *konto = cJSON_GetObjectItemCaseSensitive(konto_itemJSON, "konto");
    if (cJSON_IsNull(konto)) {
        konto = NULL;
    }
    if (!konto) {
        goto end;
    }

    
    if(!cJSON_IsString(konto))
    {
    goto end; //String
    }

    // konto_item->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(konto_itemJSON, "name");
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

    // konto_item->saldo
    cJSON *saldo = cJSON_GetObjectItemCaseSensitive(konto_itemJSON, "saldo");
    if (cJSON_IsNull(saldo)) {
        saldo = NULL;
    }
    if (!saldo) {
        goto end;
    }

    
    if(!cJSON_IsString(saldo))
    {
    goto end; //String
    }

    // konto_item->soll_umsatz
    cJSON *soll_umsatz = cJSON_GetObjectItemCaseSensitive(konto_itemJSON, "soll_umsatz");
    if (cJSON_IsNull(soll_umsatz)) {
        soll_umsatz = NULL;
    }
    if (!soll_umsatz) {
        goto end;
    }

    
    if(!cJSON_IsString(soll_umsatz))
    {
    goto end; //String
    }


    if (anfangsbestand && !cJSON_IsNull(anfangsbestand)) anfangsbestand_local_str = strdup(anfangsbestand->valuestring);
    if (haben_umsatz && !cJSON_IsNull(haben_umsatz)) haben_umsatz_local_str = strdup(haben_umsatz->valuestring);
    if (konto && !cJSON_IsNull(konto)) konto_local_str = strdup(konto->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (saldo && !cJSON_IsNull(saldo)) saldo_local_str = strdup(saldo->valuestring);
    if (soll_umsatz && !cJSON_IsNull(soll_umsatz)) soll_umsatz_local_str = strdup(soll_umsatz->valuestring);

    konto_item_local_var = konto_item_create_internal (
        anfangsbestand_local_str,
        haben_umsatz_local_str,
        konto_local_str,
        name_local_str,
        saldo_local_str,
        soll_umsatz_local_str
        );

    if (!konto_item_local_var) {
        goto end;
    }

    return konto_item_local_var;
end:
    if (anfangsbestand_local_str) {
        free(anfangsbestand_local_str);
        anfangsbestand_local_str = NULL;
    }
    if (haben_umsatz_local_str) {
        free(haben_umsatz_local_str);
        haben_umsatz_local_str = NULL;
    }
    if (konto_local_str) {
        free(konto_local_str);
        konto_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (saldo_local_str) {
        free(saldo_local_str);
        saldo_local_str = NULL;
    }
    if (soll_umsatz_local_str) {
        free(soll_umsatz_local_str);
        soll_umsatz_local_str = NULL;
    }
    return NULL;

}
