#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "platform_info.h"



static platform_info_t *platform_info_create_internal(
    char *author,
    list_t *changelog,
    list_t *config_field_names,
    list_t *config_fields,
    char *display_name,
    char *platform,
    plugin_pricing_t *pricing,
    list_t *supported_entities,
    int *supports_export,
    int *supports_import,
    int *supports_oauth,
    char *version
    ) {
    platform_info_t *platform_info_local_var = malloc(sizeof(platform_info_t));
    if (!platform_info_local_var) {
        return NULL;
    }
    memset(platform_info_local_var, 0, sizeof(platform_info_t));
    platform_info_local_var->_library_owned = 1;
    platform_info_local_var->author = author;
    platform_info_local_var->changelog = changelog;
    platform_info_local_var->config_field_names = config_field_names;
    platform_info_local_var->config_fields = config_fields;
    platform_info_local_var->display_name = display_name;
    platform_info_local_var->platform = platform;
    platform_info_local_var->pricing = pricing;
    platform_info_local_var->supported_entities = supported_entities;
    platform_info_local_var->supports_export = supports_export;
    platform_info_local_var->supports_import = supports_import;
    platform_info_local_var->supports_oauth = supports_oauth;
    platform_info_local_var->version = version;
    return platform_info_local_var;
}

__attribute__((deprecated)) platform_info_t *platform_info_create(
    char *author,
    list_t *changelog,
    list_t *config_field_names,
    list_t *config_fields,
    char *display_name,
    char *platform,
    plugin_pricing_t *pricing,
    list_t *supported_entities,
    int *supports_export,
    int *supports_import,
    int *supports_oauth,
    char *version
    ) {
    int *supports_export_copy = NULL;
    if (supports_export) {
        supports_export_copy = malloc(sizeof(int));
        if (supports_export_copy) *supports_export_copy = *supports_export;
    }
    int *supports_import_copy = NULL;
    if (supports_import) {
        supports_import_copy = malloc(sizeof(int));
        if (supports_import_copy) *supports_import_copy = *supports_import;
    }
    int *supports_oauth_copy = NULL;
    if (supports_oauth) {
        supports_oauth_copy = malloc(sizeof(int));
        if (supports_oauth_copy) *supports_oauth_copy = *supports_oauth;
    }
    platform_info_t *result = platform_info_create_internal (
        author,
        changelog,
        config_field_names,
        config_fields,
        display_name,
        platform,
        pricing,
        supported_entities,
        supports_export_copy,
        supports_import_copy,
        supports_oauth_copy,
        version
        );
    if (!result) {
        free(supports_export_copy);
        free(supports_import_copy);
        free(supports_oauth_copy);
    }
    return result;
}

void platform_info_free(platform_info_t *platform_info) {
    if(NULL == platform_info){
        return ;
    }
    if(platform_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "platform_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (platform_info->author) {
        free(platform_info->author);
        platform_info->author = NULL;
    }
    if (platform_info->changelog) {
        list_ForEach(listEntry, platform_info->changelog) {
            changelog_entry_free(listEntry->data);
        }
        list_freeList(platform_info->changelog);
        platform_info->changelog = NULL;
    }
    if (platform_info->config_field_names) {
        list_ForEach(listEntry, platform_info->config_field_names) {
            free(listEntry->data);
        }
        list_freeList(platform_info->config_field_names);
        platform_info->config_field_names = NULL;
    }
    if (platform_info->config_fields) {
        list_ForEach(listEntry, platform_info->config_fields) {
            config_field_info_free(listEntry->data);
        }
        list_freeList(platform_info->config_fields);
        platform_info->config_fields = NULL;
    }
    if (platform_info->display_name) {
        free(platform_info->display_name);
        platform_info->display_name = NULL;
    }
    if (platform_info->platform) {
        free(platform_info->platform);
        platform_info->platform = NULL;
    }
    if (platform_info->pricing) {
        plugin_pricing_free(platform_info->pricing);
        platform_info->pricing = NULL;
    }
    if (platform_info->supported_entities) {
        list_ForEach(listEntry, platform_info->supported_entities) {
            free(listEntry->data);
        }
        list_freeList(platform_info->supported_entities);
        platform_info->supported_entities = NULL;
    }
    if (platform_info->supports_export) {
        free(platform_info->supports_export);
        platform_info->supports_export = NULL;
    }
    if (platform_info->supports_import) {
        free(platform_info->supports_import);
        platform_info->supports_import = NULL;
    }
    if (platform_info->supports_oauth) {
        free(platform_info->supports_oauth);
        platform_info->supports_oauth = NULL;
    }
    if (platform_info->version) {
        free(platform_info->version);
        platform_info->version = NULL;
    }
    free(platform_info);
}

