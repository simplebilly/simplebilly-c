#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "institute_profile.h"



static institute_profile_t *institute_profile_create_internal(
    institute_type_t *institute_type,
    int *kapitalmarktorientiert
    ) {
    institute_profile_t *institute_profile_local_var = malloc(sizeof(institute_profile_t));
    if (!institute_profile_local_var) {
        return NULL;
    }
    memset(institute_profile_local_var, 0, sizeof(institute_profile_t));
    institute_profile_local_var->_library_owned = 1;
    institute_profile_local_var->institute_type = institute_type;
    institute_profile_local_var->kapitalmarktorientiert = kapitalmarktorientiert;
    return institute_profile_local_var;
}

__attribute__((deprecated)) institute_profile_t *institute_profile_create(
    institute_type_t *institute_type,
    int *kapitalmarktorientiert
    ) {
    int *kapitalmarktorientiert_copy = NULL;
    if (kapitalmarktorientiert) {
        kapitalmarktorientiert_copy = malloc(sizeof(int));
        if (kapitalmarktorientiert_copy) *kapitalmarktorientiert_copy = *kapitalmarktorientiert;
    }
    institute_profile_t *result = institute_profile_create_internal (
        institute_type,
        kapitalmarktorientiert_copy
        );
    if (!result) {
        free(kapitalmarktorientiert_copy);
    }
    return result;
}

void institute_profile_free(institute_profile_t *institute_profile) {
    if(NULL == institute_profile){
        return ;
    }
    if(institute_profile->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "institute_profile_free");
        return ;
    }
    listEntry_t *listEntry;
    if (institute_profile->institute_type) {
        institute_type_free(institute_profile->institute_type);
        institute_profile->institute_type = NULL;
    }
    if (institute_profile->kapitalmarktorientiert) {
        free(institute_profile->kapitalmarktorientiert);
        institute_profile->kapitalmarktorientiert = NULL;
    }
    free(institute_profile);
}

cJSON *institute_profile_convertToJSON(institute_profile_t *institute_profile) {
    cJSON *item = cJSON_CreateObject();

    // institute_profile->institute_type
    if(institute_profile->institute_type) {
    cJSON *institute_type_local_JSON = institute_type_convertToJSON(institute_profile->institute_type);
    if(institute_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "instituteType", institute_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // institute_profile->kapitalmarktorientiert
    if(institute_profile->kapitalmarktorientiert) {
    if(cJSON_AddBoolToObject(item, "kapitalmarktorientiert", *institute_profile->kapitalmarktorientiert) == NULL) {
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

institute_profile_t *institute_profile_parseFromJSON(cJSON *institute_profileJSON){

    institute_profile_t *institute_profile_local_var = NULL;

    // define the local variable for institute_profile->institute_type
    institute_type_t *institute_type_local_nonprim = NULL;

    // define the local variable for institute_profile->kapitalmarktorientiert
    int *kapitalmarktorientiert_local_var = NULL;

    // institute_profile->institute_type
    cJSON *institute_type = cJSON_GetObjectItemCaseSensitive(institute_profileJSON, "instituteType");
    if (cJSON_IsNull(institute_type)) {
        institute_type = NULL;
    }
    if (institute_type) { 
    institute_type_local_nonprim = institute_type_parseFromJSON(institute_type); //custom
    }

    // institute_profile->kapitalmarktorientiert
    cJSON *kapitalmarktorientiert = cJSON_GetObjectItemCaseSensitive(institute_profileJSON, "kapitalmarktorientiert");
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



    institute_profile_local_var = institute_profile_create_internal (
        institute_type ? institute_type_local_nonprim : NULL,
        kapitalmarktorientiert_local_var
        );

    if (!institute_profile_local_var) {
        goto end;
    }

    return institute_profile_local_var;
end:
    if (institute_type_local_nonprim) {
        institute_type_free(institute_type_local_nonprim);
        institute_type_local_nonprim = NULL;
    }
    if (kapitalmarktorientiert_local_var) {
        free(kapitalmarktorientiert_local_var);
        kapitalmarktorientiert_local_var = NULL;
    }
    return NULL;

}
