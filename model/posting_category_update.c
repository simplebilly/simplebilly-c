#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "posting_category_update.h"



static posting_category_update_t *posting_category_update_create_internal(
    char *account_number,
    char *account_number_skr03,
    char *account_number_skr04,
    char *account_number_skr49,
    posting_category_type_t *category_type,
    char *created_at,
    int *default_vat_rate,
    char *description,
    char *eks_category,
    int *eu_vat_line,
    char *input_vat_percentage,
    int *is_active,
    int *is_system,
    char *name,
    char *skr_version,
    char *updated_at,
    int *user_modified_skr03,
    int *user_modified_skr04
    ) {
    posting_category_update_t *posting_category_update_local_var = malloc(sizeof(posting_category_update_t));
    if (!posting_category_update_local_var) {
        return NULL;
    }
    memset(posting_category_update_local_var, 0, sizeof(posting_category_update_t));
    posting_category_update_local_var->_library_owned = 1;
    posting_category_update_local_var->account_number = account_number;
    posting_category_update_local_var->account_number_skr03 = account_number_skr03;
    posting_category_update_local_var->account_number_skr04 = account_number_skr04;
    posting_category_update_local_var->account_number_skr49 = account_number_skr49;
    posting_category_update_local_var->category_type = category_type;
    posting_category_update_local_var->created_at = created_at;
    posting_category_update_local_var->default_vat_rate = default_vat_rate;
    posting_category_update_local_var->description = description;
    posting_category_update_local_var->eks_category = eks_category;
    posting_category_update_local_var->eu_vat_line = eu_vat_line;
    posting_category_update_local_var->input_vat_percentage = input_vat_percentage;
    posting_category_update_local_var->is_active = is_active;
    posting_category_update_local_var->is_system = is_system;
    posting_category_update_local_var->name = name;
    posting_category_update_local_var->skr_version = skr_version;
    posting_category_update_local_var->updated_at = updated_at;
    posting_category_update_local_var->user_modified_skr03 = user_modified_skr03;
    posting_category_update_local_var->user_modified_skr04 = user_modified_skr04;
    return posting_category_update_local_var;
}

