#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "konzern_thresholds.h"



static konzern_thresholds_t *konzern_thresholds_create_internal(
    char *bilanzsumme,
    long *mitarbeiter,
    char *netto_umsatz
    ) {
    konzern_thresholds_t *konzern_thresholds_local_var = malloc(sizeof(konzern_thresholds_t));
    if (!konzern_thresholds_local_var) {
        return NULL;
    }
    memset(konzern_thresholds_local_var, 0, sizeof(konzern_thresholds_t));
    konzern_thresholds_local_var->_library_owned = 1;
    konzern_thresholds_local_var->bilanzsumme = bilanzsumme;
    konzern_thresholds_local_var->mitarbeiter = mitarbeiter;
    konzern_thresholds_local_var->netto_umsatz = netto_umsatz;
    return konzern_thresholds_local_var;
}

__attribute__((deprecated)) konzern_thresholds_t *konzern_thresholds_create(
    char *bilanzsumme,
    long *mitarbeiter,
    char *netto_umsatz
    ) {
    long *mitarbeiter_copy = NULL;
    if (mitarbeiter) {
        mitarbeiter_copy = malloc(sizeof(long));
        if (mitarbeiter_copy) *mitarbeiter_copy = *mitarbeiter;
    }
    konzern_thresholds_t *result = konzern_thresholds_create_internal (
        bilanzsumme,
        mitarbeiter_copy,
        netto_umsatz
        );
    if (!result) {
        free(mitarbeiter_copy);
    }
    return result;
}

void konzern_thresholds_free(konzern_thresholds_t *konzern_thresholds) {
    if(NULL == konzern_thresholds){
        return ;
    }
    if(konzern_thresholds->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "konzern_thresholds_free");
        return ;
    }
    listEntry_t *listEntry;
    if (konzern_thresholds->bilanzsumme) {
        free(konzern_thresholds->bilanzsumme);
        konzern_thresholds->bilanzsumme = NULL;
    }
    if (konzern_thresholds->mitarbeiter) {
        free(konzern_thresholds->mitarbeiter);
        konzern_thresholds->mitarbeiter = NULL;
    }
    if (konzern_thresholds->netto_umsatz) {
        free(konzern_thresholds->netto_umsatz);
        konzern_thresholds->netto_umsatz = NULL;
    }
    free(konzern_thresholds);
}

cJSON *konzern_thresholds_convertToJSON(konzern_thresholds_t *konzern_thresholds) {
    cJSON *item = cJSON_CreateObject();

    // konzern_thresholds->bilanzsumme
    if (!konzern_thresholds->bilanzsumme) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "bilanzsumme", konzern_thresholds->bilanzsumme) == NULL) {
    goto fail; //String
    }


    // konzern_thresholds->mitarbeiter
    if (!konzern_thresholds->mitarbeiter) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "mitarbeiter", *konzern_thresholds->mitarbeiter) == NULL) {
    goto fail; //Numeric
    }


    // konzern_thresholds->netto_umsatz
    if (!konzern_thresholds->netto_umsatz) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "netto_umsatz", konzern_thresholds->netto_umsatz) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

konzern_thresholds_t *konzern_thresholds_parseFromJSON(cJSON *konzern_thresholdsJSON){

    konzern_thresholds_t *konzern_thresholds_local_var = NULL;

    char *bilanzsumme_local_str = NULL;

    // define the local variable for konzern_thresholds->mitarbeiter
    long *mitarbeiter_local_var = NULL;

    char *netto_umsatz_local_str = NULL;

    // konzern_thresholds->bilanzsumme
    cJSON *bilanzsumme = cJSON_GetObjectItemCaseSensitive(konzern_thresholdsJSON, "bilanzsumme");
    if (cJSON_IsNull(bilanzsumme)) {
        bilanzsumme = NULL;
    }
    if (!bilanzsumme) {
        goto end;
    }

    
    if(!cJSON_IsString(bilanzsumme))
    {
    goto end; //String
    }

    // konzern_thresholds->mitarbeiter
    cJSON *mitarbeiter = cJSON_GetObjectItemCaseSensitive(konzern_thresholdsJSON, "mitarbeiter");
    if (cJSON_IsNull(mitarbeiter)) {
        mitarbeiter = NULL;
    }
    if (!mitarbeiter) {
        goto end;
    }

    
    if(!cJSON_IsNumber(mitarbeiter))
    {
    goto end; //Numeric
    }
    mitarbeiter_local_var = malloc(sizeof(long));
    if(!mitarbeiter_local_var)
    {
        goto end;
    }
    *mitarbeiter_local_var = mitarbeiter->valuedouble;

    // konzern_thresholds->netto_umsatz
    cJSON *netto_umsatz = cJSON_GetObjectItemCaseSensitive(konzern_thresholdsJSON, "netto_umsatz");
    if (cJSON_IsNull(netto_umsatz)) {
        netto_umsatz = NULL;
    }
    if (!netto_umsatz) {
        goto end;
    }

    
    if(!cJSON_IsString(netto_umsatz))
    {
    goto end; //String
    }


    if (bilanzsumme && !cJSON_IsNull(bilanzsumme)) bilanzsumme_local_str = strdup(bilanzsumme->valuestring);
    if (netto_umsatz && !cJSON_IsNull(netto_umsatz)) netto_umsatz_local_str = strdup(netto_umsatz->valuestring);

    konzern_thresholds_local_var = konzern_thresholds_create_internal (
        bilanzsumme_local_str,
        mitarbeiter_local_var,
        netto_umsatz_local_str
        );

    if (!konzern_thresholds_local_var) {
        goto end;
    }

    return konzern_thresholds_local_var;
end:
    if (bilanzsumme_local_str) {
        free(bilanzsumme_local_str);
        bilanzsumme_local_str = NULL;
    }
    if (mitarbeiter_local_var) {
        free(mitarbeiter_local_var);
        mitarbeiter_local_var = NULL;
    }
    if (netto_umsatz_local_str) {
        free(netto_umsatz_local_str);
        netto_umsatz_local_str = NULL;
    }
    return NULL;

}
