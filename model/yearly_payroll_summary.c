#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "yearly_payroll_summary.h"



static yearly_payroll_summary_t *yearly_payroll_summary_create_internal(
    int *avg_employee_count,
    list_t *months,
    int *year,
    char *yearly_employer_cost,
    char *yearly_gross,
    char *yearly_net
    ) {
    yearly_payroll_summary_t *yearly_payroll_summary_local_var = malloc(sizeof(yearly_payroll_summary_t));
    if (!yearly_payroll_summary_local_var) {
        return NULL;
    }
    memset(yearly_payroll_summary_local_var, 0, sizeof(yearly_payroll_summary_t));
    yearly_payroll_summary_local_var->_library_owned = 1;
    yearly_payroll_summary_local_var->avg_employee_count = avg_employee_count;
    yearly_payroll_summary_local_var->months = months;
    yearly_payroll_summary_local_var->year = year;
    yearly_payroll_summary_local_var->yearly_employer_cost = yearly_employer_cost;
    yearly_payroll_summary_local_var->yearly_gross = yearly_gross;
    yearly_payroll_summary_local_var->yearly_net = yearly_net;
    return yearly_payroll_summary_local_var;
}

__attribute__((deprecated)) yearly_payroll_summary_t *yearly_payroll_summary_create(
    int *avg_employee_count,
    list_t *months,
    int *year,
    char *yearly_employer_cost,
    char *yearly_gross,
    char *yearly_net
    ) {
    int *avg_employee_count_copy = NULL;
    if (avg_employee_count) {
        avg_employee_count_copy = malloc(sizeof(int));
        if (avg_employee_count_copy) *avg_employee_count_copy = *avg_employee_count;
    }
    int *year_copy = NULL;
    if (year) {
        year_copy = malloc(sizeof(int));
        if (year_copy) *year_copy = *year;
    }
    yearly_payroll_summary_t *result = yearly_payroll_summary_create_internal (
        avg_employee_count_copy,
        months,
        year_copy,
        yearly_employer_cost,
        yearly_gross,
        yearly_net
        );
    if (!result) {
        free(avg_employee_count_copy);
        free(year_copy);
    }
    return result;
}

void yearly_payroll_summary_free(yearly_payroll_summary_t *yearly_payroll_summary) {
    if(NULL == yearly_payroll_summary){
        return ;
    }
    if(yearly_payroll_summary->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "yearly_payroll_summary_free");
        return ;
    }
    listEntry_t *listEntry;
    if (yearly_payroll_summary->avg_employee_count) {
        free(yearly_payroll_summary->avg_employee_count);
        yearly_payroll_summary->avg_employee_count = NULL;
    }
    if (yearly_payroll_summary->months) {
        list_ForEach(listEntry, yearly_payroll_summary->months) {
            payroll_summary_item_free(listEntry->data);
        }
        list_freeList(yearly_payroll_summary->months);
        yearly_payroll_summary->months = NULL;
    }
    if (yearly_payroll_summary->year) {
        free(yearly_payroll_summary->year);
        yearly_payroll_summary->year = NULL;
    }
    if (yearly_payroll_summary->yearly_employer_cost) {
        free(yearly_payroll_summary->yearly_employer_cost);
        yearly_payroll_summary->yearly_employer_cost = NULL;
    }
    if (yearly_payroll_summary->yearly_gross) {
        free(yearly_payroll_summary->yearly_gross);
        yearly_payroll_summary->yearly_gross = NULL;
    }
    if (yearly_payroll_summary->yearly_net) {
        free(yearly_payroll_summary->yearly_net);
        yearly_payroll_summary->yearly_net = NULL;
    }
    free(yearly_payroll_summary);
}

cJSON *yearly_payroll_summary_convertToJSON(yearly_payroll_summary_t *yearly_payroll_summary) {
    cJSON *item = cJSON_CreateObject();

    // yearly_payroll_summary->avg_employee_count
    if (!yearly_payroll_summary->avg_employee_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "avg_employee_count", *yearly_payroll_summary->avg_employee_count) == NULL) {
    goto fail; //Numeric
    }


    // yearly_payroll_summary->months
    if (!yearly_payroll_summary->months) {
        goto fail;
    }
    cJSON *months = cJSON_AddArrayToObject(item, "months");
    if(months == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *monthsListEntry;
    if (yearly_payroll_summary->months) {
    list_ForEach(monthsListEntry, yearly_payroll_summary->months) {
    cJSON *itemLocal = payroll_summary_item_convertToJSON(monthsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(months, itemLocal);
    }
    }


    // yearly_payroll_summary->year
    if (!yearly_payroll_summary->year) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "year", *yearly_payroll_summary->year) == NULL) {
    goto fail; //Numeric
    }


    // yearly_payroll_summary->yearly_employer_cost
    if (!yearly_payroll_summary->yearly_employer_cost) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "yearly_employer_cost", yearly_payroll_summary->yearly_employer_cost) == NULL) {
    goto fail; //String
    }


    // yearly_payroll_summary->yearly_gross
    if (!yearly_payroll_summary->yearly_gross) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "yearly_gross", yearly_payroll_summary->yearly_gross) == NULL) {
    goto fail; //String
    }


    // yearly_payroll_summary->yearly_net
    if (!yearly_payroll_summary->yearly_net) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "yearly_net", yearly_payroll_summary->yearly_net) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

