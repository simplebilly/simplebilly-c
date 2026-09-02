#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "payroll_summary.h"



static payroll_summary_t *payroll_summary_create_internal(
    char *first_name,
    char *hourly_gross,
    char *id,
    char *job_title,
    char *last_name,
    char *monthly_salary,
    list_t *months,
    char *weekly_hours,
    int *year
    ) {
    payroll_summary_t *payroll_summary_local_var = malloc(sizeof(payroll_summary_t));
    if (!payroll_summary_local_var) {
        return NULL;
    }
    memset(payroll_summary_local_var, 0, sizeof(payroll_summary_t));
    payroll_summary_local_var->_library_owned = 1;
    payroll_summary_local_var->first_name = first_name;
    payroll_summary_local_var->hourly_gross = hourly_gross;
    payroll_summary_local_var->id = id;
    payroll_summary_local_var->job_title = job_title;
    payroll_summary_local_var->last_name = last_name;
    payroll_summary_local_var->monthly_salary = monthly_salary;
    payroll_summary_local_var->months = months;
    payroll_summary_local_var->weekly_hours = weekly_hours;
    payroll_summary_local_var->year = year;
    return payroll_summary_local_var;
}

__attribute__((deprecated)) payroll_summary_t *payroll_summary_create(
    char *first_name,
    char *hourly_gross,
    char *id,
    char *job_title,
    char *last_name,
    char *monthly_salary,
    list_t *months,
    char *weekly_hours,
    int *year
    ) {
    int *year_copy = NULL;
    if (year) {
        year_copy = malloc(sizeof(int));
        if (year_copy) *year_copy = *year;
    }
    payroll_summary_t *result = payroll_summary_create_internal (
        first_name,
        hourly_gross,
        id,
        job_title,
        last_name,
        monthly_salary,
        months,
        weekly_hours,
        year_copy
        );
    if (!result) {
        free(year_copy);
    }
    return result;
}

void payroll_summary_free(payroll_summary_t *payroll_summary) {
    if(NULL == payroll_summary){
        return ;
    }
    if(payroll_summary->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "payroll_summary_free");
        return ;
    }
    listEntry_t *listEntry;
    if (payroll_summary->first_name) {
        free(payroll_summary->first_name);
        payroll_summary->first_name = NULL;
    }
    if (payroll_summary->hourly_gross) {
        free(payroll_summary->hourly_gross);
        payroll_summary->hourly_gross = NULL;
    }
    if (payroll_summary->id) {
        free(payroll_summary->id);
        payroll_summary->id = NULL;
    }
    if (payroll_summary->job_title) {
        free(payroll_summary->job_title);
        payroll_summary->job_title = NULL;
    }
    if (payroll_summary->last_name) {
        free(payroll_summary->last_name);
        payroll_summary->last_name = NULL;
    }
    if (payroll_summary->monthly_salary) {
        free(payroll_summary->monthly_salary);
        payroll_summary->monthly_salary = NULL;
    }
    if (payroll_summary->months) {
        list_ForEach(listEntry, payroll_summary->months) {
            payroll_month_free(listEntry->data);
        }
        list_freeList(payroll_summary->months);
        payroll_summary->months = NULL;
    }
    if (payroll_summary->weekly_hours) {
        free(payroll_summary->weekly_hours);
        payroll_summary->weekly_hours = NULL;
    }
    if (payroll_summary->year) {
        free(payroll_summary->year);
        payroll_summary->year = NULL;
    }
    free(payroll_summary);
}

