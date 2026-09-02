#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "datev_import_row.h"



static datev_import_row_t *datev_import_row_create_internal(
    char *account,
    char *amount,
    char *base_amount,
    char *base_currency,
    char *booking_text,
    char *bu_key,
    char *cost_center1,
    char *cost_center2,
    char *currency,
    char *debit_credit,
    char *discount,
    char *document_date,
    char *document_field2,
    char *document_number,
    char *eu_country_vat_id,
    char *eu_tax_rate,
    char *exchange_rate,
    char *opposite_account
    ) {
    datev_import_row_t *datev_import_row_local_var = malloc(sizeof(datev_import_row_t));
    if (!datev_import_row_local_var) {
        return NULL;
    }
    memset(datev_import_row_local_var, 0, sizeof(datev_import_row_t));
    datev_import_row_local_var->_library_owned = 1;
    datev_import_row_local_var->account = account;
    datev_import_row_local_var->amount = amount;
    datev_import_row_local_var->base_amount = base_amount;
    datev_import_row_local_var->base_currency = base_currency;
    datev_import_row_local_var->booking_text = booking_text;
    datev_import_row_local_var->bu_key = bu_key;
    datev_import_row_local_var->cost_center1 = cost_center1;
    datev_import_row_local_var->cost_center2 = cost_center2;
    datev_import_row_local_var->currency = currency;
    datev_import_row_local_var->debit_credit = debit_credit;
    datev_import_row_local_var->discount = discount;
    datev_import_row_local_var->document_date = document_date;
    datev_import_row_local_var->document_field2 = document_field2;
    datev_import_row_local_var->document_number = document_number;
    datev_import_row_local_var->eu_country_vat_id = eu_country_vat_id;
    datev_import_row_local_var->eu_tax_rate = eu_tax_rate;
    datev_import_row_local_var->exchange_rate = exchange_rate;
    datev_import_row_local_var->opposite_account = opposite_account;
    return datev_import_row_local_var;
}

__attribute__((deprecated)) datev_import_row_t *datev_import_row_create(
    char *account,
    char *amount,
    char *base_amount,
    char *base_currency,
    char *booking_text,
    char *bu_key,
    char *cost_center1,
    char *cost_center2,
    char *currency,
    char *debit_credit,
    char *discount,
    char *document_date,
    char *document_field2,
    char *document_number,
    char *eu_country_vat_id,
    char *eu_tax_rate,
    char *exchange_rate,
    char *opposite_account
    ) {
    datev_import_row_t *result = datev_import_row_create_internal (
        account,
        amount,
        base_amount,
        base_currency,
        booking_text,
        bu_key,
        cost_center1,
        cost_center2,
        currency,
        debit_credit,
        discount,
        document_date,
        document_field2,
        document_number,
        eu_country_vat_id,
        eu_tax_rate,
        exchange_rate,
        opposite_account
        );
    if (!result) {
    }
    return result;
}

