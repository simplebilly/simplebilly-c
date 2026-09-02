#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plugin_error_one_of_6.h"



static plugin_error_one_of_6_t *plugin_error_one_of_6_create_internal(
    char *not_implemented
    ) {
    plugin_error_one_of_6_t *plugin_error_one_of_6_local_var = malloc(sizeof(plugin_error_one_of_6_t));
    if (!plugin_error_one_of_6_local_var) {
        return NULL;
    }
    memset(plugin_error_one_of_6_local_var, 0, sizeof(plugin_error_one_of_6_t));
    plugin_error_one_of_6_local_var->_library_owned = 1;
    plugin_error_one_of_6_local_var->not_implemented = not_implemented;
    return plugin_error_one_of_6_local_var;
}

__attribute__((deprecated)) plugin_error_one_of_6_t *plugin_error_one_of_6_create(
    char *not_implemented
    ) {
    plugin_error_one_of_6_t *result = plugin_error_one_of_6_create_internal (
        not_implemented
        );
    if (!result) {
    }
    return result;
}

void plugin_error_one_of_6_free(plugin_error_one_of_6_t *plugin_error_one_of_6) {
    if(NULL == plugin_error_one_of_6){
        return ;
    }
    if(plugin_error_one_of_6->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "plugin_error_one_of_6_free");
        return ;
    }
    listEntry_t *listEntry;
    if (plugin_error_one_of_6->not_implemented) {
        free(plugin_error_one_of_6->not_implemented);
        plugin_error_one_of_6->not_implemented = NULL;
    }
    free(plugin_error_one_of_6);
}

cJSON *plugin_error_one_of_6_convertToJSON(plugin_error_one_of_6_t *plugin_error_one_of_6) {
    cJSON *item = cJSON_CreateObject();

    // plugin_error_one_of_6->not_implemented
    if (!plugin_error_one_of_6->not_implemented) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "NotImplemented", plugin_error_one_of_6->not_implemented) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

plugin_error_one_of_6_t *plugin_error_one_of_6_parseFromJSON(cJSON *plugin_error_one_of_6JSON){

    plugin_error_one_of_6_t *plugin_error_one_of_6_local_var = NULL;

    char *not_implemented_local_str = NULL;

    // plugin_error_one_of_6->not_implemented
    cJSON *not_implemented = cJSON_GetObjectItemCaseSensitive(plugin_error_one_of_6JSON, "NotImplemented");
    if (cJSON_IsNull(not_implemented)) {
        not_implemented = NULL;
    }
    if (!not_implemented) {
        goto end;
    }

    
    if(!cJSON_IsString(not_implemented))
    {
    goto end; //String
    }


    if (not_implemented && !cJSON_IsNull(not_implemented)) not_implemented_local_str = strdup(not_implemented->valuestring);

    plugin_error_one_of_6_local_var = plugin_error_one_of_6_create_internal (
        not_implemented_local_str
        );

    if (!plugin_error_one_of_6_local_var) {
        goto end;
    }

    return plugin_error_one_of_6_local_var;
end:
    if (not_implemented_local_str) {
        free(not_implemented_local_str);
        not_implemented_local_str = NULL;
    }
    return NULL;

}