cJSON *payroll_summary_convertToJSON(payroll_summary_t *payroll_summary) {
    cJSON *item = cJSON_CreateObject();

    // payroll_summary->first_name
    if (!payroll_summary->first_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "firstName", payroll_summary->first_name) == NULL) {
    goto fail; //String
    }


    // payroll_summary->hourly_gross
    if(payroll_summary->hourly_gross) {
    if(cJSON_AddStringToObject(item, "hourlyGross", payroll_summary->hourly_gross) == NULL) {
    goto fail; //String
    }
    }


    // payroll_summary->id
    if (!payroll_summary->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", payroll_summary->id) == NULL) {
    goto fail; //String
    }


    // payroll_summary->job_title
    if (!payroll_summary->job_title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "jobTitle", payroll_summary->job_title) == NULL) {
    goto fail; //String
    }


    // payroll_summary->last_name
    if (!payroll_summary->last_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "lastName", payroll_summary->last_name) == NULL) {
    goto fail; //String
    }


    // payroll_summary->monthly_salary
    if(payroll_summary->monthly_salary) {
    if(cJSON_AddStringToObject(item, "monthlySalary", payroll_summary->monthly_salary) == NULL) {
    goto fail; //String
    }
    }


    // payroll_summary->months
    if (!payroll_summary->months) {
        goto fail;
    }
    cJSON *months = cJSON_AddArrayToObject(item, "months");
    if(months == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *monthsListEntry;
    if (payroll_summary->months) {
    list_ForEach(monthsListEntry, payroll_summary->months) {
    cJSON *itemLocal = payroll_month_convertToJSON(monthsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(months, itemLocal);
    }
    }


    // payroll_summary->weekly_hours
    if(payroll_summary->weekly_hours) {
    if(cJSON_AddStringToObject(item, "weeklyHours", payroll_summary->weekly_hours) == NULL) {
    goto fail; //String
    }
    }


    // payroll_summary->year
    if (!payroll_summary->year) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "year", *payroll_summary->year) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

payroll_summary_t *payroll_summary_parseFromJSON(cJSON *payroll_summaryJSON){

    payroll_summary_t *payroll_summary_local_var = NULL;

    char *first_name_local_str = NULL;

    char *hourly_gross_local_str = NULL;

    char *id_local_str = NULL;

    char *job_title_local_str = NULL;

    char *last_name_local_str = NULL;

    char *monthly_salary_local_str = NULL;

    // define the local list for payroll_summary->months
    list_t *monthsList = NULL;

    char *weekly_hours_local_str = NULL;

    // define the local variable for payroll_summary->year
    int *year_local_var = NULL;

    // payroll_summary->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(payroll_summaryJSON, "firstName");
    if (cJSON_IsNull(first_name)) {
        first_name = NULL;
    }
    if (!first_name) {
        goto end;
    }

    
    if(!cJSON_IsString(first_name))
    {
    goto end; //String
    }

    // payroll_summary->hourly_gross
    cJSON *hourly_gross = cJSON_GetObjectItemCaseSensitive(payroll_summaryJSON, "hourlyGross");
    if (cJSON_IsNull(hourly_gross)) {
        hourly_gross = NULL;
    }
    if (hourly_gross) { 
    if(!cJSON_IsString(hourly_gross) && !cJSON_IsNull(hourly_gross))
    {
    goto end; //String
    }
    }

    // payroll_summary->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(payroll_summaryJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // payroll_summary->job_title
    cJSON *job_title = cJSON_GetObjectItemCaseSensitive(payroll_summaryJSON, "jobTitle");
    if (cJSON_IsNull(job_title)) {
        job_title = NULL;
    }
    if (!job_title) {
        goto end;
    }

    
    if(!cJSON_IsString(job_title))
    {
    goto end; //String
    }

    // payroll_summary->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(payroll_summaryJSON, "lastName");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (!last_name) {
        goto end;
    }

    
    if(!cJSON_IsString(last_name))
    {
    goto end; //String
    }

    // payroll_summary->monthly_salary
    cJSON *monthly_salary = cJSON_GetObjectItemCaseSensitive(payroll_summaryJSON, "monthlySalary");
    if (cJSON_IsNull(monthly_salary)) {
        monthly_salary = NULL;
    }
    if (monthly_salary) { 
    if(!cJSON_IsString(monthly_salary) && !cJSON_IsNull(monthly_salary))
    {
    goto end; //String
    }
    }

    // payroll_summary->months
    cJSON *months = cJSON_GetObjectItemCaseSensitive(payroll_summaryJSON, "months");
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
        payroll_month_t *monthsItem = payroll_month_parseFromJSON(months_local_nonprimitive);

        list_addElement(monthsList, monthsItem);
    }

    // payroll_summary->weekly_hours
    cJSON *weekly_hours = cJSON_GetObjectItemCaseSensitive(payroll_summaryJSON, "weeklyHours");
    if (cJSON_IsNull(weekly_hours)) {
        weekly_hours = NULL;
    }
    if (weekly_hours) { 
    if(!cJSON_IsString(weekly_hours) && !cJSON_IsNull(weekly_hours))
    {
    goto end; //String
    }
    }

    // payroll_summary->year
    cJSON *year = cJSON_GetObjectItemCaseSensitive(payroll_summaryJSON, "year");
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


    if (first_name && !cJSON_IsNull(first_name)) first_name_local_str = strdup(first_name->valuestring);
    if (hourly_gross && !cJSON_IsNull(hourly_gross)) hourly_gross_local_str = strdup(hourly_gross->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (job_title && !cJSON_IsNull(job_title)) job_title_local_str = strdup(job_title->valuestring);
    if (last_name && !cJSON_IsNull(last_name)) last_name_local_str = strdup(last_name->valuestring);
    if (monthly_salary && !cJSON_IsNull(monthly_salary)) monthly_salary_local_str = strdup(monthly_salary->valuestring);
    if (weekly_hours && !cJSON_IsNull(weekly_hours)) weekly_hours_local_str = strdup(weekly_hours->valuestring);

    payroll_summary_local_var = payroll_summary_create_internal (
        first_name_local_str,
        hourly_gross_local_str,
        id_local_str,
        job_title_local_str,
        last_name_local_str,
        monthly_salary_local_str,
        monthsList,
        weekly_hours_local_str,
        year_local_var
        );

    if (!payroll_summary_local_var) {
        goto end;
    }

    return payroll_summary_local_var;
end:
    if (first_name_local_str) {
        free(first_name_local_str);
        first_name_local_str = NULL;
    }
    if (hourly_gross_local_str) {
        free(hourly_gross_local_str);
        hourly_gross_local_str = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (job_title_local_str) {
        free(job_title_local_str);
        job_title_local_str = NULL;
    }
    if (last_name_local_str) {
        free(last_name_local_str);
        last_name_local_str = NULL;
    }
    if (monthly_salary_local_str) {
        free(monthly_salary_local_str);
        monthly_salary_local_str = NULL;
    }
    if (monthsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, monthsList) {
            payroll_month_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(monthsList);
        monthsList = NULL;
    }
    if (weekly_hours_local_str) {
        free(weekly_hours_local_str);
        weekly_hours_local_str = NULL;
    }
    if (year_local_var) {
        free(year_local_var);
        year_local_var = NULL;
    }
    return NULL;

}