void datev_import_row_free(datev_import_row_t *datev_import_row) {
    if(NULL == datev_import_row){
        return ;
    }
    if(datev_import_row->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "datev_import_row_free");
        return ;
    }
    listEntry_t *listEntry;
    if (datev_import_row->account) {
        free(datev_import_row->account);
        datev_import_row->account = NULL;
    }
    if (datev_import_row->amount) {
        free(datev_import_row->amount);
        datev_import_row->amount = NULL;
    }
    if (datev_import_row->base_amount) {
        free(datev_import_row->base_amount);
        datev_import_row->base_amount = NULL;
    }
    if (datev_import_row->base_currency) {
        free(datev_import_row->base_currency);
        datev_import_row->base_currency = NULL;
    }
    if (datev_import_row->booking_text) {
        free(datev_import_row->booking_text);
        datev_import_row->booking_text = NULL;
    }
    if (datev_import_row->bu_key) {
        free(datev_import_row->bu_key);
        datev_import_row->bu_key = NULL;
    }
    if (datev_import_row->cost_center1) {
        free(datev_import_row->cost_center1);
        datev_import_row->cost_center1 = NULL;
    }
    if (datev_import_row->cost_center2) {
        free(datev_import_row->cost_center2);
        datev_import_row->cost_center2 = NULL;
    }
    if (datev_import_row->currency) {
        free(datev_import_row->currency);
        datev_import_row->currency = NULL;
    }
    if (datev_import_row->debit_credit) {
        free(datev_import_row->debit_credit);
        datev_import_row->debit_credit = NULL;
    }
    if (datev_import_row->discount) {
        free(datev_import_row->discount);
        datev_import_row->discount = NULL;
    }
    if (datev_import_row->document_date) {
        free(datev_import_row->document_date);
        datev_import_row->document_date = NULL;
    }
    if (datev_import_row->document_field2) {
        free(datev_import_row->document_field2);
        datev_import_row->document_field2 = NULL;
    }
    if (datev_import_row->document_number) {
        free(datev_import_row->document_number);
        datev_import_row->document_number = NULL;
    }
    if (datev_import_row->eu_country_vat_id) {
        free(datev_import_row->eu_country_vat_id);
        datev_import_row->eu_country_vat_id = NULL;
    }
    if (datev_import_row->eu_tax_rate) {
        free(datev_import_row->eu_tax_rate);
        datev_import_row->eu_tax_rate = NULL;
    }
    if (datev_import_row->exchange_rate) {
        free(datev_import_row->exchange_rate);
        datev_import_row->exchange_rate = NULL;
    }
    if (datev_import_row->opposite_account) {
        free(datev_import_row->opposite_account);
        datev_import_row->opposite_account = NULL;
    }
    free(datev_import_row);
}

cJSON *datev_import_row_convertToJSON(datev_import_row_t *datev_import_row) {
    cJSON *item = cJSON_CreateObject();

    // datev_import_row->account
    if (!datev_import_row->account) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "account", datev_import_row->account) == NULL) {
    goto fail; //String
    }


    // datev_import_row->amount
    if (!datev_import_row->amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "amount", datev_import_row->amount) == NULL) {
    goto fail; //String
    }


    // datev_import_row->base_amount
    if (!datev_import_row->base_amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "base_amount", datev_import_row->base_amount) == NULL) {
    goto fail; //String
    }


    // datev_import_row->base_currency
    if (!datev_import_row->base_currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "base_currency", datev_import_row->base_currency) == NULL) {
    goto fail; //String
    }


    // datev_import_row->booking_text
    if (!datev_import_row->booking_text) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "booking_text", datev_import_row->booking_text) == NULL) {
    goto fail; //String
    }


    // datev_import_row->bu_key
    if (!datev_import_row->bu_key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "bu_key", datev_import_row->bu_key) == NULL) {
    goto fail; //String
    }


    // datev_import_row->cost_center1
    if (!datev_import_row->cost_center1) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "cost_center1", datev_import_row->cost_center1) == NULL) {
    goto fail; //String
    }


    // datev_import_row->cost_center2
    if (!datev_import_row->cost_center2) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "cost_center2", datev_import_row->cost_center2) == NULL) {
    goto fail; //String
    }


    // datev_import_row->currency
    if (!datev_import_row->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", datev_import_row->currency) == NULL) {
    goto fail; //String
    }


    // datev_import_row->debit_credit
    if (!datev_import_row->debit_credit) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "debit_credit", datev_import_row->debit_credit) == NULL) {
    goto fail; //String
    }


    // datev_import_row->discount
    if (!datev_import_row->discount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "discount", datev_import_row->discount) == NULL) {
    goto fail; //String
    }


    // datev_import_row->document_date
    if (!datev_import_row->document_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "document_date", datev_import_row->document_date) == NULL) {
    goto fail; //String
    }


    // datev_import_row->document_field2
    if (!datev_import_row->document_field2) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "document_field2", datev_import_row->document_field2) == NULL) {
    goto fail; //String
    }


    // datev_import_row->document_number
    if (!datev_import_row->document_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "document_number", datev_import_row->document_number) == NULL) {
    goto fail; //String
    }


    // datev_import_row->eu_country_vat_id
    if (!datev_import_row->eu_country_vat_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "eu_country_vat_id", datev_import_row->eu_country_vat_id) == NULL) {
    goto fail; //String
    }


    // datev_import_row->eu_tax_rate
    if (!datev_import_row->eu_tax_rate) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "eu_tax_rate", datev_import_row->eu_tax_rate) == NULL) {
    goto fail; //String
    }


    // datev_import_row->exchange_rate
    if (!datev_import_row->exchange_rate) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "exchange_rate", datev_import_row->exchange_rate) == NULL) {
    goto fail; //String
    }


    // datev_import_row->opposite_account
    if (!datev_import_row->opposite_account) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "opposite_account", datev_import_row->opposite_account) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

