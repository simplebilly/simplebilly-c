#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_tenant_settings.h"



static update_tenant_settings_t *update_tenant_settings_create_internal(
    simplebilly_api_company_type__e company_type,
    partial_feature_settings_t *features
    ) {
    update_tenant_settings_t *update_tenant_settings_local_var = malloc(sizeof(update_tenant_settings_t));
    if (!update_tenant_settings_local_var) {
        return NULL;
    }
    memset(update_tenant_settings_local_var, 0, sizeof(update_tenant_settings_t));
    update_tenant_settings_local_var->_library_owned = 1;
    update_tenant_settings_local_var->company_type = company_type;
    update_tenant_settings_local_var->features = features;
    return update_tenant_settings_local_var;
}

__attribute__((deprecated)) update_tenant_settings_t *update_tenant_settings_create(
    simplebilly_api_company_type__e company_type,
    partial_feature_settings_t *features
    ) {
    update_tenant_settings_t *result = update_tenant_settings_create_internal (
        company_type,
        features
        );
    if (!result) {
    }
    return result;
}

void update_tenant_settings_free(update_tenant_settings_t *update_tenant_settings) {
    if(NULL == update_tenant_settings){
        return ;
    }
    if(update_tenant_settings->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_tenant_settings_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update_tenant_settings->features) {
        partial_feature_settings_free(update_tenant_settings->features);
        update_tenant_settings->features = NULL;
    }
    free(update_tenant_settings);
}

cJSON *update_tenant_settings_convertToJSON(update_tenant_settings_t *update_tenant_settings) {
    cJSON *item = cJSON_CreateObject();

    // update_tenant_settings->company_type
    if (simplebilly_api_company_type__NULL == update_tenant_settings->company_type) {
        goto fail;
    }
    cJSON *company_type_local_JSON = company_type_convertToJSON(update_tenant_settings->company_type);
    if(company_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "companyType", company_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // update_tenant_settings->features
    if(update_tenant_settings->features) {
    cJSON *features_local_JSON = partial_feature_settings_convertToJSON(update_tenant_settings->features);
    if(features_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "features", features_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

update_tenant_settings_t *update_tenant_settings_parseFromJSON(cJSON *update_tenant_settingsJSON){

    update_tenant_settings_t *update_tenant_settings_local_var = NULL;

    // define the local variable for update_tenant_settings->company_type
    simplebilly_api_company_type__e company_type_local_nonprim = 0;

    // define the local variable for update_tenant_settings->features
    partial_feature_settings_t *features_local_nonprim = NULL;

    // update_tenant_settings->company_type
    cJSON *company_type = cJSON_GetObjectItemCaseSensitive(update_tenant_settingsJSON, "companyType");
    if (cJSON_IsNull(company_type)) {
        company_type = NULL;
    }
    if (!company_type) {
        goto end;
    }

    
    company_type_local_nonprim = company_type_parseFromJSON(company_type); //custom

    // update_tenant_settings->features
    cJSON *features = cJSON_GetObjectItemCaseSensitive(update_tenant_settingsJSON, "features");
    if (cJSON_IsNull(features)) {
        features = NULL;
    }
    if (features) { 
    features_local_nonprim = partial_feature_settings_parseFromJSON(features); //nonprimitive
    }



    update_tenant_settings_local_var = update_tenant_settings_create_internal (
        company_type_local_nonprim,
        features ? features_local_nonprim : NULL
        );

    if (!update_tenant_settings_local_var) {
        goto end;
    }

    return update_tenant_settings_local_var;
end:
    if (company_type_local_nonprim) {
        company_type_local_nonprim = 0;
    }
    if (features_local_nonprim) {
        partial_feature_settings_free(features_local_nonprim);
        features_local_nonprim = NULL;
    }
    return NULL;

}
