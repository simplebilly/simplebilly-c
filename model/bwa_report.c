#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bwa_report.h"



static bwa_report_t *bwa_report_create_internal(
    bwa_expenses_t *expenses,
    char *generated_at,
    char *period,
    bwa_revenue_t *revenue,
    bwa_summary_t *summary
    ) {
    bwa_report_t *bwa_report_local_var = malloc(sizeof(bwa_report_t));
    if (!bwa_report_local_var) {
        return NULL;
    }
    memset(bwa_report_local_var, 0, sizeof(bwa_report_t));
    bwa_report_local_var->_library_owned = 1;
    bwa_report_local_var->expenses = expenses;
    bwa_report_local_var->generated_at = generated_at;
    bwa_report_local_var->period = period;
    bwa_report_local_var->revenue = revenue;
    bwa_report_local_var->summary = summary;
    return bwa_report_local_var;
}

__attribute__((deprecated)) bwa_report_t *bwa_report_create(
    bwa_expenses_t *expenses,
    char *generated_at,
    char *period,
    bwa_revenue_t *revenue,
    bwa_summary_t *summary
    ) {
    bwa_report_t *result = bwa_report_create_internal (
        expenses,
        generated_at,
        period,
        revenue,
        summary
        );
    if (!result) {
    }
    return result;
}

void bwa_report_free(bwa_report_t *bwa_report) {
    if(NULL == bwa_report){
        return ;
    }
    if(bwa_report->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "bwa_report_free");
        return ;
    }
    listEntry_t *listEntry;
    if (bwa_report->expenses) {
        bwa_expenses_free(bwa_report->expenses);
        bwa_report->expenses = NULL;
    }
    if (bwa_report->generated_at) {
        free(bwa_report->generated_at);
        bwa_report->generated_at = NULL;
    }
    if (bwa_report->period) {
        free(bwa_report->period);
        bwa_report->period = NULL;
    }
    if (bwa_report->revenue) {
        bwa_revenue_free(bwa_report->revenue);
        bwa_report->revenue = NULL;
    }
    if (bwa_report->summary) {
        bwa_summary_free(bwa_report->summary);
        bwa_report->summary = NULL;
    }
    free(bwa_report);
}

cJSON *bwa_report_convertToJSON(bwa_report_t *bwa_report) {
    cJSON *item = cJSON_CreateObject();

    // bwa_report->expenses
    if (!bwa_report->expenses) {
        goto fail;
    }
    cJSON *expenses_local_JSON = bwa_expenses_convertToJSON(bwa_report->expenses);
    if(expenses_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "expenses", expenses_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // bwa_report->generated_at
    if (!bwa_report->generated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "generated_at", bwa_report->generated_at) == NULL) {
    goto fail; //String
    }


    // bwa_report->period
    if (!bwa_report->period) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "period", bwa_report->period) == NULL) {
    goto fail; //String
    }


    // bwa_report->revenue
    if (!bwa_report->revenue) {
        goto fail;
    }
    cJSON *revenue_local_JSON = bwa_revenue_convertToJSON(bwa_report->revenue);
    if(revenue_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "revenue", revenue_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // bwa_report->summary
    if (!bwa_report->summary) {
        goto fail;
    }
    cJSON *summary_local_JSON = bwa_summary_convertToJSON(bwa_report->summary);
    if(summary_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "summary", summary_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

bwa_report_t *bwa_report_parseFromJSON(cJSON *bwa_reportJSON){

    bwa_report_t *bwa_report_local_var = NULL;

    // define the local variable for bwa_report->expenses
    bwa_expenses_t *expenses_local_nonprim = NULL;

    char *generated_at_local_str = NULL;

    char *period_local_str = NULL;

    // define the local variable for bwa_report->revenue
    bwa_revenue_t *revenue_local_nonprim = NULL;

    // define the local variable for bwa_report->summary
    bwa_summary_t *summary_local_nonprim = NULL;

    // bwa_report->expenses
    cJSON *expenses = cJSON_GetObjectItemCaseSensitive(bwa_reportJSON, "expenses");
    if (cJSON_IsNull(expenses)) {
        expenses = NULL;
    }
    if (!expenses) {
        goto end;
    }

    
    expenses_local_nonprim = bwa_expenses_parseFromJSON(expenses); //nonprimitive

    // bwa_report->generated_at
    cJSON *generated_at = cJSON_GetObjectItemCaseSensitive(bwa_reportJSON, "generated_at");
    if (cJSON_IsNull(generated_at)) {
        generated_at = NULL;
    }
    if (!generated_at) {
        goto end;
    }

    
    if(!cJSON_IsString(generated_at))
    {
    goto end; //String
    }

    // bwa_report->period
    cJSON *period = cJSON_GetObjectItemCaseSensitive(bwa_reportJSON, "period");
    if (cJSON_IsNull(period)) {
        period = NULL;
    }
    if (!period) {
        goto end;
    }

    
    if(!cJSON_IsString(period))
    {
    goto end; //String
    }

    // bwa_report->revenue
    cJSON *revenue = cJSON_GetObjectItemCaseSensitive(bwa_reportJSON, "revenue");
    if (cJSON_IsNull(revenue)) {
        revenue = NULL;
    }
    if (!revenue) {
        goto end;
    }

    
    revenue_local_nonprim = bwa_revenue_parseFromJSON(revenue); //nonprimitive

    // bwa_report->summary
    cJSON *summary = cJSON_GetObjectItemCaseSensitive(bwa_reportJSON, "summary");
    if (cJSON_IsNull(summary)) {
        summary = NULL;
    }
    if (!summary) {
        goto end;
    }

    
    summary_local_nonprim = bwa_summary_parseFromJSON(summary); //nonprimitive


    if (generated_at && !cJSON_IsNull(generated_at)) generated_at_local_str = strdup(generated_at->valuestring);
    if (period && !cJSON_IsNull(period)) period_local_str = strdup(period->valuestring);

    bwa_report_local_var = bwa_report_create_internal (
        expenses_local_nonprim,
        generated_at_local_str,
        period_local_str,
        revenue_local_nonprim,
        summary_local_nonprim
        );

    if (!bwa_report_local_var) {
        goto end;
    }

    return bwa_report_local_var;
end:
    if (expenses_local_nonprim) {
        bwa_expenses_free(expenses_local_nonprim);
        expenses_local_nonprim = NULL;
    }
    if (generated_at_local_str) {
        free(generated_at_local_str);
        generated_at_local_str = NULL;
    }
    if (period_local_str) {
        free(period_local_str);
        period_local_str = NULL;
    }
    if (revenue_local_nonprim) {
        bwa_revenue_free(revenue_local_nonprim);
        revenue_local_nonprim = NULL;
    }
    if (summary_local_nonprim) {
        bwa_summary_free(summary_local_nonprim);
        summary_local_nonprim = NULL;
    }
    return NULL;

}
