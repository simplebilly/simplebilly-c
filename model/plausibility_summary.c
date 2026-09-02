#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plausibility_summary.h"



static plausibility_summary_t *plausibility_summary_create_internal(
    int *errors,
    simplebilly_api_check_status__e overall_status,
    int *passed,
    int *total_checks,
    int *warnings
    ) {
    plausibility_summary_t *plausibility_summary_local_var = malloc(sizeof(plausibility_summary_t));
    if (!plausibility_summary_local_var) {
        return NULL;
    }
    memset(plausibility_summary_local_var, 0, sizeof(plausibility_summary_t));
    plausibility_summary_local_var->_library_owned = 1;
    plausibility_summary_local_var->errors = errors;
    plausibility_summary_local_var->overall_status = overall_status;
    plausibility_summary_local_var->passed = passed;
    plausibility_summary_local_var->total_checks = total_checks;
    plausibility_summary_local_var->warnings = warnings;
    return plausibility_summary_local_var;
}

__attribute__((deprecated)) plausibility_summary_t *plausibility_summary_create(
    int *errors,
    simplebilly_api_check_status__e overall_status,
    int *passed,
    int *total_checks,
    int *warnings
    ) {
    int *errors_copy = NULL;
    if (errors) {
        errors_copy = malloc(sizeof(int));
        if (errors_copy) *errors_copy = *errors;
    }
    int *passed_copy = NULL;
    if (passed) {
        passed_copy = malloc(sizeof(int));
        if (passed_copy) *passed_copy = *passed;
    }
    int *total_checks_copy = NULL;
    if (total_checks) {
        total_checks_copy = malloc(sizeof(int));
        if (total_checks_copy) *total_checks_copy = *total_checks;
    }
    int *warnings_copy = NULL;
    if (warnings) {
        warnings_copy = malloc(sizeof(int));
        if (warnings_copy) *warnings_copy = *warnings;
    }
    plausibility_summary_t *result = plausibility_summary_create_internal (
        errors_copy,
        overall_status,
        passed_copy,
        total_checks_copy,
        warnings_copy
        );
    if (!result) {
        free(errors_copy);
        free(passed_copy);
        free(total_checks_copy);
        free(warnings_copy);
    }
    return result;
}

void plausibility_summary_free(plausibility_summary_t *plausibility_summary) {
    if(NULL == plausibility_summary){
        return ;
    }
    if(plausibility_summary->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "plausibility_summary_free");
        return ;
    }
    listEntry_t *listEntry;
    if (plausibility_summary->errors) {
        free(plausibility_summary->errors);
        plausibility_summary->errors = NULL;
    }
    if (plausibility_summary->passed) {
        free(plausibility_summary->passed);
        plausibility_summary->passed = NULL;
    }
    if (plausibility_summary->total_checks) {
        free(plausibility_summary->total_checks);
        plausibility_summary->total_checks = NULL;
    }
    if (plausibility_summary->warnings) {
        free(plausibility_summary->warnings);
        plausibility_summary->warnings = NULL;
    }
    free(plausibility_summary);
}

cJSON *plausibility_summary_convertToJSON(plausibility_summary_t *plausibility_summary) {
    cJSON *item = cJSON_CreateObject();

    // plausibility_summary->errors
    if (!plausibility_summary->errors) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "errors", *plausibility_summary->errors) == NULL) {
    goto fail; //Numeric
    }


    // plausibility_summary->overall_status
    if (simplebilly_api_check_status__NULL == plausibility_summary->overall_status) {
        goto fail;
    }
    cJSON *overall_status_local_JSON = check_status_convertToJSON(plausibility_summary->overall_status);
    if(overall_status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "overall_status", overall_status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // plausibility_summary->passed
    if (!plausibility_summary->passed) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "passed", *plausibility_summary->passed) == NULL) {
    goto fail; //Numeric
    }


    // plausibility_summary->total_checks
    if (!plausibility_summary->total_checks) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total_checks", *plausibility_summary->total_checks) == NULL) {
    goto fail; //Numeric
    }


    // plausibility_summary->warnings
    if (!plausibility_summary->warnings) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "warnings", *plausibility_summary->warnings) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

