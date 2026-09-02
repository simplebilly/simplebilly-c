#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "box_fit.h"



static box_fit_t *box_fit_create_internal(
    double *height_cm,
    int *item_count,
    double *length_cm,
    double *volume_cm3,
    double *width_cm
    ) {
    box_fit_t *box_fit_local_var = malloc(sizeof(box_fit_t));
    if (!box_fit_local_var) {
        return NULL;
    }
    memset(box_fit_local_var, 0, sizeof(box_fit_t));
    box_fit_local_var->_library_owned = 1;
    box_fit_local_var->height_cm = height_cm;
    box_fit_local_var->item_count = item_count;
    box_fit_local_var->length_cm = length_cm;
    box_fit_local_var->volume_cm3 = volume_cm3;
    box_fit_local_var->width_cm = width_cm;
    return box_fit_local_var;
}

__attribute__((deprecated)) box_fit_t *box_fit_create(
    double *height_cm,
    int *item_count,
    double *length_cm,
    double *volume_cm3,
    double *width_cm
    ) {
    double *height_cm_copy = NULL;
    if (height_cm) {
        height_cm_copy = malloc(sizeof(double));
        if (height_cm_copy) *height_cm_copy = *height_cm;
    }
    int *item_count_copy = NULL;
    if (item_count) {
        item_count_copy = malloc(sizeof(int));
        if (item_count_copy) *item_count_copy = *item_count;
    }
    double *length_cm_copy = NULL;
    if (length_cm) {
        length_cm_copy = malloc(sizeof(double));
        if (length_cm_copy) *length_cm_copy = *length_cm;
    }
    double *volume_cm3_copy = NULL;
    if (volume_cm3) {
        volume_cm3_copy = malloc(sizeof(double));
        if (volume_cm3_copy) *volume_cm3_copy = *volume_cm3;
    }
    double *width_cm_copy = NULL;
    if (width_cm) {
        width_cm_copy = malloc(sizeof(double));
        if (width_cm_copy) *width_cm_copy = *width_cm;
    }
    box_fit_t *result = box_fit_create_internal (
        height_cm_copy,
        item_count_copy,
        length_cm_copy,
        volume_cm3_copy,
        width_cm_copy
        );
    if (!result) {
        free(height_cm_copy);
        free(item_count_copy);
        free(length_cm_copy);
        free(volume_cm3_copy);
        free(width_cm_copy);
    }
    return result;
}

void box_fit_free(box_fit_t *box_fit) {
    if(NULL == box_fit){
        return ;
    }
    if(box_fit->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "box_fit_free");
        return ;
    }
    listEntry_t *listEntry;
    if (box_fit->height_cm) {
        free(box_fit->height_cm);
        box_fit->height_cm = NULL;
    }
    if (box_fit->item_count) {
        free(box_fit->item_count);
        box_fit->item_count = NULL;
    }
    if (box_fit->length_cm) {
        free(box_fit->length_cm);
        box_fit->length_cm = NULL;
    }
    if (box_fit->volume_cm3) {
        free(box_fit->volume_cm3);
        box_fit->volume_cm3 = NULL;
    }
    if (box_fit->width_cm) {
        free(box_fit->width_cm);
        box_fit->width_cm = NULL;
    }
    free(box_fit);
}

cJSON *box_fit_convertToJSON(box_fit_t *box_fit) {
    cJSON *item = cJSON_CreateObject();

    // box_fit->height_cm
    if (!box_fit->height_cm) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "height_cm", *box_fit->height_cm) == NULL) {
    goto fail; //Numeric
    }


    // box_fit->item_count
    if (!box_fit->item_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "item_count", *box_fit->item_count) == NULL) {
    goto fail; //Numeric
    }


    // box_fit->length_cm
    if (!box_fit->length_cm) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "length_cm", *box_fit->length_cm) == NULL) {
    goto fail; //Numeric
    }


    // box_fit->volume_cm3
    if (!box_fit->volume_cm3) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "volume_cm3", *box_fit->volume_cm3) == NULL) {
    goto fail; //Numeric
    }


    // box_fit->width_cm
    if (!box_fit->width_cm) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "width_cm", *box_fit->width_cm) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

box_fit_t *box_fit_parseFromJSON(cJSON *box_fitJSON){

    box_fit_t *box_fit_local_var = NULL;

    // define the local variable for box_fit->height_cm
    double *height_cm_local_var = NULL;

    // define the local variable for box_fit->item_count
    int *item_count_local_var = NULL;

    // define the local variable for box_fit->length_cm
    double *length_cm_local_var = NULL;

    // define the local variable for box_fit->volume_cm3
    double *volume_cm3_local_var = NULL;

    // define the local variable for box_fit->width_cm
    double *width_cm_local_var = NULL;

    // box_fit->height_cm
    cJSON *height_cm = cJSON_GetObjectItemCaseSensitive(box_fitJSON, "height_cm");
    if (cJSON_IsNull(height_cm)) {
        height_cm = NULL;
    }
    if (!height_cm) {
        goto end;
    }

    
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

    // box_fit->item_count
    cJSON *item_count = cJSON_GetObjectItemCaseSensitive(box_fitJSON, "item_count");
    if (cJSON_IsNull(item_count)) {
        item_count = NULL;
    }
    if (!item_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(item_count))
    {
    goto end; //Numeric
    }
    item_count_local_var = malloc(sizeof(int));
    if(!item_count_local_var)
    {
        goto end;
    }
    *item_count_local_var = item_count->valuedouble;

    // box_fit->length_cm
    cJSON *length_cm = cJSON_GetObjectItemCaseSensitive(box_fitJSON, "length_cm");
    if (cJSON_IsNull(length_cm)) {
        length_cm = NULL;
    }
    if (!length_cm) {
        goto end;
    }

    
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

    // box_fit->volume_cm3
    cJSON *volume_cm3 = cJSON_GetObjectItemCaseSensitive(box_fitJSON, "volume_cm3");
    if (cJSON_IsNull(volume_cm3)) {
        volume_cm3 = NULL;
    }
    if (!volume_cm3) {
        goto end;
    }

    
    if(!cJSON_IsNumber(volume_cm3))
    {
    goto end; //Numeric
    }
    volume_cm3_local_var = malloc(sizeof(double));
    if(!volume_cm3_local_var)
    {
        goto end;
    }
    *volume_cm3_local_var = volume_cm3->valuedouble;

    // box_fit->width_cm
    cJSON *width_cm = cJSON_GetObjectItemCaseSensitive(box_fitJSON, "width_cm");
    if (cJSON_IsNull(width_cm)) {
        width_cm = NULL;
    }
    if (!width_cm) {
        goto end;
    }

    
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



    box_fit_local_var = box_fit_create_internal (
        height_cm_local_var,
        item_count_local_var,
        length_cm_local_var,
        volume_cm3_local_var,
        width_cm_local_var
        );

    if (!box_fit_local_var) {
        goto end;
    }

    return box_fit_local_var;
end:
    if (height_cm_local_var) {
        free(height_cm_local_var);
        height_cm_local_var = NULL;
    }
    if (item_count_local_var) {
        free(item_count_local_var);
        item_count_local_var = NULL;
    }
    if (length_cm_local_var) {
        free(length_cm_local_var);
        length_cm_local_var = NULL;
    }
    if (volume_cm3_local_var) {
        free(volume_cm3_local_var);
        volume_cm3_local_var = NULL;
    }
    if (width_cm_local_var) {
        free(width_cm_local_var);
        width_cm_local_var = NULL;
    }
    return NULL;

}
