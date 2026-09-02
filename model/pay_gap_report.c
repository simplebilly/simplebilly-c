#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pay_gap_report.h"



static pay_gap_report_t *pay_gap_report_create_internal(
    list_t *by_job_title,
    int *diverse_count,
    int *employee_count,
    int *female_count,
    int *male_count,
    double *mean_gap_pct,
    double *median_gap_pct,
    list_t *quartiles
    ) {
    pay_gap_report_t *pay_gap_report_local_var = malloc(sizeof(pay_gap_report_t));
    if (!pay_gap_report_local_var) {
        return NULL;
    }
    memset(pay_gap_report_local_var, 0, sizeof(pay_gap_report_t));
    pay_gap_report_local_var->_library_owned = 1;
    pay_gap_report_local_var->by_job_title = by_job_title;
    pay_gap_report_local_var->diverse_count = diverse_count;
    pay_gap_report_local_var->employee_count = employee_count;
    pay_gap_report_local_var->female_count = female_count;
    pay_gap_report_local_var->male_count = male_count;
    pay_gap_report_local_var->mean_gap_pct = mean_gap_pct;
    pay_gap_report_local_var->median_gap_pct = median_gap_pct;
    pay_gap_report_local_var->quartiles = quartiles;
    return pay_gap_report_local_var;
}

__attribute__((deprecated)) pay_gap_report_t *pay_gap_report_create(
    list_t *by_job_title,
    int *diverse_count,
    int *employee_count,
    int *female_count,
    int *male_count,
    double *mean_gap_pct,
    double *median_gap_pct,
    list_t *quartiles
    ) {
    int *diverse_count_copy = NULL;
    if (diverse_count) {
        diverse_count_copy = malloc(sizeof(int));
        if (diverse_count_copy) *diverse_count_copy = *diverse_count;
    }
    int *employee_count_copy = NULL;
    if (employee_count) {
        employee_count_copy = malloc(sizeof(int));
        if (employee_count_copy) *employee_count_copy = *employee_count;
    }
    int *female_count_copy = NULL;
    if (female_count) {
        female_count_copy = malloc(sizeof(int));
        if (female_count_copy) *female_count_copy = *female_count;
    }
    int *male_count_copy = NULL;
    if (male_count) {
        male_count_copy = malloc(sizeof(int));
        if (male_count_copy) *male_count_copy = *male_count;
    }
    double *mean_gap_pct_copy = NULL;
    if (mean_gap_pct) {
        mean_gap_pct_copy = malloc(sizeof(double));
        if (mean_gap_pct_copy) *mean_gap_pct_copy = *mean_gap_pct;
    }
    double *median_gap_pct_copy = NULL;
    if (median_gap_pct) {
        median_gap_pct_copy = malloc(sizeof(double));
        if (median_gap_pct_copy) *median_gap_pct_copy = *median_gap_pct;
    }
    pay_gap_report_t *result = pay_gap_report_create_internal (
        by_job_title,
        diverse_count_copy,
        employee_count_copy,
        female_count_copy,
        male_count_copy,
        mean_gap_pct_copy,
        median_gap_pct_copy,
        quartiles
        );
    if (!result) {
        free(diverse_count_copy);
        free(employee_count_copy);
        free(female_count_copy);
        free(male_count_copy);
        free(mean_gap_pct_copy);
        free(median_gap_pct_copy);
    }
    return result;
}

void pay_gap_report_free(pay_gap_report_t *pay_gap_report) {
    if(NULL == pay_gap_report){
        return ;
    }
    if(pay_gap_report->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "pay_gap_report_free");
        return ;
    }
    listEntry_t *listEntry;
    if (pay_gap_report->by_job_title) {
        list_ForEach(listEntry, pay_gap_report->by_job_title) {
            job_title_gap_free(listEntry->data);
        }
        list_freeList(pay_gap_report->by_job_title);
        pay_gap_report->by_job_title = NULL;
    }
    if (pay_gap_report->diverse_count) {
        free(pay_gap_report->diverse_count);
        pay_gap_report->diverse_count = NULL;
    }
    if (pay_gap_report->employee_count) {
        free(pay_gap_report->employee_count);
        pay_gap_report->employee_count = NULL;
    }
    if (pay_gap_report->female_count) {
        free(pay_gap_report->female_count);
        pay_gap_report->female_count = NULL;
    }
    if (pay_gap_report->male_count) {
        free(pay_gap_report->male_count);
        pay_gap_report->male_count = NULL;
    }
    if (pay_gap_report->mean_gap_pct) {
        free(pay_gap_report->mean_gap_pct);
        pay_gap_report->mean_gap_pct = NULL;
    }
    if (pay_gap_report->median_gap_pct) {
        free(pay_gap_report->median_gap_pct);
        pay_gap_report->median_gap_pct = NULL;
    }
    if (pay_gap_report->quartiles) {
        list_ForEach(listEntry, pay_gap_report->quartiles) {
            quartile_band_free(listEntry->data);
        }
        list_freeList(pay_gap_report->quartiles);
        pay_gap_report->quartiles = NULL;
    }
    free(pay_gap_report);
}

