#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "verfahrensdokumentation.h"



static verfahrensdokumentation_t *verfahrensdokumentation_create_internal(
    list_t *entries,
    char *generated_at,
    char *title,
    char *version
    ) {
    verfahrensdokumentation_t *verfahrensdokumentation_local_var = malloc(sizeof(verfahrensdokumentation_t));
    if (!verfahrensdokumentation_local_var) {
        return NULL;
    }
    memset(verfahrensdokumentation_local_var, 0, sizeof(verfahrensdokumentation_t));
    verfahrensdokumentation_local_var->_library_owned = 1;
    verfahrensdokumentation_local_var->entries = entries;
    verfahrensdokumentation_local_var->generated_at = generated_at;
    verfahrensdokumentation_local_var->title = title;
    verfahrensdokumentation_local_var->version = version;
    return verfahrensdokumentation_local_var;
}

__attribute__((deprecated)) verfahrensdokumentation_t *verfahrensdokumentation_create(
    list_t *entries,
    char *generated_at,
    char *title,
    char *version
    ) {
    verfahrensdokumentation_t *result = verfahrensdokumentation_create_internal (
        entries,
        generated_at,
        title,
        version
        );
    if (!result) {
    }
    return result;
}

void verfahrensdokumentation_free(verfahrensdokumentation_t *verfahrensdokumentation) {
    if(NULL == verfahrensdokumentation){
        return ;
    }
    if(verfahrensdokumentation->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "verfahrensdokumentation_free");
        return ;
    }
    listEntry_t *listEntry;
    if (verfahrensdokumentation->entries) {
        list_ForEach(listEntry, verfahrensdokumentation->entries) {
            compliance_entry_free(listEntry->data);
        }
        list_freeList(verfahrensdokumentation->entries);
        verfahrensdokumentation->entries = NULL;
    }
    if (verfahrensdokumentation->generated_at) {
        free(verfahrensdokumentation->generated_at);
        verfahrensdokumentation->generated_at = NULL;
    }
    if (verfahrensdokumentation->title) {
        free(verfahrensdokumentation->title);
        verfahrensdokumentation->title = NULL;
    }
    if (verfahrensdokumentation->version) {
        free(verfahrensdokumentation->version);
        verfahrensdokumentation->version = NULL;
    }
    free(verfahrensdokumentation);
}

cJSON *verfahrensdokumentation_convertToJSON(verfahrensdokumentation_t *verfahrensdokumentation) {
    cJSON *item = cJSON_CreateObject();

    // verfahrensdokumentation->entries
    if (!verfahrensdokumentation->entries) {
        goto fail;
    }
    cJSON *entries = cJSON_AddArrayToObject(item, "entries");
    if(entries == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *entriesListEntry;
    if (verfahrensdokumentation->entries) {
    list_ForEach(entriesListEntry, verfahrensdokumentation->entries) {
    cJSON *itemLocal = compliance_entry_convertToJSON(entriesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(entries, itemLocal);
    }
    }


    // verfahrensdokumentation->generated_at
    if (!verfahrensdokumentation->generated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "generated_at", verfahrensdokumentation->generated_at) == NULL) {
    goto fail; //String
    }


    // verfahrensdokumentation->title
    if (!verfahrensdokumentation->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", verfahrensdokumentation->title) == NULL) {
    goto fail; //String
    }


    // verfahrensdokumentation->version
    if (!verfahrensdokumentation->version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "version", verfahrensdokumentation->version) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

verfahrensdokumentation_t *verfahrensdokumentation_parseFromJSON(cJSON *verfahrensdokumentationJSON){

    verfahrensdokumentation_t *verfahrensdokumentation_local_var = NULL;

    // define the local list for verfahrensdokumentation->entries
    list_t *entriesList = NULL;

    char *generated_at_local_str = NULL;

    char *title_local_str = NULL;

    char *version_local_str = NULL;

    // verfahrensdokumentation->entries
    cJSON *entries = cJSON_GetObjectItemCaseSensitive(verfahrensdokumentationJSON, "entries");
    if (cJSON_IsNull(entries)) {
        entries = NULL;
    }
    if (!entries) {
        goto end;
    }

    
    cJSON *entries_local_nonprimitive = NULL;
    if(!cJSON_IsArray(entries)){
        goto end; //nonprimitive container
    }

    entriesList = list_createList();

    cJSON_ArrayForEach(entries_local_nonprimitive,entries )
    {
        if(!cJSON_IsObject(entries_local_nonprimitive)){
            goto end;
        }
        compliance_entry_t *entriesItem = compliance_entry_parseFromJSON(entries_local_nonprimitive);

        list_addElement(entriesList, entriesItem);
    }

    // verfahrensdokumentation->generated_at
    cJSON *generated_at = cJSON_GetObjectItemCaseSensitive(verfahrensdokumentationJSON, "generated_at");
    if (cJSON_IsNull(generated_at)) {
        generated_at = NULL;
    }
    if (!generated_at) {
        goto end;
    }

    
    if(!cJSON_IsString(generated_at))
    {
    goto end; //String
    }

    // verfahrensdokumentation->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(verfahrensdokumentationJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (!title) {
        goto end;
    }

    
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }

    // verfahrensdokumentation->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(verfahrensdokumentationJSON, "version");
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


    if (generated_at && !cJSON_IsNull(generated_at)) generated_at_local_str = strdup(generated_at->valuestring);
    if (title && !cJSON_IsNull(title)) title_local_str = strdup(title->valuestring);
    if (version && !cJSON_IsNull(version)) version_local_str = strdup(version->valuestring);

    verfahrensdokumentation_local_var = verfahrensdokumentation_create_internal (
        entriesList,
        generated_at_local_str,
        title_local_str,
        version_local_str
        );

    if (!verfahrensdokumentation_local_var) {
        goto end;
    }

    return verfahrensdokumentation_local_var;
end:
    if (entriesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, entriesList) {
            compliance_entry_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(entriesList);
        entriesList = NULL;
    }
    if (generated_at_local_str) {
        free(generated_at_local_str);
        generated_at_local_str = NULL;
    }
    if (title_local_str) {
        free(title_local_str);
        title_local_str = NULL;
    }
    if (version_local_str) {
        free(version_local_str);
        version_local_str = NULL;
    }
    return NULL;

}
