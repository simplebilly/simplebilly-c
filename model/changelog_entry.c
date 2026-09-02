#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "changelog_entry.h"



static changelog_entry_t *changelog_entry_create_internal(
    char *date,
    char *notes,
    char *version
    ) {
    changelog_entry_t *changelog_entry_local_var = malloc(sizeof(changelog_entry_t));
    if (!changelog_entry_local_var) {
        return NULL;
    }
    memset(changelog_entry_local_var, 0, sizeof(changelog_entry_t));
    changelog_entry_local_var->_library_owned = 1;
    changelog_entry_local_var->date = date;
    changelog_entry_local_var->notes = notes;
    changelog_entry_local_var->version = version;
    return changelog_entry_local_var;
}

__attribute__((deprecated)) changelog_entry_t *changelog_entry_create(
    char *date,
    char *notes,
    char *version
    ) {
    changelog_entry_t *result = changelog_entry_create_internal (
        date,
        notes,
        version
        );
    if (!result) {
    }
    return result;
}

void changelog_entry_free(changelog_entry_t *changelog_entry) {
    if(NULL == changelog_entry){
        return ;
    }
    if(changelog_entry->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "changelog_entry_free");
        return ;
    }
    listEntry_t *listEntry;
    if (changelog_entry->date) {
        free(changelog_entry->date);
        changelog_entry->date = NULL;
    }
    if (changelog_entry->notes) {
        free(changelog_entry->notes);
        changelog_entry->notes = NULL;
    }
    if (changelog_entry->version) {
        free(changelog_entry->version);
        changelog_entry->version = NULL;
    }
    free(changelog_entry);
}

cJSON *changelog_entry_convertToJSON(changelog_entry_t *changelog_entry) {
    cJSON *item = cJSON_CreateObject();

    // changelog_entry->date
    if (!changelog_entry->date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "date", changelog_entry->date) == NULL) {
    goto fail; //String
    }


    // changelog_entry->notes
    if (!changelog_entry->notes) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "notes", changelog_entry->notes) == NULL) {
    goto fail; //String
    }


    // changelog_entry->version
    if (!changelog_entry->version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "version", changelog_entry->version) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

changelog_entry_t *changelog_entry_parseFromJSON(cJSON *changelog_entryJSON){

    changelog_entry_t *changelog_entry_local_var = NULL;

    char *date_local_str = NULL;

    char *notes_local_str = NULL;

    char *version_local_str = NULL;

    // changelog_entry->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(changelog_entryJSON, "date");
    if (cJSON_IsNull(date)) {
        date = NULL;
    }
    if (!date) {
        goto end;
    }

    
    if(!cJSON_IsString(date))
    {
    goto end; //String
    }

    // changelog_entry->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(changelog_entryJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (!notes) {
        goto end;
    }

    
    if(!cJSON_IsString(notes))
    {
    goto end; //String
    }

    // changelog_entry->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(changelog_entryJSON, "version");
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


    if (date && !cJSON_IsNull(date)) date_local_str = strdup(date->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (version && !cJSON_IsNull(version)) version_local_str = strdup(version->valuestring);

    changelog_entry_local_var = changelog_entry_create_internal (
        date_local_str,
        notes_local_str,
        version_local_str
        );

    if (!changelog_entry_local_var) {
        goto end;
    }

    return changelog_entry_local_var;
end:
    if (date_local_str) {
        free(date_local_str);
        date_local_str = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (version_local_str) {
        free(version_local_str);
        version_local_str = NULL;
    }
    return NULL;

}
