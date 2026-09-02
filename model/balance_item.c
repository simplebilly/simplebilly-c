#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "balance_item.h"



static balance_item_t *balance_item_create_internal(
    char *account,
    char *account_name,
    char *amount
    ) {
    balance_item_t *balance_item_local_var = malloc(sizeof(balance_item_t));
    if (!balance_item_local_var) {
        return NULL;
    }
    memset(balance_item_local_var, 0, sizeof(balance_item_t));
    balance_item_local_var->_library_owned = 1;
    balance_item_local_var->account = account;
    balance_item_local_var->account_name = account_name;
    balance_item_local_var->amount = amount;
    return balance_item_local_var;
}

__attribute__((deprecated)) balance_item_t *balance_item_create(
    char *account,
    char *account_name,
    char *amount
    ) {
    balance_item_t *result = balance_item_create_internal (
        account,
        account_name,
        amount
        );
    if (!result) {
    }
    return result;
}

void balance_item_free(balance_item_t *balance_item) {
    if(NULL == balance_item){
        return ;
    }
    if(balance_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "balance_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (balance_item->account) {
        free(balance_item->account);
        balance_item->account = NULL;
    }
    if (balance_item->account_name) {
        free(balance_item->account_name);
        balance_item->account_name = NULL;
    }
    if (balance_item->amount) {
        free(balance_item->amount);
        balance_item->amount = NULL;
    }
    free(balance_item);
}

cJSON *balance_item_convertToJSON(balance_item_t *balance_item) {
    cJSON *item = cJSON_CreateObject();

    // balance_item->account
    if (!balance_item->account) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "account", balance_item->account) == NULL) {
    goto fail; //String
    }


    // balance_item->account_name
    if (!balance_item->account_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "account_name", balance_item->account_name) == NULL) {
    goto fail; //String
    }


    // balance_item->amount
    if (!balance_item->amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "amount", balance_item->amount) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

balance_item_t *balance_item_parseFromJSON(cJSON *balance_itemJSON){

    balance_item_t *balance_item_local_var = NULL;

    char *account_local_str = NULL;

    char *account_name_local_str = NULL;

    char *amount_local_str = NULL;

    // balance_item->account
    cJSON *account = cJSON_GetObjectItemCaseSensitive(balance_itemJSON, "account");
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

    // balance_item->account_name
    cJSON *account_name = cJSON_GetObjectItemCaseSensitive(balance_itemJSON, "account_name");
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

    // balance_item->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(balance_itemJSON, "amount");
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

    balance_item_local_var = balance_item_create_internal (
        account_local_str,
        account_name_local_str,
        amount_local_str
        );

    if (!balance_item_local_var) {
        goto end;
    }

    return balance_item_local_var;
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
