#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "metered_usage.h"



static metered_usage_t *metered_usage_create_internal(
    long *limit,
    char *meter,
    long *used
    ) {
    metered_usage_t *metered_usage_local_var = malloc(sizeof(metered_usage_t));
    if (!metered_usage_local_var) {
        return NULL;
    }
    memset(metered_usage_local_var, 0, sizeof(metered_usage_t));
    metered_usage_local_var->_library_owned = 1;
    metered_usage_local_var->limit = limit;
    metered_usage_local_var->meter = meter;
    metered_usage_local_var->used = used;
    return metered_usage_local_var;
}

__attribute__((deprecated)) metered_usage_t *metered_usage_create(
    long *limit,
    char *meter,
    long *used
    ) {
    long *limit_copy = NULL;
    if (limit) {
        limit_copy = malloc(sizeof(long));
        if (limit_copy) *limit_copy = *limit;
    }
    long *used_copy = NULL;
    if (used) {
        used_copy = malloc(sizeof(long));
        if (used_copy) *used_copy = *used;
    }
    metered_usage_t *result = metered_usage_create_internal (
        limit_copy,
        meter,
        used_copy
        );
    if (!result) {
        free(limit_copy);
        free(used_copy);
    }
    return result;
}

void metered_usage_free(metered_usage_t *metered_usage) {
    if(NULL == metered_usage){
        return ;
    }
    if(metered_usage->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "metered_usage_free");
        return ;
    }
    listEntry_t *listEntry;
    if (metered_usage->limit) {
        free(metered_usage->limit);
        metered_usage->limit = NULL;
    }
    if (metered_usage->meter) {
        free(metered_usage->meter);
        metered_usage->meter = NULL;
    }
    if (metered_usage->used) {
        free(metered_usage->used);
        metered_usage->used = NULL;
    }
    free(metered_usage);
}

cJSON *metered_usage_convertToJSON(metered_usage_t *metered_usage) {
    cJSON *item = cJSON_CreateObject();

    // metered_usage->limit
    if (!metered_usage->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", *metered_usage->limit) == NULL) {
    goto fail; //Numeric
    }


    // metered_usage->meter
    if (!metered_usage->meter) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "meter", metered_usage->meter) == NULL) {
    goto fail; //String
    }


    // metered_usage->used
    if (!metered_usage->used) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "used", *metered_usage->used) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

metered_usage_t *metered_usage_parseFromJSON(cJSON *metered_usageJSON){

    metered_usage_t *metered_usage_local_var = NULL;

    // define the local variable for metered_usage->limit
    long *limit_local_var = NULL;

    char *meter_local_str = NULL;

    // define the local variable for metered_usage->used
    long *used_local_var = NULL;

    // metered_usage->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(metered_usageJSON, "limit");
    if (cJSON_IsNull(limit)) {
        limit = NULL;
    }
    if (!limit) {
        goto end;
    }

    
    if(!cJSON_IsNumber(limit))
    {
    goto end; //Numeric
    }
    limit_local_var = malloc(sizeof(long));
    if(!limit_local_var)
    {
        goto end;
    }
    *limit_local_var = limit->valuedouble;

    // metered_usage->meter
    cJSON *meter = cJSON_GetObjectItemCaseSensitive(metered_usageJSON, "meter");
    if (cJSON_IsNull(meter)) {
        meter = NULL;
    }
    if (!meter) {
        goto end;
    }

    
    if(!cJSON_IsString(meter))
    {
    goto end; //String
    }

    // metered_usage->used
    cJSON *used = cJSON_GetObjectItemCaseSensitive(metered_usageJSON, "used");
    if (cJSON_IsNull(used)) {
        used = NULL;
    }
    if (!used) {
        goto end;
    }

    
    if(!cJSON_IsNumber(used))
    {
    goto end; //Numeric
    }
    used_local_var = malloc(sizeof(long));
    if(!used_local_var)
    {
        goto end;
    }
    *used_local_var = used->valuedouble;


    if (meter && !cJSON_IsNull(meter)) meter_local_str = strdup(meter->valuestring);

    metered_usage_local_var = metered_usage_create_internal (
        limit_local_var,
        meter_local_str,
        used_local_var
        );

    if (!metered_usage_local_var) {
        goto end;
    }

    return metered_usage_local_var;
end:
    if (limit_local_var) {
        free(limit_local_var);
        limit_local_var = NULL;
    }
    if (meter_local_str) {
        free(meter_local_str);
        meter_local_str = NULL;
    }
    if (used_local_var) {
        free(used_local_var);
        used_local_var = NULL;
    }
    return NULL;

}
