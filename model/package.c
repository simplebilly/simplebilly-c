#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "package.h"



static package_t *package_create_internal(
    char *description,
    double *height_cm,
    double *length_cm,
    char *reference,
    double *weight_kg,
    double *width_cm
    ) {
    package_t *package_local_var = malloc(sizeof(package_t));
    if (!package_local_var) {
        return NULL;
    }
    memset(package_local_var, 0, sizeof(package_t));
    package_local_var->_library_owned = 1;
    package_local_var->description = description;
    package_local_var->height_cm = height_cm;
    package_local_var->length_cm = length_cm;
    package_local_var->reference = reference;
    package_local_var->weight_kg = weight_kg;
    package_local_var->width_cm = width_cm;
    return package_local_var;
}

__attribute__((deprecated)) package_t *package_create(
    char *description,
    double *height_cm,
    double *length_cm,
    char *reference,
    double *weight_kg,
    double *width_cm
    ) {
    double *height_cm_copy = NULL;
    if (height_cm) {
        height_cm_copy = malloc(sizeof(double));
        if (height_cm_copy) *height_cm_copy = *height_cm;
    }
    double *length_cm_copy = NULL;
    if (length_cm) {
        length_cm_copy = malloc(sizeof(double));
        if (length_cm_copy) *length_cm_copy = *length_cm;
    }
    double *weight_kg_copy = NULL;
    if (weight_kg) {
        weight_kg_copy = malloc(sizeof(double));
        if (weight_kg_copy) *weight_kg_copy = *weight_kg;
    }
    double *width_cm_copy = NULL;
    if (width_cm) {
        width_cm_copy = malloc(sizeof(double));
        if (width_cm_copy) *width_cm_copy = *width_cm;
    }
    package_t *result = package_create_internal (
        description,
        height_cm_copy,
        length_cm_copy,
        reference,
        weight_kg_copy,
        width_cm_copy
        );
    if (!result) {
        free(height_cm_copy);
        free(length_cm_copy);
        free(weight_kg_copy);
        free(width_cm_copy);
    }
    return result;
}

void package_free(package_t *package) {
    if(NULL == package){
        return ;
    }
    if(package->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "package_free");
        return ;
    }
    listEntry_t *listEntry;
    if (package->description) {
        free(package->description);
        package->description = NULL;
    }
    if (package->height_cm) {
        free(package->height_cm);
        package->height_cm = NULL;
    }
    if (package->length_cm) {
        free(package->length_cm);
        package->length_cm = NULL;
    }
    if (package->reference) {
        free(package->reference);
        package->reference = NULL;
    }
    if (package->weight_kg) {
        free(package->weight_kg);
        package->weight_kg = NULL;
    }
    if (package->width_cm) {
        free(package->width_cm);
        package->width_cm = NULL;
    }
    free(package);
}

