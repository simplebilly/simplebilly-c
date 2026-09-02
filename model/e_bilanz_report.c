#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "e_bilanz_report.h"



static e_bilanz_report_t *e_bilanz_report_create_internal(
    list_t *account_overview,
    balance_sheet_t *balance_sheet,
    char *generated_at,
    income_statement_t *income_statement,
    char *period,
    vat_summary_t *vat_summary
    ) {
    e_bilanz_report_t *e_bilanz_report_local_var = malloc(sizeof(e_bilanz_report_t));
    if (!e_bilanz_report_local_var) {
        return NULL;
    }
    memset(e_bilanz_report_local_var, 0, sizeof(e_bilanz_report_t));
    e_bilanz_report_local_var->_library_owned = 1;
    e_bilanz_report_local_var->account_overview = account_overview;
    e_bilanz_report_local_var->balance_sheet = balance_sheet;
    e_bilanz_report_local_var->generated_at = generated_at;
    e_bilanz_report_local_var->income_statement = income_statement;
    e_bilanz_report_local_var->period = period;
    e_bilanz_report_local_var->vat_summary = vat_summary;
    return e_bilanz_report_local_var;
}

__attribute__((deprecated)) e_bilanz_report_t *e_bilanz_report_create(
    list_t *account_overview,
    balance_sheet_t *balance_sheet,
    char *generated_at,
    income_statement_t *income_statement,
    char *period,
    vat_summary_t *vat_summary
    ) {
    e_bilanz_report_t *result = e_bilanz_report_create_internal (
        account_overview,
        balance_sheet,
        generated_at,
        income_statement,
        period,
        vat_summary
        );
    if (!result) {
    }
    return result;
}

void e_bilanz_report_free(e_bilanz_report_t *e_bilanz_report) {
    if(NULL == e_bilanz_report){
        return ;
    }
    if(e_bilanz_report->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "e_bilanz_report_free");
        return ;
    }
    listEntry_t *listEntry;
    if (e_bilanz_report->account_overview) {
        list_ForEach(listEntry, e_bilanz_report->account_overview) {
            account_overview_free(listEntry->data);
        }
        list_freeList(e_bilanz_report->account_overview);
        e_bilanz_report->account_overview = NULL;
    }
    if (e_bilanz_report->balance_sheet) {
        balance_sheet_free(e_bilanz_report->balance_sheet);
        e_bilanz_report->balance_sheet = NULL;
    }
    if (e_bilanz_report->generated_at) {
        free(e_bilanz_report->generated_at);
        e_bilanz_report->generated_at = NULL;
    }
    if (e_bilanz_report->income_statement) {
        income_statement_free(e_bilanz_report->income_statement);
        e_bilanz_report->income_statement = NULL;
    }
    if (e_bilanz_report->period) {
        free(e_bilanz_report->period);
        e_bilanz_report->period = NULL;
    }
    if (e_bilanz_report->vat_summary) {
        vat_summary_free(e_bilanz_report->vat_summary);
        e_bilanz_report->vat_summary = NULL;
    }
    free(e_bilanz_report);
}