cJSON *pay_gap_report_convertToJSON(pay_gap_report_t *pay_gap_report) {
    cJSON *item = cJSON_CreateObject();

    // pay_gap_report->by_job_title
    if (!pay_gap_report->by_job_title) {
        goto fail;
    }
    cJSON *by_job_title = cJSON_AddArrayToObject(item, "by_job_title");
    if(by_job_title == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *by_job_titleListEntry;
    if (pay_gap_report->by_job_title) {
    list_ForEach(by_job_titleListEntry, pay_gap_report->by_job_title) {
    cJSON *itemLocal = job_title_gap_convertToJSON(by_job_titleListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(by_job_title, itemLocal);
    }
    }


    // pay_gap_report->diverse_count
    if (!pay_gap_report->diverse_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "diverse_count", *pay_gap_report->diverse_count) == NULL) {
    goto fail; //Numeric
    }


    // pay_gap_report->employee_count
    if (!pay_gap_report->employee_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "employee_count", *pay_gap_report->employee_count) == NULL) {
    goto fail; //Numeric
    }


    // pay_gap_report->female_count
    if (!pay_gap_report->female_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "female_count", *pay_gap_report->female_count) == NULL) {
    goto fail; //Numeric
    }


    // pay_gap_report->male_count
    if (!pay_gap_report->male_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "male_count", *pay_gap_report->male_count) == NULL) {
    goto fail; //Numeric
    }


    // pay_gap_report->mean_gap_pct
    if (!pay_gap_report->mean_gap_pct) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "mean_gap_pct", *pay_gap_report->mean_gap_pct) == NULL) {
    goto fail; //Numeric
    }


    // pay_gap_report->median_gap_pct
    if (!pay_gap_report->median_gap_pct) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "median_gap_pct", *pay_gap_report->median_gap_pct) == NULL) {
    goto fail; //Numeric
    }


    // pay_gap_report->quartiles
    if (!pay_gap_report->quartiles) {
        goto fail;
    }
    cJSON *quartiles = cJSON_AddArrayToObject(item, "quartiles");
    if(quartiles == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *quartilesListEntry;
    if (pay_gap_report->quartiles) {
    list_ForEach(quartilesListEntry, pay_gap_report->quartiles) {
    cJSON *itemLocal = quartile_band_convertToJSON(quartilesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(quartiles, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

pay_gap_report_t *pay_gap_report_parseFromJSON(cJSON *pay_gap_reportJSON){

    pay_gap_report_t *pay_gap_report_local_var = NULL;

    // define the local list for pay_gap_report->by_job_title
    list_t *by_job_titleList = NULL;

    // define the local variable for pay_gap_report->diverse_count
    int *diverse_count_local_var = NULL;

    // define the local variable for pay_gap_report->employee_count
    int *employee_count_local_var = NULL;

    // define the local variable for pay_gap_report->female_count
    int *female_count_local_var = NULL;

    // define the local variable for pay_gap_report->male_count
    int *male_count_local_var = NULL;

    // define the local variable for pay_gap_report->mean_gap_pct
    double *mean_gap_pct_local_var = NULL;

    // define the local variable for pay_gap_report->median_gap_pct
    double *median_gap_pct_local_var = NULL;

    // define the local list for pay_gap_report->quartiles
    list_t *quartilesList = NULL;

    // pay_gap_report->by_job_title
    cJSON *by_job_title = cJSON_GetObjectItemCaseSensitive(pay_gap_reportJSON, "by_job_title");
    if (cJSON_IsNull(by_job_title)) {
        by_job_title = NULL;
    }
    if (!by_job_title) {
        goto end;
    }

    
    cJSON *by_job_title_local_nonprimitive = NULL;
    if(!cJSON_IsArray(by_job_title)){
        goto end; //nonprimitive container
    }

    by_job_titleList = list_createList();

    cJSON_ArrayForEach(by_job_title_local_nonprimitive,by_job_title )
    {
        if(!cJSON_IsObject(by_job_title_local_nonprimitive)){
            goto end;
        }
        job_title_gap_t *by_job_titleItem = job_title_gap_parseFromJSON(by_job_title_local_nonprimitive);

        list_addElement(by_job_titleList, by_job_titleItem);
    }

    // pay_gap_report->diverse_count
    cJSON *diverse_count = cJSON_GetObjectItemCaseSensitive(pay_gap_reportJSON, "diverse_count");
    if (cJSON_IsNull(diverse_count)) {
        diverse_count = NULL;
    }
    if (!diverse_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(diverse_count))
    {
    goto end; //Numeric
    }
    diverse_count_local_var = malloc(sizeof(int));
    if(!diverse_count_local_var)
    {
        goto end;
    }
    *diverse_count_local_var = diverse_count->valuedouble;

    // pay_gap_report->employee_count
    cJSON *employee_count = cJSON_GetObjectItemCaseSensitive(pay_gap_reportJSON, "employee_count");
    if (cJSON_IsNull(employee_count)) {
        employee_count = NULL;
    }
    if (!employee_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(employee_count))
    {
    goto end; //Numeric
    }
    employee_count_local_var = malloc(sizeof(int));
    if(!employee_count_local_var)
    {
        goto end;
    }
    *employee_count_local_var = employee_count->valuedouble;

    // pay_gap_report->female_count
    cJSON *female_count = cJSON_GetObjectItemCaseSensitive(pay_gap_reportJSON, "female_count");
    if (cJSON_IsNull(female_count)) {
        female_count = NULL;
    }
    if (!female_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(female_count))
    {
    goto end; //Numeric
    }
    female_count_local_var = malloc(sizeof(int));
    if(!female_count_local_var)
    {
        goto end;
    }
    *female_count_local_var = female_count->valuedouble;

    // pay_gap_report->male_count
    cJSON *male_count = cJSON_GetObjectItemCaseSensitive(pay_gap_reportJSON, "male_count");
    if (cJSON_IsNull(male_count)) {
        male_count = NULL;
    }
    if (!male_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(male_count))
    {
    goto end; //Numeric
    }
    male_count_local_var = malloc(sizeof(int));
    if(!male_count_local_var)
    {
        goto end;
    }
    *male_count_local_var = male_count->valuedouble;

    // pay_gap_report->mean_gap_pct
    cJSON *mean_gap_pct = cJSON_GetObjectItemCaseSensitive(pay_gap_reportJSON, "mean_gap_pct");
    if (cJSON_IsNull(mean_gap_pct)) {
        mean_gap_pct = NULL;
    }
    if (!mean_gap_pct) {
        goto end;
    }

    
    if(!cJSON_IsNumber(mean_gap_pct))
    {
    goto end; //Numeric
    }
    mean_gap_pct_local_var = malloc(sizeof(double));
    if(!mean_gap_pct_local_var)
    {
        goto end;
    }
    *mean_gap_pct_local_var = mean_gap_pct->valuedouble;

    // pay_gap_report->median_gap_pct
    cJSON *median_gap_pct = cJSON_GetObjectItemCaseSensitive(pay_gap_reportJSON, "median_gap_pct");
    if (cJSON_IsNull(median_gap_pct)) {
        median_gap_pct = NULL;
    }
    if (!median_gap_pct) {
        goto end;
    }

    
    if(!cJSON_IsNumber(median_gap_pct))
    {
    goto end; //Numeric
    }
    median_gap_pct_local_var = malloc(sizeof(double));
    if(!median_gap_pct_local_var)
    {
        goto end;
    }
    *median_gap_pct_local_var = median_gap_pct->valuedouble;

    // pay_gap_report->quartiles
    cJSON *quartiles = cJSON_GetObjectItemCaseSensitive(pay_gap_reportJSON, "quartiles");
    if (cJSON_IsNull(quartiles)) {
        quartiles = NULL;
    }
    if (!quartiles) {
        goto end;
    }

    
    cJSON *quartiles_local_nonprimitive = NULL;
    if(!cJSON_IsArray(quartiles)){
        goto end; //nonprimitive container
    }

    quartilesList = list_createList();

    cJSON_ArrayForEach(quartiles_local_nonprimitive,quartiles )
    {
        if(!cJSON_IsObject(quartiles_local_nonprimitive)){
            goto end;
        }
        quartile_band_t *quartilesItem = quartile_band_parseFromJSON(quartiles_local_nonprimitive);

        list_addElement(quartilesList, quartilesItem);
    }



    pay_gap_report_local_var = pay_gap_report_create_internal (
        by_job_titleList,
        diverse_count_local_var,
        employee_count_local_var,
        female_count_local_var,
        male_count_local_var,
        mean_gap_pct_local_var,
        median_gap_pct_local_var,
        quartilesList
        );

    if (!pay_gap_report_local_var) {
        goto end;
    }

    return pay_gap_report_local_var;
end:
    if (by_job_titleList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, by_job_titleList) {
            job_title_gap_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(by_job_titleList);
        by_job_titleList = NULL;
    }
    if (diverse_count_local_var) {
        free(diverse_count_local_var);
        diverse_count_local_var = NULL;
    }
    if (employee_count_local_var) {
        free(employee_count_local_var);
        employee_count_local_var = NULL;
    }
    if (female_count_local_var) {
        free(female_count_local_var);
        female_count_local_var = NULL;
    }
    if (male_count_local_var) {
        free(male_count_local_var);
        male_count_local_var = NULL;
    }
    if (mean_gap_pct_local_var) {
        free(mean_gap_pct_local_var);
        mean_gap_pct_local_var = NULL;
    }
    if (median_gap_pct_local_var) {
        free(median_gap_pct_local_var);
        median_gap_pct_local_var = NULL;
    }
    if (quartilesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, quartilesList) {
            quartile_band_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(quartilesList);
        quartilesList = NULL;
    }
    return NULL;

}
