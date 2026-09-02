#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "compliance_training.h"



static compliance_training_t *compliance_training_create_internal(
    int *assignable,
    char *code,
    char *created_at,
    char *deleted_at,
    char *description,
    char *id,
    int *pass_score,
    char *plugin_platform,
    simplebilly_api_training_source__e source,
    char *tenant_id,
    char *title,
    char *updated_at,
    int *validity_months
    ) {
    compliance_training_t *compliance_training_local_var = malloc(sizeof(compliance_training_t));
    if (!compliance_training_local_var) {
        return NULL;
    }
    memset(compliance_training_local_var, 0, sizeof(compliance_training_t));
    compliance_training_local_var->_library_owned = 1;
    compliance_training_local_var->assignable = assignable;
    compliance_training_local_var->code = code;
    compliance_training_local_var->created_at = created_at;
    compliance_training_local_var->deleted_at = deleted_at;
    compliance_training_local_var->description = description;
    compliance_training_local_var->id = id;
    compliance_training_local_var->pass_score = pass_score;
    compliance_training_local_var->plugin_platform = plugin_platform;
    compliance_training_local_var->source = source;
    compliance_training_local_var->tenant_id = tenant_id;
    compliance_training_local_var->title = title;
    compliance_training_local_var->updated_at = updated_at;
    compliance_training_local_var->validity_months = validity_months;
    return compliance_training_local_var;
}

__attribute__((deprecated)) compliance_training_t *compliance_training_create(
    int *assignable,
    char *code,
    char *created_at,
    char *deleted_at,
    char *description,
    char *id,
    int *pass_score,
    char *plugin_platform,
    simplebilly_api_training_source__e source,
    char *tenant_id,
    char *title,
    char *updated_at,
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
    compliance_training_t *result = compliance_training_create_internal (
        assignable_copy,
        code,
        created_at,
        deleted_at,
        description,
        id,
        pass_score_copy,
        plugin_platform,
        source,
        tenant_id,
        title,
        updated_at,
        validity_months_copy
        );
    if (!result) {
        free(assignable_copy);
        free(pass_score_copy);
        free(validity_months_copy);
    }
    return result;
}

void compliance_training_free(compliance_training_t *compliance_training) {
    if(NULL == compliance_training){
        return ;
    }
    if(compliance_training->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "compliance_training_free");
        return ;
    }
    listEntry_t *listEntry;
    if (compliance_training->assignable) {
        free(compliance_training->assignable);
        compliance_training->assignable = NULL;
    }
    if (compliance_training->code) {
        free(compliance_training->code);
        compliance_training->code = NULL;
    }
    if (compliance_training->created_at) {
        free(compliance_training->created_at);
        compliance_training->created_at = NULL;
    }
    if (compliance_training->deleted_at) {
        free(compliance_training->deleted_at);
        compliance_training->deleted_at = NULL;
    }
    if (compliance_training->description) {
        free(compliance_training->description);
        compliance_training->description = NULL;
    }
    if (compliance_training->id) {
        free(compliance_training->id);
        compliance_training->id = NULL;
    }
    if (compliance_training->pass_score) {
        free(compliance_training->pass_score);
        compliance_training->pass_score = NULL;
    }
    if (compliance_training->plugin_platform) {
        free(compliance_training->plugin_platform);
        compliance_training->plugin_platform = NULL;
    }
    if (compliance_training->tenant_id) {
        free(compliance_training->tenant_id);
        compliance_training->tenant_id = NULL;
    }
    if (compliance_training->title) {
        free(compliance_training->title);
        compliance_training->title = NULL;
    }
    if (compliance_training->updated_at) {
        free(compliance_training->updated_at);
        compliance_training->updated_at = NULL;
    }
    if (compliance_training->validity_months) {
        free(compliance_training->validity_months);
        compliance_training->validity_months = NULL;
    }
    free(compliance_training);
}

