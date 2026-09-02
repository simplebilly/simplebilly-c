#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "partial_feature_settings.h"



static partial_feature_settings_t *partial_feature_settings_create_internal(
    int *onlineshop,
    int *report_bilanz,
    int *report_bwa,
    int *report_euer,
    int *report_gewerbesteuer,
    int *report_guv,
    int *report_kst,
    int *report_ustva
    ) {
    partial_feature_settings_t *partial_feature_settings_local_var = malloc(sizeof(partial_feature_settings_t));
    if (!partial_feature_settings_local_var) {
        return NULL;
    }
    memset(partial_feature_settings_local_var, 0, sizeof(partial_feature_settings_t));
    partial_feature_settings_local_var->_library_owned = 1;
    partial_feature_settings_local_var->onlineshop = onlineshop;
    partial_feature_settings_local_var->report_bilanz = report_bilanz;
    partial_feature_settings_local_var->report_bwa = report_bwa;
    partial_feature_settings_local_var->report_euer = report_euer;
    partial_feature_settings_local_var->report_gewerbesteuer = report_gewerbesteuer;
    partial_feature_settings_local_var->report_guv = report_guv;
    partial_feature_settings_local_var->report_kst = report_kst;
    partial_feature_settings_local_var->report_ustva = report_ustva;
    return partial_feature_settings_local_var;
}

__attribute__((deprecated)) partial_feature_settings_t *partial_feature_settings_create(
    int *onlineshop,
    int *report_bilanz,
    int *report_bwa,
    int *report_euer,
    int *report_gewerbesteuer,
    int *report_guv,
    int *report_kst,
    int *report_ustva
    ) {
    int *onlineshop_copy = NULL;
    if (onlineshop) {
        onlineshop_copy = malloc(sizeof(int));
        if (onlineshop_copy) *onlineshop_copy = *onlineshop;
    }
    int *report_bilanz_copy = NULL;
    if (report_bilanz) {
        report_bilanz_copy = malloc(sizeof(int));
        if (report_bilanz_copy) *report_bilanz_copy = *report_bilanz;
    }
    int *report_bwa_copy = NULL;
    if (report_bwa) {
        report_bwa_copy = malloc(sizeof(int));
        if (report_bwa_copy) *report_bwa_copy = *report_bwa;
    }
    int *report_euer_copy = NULL;
    if (report_euer) {
        report_euer_copy = malloc(sizeof(int));
        if (report_euer_copy) *report_euer_copy = *report_euer;
    }
    int *report_gewerbesteuer_copy = NULL;
    if (report_gewerbesteuer) {
        report_gewerbesteuer_copy = malloc(sizeof(int));
        if (report_gewerbesteuer_copy) *report_gewerbesteuer_copy = *report_gewerbesteuer;
    }
    int *report_guv_copy = NULL;
    if (report_guv) {
        report_guv_copy = malloc(sizeof(int));
        if (report_guv_copy) *report_guv_copy = *report_guv;
    }
    int *report_kst_copy = NULL;
    if (report_kst) {
        report_kst_copy = malloc(sizeof(int));
        if (report_kst_copy) *report_kst_copy = *report_kst;
    }
    int *report_ustva_copy = NULL;
    if (report_ustva) {
        report_ustva_copy = malloc(sizeof(int));
        if (report_ustva_copy) *report_ustva_copy = *report_ustva;
    }
    partial_feature_settings_t *result = partial_feature_settings_create_internal (
        onlineshop_copy,
        report_bilanz_copy,
        report_bwa_copy,
        report_euer_copy,
        report_gewerbesteuer_copy,
        report_guv_copy,
        report_kst_copy,
        report_ustva_copy
        );
    if (!result) {
        free(onlineshop_copy);
        free(report_bilanz_copy);
        free(report_bwa_copy);
        free(report_euer_copy);
        free(report_gewerbesteuer_copy);
        free(report_guv_copy);
        free(report_kst_copy);
        free(report_ustva_copy);
    }
    return result;
}

void partial_feature_settings_free(partial_feature_settings_t *partial_feature_settings) {
    if(NULL == partial_feature_settings){
        return ;
    }
    if(partial_feature_settings->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "partial_feature_settings_free");
        return ;
    }
    listEntry_t *listEntry;
    if (partial_feature_settings->onlineshop) {
        free(partial_feature_settings->onlineshop);
        partial_feature_settings->onlineshop = NULL;
    }
    if (partial_feature_settings->report_bilanz) {
        free(partial_feature_settings->report_bilanz);
        partial_feature_settings->report_bilanz = NULL;
    }
    if (partial_feature_settings->report_bwa) {
        free(partial_feature_settings->report_bwa);
        partial_feature_settings->report_bwa = NULL;
    }
    if (partial_feature_settings->report_euer) {
        free(partial_feature_settings->report_euer);
        partial_feature_settings->report_euer = NULL;
    }
    if (partial_feature_settings->report_gewerbesteuer) {
        free(partial_feature_settings->report_gewerbesteuer);
        partial_feature_settings->report_gewerbesteuer = NULL;
    }
    if (partial_feature_settings->report_guv) {
        free(partial_feature_settings->report_guv);
        partial_feature_settings->report_guv = NULL;
    }
    if (partial_feature_settings->report_kst) {
        free(partial_feature_settings->report_kst);
        partial_feature_settings->report_kst = NULL;
    }
    if (partial_feature_settings->report_ustva) {
        free(partial_feature_settings->report_ustva);
        partial_feature_settings->report_ustva = NULL;
    }
    free(partial_feature_settings);
}

