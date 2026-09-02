#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "compliance_training_create.h"



static compliance_training_create_t *compliance_training_create_create_internal(
    int *assignable,
    char *code,
    char *description,
    int *pass_score,
    char *plugin_platform,
    simplebilly_api_training_source__e source,
    char *title,
    int *validity_months
    ) {
    compliance_training_create_t *compliance_training_create_local_var = malloc(sizeof(compliance_training_create_t));
    if (!compliance_training_create_local_var) {
        return NULL;
    }
    memset(compliance_training_create_local_var, 0, sizeof(compliance_training_create_t));
    compliance_training_create_local_var->_library_owned = 1;
    compliance_training_create_local_var->assignable = assignable;
    compliance_training_create_local_var->code = code;
    compliance_training_create_local_var->description = description;
    compliance_training_create_local_var->pass_score = pass_score;
    compliance_training_create_local_var->plugin_platform = plugin_platform;
    compliance_training_create_local_var->source = source;
    compliance_training_create_local_var->title = title;
    compliance_training_create_local_var->validity_months = validity_months;
    return compliance_training_create_local_var;
}

__attribute__((deprecated)) compliance_training_create_t *compliance_training_create_create(
    int *assignable,
    char *code,
    char *description,
    int *pass_score,
    char *plugin_platform,
    simplebilly_api_training_source__e source,
    char *title,
    int *validity_months
    ) {
    int *assignable_copy = NULL;
    if (assignable) {
        assignable_copy = malloc(sizeof(int));
        if (assignable_copy) *assignable_copy = *assignable;
    }
    int *pass_score_copy = NULL;
    if (pass_score) {
        pass_score_copy = malloc(sizeof(int));
        if (pass_score_copy) *pass_score_copy = *pass_score;
    }
    int *validity_months_copy = NULL;
    if (validity_months) {
        validity_months_copy = malloc(sizeof(int));
        if (validity_months_copy) *validity_months_copy = *validity_months;
    }
    compliance_training_create_t *result = compliance_training_create_create_internal (
        assignable_copy,
        code,
        description,
        pass_score_copy,
        plugin_platform,
        source,
        title,
        validity_months_copy
        );
    if (!result) {
        free(assignable_copy);
        free(pass_score_copy);
        free(validity_months_copy);
    }
    return result;
}

void compliance_training_create_free(compliance_training_create_t *compliance_training_create) {
    if(NULL == compliance_training_create){
        return ;
    }
    if(compliance_training_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "compliance_training_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (compliance_training_create->assignable) {
        free(compliance_training_create->assignable);
        compliance_training_create->assignable = NULL;
    }
    if (compliance_training_create->code) {
        free(compliance_training_create->code);
        compliance_training_create->code = NULL;
    }
    if (compliance_training_create->description) {
        free(compliance_training_create->description);
        compliance_training_create->description = NULL;
    }
    if (compliance_training_create->pass_score) {
        free(compliance_training_create->pass_score);
        compliance_training_create->pass_score = NULL;
    }
    if (compliance_training_create->plugin_platform) {
        free(compliance_training_create->plugin_platform);
        compliance_training_create->plugin_platform = NULL;
    }
    if (compliance_training_create->title) {
        free(compliance_training_create->title);
        compliance_training_create->title = NULL;
    }
    if (compliance_training_create->validity_months) {
        free(compliance_training_create->validity_months);
        compliance_training_create->validity_months = NULL;
    }
    free(compliance_training_create);
}

