#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "institute_deadlines.h"



static institute_deadlines_t *institute_deadlines_create_internal(
    int *abschlusspruefung_months,
    int *jahresabschluss_bafin_months,
    int *offenlegung_months
    ) {
    institute_deadlines_t *institute_deadlines_local_var = malloc(sizeof(institute_deadlines_t));
    if (!institute_deadlines_local_var) {
        return NULL;
    }
    memset(institute_deadlines_local_var, 0, sizeof(institute_deadlines_t));
    institute_deadlines_local_var->_library_owned = 1;
    institute_deadlines_local_var->abschlusspruefung_months = abschlusspruefung_months;
    institute_deadlines_local_var->jahresabschluss_bafin_months = jahresabschluss_bafin_months;
    institute_deadlines_local_var->offenlegung_months = offenlegung_months;
    return institute_deadlines_local_var;
}

__attribute__((deprecated)) institute_deadlines_t *institute_deadlines_create(
    int *abschlusspruefung_months,
    int *jahresabschluss_bafin_months,
    int *offenlegung_months
    ) {
    int *abschlusspruefung_months_copy = NULL;
    if (abschlusspruefung_months) {
        abschlusspruefung_months_copy = malloc(sizeof(int));
        if (abschlusspruefung_months_copy) *abschlusspruefung_months_copy = *abschlusspruefung_months;
    }
    int *jahresabschluss_bafin_months_copy = NULL;
    if (jahresabschluss_bafin_months) {
        jahresabschluss_bafin_months_copy = malloc(sizeof(int));
        if (jahresabschluss_bafin_months_copy) *jahresabschluss_bafin_months_copy = *jahresabschluss_bafin_months;
    }
    int *offenlegung_months_copy = NULL;
    if (offenlegung_months) {
        offenlegung_months_copy = malloc(sizeof(int));
        if (offenlegung_months_copy) *offenlegung_months_copy = *offenlegung_months;
    }
    institute_deadlines_t *result = institute_deadlines_create_internal (
        abschlusspruefung_months_copy,
        jahresabschluss_bafin_months_copy,
        offenlegung_months_copy
        );
    if (!result) {
        free(abschlusspruefung_months_copy);
        free(jahresabschluss_bafin_months_copy);
        free(offenlegung_months_copy);
    }
    return result;
}

void institute_deadlines_free(institute_deadlines_t *institute_deadlines) {
    if(NULL == institute_deadlines){
        return ;
    }
    if(institute_deadlines->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "institute_deadlines_free");
        return ;
    }
    listEntry_t *listEntry;
    if (institute_deadlines->abschlusspruefung_months) {
        free(institute_deadlines->abschlusspruefung_months);
        institute_deadlines->abschlusspruefung_months = NULL;
    }
    if (institute_deadlines->jahresabschluss_bafin_months) {
        free(institute_deadlines->jahresabschluss_bafin_months);
        institute_deadlines->jahresabschluss_bafin_months = NULL;
    }
    if (institute_deadlines->offenlegung_months) {
        free(institute_deadlines->offenlegung_months);
        institute_deadlines->offenlegung_months = NULL;
    }
    free(institute_deadlines);
}

cJSON *institute_deadlines_convertToJSON(institute_deadlines_t *institute_deadlines) {
    cJSON *item = cJSON_CreateObject();

    // institute_deadlines->abschlusspruefung_months
    if(institute_deadlines->abschlusspruefung_months) {
    if(cJSON_AddNumberToObject(item, "abschlusspruefungMonths", *institute_deadlines->abschlusspruefung_months) == NULL) {
    goto fail; //Numeric
    }
    }


    // institute_deadlines->jahresabschluss_bafin_months
    if(institute_deadlines->jahresabschluss_bafin_months) {
    if(cJSON_AddNumberToObject(item, "jahresabschlussBafinMonths", *institute_deadlines->jahresabschluss_bafin_months) == NULL) {
    goto fail; //Numeric
    }
    }


    // institute_deadlines->offenlegung_months
    if (!institute_deadlines->offenlegung_months) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offenlegungMonths", *institute_deadlines->offenlegung_months) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

institute_deadlines_t *institute_deadlines_parseFromJSON(cJSON *institute_deadlinesJSON){

    institute_deadlines_t *institute_deadlines_local_var = NULL;

    // define the local variable for institute_deadlines->abschlusspruefung_months
    int *abschlusspruefung_months_local_var = NULL;

    // define the local variable for institute_deadlines->jahresabschluss_bafin_months
    int *jahresabschluss_bafin_months_local_var = NULL;

    // define the local variable for institute_deadlines->offenlegung_months
    int *offenlegung_months_local_var = NULL;

    // institute_deadlines->abschlusspruefung_months
    cJSON *abschlusspruefung_months = cJSON_GetObjectItemCaseSensitive(institute_deadlinesJSON, "abschlusspruefungMonths");
    if (cJSON_IsNull(abschlusspruefung_months)) {
        abschlusspruefung_months = NULL;
    }
    if (abschlusspruefung_months) { 
    if(!cJSON_IsNumber(abschlusspruefung_months))
    {
    goto end; //Numeric
    }
    abschlusspruefung_months_local_var = malloc(sizeof(int));
    if(!abschlusspruefung_months_local_var)
    {
        goto end;
    }
    *abschlusspruefung_months_local_var = abschlusspruefung_months->valuedouble;
    }

    // institute_deadlines->jahresabschluss_bafin_months
    cJSON *jahresabschluss_bafin_months = cJSON_GetObjectItemCaseSensitive(institute_deadlinesJSON, "jahresabschlussBafinMonths");
    if (cJSON_IsNull(jahresabschluss_bafin_months)) {
        jahresabschluss_bafin_months = NULL;
    }
    if (jahresabschluss_bafin_months) { 
    if(!cJSON_IsNumber(jahresabschluss_bafin_months))
    {
    goto end; //Numeric
    }
    jahresabschluss_bafin_months_local_var = malloc(sizeof(int));
    if(!jahresabschluss_bafin_months_local_var)
    {
        goto end;
    }
    *jahresabschluss_bafin_months_local_var = jahresabschluss_bafin_months->valuedouble;
    }

    // institute_deadlines->offenlegung_months
    cJSON *offenlegung_months = cJSON_GetObjectItemCaseSensitive(institute_deadlinesJSON, "offenlegungMonths");
    if (cJSON_IsNull(offenlegung_months)) {
        offenlegung_months = NULL;
    }
    if (!offenlegung_months) {
        goto end;
    }

    
    if(!cJSON_IsNumber(offenlegung_months))
    {
    goto end; //Numeric
    }
    offenlegung_months_local_var = malloc(sizeof(int));
    if(!offenlegung_months_local_var)
    {
        goto end;
    }
    *offenlegung_months_local_var = offenlegung_months->valuedouble;



    institute_deadlines_local_var = institute_deadlines_create_internal (
        abschlusspruefung_months_local_var,
        jahresabschluss_bafin_months_local_var,
        offenlegung_months_local_var
        );

    if (!institute_deadlines_local_var) {
        goto end;
    }

    return institute_deadlines_local_var;
end:
    if (abschlusspruefung_months_local_var) {
        free(abschlusspruefung_months_local_var);
        abschlusspruefung_months_local_var = NULL;
    }
    if (jahresabschluss_bafin_months_local_var) {
        free(jahresabschluss_bafin_months_local_var);
        jahresabschluss_bafin_months_local_var = NULL;
    }
    if (offenlegung_months_local_var) {
        free(offenlegung_months_local_var);
        offenlegung_months_local_var = NULL;
    }
    return NULL;

}