cJSON *package_convertToJSON(package_t *package) {
    cJSON *item = cJSON_CreateObject();

    // package->description
    if(package->description) {
    if(cJSON_AddStringToObject(item, "description", package->description) == NULL) {
    goto fail; //String
    }
    }


    // package->height_cm
    if(package->height_cm) {
    if(cJSON_AddNumberToObject(item, "height_cm", *package->height_cm) == NULL) {
    goto fail; //Numeric
    }
    }


    // package->length_cm
    if(package->length_cm) {
    if(cJSON_AddNumberToObject(item, "length_cm", *package->length_cm) == NULL) {
    goto fail; //Numeric
    }
    }


    // package->reference
    if(package->reference) {
    if(cJSON_AddStringToObject(item, "reference", package->reference) == NULL) {
    goto fail; //String
    }
    }


    // package->weight_kg
    if (!package->weight_kg) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "weight_kg", *package->weight_kg) == NULL) {
    goto fail; //Numeric
    }


    // package->width_cm
    if(package->width_cm) {
    if(cJSON_AddNumberToObject(item, "width_cm", *package->width_cm) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

package_t *package_parseFromJSON(cJSON *packageJSON){

    package_t *package_local_var = NULL;

    char *description_local_str = NULL;

    // define the local variable for package->height_cm
    double *height_cm_local_var = NULL;

    // define the local variable for package->length_cm
    double *length_cm_local_var = NULL;

    char *reference_local_str = NULL;

    // define the local variable for package->weight_kg
    double *weight_kg_local_var = NULL;

    // define the local variable for package->width_cm
    double *width_cm_local_var = NULL;

    // package->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(packageJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // package->height_cm
    cJSON *height_cm = cJSON_GetObjectItemCaseSensitive(packageJSON, "height_cm");
    if (cJSON_IsNull(height_cm)) {
        height_cm = NULL;
    }
    if (height_cm) { 
    if(!cJSON_IsNumber(height_cm))
    {
    goto end; //Numeric
    }
    height_cm_local_var = malloc(sizeof(double));
    if(!height_cm_local_var)
    {
        goto end;
    }
    *height_cm_local_var = height_cm->valuedouble;
    }

    // package->length_cm
    cJSON *length_cm = cJSON_GetObjectItemCaseSensitive(packageJSON, "length_cm");
    if (cJSON_IsNull(length_cm)) {
        length_cm = NULL;
    }
    if (length_cm) { 
    if(!cJSON_IsNumber(length_cm))
    {
    goto end; //Numeric
    }
    length_cm_local_var = malloc(sizeof(double));
    if(!length_cm_local_var)
    {
        goto end;
    }
    *length_cm_local_var = length_cm->valuedouble;
    }

    // package->reference
    cJSON *reference = cJSON_GetObjectItemCaseSensitive(packageJSON, "reference");
    if (cJSON_IsNull(reference)) {
        reference = NULL;
    }
    if (reference) { 
    if(!cJSON_IsString(reference) && !cJSON_IsNull(reference))
    {
    goto end; //String
    }
    }

    // package->weight_kg
    cJSON *weight_kg = cJSON_GetObjectItemCaseSensitive(packageJSON, "weight_kg");
    if (cJSON_IsNull(weight_kg)) {
        weight_kg = NULL;
    }
    if (!weight_kg) {
        goto end;
    }

    
    if(!cJSON_IsNumber(weight_kg))
    {
    goto end; //Numeric
    }
    weight_kg_local_var = malloc(sizeof(double));
    if(!weight_kg_local_var)
    {
        goto end;
    }
    *weight_kg_local_var = weight_kg->valuedouble;

    // package->width_cm
    cJSON *width_cm = cJSON_GetObjectItemCaseSensitive(packageJSON, "width_cm");
    if (cJSON_IsNull(width_cm)) {
        width_cm = NULL;
    }
    if (width_cm) { 
    if(!cJSON_IsNumber(width_cm))
    {
    goto end; //Numeric
    }
    width_cm_local_var = malloc(sizeof(double));
    if(!width_cm_local_var)
    {
        goto end;
    }
    *width_cm_local_var = width_cm->valuedouble;
    }


    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (reference && !cJSON_IsNull(reference)) reference_local_str = strdup(reference->valuestring);

    package_local_var = package_create_internal (
        description_local_str,
        height_cm_local_var,
        length_cm_local_var,
        reference_local_str,
        weight_kg_local_var,
        width_cm_local_var
        );

    if (!package_local_var) {
        goto end;
    }

    return package_local_var;
end:
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (height_cm_local_var) {
        free(height_cm_local_var);
        height_cm_local_var = NULL;
    }
    if (length_cm_local_var) {
        free(length_cm_local_var);
        length_cm_local_var = NULL;
    }
    if (reference_local_str) {
        free(reference_local_str);
        reference_local_str = NULL;
    }
    if (weight_kg_local_var) {
        free(weight_kg_local_var);
        weight_kg_local_var = NULL;
    }
    if (width_cm_local_var) {
        free(width_cm_local_var);
        width_cm_local_var = NULL;
    }
    return NULL;

}