plausibility_summary_t *plausibility_summary_parseFromJSON(cJSON *plausibility_summaryJSON){

    plausibility_summary_t *plausibility_summary_local_var = NULL;

    // define the local variable for plausibility_summary->errors
    int *errors_local_var = NULL;

    // define the local variable for plausibility_summary->overall_status
    simplebilly_api_check_status__e overall_status_local_nonprim = 0;

    // define the local variable for plausibility_summary->passed
    int *passed_local_var = NULL;

    // define the local variable for plausibility_summary->total_checks
    int *total_checks_local_var = NULL;

    // define the local variable for plausibility_summary->warnings
    int *warnings_local_var = NULL;

    // plausibility_summary->errors
    cJSON *errors = cJSON_GetObjectItemCaseSensitive(plausibility_summaryJSON, "errors");
    if (cJSON_IsNull(errors)) {
        errors = NULL;
    }
    if (!errors) {
        goto end;
    }

    
    if(!cJSON_IsNumber(errors))
    {
    goto end; //Numeric
    }
    errors_local_var = malloc(sizeof(int));
    if(!errors_local_var)
    {
        goto end;
    }
    *errors_local_var = errors->valuedouble;

    // plausibility_summary->overall_status
    cJSON *overall_status = cJSON_GetObjectItemCaseSensitive(plausibility_summaryJSON, "overall_status");
    if (cJSON_IsNull(overall_status)) {
        overall_status = NULL;
    }
    if (!overall_status) {
        goto end;
    }

    
    overall_status_local_nonprim = check_status_parseFromJSON(overall_status); //custom

    // plausibility_summary->passed
    cJSON *passed = cJSON_GetObjectItemCaseSensitive(plausibility_summaryJSON, "passed");
    if (cJSON_IsNull(passed)) {
        passed = NULL;
    }
    if (!passed) {
        goto end;
    }

    
    if(!cJSON_IsNumber(passed))
    {
    goto end; //Numeric
    }
    passed_local_var = malloc(sizeof(int));
    if(!passed_local_var)
    {
        goto end;
    }
    *passed_local_var = passed->valuedouble;

    // plausibility_summary->total_checks
    cJSON *total_checks = cJSON_GetObjectItemCaseSensitive(plausibility_summaryJSON, "total_checks");
    if (cJSON_IsNull(total_checks)) {
        total_checks = NULL;
    }
    if (!total_checks) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total_checks))
    {
    goto end; //Numeric
    }
    total_checks_local_var = malloc(sizeof(int));
    if(!total_checks_local_var)
    {
        goto end;
    }
    *total_checks_local_var = total_checks->valuedouble;

    // plausibility_summary->warnings
    cJSON *warnings = cJSON_GetObjectItemCaseSensitive(plausibility_summaryJSON, "warnings");
    if (cJSON_IsNull(warnings)) {
        warnings = NULL;
    }
    if (!warnings) {
        goto end;
    }

    
    if(!cJSON_IsNumber(warnings))
    {
    goto end; //Numeric
    }
    warnings_local_var = malloc(sizeof(int));
    if(!warnings_local_var)
    {
        goto end;
    }
    *warnings_local_var = warnings->valuedouble;



    plausibility_summary_local_var = plausibility_summary_create_internal (
        errors_local_var,
        overall_status_local_nonprim,
        passed_local_var,
        total_checks_local_var,
        warnings_local_var
        );

    if (!plausibility_summary_local_var) {
        goto end;
    }

    return plausibility_summary_local_var;
end:
    if (errors_local_var) {
        free(errors_local_var);
        errors_local_var = NULL;
    }
    if (overall_status_local_nonprim) {
        overall_status_local_nonprim = 0;
    }
    if (passed_local_var) {
        free(passed_local_var);
        passed_local_var = NULL;
    }
    if (total_checks_local_var) {
        free(total_checks_local_var);
        total_checks_local_var = NULL;
    }
    if (warnings_local_var) {
        free(warnings_local_var);
        warnings_local_var = NULL;
    }
    return NULL;

}