cJSON *compliance_training_convertToJSON(compliance_training_t *compliance_training) {
    cJSON *item = cJSON_CreateObject();

    // compliance_training->assignable
    if(compliance_training->assignable) {
    if(cJSON_AddBoolToObject(item, "assignable", *compliance_training->assignable) == NULL) {
    goto fail; //Bool
    }
    }


    // compliance_training->code
    if(compliance_training->code) {
    if(cJSON_AddStringToObject(item, "code", compliance_training->code) == NULL) {
    goto fail; //String
    }
    }


    // compliance_training->created_at
    if(compliance_training->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", compliance_training->created_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // compliance_training->deleted_at
    if(compliance_training->deleted_at) {
    if(cJSON_AddStringToObject(item, "deletedAt", compliance_training->deleted_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // compliance_training->description
    if(compliance_training->description) {
    if(cJSON_AddStringToObject(item, "description", compliance_training->description) == NULL) {
    goto fail; //String
    }
    }


    // compliance_training->id
    if(compliance_training->id) {
    if(cJSON_AddStringToObject(item, "id", compliance_training->id) == NULL) {
    goto fail; //String
    }
    }


    // compliance_training->pass_score
    if(compliance_training->pass_score) {
    if(cJSON_AddNumberToObject(item, "passScore", *compliance_training->pass_score) == NULL) {
    goto fail; //Numeric
    }
    }


    // compliance_training->plugin_platform
    if(compliance_training->plugin_platform) {
    if(cJSON_AddStringToObject(item, "pluginPlatform", compliance_training->plugin_platform) == NULL) {
    goto fail; //String
    }
    }


    // compliance_training->source
    if(compliance_training->source != simplebilly_api_training_source__NULL) {
    cJSON *source_local_JSON = training_source_convertToJSON(compliance_training->source);
    if(source_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "source", source_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // compliance_training->tenant_id
    if(compliance_training->tenant_id) {
    if(cJSON_AddStringToObject(item, "tenantId", compliance_training->tenant_id) == NULL) {
    goto fail; //String
    }
    }


    // compliance_training->title
    if(compliance_training->title) {
    if(cJSON_AddStringToObject(item, "title", compliance_training->title) == NULL) {
    goto fail; //String
    }
    }


    // compliance_training->updated_at
    if(compliance_training->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", compliance_training->updated_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // compliance_training->validity_months
    if(compliance_training->validity_months) {
    if(cJSON_AddNumberToObject(item, "validityMonths", *compliance_training->validity_months) == NULL) {
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

compliance_training_t *compliance_training_parseFromJSON(cJSON *compliance_trainingJSON){

    compliance_training_t *compliance_training_local_var = NULL;

    // define the local variable for compliance_training->assignable
    int *assignable_local_var = NULL;

    char *code_local_str = NULL;

    char *created_at_local_str = NULL;

    char *deleted_at_local_str = NULL;

    char *description_local_str = NULL;

    char *id_local_str = NULL;

    // define the local variable for compliance_training->pass_score
    int *pass_score_local_var = NULL;

    char *plugin_platform_local_str = NULL;

    // define the local variable for compliance_training->source
    simplebilly_api_training_source__e source_local_nonprim = 0;

    char *tenant_id_local_str = NULL;

    char *title_local_str = NULL;

    char *updated_at_local_str = NULL;

    // define the local variable for compliance_training->validity_months
    int *validity_months_local_var = NULL;

    // compliance_training->assignable
    cJSON *assignable = cJSON_GetObjectItemCaseSensitive(compliance_trainingJSON, "assignable");
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

    // compliance_training->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(compliance_trainingJSON, "code");
    if (cJSON_IsNull(code)) {
        code = NULL;
    }
    if (code) { 
    if(!cJSON_IsString(code) && !cJSON_IsNull(code))
    {
    goto end; //String
    }
    }

    // compliance_training->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(compliance_trainingJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }
    }

    // compliance_training->deleted_at
    cJSON *deleted_at = cJSON_GetObjectItemCaseSensitive(compliance_trainingJSON, "deletedAt");
    if (cJSON_IsNull(deleted_at)) {
        deleted_at = NULL;
    }
    if (deleted_at) { 
    if(!cJSON_IsString(deleted_at) && !cJSON_IsNull(deleted_at))
    {
    goto end; //DateTime
    }
    }

    // compliance_training->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(compliance_trainingJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // compliance_training->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(compliance_trainingJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // compliance_training->pass_score
    cJSON *pass_score = cJSON_GetObjectItemCaseSensitive(compliance_trainingJSON, "passScore");
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

    // compliance_training->plugin_platform
    cJSON *plugin_platform = cJSON_GetObjectItemCaseSensitive(compliance_trainingJSON, "pluginPlatform");
    if (cJSON_IsNull(plugin_platform)) {
        plugin_platform = NULL;
    }
    if (plugin_platform) { 
    if(!cJSON_IsString(plugin_platform) && !cJSON_IsNull(plugin_platform))
    {
    goto end; //String
    }
    }

    // compliance_training->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(compliance_trainingJSON, "source");
    if (cJSON_IsNull(source)) {
        source = NULL;
    }
    if (source) { 
    source_local_nonprim = training_source_parseFromJSON(source); //custom
    }

    // compliance_training->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(compliance_trainingJSON, "tenantId");
    if (cJSON_IsNull(tenant_id)) {
        tenant_id = NULL;
    }
    if (tenant_id) { 
    if(!cJSON_IsString(tenant_id) && !cJSON_IsNull(tenant_id))
    {
    goto end; //String
    }
    }

    // compliance_training->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(compliance_trainingJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // compliance_training->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(compliance_trainingJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }

    // compliance_training->validity_months
    cJSON *validity_months = cJSON_GetObjectItemCaseSensitive(compliance_trainingJSON, "validityMonths");
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
    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (deleted_at && !cJSON_IsNull(deleted_at)) deleted_at_local_str = strdup(deleted_at->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (plugin_platform && !cJSON_IsNull(plugin_platform)) plugin_platform_local_str = strdup(plugin_platform->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);
    if (title && !cJSON_IsNull(title)) title_local_str = strdup(title->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);

    compliance_training_local_var = compliance_training_create_internal (
        assignable_local_var,
        code_local_str,
        created_at_local_str,
        deleted_at_local_str,
        description_local_str,
        id_local_str,
        pass_score_local_var,
        plugin_platform_local_str,
        source ? source_local_nonprim : 0,
        tenant_id_local_str,
        title_local_str,
        updated_at_local_str,
        validity_months_local_var
        );

    if (!compliance_training_local_var) {
        goto end;
    }

    return compliance_training_local_var;
end:
    if (assignable_local_var) {
        free(assignable_local_var);
        assignable_local_var = NULL;
    }
    if (code_local_str) {
        free(code_local_str);
        code_local_str = NULL;
    }
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (deleted_at_local_str) {
        free(deleted_at_local_str);
        deleted_at_local_str = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
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
    if (tenant_id_local_str) {
        free(tenant_id_local_str);
        tenant_id_local_str = NULL;
    }
    if (title_local_str) {
        free(title_local_str);
        title_local_str = NULL;
    }
    if (updated_at_local_str) {
        free(updated_at_local_str);
        updated_at_local_str = NULL;
    }
    if (validity_months_local_var) {
        free(validity_months_local_var);
        validity_months_local_var = NULL;
    }
    return NULL;

}
