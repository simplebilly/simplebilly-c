#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "institute_profile_update.h"



static institute_profile_update_t *institute_profile_update_create_internal(
    char *institute_type,
    int *kapitalmarktorientiert
    ) {
    institute_profile_update_t *institute_profile_update_local_var = malloc(sizeof(institute_profile_update_t));
    if (!institute_profile_update_local_var) {
        return NULL;
    }
    memset(institute_profile_update_local_var, 0, sizeof(institute_profile_update_t));
    institute_profile_update_local_var->_library_owned = 1;
    institute_profile_update_local_var->institute_type = institute_type;
    institute_profile_update_local_var->kapitalmarktorientiert = kapitalmarktorientiert;
    return institute_profile_update_local_var;
}

__attribute__((deprecated)) institute_profile_update_t *institute_profile_update_create(
    char *institute_type,
    int *kapitalmarktorientiert
    ) {
    int *kapitalmarktorientiert_copy = NULL;
    if (kapitalmarktorientiert) {
        kapitalmarktorientiert_copy = malloc(sizeof(int));
        if (kapitalmarktorientiert_copy) *kapitalmarktorientiert_copy = *kapitalmarktorientiert;
    }
    institute_profile_update_t *result = institute_profile_update_create_internal (
        institute_type,
        kapitalmarktorientiert_copy
        );
    if (!result) {
        free(kapitalmarktorientiert_copy);
    }
    return result;
}

void institute_profile_update_free(institute_profile_update_t *institute_profile_update) {
    if(NULL == institute_profile_update){
        return ;
    }
    if(institute_profile_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "institute_profile_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (institute_profile_update->institute_type) {
        free(institute_profile_update->institute_type);
        institute_profile_update->institute_type = NULL;
    }
    if (institute_profile_update->kapitalmarktorientiert) {
        free(institute_profile_update->kapitalmarktorientiert);
        institute_profile_update->kapitalmarktorientiert = NULL;
    }
    free(institute_profile_update);
}

cJSON *institute_profile_update_convertToJSON(institute_profile_update_t *institute_profile_update) {
    cJSON *item = cJSON_CreateObject();

    // institute_profile_update->institute_type
    if(institute_profile_update->institute_type) {
    if(cJSON_AddStringToObject(item, "instituteType", institute_profile_update->institute_type) == NULL) {
    goto fail; //String
    }
    }


    // institute_profile_update->kapitalmarktorientiert
    if(institute_profile_update->kapitalmarktorientiert) {
    if(cJSON_AddBoolToObject(item, "kapitalmarktorientiert", *institute_profile_update->kapitalmarktorientiert) == NULL) {
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

institute_profile_update_t *institute_profile_update_parseFromJSON(cJSON *institute_profile_updateJSON){

    institute_profile_update_t *institute_profile_update_local_var = NULL;

    char *institute_type_local_str = NULL;

    // define the local variable for institute_profile_update->kapitalmarktorientiert
    int *kapitalmarktorientiert_local_var = NULL;

    // institute_profile_update->institute_type
    cJSON *institute_type = cJSON_GetObjectItemCaseSensitive(institute_profile_updateJSON, "instituteType");
    if (cJSON_IsNull(institute_type)) {
        institute_type = NULL;
    }
    if (institute_type) { 
    if(!cJSON_IsString(institute_type) && !cJSON_IsNull(institute_type))
    {
    goto end; //String
    }
    }

    // institute_profile_update->kapitalmarktorientiert
    cJSON *kapitalmarktorientiert = cJSON_GetObjectItemCaseSensitive(institute_profile_updateJSON, "kapitalmarktorientiert");
    if (cJSON_IsNull(kapitalmarktorientiert)) {
        kapitalmarktorientiert = NULL;
    }
    if (kapitalmarktorientiert) { 
    if(!cJSON_IsBool(kapitalmarktorientiert))
    {
    goto end; //Bool
    }
    kapitalmarktorientiert_local_var = malloc(sizeof(int));
    if(!kapitalmarktorientiert_local_var)
    {
        goto end;
    }
    *kapitalmarktorientiert_local_var = kapitalmarktorientiert->valueint;
    }


    if (institute_type && !cJSON_IsNull(institute_type)) institute_type_local_str = strdup(institute_type->valuestring);

    institute_profile_update_local_var = institute_profile_update_create_internal (
        institute_type_local_str,
        kapitalmarktorientiert_local_var
        );

    if (!institute_profile_update_local_var) {
        goto end;
    }

    return institute_profile_update_local_var;
end:
    if (institute_type_local_str) {
        free(institute_type_local_str);
        institute_type_local_str = NULL;
    }
    if (kapitalmarktorientiert_local_var) {
        free(kapitalmarktorientiert_local_var);
        kapitalmarktorientiert_local_var = NULL;
    }
    return NULL;

}