cJSON *platform_info_convertToJSON(platform_info_t *platform_info) {
    cJSON *item = cJSON_CreateObject();

    // platform_info->author
    if (!platform_info->author) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "author", platform_info->author) == NULL) {
    goto fail; //String
    }


    // platform_info->changelog
    if (!platform_info->changelog) {
        goto fail;
    }
    cJSON *changelog = cJSON_AddArrayToObject(item, "changelog");
    if(changelog == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *changelogListEntry;
    if (platform_info->changelog) {
    list_ForEach(changelogListEntry, platform_info->changelog) {
    cJSON *itemLocal = changelog_entry_convertToJSON(changelogListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(changelog, itemLocal);
    }
    }


    // platform_info->config_field_names
    if (!platform_info->config_field_names) {
        goto fail;
    }
    cJSON *config_field_names = cJSON_AddArrayToObject(item, "config_field_names");
    if(config_field_names == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *config_field_namesListEntry;
    list_ForEach(config_field_namesListEntry, platform_info->config_field_names) {
    if(cJSON_AddStringToObject(config_field_names, "", config_field_namesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // platform_info->config_fields
    if (!platform_info->config_fields) {
        goto fail;
    }
    cJSON *config_fields = cJSON_AddArrayToObject(item, "config_fields");
    if(config_fields == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *config_fieldsListEntry;
    if (platform_info->config_fields) {
    list_ForEach(config_fieldsListEntry, platform_info->config_fields) {
    cJSON *itemLocal = config_field_info_convertToJSON(config_fieldsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(config_fields, itemLocal);
    }
    }


    // platform_info->display_name
    if (!platform_info->display_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "display_name", platform_info->display_name) == NULL) {
    goto fail; //String
    }


    // platform_info->platform
    if (!platform_info->platform) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "platform", platform_info->platform) == NULL) {
    goto fail; //String
    }


    // platform_info->pricing
    if (!platform_info->pricing) {
        goto fail;
    }
    cJSON *pricing_local_JSON = plugin_pricing_convertToJSON(platform_info->pricing);
    if(pricing_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "pricing", pricing_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // platform_info->supported_entities
    if (!platform_info->supported_entities) {
        goto fail;
    }
    cJSON *supported_entities = cJSON_AddArrayToObject(item, "supported_entities");
    if(supported_entities == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *supported_entitiesListEntry;
    list_ForEach(supported_entitiesListEntry, platform_info->supported_entities) {
    if(cJSON_AddStringToObject(supported_entities, "", supported_entitiesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // platform_info->supports_export
    if (!platform_info->supports_export) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "supports_export", *platform_info->supports_export) == NULL) {
    goto fail; //Bool
    }


    // platform_info->supports_import
    if (!platform_info->supports_import) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "supports_import", *platform_info->supports_import) == NULL) {
    goto fail; //Bool
    }


    // platform_info->supports_oauth
    if (!platform_info->supports_oauth) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "supports_oauth", *platform_info->supports_oauth) == NULL) {
    goto fail; //Bool
    }


    // platform_info->version
    if (!platform_info->version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "version", platform_info->version) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

platform_info_t *platform_info_parseFromJSON(cJSON *platform_infoJSON){

    platform_info_t *platform_info_local_var = NULL;

    char *author_local_str = NULL;

    // define the local list for platform_info->changelog
    list_t *changelogList = NULL;

    // define the local list for platform_info->config_field_names
    list_t *config_field_namesList = NULL;

    // define the local list for platform_info->config_fields
    list_t *config_fieldsList = NULL;

    char *display_name_local_str = NULL;

    char *platform_local_str = NULL;

    // define the local variable for platform_info->pricing
    plugin_pricing_t *pricing_local_nonprim = NULL;

    // define the local list for platform_info->supported_entities
    list_t *supported_entitiesList = NULL;

    // define the local variable for platform_info->supports_export
    int *supports_export_local_var = NULL;

    // define the local variable for platform_info->supports_import
    int *supports_import_local_var = NULL;

    // define the local variable for platform_info->supports_oauth
    int *supports_oauth_local_var = NULL;

    char *version_local_str = NULL;

    // platform_info->author
    cJSON *author = cJSON_GetObjectItemCaseSensitive(platform_infoJSON, "author");
    if (cJSON_IsNull(author)) {
        author = NULL;
    }
    if (!author) {
        goto end;
    }

    
    if(!cJSON_IsString(author))
    {
    goto end; //String
    }

    // platform_info->changelog
    cJSON *changelog = cJSON_GetObjectItemCaseSensitive(platform_infoJSON, "changelog");
    if (cJSON_IsNull(changelog)) {
        changelog = NULL;
    }
    if (!changelog) {
        goto end;
    }

    
    cJSON *changelog_local_nonprimitive = NULL;
    if(!cJSON_IsArray(changelog)){
        goto end; //nonprimitive container
    }

    changelogList = list_createList();

    cJSON_ArrayForEach(changelog_local_nonprimitive,changelog )
    {
        if(!cJSON_IsObject(changelog_local_nonprimitive)){
            goto end;
        }
        changelog_entry_t *changelogItem = changelog_entry_parseFromJSON(changelog_local_nonprimitive);

        list_addElement(changelogList, changelogItem);
    }

    // platform_info->config_field_names
    cJSON *config_field_names = cJSON_GetObjectItemCaseSensitive(platform_infoJSON, "config_field_names");
    if (cJSON_IsNull(config_field_names)) {
        config_field_names = NULL;
    }
    if (!config_field_names) {
        goto end;
    }

    
    cJSON *config_field_names_local = NULL;
    if(!cJSON_IsArray(config_field_names)) {
        goto end;//primitive container
    }
    config_field_namesList = list_createList();

    cJSON_ArrayForEach(config_field_names_local, config_field_names)
    {
        if(!cJSON_IsString(config_field_names_local))
        {
            goto end;
        }
        list_addElement(config_field_namesList , strdup(config_field_names_local->valuestring));
    }

    // platform_info->config_fields
    cJSON *config_fields = cJSON_GetObjectItemCaseSensitive(platform_infoJSON, "config_fields");
    if (cJSON_IsNull(config_fields)) {
        config_fields = NULL;
    }
    if (!config_fields) {
        goto end;
    }

    
    cJSON *config_fields_local_nonprimitive = NULL;
    if(!cJSON_IsArray(config_fields)){
        goto end; //nonprimitive container
    }

    config_fieldsList = list_createList();

    cJSON_ArrayForEach(config_fields_local_nonprimitive,config_fields )
    {
        if(!cJSON_IsObject(config_fields_local_nonprimitive)){
            goto end;
        }
        config_field_info_t *config_fieldsItem = config_field_info_parseFromJSON(config_fields_local_nonprimitive);

        list_addElement(config_fieldsList, config_fieldsItem);
    }

    // platform_info->display_name
    cJSON *display_name = cJSON_GetObjectItemCaseSensitive(platform_infoJSON, "display_name");
    if (cJSON_IsNull(display_name)) {
        display_name = NULL;
    }
    if (!display_name) {
        goto end;
    }

    
    if(!cJSON_IsString(display_name))
    {
    goto end; //String
    }

    // platform_info->platform
    cJSON *platform = cJSON_GetObjectItemCaseSensitive(platform_infoJSON, "platform");
    if (cJSON_IsNull(platform)) {
        platform = NULL;
    }
    if (!platform) {
        goto end;
    }

    
    if(!cJSON_IsString(platform))
    {
    goto end; //String
    }

    // platform_info->pricing
    cJSON *pricing = cJSON_GetObjectItemCaseSensitive(platform_infoJSON, "pricing");
    if (cJSON_IsNull(pricing)) {
        pricing = NULL;
    }
    if (!pricing) {
        goto end;
    }

    
    pricing_local_nonprim = plugin_pricing_parseFromJSON(pricing); //nonprimitive

    // platform_info->supported_entities
    cJSON *supported_entities = cJSON_GetObjectItemCaseSensitive(platform_infoJSON, "supported_entities");
    if (cJSON_IsNull(supported_entities)) {
        supported_entities = NULL;
    }
    if (!supported_entities) {
        goto end;
    }

    
    cJSON *supported_entities_local = NULL;
    if(!cJSON_IsArray(supported_entities)) {
        goto end;//primitive container
    }
    supported_entitiesList = list_createList();

    cJSON_ArrayForEach(supported_entities_local, supported_entities)
    {
        if(!cJSON_IsString(supported_entities_local))
        {
            goto end;
        }
        list_addElement(supported_entitiesList , strdup(supported_entities_local->valuestring));
    }

    // platform_info->supports_export
    cJSON *supports_export = cJSON_GetObjectItemCaseSensitive(platform_infoJSON, "supports_export");
    if (cJSON_IsNull(supports_export)) {
        supports_export = NULL;
    }
    if (!supports_export) {
        goto end;
    }

    
    if(!cJSON_IsBool(supports_export))
    {
    goto end; //Bool
    }
    supports_export_local_var = malloc(sizeof(int));
    if(!supports_export_local_var)
    {
        goto end;
    }
    *supports_export_local_var = supports_export->valueint;

    // platform_info->supports_import
    cJSON *supports_import = cJSON_GetObjectItemCaseSensitive(platform_infoJSON, "supports_import");
    if (cJSON_IsNull(supports_import)) {
        supports_import = NULL;
    }
    if (!supports_import) {
        goto end;
    }

    
    if(!cJSON_IsBool(supports_import))
    {
    goto end; //Bool
    }
    supports_import_local_var = malloc(sizeof(int));
    if(!supports_import_local_var)
    {
        goto end;
    }
    *supports_import_local_var = supports_import->valueint;

    // platform_info->supports_oauth
    cJSON *supports_oauth = cJSON_GetObjectItemCaseSensitive(platform_infoJSON, "supports_oauth");
    if (cJSON_IsNull(supports_oauth)) {
        supports_oauth = NULL;
    }
    if (!supports_oauth) {
        goto end;
    }

    
    if(!cJSON_IsBool(supports_oauth))
    {
    goto end; //Bool
    }
    supports_oauth_local_var = malloc(sizeof(int));
    if(!supports_oauth_local_var)
    {
        goto end;
    }
    *supports_oauth_local_var = supports_oauth->valueint;

    // platform_info->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(platform_infoJSON, "version");
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


    if (author && !cJSON_IsNull(author)) author_local_str = strdup(author->valuestring);
    if (display_name && !cJSON_IsNull(display_name)) display_name_local_str = strdup(display_name->valuestring);
    if (platform && !cJSON_IsNull(platform)) platform_local_str = strdup(platform->valuestring);
    if (version && !cJSON_IsNull(version)) version_local_str = strdup(version->valuestring);

    platform_info_local_var = platform_info_create_internal (
        author_local_str,
        changelogList,
        config_field_namesList,
        config_fieldsList,
        display_name_local_str,
        platform_local_str,
        pricing_local_nonprim,
        supported_entitiesList,
        supports_export_local_var,
        supports_import_local_var,
        supports_oauth_local_var,
        version_local_str
        );

    if (!platform_info_local_var) {
        goto end;
    }

    return platform_info_local_var;
end:
    if (author_local_str) {
        free(author_local_str);
        author_local_str = NULL;
    }
    if (changelogList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, changelogList) {
            changelog_entry_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(changelogList);
        changelogList = NULL;
    }
    if (config_field_namesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, config_field_namesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(config_field_namesList);
        config_field_namesList = NULL;
    }
    if (config_fieldsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, config_fieldsList) {
            config_field_info_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(config_fieldsList);
        config_fieldsList = NULL;
    }
    if (display_name_local_str) {
        free(display_name_local_str);
        display_name_local_str = NULL;
    }
    if (platform_local_str) {
        free(platform_local_str);
        platform_local_str = NULL;
    }
    if (pricing_local_nonprim) {
        plugin_pricing_free(pricing_local_nonprim);
        pricing_local_nonprim = NULL;
    }
    if (supported_entitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, supported_entitiesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(supported_entitiesList);
        supported_entitiesList = NULL;
    }
    if (supports_export_local_var) {
        free(supports_export_local_var);
        supports_export_local_var = NULL;
    }
    if (supports_import_local_var) {
        free(supports_import_local_var);
        supports_import_local_var = NULL;
    }
    if (supports_oauth_local_var) {
        free(supports_oauth_local_var);
        supports_oauth_local_var = NULL;
    }
    if (version_local_str) {
        free(version_local_str);
        version_local_str = NULL;
    }
    return NULL;

}
