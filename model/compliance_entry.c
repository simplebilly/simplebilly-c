#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "compliance_entry.h"



static compliance_entry_t *compliance_entry_create_internal(
    char *description,
    char *module,
    list_t *regulations
    ) {
    compliance_entry_t *compliance_entry_local_var = malloc(sizeof(compliance_entry_t));
    if (!compliance_entry_local_var) {
        return NULL;
    }
    memset(compliance_entry_local_var, 0, sizeof(compliance_entry_t));
    compliance_entry_local_var->_library_owned = 1;
    compliance_entry_local_var->description = description;
    compliance_entry_local_var->module = module;
    compliance_entry_local_var->regulations = regulations;
    return compliance_entry_local_var;
}

__attribute__((deprecated)) compliance_entry_t *compliance_entry_create(
    char *description,
    char *module,
    list_t *regulations
    ) {
    compliance_entry_t *result = compliance_entry_create_internal (
        description,
        module,
        regulations
        );
    if (!result) {
    }
    return result;
}

void compliance_entry_free(compliance_entry_t *compliance_entry) {
    if(NULL == compliance_entry){
        return ;
    }
    if(compliance_entry->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "compliance_entry_free");
        return ;
    }
    listEntry_t *listEntry;
    if (compliance_entry->description) {
        free(compliance_entry->description);
        compliance_entry->description = NULL;
    }
    if (compliance_entry->module) {
        free(compliance_entry->module);
        compliance_entry->module = NULL;
    }
    if (compliance_entry->regulations) {
        list_ForEach(listEntry, compliance_entry->regulations) {
            free(listEntry->data);
        }
        list_freeList(compliance_entry->regulations);
        compliance_entry->regulations = NULL;
    }
    free(compliance_entry);
}

cJSON *compliance_entry_convertToJSON(compliance_entry_t *compliance_entry) {
    cJSON *item = cJSON_CreateObject();

    // compliance_entry->description
    if (!compliance_entry->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", compliance_entry->description) == NULL) {
    goto fail; //String
    }


    // compliance_entry->module
    if (!compliance_entry->module) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "module", compliance_entry->module) == NULL) {
    goto fail; //String
    }


    // compliance_entry->regulations
    if (!compliance_entry->regulations) {
        goto fail;
    }
    cJSON *regulations = cJSON_AddArrayToObject(item, "regulations");
    if(regulations == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *regulationsListEntry;
    list_ForEach(regulationsListEntry, compliance_entry->regulations) {
    if(cJSON_AddStringToObject(regulations, "", regulationsListEntry->data) == NULL)
    {
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

compliance_entry_t *compliance_entry_parseFromJSON(cJSON *compliance_entryJSON){

    compliance_entry_t *compliance_entry_local_var = NULL;

    char *description_local_str = NULL;

    char *module_local_str = NULL;

    // define the local list for compliance_entry->regulations
    list_t *regulationsList = NULL;

    // compliance_entry->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(compliance_entryJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (!description) {
        goto end;
    }

    
    if(!cJSON_IsString(description))
    {
    goto end; //String
    }

    // compliance_entry->module
    cJSON *module = cJSON_GetObjectItemCaseSensitive(compliance_entryJSON, "module");
    if (cJSON_IsNull(module)) {
        module = NULL;
    }
    if (!module) {
        goto end;
    }

    
    if(!cJSON_IsString(module))
    {
    goto end; //String
    }

    // compliance_entry->regulations
    cJSON *regulations = cJSON_GetObjectItemCaseSensitive(compliance_entryJSON, "regulations");
    if (cJSON_IsNull(regulations)) {
        regulations = NULL;
    }
    if (!regulations) {
        goto end;
    }

    
    cJSON *regulations_local = NULL;
    if(!cJSON_IsArray(regulations)) {
        goto end;//primitive container
    }
    regulationsList = list_createList();

    cJSON_ArrayForEach(regulations_local, regulations)
    {
        if(!cJSON_IsString(regulations_local))
        {
            goto end;
        }
        list_addElement(regulationsList , strdup(regulations_local->valuestring));
    }


    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (module && !cJSON_IsNull(module)) module_local_str = strdup(module->valuestring);

    compliance_entry_local_var = compliance_entry_create_internal (
        description_local_str,
        module_local_str,
        regulationsList
        );

    if (!compliance_entry_local_var) {
        goto end;
    }

    return compliance_entry_local_var;
end:
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (module_local_str) {
        free(module_local_str);
        module_local_str = NULL;
    }
    if (regulationsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, regulationsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(regulationsList);
        regulationsList = NULL;
    }
    return NULL;

}
