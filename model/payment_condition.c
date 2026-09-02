#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "payment_condition.h"



static payment_condition_t *payment_condition_create_internal(
    int *discount_days,
    double *discount_percentage,
    char *id,
    char *name,
    int *payment_term_days
    ) {
    payment_condition_t *payment_condition_local_var = malloc(sizeof(payment_condition_t));
    if (!payment_condition_local_var) {
        return NULL;
    }
    memset(payment_condition_local_var, 0, sizeof(payment_condition_t));
    payment_condition_local_var->_library_owned = 1;
    payment_condition_local_var->discount_days = discount_days;
    payment_condition_local_var->discount_percentage = discount_percentage;
    payment_condition_local_var->id = id;
    payment_condition_local_var->name = name;
    payment_condition_local_var->payment_term_days = payment_term_days;
    return payment_condition_local_var;
}

__attribute__((deprecated)) payment_condition_t *payment_condition_create(
    int *discount_days,
    double *discount_percentage,
    char *id,
    char *name,
    int *payment_term_days
    ) {
    int *discount_days_copy = NULL;
    if (discount_days) {
        discount_days_copy = malloc(sizeof(int));
        if (discount_days_copy) *discount_days_copy = *discount_days;
    }
    double *discount_percentage_copy = NULL;
    if (discount_percentage) {
        discount_percentage_copy = malloc(sizeof(double));
        if (discount_percentage_copy) *discount_percentage_copy = *discount_percentage;
    }
    int *payment_term_days_copy = NULL;
    if (payment_term_days) {
        payment_term_days_copy = malloc(sizeof(int));
        if (payment_term_days_copy) *payment_term_days_copy = *payment_term_days;
    }
    payment_condition_t *result = payment_condition_create_internal (
        discount_days_copy,
        discount_percentage_copy,
        id,
        name,
        payment_term_days_copy
        );
    if (!result) {
        free(discount_days_copy);
        free(discount_percentage_copy);
        free(payment_term_days_copy);
    }
    return result;
}

void payment_condition_free(payment_condition_t *payment_condition) {
    if(NULL == payment_condition){
        return ;
    }
    if(payment_condition->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "payment_condition_free");
        return ;
    }
    listEntry_t *listEntry;
    if (payment_condition->discount_days) {
        free(payment_condition->discount_days);
        payment_condition->discount_days = NULL;
    }
    if (payment_condition->discount_percentage) {
        free(payment_condition->discount_percentage);
        payment_condition->discount_percentage = NULL;
    }
    if (payment_condition->id) {
        free(payment_condition->id);
        payment_condition->id = NULL;
    }
    if (payment_condition->name) {
        free(payment_condition->name);
        payment_condition->name = NULL;
    }
    if (payment_condition->payment_term_days) {
        free(payment_condition->payment_term_days);
        payment_condition->payment_term_days = NULL;
    }
    free(payment_condition);
}

cJSON *payment_condition_convertToJSON(payment_condition_t *payment_condition) {
    cJSON *item = cJSON_CreateObject();

    // payment_condition->discount_days
    if (!payment_condition->discount_days) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "discount_days", *payment_condition->discount_days) == NULL) {
    goto fail; //Numeric
    }


    // payment_condition->discount_percentage
    if (!payment_condition->discount_percentage) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "discount_percentage", *payment_condition->discount_percentage) == NULL) {
    goto fail; //Numeric
    }


    // payment_condition->id
    if (!payment_condition->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", payment_condition->id) == NULL) {
    goto fail; //String
    }


    // payment_condition->name
    if (!payment_condition->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", payment_condition->name) == NULL) {
    goto fail; //String
    }


    // payment_condition->payment_term_days
    if (!payment_condition->payment_term_days) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "payment_term_days", *payment_condition->payment_term_days) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

payment_condition_t *payment_condition_parseFromJSON(cJSON *payment_conditionJSON){

    payment_condition_t *payment_condition_local_var = NULL;

    // define the local variable for payment_condition->discount_days
    int *discount_days_local_var = NULL;

    // define the local variable for payment_condition->discount_percentage
    double *discount_percentage_local_var = NULL;

    char *id_local_str = NULL;

    char *name_local_str = NULL;

    // define the local variable for payment_condition->payment_term_days
    int *payment_term_days_local_var = NULL;

    // payment_condition->discount_days
    cJSON *discount_days = cJSON_GetObjectItemCaseSensitive(payment_conditionJSON, "discount_days");
    if (cJSON_IsNull(discount_days)) {
        discount_days = NULL;
    }
    if (!discount_days) {
        goto end;
    }

    
    if(!cJSON_IsNumber(discount_days))
    {
    goto end; //Numeric
    }
    discount_days_local_var = malloc(sizeof(int));
    if(!discount_days_local_var)
    {
        goto end;
    }
    *discount_days_local_var = discount_days->valuedouble;

    // payment_condition->discount_percentage
    cJSON *discount_percentage = cJSON_GetObjectItemCaseSensitive(payment_conditionJSON, "discount_percentage");
    if (cJSON_IsNull(discount_percentage)) {
        discount_percentage = NULL;
    }
    if (!discount_percentage) {
        goto end;
    }

    
    if(!cJSON_IsNumber(discount_percentage))
    {
    goto end; //Numeric
    }
    discount_percentage_local_var = malloc(sizeof(double));
    if(!discount_percentage_local_var)
    {
        goto end;
    }
    *discount_percentage_local_var = discount_percentage->valuedouble;

    // payment_condition->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(payment_conditionJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // payment_condition->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(payment_conditionJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // payment_condition->payment_term_days
    cJSON *payment_term_days = cJSON_GetObjectItemCaseSensitive(payment_conditionJSON, "payment_term_days");
    if (cJSON_IsNull(payment_term_days)) {
        payment_term_days = NULL;
    }
    if (!payment_term_days) {
        goto end;
    }

    
    if(!cJSON_IsNumber(payment_term_days))
    {
    goto end; //Numeric
    }
    payment_term_days_local_var = malloc(sizeof(int));
    if(!payment_term_days_local_var)
    {
        goto end;
    }
    *payment_term_days_local_var = payment_term_days->valuedouble;


    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    payment_condition_local_var = payment_condition_create_internal (
        discount_days_local_var,
        discount_percentage_local_var,
        id_local_str,
        name_local_str,
        payment_term_days_local_var
        );

    if (!payment_condition_local_var) {
        goto end;
    }

    return payment_condition_local_var;
end:
    if (discount_days_local_var) {
        free(discount_days_local_var);
        discount_days_local_var = NULL;
    }
    if (discount_percentage_local_var) {
        free(discount_percentage_local_var);
        discount_percentage_local_var = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (payment_term_days_local_var) {
        free(payment_term_days_local_var);
        payment_term_days_local_var = NULL;
    }
    return NULL;

}
