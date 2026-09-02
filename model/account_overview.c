#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "account_overview.h"



static account_overview_t *account_overview_create_internal(
    char *account,
    char *account_name,
    char *balance,
    char *credit_total,
    char *debit_total
    ) {
    account_overview_t *account_overview_local_var = malloc(sizeof(account_overview_t));
    if (!account_overview_local_var) {
        return NULL;
    }
    memset(account_overview_local_var, 0, sizeof(account_overview_t));
    account_overview_local_var->_library_owned = 1;
    account_overview_local_var->account = account;
    account_overview_local_var->account_name = account_name;
    account_overview_local_var->balance = balance;
    account_overview_local_var->credit_total = credit_total;
    account_overview_local_var->debit_total = debit_total;
    return account_overview_local_var;
}

__attribute__((deprecated)) account_overview_t *account_overview_create(
    char *account,
    char *account_name,
    char *balance,
    char *credit_total,
    char *debit_total
    ) {
    account_overview_t *result = account_overview_create_internal (
        account,
        account_name,
        balance,
        credit_total,
        debit_total
        );
    if (!result) {
    }
    return result;
}

void account_overview_free(account_overview_t *account_overview) {
    if(NULL == account_overview){
        return ;
    }
    if(account_overview->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "account_overview_free");
        return ;
    }
    listEntry_t *listEntry;
    if (account_overview->account) {
        free(account_overview->account);
        account_overview->account = NULL;
    }
    if (account_overview->account_name) {
        free(account_overview->account_name);
        account_overview->account_name = NULL;
    }
    if (account_overview->balance) {
        free(account_overview->balance);
        account_overview->balance = NULL;
    }
    if (account_overview->credit_total) {
        free(account_overview->credit_total);
        account_overview->credit_total = NULL;
    }
    if (account_overview->debit_total) {
        free(account_overview->debit_total);
        account_overview->debit_total = NULL;
    }
    free(account_overview);
}

cJSON *account_overview_convertToJSON(account_overview_t *account_overview) {
    cJSON *item = cJSON_CreateObject();

    // account_overview->account
    if (!account_overview->account) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "account", account_overview->account) == NULL) {
    goto fail; //String
    }


    // account_overview->account_name
    if (!account_overview->account_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "account_name", account_overview->account_name) == NULL) {
    goto fail; //String
    }


    // account_overview->balance
    if (!account_overview->balance) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "balance", account_overview->balance) == NULL) {
    goto fail; //String
    }


    // account_overview->credit_total
    if (!account_overview->credit_total) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "credit_total", account_overview->credit_total) == NULL) {
    goto fail; //String
    }


    // account_overview->debit_total
    if (!account_overview->debit_total) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "debit_total", account_overview->debit_total) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

account_overview_t *account_overview_parseFromJSON(cJSON *account_overviewJSON){

    account_overview_t *account_overview_local_var = NULL;

    char *account_local_str = NULL;

    char *account_name_local_str = NULL;

    char *balance_local_str = NULL;

    char *credit_total_local_str = NULL;

    char *debit_total_local_str = NULL;

    // account_overview->account
    cJSON *account = cJSON_GetObjectItemCaseSensitive(account_overviewJSON, "account");
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

    // account_overview->account_name
    cJSON *account_name = cJSON_GetObjectItemCaseSensitive(account_overviewJSON, "account_name");
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

    // account_overview->balance
    cJSON *balance = cJSON_GetObjectItemCaseSensitive(account_overviewJSON, "balance");
    if (cJSON_IsNull(balance)) {
        balance = NULL;
    }
    if (!balance) {
        goto end;
    }

    
    if(!cJSON_IsString(balance))
    {
    goto end; //String
    }

    // account_overview->credit_total
    cJSON *credit_total = cJSON_GetObjectItemCaseSensitive(account_overviewJSON, "credit_total");
    if (cJSON_IsNull(credit_total)) {
        credit_total = NULL;
    }
    if (!credit_total) {
        goto end;
    }

    
    if(!cJSON_IsString(credit_total))
    {
    goto end; //String
    }

    // account_overview->debit_total
    cJSON *debit_total = cJSON_GetObjectItemCaseSensitive(account_overviewJSON, "debit_total");
    if (cJSON_IsNull(debit_total)) {
        debit_total = NULL;
    }
    if (!debit_total) {
        goto end;
    }

    
    if(!cJSON_IsString(debit_total))
    {
    goto end; //String
    }


    if (account && !cJSON_IsNull(account)) account_local_str = strdup(account->valuestring);
    if (account_name && !cJSON_IsNull(account_name)) account_name_local_str = strdup(account_name->valuestring);
    if (balance && !cJSON_IsNull(balance)) balance_local_str = strdup(balance->valuestring);
    if (credit_total && !cJSON_IsNull(credit_total)) credit_total_local_str = strdup(credit_total->valuestring);
    if (debit_total && !cJSON_IsNull(debit_total)) debit_total_local_str = strdup(debit_total->valuestring);

    account_overview_local_var = account_overview_create_internal (
        account_local_str,
        account_name_local_str,
        balance_local_str,
        credit_total_local_str,
        debit_total_local_str
        );

    if (!account_overview_local_var) {
        goto end;
    }

    return account_overview_local_var;
end:
    if (account_local_str) {
        free(account_local_str);
        account_local_str = NULL;
    }
    if (account_name_local_str) {
        free(account_name_local_str);
        account_name_local_str = NULL;
    }
    if (balance_local_str) {
        free(balance_local_str);
        balance_local_str = NULL;
    }
    if (credit_total_local_str) {
        free(credit_total_local_str);
        credit_total_local_str = NULL;
    }
    if (debit_total_local_str) {
        free(debit_total_local_str);
        debit_total_local_str = NULL;
    }
    return NULL;

}
