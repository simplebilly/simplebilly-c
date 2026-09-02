#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "datev_booking_preview.h"



static datev_booking_preview_t *datev_booking_preview_create_internal(
    char *account_number,
    char *debit_credit,
    char *document_date,
    char *document_text,
    char *net_amount,
    char *opposite_account,
    char *tax_amount,
    char *tax_rate
    ) {
    datev_booking_preview_t *datev_booking_preview_local_var = malloc(sizeof(datev_booking_preview_t));
    if (!datev_booking_preview_local_var) {
        return NULL;
    }
    memset(datev_booking_preview_local_var, 0, sizeof(datev_booking_preview_t));
    datev_booking_preview_local_var->_library_owned = 1;
    datev_booking_preview_local_var->account_number = account_number;
    datev_booking_preview_local_var->debit_credit = debit_credit;
    datev_booking_preview_local_var->document_date = document_date;
    datev_booking_preview_local_var->document_text = document_text;
    datev_booking_preview_local_var->net_amount = net_amount;
    datev_booking_preview_local_var->opposite_account = opposite_account;
    datev_booking_preview_local_var->tax_amount = tax_amount;
    datev_booking_preview_local_var->tax_rate = tax_rate;
    return datev_booking_preview_local_var;
}

__attribute__((deprecated)) datev_booking_preview_t *datev_booking_preview_create(
    char *account_number,
    char *debit_credit,
    char *document_date,
    char *document_text,
    char *net_amount,
    char *opposite_account,
    char *tax_amount,
    char *tax_rate
    ) {
    datev_booking_preview_t *result = datev_booking_preview_create_internal (
        account_number,
        debit_credit,
        document_date,
        document_text,
        net_amount,
        opposite_account,
        tax_amount,
        tax_rate
        );
    if (!result) {
    }
    return result;
}

void datev_booking_preview_free(datev_booking_preview_t *datev_booking_preview) {
    if(NULL == datev_booking_preview){
        return ;
    }
    if(datev_booking_preview->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "datev_booking_preview_free");
        return ;
    }
    listEntry_t *listEntry;
    if (datev_booking_preview->account_number) {
        free(datev_booking_preview->account_number);
        datev_booking_preview->account_number = NULL;
    }
    if (datev_booking_preview->debit_credit) {
        free(datev_booking_preview->debit_credit);
        datev_booking_preview->debit_credit = NULL;
    }
    if (datev_booking_preview->document_date) {
        free(datev_booking_preview->document_date);
        datev_booking_preview->document_date = NULL;
    }
    if (datev_booking_preview->document_text) {
        free(datev_booking_preview->document_text);
        datev_booking_preview->document_text = NULL;
    }
    if (datev_booking_preview->net_amount) {
        free(datev_booking_preview->net_amount);
        datev_booking_preview->net_amount = NULL;
    }
    if (datev_booking_preview->opposite_account) {
        free(datev_booking_preview->opposite_account);
        datev_booking_preview->opposite_account = NULL;
    }
    if (datev_booking_preview->tax_amount) {
        free(datev_booking_preview->tax_amount);
        datev_booking_preview->tax_amount = NULL;
    }
    if (datev_booking_preview->tax_rate) {
        free(datev_booking_preview->tax_rate);
        datev_booking_preview->tax_rate = NULL;
    }
    free(datev_booking_preview);
}

