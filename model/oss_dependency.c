#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "oss_dependency.h"



static oss_dependency_t *oss_dependency_create_internal(
    char *dependency_type,
    char *license,
    char *name,
    char *version
    ) {
    oss_dependency_t *oss_dependency_local_var = malloc(sizeof(oss_dependency_t));
    if (!oss_dependency_local_var) {
        return NULL;
    }
    memset(oss_dependency_local_var, 0, sizeof(oss_dependency_t));
    oss_dependency_local_var->_library_owned = 1;
    oss_dependency_local_var->dependency_type = dependency_type;
    oss_dependency_local_var->license = license;
    oss_dependency_local_var->name = name;
    oss_dependency_local_var->version = version;
    return oss_dependency_local_var;
}

__attribute__((deprecated)) oss_dependency_t *oss_dependency_create(
    char *dependency_type,
    char *license,
    char *name,
    char *version
    ) {
    oss_dependency_t *result = oss_dependency_create_internal (
        dependency_type,
        license,
        name,
        version
        );
    if (!result) {
    }
    return result;
}

void oss_dependency_free(oss_dependency_t *oss_dependency) {
    if(NULL == oss_dependency){
        return ;
    }
    if(oss_dependency->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "oss_dependency_free");
        return ;
    }
    listEntry_t *listEntry;
    if (oss_dependency->dependency_type) {
        free(oss_dependency->dependency_type);
        oss_dependency->dependency_type = NULL;
    }
    if (oss_dependency->license) {
        free(oss_dependency->license);
        oss_dependency->license = NULL;
    }
    if (oss_dependency->name) {
        free(oss_dependency->name);
        oss_dependency->name = NULL;
    }
    if (oss_dependency->version) {
        free(oss_dependency->version);
        oss_dependency->version = NULL;
    }
    free(oss_dependency);
}

cJSON *oss_dependency_convertToJSON(oss_dependency_t *oss_dependency) {
    cJSON *item = cJSON_CreateObject();

    // oss_dependency->dependency_type
    if (!oss_dependency->dependency_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "dependency_type", oss_dependency->dependency_type) == NULL) {
    goto fail; //String
    }


    // oss_dependency->license
    if(oss_dependency->license) {
    if(cJSON_AddStringToObject(item, "license", oss_dependency->license) == NULL) {
    goto fail; //String
    }
    }


    // oss_dependency->name
    if (!oss_dependency->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", oss_dependency->name) == NULL) {
    goto fail; //String
    }


    // oss_dependency->version
    if (!oss_dependency->version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "version", oss_dependency->version) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

oss_dependency_t *oss_dependency_parseFromJSON(cJSON *oss_dependencyJSON){

    oss_dependency_t *oss_dependency_local_var = NULL;

    char *dependency_type_local_str = NULL;

    char *license_local_str = NULL;

    char *name_local_str = NULL;

    char *version_local_str = NULL;

    // oss_dependency->dependency_type
    cJSON *dependency_type = cJSON_GetObjectItemCaseSensitive(oss_dependencyJSON, "dependency_type");
    if (cJSON_IsNull(dependency_type)) {
        dependency_type = NULL;
    }
    if (!dependency_type) {
        goto end;
    }

    
    if(!cJSON_IsString(dependency_type))
    {
    goto end; //String
    }

    // oss_dependency->license
    cJSON *license = cJSON_GetObjectItemCaseSensitive(oss_dependencyJSON, "license");
    if (cJSON_IsNull(license)) {
        license = NULL;
    }
    if (license) { 
    if(!cJSON_IsString(license) && !cJSON_IsNull(license))
    {
    goto end; //String
    }
    }

    // oss_dependency->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(oss_dependencyJSON, "name");
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

    // oss_dependency->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(oss_dependencyJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (!version) {
        goto end;
    }

    
    if(!cJSON_IsString(version))
    {
    goto end; //String
    }


    if (dependency_type && !cJSON_IsNull(dependency_type)) dependency_type_local_str = strdup(dependency_type->valuestring);
    if (license && !cJSON_IsNull(license)) license_local_str = strdup(license->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (version && !cJSON_IsNull(version)) version_local_str = strdup(version->valuestring);

    oss_dependency_local_var = oss_dependency_create_internal (
        dependency_type_local_str,
        license_local_str,
        name_local_str,
        version_local_str
        );

    if (!oss_dependency_local_var) {
        goto end;
    }

    return oss_dependency_local_var;
end:
    if (dependency_type_local_str) {
        free(dependency_type_local_str);
        dependency_type_local_str = NULL;
    }
    if (license_local_str) {
        free(license_local_str);
        license_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (version_local_str) {
        free(version_local_str);
        version_local_str = NULL;
    }
    return NULL;

}
