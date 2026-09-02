#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "year_total.h"



static year_total_t *year_total_create_internal(
    char *tco2e,
    int *year
    ) {
    year_total_t *year_total_local_var = malloc(sizeof(year_total_t));
    if (!year_total_local_var) {
        return NULL;
    }
    memset(year_total_local_var, 0, sizeof(year_total_t));
    year_total_local_var->_library_owned = 1;
    year_total_local_var->tco2e = tco2e;
    year_total_local_var->year = year;
    return year_total_local_var;
}

__attribute__((deprecated)) year_total_t *year_total_create(
    char *tco2e,
    int *year
    ) {
    int *year_copy = NULL;
    if (year) {
        year_copy = malloc(sizeof(int));
        if (year_copy) *year_copy = *year;
    }
    year_total_t *result = year_total_create_internal (
        tco2e,
        year_copy
        );
    if (!result) {
        free(year_copy);
    }
    return result;
}

void year_total_free(year_total_t *year_total) {
    if(NULL == year_total){
        return ;
    }
    if(year_total->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "year_total_free");
        return ;
    }
    listEntry_t *listEntry;
    if (year_total->tco2e) {
        free(year_total->tco2e);
        year_total->tco2e = NULL;
    }
    if (year_total->year) {
        free(year_total->year);
        year_total->year = NULL;
    }
    free(year_total);
}

cJSON *year_total_convertToJSON(year_total_t *year_total) {
    cJSON *item = cJSON_CreateObject();

    // year_total->tco2e
    if (!year_total->tco2e) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tco2e", year_total->tco2e) == NULL) {
    goto fail; //String
    }


    // year_total->year
    if (!year_total->year) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "year", *year_total->year) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

year_total_t *year_total_parseFromJSON(cJSON *year_totalJSON){

    year_total_t *year_total_local_var = NULL;

    char *tco2e_local_str = NULL;

    // define the local variable for year_total->year
    int *year_local_var = NULL;

    // year_total->tco2e
    cJSON *tco2e = cJSON_GetObjectItemCaseSensitive(year_totalJSON, "tco2e");
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

    // year_total->year
    cJSON *year = cJSON_GetObjectItemCaseSensitive(year_totalJSON, "year");
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


    if (tco2e && !cJSON_IsNull(tco2e)) tco2e_local_str = strdup(tco2e->valuestring);

    year_total_local_var = year_total_create_internal (
        tco2e_local_str,
        year_local_var
        );

    if (!year_total_local_var) {
        goto end;
    }

    return year_total_local_var;
end:
    if (tco2e_local_str) {
        free(tco2e_local_str);
        tco2e_local_str = NULL;
    }
    if (year_local_var) {
        free(year_local_var);
        year_local_var = NULL;
    }
    return NULL;

}
