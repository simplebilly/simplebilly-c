#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tax_rate_create.h"



static tax_rate_create_t *tax_rate_create_create_internal(
    char *country_code,
    char *effective_from,
    int *is_default,
    char *name,
    long *rate_percent
    ) {
    tax_rate_create_t *tax_rate_create_local_var = malloc(sizeof(tax_rate_create_t));
    if (!tax_rate_create_local_var) {
        return NULL;
    }
    memset(tax_rate_create_local_var, 0, sizeof(tax_rate_create_t));
    tax_rate_create_local_var->_library_owned = 1;
    tax_rate_create_local_var->country_code = country_code;
    tax_rate_create_local_var->effective_from = effective_from;
    tax_rate_create_local_var->is_default = is_default;
    tax_rate_create_local_var->name = name;
    tax_rate_create_local_var->rate_percent = rate_percent;
    return tax_rate_create_local_var;
}

__attribute__((deprecated)) tax_rate_create_t *tax_rate_create_create(
    char *country_code,
    char *effective_from,
    int *is_default,
    char *name,
    long *rate_percent
    ) {
    int *is_default_copy = NULL;
    if (is_default) {
        is_default_copy = malloc(sizeof(int));
        if (is_default_copy) *is_default_copy = *is_default;
    }
    long *rate_percent_copy = NULL;
    if (rate_percent) {
        rate_percent_copy = malloc(sizeof(long));
        if (rate_percent_copy) *rate_percent_copy = *rate_percent;
    }
    tax_rate_create_t *result = tax_rate_create_create_internal (
        country_code,
        effective_from,
        is_default_copy,
        name,
        rate_percent_copy
        );
    if (!result) {
        free(is_default_copy);
        free(rate_percent_copy);
    }
    return result;
}

void tax_rate_create_free(tax_rate_create_t *tax_rate_create) {
    if(NULL == tax_rate_create){
        return ;
    }
    if(tax_rate_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "tax_rate_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (tax_rate_create->country_code) {
        free(tax_rate_create->country_code);
        tax_rate_create->country_code = NULL;
    }
    if (tax_rate_create->effective_from) {
        free(tax_rate_create->effective_from);
        tax_rate_create->effective_from = NULL;
    }
    if (tax_rate_create->is_default) {
        free(tax_rate_create->is_default);
        tax_rate_create->is_default = NULL;
    }
    if (tax_rate_create->name) {
        free(tax_rate_create->name);
        tax_rate_create->name = NULL;
    }
    if (tax_rate_create->rate_percent) {
        free(tax_rate_create->rate_percent);
        tax_rate_create->rate_percent = NULL;
    }
    free(tax_rate_create);
}

cJSON *tax_rate_create_convertToJSON(tax_rate_create_t *tax_rate_create) {
    cJSON *item = cJSON_CreateObject();

    // tax_rate_create->country_code
    if (!tax_rate_create->country_code) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "countryCode", tax_rate_create->country_code) == NULL) {
    goto fail; //String
    }


    // tax_rate_create->effective_from
    if(tax_rate_create->effective_from) {
    if(cJSON_AddStringToObject(item, "effectiveFrom", tax_rate_create->effective_from) == NULL) {
    goto fail; //Date
    }
    }


    // tax_rate_create->is_default
    if (!tax_rate_create->is_default) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "isDefault", *tax_rate_create->is_default) == NULL) {
    goto fail; //Bool
    }


    // tax_rate_create->name
    if (!tax_rate_create->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", tax_rate_create->name) == NULL) {
    goto fail; //String
    }


    // tax_rate_create->rate_percent
    if (!tax_rate_create->rate_percent) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "ratePercent", *tax_rate_create->rate_percent) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

tax_rate_create_t *tax_rate_create_parseFromJSON(cJSON *tax_rate_createJSON){

    tax_rate_create_t *tax_rate_create_local_var = NULL;

    char *country_code_local_str = NULL;

    char *effective_from_local_str = NULL;

    // define the local variable for tax_rate_create->is_default
    int *is_default_local_var = NULL;

    char *name_local_str = NULL;

    // define the local variable for tax_rate_create->rate_percent
    long *rate_percent_local_var = NULL;

    // tax_rate_create->country_code
    cJSON *country_code = cJSON_GetObjectItemCaseSensitive(tax_rate_createJSON, "countryCode");
    if (cJSON_IsNull(country_code)) {
        country_code = NULL;
    }
    if (!country_code) {
        goto end;
    }

    
    if(!cJSON_IsString(country_code))
    {
    goto end; //String
    }

    // tax_rate_create->effective_from
    cJSON *effective_from = cJSON_GetObjectItemCaseSensitive(tax_rate_createJSON, "effectiveFrom");
    if (cJSON_IsNull(effective_from)) {
        effective_from = NULL;
    }
    if (effective_from) { 
    if(!cJSON_IsString(effective_from))
    {
    goto end; //Date
    }
    }

    // tax_rate_create->is_default
    cJSON *is_default = cJSON_GetObjectItemCaseSensitive(tax_rate_createJSON, "isDefault");
    if (cJSON_IsNull(is_default)) {
        is_default = NULL;
    }
    if (!is_default) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_default))
    {
    goto end; //Bool
    }
    is_default_local_var = malloc(sizeof(int));
    if(!is_default_local_var)
    {
        goto end;
    }
    *is_default_local_var = is_default->valueint;

    // tax_rate_create->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(tax_rate_createJSON, "name");
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

    // tax_rate_create->rate_percent
    cJSON *rate_percent = cJSON_GetObjectItemCaseSensitive(tax_rate_createJSON, "ratePercent");
    if (cJSON_IsNull(rate_percent)) {
        rate_percent = NULL;
    }
    if (!rate_percent) {
        goto end;
    }

    
    if(!cJSON_IsNumber(rate_percent))
    {
    goto end; //Numeric
    }
    rate_percent_local_var = malloc(sizeof(long));
    if(!rate_percent_local_var)
    {
        goto end;
    }
    *rate_percent_local_var = rate_percent->valuedouble;


    if (country_code && !cJSON_IsNull(country_code)) country_code_local_str = strdup(country_code->valuestring);
    if (effective_from) effective_from_local_str = strdup(effective_from->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    tax_rate_create_local_var = tax_rate_create_create_internal (
        country_code_local_str,
        effective_from_local_str,
        is_default_local_var,
        name_local_str,
        rate_percent_local_var
        );

    if (!tax_rate_create_local_var) {
        goto end;
    }

    return tax_rate_create_local_var;
end:
    if (country_code_local_str) {
        free(country_code_local_str);
        country_code_local_str = NULL;
    }
    if (effective_from_local_str) {
        free(effective_from_local_str);
        effective_from_local_str = NULL;
    }
    if (is_default_local_var) {
        free(is_default_local_var);
        is_default_local_var = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (rate_percent_local_var) {
        free(rate_percent_local_var);
        rate_percent_local_var = NULL;
    }
    return NULL;

}