cJSON *e_bilanz_report_convertToJSON(e_bilanz_report_t *e_bilanz_report) {
    cJSON *item = cJSON_CreateObject();

    // e_bilanz_report->account_overview
    if (!e_bilanz_report->account_overview) {
        goto fail;
    }
    cJSON *account_overview = cJSON_AddArrayToObject(item, "account_overview");
    if(account_overview == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *account_overviewListEntry;
    if (e_bilanz_report->account_overview) {
    list_ForEach(account_overviewListEntry, e_bilanz_report->account_overview) {
    cJSON *itemLocal = account_overview_convertToJSON(account_overviewListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(account_overview, itemLocal);
    }
    }


    // e_bilanz_report->balance_sheet
    if (!e_bilanz_report->balance_sheet) {
        goto fail;
    }
    cJSON *balance_sheet_local_JSON = balance_sheet_convertToJSON(e_bilanz_report->balance_sheet);
    if(balance_sheet_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "balance_sheet", balance_sheet_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // e_bilanz_report->generated_at
    if (!e_bilanz_report->generated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "generated_at", e_bilanz_report->generated_at) == NULL) {
    goto fail; //String
    }


    // e_bilanz_report->income_statement
    if (!e_bilanz_report->income_statement) {
        goto fail;
    }
    cJSON *income_statement_local_JSON = income_statement_convertToJSON(e_bilanz_report->income_statement);
    if(income_statement_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "income_statement", income_statement_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // e_bilanz_report->period
    if (!e_bilanz_report->period) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "period", e_bilanz_report->period) == NULL) {
    goto fail; //String
    }


    // e_bilanz_report->vat_summary
    if (!e_bilanz_report->vat_summary) {
        goto fail;
    }
    cJSON *vat_summary_local_JSON = vat_summary_convertToJSON(e_bilanz_report->vat_summary);
    if(vat_summary_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "vat_summary", vat_summary_local_JSON);
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

e_bilanz_report_t *e_bilanz_report_parseFromJSON(cJSON *e_bilanz_reportJSON){

    e_bilanz_report_t *e_bilanz_report_local_var = NULL;

    // define the local list for e_bilanz_report->account_overview
    list_t *account_overviewList = NULL;

    // define the local variable for e_bilanz_report->balance_sheet
    balance_sheet_t *balance_sheet_local_nonprim = NULL;

    char *generated_at_local_str = NULL;

    // define the local variable for e_bilanz_report->income_statement
    income_statement_t *income_statement_local_nonprim = NULL;

    char *period_local_str = NULL;

    // define the local variable for e_bilanz_report->vat_summary
    vat_summary_t *vat_summary_local_nonprim = NULL;

    // e_bilanz_report->account_overview
    cJSON *account_overview = cJSON_GetObjectItemCaseSensitive(e_bilanz_reportJSON, "account_overview");
    if (cJSON_IsNull(account_overview)) {
        account_overview = NULL;
    }
    if (!account_overview) {
        goto end;
    }

    
    cJSON *account_overview_local_nonprimitive = NULL;
    if(!cJSON_IsArray(account_overview)){
        goto end; //nonprimitive container
    }

    account_overviewList = list_createList();

    cJSON_ArrayForEach(account_overview_local_nonprimitive,account_overview )
    {
        if(!cJSON_IsObject(account_overview_local_nonprimitive)){
            goto end;
        }
        account_overview_t *account_overviewItem = account_overview_parseFromJSON(account_overview_local_nonprimitive);

        list_addElement(account_overviewList, account_overviewItem);
    }

    // e_bilanz_report->balance_sheet
    cJSON *balance_sheet = cJSON_GetObjectItemCaseSensitive(e_bilanz_reportJSON, "balance_sheet");
    if (cJSON_IsNull(balance_sheet)) {
        balance_sheet = NULL;
    }
    if (!balance_sheet) {
        goto end;
    }

    
    balance_sheet_local_nonprim = balance_sheet_parseFromJSON(balance_sheet); //nonprimitive

    // e_bilanz_report->generated_at
    cJSON *generated_at = cJSON_GetObjectItemCaseSensitive(e_bilanz_reportJSON, "generated_at");
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

    // e_bilanz_report->income_statement
    cJSON *income_statement = cJSON_GetObjectItemCaseSensitive(e_bilanz_reportJSON, "income_statement");
    if (cJSON_IsNull(income_statement)) {
        income_statement = NULL;
    }
    if (!income_statement) {
        goto end;
    }

    
    income_statement_local_nonprim = income_statement_parseFromJSON(income_statement); //nonprimitive

    // e_bilanz_report->period
    cJSON *period = cJSON_GetObjectItemCaseSensitive(e_bilanz_reportJSON, "period");
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

    // e_bilanz_report->vat_summary
    cJSON *vat_summary = cJSON_GetObjectItemCaseSensitive(e_bilanz_reportJSON, "vat_summary");
    if (cJSON_IsNull(vat_summary)) {
        vat_summary = NULL;
    }
    if (!vat_summary) {
        goto end;
    }

    
    vat_summary_local_nonprim = vat_summary_parseFromJSON(vat_summary); //nonprimitive


    if (generated_at && !cJSON_IsNull(generated_at)) generated_at_local_str = strdup(generated_at->valuestring);
    if (period && !cJSON_IsNull(period)) period_local_str = strdup(period->valuestring);

    e_bilanz_report_local_var = e_bilanz_report_create_internal (
        account_overviewList,
        balance_sheet_local_nonprim,
        generated_at_local_str,
        income_statement_local_nonprim,
        period_local_str,
        vat_summary_local_nonprim
        );

    if (!e_bilanz_report_local_var) {
        goto end;
    }

    return e_bilanz_report_local_var;
end:
    if (account_overviewList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, account_overviewList) {
            account_overview_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(account_overviewList);
        account_overviewList = NULL;
    }
    if (balance_sheet_local_nonprim) {
        balance_sheet_free(balance_sheet_local_nonprim);
        balance_sheet_local_nonprim = NULL;
    }
    if (generated_at_local_str) {
        free(generated_at_local_str);
        generated_at_local_str = NULL;
    }
    if (income_statement_local_nonprim) {
        income_statement_free(income_statement_local_nonprim);
        income_statement_local_nonprim = NULL;
    }
    if (period_local_str) {
        free(period_local_str);
        period_local_str = NULL;
    }
    if (vat_summary_local_nonprim) {
        vat_summary_free(vat_summary_local_nonprim);
        vat_summary_local_nonprim = NULL;
    }
    return NULL;

}
