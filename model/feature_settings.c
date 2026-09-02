#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "feature_settings.h"



static feature_settings_t *feature_settings_create_internal(
    int *onlineshop,
    int *report_bilanz,
    int *report_bwa,
    int *report_euer,
    int *report_gewerbesteuer,
    int *report_guv,
    int *report_kst,
    int *report_ustva
    ) {
    feature_settings_t *feature_settings_local_var = malloc(sizeof(feature_settings_t));
    if (!feature_settings_local_var) {
        return NULL;
    }
    memset(feature_settings_local_var, 0, sizeof(feature_settings_t));
    feature_settings_local_var->_library_owned = 1;
    feature_settings_local_var->onlineshop = onlineshop;
    feature_settings_local_var->report_bilanz = report_bilanz;
    feature_settings_local_var->report_bwa = report_bwa;
    feature_settings_local_var->report_euer = report_euer;
    feature_settings_local_var->report_gewerbesteuer = report_gewerbesteuer;
    feature_settings_local_var->report_guv = report_guv;
    feature_settings_local_var->report_kst = report_kst;
    feature_settings_local_var->report_ustva = report_ustva;
    return feature_settings_local_var;
}

__attribute__((deprecated)) feature_settings_t *feature_settings_create(
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
    feature_settings_t *result = feature_settings_create_internal (
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

void feature_settings_free(feature_settings_t *feature_settings) {
    if(NULL == feature_settings){
        return ;
    }
    if(feature_settings->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "feature_settings_free");
        return ;
    }
    listEntry_t *listEntry;
    if (feature_settings->onlineshop) {
        free(feature_settings->onlineshop);
        feature_settings->onlineshop = NULL;
    }
    if (feature_settings->report_bilanz) {
        free(feature_settings->report_bilanz);
        feature_settings->report_bilanz = NULL;
    }
    if (feature_settings->report_bwa) {
        free(feature_settings->report_bwa);
        feature_settings->report_bwa = NULL;
    }
    if (feature_settings->report_euer) {
        free(feature_settings->report_euer);
        feature_settings->report_euer = NULL;
    }
    if (feature_settings->report_gewerbesteuer) {
        free(feature_settings->report_gewerbesteuer);
        feature_settings->report_gewerbesteuer = NULL;
    }
    if (feature_settings->report_guv) {
        free(feature_settings->report_guv);
        feature_settings->report_guv = NULL;
    }
    if (feature_settings->report_kst) {
        free(feature_settings->report_kst);
        feature_settings->report_kst = NULL;
    }
    if (feature_settings->report_ustva) {
        free(feature_settings->report_ustva);
        feature_settings->report_ustva = NULL;
    }
    free(feature_settings);
}

cJSON *feature_settings_convertToJSON(feature_settings_t *feature_settings) {
    cJSON *item = cJSON_CreateObject();

    // feature_settings->onlineshop
    if (!feature_settings->onlineshop) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "onlineshop", *feature_settings->onlineshop) == NULL) {
    goto fail; //Bool
    }


    // feature_settings->report_bilanz
    if (!feature_settings->report_bilanz) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "reportBilanz", *feature_settings->report_bilanz) == NULL) {
    goto fail; //Bool
    }


    // feature_settings->report_bwa
    if (!feature_settings->report_bwa) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "reportBwa", *feature_settings->report_bwa) == NULL) {
    goto fail; //Bool
    }


    // feature_settings->report_euer
    if (!feature_settings->report_euer) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "reportEuer", *feature_settings->report_euer) == NULL) {
    goto fail; //Bool
    }


    // feature_settings->report_gewerbesteuer
    if (!feature_settings->report_gewerbesteuer) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "reportGewerbesteuer", *feature_settings->report_gewerbesteuer) == NULL) {
    goto fail; //Bool
    }


    // feature_settings->report_guv
    if (!feature_settings->report_guv) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "reportGuv", *feature_settings->report_guv) == NULL) {
    goto fail; //Bool
    }


    // feature_settings->report_kst
    if (!feature_settings->report_kst) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "reportKst", *feature_settings->report_kst) == NULL) {
    goto fail; //Bool
    }


    // feature_settings->report_ustva
    if (!feature_settings->report_ustva) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "reportUstva", *feature_settings->report_ustva) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

