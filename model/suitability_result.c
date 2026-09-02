#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "suitability_result.h"



static suitability_result_t *suitability_result_create_internal(
    list_t *methods,
    box_fit_t *recommended_box,
    int *requires_insurance,
    char *total_value,
    double *total_weight_kg
    ) {
    suitability_result_t *suitability_result_local_var = malloc(sizeof(suitability_result_t));
    if (!suitability_result_local_var) {
        return NULL;
    }
    memset(suitability_result_local_var, 0, sizeof(suitability_result_t));
    suitability_result_local_var->_library_owned = 1;
    suitability_result_local_var->methods = methods;
    suitability_result_local_var->recommended_box = recommended_box;
    suitability_result_local_var->requires_insurance = requires_insurance;
    suitability_result_local_var->total_value = total_value;
    suitability_result_local_var->total_weight_kg = total_weight_kg;
    return suitability_result_local_var;
}

__attribute__((deprecated)) suitability_result_t *suitability_result_create(
    list_t *methods,
    box_fit_t *recommended_box,
    int *requires_insurance,
    char *total_value,
    double *total_weight_kg
    ) {
    int *requires_insurance_copy = NULL;
    if (requires_insurance) {
        requires_insurance_copy = malloc(sizeof(int));
        if (requires_insurance_copy) *requires_insurance_copy = *requires_insurance;
    }
    double *total_weight_kg_copy = NULL;
    if (total_weight_kg) {
        total_weight_kg_copy = malloc(sizeof(double));
        if (total_weight_kg_copy) *total_weight_kg_copy = *total_weight_kg;
    }
    suitability_result_t *result = suitability_result_create_internal (
        methods,
        recommended_box,
        requires_insurance_copy,
        total_value,
        total_weight_kg_copy
        );
    if (!result) {
        free(requires_insurance_copy);
        free(total_weight_kg_copy);
    }
    return result;
}

void suitability_result_free(suitability_result_t *suitability_result) {
    if(NULL == suitability_result){
        return ;
    }
    if(suitability_result->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "suitability_result_free");
        return ;
    }
    listEntry_t *listEntry;
    if (suitability_result->methods) {
        list_ForEach(listEntry, suitability_result->methods) {
            method_suitability_free(listEntry->data);
        }
        list_freeList(suitability_result->methods);
        suitability_result->methods = NULL;
    }
    if (suitability_result->recommended_box) {
        box_fit_free(suitability_result->recommended_box);
        suitability_result->recommended_box = NULL;
    }
    if (suitability_result->requires_insurance) {
        free(suitability_result->requires_insurance);
        suitability_result->requires_insurance = NULL;
    }
    if (suitability_result->total_value) {
        free(suitability_result->total_value);
        suitability_result->total_value = NULL;
    }
    if (suitability_result->total_weight_kg) {
        free(suitability_result->total_weight_kg);
        suitability_result->total_weight_kg = NULL;
    }
    free(suitability_result);
}