yearly_payroll_summary_t *yearly_payroll_summary_parseFromJSON(cJSON *yearly_payroll_summaryJSON){

    yearly_payroll_summary_t *yearly_payroll_summary_local_var = NULL;

    // define the local variable for yearly_payroll_summary->avg_employee_count
    int *avg_employee_count_local_var = NULL;

    // define the local list for yearly_payroll_summary->months
    list_t *monthsList = NULL;

    // define the local variable for yearly_payroll_summary->year
    int *year_local_var = NULL;

    char *yearly_employer_cost_local_str = NULL;

    char *yearly_gross_local_str = NULL;

    char *yearly_net_local_str = NULL;

    // yearly_payroll_summary->avg_employee_count
    cJSON *avg_employee_count = cJSON_GetObjectItemCaseSensitive(yearly_payroll_summaryJSON, "avg_employee_count");
    if (cJSON_IsNull(avg_employee_count)) {
        avg_employee_count = NULL;
    }
    if (!avg_employee_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(avg_employee_count))
    {
    goto end; //Numeric
    }
    avg_employee_count_local_var = malloc(sizeof(int));
    if(!avg_employee_count_local_var)
    {
        goto end;
    }
    *avg_employee_count_local_var = avg_employee_count->valuedouble;

    // yearly_payroll_summary->months
    cJSON *months = cJSON_GetObjectItemCaseSensitive(yearly_payroll_summaryJSON, "months");
    if (cJSON_IsNull(months)) {
        months = NULL;
    }
    if (!months) {
        goto end;
    }

    
    cJSON *months_local_nonprimitive = NULL;
    if(!cJSON_IsArray(months)){
        goto end; //nonprimitive container
    }

    monthsList = list_createList();

    cJSON_ArrayForEach(months_local_nonprimitive,months )
    {
        if(!cJSON_IsObject(months_local_nonprimitive)){
            goto end;
        }
        payroll_summary_item_t *monthsItem = payroll_summary_item_parseFromJSON(months_local_nonprimitive);

        list_addElement(monthsList, monthsItem);
    }

    // yearly_payroll_summary->year
    cJSON *year = cJSON_GetObjectItemCaseSensitive(yearly_payroll_summaryJSON, "year");
    if (cJSON_IsNull(year)) {
        year = NULL;
    }
    if (!year) {
        goto end;
    }

    
    if(!cJSON_IsNumber(year))
    {
    goto end; //Numeric
    }
    year_local_var = malloc(sizeof(int));
    if(!year_local_var)
    {
        goto end;
    }
    *year_local_var = year->valuedouble;

    // yearly_payroll_summary->yearly_employer_cost
    cJSON *yearly_employer_cost = cJSON_GetObjectItemCaseSensitive(yearly_payroll_summaryJSON, "yearly_employer_cost");
    if (cJSON_IsNull(yearly_employer_cost)) {
        yearly_employer_cost = NULL;
    }
    if (!yearly_employer_cost) {
        goto end;
    }

    
    if(!cJSON_IsString(yearly_employer_cost))
    {
    goto end; //String
    }

    // yearly_payroll_summary->yearly_gross
    cJSON *yearly_gross = cJSON_GetObjectItemCaseSensitive(yearly_payroll_summaryJSON, "yearly_gross");
    if (cJSON_IsNull(yearly_gross)) {
        yearly_gross = NULL;
    }
    if (!yearly_gross) {
        goto end;
    }

    
    if(!cJSON_IsString(yearly_gross))
    {
    goto end; //String
    }

    // yearly_payroll_summary->yearly_net
    cJSON *yearly_net = cJSON_GetObjectItemCaseSensitive(yearly_payroll_summaryJSON, "yearly_net");
    if (cJSON_IsNull(yearly_net)) {
        yearly_net = NULL;
    }
    if (!yearly_net) {
        goto end;
    }

    
    if(!cJSON_IsString(yearly_net))
    {
    goto end; //String
    }


    if (yearly_employer_cost && !cJSON_IsNull(yearly_employer_cost)) yearly_employer_cost_local_str = strdup(yearly_employer_cost->valuestring);
    if (yearly_gross && !cJSON_IsNull(yearly_gross)) yearly_gross_local_str = strdup(yearly_gross->valuestring);
    if (yearly_net && !cJSON_IsNull(yearly_net)) yearly_net_local_str = strdup(yearly_net->valuestring);

    yearly_payroll_summary_local_var = yearly_payroll_summary_create_internal (
        avg_employee_count_local_var,
        monthsList,
        year_local_var,
        yearly_employer_cost_local_str,
        yearly_gross_local_str,
        yearly_net_local_str
        );

    if (!yearly_payroll_summary_local_var) {
        goto end;
    }

    return yearly_payroll_summary_local_var;
end:
    if (avg_employee_count_local_var) {
        free(avg_employee_count_local_var);
        avg_employee_count_local_var = NULL;
    }
    if (monthsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, monthsList) {
            payroll_summary_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(monthsList);
        monthsList = NULL;
    }
    if (year_local_var) {
        free(year_local_var);
        year_local_var = NULL;
    }
    if (yearly_employer_cost_local_str) {
        free(yearly_employer_cost_local_str);
        yearly_employer_cost_local_str = NULL;
    }
    if (yearly_gross_local_str) {
        free(yearly_gross_local_str);
        yearly_gross_local_str = NULL;
    }
    if (yearly_net_local_str) {
        free(yearly_net_local_str);
        yearly_net_local_str = NULL;
    }
    return NULL;

}