cJSON *datev_booking_preview_convertToJSON(datev_booking_preview_t *datev_booking_preview) {
    cJSON *item = cJSON_CreateObject();

    // datev_booking_preview->account_number
    if (!datev_booking_preview->account_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "account_number", datev_booking_preview->account_number) == NULL) {
    goto fail; //String
    }


    // datev_booking_preview->debit_credit
    if (!datev_booking_preview->debit_credit) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "debit_credit", datev_booking_preview->debit_credit) == NULL) {
    goto fail; //String
    }


    // datev_booking_preview->document_date
    if (!datev_booking_preview->document_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "document_date", datev_booking_preview->document_date) == NULL) {
    goto fail; //String
    }


    // datev_booking_preview->document_text
    if (!datev_booking_preview->document_text) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "document_text", datev_booking_preview->document_text) == NULL) {
    goto fail; //String
    }


    // datev_booking_preview->net_amount
    if (!datev_booking_preview->net_amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "net_amount", datev_booking_preview->net_amount) == NULL) {
    goto fail; //String
    }


    // datev_booking_preview->opposite_account
    if (!datev_booking_preview->opposite_account) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "opposite_account", datev_booking_preview->opposite_account) == NULL) {
    goto fail; //String
    }


    // datev_booking_preview->tax_amount
    if(datev_booking_preview->tax_amount) {
    if(cJSON_AddStringToObject(item, "tax_amount", datev_booking_preview->tax_amount) == NULL) {
    goto fail; //String
    }
    }


    // datev_booking_preview->tax_rate
    if(datev_booking_preview->tax_rate) {
    if(cJSON_AddStringToObject(item, "tax_rate", datev_booking_preview->tax_rate) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

datev_booking_preview_t *datev_booking_preview_parseFromJSON(cJSON *datev_booking_previewJSON){

    datev_booking_preview_t *datev_booking_preview_local_var = NULL;

    char *account_number_local_str = NULL;

    char *debit_credit_local_str = NULL;

    char *document_date_local_str = NULL;

    char *document_text_local_str = NULL;

    char *net_amount_local_str = NULL;

    char *opposite_account_local_str = NULL;

    char *tax_amount_local_str = NULL;

    char *tax_rate_local_str = NULL;

    // datev_booking_preview->account_number
    cJSON *account_number = cJSON_GetObjectItemCaseSensitive(datev_booking_previewJSON, "account_number");
    if (cJSON_IsNull(account_number)) {
        account_number = NULL;
    }
    if (!account_number) {
        goto end;
    }

    
    if(!cJSON_IsString(account_number))
    {
    goto end; //String
    }

    // datev_booking_preview->debit_credit
    cJSON *debit_credit = cJSON_GetObjectItemCaseSensitive(datev_booking_previewJSON, "debit_credit");
    if (cJSON_IsNull(debit_credit)) {
        debit_credit = NULL;
    }
    if (!debit_credit) {
        goto end;
    }

    
    if(!cJSON_IsString(debit_credit))
    {
    goto end; //String
    }

    // datev_booking_preview->document_date
    cJSON *document_date = cJSON_GetObjectItemCaseSensitive(datev_booking_previewJSON, "document_date");
    if (cJSON_IsNull(document_date)) {
        document_date = NULL;
    }
    if (!document_date) {
        goto end;
    }

    
    if(!cJSON_IsString(document_date))
    {
    goto end; //String
    }

    // datev_booking_preview->document_text
    cJSON *document_text = cJSON_GetObjectItemCaseSensitive(datev_booking_previewJSON, "document_text");
    if (cJSON_IsNull(document_text)) {
        document_text = NULL;
    }
    if (!document_text) {
        goto end;
    }

    
    if(!cJSON_IsString(document_text))
    {
    goto end; //String
    }

    // datev_booking_preview->net_amount
    cJSON *net_amount = cJSON_GetObjectItemCaseSensitive(datev_booking_previewJSON, "net_amount");
    if (cJSON_IsNull(net_amount)) {
        net_amount = NULL;
    }
    if (!net_amount) {
        goto end;
    }

    
    if(!cJSON_IsString(net_amount))
    {
    goto end; //String
    }

    // datev_booking_preview->opposite_account
    cJSON *opposite_account = cJSON_GetObjectItemCaseSensitive(datev_booking_previewJSON, "opposite_account");
    if (cJSON_IsNull(opposite_account)) {
        opposite_account = NULL;
    }
    if (!opposite_account) {
        goto end;
    }

    
    if(!cJSON_IsString(opposite_account))
    {
    goto end; //String
    }

    // datev_booking_preview->tax_amount
    cJSON *tax_amount = cJSON_GetObjectItemCaseSensitive(datev_booking_previewJSON, "tax_amount");
    if (cJSON_IsNull(tax_amount)) {
        tax_amount = NULL;
    }
    if (tax_amount) { 
    if(!cJSON_IsString(tax_amount) && !cJSON_IsNull(tax_amount))
    {
    goto end; //String
    }
    }

    // datev_booking_preview->tax_rate
    cJSON *tax_rate = cJSON_GetObjectItemCaseSensitive(datev_booking_previewJSON, "tax_rate");
    if (cJSON_IsNull(tax_rate)) {
        tax_rate = NULL;
    }
    if (tax_rate) { 
    if(!cJSON_IsString(tax_rate) && !cJSON_IsNull(tax_rate))
    {
    goto end; //String
    }
    }


    if (account_number && !cJSON_IsNull(account_number)) account_number_local_str = strdup(account_number->valuestring);
    if (debit_credit && !cJSON_IsNull(debit_credit)) debit_credit_local_str = strdup(debit_credit->valuestring);
    if (document_date && !cJSON_IsNull(document_date)) document_date_local_str = strdup(document_date->valuestring);
    if (document_text && !cJSON_IsNull(document_text)) document_text_local_str = strdup(document_text->valuestring);
    if (net_amount && !cJSON_IsNull(net_amount)) net_amount_local_str = strdup(net_amount->valuestring);
    if (opposite_account && !cJSON_IsNull(opposite_account)) opposite_account_local_str = strdup(opposite_account->valuestring);
    if (tax_amount && !cJSON_IsNull(tax_amount)) tax_amount_local_str = strdup(tax_amount->valuestring);
    if (tax_rate && !cJSON_IsNull(tax_rate)) tax_rate_local_str = strdup(tax_rate->valuestring);

    datev_booking_preview_local_var = datev_booking_preview_create_internal (
        account_number_local_str,
        debit_credit_local_str,
        document_date_local_str,
        document_text_local_str,
        net_amount_local_str,
        opposite_account_local_str,
        tax_amount_local_str,
        tax_rate_local_str
        );

    if (!datev_booking_preview_local_var) {
        goto end;
    }

    return datev_booking_preview_local_var;
end:
    if (account_number_local_str) {
        free(account_number_local_str);
        account_number_local_str = NULL;
    }
    if (debit_credit_local_str) {
        free(debit_credit_local_str);
        debit_credit_local_str = NULL;
    }
    if (document_date_local_str) {
        free(document_date_local_str);
        document_date_local_str = NULL;
    }
    if (document_text_local_str) {
        free(document_text_local_str);
        document_text_local_str = NULL;
    }
    if (net_amount_local_str) {
        free(net_amount_local_str);
        net_amount_local_str = NULL;
    }
    if (opposite_account_local_str) {
        free(opposite_account_local_str);
        opposite_account_local_str = NULL;
    }
    if (tax_amount_local_str) {
        free(tax_amount_local_str);
        tax_amount_local_str = NULL;
    }
    if (tax_rate_local_str) {
        free(tax_rate_local_str);
        tax_rate_local_str = NULL;
    }
    return NULL;

}
