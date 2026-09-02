#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "posting_category.h"



static posting_category_t *posting_category_create_internal(
    char *account_number,
    char *account_number_skr03,
    char *account_number_skr04,
    char *account_number_skr49,
    char *category_id,
    int *default_vat_rate,
    char *description,
    char *eks_category,
    int *is_active,
    int *is_system,
    char *name,
    char *skr_version,
    char *type
    ) {
    posting_category_t *posting_category_local_var = malloc(sizeof(posting_category_t));
    if (!posting_category_local_var) {
        return NULL;
    }
    memset(posting_category_local_var, 0, sizeof(posting_category_t));
    posting_category_local_var->_library_owned = 1;
    posting_category_local_var->account_number = account_number;
    posting_category_local_var->account_number_skr03 = account_number_skr03;
    posting_category_local_var->account_number_skr04 = account_number_skr04;
    posting_category_local_var->account_number_skr49 = account_number_skr49;
    posting_category_local_var->category_id = category_id;
    posting_category_local_var->default_vat_rate = default_vat_rate;
    posting_category_local_var->description = description;
    posting_category_local_var->eks_category = eks_category;
    posting_category_local_var->is_active = is_active;
    posting_category_local_var->is_system = is_system;
    posting_category_local_var->name = name;
    posting_category_local_var->skr_version = skr_version;
    posting_category_local_var->type = type;
    return posting_category_local_var;
}

__attribute__((deprecated)) posting_category_t *posting_category_create(
    char *account_number,
    char *account_number_skr03,
    char *account_number_skr04,
    char *account_number_skr49,
    char *category_id,
    int *default_vat_rate,
    char *description,
    char *eks_category,
    int *is_active,
    int *is_system,
    char *name,
    char *skr_version,
    char *type
    ) {
    int *default_vat_rate_copy = NULL;
    if (default_vat_rate) {
        default_vat_rate_copy = malloc(sizeof(int));
        if (default_vat_rate_copy) *default_vat_rate_copy = *default_vat_rate;
    }
    int *is_active_copy = NULL;
    if (is_active) {
        is_active_copy = malloc(sizeof(int));
        if (is_active_copy) *is_active_copy = *is_active;
    }
    int *is_system_copy = NULL;
    if (is_system) {
        is_system_copy = malloc(sizeof(int));
        if (is_system_copy) *is_system_copy = *is_system;
    }
    posting_category_t *result = posting_category_create_internal (
        account_number,
        account_number_skr03,
        account_number_skr04,
        account_number_skr49,
        category_id,
        default_vat_rate_copy,
        description,
        eks_category,
        is_active_copy,
        is_system_copy,
        name,
        skr_version,
        type
        );
    if (!result) {
        free(default_vat_rate_copy);
        free(is_active_copy);
        free(is_system_copy);
    }
    return result;
}

void posting_category_free(posting_category_t *posting_category) {
    if(NULL == posting_category){
        return ;
    }
    if(posting_category->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "posting_category_free");
        return ;
    }
    listEntry_t *listEntry;
    if (posting_category->account_number) {
        free(posting_category->account_number);
        posting_category->account_number = NULL;
    }
    if (posting_category->account_number_skr03) {
        free(posting_category->account_number_skr03);
        posting_category->account_number_skr03 = NULL;
    }
    if (posting_category->account_number_skr04) {
        free(posting_category->account_number_skr04);
        posting_category->account_number_skr04 = NULL;
    }
    if (posting_category->account_number_skr49) {
        free(posting_category->account_number_skr49);
        posting_category->account_number_skr49 = NULL;
    }
    if (posting_category->category_id) {
        free(posting_category->category_id);
        posting_category->category_id = NULL;
    }
    if (posting_category->default_vat_rate) {
        free(posting_category->default_vat_rate);
        posting_category->default_vat_rate = NULL;
    }
    if (posting_category->description) {
        free(posting_category->description);
        posting_category->description = NULL;
    }
    if (posting_category->eks_category) {
        free(posting_category->eks_category);
        posting_category->eks_category = NULL;
    }
    if (posting_category->is_active) {
        free(posting_category->is_active);
        posting_category->is_active = NULL;
    }
    if (posting_category->is_system) {
        free(posting_category->is_system);
        posting_category->is_system = NULL;
    }
    if (posting_category->name) {
        free(posting_category->name);
        posting_category->name = NULL;
    }
    if (posting_category->skr_version) {
        free(posting_category->skr_version);
        posting_category->skr_version = NULL;
    }
    if (posting_category->type) {
        free(posting_category->type);
        posting_category->type = NULL;
    }
    free(posting_category);
}

