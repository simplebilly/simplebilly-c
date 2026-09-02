#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "emissions_report.h"



static emissions_report_t *emissions_report_create_internal(
    list_t *by_category,
    list_t *by_scope,
    list_t *by_year,
    data_quality_t *data_quality,
    double *intensity_per_employee,
    double *intensity_per_revenue_mio,
    double *net_revenue,
    double *spend_based_estimate_tco2e,
    list_t *targets,
    char *total_tco2e
    ) {
    emissions_report_t *emissions_report_local_var = malloc(sizeof(emissions_report_t));
    if (!emissions_report_local_var) {
        return NULL;
    }
    memset(emissions_report_local_var, 0, sizeof(emissions_report_t));
    emissions_report_local_var->_library_owned = 1;
    emissions_report_local_var->by_category = by_category;
    emissions_report_local_var->by_scope = by_scope;
    emissions_report_local_var->by_year = by_year;
    emissions_report_local_var->data_quality = data_quality;
    emissions_report_local_var->intensity_per_employee = intensity_per_employee;
    emissions_report_local_var->intensity_per_revenue_mio = intensity_per_revenue_mio;
    emissions_report_local_var->net_revenue = net_revenue;
    emissions_report_local_var->spend_based_estimate_tco2e = spend_based_estimate_tco2e;
    emissions_report_local_var->targets = targets;
    emissions_report_local_var->total_tco2e = total_tco2e;
    return emissions_report_local_var;
}

__attribute__((deprecated)) emissions_report_t *emissions_report_create(
    list_t *by_category,
    list_t *by_scope,
    list_t *by_year,
    data_quality_t *data_quality,
    double *intensity_per_employee,
    double *intensity_per_revenue_mio,
    double *net_revenue,
    double *spend_based_estimate_tco2e,
    list_t *targets,
    char *total_tco2e
    ) {
    double *intensity_per_employee_copy = NULL;
    if (intensity_per_employee) {
        intensity_per_employee_copy = malloc(sizeof(double));
        if (intensity_per_employee_copy) *intensity_per_employee_copy = *intensity_per_employee;
    }
    double *intensity_per_revenue_mio_copy = NULL;
    if (intensity_per_revenue_mio) {
        intensity_per_revenue_mio_copy = malloc(sizeof(double));
        if (intensity_per_revenue_mio_copy) *intensity_per_revenue_mio_copy = *intensity_per_revenue_mio;
    }
    double *net_revenue_copy = NULL;
    if (net_revenue) {
        net_revenue_copy = malloc(sizeof(double));
        if (net_revenue_copy) *net_revenue_copy = *net_revenue;
    }
    double *spend_based_estimate_tco2e_copy = NULL;
    if (spend_based_estimate_tco2e) {
        spend_based_estimate_tco2e_copy = malloc(sizeof(double));
        if (spend_based_estimate_tco2e_copy) *spend_based_estimate_tco2e_copy = *spend_based_estimate_tco2e;
    }
    emissions_report_t *result = emissions_report_create_internal (
        by_category,
        by_scope,
        by_year,
        data_quality,
        intensity_per_employee_copy,
        intensity_per_revenue_mio_copy,
        net_revenue_copy,
        spend_based_estimate_tco2e_copy,
        targets,
        total_tco2e
        );
    if (!result) {
        free(intensity_per_employee_copy);
        free(intensity_per_revenue_mio_copy);
        free(net_revenue_copy);
        free(spend_based_estimate_tco2e_copy);
    }
    return result;
}

void emissions_report_free(emissions_report_t *emissions_report) {
    if(NULL == emissions_report){
        return ;
    }
    if(emissions_report->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "emissions_report_free");
        return ;
    }
    listEntry_t *listEntry;
    if (emissions_report->by_category) {
        list_ForEach(listEntry, emissions_report->by_category) {
            category_total_free(listEntry->data);
        }
        list_freeList(emissions_report->by_category);
        emissions_report->by_category = NULL;
    }
    if (emissions_report->by_scope) {
        list_ForEach(listEntry, emissions_report->by_scope) {
            scope_total_free(listEntry->data);
        }
        list_freeList(emissions_report->by_scope);
        emissions_report->by_scope = NULL;
    }
    if (emissions_report->by_year) {
        list_ForEach(listEntry, emissions_report->by_year) {
            year_total_free(listEntry->data);
        }
        list_freeList(emissions_report->by_year);
        emissions_report->by_year = NULL;
    }
    if (emissions_report->data_quality) {
        data_quality_free(emissions_report->data_quality);
        emissions_report->data_quality = NULL;
    }
    if (emissions_report->intensity_per_employee) {
        free(emissions_report->intensity_per_employee);
        emissions_report->intensity_per_employee = NULL;
    }
    if (emissions_report->intensity_per_revenue_mio) {
        free(emissions_report->intensity_per_revenue_mio);
        emissions_report->intensity_per_revenue_mio = NULL;
    }
    if (emissions_report->net_revenue) {
        free(emissions_report->net_revenue);
        emissions_report->net_revenue = NULL;
    }
    if (emissions_report->spend_based_estimate_tco2e) {
        free(emissions_report->spend_based_estimate_tco2e);
        emissions_report->spend_based_estimate_tco2e = NULL;
    }
    if (emissions_report->targets) {
        list_ForEach(listEntry, emissions_report->targets) {
            target_progress_free(listEntry->data);
        }
        list_freeList(emissions_report->targets);
        emissions_report->targets = NULL;
    }
    if (emissions_report->total_tco2e) {
        free(emissions_report->total_tco2e);
        emissions_report->total_tco2e = NULL;
    }
    free(emissions_report);
}