datev_import_row_t *datev_import_row_parseFromJSON(cJSON *datev_import_rowJSON){

    datev_import_row_t *datev_import_row_local_var = NULL;

    char *account_local_str = NULL;

    char *amount_local_str = NULL;

    char *base_amount_local_str = NULL;

    char *base_currency_local_str = NULL;

    char *booking_text_local_str = NULL;

    char *bu_key_local_str = NULL;

    char *cost_center1_local_str = NULL;

    char *cost_center2_local_str = NULL;

    char *currency_local_str = NULL;

    char *debit_credit_local_str = NULL;

    char *discount_local_str = NULL;

    char *document_date_local_str = NULL;

    char *document_field2_local_str = NULL;

    char *document_number_local_str = NULL;

    char *eu_country_vat_id_local_str = NULL;

    char *eu_tax_rate_local_str = NULL;

    char *exchange_rate_local_str = NULL;

    char *opposite_account_local_str = NULL;

    // datev_import_row->account
    cJSON *account = cJSON_GetObjectItemCaseSensitive(datev_import_rowJSON, "account");
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

    // datev_import_row->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(datev_import_rowJSON, "amount");
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

    // datev_import_row->base_amount
    cJSON *base_amount = cJSON_GetObjectItemCaseSensitive(datev_import_rowJSON, "base_amount");
    if (cJSON_IsNull(base_amount)) {
        base_amount = NULL;
    }
    if (!base_amount) {
        goto end;
    }

    
    if(!cJSON_IsString(base_amount))
    {
    goto end; //String
    }

    // datev_import_row->base_currency
    cJSON *base_currency = cJSON_GetObjectItemCaseSensitive(datev_import_rowJSON, "base_currency");
    if (cJSON_IsNull(base_currency)) {
        base_currency = NULL;
    }
    if (!base_currency) {
        goto end;
    }

    
    if(!cJSON_IsString(base_currency))
    {
    goto end; //String
    }

    // datev_import_row->booking_text
    cJSON *booking_text = cJSON_GetObjectItemCaseSensitive(datev_import_rowJSON, "booking_text");
    if (cJSON_IsNull(booking_text)) {
        booking_text = NULL;
    }
    if (!booking_text) {
        goto end;
    }

    
    if(!cJSON_IsString(booking_text))
    {
    goto end; //String
    }

    // datev_import_row->bu_key
    cJSON *bu_key = cJSON_GetObjectItemCaseSensitive(datev_import_rowJSON, "bu_key");
    if (cJSON_IsNull(bu_key)) {
        bu_key = NULL;
    }
    if (!bu_key) {
        goto end;
    }

    
    if(!cJSON_IsString(bu_key))
    {
    goto end; //String
    }

    // datev_import_row->cost_center1
    cJSON *cost_center1 = cJSON_GetObjectItemCaseSensitive(datev_import_rowJSON, "cost_center1");
    if (cJSON_IsNull(cost_center1)) {
        cost_center1 = NULL;
    }
    if (!cost_center1) {
        goto end;
    }

    
    if(!cJSON_IsString(cost_center1))
    {
    goto end; //String
    }

    // datev_import_row->cost_center2
    cJSON *cost_center2 = cJSON_GetObjectItemCaseSensitive(datev_import_rowJSON, "cost_center2");
    if (cJSON_IsNull(cost_center2)) {
        cost_center2 = NULL;
    }
    if (!cost_center2) {
        goto end;
    }

    
    if(!cJSON_IsString(cost_center2))
    {
    goto end; //String
    }

    // datev_import_row->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(datev_import_rowJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (!currency) {
        goto end;
    }

    
    if(!cJSON_IsString(currency))
    {
    goto end; //String
    }

    // datev_import_row->debit_credit
    cJSON *debit_credit = cJSON_GetObjectItemCaseSensitive(datev_import_rowJSON, "debit_credit");
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

    // datev_import_row->discount
    cJSON *discount = cJSON_GetObjectItemCaseSensitive(datev_import_rowJSON, "discount");
    if (cJSON_IsNull(discount)) {
        discount = NULL;
    }
    if (!discount) {
        goto end;
    }

    
    if(!cJSON_IsString(discount))
    {
    goto end; //String
    }

    // datev_import_row->document_date
    cJSON *document_date = cJSON_GetObjectItemCaseSensitive(datev_import_rowJSON, "document_date");
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

    // datev_import_row->document_field2
    cJSON *document_field2 = cJSON_GetObjectItemCaseSensitive(datev_import_rowJSON, "document_field2");
    if (cJSON_IsNull(document_field2)) {
        document_field2 = NULL;
    }
    if (!document_field2) {
        goto end;
    }

    
    if(!cJSON_IsString(document_field2))
    {
    goto end; //String
    }

    // datev_import_row->document_number
    cJSON *document_number = cJSON_GetObjectItemCaseSensitive(datev_import_rowJSON, "document_number");
    if (cJSON_IsNull(document_number)) {
        document_number = NULL;
    }
    if (!document_number) {
        goto end;
    }

    
    if(!cJSON_IsString(document_number))
    {
    goto end; //String
    }

    // datev_import_row->eu_country_vat_id
    cJSON *eu_country_vat_id = cJSON_GetObjectItemCaseSensitive(datev_import_rowJSON, "eu_country_vat_id");
    if (cJSON_IsNull(eu_country_vat_id)) {
        eu_country_vat_id = NULL;
    }
    if (!eu_country_vat_id) {
        goto end;
    }

    
    if(!cJSON_IsString(eu_country_vat_id))
    {
    goto end; //String
    }

    // datev_import_row->eu_tax_rate
    cJSON *eu_tax_rate = cJSON_GetObjectItemCaseSensitive(datev_import_rowJSON, "eu_tax_rate");
    if (cJSON_IsNull(eu_tax_rate)) {
        eu_tax_rate = NULL;
    }
    if (!eu_tax_rate) {
        goto end;
    }

    
    if(!cJSON_IsString(eu_tax_rate))
    {
    goto end; //String
    }

    // datev_import_row->exchange_rate
    cJSON *exchange_rate = cJSON_GetObjectItemCaseSensitive(datev_import_rowJSON, "exchange_rate");
    if (cJSON_IsNull(exchange_rate)) {
        exchange_rate = NULL;
    }
    if (!exchange_rate) {
        goto end;
    }

    
    if(!cJSON_IsString(exchange_rate))
    {
    goto end; //String
    }

    // datev_import_row->opposite_account
    cJSON *opposite_account = cJSON_GetObjectItemCaseSensitive(datev_import_rowJSON, "opposite_account");
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


    if (account && !cJSON_IsNull(account)) account_local_str = strdup(account->valuestring);
    if (amount && !cJSON_IsNull(amount)) amount_local_str = strdup(amount->valuestring);
    if (base_amount && !cJSON_IsNull(base_amount)) base_amount_local_str = strdup(base_amount->valuestring);
    if (base_currency && !cJSON_IsNull(base_currency)) base_currency_local_str = strdup(base_currency->valuestring);
    if (booking_text && !cJSON_IsNull(booking_text)) booking_text_local_str = strdup(booking_text->valuestring);
    if (bu_key && !cJSON_IsNull(bu_key)) bu_key_local_str = strdup(bu_key->valuestring);
    if (cost_center1 && !cJSON_IsNull(cost_center1)) cost_center1_local_str = strdup(cost_center1->valuestring);
    if (cost_center2 && !cJSON_IsNull(cost_center2)) cost_center2_local_str = strdup(cost_center2->valuestring);
    if (currency && !cJSON_IsNull(currency)) currency_local_str = strdup(currency->valuestring);
    if (debit_credit && !cJSON_IsNull(debit_credit)) debit_credit_local_str = strdup(debit_credit->valuestring);
    if (discount && !cJSON_IsNull(discount)) discount_local_str = strdup(discount->valuestring);
    if (document_date && !cJSON_IsNull(document_date)) document_date_local_str = strdup(document_date->valuestring);
    if (document_field2 && !cJSON_IsNull(document_field2)) document_field2_local_str = strdup(document_field2->valuestring);
    if (document_number && !cJSON_IsNull(document_number)) document_number_local_str = strdup(document_number->valuestring);
    if (eu_country_vat_id && !cJSON_IsNull(eu_country_vat_id)) eu_country_vat_id_local_str = strdup(eu_country_vat_id->valuestring);
    if (eu_tax_rate && !cJSON_IsNull(eu_tax_rate)) eu_tax_rate_local_str = strdup(eu_tax_rate->valuestring);
    if (exchange_rate && !cJSON_IsNull(exchange_rate)) exchange_rate_local_str = strdup(exchange_rate->valuestring);
    if (opposite_account && !cJSON_IsNull(opposite_account)) opposite_account_local_str = strdup(opposite_account->valuestring);

    datev_import_row_local_var = datev_import_row_create_internal (
        account_local_str,
        amount_local_str,
        base_amount_local_str,
        base_currency_local_str,
        booking_text_local_str,
        bu_key_local_str,
        cost_center1_local_str,
        cost_center2_local_str,
        currency_local_str,
        debit_credit_local_str,
        discount_local_str,
        document_date_local_str,
        document_field2_local_str,
        document_number_local_str,
        eu_country_vat_id_local_str,
        eu_tax_rate_local_str,
        exchange_rate_local_str,
        opposite_account_local_str
        );

    if (!datev_import_row_local_var) {
        goto end;
    }

    return datev_import_row_local_var;