cJSON *posting_category_convertToJSON(posting_category_t *posting_category) {
    cJSON *item = cJSON_CreateObject();

    // posting_category->account_number
    if(posting_category->account_number) {
    if(cJSON_AddStringToObject(item, "account_number", posting_category->account_number) == NULL) {
    goto fail; //String
    }
    }


    // posting_category->account_number_skr03
    if(posting_category->account_number_skr03) {
    if(cJSON_AddStringToObject(item, "account_number_skr03", posting_category->account_number_skr03) == NULL) {
    goto fail; //String
    }
    }


    // posting_category->account_number_skr04
    if(posting_category->account_number_skr04) {
    if(cJSON_AddStringToObject(item, "account_number_skr04", posting_category->account_number_skr04) == NULL) {
    goto fail; //String
    }
    }


    // posting_category->account_number_skr49
    if(posting_category->account_number_skr49) {
    if(cJSON_AddStringToObject(item, "account_number_skr49", posting_category->account_number_skr49) == NULL) {
    goto fail; //String
    }
    }


    // posting_category->category_id
    if (!posting_category->category_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "category_id", posting_category->category_id) == NULL) {
    goto fail; //String
    }


    // posting_category->default_vat_rate
    if (!posting_category->default_vat_rate) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "default_vat_rate", *posting_category->default_vat_rate) == NULL) {
    goto fail; //Numeric
    }


    // posting_category->description
    if(posting_category->description) {
    if(cJSON_AddStringToObject(item, "description", posting_category->description) == NULL) {
    goto fail; //String
    }
    }


    // posting_category->eks_category
    if(posting_category->eks_category) {
    if(cJSON_AddStringToObject(item, "eks_category", posting_category->eks_category) == NULL) {
    goto fail; //String
    }
    }


    // posting_category->is_active
    if (!posting_category->is_active) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_active", *posting_category->is_active) == NULL) {
    goto fail; //Bool
    }


    // posting_category->is_system
    if (!posting_category->is_system) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_system", *posting_category->is_system) == NULL) {
    goto fail; //Bool
    }


    // posting_category->name
    if (!posting_category->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", posting_category->name) == NULL) {
    goto fail; //String
    }


    // posting_category->skr_version
    if (!posting_category->skr_version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "skr_version", posting_category->skr_version) == NULL) {
    goto fail; //String
    }


    // posting_category->type
    if (!posting_category->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", posting_category->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

posting_category_t *posting_category_parseFromJSON(cJSON *posting_categoryJSON){

    posting_category_t *posting_category_local_var = NULL;

    char *account_number_local_str = NULL;

    char *account_number_skr03_local_str = NULL;

    char *account_number_skr04_local_str = NULL;

    char *account_number_skr49_local_str = NULL;

    char *category_id_local_str = NULL;

    // define the local variable for posting_category->default_vat_rate
    int *default_vat_rate_local_var = NULL;

    char *description_local_str = NULL;

    char *eks_category_local_str = NULL;

    // define the local variable for posting_category->is_active
    int *is_active_local_var = NULL;

    // define the local variable for posting_category->is_system
    int *is_system_local_var = NULL;

    char *name_local_str = NULL;

    char *skr_version_local_str = NULL;

    char *type_local_str = NULL;

    // posting_category->account_number
    cJSON *account_number = cJSON_GetObjectItemCaseSensitive(posting_categoryJSON, "account_number");
    if (cJSON_IsNull(account_number)) {
        account_number = NULL;
    }
    if (account_number) { 
    if(!cJSON_IsString(account_number) && !cJSON_IsNull(account_number))
    {
    goto end; //String
    }
    }

    // posting_category->account_number_skr03
    cJSON *account_number_skr03 = cJSON_GetObjectItemCaseSensitive(posting_categoryJSON, "account_number_skr03");
    if (cJSON_IsNull(account_number_skr03)) {
        account_number_skr03 = NULL;
    }
    if (account_number_skr03) { 
    if(!cJSON_IsString(account_number_skr03) && !cJSON_IsNull(account_number_skr03))
    {
    goto end; //String
    }
    }

    // posting_category->account_number_skr04
    cJSON *account_number_skr04 = cJSON_GetObjectItemCaseSensitive(posting_categoryJSON, "account_number_skr04");
    if (cJSON_IsNull(account_number_skr04)) {
        account_number_skr04 = NULL;
    }
    if (account_number_skr04) { 
    if(!cJSON_IsString(account_number_skr04) && !cJSON_IsNull(account_number_skr04))
    {
    goto end; //String
    }
    }

    // posting_category->account_number_skr49
    cJSON *account_number_skr49 = cJSON_GetObjectItemCaseSensitive(posting_categoryJSON, "account_number_skr49");
    if (cJSON_IsNull(account_number_skr49)) {
        account_number_skr49 = NULL;
    }
    if (account_number_skr49) { 
    if(!cJSON_IsString(account_number_skr49) && !cJSON_IsNull(account_number_skr49))
    {
    goto end; //String
    }
    }

    // posting_category->category_id
    cJSON *category_id = cJSON_GetObjectItemCaseSensitive(posting_categoryJSON, "category_id");
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

    // posting_category->default_vat_rate
    cJSON *default_vat_rate = cJSON_GetObjectItemCaseSensitive(posting_categoryJSON, "default_vat_rate");
    if (cJSON_IsNull(default_vat_rate)) {
        default_vat_rate = NULL;
    }
    if (!default_vat_rate) {
        goto end;
    }

    
    if(!cJSON_IsNumber(default_vat_rate))
    {
    goto end; //Numeric
    }
    default_vat_rate_local_var = malloc(sizeof(int));
    if(!default_vat_rate_local_var)
    {
        goto end;
    }
    *default_vat_rate_local_var = default_vat_rate->valuedouble;

    // posting_category->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(posting_categoryJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // posting_category->eks_category
    cJSON *eks_category = cJSON_GetObjectItemCaseSensitive(posting_categoryJSON, "eks_category");
    if (cJSON_IsNull(eks_category)) {
        eks_category = NULL;
    }
    if (eks_category) { 
    if(!cJSON_IsString(eks_category) && !cJSON_IsNull(eks_category))
    {
    goto end; //String
    }
    }

    // posting_category->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(posting_categoryJSON, "is_active");
    if (cJSON_IsNull(is_active)) {
        is_active = NULL;
    }
    if (!is_active) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_active))
    {
    goto end; //Bool
    }
    is_active_local_var = malloc(sizeof(int));
    if(!is_active_local_var)
    {
        goto end;
    }
    *is_active_local_var = is_active->valueint;

    // posting_category->is_system
    cJSON *is_system = cJSON_GetObjectItemCaseSensitive(posting_categoryJSON, "is_system");
    if (cJSON_IsNull(is_system)) {
        is_system = NULL;
    }
    if (!is_system) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_system))
    {
    goto end; //Bool
    }
    is_system_local_var = malloc(sizeof(int));
    if(!is_system_local_var)
    {
        goto end;
    }
    *is_system_local_var = is_system->valueint;

    // posting_category->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(posting_categoryJSON, "name");
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

    // posting_category->skr_version
    cJSON *skr_version = cJSON_GetObjectItemCaseSensitive(posting_categoryJSON, "skr_version");
    if (cJSON_IsNull(skr_version)) {
        skr_version = NULL;
    }
    if (!skr_version) {
        goto end;
    }

    
    if(!cJSON_IsString(skr_version))
    {
    goto end; //String
    }

    // posting_category->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(posting_categoryJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    if (account_number && !cJSON_IsNull(account_number)) account_number_local_str = strdup(account_number->valuestring);
    if (account_number_skr03 && !cJSON_IsNull(account_number_skr03)) account_number_skr03_local_str = strdup(account_number_skr03->valuestring);
    if (account_number_skr04 && !cJSON_IsNull(account_number_skr04)) account_number_skr04_local_str = strdup(account_number_skr04->valuestring);
    if (account_number_skr49 && !cJSON_IsNull(account_number_skr49)) account_number_skr49_local_str = strdup(account_number_skr49->valuestring);
    if (category_id && !cJSON_IsNull(category_id)) category_id_local_str = strdup(category_id->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (eks_category && !cJSON_IsNull(eks_category)) eks_category_local_str = strdup(eks_category->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (skr_version && !cJSON_IsNull(skr_version)) skr_version_local_str = strdup(skr_version->valuestring);
    if (type && !cJSON_IsNull(type)) type_local_str = strdup(type->valuestring);

    posting_category_local_var = posting_category_create_internal (
        account_number_local_str,
        account_number_skr03_local_str,
        account_number_skr04_local_str,
        account_number_skr49_local_str,
        category_id_local_str,
        default_vat_rate_local_var,
        description_local_str,
        eks_category_local_str,
        is_active_local_var,
        is_system_local_var,
        name_local_str,
        skr_version_local_str,
        type_local_str
        );

    if (!posting_category_local_var) {
        goto end;
    }

    return posting_category_local_var;
end:
    if (account_number_local_str) {
        free(account_number_local_str);
        account_number_local_str = NULL;
    }
    if (account_number_skr03_local_str) {
        free(account_number_skr03_local_str);
        account_number_skr03_local_str = NULL;
    }
    if (account_number_skr04_local_str) {
        free(account_number_skr04_local_str);
        account_number_skr04_local_str = NULL;
    }
    if (account_number_skr49_local_str) {
        free(account_number_skr49_local_str);
        account_number_skr49_local_str = NULL;
    }
    if (category_id_local_str) {
        free(category_id_local_str);
        category_id_local_str = NULL;
    }
    if (default_vat_rate_local_var) {
        free(default_vat_rate_local_var);
        default_vat_rate_local_var = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (eks_category_local_str) {
        free(eks_category_local_str);
        eks_category_local_str = NULL;
    }
    if (is_active_local_var) {
        free(is_active_local_var);
        is_active_local_var = NULL;
    }
    if (is_system_local_var) {
        free(is_system_local_var);
        is_system_local_var = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (skr_version_local_str) {
        free(skr_version_local_str);
        skr_version_local_str = NULL;
    }
    if (type_local_str) {
        free(type_local_str);
        type_local_str = NULL;
    }
    return NULL;

}
