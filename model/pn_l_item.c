#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pn_l_item.h"



static pn_l_item_t *pn_l_item_create_internal(
    char *account,
    char *account_name,
    char *amount
    ) {
    pn_l_item_t *pn_l_item_local_var = malloc(sizeof(pn_l_item_t));
    if (!pn_l_item_local_var) {
        return NULL;
    }
    memset(pn_l_item_local_var, 0, sizeof(pn_l_item_t));
    pn_l_item_local_var->_library_owned = 1;
    pn_l_item_local_var->account = account;
    pn_l_item_local_var->account_name = account_name;
    pn_l_item_local_var->amount = amount;
    return pn_l_item_local_var;
}

__attribute__((deprecated)) pn_l_item_t *pn_l_item_create(
    char *account,
    char *account_name,
    char *amount
    ) {
    pn_l_item_t *result = pn_l_item_create_internal (
        account,
        account_name,
        amount
        );
    if (!result) {
    }
    return result;
}

void pn_l_item_free(pn_l_item_t *pn_l_item) {
    if(NULL == pn_l_item){
        return ;
    }
    if(pn_l_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "pn_l_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (pn_l_item->account) {
        free(pn_l_item->account);
        pn_l_item->account = NULL;
    }
    if (pn_l_item->account_name) {
        free(pn_l_item->account_name);
        pn_l_item->account_name = NULL;
    }
    if (pn_l_item->amount) {
        free(pn_l_item->amount);
        pn_l_item->amount = NULL;
    }
    free(pn_l_item);
}

cJSON *pn_l_item_convertToJSON(pn_l_item_t *pn_l_item) {
    cJSON *item = cJSON_CreateObject();

    // pn_l_item->account
    if (!pn_l_item->account) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "account", pn_l_item->account) == NULL) {
    goto fail; //String
    }


    // pn_l_item->account_name
    if (!pn_l_item->account_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "account_name", pn_l_item->account_name) == NULL) {
    goto fail; //String
    }


    // pn_l_item->amount
    if (!pn_l_item->amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "amount", pn_l_item->amount) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

pn_l_item_t *pn_l_item_parseFromJSON(cJSON *pn_l_itemJSON){

    pn_l_item_t *pn_l_item_local_var = NULL;

    char *account_local_str = NULL;

    char *account_name_local_str = NULL;

    char *amount_local_str = NULL;

    // pn_l_item->account
    cJSON *account = cJSON_GetObjectItemCaseSensitive(pn_l_itemJSON, "account");
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

    // pn_l_item->account_name
    cJSON *account_name = cJSON_GetObjectItemCaseSensitive(pn_l_itemJSON, "account_name");
    if (cJSON_IsNull(account_name)) {
        account_name = NULL;
    }
    if (!account_name) {
        goto end;
    }

    
    if(!cJSON_IsString(account_name))
    {
    goto end; //String
    }

    // pn_l_item->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(pn_l_itemJSON, "amount");
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


    if (account && !cJSON_IsNull(account)) account_local_str = strdup(account->valuestring);
    if (account_name && !cJSON_IsNull(account_name)) account_name_local_str = strdup(account_name->valuestring);
    if (amount && !cJSON_IsNull(amount)) amount_local_str = strdup(amount->valuestring);

    pn_l_item_local_var = pn_l_item_create_internal (
        account_local_str,
        account_name_local_str,
        amount_local_str
        );

    if (!pn_l_item_local_var) {
        goto end;
    }

    return pn_l_item_local_var;
end:
    if (account_local_str) {
        free(account_local_str);
        account_local_str = NULL;
    }
    if (account_name_local_str) {
        free(account_name_local_str);
        account_name_local_str = NULL;
    }
    if (amount_local_str) {
        free(amount_local_str);
        amount_local_str = NULL;
    }
    return NULL;

}