cJSON *emissions_report_convertToJSON(emissions_report_t *emissions_report) {
    cJSON *item = cJSON_CreateObject();

    // emissions_report->by_category
    if (!emissions_report->by_category) {
        goto fail;
    }
    cJSON *by_category = cJSON_AddArrayToObject(item, "by_category");
    if(by_category == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *by_categoryListEntry;
    if (emissions_report->by_category) {
    list_ForEach(by_categoryListEntry, emissions_report->by_category) {
    cJSON *itemLocal = category_total_convertToJSON(by_categoryListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(by_category, itemLocal);
    }
    }


    // emissions_report->by_scope
    if (!emissions_report->by_scope) {
        goto fail;
    }
    cJSON *by_scope = cJSON_AddArrayToObject(item, "by_scope");
    if(by_scope == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *by_scopeListEntry;
    if (emissions_report->by_scope) {
    list_ForEach(by_scopeListEntry, emissions_report->by_scope) {
    cJSON *itemLocal = scope_total_convertToJSON(by_scopeListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(by_scope, itemLocal);
    }
    }


    // emissions_report->by_year
    if (!emissions_report->by_year) {
        goto fail;
    }
    cJSON *by_year = cJSON_AddArrayToObject(item, "by_year");
    if(by_year == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *by_yearListEntry;
    if (emissions_report->by_year) {
    list_ForEach(by_yearListEntry, emissions_report->by_year) {
    cJSON *itemLocal = year_total_convertToJSON(by_yearListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(by_year, itemLocal);
    }
    }


    // emissions_report->data_quality
    if (!emissions_report->data_quality) {
        goto fail;
    }
    cJSON *data_quality_local_JSON = data_quality_convertToJSON(emissions_report->data_quality);
    if(data_quality_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "data_quality", data_quality_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // emissions_report->intensity_per_employee
    if(emissions_report->intensity_per_employee) {
    if(cJSON_AddNumberToObject(item, "intensity_per_employee", *emissions_report->intensity_per_employee) == NULL) {
    goto fail; //Numeric
    }
    }


    // emissions_report->intensity_per_revenue_mio
    if(emissions_report->intensity_per_revenue_mio) {
    if(cJSON_AddNumberToObject(item, "intensity_per_revenue_mio", *emissions_report->intensity_per_revenue_mio) == NULL) {
    goto fail; //Numeric
    }
    }


    // emissions_report->net_revenue
    if(emissions_report->net_revenue) {
    if(cJSON_AddNumberToObject(item, "net_revenue", *emissions_report->net_revenue) == NULL) {
    goto fail; //Numeric
    }
    }


    // emissions_report->spend_based_estimate_tco2e
    if(emissions_report->spend_based_estimate_tco2e) {
    if(cJSON_AddNumberToObject(item, "spend_based_estimate_tco2e", *emissions_report->spend_based_estimate_tco2e) == NULL) {
    goto fail; //Numeric
    }
    }


    // emissions_report->targets
    if (!emissions_report->targets) {
        goto fail;
    }
    cJSON *targets = cJSON_AddArrayToObject(item, "targets");
    if(targets == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *targetsListEntry;
    if (emissions_report->targets) {
    list_ForEach(targetsListEntry, emissions_report->targets) {
    cJSON *itemLocal = target_progress_convertToJSON(targetsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(targets, itemLocal);
    }
    }


    // emissions_report->total_tco2e
    if (!emissions_report->total_tco2e) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_tco2e", emissions_report->total_tco2e) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

emissions_report_t *emissions_report_parseFromJSON(cJSON *emissions_reportJSON){

    emissions_report_t *emissions_report_local_var = NULL;

    // define the local list for emissions_report->by_category
    list_t *by_categoryList = NULL;

    // define the local list for emissions_report->by_scope
    list_t *by_scopeList = NULL;

    // define the local list for emissions_report->by_year
    list_t *by_yearList = NULL;

    // define the local variable for emissions_report->data_quality
    data_quality_t *data_quality_local_nonprim = NULL;

    // define the local variable for emissions_report->intensity_per_employee
    double *intensity_per_employee_local_var = NULL;

    // define the local variable for emissions_report->intensity_per_revenue_mio
    double *intensity_per_revenue_mio_local_var = NULL;

    // define the local variable for emissions_report->net_revenue
    double *net_revenue_local_var = NULL;

    // define the local variable for emissions_report->spend_based_estimate_tco2e
    double *spend_based_estimate_tco2e_local_var = NULL;

    // define the local list for emissions_report->targets
    list_t *targetsList = NULL;

    char *total_tco2e_local_str = NULL;

    // emissions_report->by_category
    cJSON *by_category = cJSON_GetObjectItemCaseSensitive(emissions_reportJSON, "by_category");
    if (cJSON_IsNull(by_category)) {
        by_category = NULL;
    }
    if (!by_category) {
        goto end;
    }

    
    cJSON *by_category_local_nonprimitive = NULL;
    if(!cJSON_IsArray(by_category)){
        goto end; //nonprimitive container
    }

    by_categoryList = list_createList();

    cJSON_ArrayForEach(by_category_local_nonprimitive,by_category )
    {
        if(!cJSON_IsObject(by_category_local_nonprimitive)){
            goto end;
        }
        category_total_t *by_categoryItem = category_total_parseFromJSON(by_category_local_nonprimitive);

        list_addElement(by_categoryList, by_categoryItem);
    }

    // emissions_report->by_scope
    cJSON *by_scope = cJSON_GetObjectItemCaseSensitive(emissions_reportJSON, "by_scope");
    if (cJSON_IsNull(by_scope)) {
        by_scope = NULL;
    }
    if (!by_scope) {
        goto end;
    }

    
    cJSON *by_scope_local_nonprimitive = NULL;
    if(!cJSON_IsArray(by_scope)){
        goto end; //nonprimitive container
    }

    by_scopeList = list_createList();

    cJSON_ArrayForEach(by_scope_local_nonprimitive,by_scope )
    {
        if(!cJSON_IsObject(by_scope_local_nonprimitive)){
            goto end;
        }
        scope_total_t *by_scopeItem = scope_total_parseFromJSON(by_scope_local_nonprimitive);

        list_addElement(by_scopeList, by_scopeItem);
    }

    // emissions_report->by_year
    cJSON *by_year = cJSON_GetObjectItemCaseSensitive(emissions_reportJSON, "by_year");
    if (cJSON_IsNull(by_year)) {
        by_year = NULL;
    }
    if (!by_year) {
        goto end;
    }

    
    cJSON *by_year_local_nonprimitive = NULL;
    if(!cJSON_IsArray(by_year)){
        goto end; //nonprimitive container
    }

    by_yearList = list_createList();

    cJSON_ArrayForEach(by_year_local_nonprimitive,by_year )
    {
        if(!cJSON_IsObject(by_year_local_nonprimitive)){
            goto end;
        }
        year_total_t *by_yearItem = year_total_parseFromJSON(by_year_local_nonprimitive);

        list_addElement(by_yearList, by_yearItem);
    }

    // emissions_report->data_quality
    cJSON *data_quality = cJSON_GetObjectItemCaseSensitive(emissions_reportJSON, "data_quality");
    if (cJSON_IsNull(data_quality)) {
        data_quality = NULL;
    }
    if (!data_quality) {
        goto end;
    }

    
    data_quality_local_nonprim = data_quality_parseFromJSON(data_quality); //nonprimitive

    // emissions_report->intensity_per_employee
    cJSON *intensity_per_employee = cJSON_GetObjectItemCaseSensitive(emissions_reportJSON, "intensity_per_employee");
    if (cJSON_IsNull(intensity_per_employee)) {
        intensity_per_employee = NULL;
    }
    if (intensity_per_employee) { 
    if(!cJSON_IsNumber(intensity_per_employee))
    {
    goto end; //Numeric
    }
    intensity_per_employee_local_var = malloc(sizeof(double));
    if(!intensity_per_employee_local_var)
    {
        goto end;
    }
    *intensity_per_employee_local_var = intensity_per_employee->valuedouble;
    }

    // emissions_report->intensity_per_revenue_mio
    cJSON *intensity_per_revenue_mio = cJSON_GetObjectItemCaseSensitive(emissions_reportJSON, "intensity_per_revenue_mio");
    if (cJSON_IsNull(intensity_per_revenue_mio)) {
        intensity_per_revenue_mio = NULL;
    }
    if (intensity_per_revenue_mio) { 
    if(!cJSON_IsNumber(intensity_per_revenue_mio))
    {
    goto end; //Numeric
    }
    intensity_per_revenue_mio_local_var = malloc(sizeof(double));
    if(!intensity_per_revenue_mio_local_var)
    {
        goto end;
    }
    *intensity_per_revenue_mio_local_var = intensity_per_revenue_mio->valuedouble;
    }

    // emissions_report->net_revenue
    cJSON *net_revenue = cJSON_GetObjectItemCaseSensitive(emissions_reportJSON, "net_revenue");
    if (cJSON_IsNull(net_revenue)) {
        net_revenue = NULL;
    }
    if (net_revenue) { 
    if(!cJSON_IsNumber(net_revenue))
    {
    goto end; //Numeric
    }
    net_revenue_local_var = malloc(sizeof(double));
    if(!net_revenue_local_var)
    {
        goto end;
    }
    *net_revenue_local_var = net_revenue->valuedouble;
    }

    // emissions_report->spend_based_estimate_tco2e
    cJSON *spend_based_estimate_tco2e = cJSON_GetObjectItemCaseSensitive(emissions_reportJSON, "spend_based_estimate_tco2e");
    if (cJSON_IsNull(spend_based_estimate_tco2e)) {
        spend_based_estimate_tco2e = NULL;
    }
    if (spend_based_estimate_tco2e) { 
    if(!cJSON_IsNumber(spend_based_estimate_tco2e))
    {
    goto end; //Numeric
    }
    spend_based_estimate_tco2e_local_var = malloc(sizeof(double));
    if(!spend_based_estimate_tco2e_local_var)
    {
        goto end;
    }
    *spend_based_estimate_tco2e_local_var = spend_based_estimate_tco2e->valuedouble;
    }

    // emissions_report->targets
    cJSON *targets = cJSON_GetObjectItemCaseSensitive(emissions_reportJSON, "targets");
    if (cJSON_IsNull(targets)) {
        targets = NULL;
    }
    if (!targets) {
        goto end;
    }

    
    cJSON *targets_local_nonprimitive = NULL;
    if(!cJSON_IsArray(targets)){
        goto end; //nonprimitive container
    }

    targetsList = list_createList();

    cJSON_ArrayForEach(targets_local_nonprimitive,targets )
    {
        if(!cJSON_IsObject(targets_local_nonprimitive)){
            goto end;
        }
        target_progress_t *targetsItem = target_progress_parseFromJSON(targets_local_nonprimitive);

        list_addElement(targetsList, targetsItem);
    }

    // emissions_report->total_tco2e
    cJSON *total_tco2e = cJSON_GetObjectItemCaseSensitive(emissions_reportJSON, "total_tco2e");
    if (cJSON_IsNull(total_tco2e)) {
        total_tco2e = NULL;
    }
    if (!total_tco2e) {
        goto end;
    }

    
    if(!cJSON_IsString(total_tco2e))
    {
    goto end; //String
    }


    if (total_tco2e && !cJSON_IsNull(total_tco2e)) total_tco2e_local_str = strdup(total_tco2e->valuestring);

    emissions_report_local_var = emissions_report_create_internal (
        by_categoryList,
        by_scopeList,
        by_yearList,
        data_quality_local_nonprim,
        intensity_per_employee_local_var,
        intensity_per_revenue_mio_local_var,
        net_revenue_local_var,
        spend_based_estimate_tco2e_local_var,
        targetsList,
        total_tco2e_local_str
        );

    if (!emissions_report_local_var) {
        goto end;
    }

    return emissions_report_local_var;
end:
    if (by_categoryList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, by_categoryList) {
            category_total_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(by_categoryList);
        by_categoryList = NULL;
    }
    if (by_scopeList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, by_scopeList) {
            scope_total_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(by_scopeList);
        by_scopeList = NULL;
    }
    if (by_yearList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, by_yearList) {
            year_total_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(by_yearList);
        by_yearList = NULL;
    }
    if (data_quality_local_nonprim) {
        data_quality_free(data_quality_local_nonprim);
        data_quality_local_nonprim = NULL;
    }
    if (intensity_per_employee_local_var) {
        free(intensity_per_employee_local_var);
        intensity_per_employee_local_var = NULL;
    }
    if (intensity_per_revenue_mio_local_var) {
        free(intensity_per_revenue_mio_local_var);
        intensity_per_revenue_mio_local_var = NULL;
    }
    if (net_revenue_local_var) {
        free(net_revenue_local_var);
        net_revenue_local_var = NULL;
    }
    if (spend_based_estimate_tco2e_local_var) {
        free(spend_based_estimate_tco2e_local_var);
        spend_based_estimate_tco2e_local_var = NULL;
    }
    if (targetsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, targetsList) {
            target_progress_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(targetsList);
        targetsList = NULL;
    }
    if (total_tco2e_local_str) {
        free(total_tco2e_local_str);
        total_tco2e_local_str = NULL;
    }
    return NULL;

}
