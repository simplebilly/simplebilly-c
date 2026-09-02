#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gu_v_item.h"



static gu_v_item_t *gu_v_item_create_internal(
    char *account,
    char *amount,
    char *name
    ) {
    gu_v_item_t *gu_v_item_local_var = malloc(sizeof(gu_v_item_t));
    if (!gu_v_item_local_var) {
        return NULL;
    }
    memset(gu_v_item_local_var, 0, sizeof(gu_v_item_t));
    gu_v_item_local_var->_library_owned = 1;
    gu_v_item_local_var->account = account;
    gu_v_item_local_var->amount = amount;
    gu_v_item_local_var->name = name;
    return gu_v_item_local_var;
}

__attribute__((deprecated)) gu_v_item_t *gu_v_item_create(
    char *account,
    char *amount,
    char *name
    ) {
    gu_v_item_t *result = gu_v_item_create_internal (
        account,
        amount,
        name
        );
    if (!result) {
    }
    return result;
}

void gu_v_item_free(gu_v_item_t *gu_v_item) {
    if(NULL == gu_v_item){
        return ;
    }
    if(gu_v_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gu_v_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gu_v_item->account) {
        free(gu_v_item->account);
        gu_v_item->account = NULL;
    }
    if (gu_v_item->amount) {
        free(gu_v_item->amount);
        gu_v_item->amount = NULL;
    }
    if (gu_v_item->name) {
        free(gu_v_item->name);
        gu_v_item->name = NULL;
    }
    free(gu_v_item);
}

cJSON *gu_v_item_convertToJSON(gu_v_item_t *gu_v_item) {
    cJSON *item = cJSON_CreateObject();

    // gu_v_item->account
    if (!gu_v_item->account) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "account", gu_v_item->account) == NULL) {
    goto fail; //String
    }


    // gu_v_item->amount
    if (!gu_v_item->amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "amount", gu_v_item->amount) == NULL) {
    goto fail; //String
    }


    // gu_v_item->name
    if (!gu_v_item->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", gu_v_item->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gu_v_item_t *gu_v_item_parseFromJSON(cJSON *gu_v_itemJSON){

    gu_v_item_t *gu_v_item_local_var = NULL;

    char *account_local_str = NULL;

    char *amount_local_str = NULL;

    char *name_local_str = NULL;

    // gu_v_item->account
    cJSON *account = cJSON_GetObjectItemCaseSensitive(gu_v_itemJSON, "account");
    if (cJSON_IsNull(account)) {
        account = NULL;
    }
    if (!account) {
        goto end;
    }

    
    if(!cJSON_IsString(account))
    {
    goto end; //String
    }

    // gu_v_item->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(gu_v_itemJSON, "amount");
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

    // gu_v_item->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(gu_v_itemJSON, "name");
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


    if (account && !cJSON_IsNull(account)) account_local_str = strdup(account->valuestring);
    if (amount && !cJSON_IsNull(amount)) amount_local_str = strdup(amount->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    gu_v_item_local_var = gu_v_item_create_internal (
        account_local_str,
        amount_local_str,
        name_local_str
        );

    if (!gu_v_item_local_var) {
        goto end;
    }

    return gu_v_item_local_var;
end:
    if (account_local_str) {
        free(account_local_str);
        account_local_str = NULL;
    }
    if (amount_local_str) {
        free(amount_local_str);
        amount_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    return NULL;

}