feature_settings_t *feature_settings_parseFromJSON(cJSON *feature_settingsJSON){

    feature_settings_t *feature_settings_local_var = NULL;

    // define the local variable for feature_settings->onlineshop
    int *onlineshop_local_var = NULL;

    // define the local variable for feature_settings->report_bilanz
    int *report_bilanz_local_var = NULL;

    // define the local variable for feature_settings->report_bwa
    int *report_bwa_local_var = NULL;

    // define the local variable for feature_settings->report_euer
    int *report_euer_local_var = NULL;

    // define the local variable for feature_settings->report_gewerbesteuer
    int *report_gewerbesteuer_local_var = NULL;

    // define the local variable for feature_settings->report_guv
    int *report_guv_local_var = NULL;

    // define the local variable for feature_settings->report_kst
    int *report_kst_local_var = NULL;

    // define the local variable for feature_settings->report_ustva
    int *report_ustva_local_var = NULL;

    // feature_settings->onlineshop
    cJSON *onlineshop = cJSON_GetObjectItemCaseSensitive(feature_settingsJSON, "onlineshop");
    if (cJSON_IsNull(onlineshop)) {
        onlineshop = NULL;
    }
    if (!onlineshop) {
        goto end;
    }

    
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

    // feature_settings->report_bilanz
    cJSON *report_bilanz = cJSON_GetObjectItemCaseSensitive(feature_settingsJSON, "reportBilanz");
    if (cJSON_IsNull(report_bilanz)) {
        report_bilanz = NULL;
    }
    if (!report_bilanz) {
        goto end;
    }

    
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

    // feature_settings->report_bwa
    cJSON *report_bwa = cJSON_GetObjectItemCaseSensitive(feature_settingsJSON, "reportBwa");
    if (cJSON_IsNull(report_bwa)) {
        report_bwa = NULL;
    }
    if (!report_bwa) {
        goto end;
    }

    
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

    // feature_settings->report_euer
    cJSON *report_euer = cJSON_GetObjectItemCaseSensitive(feature_settingsJSON, "reportEuer");
    if (cJSON_IsNull(report_euer)) {
        report_euer = NULL;
    }
    if (!report_euer) {
        goto end;
    }

    
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

    // feature_settings->report_gewerbesteuer
    cJSON *report_gewerbesteuer = cJSON_GetObjectItemCaseSensitive(feature_settingsJSON, "reportGewerbesteuer");
    if (cJSON_IsNull(report_gewerbesteuer)) {
        report_gewerbesteuer = NULL;
    }
    if (!report_gewerbesteuer) {
        goto end;
    }

    
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

    // feature_settings->report_guv
    cJSON *report_guv = cJSON_GetObjectItemCaseSensitive(feature_settingsJSON, "reportGuv");
    if (cJSON_IsNull(report_guv)) {
        report_guv = NULL;
    }
    if (!report_guv) {
        goto end;
    }

    
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

    // feature_settings->report_kst
    cJSON *report_kst = cJSON_GetObjectItemCaseSensitive(feature_settingsJSON, "reportKst");
    if (cJSON_IsNull(report_kst)) {
        report_kst = NULL;
    }
    if (!report_kst) {
        goto end;
    }

    
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

    // feature_settings->report_ustva
    cJSON *report_ustva = cJSON_GetObjectItemCaseSensitive(feature_settingsJSON, "reportUstva");
    if (cJSON_IsNull(report_ustva)) {
        report_ustva = NULL;
    }
    if (!report_ustva) {
        goto end;
    }

    
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



    feature_settings_local_var = feature_settings_create_internal (
        onlineshop_local_var,
        report_bilanz_local_var,
        report_bwa_local_var,
        report_euer_local_var,
        report_gewerbesteuer_local_var,
        report_guv_local_var,
        report_kst_local_var,
        report_ustva_local_var
        );

    if (!feature_settings_local_var) {
        goto end;
    }

    return feature_settings_local_var;
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