cJSON *suitability_result_convertToJSON(suitability_result_t *suitability_result) {
    cJSON *item = cJSON_CreateObject();

    // suitability_result->methods
    if (!suitability_result->methods) {
        goto fail;
    }
    cJSON *methods = cJSON_AddArrayToObject(item, "methods");
    if(methods == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *methodsListEntry;
    if (suitability_result->methods) {
    list_ForEach(methodsListEntry, suitability_result->methods) {
    cJSON *itemLocal = method_suitability_convertToJSON(methodsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(methods, itemLocal);
    }
    }


    // suitability_result->recommended_box
    if(suitability_result->recommended_box) {
    cJSON *recommended_box_local_JSON = box_fit_convertToJSON(suitability_result->recommended_box);
    if(recommended_box_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "recommended_box", recommended_box_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // suitability_result->requires_insurance
    if (!suitability_result->requires_insurance) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "requires_insurance", *suitability_result->requires_insurance) == NULL) {
    goto fail; //Bool
    }


    // suitability_result->total_value
    if (!suitability_result->total_value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_value", suitability_result->total_value) == NULL) {
    goto fail; //String
    }


    // suitability_result->total_weight_kg
    if (!suitability_result->total_weight_kg) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total_weight_kg", *suitability_result->total_weight_kg) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

suitability_result_t *suitability_result_parseFromJSON(cJSON *suitability_resultJSON){

    suitability_result_t *suitability_result_local_var = NULL;

    // define the local list for suitability_result->methods
    list_t *methodsList = NULL;

    // define the local variable for suitability_result->recommended_box
    box_fit_t *recommended_box_local_nonprim = NULL;

    // define the local variable for suitability_result->requires_insurance
    int *requires_insurance_local_var = NULL;

    char *total_value_local_str = NULL;

    // define the local variable for suitability_result->total_weight_kg
    double *total_weight_kg_local_var = NULL;

    // suitability_result->methods
    cJSON *methods = cJSON_GetObjectItemCaseSensitive(suitability_resultJSON, "methods");
    if (cJSON_IsNull(methods)) {
        methods = NULL;
    }
    if (!methods) {
        goto end;
    }

    
    cJSON *methods_local_nonprimitive = NULL;
    if(!cJSON_IsArray(methods)){
        goto end; //nonprimitive container
    }

    methodsList = list_createList();

    cJSON_ArrayForEach(methods_local_nonprimitive,methods )
    {
        if(!cJSON_IsObject(methods_local_nonprimitive)){
            goto end;
        }
        method_suitability_t *methodsItem = method_suitability_parseFromJSON(methods_local_nonprimitive);

        list_addElement(methodsList, methodsItem);
    }

    // suitability_result->recommended_box
    cJSON *recommended_box = cJSON_GetObjectItemCaseSensitive(suitability_resultJSON, "recommended_box");
    if (cJSON_IsNull(recommended_box)) {
        recommended_box = NULL;
    }
    if (recommended_box) { 
    recommended_box_local_nonprim = box_fit_parseFromJSON(recommended_box); //nonprimitive
    }

    // suitability_result->requires_insurance
    cJSON *requires_insurance = cJSON_GetObjectItemCaseSensitive(suitability_resultJSON, "requires_insurance");
    if (cJSON_IsNull(requires_insurance)) {
        requires_insurance = NULL;
    }
    if (!requires_insurance) {
        goto end;
    }

    
    if(!cJSON_IsBool(requires_insurance))
    {
    goto end; //Bool
    }
    requires_insurance_local_var = malloc(sizeof(int));
    if(!requires_insurance_local_var)
    {
        goto end;
    }
    *requires_insurance_local_var = requires_insurance->valueint;

    // suitability_result->total_value
    cJSON *total_value = cJSON_GetObjectItemCaseSensitive(suitability_resultJSON, "total_value");
    if (cJSON_IsNull(total_value)) {
        total_value = NULL;
    }
    if (!total_value) {
        goto end;
    }

    
    if(!cJSON_IsString(total_value))
    {
    goto end; //String
    }

    // suitability_result->total_weight_kg
    cJSON *total_weight_kg = cJSON_GetObjectItemCaseSensitive(suitability_resultJSON, "total_weight_kg");
    if (cJSON_IsNull(total_weight_kg)) {
        total_weight_kg = NULL;
    }
    if (!total_weight_kg) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total_weight_kg))
    {
    goto end; //Numeric
    }
    total_weight_kg_local_var = malloc(sizeof(double));
    if(!total_weight_kg_local_var)
    {
        goto end;
    }
    *total_weight_kg_local_var = total_weight_kg->valuedouble;


    if (total_value && !cJSON_IsNull(total_value)) total_value_local_str = strdup(total_value->valuestring);

    suitability_result_local_var = suitability_result_create_internal (
        methodsList,
        recommended_box ? recommended_box_local_nonprim : NULL,
        requires_insurance_local_var,
        total_value_local_str,
        total_weight_kg_local_var
        );

    if (!suitability_result_local_var) {
        goto end;
    }

    return suitability_result_local_var;
end:
    if (methodsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, methodsList) {
            method_suitability_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(methodsList);
        methodsList = NULL;
    }
    if (recommended_box_local_nonprim) {
        box_fit_free(recommended_box_local_nonprim);
        recommended_box_local_nonprim = NULL;
    }
    if (requires_insurance_local_var) {
        free(requires_insurance_local_var);
        requires_insurance_local_var = NULL;
    }
    if (total_value_local_str) {
        free(total_value_local_str);
        total_value_local_str = NULL;
    }
    if (total_weight_kg_local_var) {
        free(total_weight_kg_local_var);
        total_weight_kg_local_var = NULL;
    }
    return NULL;

}
