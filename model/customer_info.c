#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "customer_info.h"



static customer_info_t *customer_info_create_internal(
    int *annual_volume,
    int *is_registered
    ) {
    customer_info_t *customer_info_local_var = malloc(sizeof(customer_info_t));
    if (!customer_info_local_var) {
        return NULL;
    }
    memset(customer_info_local_var, 0, sizeof(customer_info_t));
    customer_info_local_var->_library_owned = 1;
    customer_info_local_var->annual_volume = annual_volume;
    customer_info_local_var->is_registered = is_registered;
    return customer_info_local_var;
}

__attribute__((deprecated)) customer_info_t *customer_info_create(
    int *annual_volume,
    int *is_registered
    ) {
    int *annual_volume_copy = NULL;
    if (annual_volume) {
        annual_volume_copy = malloc(sizeof(int));
        if (annual_volume_copy) *annual_volume_copy = *annual_volume;
    }
    int *is_registered_copy = NULL;
    if (is_registered) {
        is_registered_copy = malloc(sizeof(int));
        if (is_registered_copy) *is_registered_copy = *is_registered;
    }
    customer_info_t *result = customer_info_create_internal (
        annual_volume_copy,
        is_registered_copy
        );
    if (!result) {
        free(annual_volume_copy);
        free(is_registered_copy);
    }
    return result;
}

void customer_info_free(customer_info_t *customer_info) {
    if(NULL == customer_info){
        return ;
    }
    if(customer_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "customer_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (customer_info->annual_volume) {
        free(customer_info->annual_volume);
        customer_info->annual_volume = NULL;
    }
    if (customer_info->is_registered) {
        free(customer_info->is_registered);
        customer_info->is_registered = NULL;
    }
    free(customer_info);
}

cJSON *customer_info_convertToJSON(customer_info_t *customer_info) {
    cJSON *item = cJSON_CreateObject();

    // customer_info->annual_volume
    if (!customer_info->annual_volume) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "annual_volume", *customer_info->annual_volume) == NULL) {
    goto fail; //Numeric
    }


    // customer_info->is_registered
    if (!customer_info->is_registered) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_registered", *customer_info->is_registered) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

customer_info_t *customer_info_parseFromJSON(cJSON *customer_infoJSON){

    customer_info_t *customer_info_local_var = NULL;

    // define the local variable for customer_info->annual_volume
    int *annual_volume_local_var = NULL;

    // define the local variable for customer_info->is_registered
    int *is_registered_local_var = NULL;

    // customer_info->annual_volume
    cJSON *annual_volume = cJSON_GetObjectItemCaseSensitive(customer_infoJSON, "annual_volume");
    if (cJSON_IsNull(annual_volume)) {
        annual_volume = NULL;
    }
    if (!annual_volume) {
        goto end;
    }

    
    if(!cJSON_IsNumber(annual_volume))
    {
    goto end; //Numeric
    }
    annual_volume_local_var = malloc(sizeof(int));
    if(!annual_volume_local_var)
    {
        goto end;
    }
    *annual_volume_local_var = annual_volume->valuedouble;

    // customer_info->is_registered
    cJSON *is_registered = cJSON_GetObjectItemCaseSensitive(customer_infoJSON, "is_registered");
    if (cJSON_IsNull(is_registered)) {
        is_registered = NULL;
    }
    if (!is_registered) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_registered))
    {
    goto end; //Bool
    }
    is_registered_local_var = malloc(sizeof(int));
    if(!is_registered_local_var)
    {
        goto end;
    }
    *is_registered_local_var = is_registered->valueint;



    customer_info_local_var = customer_info_create_internal (
        annual_volume_local_var,
        is_registered_local_var
        );

    if (!customer_info_local_var) {
        goto end;
    }

    return customer_info_local_var;
end:
    if (annual_volume_local_var) {
        free(annual_volume_local_var);
        annual_volume_local_var = NULL;
    }
    if (is_registered_local_var) {
        free(is_registered_local_var);
        is_registered_local_var = NULL;
    }
    return NULL;

}
