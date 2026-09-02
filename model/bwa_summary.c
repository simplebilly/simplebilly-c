#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bwa_summary.h"



static bwa_summary_t *bwa_summary_create_internal(
    char *gross_profit,
    char *net_profit,
    long *open_invoices_count,
    char *open_invoices_total,
    long *overdue_invoices_count,
    char *overdue_invoices_total,
    double *profit_margin
    ) {
    bwa_summary_t *bwa_summary_local_var = malloc(sizeof(bwa_summary_t));
    if (!bwa_summary_local_var) {
        return NULL;
    }
    memset(bwa_summary_local_var, 0, sizeof(bwa_summary_t));
    bwa_summary_local_var->_library_owned = 1;
    bwa_summary_local_var->gross_profit = gross_profit;
    bwa_summary_local_var->net_profit = net_profit;
    bwa_summary_local_var->open_invoices_count = open_invoices_count;
    bwa_summary_local_var->open_invoices_total = open_invoices_total;
    bwa_summary_local_var->overdue_invoices_count = overdue_invoices_count;
    bwa_summary_local_var->overdue_invoices_total = overdue_invoices_total;
    bwa_summary_local_var->profit_margin = profit_margin;
    return bwa_summary_local_var;
}

__attribute__((deprecated)) bwa_summary_t *bwa_summary_create(
    char *gross_profit,
    char *net_profit,
    long *open_invoices_count,
    char *open_invoices_total,
    long *overdue_invoices_count,
    char *overdue_invoices_total,
    double *profit_margin
    ) {
    long *open_invoices_count_copy = NULL;
    if (open_invoices_count) {
        open_invoices_count_copy = malloc(sizeof(long));
        if (open_invoices_count_copy) *open_invoices_count_copy = *open_invoices_count;
    }
    long *overdue_invoices_count_copy = NULL;
    if (overdue_invoices_count) {
        overdue_invoices_count_copy = malloc(sizeof(long));
        if (overdue_invoices_count_copy) *overdue_invoices_count_copy = *overdue_invoices_count;
    }
    double *profit_margin_copy = NULL;
    if (profit_margin) {
        profit_margin_copy = malloc(sizeof(double));
        if (profit_margin_copy) *profit_margin_copy = *profit_margin;
    }
    bwa_summary_t *result = bwa_summary_create_internal (
        gross_profit,
        net_profit,
        open_invoices_count_copy,
        open_invoices_total,
        overdue_invoices_count_copy,
        overdue_invoices_total,
        profit_margin_copy
        );
    if (!result) {
        free(open_invoices_count_copy);
        free(overdue_invoices_count_copy);
        free(profit_margin_copy);
    }
    return result;
}

void bwa_summary_free(bwa_summary_t *bwa_summary) {
    if(NULL == bwa_summary){
        return ;
    }
    if(bwa_summary->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "bwa_summary_free");
        return ;
    }
    listEntry_t *listEntry;
    if (bwa_summary->gross_profit) {
        free(bwa_summary->gross_profit);
        bwa_summary->gross_profit = NULL;
    }
    if (bwa_summary->net_profit) {
        free(bwa_summary->net_profit);
        bwa_summary->net_profit = NULL;
    }
    if (bwa_summary->open_invoices_count) {
        free(bwa_summary->open_invoices_count);
        bwa_summary->open_invoices_count = NULL;
    }
    if (bwa_summary->open_invoices_total) {
        free(bwa_summary->open_invoices_total);
        bwa_summary->open_invoices_total = NULL;
    }
    if (bwa_summary->overdue_invoices_count) {
        free(bwa_summary->overdue_invoices_count);
        bwa_summary->overdue_invoices_count = NULL;
    }
    if (bwa_summary->overdue_invoices_total) {
        free(bwa_summary->overdue_invoices_total);
        bwa_summary->overdue_invoices_total = NULL;
    }
    if (bwa_summary->profit_margin) {
        free(bwa_summary->profit_margin);
        bwa_summary->profit_margin = NULL;
    }
    free(bwa_summary);
}