cJSON *compliance_training_create_convertToJSON(compliance_training_create_t *compliance_training_create) {
    cJSON *item = cJSON_CreateObject();

    // compliance_training_create->assignable
    if(compliance_training_create->assignable) {
    if(cJSON_AddBoolToObject(item, "assignable", *compliance_training_create->assignable) == NULL) {
    goto fail; //Bool
    }
    }


    // compliance_training_create->code
    if(compliance_training_create->code) {
    if(cJSON_AddStringToObject(item, "code", compliance_training_create->code) == NULL) {
    goto fail; //String
    }
    }


    // compliance_training_create->description
    if(compliance_training_create->description) {
    if(cJSON_AddStringToObject(item, "description", compliance_training_create->description) == NULL) {
    goto fail; //String
    }
    }


    // compliance_training_create->pass_score
    if(compliance_training_create->pass_score) {
    if(cJSON_AddNumberToObject(item, "passScore", *compliance_training_create->pass_score) == NULL) {
    goto fail; //Numeric
    }
    }


    // compliance_training_create->plugin_platform
    if(compliance_training_create->plugin_platform) {
    if(cJSON_AddStringToObject(item, "pluginPlatform", compliance_training_create->plugin_platform) == NULL) {
    goto fail; //String
    }
    }


    // compliance_training_create->source
    if(compliance_training_create->source != simplebilly_api_training_source__NULL) {
    cJSON *source_local_JSON = training_source_convertToJSON(compliance_training_create->source);
    if(source_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "source", source_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // compliance_training_create->title
    if(compliance_training_create->title) {
    if(cJSON_AddStringToObject(item, "title", compliance_training_create->title) == NULL) {
    goto fail; //String
    }
    }


    // compliance_training_create->validity_months
    if(compliance_training_create->validity_months) {
    if(cJSON_AddNumberToObject(item, "validityMonths", *compliance_training_create->validity_months) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

compliance_training_create_t *compliance_training_create_parseFromJSON(cJSON *compliance_training_createJSON){

    compliance_training_create_t *compliance_training_create_local_var = NULL;

    // define the local variable for compliance_training_create->assignable
    int *assignable_local_var = NULL;

    char *code_local_str = NULL;

    char *description_local_str = NULL;

    // define the local variable for compliance_training_create->pass_score
    int *pass_score_local_var = NULL;

    char *plugin_platform_local_str = NULL;

    // define the local variable for compliance_training_create->source
    simplebilly_api_training_source__e source_local_nonprim = 0;

    char *title_local_str = NULL;

    // define the local variable for compliance_training_create->validity_months
    int *validity_months_local_var = NULL;

    // compliance_training_create->assignable
    cJSON *assignable = cJSON_GetObjectItemCaseSensitive(compliance_training_createJSON, "assignable");
    if (cJSON_IsNull(assignable)) {
        assignable = NULL;
    }
    if (assignable) { 
    if(!cJSON_IsBool(assignable))
    {
    goto end; //Bool
    }
    assignable_local_var = malloc(sizeof(int));
    if(!assignable_local_var)
    {
        goto end;
    }
    *assignable_local_var = assignable->valueint;
    }

    // compliance_training_create->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(compliance_training_createJSON, "code");
    if (cJSON_IsNull(code)) {
        code = NULL;
    }
    if (code) { 
    if(!cJSON_IsString(code) && !cJSON_IsNull(code))
    {
    goto end; //String
    }
    }

    // compliance_training_create->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(compliance_training_createJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // compliance_training_create->pass_score
    cJSON *pass_score = cJSON_GetObjectItemCaseSensitive(compliance_training_createJSON, "passScore");
    if (cJSON_IsNull(pass_score)) {
        pass_score = NULL;
    }
    if (pass_score) { 
    if(!cJSON_IsNumber(pass_score))
    {
    goto end; //Numeric
    }
    pass_score_local_var = malloc(sizeof(int));
    if(!pass_score_local_var)
    {
        goto end;
    }
    *pass_score_local_var = pass_score->valuedouble;
    }

    // compliance_training_create->plugin_platform
    cJSON *plugin_platform = cJSON_GetObjectItemCaseSensitive(compliance_training_createJSON, "pluginPlatform");
    if (cJSON_IsNull(plugin_platform)) {
        plugin_platform = NULL;
    }
    if (plugin_platform) { 
    if(!cJSON_IsString(plugin_platform) && !cJSON_IsNull(plugin_platform))
    {
    goto end; //String
    }
    }

    // compliance_training_create->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(compliance_training_createJSON, "source");
    if (cJSON_IsNull(source)) {
        source = NULL;
    }
    if (source) { 
    source_local_nonprim = training_source_parseFromJSON(source); //custom
    }

    // compliance_training_create->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(compliance_training_createJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // compliance_training_create->validity_months
    cJSON *validity_months = cJSON_GetObjectItemCaseSensitive(compliance_training_createJSON, "validityMonths");
    if (cJSON_IsNull(validity_months)) {
        validity_months = NULL;
    }
    if (validity_months) { 
    if(!cJSON_IsNumber(validity_months))
    {
    goto end; //Numeric
    }
    validity_months_local_var = malloc(sizeof(int));
    if(!validity_months_local_var)
    {
        goto end;
    }
    *validity_months_local_var = validity_months->valuedouble;
    }


    if (code && !cJSON_IsNull(code)) code_local_str = strdup(code->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (plugin_platform && !cJSON_IsNull(plugin_platform)) plugin_platform_local_str = strdup(plugin_platform->valuestring);
    if (title && !cJSON_IsNull(title)) title_local_str = strdup(title->valuestring);

    compliance_training_create_local_var = compliance_training_create_create_internal (
        assignable_local_var,
        code_local_str,
        description_local_str,
        pass_score_local_var,
        plugin_platform_local_str,
        source ? source_local_nonprim : 0,
        title_local_str,
        validity_months_local_var
        );

    if (!compliance_training_create_local_var) {
        goto end;
    }

    return compliance_training_create_local_var;
end:
    if (assignable_local_var) {
        free(assignable_local_var);
        assignable_local_var = NULL;
    }
    if (code_local_str) {
        free(code_local_str);
        code_local_str = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (pass_score_local_var) {
        free(pass_score_local_var);
        pass_score_local_var = NULL;
    }
    if (plugin_platform_local_str) {
        free(plugin_platform_local_str);
        plugin_platform_local_str = NULL;
    }
    if (source_local_nonprim) {
        source_local_nonprim = 0;
    }
    if (title_local_str) {
        free(title_local_str);
        title_local_str = NULL;
    }
    if (validity_months_local_var) {
        free(validity_months_local_var);
        validity_months_local_var = NULL;
    }
    return NULL;

}
