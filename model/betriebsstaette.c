#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "betriebsstaette.h"



static betriebsstaette_t *betriebsstaette_create_internal(
    long *beschaefigte,
    char *name
    ) {
    betriebsstaette_t *betriebsstaette_local_var = malloc(sizeof(betriebsstaette_t));
    if (!betriebsstaette_local_var) {
        return NULL;
    }
    memset(betriebsstaette_local_var, 0, sizeof(betriebsstaette_t));
    betriebsstaette_local_var->_library_owned = 1;
    betriebsstaette_local_var->beschaefigte = beschaefigte;
    betriebsstaette_local_var->name = name;
    return betriebsstaette_local_var;
}

__attribute__((deprecated)) betriebsstaette_t *betriebsstaette_create(
    long *beschaefigte,
    char *name
    ) {
    long *beschaefigte_copy = NULL;
    if (beschaefigte) {
        beschaefigte_copy = malloc(sizeof(long));
        if (beschaefigte_copy) *beschaefigte_copy = *beschaefigte;
    }
    betriebsstaette_t *result = betriebsstaette_create_internal (
        beschaefigte_copy,
        name
        );
    if (!result) {
        free(beschaefigte_copy);
    }
    return result;
}

void betriebsstaette_free(betriebsstaette_t *betriebsstaette) {
    if(NULL == betriebsstaette){
        return ;
    }
    if(betriebsstaette->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "betriebsstaette_free");
        return ;
    }
    listEntry_t *listEntry;
    if (betriebsstaette->beschaefigte) {
        free(betriebsstaette->beschaefigte);
        betriebsstaette->beschaefigte = NULL;
    }
    if (betriebsstaette->name) {
        free(betriebsstaette->name);
        betriebsstaette->name = NULL;
    }
    free(betriebsstaette);
}

cJSON *betriebsstaette_convertToJSON(betriebsstaette_t *betriebsstaette) {
    cJSON *item = cJSON_CreateObject();

    // betriebsstaette->beschaefigte
    if (!betriebsstaette->beschaefigte) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "beschaefigte", *betriebsstaette->beschaefigte) == NULL) {
    goto fail; //Numeric
    }


    // betriebsstaette->name
    if (!betriebsstaette->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", betriebsstaette->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

betriebsstaette_t *betriebsstaette_parseFromJSON(cJSON *betriebsstaetteJSON){

    betriebsstaette_t *betriebsstaette_local_var = NULL;

    // define the local variable for betriebsstaette->beschaefigte
    long *beschaefigte_local_var = NULL;

    char *name_local_str = NULL;

    // betriebsstaette->beschaefigte
    cJSON *beschaefigte = cJSON_GetObjectItemCaseSensitive(betriebsstaetteJSON, "beschaefigte");
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

    // betriebsstaette->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(betriebsstaetteJSON, "name");
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


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    betriebsstaette_local_var = betriebsstaette_create_internal (
        beschaefigte_local_var,
        name_local_str
        );

    if (!betriebsstaette_local_var) {
        goto end;
    }

    return betriebsstaette_local_var;
end:
    if (beschaefigte_local_var) {
        free(beschaefigte_local_var);
        beschaefigte_local_var = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    return NULL;

}