cJSON *bwa_summary_convertToJSON(bwa_summary_t *bwa_summary) {
    cJSON *item = cJSON_CreateObject();

    // bwa_summary->gross_profit
    if (!bwa_summary->gross_profit) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gross_profit", bwa_summary->gross_profit) == NULL) {
    goto fail; //String
    }


    // bwa_summary->net_profit
    if (!bwa_summary->net_profit) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "net_profit", bwa_summary->net_profit) == NULL) {
    goto fail; //String
    }


    // bwa_summary->open_invoices_count
    if (!bwa_summary->open_invoices_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "open_invoices_count", *bwa_summary->open_invoices_count) == NULL) {
    goto fail; //Numeric
    }


    // bwa_summary->open_invoices_total
    if (!bwa_summary->open_invoices_total) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "open_invoices_total", bwa_summary->open_invoices_total) == NULL) {
    goto fail; //String
    }


    // bwa_summary->overdue_invoices_count
    if (!bwa_summary->overdue_invoices_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "overdue_invoices_count", *bwa_summary->overdue_invoices_count) == NULL) {
    goto fail; //Numeric
    }


    // bwa_summary->overdue_invoices_total
    if (!bwa_summary->overdue_invoices_total) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "overdue_invoices_total", bwa_summary->overdue_invoices_total) == NULL) {
    goto fail; //String
    }


    // bwa_summary->profit_margin
    if (!bwa_summary->profit_margin) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "profit_margin", *bwa_summary->profit_margin) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

