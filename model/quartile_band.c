#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "quartile_band.h"



static quartile_band_t *quartile_band_create_internal(
    double *female_share_pct,
    char *hourly_median,
    double *male_share_pct,
    char *quartile
    ) {
    quartile_band_t *quartile_band_local_var = malloc(sizeof(quartile_band_t));
    if (!quartile_band_local_var) {
        return NULL;
    }
    memset(quartile_band_local_var, 0, sizeof(quartile_band_t));
    quartile_band_local_var->_library_owned = 1;
    quartile_band_local_var->female_share_pct = female_share_pct;
    quartile_band_local_var->hourly_median = hourly_median;
    quartile_band_local_var->male_share_pct = male_share_pct;
    quartile_band_local_var->quartile = quartile;
    return quartile_band_local_var;
}

__attribute__((deprecated)) quartile_band_t *quartile_band_create(
    double *female_share_pct,
    char *hourly_median,
    double *male_share_pct,
    char *quartile
    ) {
    double *female_share_pct_copy = NULL;
    if (female_share_pct) {
        female_share_pct_copy = malloc(sizeof(double));
        if (female_share_pct_copy) *female_share_pct_copy = *female_share_pct;
    }
    double *male_share_pct_copy = NULL;
    if (male_share_pct) {
        male_share_pct_copy = malloc(sizeof(double));
        if (male_share_pct_copy) *male_share_pct_copy = *male_share_pct;
    }
    quartile_band_t *result = quartile_band_create_internal (
        female_share_pct_copy,
        hourly_median,
        male_share_pct_copy,
        quartile
        );
    if (!result) {
        free(female_share_pct_copy);
        free(male_share_pct_copy);
    }
    return result;
}

void quartile_band_free(quartile_band_t *quartile_band) {
    if(NULL == quartile_band){
        return ;
    }
    if(quartile_band->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "quartile_band_free");
        return ;
    }
    listEntry_t *listEntry;
    if (quartile_band->female_share_pct) {
        free(quartile_band->female_share_pct);
        quartile_band->female_share_pct = NULL;
    }
    if (quartile_band->hourly_median) {
        free(quartile_band->hourly_median);
        quartile_band->hourly_median = NULL;
    }
    if (quartile_band->male_share_pct) {
        free(quartile_band->male_share_pct);
        quartile_band->male_share_pct = NULL;
    }
    if (quartile_band->quartile) {
        free(quartile_band->quartile);
        quartile_band->quartile = NULL;
    }
    free(quartile_band);
}

cJSON *quartile_band_convertToJSON(quartile_band_t *quartile_band) {
    cJSON *item = cJSON_CreateObject();

    // quartile_band->female_share_pct
    if (!quartile_band->female_share_pct) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "female_share_pct", *quartile_band->female_share_pct) == NULL) {
    goto fail; //Numeric
    }


    // quartile_band->hourly_median
    if (!quartile_band->hourly_median) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "hourly_median", quartile_band->hourly_median) == NULL) {
    goto fail; //String
    }


    // quartile_band->male_share_pct
    if (!quartile_band->male_share_pct) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "male_share_pct", *quartile_band->male_share_pct) == NULL) {
    goto fail; //Numeric
    }


    // quartile_band->quartile
    if (!quartile_band->quartile) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "quartile", quartile_band->quartile) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

quartile_band_t *quartile_band_parseFromJSON(cJSON *quartile_bandJSON){

    quartile_band_t *quartile_band_local_var = NULL;

    // define the local variable for quartile_band->female_share_pct
    double *female_share_pct_local_var = NULL;

    char *hourly_median_local_str = NULL;

    // define the local variable for quartile_band->male_share_pct
    double *male_share_pct_local_var = NULL;

    char *quartile_local_str = NULL;

    // quartile_band->female_share_pct
    cJSON *female_share_pct = cJSON_GetObjectItemCaseSensitive(quartile_bandJSON, "female_share_pct");
    if (cJSON_IsNull(female_share_pct)) {
        female_share_pct = NULL;
    }
    if (!female_share_pct) {
        goto end;
    }

    
    if(!cJSON_IsNumber(female_share_pct))
    {
    goto end; //Numeric
    }
    female_share_pct_local_var = malloc(sizeof(double));
    if(!female_share_pct_local_var)
    {
        goto end;
    }
    *female_share_pct_local_var = female_share_pct->valuedouble;

    // quartile_band->hourly_median
    cJSON *hourly_median = cJSON_GetObjectItemCaseSensitive(quartile_bandJSON, "hourly_median");
    if (cJSON_IsNull(hourly_median)) {
        hourly_median = NULL;
    }
    if (!hourly_median) {
        goto end;
    }

    
    if(!cJSON_IsString(hourly_median))
    {
    goto end; //String
    }

    // quartile_band->male_share_pct
    cJSON *male_share_pct = cJSON_GetObjectItemCaseSensitive(quartile_bandJSON, "male_share_pct");
    if (cJSON_IsNull(male_share_pct)) {
        male_share_pct = NULL;
    }
    if (!male_share_pct) {
        goto end;
    }

    
    if(!cJSON_IsNumber(male_share_pct))
    {
    goto end; //Numeric
    }
    male_share_pct_local_var = malloc(sizeof(double));
    if(!male_share_pct_local_var)
    {
        goto end;
    }
    *male_share_pct_local_var = male_share_pct->valuedouble;

    // quartile_band->quartile
    cJSON *quartile = cJSON_GetObjectItemCaseSensitive(quartile_bandJSON, "quartile");
    if (cJSON_IsNull(quartile)) {
        quartile = NULL;
    }
    if (!quartile) {
        goto end;
    }

    
    if(!cJSON_IsString(quartile))
    {
    goto end; //String
    }


    if (hourly_median && !cJSON_IsNull(hourly_median)) hourly_median_local_str = strdup(hourly_median->valuestring);
    if (quartile && !cJSON_IsNull(quartile)) quartile_local_str = strdup(quartile->valuestring);

    quartile_band_local_var = quartile_band_create_internal (
        female_share_pct_local_var,
        hourly_median_local_str,
        male_share_pct_local_var,
        quartile_local_str
        );

    if (!quartile_band_local_var) {
        goto end;
    }

    return quartile_band_local_var;
end:
    if (female_share_pct_local_var) {
        free(female_share_pct_local_var);
        female_share_pct_local_var = NULL;
    }
    if (hourly_median_local_str) {
        free(hourly_median_local_str);
        hourly_median_local_str = NULL;
    }
    if (male_share_pct_local_var) {
        free(male_share_pct_local_var);
        male_share_pct_local_var = NULL;
    }
    if (quartile_local_str) {
        free(quartile_local_str);
        quartile_local_str = NULL;
    }
    return NULL;

}
