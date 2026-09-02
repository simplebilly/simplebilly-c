#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "print_label_response.h"



static print_label_response_t *print_label_response_create_internal(
    char *label_url,
    char *message,
    char *sscc,
    int *success,
    char *tracking_number
    ) {
    print_label_response_t *print_label_response_local_var = malloc(sizeof(print_label_response_t));
    if (!print_label_response_local_var) {
        return NULL;
    }
    memset(print_label_response_local_var, 0, sizeof(print_label_response_t));
    print_label_response_local_var->_library_owned = 1;
    print_label_response_local_var->label_url = label_url;
    print_label_response_local_var->message = message;
    print_label_response_local_var->sscc = sscc;
    print_label_response_local_var->success = success;
    print_label_response_local_var->tracking_number = tracking_number;
    return print_label_response_local_var;
}

__attribute__((deprecated)) print_label_response_t *print_label_response_create(
    char *label_url,
    char *message,
    char *sscc,
    int *success,
    char *tracking_number
    ) {
    int *success_copy = NULL;
    if (success) {
        success_copy = malloc(sizeof(int));
        if (success_copy) *success_copy = *success;
    }
    print_label_response_t *result = print_label_response_create_internal (
        label_url,
        message,
        sscc,
        success_copy,
        tracking_number
        );
    if (!result) {
        free(success_copy);
    }
    return result;
}

void print_label_response_free(print_label_response_t *print_label_response) {
    if(NULL == print_label_response){
        return ;
    }
    if(print_label_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "print_label_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (print_label_response->label_url) {
        free(print_label_response->label_url);
        print_label_response->label_url = NULL;
    }
    if (print_label_response->message) {
        free(print_label_response->message);
        print_label_response->message = NULL;
    }
    if (print_label_response->sscc) {
        free(print_label_response->sscc);
        print_label_response->sscc = NULL;
    }
    if (print_label_response->success) {
        free(print_label_response->success);
        print_label_response->success = NULL;
    }
    if (print_label_response->tracking_number) {
        free(print_label_response->tracking_number);
        print_label_response->tracking_number = NULL;
    }
    free(print_label_response);
}

cJSON *print_label_response_convertToJSON(print_label_response_t *print_label_response) {
    cJSON *item = cJSON_CreateObject();

    // print_label_response->label_url
    if(print_label_response->label_url) {
    if(cJSON_AddStringToObject(item, "label_url", print_label_response->label_url) == NULL) {
    goto fail; //String
    }
    }


    // print_label_response->message
    if (!print_label_response->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", print_label_response->message) == NULL) {
    goto fail; //String
    }


    // print_label_response->sscc
    if(print_label_response->sscc) {
    if(cJSON_AddStringToObject(item, "sscc", print_label_response->sscc) == NULL) {
    goto fail; //String
    }
    }


    // print_label_response->success
    if (!print_label_response->success) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "success", *print_label_response->success) == NULL) {
    goto fail; //Bool
    }


    // print_label_response->tracking_number
    if(print_label_response->tracking_number) {
    if(cJSON_AddStringToObject(item, "tracking_number", print_label_response->tracking_number) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

print_label_response_t *print_label_response_parseFromJSON(cJSON *print_label_responseJSON){

    print_label_response_t *print_label_response_local_var = NULL;

    char *label_url_local_str = NULL;

    char *message_local_str = NULL;

    char *sscc_local_str = NULL;

    // define the local variable for print_label_response->success
    int *success_local_var = NULL;

    char *tracking_number_local_str = NULL;

    // print_label_response->label_url
    cJSON *label_url = cJSON_GetObjectItemCaseSensitive(print_label_responseJSON, "label_url");
    if (cJSON_IsNull(label_url)) {
        label_url = NULL;
    }
    if (label_url) { 
    if(!cJSON_IsString(label_url) && !cJSON_IsNull(label_url))
    {
    goto end; //String
    }
    }

    // print_label_response->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(print_label_responseJSON, "message");
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

    // print_label_response->sscc
    cJSON *sscc = cJSON_GetObjectItemCaseSensitive(print_label_responseJSON, "sscc");
    if (cJSON_IsNull(sscc)) {
        sscc = NULL;
    }
    if (sscc) { 
    if(!cJSON_IsString(sscc) && !cJSON_IsNull(sscc))
    {
    goto end; //String
    }
    }

    // print_label_response->success
    cJSON *success = cJSON_GetObjectItemCaseSensitive(print_label_responseJSON, "success");
    if (cJSON_IsNull(success)) {
        success = NULL;
    }
    if (!success) {
        goto end;
    }

    
    if(!cJSON_IsBool(success))
    {
    goto end; //Bool
    }
    success_local_var = malloc(sizeof(int));
    if(!success_local_var)
    {
        goto end;
    }
    *success_local_var = success->valueint;

    // print_label_response->tracking_number
    cJSON *tracking_number = cJSON_GetObjectItemCaseSensitive(print_label_responseJSON, "tracking_number");
    if (cJSON_IsNull(tracking_number)) {
        tracking_number = NULL;
    }
    if (tracking_number) { 
    if(!cJSON_IsString(tracking_number) && !cJSON_IsNull(tracking_number))
    {
    goto end; //String
    }
    }


    if (label_url && !cJSON_IsNull(label_url)) label_url_local_str = strdup(label_url->valuestring);
    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (sscc && !cJSON_IsNull(sscc)) sscc_local_str = strdup(sscc->valuestring);
    if (tracking_number && !cJSON_IsNull(tracking_number)) tracking_number_local_str = strdup(tracking_number->valuestring);

    print_label_response_local_var = print_label_response_create_internal (
        label_url_local_str,
        message_local_str,
        sscc_local_str,
        success_local_var,
        tracking_number_local_str
        );

    if (!print_label_response_local_var) {
        goto end;
    }

    return print_label_response_local_var;
end:
    if (label_url_local_str) {
        free(label_url_local_str);
        label_url_local_str = NULL;
    }
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    if (sscc_local_str) {
        free(sscc_local_str);
        sscc_local_str = NULL;
    }
    if (success_local_var) {
        free(success_local_var);
        success_local_var = NULL;
    }
    if (tracking_number_local_str) {
        free(tracking_number_local_str);
        tracking_number_local_str = NULL;
    }
    return NULL;

}