cJSON *partial_feature_settings_convertToJSON(partial_feature_settings_t *partial_feature_settings) {
    cJSON *item = cJSON_CreateObject();

    // partial_feature_settings->onlineshop
    if(partial_feature_settings->onlineshop) {
    if(cJSON_AddBoolToObject(item, "onlineshop", *partial_feature_settings->onlineshop) == NULL) {
    goto fail; //Bool
    }
    }


    // partial_feature_settings->report_bilanz
    if(partial_feature_settings->report_bilanz) {
    if(cJSON_AddBoolToObject(item, "reportBilanz", *partial_feature_settings->report_bilanz) == NULL) {
    goto fail; //Bool
    }
    }


    // partial_feature_settings->report_bwa
    if(partial_feature_settings->report_bwa) {
    if(cJSON_AddBoolToObject(item, "reportBwa", *partial_feature_settings->report_bwa) == NULL) {
    goto fail; //Bool
    }
    }


    // partial_feature_settings->report_euer
    if(partial_feature_settings->report_euer) {
    if(cJSON_AddBoolToObject(item, "reportEuer", *partial_feature_settings->report_euer) == NULL) {
    goto fail; //Bool
    }
    }


    // partial_feature_settings->report_gewerbesteuer
    if(partial_feature_settings->report_gewerbesteuer) {
    if(cJSON_AddBoolToObject(item, "reportGewerbesteuer", *partial_feature_settings->report_gewerbesteuer) == NULL) {
    goto fail; //Bool
    }
    }


    // partial_feature_settings->report_guv
    if(partial_feature_settings->report_guv) {
    if(cJSON_AddBoolToObject(item, "reportGuv", *partial_feature_settings->report_guv) == NULL) {
    goto fail; //Bool
    }
    }


    // partial_feature_settings->report_kst
    if(partial_feature_settings->report_kst) {
    if(cJSON_AddBoolToObject(item, "reportKst", *partial_feature_settings->report_kst) == NULL) {
    goto fail; //Bool
    }
    }


    // partial_feature_settings->report_ustva
    if(partial_feature_settings->report_ustva) {
    if(cJSON_AddBoolToObject(item, "reportUstva", *partial_feature_settings->report_ustva) == NULL) {
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

partial_feature_settings_t *partial_feature_settings_parseFromJSON(cJSON *partial_feature_settingsJSON){

    partial_feature_settings_t *partial_feature_settings_local_var = NULL;

    // define the local variable for partial_feature_settings->onlineshop
    int *onlineshop_local_var = NULL;

    // define the local variable for partial_feature_settings->report_bilanz
    int *report_bilanz_local_var = NULL;

    // define the local variable for partial_feature_settings->report_bwa
    int *report_bwa_local_var = NULL;

    // define the local variable for partial_feature_settings->report_euer
    int *report_euer_local_var = NULL;

    // define the local variable for partial_feature_settings->report_gewerbesteuer
    int *report_gewerbesteuer_local_var = NULL;

    // define the local variable for partial_feature_settings->report_guv
    int *report_guv_local_var = NULL;

    // define the local variable for partial_feature_settings->report_kst
    int *report_kst_local_var = NULL;

    // define the local variable for partial_feature_settings->report_ustva
    int *report_ustva_local_var = NULL;

    // partial_feature_settings->onlineshop
    cJSON *onlineshop = cJSON_GetObjectItemCaseSensitive(partial_feature_settingsJSON, "onlineshop");
    if (cJSON_IsNull(onlineshop)) {
        onlineshop = NULL;
    }
    if (onlineshop) { 
    if(!cJSON_IsBool(onlineshop))
    {
    goto end; //Bool
    }
    onlineshop_local_var = malloc(sizeof(int));
    if(!onlineshop_local_var)
    {
        goto end;
    }
    *onlineshop_local_var = onlineshop->valueint;
    }

    // partial_feature_settings->report_bilanz
    cJSON *report_bilanz = cJSON_GetObjectItemCaseSensitive(partial_feature_settingsJSON, "reportBilanz");
    if (cJSON_IsNull(report_bilanz)) {
        report_bilanz = NULL;
    }
    if (report_bilanz) { 
    if(!cJSON_IsBool(report_bilanz))
    {
    goto end; //Bool
    }
    report_bilanz_local_var = malloc(sizeof(int));
    if(!report_bilanz_local_var)
    {
        goto end;
    }
    *report_bilanz_local_var = report_bilanz->valueint;
    }

    // partial_feature_settings->report_bwa
    cJSON *report_bwa = cJSON_GetObjectItemCaseSensitive(partial_feature_settingsJSON, "reportBwa");
    if (cJSON_IsNull(report_bwa)) {
        report_bwa = NULL;
    }
    if (report_bwa) { 
    if(!cJSON_IsBool(report_bwa))
    {
    goto end; //Bool
    }
    report_bwa_local_var = malloc(sizeof(int));
    if(!report_bwa_local_var)
    {
        goto end;
    }
    *report_bwa_local_var = report_bwa->valueint;
    }

    // partial_feature_settings->report_euer
    cJSON *report_euer = cJSON_GetObjectItemCaseSensitive(partial_feature_settingsJSON, "reportEuer");
    if (cJSON_IsNull(report_euer)) {
        report_euer = NULL;
    }
    if (report_euer) { 
    if(!cJSON_IsBool(report_euer))
    {
    goto end; //Bool
    }
    report_euer_local_var = malloc(sizeof(int));
    if(!report_euer_local_var)
    {
        goto end;
    }
    *report_euer_local_var = report_euer->valueint;
    }

    // partial_feature_settings->report_gewerbesteuer
    cJSON *report_gewerbesteuer = cJSON_GetObjectItemCaseSensitive(partial_feature_settingsJSON, "reportGewerbesteuer");
    if (cJSON_IsNull(report_gewerbesteuer)) {
        report_gewerbesteuer = NULL;
    }
    if (report_gewerbesteuer) { 
    if(!cJSON_IsBool(report_gewerbesteuer))
    {
    goto end; //Bool
    }
    report_gewerbesteuer_local_var = malloc(sizeof(int));
    if(!report_gewerbesteuer_local_var)
    {
        goto end;
    }
    *report_gewerbesteuer_local_var = report_gewerbesteuer->valueint;
    }

    // partial_feature_settings->report_guv
    cJSON *report_guv = cJSON_GetObjectItemCaseSensitive(partial_feature_settingsJSON, "reportGuv");
    if (cJSON_IsNull(report_guv)) {
        report_guv = NULL;
    }
    if (report_guv) { 
    if(!cJSON_IsBool(report_guv))
    {
    goto end; //Bool
    }
    report_guv_local_var = malloc(sizeof(int));
    if(!report_guv_local_var)
    {
        goto end;
    }
    *report_guv_local_var = report_guv->valueint;
    }

    // partial_feature_settings->report_kst
    cJSON *report_kst = cJSON_GetObjectItemCaseSensitive(partial_feature_settingsJSON, "reportKst");
    if (cJSON_IsNull(report_kst)) {
        report_kst = NULL;
    }
    if (report_kst) { 
    if(!cJSON_IsBool(report_kst))
    {
    goto end; //Bool
    }
    report_kst_local_var = malloc(sizeof(int));
    if(!report_kst_local_var)
    {
        goto end;
    }
    *report_kst_local_var = report_kst->valueint;
    }

    // partial_feature_settings->report_ustva
    cJSON *report_ustva = cJSON_GetObjectItemCaseSensitive(partial_feature_settingsJSON, "reportUstva");
    if (cJSON_IsNull(report_ustva)) {
        report_ustva = NULL;
    }
    if (report_ustva) { 
    if(!cJSON_IsBool(report_ustva))
    {
    goto end; //Bool
    }
    report_ustva_local_var = malloc(sizeof(int));
    if(!report_ustva_local_var)
    {
        goto end;
    }
    *report_ustva_local_var = report_ustva->valueint;
    }



    partial_feature_settings_local_var = partial_feature_settings_create_internal (
        onlineshop_local_var,
        report_bilanz_local_var,
        report_bwa_local_var,
        report_euer_local_var,
        report_gewerbesteuer_local_var,
        report_guv_local_var,
        report_kst_local_var,
        report_ustva_local_var
        );

    if (!partial_feature_settings_local_var) {
        goto end;
    }

    return partial_feature_settings_local_var;
end:
    if (onlineshop_local_var) {
        free(onlineshop_local_var);
        onlineshop_local_var = NULL;
    }
    if (report_bilanz_local_var) {
        free(report_bilanz_local_var);
        report_bilanz_local_var = NULL;
    }
    if (report_bwa_local_var) {
        free(report_bwa_local_var);
        report_bwa_local_var = NULL;
    }
    if (report_euer_local_var) {
        free(report_euer_local_var);
        report_euer_local_var = NULL;
    }
    if (report_gewerbesteuer_local_var) {
        free(report_gewerbesteuer_local_var);
        report_gewerbesteuer_local_var = NULL;
    }
    if (report_guv_local_var) {
        free(report_guv_local_var);
        report_guv_local_var = NULL;
    }
    if (report_kst_local_var) {
        free(report_kst_local_var);
        report_kst_local_var = NULL;
    }
    if (report_ustva_local_var) {
        free(report_ustva_local_var);
        report_ustva_local_var = NULL;
    }
    return NULL;

}