__attribute__((deprecated)) posting_category_update_t *posting_category_update_create(
    char *account_number,
    char *account_number_skr03,
    char *account_number_skr04,
    char *account_number_skr49,
    posting_category_type_t *category_type,
    char *created_at,
    int *default_vat_rate,
    char *description,
    char *eks_category,
    int *eu_vat_line,
    char *input_vat_percentage,
    int *is_active,
    int *is_system,
    char *name,
    char *skr_version,
    char *updated_at,
    int *user_modified_skr03,
    int *user_modified_skr04
    ) {
    int *default_vat_rate_copy = NULL;
    if (default_vat_rate) {
        default_vat_rate_copy = malloc(sizeof(int));
        if (default_vat_rate_copy) *default_vat_rate_copy = *default_vat_rate;
    }
    int *eu_vat_line_copy = NULL;
    if (eu_vat_line) {
        eu_vat_line_copy = malloc(sizeof(int));
        if (eu_vat_line_copy) *eu_vat_line_copy = *eu_vat_line;
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
    int *user_modified_skr03_copy = NULL;
    if (user_modified_skr03) {
        user_modified_skr03_copy = malloc(sizeof(int));
        if (user_modified_skr03_copy) *user_modified_skr03_copy = *user_modified_skr03;
    }
    int *user_modified_skr04_copy = NULL;
    if (user_modified_skr04) {
        user_modified_skr04_copy = malloc(sizeof(int));
        if (user_modified_skr04_copy) *user_modified_skr04_copy = *user_modified_skr04;
    }
    posting_category_update_t *result = posting_category_update_create_internal (
        account_number,
        account_number_skr03,
        account_number_skr04,
        account_number_skr49,
        category_type,
        created_at,
        default_vat_rate_copy,
        description,
        eks_category,
        eu_vat_line_copy,
        input_vat_percentage,
        is_active_copy,
        is_system_copy,
        name,
        skr_version,
        updated_at,
        user_modified_skr03_copy,
        user_modified_skr04_copy
        );
    if (!result) {
        free(default_vat_rate_copy);
        free(eu_vat_line_copy);
        free(is_active_copy);
        free(is_system_copy);
        free(user_modified_skr03_copy);
        free(user_modified_skr04_copy);
    }
    return result;
}

void posting_category_update_free(posting_category_update_t *posting_category_update) {
    if(NULL == posting_category_update){
        return ;
    }
    if(posting_category_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "posting_category_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (posting_category_update->account_number) {
        free(posting_category_update->account_number);
        posting_category_update->account_number = NULL;
    }
    if (posting_category_update->account_number_skr03) {
        free(posting_category_update->account_number_skr03);
        posting_category_update->account_number_skr03 = NULL;
    }
    if (posting_category_update->account_number_skr04) {
        free(posting_category_update->account_number_skr04);
        posting_category_update->account_number_skr04 = NULL;
    }
    if (posting_category_update->account_number_skr49) {
        free(posting_category_update->account_number_skr49);
        posting_category_update->account_number_skr49 = NULL;
    }
    if (posting_category_update->category_type) {
        posting_category_type_free(posting_category_update->category_type);
        posting_category_update->category_type = NULL;
    }
    if (posting_category_update->created_at) {
        free(posting_category_update->created_at);
        posting_category_update->created_at = NULL;
    }
    if (posting_category_update->default_vat_rate) {
        free(posting_category_update->default_vat_rate);
        posting_category_update->default_vat_rate = NULL;
    }
    if (posting_category_update->description) {
        free(posting_category_update->description);
        posting_category_update->description = NULL;
    }
    if (posting_category_update->eks_category) {
        free(posting_category_update->eks_category);
        posting_category_update->eks_category = NULL;
    }
    if (posting_category_update->eu_vat_line) {
        free(posting_category_update->eu_vat_line);
        posting_category_update->eu_vat_line = NULL;
    }
    if (posting_category_update->input_vat_percentage) {
        free(posting_category_update->input_vat_percentage);
        posting_category_update->input_vat_percentage = NULL;
    }
    if (posting_category_update->is_active) {
        free(posting_category_update->is_active);
        posting_category_update->is_active = NULL;
    }
    if (posting_category_update->is_system) {
        free(posting_category_update->is_system);
        posting_category_update->is_system = NULL;
    }
    if (posting_category_update->name) {
        free(posting_category_update->name);
        posting_category_update->name = NULL;
    }
    if (posting_category_update->skr_version) {
        free(posting_category_update->skr_version);
        posting_category_update->skr_version = NULL;
    }
    if (posting_category_update->updated_at) {
        free(posting_category_update->updated_at);
        posting_category_update->updated_at = NULL;
    }
    if (posting_category_update->user_modified_skr03) {
        free(posting_category_update->user_modified_skr03);
        posting_category_update->user_modified_skr03 = NULL;
    }
    if (posting_category_update->user_modified_skr04) {
        free(posting_category_update->user_modified_skr04);
        posting_category_update->user_modified_skr04 = NULL;
    }
    free(posting_category_update);
}

cJSON *posting_category_update_convertToJSON(posting_category_update_t *posting_category_update) {
    cJSON *item = cJSON_CreateObject();

    // posting_category_update->account_number
    if(posting_category_update->account_number) {
    if(cJSON_AddStringToObject(item, "accountNumber", posting_category_update->account_number) == NULL) {
    goto fail; //String
    }
    }


    // posting_category_update->account_number_skr03
    if(posting_category_update->account_number_skr03) {
    if(cJSON_AddStringToObject(item, "accountNumberSkr03", posting_category_update->account_number_skr03) == NULL) {
    goto fail; //String
    }
    }


    // posting_category_update->account_number_skr04
    if(posting_category_update->account_number_skr04) {
    if(cJSON_AddStringToObject(item, "accountNumberSkr04", posting_category_update->account_number_skr04) == NULL) {
    goto fail; //String
    }
    }


    // posting_category_update->account_number_skr49
    if(posting_category_update->account_number_skr49) {
    if(cJSON_AddStringToObject(item, "accountNumberSkr49", posting_category_update->account_number_skr49) == NULL) {
    goto fail; //String
    }
    }


    // posting_category_update->category_type
    if(posting_category_update->category_type) {
    cJSON *category_type_local_JSON = posting_category_type_convertToJSON(posting_category_update->category_type);
    if(category_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "categoryType", category_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // posting_category_update->created_at
    if(posting_category_update->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", posting_category_update->created_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // posting_category_update->default_vat_rate
    if(posting_category_update->default_vat_rate) {
    if(cJSON_AddNumberToObject(item, "defaultVatRate", *posting_category_update->default_vat_rate) == NULL) {
    goto fail; //Numeric
    }
    }


    // posting_category_update->description
    if(posting_category_update->description) {
    if(cJSON_AddStringToObject(item, "description", posting_category_update->description) == NULL) {
    goto fail; //String
    }
    }


    // posting_category_update->eks_category
    if(posting_category_update->eks_category) {
    if(cJSON_AddStringToObject(item, "eksCategory", posting_category_update->eks_category) == NULL) {
    goto fail; //String
    }
    }


    // posting_category_update->eu_vat_line
    if(posting_category_update->eu_vat_line) {
    if(cJSON_AddNumberToObject(item, "euVatLine", *posting_category_update->eu_vat_line) == NULL) {
    goto fail; //Numeric
    }
    }


    // posting_category_update->input_vat_percentage
    if(posting_category_update->input_vat_percentage) {
    if(cJSON_AddStringToObject(item, "inputVatPercentage", posting_category_update->input_vat_percentage) == NULL) {
    goto fail; //String
    }
    }


    // posting_category_update->is_active
    if(posting_category_update->is_active) {
    if(cJSON_AddBoolToObject(item, "isActive", *posting_category_update->is_active) == NULL) {
    goto fail; //Bool
    }
    }


    // posting_category_update->is_system
    if(posting_category_update->is_system) {
    if(cJSON_AddBoolToObject(item, "isSystem", *posting_category_update->is_system) == NULL) {
    goto fail; //Bool
    }
    }


    // posting_category_update->name
    if(posting_category_update->name) {
    if(cJSON_AddStringToObject(item, "name", posting_category_update->name) == NULL) {
    goto fail; //String
    }
    }


    // posting_category_update->skr_version
    if(posting_category_update->skr_version) {
    if(cJSON_AddStringToObject(item, "skrVersion", posting_category_update->skr_version) == NULL) {
    goto fail; //String
    }
    }


    // posting_category_update->updated_at
    if(posting_category_update->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", posting_category_update->updated_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // posting_category_update->user_modified_skr03
    if(posting_category_update->user_modified_skr03) {
    if(cJSON_AddBoolToObject(item, "userModifiedSkr03", *posting_category_update->user_modified_skr03) == NULL) {
    goto fail; //Bool
    }
    }


    // posting_category_update->user_modified_skr04
    if(posting_category_update->user_modified_skr04) {
    if(cJSON_AddBoolToObject(item, "userModifiedSkr04", *posting_category_update->user_modified_skr04) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

posting_category_update_t *posting_category_update_parseFromJSON(cJSON *posting_category_updateJSON){

    posting_category_update_t *posting_category_update_local_var = NULL;

    char *account_number_local_str = NULL;

    char *account_number_skr03_local_str = NULL;

    char *account_number_skr04_local_str = NULL;

    char *account_number_skr49_local_str = NULL;

    // define the local variable for posting_category_update->category_type
    posting_category_type_t *category_type_local_nonprim = NULL;

    char *created_at_local_str = NULL;

    // define the local variable for posting_category_update->default_vat_rate
    int *default_vat_rate_local_var = NULL;

    char *description_local_str = NULL;

    char *eks_category_local_str = NULL;

    // define the local variable for posting_category_update->eu_vat_line
    int *eu_vat_line_local_var = NULL;

    char *input_vat_percentage_local_str = NULL;

    // define the local variable for posting_category_update->is_active
    int *is_active_local_var = NULL;

    // define the local variable for posting_category_update->is_system
    int *is_system_local_var = NULL;

    char *name_local_str = NULL;

    char *skr_version_local_str = NULL;

    char *updated_at_local_str = NULL;

    // define the local variable for posting_category_update->user_modified_skr03
    int *user_modified_skr03_local_var = NULL;

    // define the local variable for posting_category_update->user_modified_skr04
    int *user_modified_skr04_local_var = NULL;

    // posting_category_update->account_number
    cJSON *account_number = cJSON_GetObjectItemCaseSensitive(posting_category_updateJSON, "accountNumber");
    if (cJSON_IsNull(account_number)) {
        account_number = NULL;
    }
    if (account_number) { 
    if(!cJSON_IsString(account_number) && !cJSON_IsNull(account_number))
    {
    goto end; //String
    }
    }

    // posting_category_update->account_number_skr03
    cJSON *account_number_skr03 = cJSON_GetObjectItemCaseSensitive(posting_category_updateJSON, "accountNumberSkr03");
    if (cJSON_IsNull(account_number_skr03)) {
        account_number_skr03 = NULL;
    }
    if (account_number_skr03) { 
    if(!cJSON_IsString(account_number_skr03) && !cJSON_IsNull(account_number_skr03))
    {
    goto end; //String
    }
    }

    // posting_category_update->account_number_skr04
    cJSON *account_number_skr04 = cJSON_GetObjectItemCaseSensitive(posting_category_updateJSON, "accountNumberSkr04");
    if (cJSON_IsNull(account_number_skr04)) {
        account_number_skr04 = NULL;
    }
    if (account_number_skr04) { 
    if(!cJSON_IsString(account_number_skr04) && !cJSON_IsNull(account_number_skr04))
    {
    goto end; //String
    }
    }

    // posting_category_update->account_number_skr49
    cJSON *account_number_skr49 = cJSON_GetObjectItemCaseSensitive(posting_category_updateJSON, "accountNumberSkr49");
    if (cJSON_IsNull(account_number_skr49)) {
        account_number_skr49 = NULL;
    }
    if (account_number_skr49) { 
    if(!cJSON_IsString(account_number_skr49) && !cJSON_IsNull(account_number_skr49))
    {
    goto end; //String
    }
    }

    // posting_category_update->category_type
    cJSON *category_type = cJSON_GetObjectItemCaseSensitive(posting_category_updateJSON, "categoryType");
    if (cJSON_IsNull(category_type)) {
        category_type = NULL;
    }
    if (category_type) { 
    category_type_local_nonprim = posting_category_type_parseFromJSON(category_type); //custom
    }

    // posting_category_update->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(posting_category_updateJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }
    }

    // posting_category_update->default_vat_rate
    cJSON *default_vat_rate = cJSON_GetObjectItemCaseSensitive(posting_category_updateJSON, "defaultVatRate");
    if (cJSON_IsNull(default_vat_rate)) {
        default_vat_rate = NULL;
    }
    if (default_vat_rate) { 
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
    }

    // posting_category_update->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(posting_category_updateJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // posting_category_update->eks_category
    cJSON *eks_category = cJSON_GetObjectItemCaseSensitive(posting_category_updateJSON, "eksCategory");
    if (cJSON_IsNull(eks_category)) {
        eks_category = NULL;
    }
    if (eks_category) { 
    if(!cJSON_IsString(eks_category) && !cJSON_IsNull(eks_category))
    {
    goto end; //String
    }
    }

    // posting_category_update->eu_vat_line
    cJSON *eu_vat_line = cJSON_GetObjectItemCaseSensitive(posting_category_updateJSON, "euVatLine");
    if (cJSON_IsNull(eu_vat_line)) {
        eu_vat_line = NULL;
    }
    if (eu_vat_line) { 
    if(!cJSON_IsNumber(eu_vat_line))
    {
    goto end; //Numeric
    }
    eu_vat_line_local_var = malloc(sizeof(int));
    if(!eu_vat_line_local_var)
    {
        goto end;
    }
    *eu_vat_line_local_var = eu_vat_line->valuedouble;
    }

    // posting_category_update->input_vat_percentage
    cJSON *input_vat_percentage = cJSON_GetObjectItemCaseSensitive(posting_category_updateJSON, "inputVatPercentage");
    if (cJSON_IsNull(input_vat_percentage)) {
        input_vat_percentage = NULL;
    }
    if (input_vat_percentage) { 
    if(!cJSON_IsString(input_vat_percentage) && !cJSON_IsNull(input_vat_percentage))
    {
    goto end; //String
    }
    }

    // posting_category_update->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(posting_category_updateJSON, "isActive");
    if (cJSON_IsNull(is_active)) {
        is_active = NULL;
    }
    if (is_active) { 
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
    }

    // posting_category_update->is_system
    cJSON *is_system = cJSON_GetObjectItemCaseSensitive(posting_category_updateJSON, "isSystem");
    if (cJSON_IsNull(is_system)) {
        is_system = NULL;
    }
    if (is_system) { 
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
    }

    // posting_category_update->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(posting_category_updateJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // posting_category_update->skr_version
    cJSON *skr_version = cJSON_GetObjectItemCaseSensitive(posting_category_updateJSON, "skrVersion");
    if (cJSON_IsNull(skr_version)) {
        skr_version = NULL;
    }
    if (skr_version) { 
    if(!cJSON_IsString(skr_version) && !cJSON_IsNull(skr_version))
    {
    goto end; //String
    }
    }

    // posting_category_update->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(posting_category_updateJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }

    // posting_category_update->user_modified_skr03
    cJSON *user_modified_skr03 = cJSON_GetObjectItemCaseSensitive(posting_category_updateJSON, "userModifiedSkr03");
    if (cJSON_IsNull(user_modified_skr03)) {
        user_modified_skr03 = NULL;
    }
    if (user_modified_skr03) { 
    if(!cJSON_IsBool(user_modified_skr03))
    {
    goto end; //Bool
    }
    user_modified_skr03_local_var = malloc(sizeof(int));
    if(!user_modified_skr03_local_var)
    {
        goto end;
    }
    *user_modified_skr03_local_var = user_modified_skr03->valueint;
    }

    // posting_category_update->user_modified_skr04
    cJSON *user_modified_skr04 = cJSON_GetObjectItemCaseSensitive(posting_category_updateJSON, "userModifiedSkr04");
    if (cJSON_IsNull(user_modified_skr04)) {
        user_modified_skr04 = NULL;
    }
    if (user_modified_skr04) { 
    if(!cJSON_IsBool(user_modified_skr04))
    {
    goto end; //Bool
    }
    user_modified_skr04_local_var = malloc(sizeof(int));
    if(!user_modified_skr04_local_var)
    {
        goto end;
    }
    *user_modified_skr04_local_var = user_modified_skr04->valueint;
    }


    if (account_number && !cJSON_IsNull(account_number)) account_number_local_str = strdup(account_number->valuestring);
    if (account_number_skr03 && !cJSON_IsNull(account_number_skr03)) account_number_skr03_local_str = strdup(account_number_skr03->valuestring);
    if (account_number_skr04 && !cJSON_IsNull(account_number_skr04)) account_number_skr04_local_str = strdup(account_number_skr04->valuestring);
    if (account_number_skr49 && !cJSON_IsNull(account_number_skr49)) account_number_skr49_local_str = strdup(account_number_skr49->valuestring);
    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (eks_category && !cJSON_IsNull(eks_category)) eks_category_local_str = strdup(eks_category->valuestring);
    if (input_vat_percentage && !cJSON_IsNull(input_vat_percentage)) input_vat_percentage_local_str = strdup(input_vat_percentage->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (skr_version && !cJSON_IsNull(skr_version)) skr_version_local_str = strdup(skr_version->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);

    posting_category_update_local_var = posting_category_update_create_internal (
        account_number_local_str,
        account_number_skr03_local_str,
        account_number_skr04_local_str,
        account_number_skr49_local_str,
        category_type ? category_type_local_nonprim : NULL,
        created_at_local_str,
        default_vat_rate_local_var,
        description_local_str,
        eks_category_local_str,
        eu_vat_line_local_var,
        input_vat_percentage_local_str,
        is_active_local_var,
        is_system_local_var,
        name_local_str,
        skr_version_local_str,
        updated_at_local_str,
        user_modified_skr03_local_var,
        user_modified_skr04_local_var
        );

    if (!posting_category_update_local_var) {
        goto end;
    }

    return posting_category_update_local_var;
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
    if (category_type_local_nonprim) {
        posting_category_type_free(category_type_local_nonprim);
        category_type_local_nonprim = NULL;
    }
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
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
    if (eu_vat_line_local_var) {
        free(eu_vat_line_local_var);
        eu_vat_line_local_var = NULL;
    }
    if (input_vat_percentage_local_str) {
        free(input_vat_percentage_local_str);
        input_vat_percentage_local_str = NULL;
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
    if (updated_at_local_str) {
        free(updated_at_local_str);
        updated_at_local_str = NULL;
    }
    if (user_modified_skr03_local_var) {
        free(user_modified_skr03_local_var);
        user_modified_skr03_local_var = NULL;
    }
    if (user_modified_skr04_local_var) {
        free(user_modified_skr04_local_var);
        user_modified_skr04_local_var = NULL;
    }
    return NULL;

}