bwa_summary_t *bwa_summary_parseFromJSON(cJSON *bwa_summaryJSON){

    bwa_summary_t *bwa_summary_local_var = NULL;

    char *gross_profit_local_str = NULL;

    char *net_profit_local_str = NULL;

    // define the local variable for bwa_summary->open_invoices_count
    long *open_invoices_count_local_var = NULL;

    char *open_invoices_total_local_str = NULL;

    // define the local variable for bwa_summary->overdue_invoices_count
    long *overdue_invoices_count_local_var = NULL;

    char *overdue_invoices_total_local_str = NULL;

    // define the local variable for bwa_summary->profit_margin
    double *profit_margin_local_var = NULL;

    // bwa_summary->gross_profit
    cJSON *gross_profit = cJSON_GetObjectItemCaseSensitive(bwa_summaryJSON, "gross_profit");
    if (cJSON_IsNull(gross_profit)) {
        gross_profit = NULL;
    }
    if (!gross_profit) {
        goto end;
    }

    
    if(!cJSON_IsString(gross_profit))
    {
    goto end; //String
    }

    // bwa_summary->net_profit
    cJSON *net_profit = cJSON_GetObjectItemCaseSensitive(bwa_summaryJSON, "net_profit");
    if (cJSON_IsNull(net_profit)) {
        net_profit = NULL;
    }
    if (!net_profit) {
        goto end;
    }

    
    if(!cJSON_IsString(net_profit))
    {
    goto end; //String
    }

    // bwa_summary->open_invoices_count
    cJSON *open_invoices_count = cJSON_GetObjectItemCaseSensitive(bwa_summaryJSON, "open_invoices_count");
    if (cJSON_IsNull(open_invoices_count)) {
        open_invoices_count = NULL;
    }
    if (!open_invoices_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(open_invoices_count))
    {
    goto end; //Numeric
    }
    open_invoices_count_local_var = malloc(sizeof(long));
    if(!open_invoices_count_local_var)
    {
        goto end;
    }
    *open_invoices_count_local_var = open_invoices_count->valuedouble;

    // bwa_summary->open_invoices_total
    cJSON *open_invoices_total = cJSON_GetObjectItemCaseSensitive(bwa_summaryJSON, "open_invoices_total");
    if (cJSON_IsNull(open_invoices_total)) {
        open_invoices_total = NULL;
    }
    if (!open_invoices_total) {
        goto end;
    }

    
    if(!cJSON_IsString(open_invoices_total))
    {
    goto end; //String
    }

    // bwa_summary->overdue_invoices_count
    cJSON *overdue_invoices_count = cJSON_GetObjectItemCaseSensitive(bwa_summaryJSON, "overdue_invoices_count");
    if (cJSON_IsNull(overdue_invoices_count)) {
        overdue_invoices_count = NULL;
    }
    if (!overdue_invoices_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(overdue_invoices_count))
    {
    goto end; //Numeric
    }
    overdue_invoices_count_local_var = malloc(sizeof(long));
    if(!overdue_invoices_count_local_var)
    {
        goto end;
    }
    *overdue_invoices_count_local_var = overdue_invoices_count->valuedouble;

    // bwa_summary->overdue_invoices_total
    cJSON *overdue_invoices_total = cJSON_GetObjectItemCaseSensitive(bwa_summaryJSON, "overdue_invoices_total");
    if (cJSON_IsNull(overdue_invoices_total)) {
        overdue_invoices_total = NULL;
    }
    if (!overdue_invoices_total) {
        goto end;
    }

    
    if(!cJSON_IsString(overdue_invoices_total))
    {
    goto end; //String
    }

    // bwa_summary->profit_margin
    cJSON *profit_margin = cJSON_GetObjectItemCaseSensitive(bwa_summaryJSON, "profit_margin");
    if (cJSON_IsNull(profit_margin)) {
        profit_margin = NULL;
    }
    if (!profit_margin) {
        goto end;
    }

    
    if(!cJSON_IsNumber(profit_margin))
    {
    goto end; //Numeric
    }
    profit_margin_local_var = malloc(sizeof(double));
    if(!profit_margin_local_var)
    {
        goto end;
    }
    *profit_margin_local_var = profit_margin->valuedouble;


    if (gross_profit && !cJSON_IsNull(gross_profit)) gross_profit_local_str = strdup(gross_profit->valuestring);
    if (net_profit && !cJSON_IsNull(net_profit)) net_profit_local_str = strdup(net_profit->valuestring);
    if (open_invoices_total && !cJSON_IsNull(open_invoices_total)) open_invoices_total_local_str = strdup(open_invoices_total->valuestring);
    if (overdue_invoices_total && !cJSON_IsNull(overdue_invoices_total)) overdue_invoices_total_local_str = strdup(overdue_invoices_total->valuestring);

    bwa_summary_local_var = bwa_summary_create_internal (
        gross_profit_local_str,
        net_profit_local_str,
        open_invoices_count_local_var,
        open_invoices_total_local_str,
        overdue_invoices_count_local_var,
        overdue_invoices_total_local_str,
        profit_margin_local_var
        );

    if (!bwa_summary_local_var) {
        goto end;
    }

    return bwa_summary_local_var;
end:
    if (gross_profit_local_str) {
        free(gross_profit_local_str);
        gross_profit_local_str = NULL;
    }
    if (net_profit_local_str) {
        free(net_profit_local_str);
        net_profit_local_str = NULL;
    }
    if (open_invoices_count_local_var) {
        free(open_invoices_count_local_var);
        open_invoices_count_local_var = NULL;
    }
    if (open_invoices_total_local_str) {
        free(open_invoices_total_local_str);
        open_invoices_total_local_str = NULL;
    }
    if (overdue_invoices_count_local_var) {
        free(overdue_invoices_count_local_var);
        overdue_invoices_count_local_var = NULL;
    }
    if (overdue_invoices_total_local_str) {
        free(overdue_invoices_total_local_str);
        overdue_invoices_total_local_str = NULL;
    }
    if (profit_margin_local_var) {
        free(profit_margin_local_var);
        profit_margin_local_var = NULL;
    }
    return NULL;

}
