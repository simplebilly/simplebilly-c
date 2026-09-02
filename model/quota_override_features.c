#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "quota_override_features.h"



static quota_override_features_t *quota_override_features_create_internal(
    int *erp,
    int *fancy_reports,
    int *tax_automations
    ) {
    quota_override_features_t *quota_override_features_local_var = malloc(sizeof(quota_override_features_t));
    if (!quota_override_features_local_var) {
        return NULL;
    }
    memset(quota_override_features_local_var, 0, sizeof(quota_override_features_t));
    quota_override_features_local_var->_library_owned = 1;
    quota_override_features_local_var->erp = erp;
    quota_override_features_local_var->fancy_reports = fancy_reports;
    quota_override_features_local_var->tax_automations = tax_automations;
    return quota_override_features_local_var;
}

__attribute__((deprecated)) quota_override_features_t *quota_override_features_create(
    int *erp,
    int *fancy_reports,
    int *tax_automations
    ) {
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
    quota_override_features_t *result = quota_override_features_create_internal (
        erp_copy,
        fancy_reports_copy,
        tax_automations_copy
        );
    if (!result) {
        free(erp_copy);
        free(fancy_reports_copy);
        free(tax_automations_copy);
    }
    return result;
}

void quota_override_features_free(quota_override_features_t *quota_override_features) {
    if(NULL == quota_override_features){
        return ;
    }
    if(quota_override_features->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "quota_override_features_free");
        return ;
    }
    listEntry_t *listEntry;
    if (quota_override_features->erp) {
        free(quota_override_features->erp);
        quota_override_features->erp = NULL;
    }
    if (quota_override_features->fancy_reports) {
        free(quota_override_features->fancy_reports);
        quota_override_features->fancy_reports = NULL;
    }
    if (quota_override_features->tax_automations) {
        free(quota_override_features->tax_automations);
        quota_override_features->tax_automations = NULL;
    }
    free(quota_override_features);
}

cJSON *quota_override_features_convertToJSON(quota_override_features_t *quota_override_features) {
    cJSON *item = cJSON_CreateObject();

    // quota_override_features->erp
    if(quota_override_features->erp) {
    if(cJSON_AddBoolToObject(item, "erp", *quota_override_features->erp) == NULL) {
    goto fail; //Bool
    }
    }


    // quota_override_features->fancy_reports
    if(quota_override_features->fancy_reports) {
    if(cJSON_AddBoolToObject(item, "fancy_reports", *quota_override_features->fancy_reports) == NULL) {
    goto fail; //Bool
    }
    }


    // quota_override_features->tax_automations
    if(quota_override_features->tax_automations) {
    if(cJSON_AddBoolToObject(item, "tax_automations", *quota_override_features->tax_automations) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

quota_override_features_t *quota_override_features_parseFromJSON(cJSON *quota_override_featuresJSON){

    quota_override_features_t *quota_override_features_local_var = NULL;

    // define the local variable for quota_override_features->erp
    int *erp_local_var = NULL;

    // define the local variable for quota_override_features->fancy_reports
    int *fancy_reports_local_var = NULL;

    // define the local variable for quota_override_features->tax_automations
    int *tax_automations_local_var = NULL;

    // quota_override_features->erp
    cJSON *erp = cJSON_GetObjectItemCaseSensitive(quota_override_featuresJSON, "erp");
    if (cJSON_IsNull(erp)) {
        erp = NULL;
    }
    if (erp) { 
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
    }

    // quota_override_features->fancy_reports
    cJSON *fancy_reports = cJSON_GetObjectItemCaseSensitive(quota_override_featuresJSON, "fancy_reports");
    if (cJSON_IsNull(fancy_reports)) {
        fancy_reports = NULL;
    }
    if (fancy_reports) { 
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
    }

    // quota_override_features->tax_automations
    cJSON *tax_automations = cJSON_GetObjectItemCaseSensitive(quota_override_featuresJSON, "tax_automations");
    if (cJSON_IsNull(tax_automations)) {
        tax_automations = NULL;
    }
    if (tax_automations) { 
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
    }



    quota_override_features_local_var = quota_override_features_create_internal (
        erp_local_var,
        fancy_reports_local_var,
        tax_automations_local_var
        );

    if (!quota_override_features_local_var) {
        goto end;
    }

    return quota_override_features_local_var;
end:
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
