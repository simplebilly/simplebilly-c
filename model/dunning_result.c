#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dunning_result.h"



static dunning_result_t *dunning_result_create_internal(
    int *invoices_processed,
    char *message
    ) {
    dunning_result_t *dunning_result_local_var = malloc(sizeof(dunning_result_t));
    if (!dunning_result_local_var) {
        return NULL;
    }
    memset(dunning_result_local_var, 0, sizeof(dunning_result_t));
    dunning_result_local_var->_library_owned = 1;
    dunning_result_local_var->invoices_processed = invoices_processed;
    dunning_result_local_var->message = message;
    return dunning_result_local_var;
}

__attribute__((deprecated)) dunning_result_t *dunning_result_create(
    int *invoices_processed,
    char *message
    ) {
    int *invoices_processed_copy = NULL;
    if (invoices_processed) {
        invoices_processed_copy = malloc(sizeof(int));
        if (invoices_processed_copy) *invoices_processed_copy = *invoices_processed;
    }
    dunning_result_t *result = dunning_result_create_internal (
        invoices_processed_copy,
        message
        );
    if (!result) {
        free(invoices_processed_copy);
    }
    return result;
}

void dunning_result_free(dunning_result_t *dunning_result) {
    if(NULL == dunning_result){
        return ;
    }
    if(dunning_result->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "dunning_result_free");
        return ;
    }
    listEntry_t *listEntry;
    if (dunning_result->invoices_processed) {
        free(dunning_result->invoices_processed);
        dunning_result->invoices_processed = NULL;
    }
    if (dunning_result->message) {
        free(dunning_result->message);
        dunning_result->message = NULL;
    }
    free(dunning_result);
}

cJSON *dunning_result_convertToJSON(dunning_result_t *dunning_result) {
    cJSON *item = cJSON_CreateObject();

    // dunning_result->invoices_processed
    if (!dunning_result->invoices_processed) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "invoices_processed", *dunning_result->invoices_processed) == NULL) {
    goto fail; //Numeric
    }


    // dunning_result->message
    if (!dunning_result->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", dunning_result->message) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

dunning_result_t *dunning_result_parseFromJSON(cJSON *dunning_resultJSON){

    dunning_result_t *dunning_result_local_var = NULL;

    // define the local variable for dunning_result->invoices_processed
    int *invoices_processed_local_var = NULL;

    char *message_local_str = NULL;

    // dunning_result->invoices_processed
    cJSON *invoices_processed = cJSON_GetObjectItemCaseSensitive(dunning_resultJSON, "invoices_processed");
    if (cJSON_IsNull(invoices_processed)) {
        invoices_processed = NULL;
    }
    if (!invoices_processed) {
        goto end;
    }

    
    if(!cJSON_IsNumber(invoices_processed))
    {
    goto end; //Numeric
    }
    invoices_processed_local_var = malloc(sizeof(int));
    if(!invoices_processed_local_var)
    {
        goto end;
    }
    *invoices_processed_local_var = invoices_processed->valuedouble;

    // dunning_result->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(dunning_resultJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (!message) {
        goto end;
    }

    
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }


    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);

    dunning_result_local_var = dunning_result_create_internal (
        invoices_processed_local_var,
        message_local_str
        );

    if (!dunning_result_local_var) {
        goto end;
    }

    return dunning_result_local_var;
end:
    if (invoices_processed_local_var) {
        free(invoices_processed_local_var);
        invoices_processed_local_var = NULL;
    }
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    return NULL;

}
