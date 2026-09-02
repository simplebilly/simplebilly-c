#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "betriebsstaetten_detail.h"



static betriebsstaetten_detail_t *betriebsstaetten_detail_create_internal(
    long *beschaefigte,
    char *monatlicher_beitrag,
    char *name
    ) {
    betriebsstaetten_detail_t *betriebsstaetten_detail_local_var = malloc(sizeof(betriebsstaetten_detail_t));
    if (!betriebsstaetten_detail_local_var) {
        return NULL;
    }
    memset(betriebsstaetten_detail_local_var, 0, sizeof(betriebsstaetten_detail_t));
    betriebsstaetten_detail_local_var->_library_owned = 1;
    betriebsstaetten_detail_local_var->beschaefigte = beschaefigte;
    betriebsstaetten_detail_local_var->monatlicher_beitrag = monatlicher_beitrag;
    betriebsstaetten_detail_local_var->name = name;
    return betriebsstaetten_detail_local_var;
}

__attribute__((deprecated)) betriebsstaetten_detail_t *betriebsstaetten_detail_create(
    long *beschaefigte,
    char *monatlicher_beitrag,
    char *name
    ) {
    long *beschaefigte_copy = NULL;
    if (beschaefigte) {
        beschaefigte_copy = malloc(sizeof(long));
        if (beschaefigte_copy) *beschaefigte_copy = *beschaefigte;
    }
    betriebsstaetten_detail_t *result = betriebsstaetten_detail_create_internal (
        beschaefigte_copy,
        monatlicher_beitrag,
        name
        );
    if (!result) {
        free(beschaefigte_copy);
    }
    return result;
}

void betriebsstaetten_detail_free(betriebsstaetten_detail_t *betriebsstaetten_detail) {
    if(NULL == betriebsstaetten_detail){
        return ;
    }
    if(betriebsstaetten_detail->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "betriebsstaetten_detail_free");
        return ;
    }
    listEntry_t *listEntry;
    if (betriebsstaetten_detail->beschaefigte) {
        free(betriebsstaetten_detail->beschaefigte);
        betriebsstaetten_detail->beschaefigte = NULL;
    }
    if (betriebsstaetten_detail->monatlicher_beitrag) {
        free(betriebsstaetten_detail->monatlicher_beitrag);
        betriebsstaetten_detail->monatlicher_beitrag = NULL;
    }
    if (betriebsstaetten_detail->name) {
        free(betriebsstaetten_detail->name);
        betriebsstaetten_detail->name = NULL;
    }
    free(betriebsstaetten_detail);
}

cJSON *betriebsstaetten_detail_convertToJSON(betriebsstaetten_detail_t *betriebsstaetten_detail) {
    cJSON *item = cJSON_CreateObject();

    // betriebsstaetten_detail->beschaefigte
    if (!betriebsstaetten_detail->beschaefigte) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "beschaefigte", *betriebsstaetten_detail->beschaefigte) == NULL) {
    goto fail; //Numeric
    }


    // betriebsstaetten_detail->monatlicher_beitrag
    if (!betriebsstaetten_detail->monatlicher_beitrag) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "monatlicher_beitrag", betriebsstaetten_detail->monatlicher_beitrag) == NULL) {
    goto fail; //String
    }


    // betriebsstaetten_detail->name
    if (!betriebsstaetten_detail->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", betriebsstaetten_detail->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

betriebsstaetten_detail_t *betriebsstaetten_detail_parseFromJSON(cJSON *betriebsstaetten_detailJSON){

    betriebsstaetten_detail_t *betriebsstaetten_detail_local_var = NULL;

    // define the local variable for betriebsstaetten_detail->beschaefigte
    long *beschaefigte_local_var = NULL;

    char *monatlicher_beitrag_local_str = NULL;

    char *name_local_str = NULL;

    // betriebsstaetten_detail->beschaefigte
    cJSON *beschaefigte = cJSON_GetObjectItemCaseSensitive(betriebsstaetten_detailJSON, "beschaefigte");
    if (cJSON_IsNull(beschaefigte)) {
        beschaefigte = NULL;
    }
    if (!beschaefigte) {
        goto end;
    }

    
    if(!cJSON_IsNumber(beschaefigte))
    {
    goto end; //Numeric
    }
    beschaefigte_local_var = malloc(sizeof(long));
    if(!beschaefigte_local_var)
    {
        goto end;
    }
    *beschaefigte_local_var = beschaefigte->valuedouble;

    // betriebsstaetten_detail->monatlicher_beitrag
    cJSON *monatlicher_beitrag = cJSON_GetObjectItemCaseSensitive(betriebsstaetten_detailJSON, "monatlicher_beitrag");
    if (cJSON_IsNull(monatlicher_beitrag)) {
        monatlicher_beitrag = NULL;
    }
    if (!monatlicher_beitrag) {
        goto end;
    }

    
    if(!cJSON_IsString(monatlicher_beitrag))
    {
    goto end; //String
    }

    // betriebsstaetten_detail->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(betriebsstaetten_detailJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    if (monatlicher_beitrag && !cJSON_IsNull(monatlicher_beitrag)) monatlicher_beitrag_local_str = strdup(monatlicher_beitrag->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    betriebsstaetten_detail_local_var = betriebsstaetten_detail_create_internal (
        beschaefigte_local_var,
        monatlicher_beitrag_local_str,
        name_local_str
        );

    if (!betriebsstaetten_detail_local_var) {
        goto end;
    }

    return betriebsstaetten_detail_local_var;
end:
    if (beschaefigte_local_var) {
        free(beschaefigte_local_var);
        beschaefigte_local_var = NULL;
    }
    if (monatlicher_beitrag_local_str) {
        free(monatlicher_beitrag_local_str);
        monatlicher_beitrag_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    return NULL;

}