end:
    if (account_local_str) {
        free(account_local_str);
        account_local_str = NULL;
    }
    if (amount_local_str) {
        free(amount_local_str);
        amount_local_str = NULL;
    }
    if (base_amount_local_str) {
        free(base_amount_local_str);
        base_amount_local_str = NULL;
    }
    if (base_currency_local_str) {
        free(base_currency_local_str);
        base_currency_local_str = NULL;
    }
    if (booking_text_local_str) {
        free(booking_text_local_str);
        booking_text_local_str = NULL;
    }
    if (bu_key_local_str) {
        free(bu_key_local_str);
        bu_key_local_str = NULL;
    }
    if (cost_center1_local_str) {
        free(cost_center1_local_str);
        cost_center1_local_str = NULL;
    }
    if (cost_center2_local_str) {
        free(cost_center2_local_str);
        cost_center2_local_str = NULL;
    }
    if (currency_local_str) {
        free(currency_local_str);
        currency_local_str = NULL;
    }
    if (debit_credit_local_str) {
        free(debit_credit_local_str);
        debit_credit_local_str = NULL;
    }
    if (discount_local_str) {
        free(discount_local_str);
        discount_local_str = NULL;
    }
    if (document_date_local_str) {
        free(document_date_local_str);
        document_date_local_str = NULL;
    }
    if (document_field2_local_str) {
        free(document_field2_local_str);
        document_field2_local_str = NULL;
    }
    if (document_number_local_str) {
        free(document_number_local_str);
        document_number_local_str = NULL;
    }
    if (eu_country_vat_id_local_str) {
        free(eu_country_vat_id_local_str);
        eu_country_vat_id_local_str = NULL;
    }
    if (eu_tax_rate_local_str) {
        free(eu_tax_rate_local_str);
        eu_tax_rate_local_str = NULL;
    }
    if (exchange_rate_local_str) {
        free(exchange_rate_local_str);
        exchange_rate_local_str = NULL;
    }
    if (opposite_account_local_str) {
        free(opposite_account_local_str);
        opposite_account_local_str = NULL;
    }
    return NULL;

}
