#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bilanz_item.h"



static bilanz_item_t *bilanz_item_create_internal(
    char *amount,
    char *konto,
    char *name
    ) {
    bilanz_item_t *bilanz_item_local_var = malloc(sizeof(bilanz_item_t));
    if (!bilanz_item_local_var) {
        return NULL;
    }
    memset(bilanz_item_local_var, 0, sizeof(bilanz_item_t));
    bilanz_item_local_var->_library_owned = 1;
    bilanz_item_local_var->amount = amount;
    bilanz_item_local_var->konto = konto;
    bilanz_item_local_var->name = name;
    return bilanz_item_local_var;
}

__attribute__((deprecated)) bilanz_item_t *bilanz_item_create(
    char *amount,
    char *konto,
    char *name
    ) {
    bilanz_item_t *result = bilanz_item_create_internal (
        amount,
        konto,
        name
        );
    if (!result) {
    }
    return result;
}

void bilanz_item_free(bilanz_item_t *bilanz_item) {
    if(NULL == bilanz_item){
        return ;
    }
    if(bilanz_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "bilanz_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (bilanz_item->amount) {
        free(bilanz_item->amount);
        bilanz_item->amount = NULL;
    }
    if (bilanz_item->konto) {
        free(bilanz_item->konto);
        bilanz_item->konto = NULL;
    }
    if (bilanz_item->name) {
        free(bilanz_item->name);
        bilanz_item->name = NULL;
    }
    free(bilanz_item);
}

cJSON *bilanz_item_convertToJSON(bilanz_item_t *bilanz_item) {
    cJSON *item = cJSON_CreateObject();

    // bilanz_item->amount
    if (!bilanz_item->amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "amount", bilanz_item->amount) == NULL) {
    goto fail; //String
    }


    // bilanz_item->konto
    if (!bilanz_item->konto) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "konto", bilanz_item->konto) == NULL) {
    goto fail; //String
    }


    // bilanz_item->name
    if (!bilanz_item->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", bilanz_item->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

bilanz_item_t *bilanz_item_parseFromJSON(cJSON *bilanz_itemJSON){

    bilanz_item_t *bilanz_item_local_var = NULL;

    char *amount_local_str = NULL;

    char *konto_local_str = NULL;

    char *name_local_str = NULL;

    // bilanz_item->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(bilanz_itemJSON, "amount");
    if (cJSON_IsNull(amount)) {
        amount = NULL;
    }
    if (!amount) {
        goto end;
    }

    
    if(!cJSON_IsString(amount))
    {
    goto end; //String
    }

    // bilanz_item->konto
    cJSON *konto = cJSON_GetObjectItemCaseSensitive(bilanz_itemJSON, "konto");
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

    // bilanz_item->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(bilanz_itemJSON, "name");
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


    if (amount && !cJSON_IsNull(amount)) amount_local_str = strdup(amount->valuestring);
    if (konto && !cJSON_IsNull(konto)) konto_local_str = strdup(konto->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    bilanz_item_local_var = bilanz_item_create_internal (
        amount_local_str,
        konto_local_str,
        name_local_str
        );

    if (!bilanz_item_local_var) {
        goto end;
    }

    return bilanz_item_local_var;
end:
    if (amount_local_str) {
        free(amount_local_str);
        amount_local_str = NULL;
    }
    if (konto_local_str) {
        free(konto_local_str);
        konto_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    return NULL;

}
