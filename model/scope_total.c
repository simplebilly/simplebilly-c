#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "scope_total.h"



static scope_total_t *scope_total_create_internal(
    char *scope,
    char *tco2e
    ) {
    scope_total_t *scope_total_local_var = malloc(sizeof(scope_total_t));
    if (!scope_total_local_var) {
        return NULL;
    }
    memset(scope_total_local_var, 0, sizeof(scope_total_t));
    scope_total_local_var->_library_owned = 1;
    scope_total_local_var->scope = scope;
    scope_total_local_var->tco2e = tco2e;
    return scope_total_local_var;
}

__attribute__((deprecated)) scope_total_t *scope_total_create(
    char *scope,
    char *tco2e
    ) {
    scope_total_t *result = scope_total_create_internal (
        scope,
        tco2e
        );
    if (!result) {
    }
    return result;
}

void scope_total_free(scope_total_t *scope_total) {
    if(NULL == scope_total){
        return ;
    }
    if(scope_total->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "scope_total_free");
        return ;
    }
    listEntry_t *listEntry;
    if (scope_total->scope) {
        free(scope_total->scope);
        scope_total->scope = NULL;
    }
    if (scope_total->tco2e) {
        free(scope_total->tco2e);
        scope_total->tco2e = NULL;
    }
    free(scope_total);
}

cJSON *scope_total_convertToJSON(scope_total_t *scope_total) {
    cJSON *item = cJSON_CreateObject();

    // scope_total->scope
    if (!scope_total->scope) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "scope", scope_total->scope) == NULL) {
    goto fail; //String
    }


    // scope_total->tco2e
    if (!scope_total->tco2e) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tco2e", scope_total->tco2e) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

scope_total_t *scope_total_parseFromJSON(cJSON *scope_totalJSON){

    scope_total_t *scope_total_local_var = NULL;

    char *scope_local_str = NULL;

    char *tco2e_local_str = NULL;

    // scope_total->scope
    cJSON *scope = cJSON_GetObjectItemCaseSensitive(scope_totalJSON, "scope");
    if (cJSON_IsNull(scope)) {
        scope = NULL;
    }
    if (!scope) {
        goto end;
    }

    
    if(!cJSON_IsString(scope))
    {
    goto end; //String
    }

    // scope_total->tco2e
    cJSON *tco2e = cJSON_GetObjectItemCaseSensitive(scope_totalJSON, "tco2e");
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


    if (scope && !cJSON_IsNull(scope)) scope_local_str = strdup(scope->valuestring);
    if (tco2e && !cJSON_IsNull(tco2e)) tco2e_local_str = strdup(tco2e->valuestring);

    scope_total_local_var = scope_total_create_internal (
        scope_local_str,
        tco2e_local_str
        );

    if (!scope_total_local_var) {
        goto end;
    }

    return scope_total_local_var;
end:
    if (scope_local_str) {
        free(scope_local_str);
        scope_local_str = NULL;
    }
    if (tco2e_local_str) {
        free(tco2e_local_str);
        tco2e_local_str = NULL;
    }
    return NULL;

}
