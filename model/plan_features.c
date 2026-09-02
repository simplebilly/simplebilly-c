#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plan_features.h"



static plan_features_t *plan_features_create_internal(
    int *connectors,
    int *erp,
    int *fancy_reports,
    int *tax_automations
    ) {
    plan_features_t *plan_features_local_var = malloc(sizeof(plan_features_t));
    if (!plan_features_local_var) {
        return NULL;
    }
    memset(plan_features_local_var, 0, sizeof(plan_features_t));
    plan_features_local_var->_library_owned = 1;
    plan_features_local_var->connectors = connectors;
    plan_features_local_var->erp = erp;
    plan_features_local_var->fancy_reports = fancy_reports;
    plan_features_local_var->tax_automations = tax_automations;
    return plan_features_local_var;
}

__attribute__((deprecated)) plan_features_t *plan_features_create(
    int *connectors,
    int *erp,
    int *fancy_reports,
    int *tax_automations
    ) {
    int *connectors_copy = NULL;
    if (connectors) {
        connectors_copy = malloc(sizeof(int));
        if (connectors_copy) *connectors_copy = *connectors;
    }
    int *erp_copy = NULL;
    if (erp) {
        erp_copy = malloc(sizeof(int));
        if (erp_copy) *erp_copy = *erp;
    }
    int *fancy_reports_copy = NULL;
    if (fancy_reports) {
        fancy_reports_copy = malloc(sizeof(int));
        if (fancy_reports_copy) *fancy_reports_copy = *fancy_reports;
    }
    int *tax_automations_copy = NULL;
    if (tax_automations) {
        tax_automations_copy = malloc(sizeof(int));
        if (tax_automations_copy) *tax_automations_copy = *tax_automations;
    }
    plan_features_t *result = plan_features_create_internal (
        connectors_copy,
        erp_copy,
        fancy_reports_copy,
        tax_automations_copy
        );
    if (!result) {
        free(connectors_copy);
        free(erp_copy);
        free(fancy_reports_copy);
        free(tax_automations_copy);
    }
    return result;
}

void plan_features_free(plan_features_t *plan_features) {
    if(NULL == plan_features){
        return ;
    }
    if(plan_features->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "plan_features_free");
        return ;
    }
    listEntry_t *listEntry;
    if (plan_features->connectors) {
        free(plan_features->connectors);
        plan_features->connectors = NULL;
    }
    if (plan_features->erp) {
        free(plan_features->erp);
        plan_features->erp = NULL;
    }
    if (plan_features->fancy_reports) {
        free(plan_features->fancy_reports);
        plan_features->fancy_reports = NULL;
    }
    if (plan_features->tax_automations) {
        free(plan_features->tax_automations);
        plan_features->tax_automations = NULL;
    }
    free(plan_features);
}

cJSON *plan_features_convertToJSON(plan_features_t *plan_features) {
    cJSON *item = cJSON_CreateObject();

    // plan_features->connectors
    if (!plan_features->connectors) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "connectors", *plan_features->connectors) == NULL) {
    goto fail; //Bool
    }


    // plan_features->erp
    if (!plan_features->erp) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "erp", *plan_features->erp) == NULL) {
    goto fail; //Bool
    }


    // plan_features->fancy_reports
    if (!plan_features->fancy_reports) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "fancyReports", *plan_features->fancy_reports) == NULL) {
    goto fail; //Bool
    }


    // plan_features->tax_automations
    if (!plan_features->tax_automations) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "taxAutomations", *plan_features->tax_automations) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

plan_features_t *plan_features_parseFromJSON(cJSON *plan_featuresJSON){

    plan_features_t *plan_features_local_var = NULL;

    // define the local variable for plan_features->connectors
    int *connectors_local_var = NULL;

    // define the local variable for plan_features->erp
    int *erp_local_var = NULL;

    // define the local variable for plan_features->fancy_reports
    int *fancy_reports_local_var = NULL;

    // define the local variable for plan_features->tax_automations
    int *tax_automations_local_var = NULL;

    // plan_features->connectors
    cJSON *connectors = cJSON_GetObjectItemCaseSensitive(plan_featuresJSON, "connectors");
    if (cJSON_IsNull(connectors)) {
        connectors = NULL;
    }
    if (!connectors) {
        goto end;
    }

    
    if(!cJSON_IsBool(connectors))
    {
    goto end; //Bool
    }
    connectors_local_var = malloc(sizeof(int));
    if(!connectors_local_var)
    {
        goto end;
    }
    *connectors_local_var = connectors->valueint;

    // plan_features->erp
    cJSON *erp = cJSON_GetObjectItemCaseSensitive(plan_featuresJSON, "erp");
    if (cJSON_IsNull(erp)) {
        erp = NULL;
    }
    if (!erp) {
        goto end;
    }

    
    if(!cJSON_IsBool(erp))
    {
    goto end; //Bool
    }
    erp_local_var = malloc(sizeof(int));
    if(!erp_local_var)
    {
        goto end;
    }
    *erp_local_var = erp->valueint;

    // plan_features->fancy_reports
    cJSON *fancy_reports = cJSON_GetObjectItemCaseSensitive(plan_featuresJSON, "fancyReports");
    if (cJSON_IsNull(fancy_reports)) {
        fancy_reports = NULL;
    }
    if (!fancy_reports) {
        goto end;
    }

    
    if(!cJSON_IsBool(fancy_reports))
    {
    goto end; //Bool
    }
    fancy_reports_local_var = malloc(sizeof(int));
    if(!fancy_reports_local_var)
    {
        goto end;
    }
    *fancy_reports_local_var = fancy_reports->valueint;

    // plan_features->tax_automations
    cJSON *tax_automations = cJSON_GetObjectItemCaseSensitive(plan_featuresJSON, "taxAutomations");
    if (cJSON_IsNull(tax_automations)) {
        tax_automations = NULL;
    }
    if (!tax_automations) {
        goto end;
    }

    
    if(!cJSON_IsBool(tax_automations))
    {
    goto end; //Bool
    }
    tax_automations_local_var = malloc(sizeof(int));
    if(!tax_automations_local_var)
    {
        goto end;
    }
    *tax_automations_local_var = tax_automations->valueint;



    plan_features_local_var = plan_features_create_internal (
        connectors_local_var,
        erp_local_var,
        fancy_reports_local_var,
        tax_automations_local_var
        );

    if (!plan_features_local_var) {
        goto end;
    }

    return plan_features_local_var;
end:
    if (connectors_local_var) {
        free(connectors_local_var);
        connectors_local_var = NULL;
    }
    if (erp_local_var) {
        free(erp_local_var);
        erp_local_var = NULL;
    }
    if (fancy_reports_local_var) {
        free(fancy_reports_local_var);
        fancy_reports_local_var = NULL;
    }
    if (tax_automations_local_var) {
        free(tax_automations_local_var);
        tax_automations_local_var = NULL;
    }
    return NULL;

}
