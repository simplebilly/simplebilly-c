#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "category_total.h"



static category_total_t *category_total_create_internal(
    char *category_id,
    double *share_pct,
    char *tco2e
    ) {
    category_total_t *category_total_local_var = malloc(sizeof(category_total_t));
    if (!category_total_local_var) {
        return NULL;
    }
    memset(category_total_local_var, 0, sizeof(category_total_t));
    category_total_local_var->_library_owned = 1;
    category_total_local_var->category_id = category_id;
    category_total_local_var->share_pct = share_pct;
    category_total_local_var->tco2e = tco2e;
    return category_total_local_var;
}

__attribute__((deprecated)) category_total_t *category_total_create(
    char *category_id,
    double *share_pct,
    char *tco2e
    ) {
    double *share_pct_copy = NULL;
    if (share_pct) {
        share_pct_copy = malloc(sizeof(double));
        if (share_pct_copy) *share_pct_copy = *share_pct;
    }
    category_total_t *result = category_total_create_internal (
        category_id,
        share_pct_copy,
        tco2e
        );
    if (!result) {
        free(share_pct_copy);
    }
    return result;
}

void category_total_free(category_total_t *category_total) {
    if(NULL == category_total){
        return ;
    }
    if(category_total->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "category_total_free");
        return ;
    }
    listEntry_t *listEntry;
    if (category_total->category_id) {
        free(category_total->category_id);
        category_total->category_id = NULL;
    }
    if (category_total->share_pct) {
        free(category_total->share_pct);
        category_total->share_pct = NULL;
    }
    if (category_total->tco2e) {
        free(category_total->tco2e);
        category_total->tco2e = NULL;
    }
    free(category_total);
}

cJSON *category_total_convertToJSON(category_total_t *category_total) {
    cJSON *item = cJSON_CreateObject();

    // category_total->category_id
    if (!category_total->category_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "category_id", category_total->category_id) == NULL) {
    goto fail; //String
    }


    // category_total->share_pct
    if (!category_total->share_pct) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "share_pct", *category_total->share_pct) == NULL) {
    goto fail; //Numeric
    }


    // category_total->tco2e
    if (!category_total->tco2e) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tco2e", category_total->tco2e) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

category_total_t *category_total_parseFromJSON(cJSON *category_totalJSON){

    category_total_t *category_total_local_var = NULL;

    char *category_id_local_str = NULL;

    // define the local variable for category_total->share_pct
    double *share_pct_local_var = NULL;

    char *tco2e_local_str = NULL;

    // category_total->category_id
    cJSON *category_id = cJSON_GetObjectItemCaseSensitive(category_totalJSON, "category_id");
    if (cJSON_IsNull(category_id)) {
        category_id = NULL;
    }
    if (!category_id) {
        goto end;
    }

    
    if(!cJSON_IsString(category_id))
    {
    goto end; //String
    }

    // category_total->share_pct
    cJSON *share_pct = cJSON_GetObjectItemCaseSensitive(category_totalJSON, "share_pct");
    if (cJSON_IsNull(share_pct)) {
        share_pct = NULL;
    }
    if (!share_pct) {
        goto end;
    }

    
    if(!cJSON_IsNumber(share_pct))
    {
    goto end; //Numeric
    }
    share_pct_local_var = malloc(sizeof(double));
    if(!share_pct_local_var)
    {
        goto end;
    }
    *share_pct_local_var = share_pct->valuedouble;

    // category_total->tco2e
    cJSON *tco2e = cJSON_GetObjectItemCaseSensitive(category_totalJSON, "tco2e");
    if (cJSON_IsNull(tco2e)) {
        tco2e = NULL;
    }
    if (!tco2e) {
        goto end;
    }

    
    if(!cJSON_IsString(tco2e))
    {
    goto end; //String
    }


    if (category_id && !cJSON_IsNull(category_id)) category_id_local_str = strdup(category_id->valuestring);
    if (tco2e && !cJSON_IsNull(tco2e)) tco2e_local_str = strdup(tco2e->valuestring);

    category_total_local_var = category_total_create_internal (
        category_id_local_str,
        share_pct_local_var,
        tco2e_local_str
        );

    if (!category_total_local_var) {
        goto end;
    }

    return category_total_local_var;
end:
    if (category_id_local_str) {
        free(category_id_local_str);
        category_id_local_str = NULL;
    }
    if (share_pct_local_var) {
        free(share_pct_local_var);
        share_pct_local_var = NULL;
    }
    if (tco2e_local_str) {
        free(tco2e_local_str);
        tco2e_local_str = NULL;
    }
    return NULL;

}
