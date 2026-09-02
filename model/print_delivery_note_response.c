#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "print_delivery_note_response.h"



static print_delivery_note_response_t *print_delivery_note_response_create_internal(
    char *message,
    char *pdf_url,
    int *success
    ) {
    print_delivery_note_response_t *print_delivery_note_response_local_var = malloc(sizeof(print_delivery_note_response_t));
    if (!print_delivery_note_response_local_var) {
        return NULL;
    }
    memset(print_delivery_note_response_local_var, 0, sizeof(print_delivery_note_response_t));
    print_delivery_note_response_local_var->_library_owned = 1;
    print_delivery_note_response_local_var->message = message;
    print_delivery_note_response_local_var->pdf_url = pdf_url;
    print_delivery_note_response_local_var->success = success;
    return print_delivery_note_response_local_var;
}

__attribute__((deprecated)) print_delivery_note_response_t *print_delivery_note_response_create(
    char *message,
    char *pdf_url,
    int *success
    ) {
    int *success_copy = NULL;
    if (success) {
        success_copy = malloc(sizeof(int));
        if (success_copy) *success_copy = *success;
    }
    print_delivery_note_response_t *result = print_delivery_note_response_create_internal (
        message,
        pdf_url,
        success_copy
        );
    if (!result) {
        free(success_copy);
    }
    return result;
}

void print_delivery_note_response_free(print_delivery_note_response_t *print_delivery_note_response) {
    if(NULL == print_delivery_note_response){
        return ;
    }
    if(print_delivery_note_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "print_delivery_note_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (print_delivery_note_response->message) {
        free(print_delivery_note_response->message);
        print_delivery_note_response->message = NULL;
    }
    if (print_delivery_note_response->pdf_url) {
        free(print_delivery_note_response->pdf_url);
        print_delivery_note_response->pdf_url = NULL;
    }
    if (print_delivery_note_response->success) {
        free(print_delivery_note_response->success);
        print_delivery_note_response->success = NULL;
    }
    free(print_delivery_note_response);
}

cJSON *print_delivery_note_response_convertToJSON(print_delivery_note_response_t *print_delivery_note_response) {
    cJSON *item = cJSON_CreateObject();

    // print_delivery_note_response->message
    if (!print_delivery_note_response->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", print_delivery_note_response->message) == NULL) {
    goto fail; //String
    }


    // print_delivery_note_response->pdf_url
    if(print_delivery_note_response->pdf_url) {
    if(cJSON_AddStringToObject(item, "pdf_url", print_delivery_note_response->pdf_url) == NULL) {
    goto fail; //String
    }
    }


    // print_delivery_note_response->success
    if (!print_delivery_note_response->success) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "success", *print_delivery_note_response->success) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

print_delivery_note_response_t *print_delivery_note_response_parseFromJSON(cJSON *print_delivery_note_responseJSON){

    print_delivery_note_response_t *print_delivery_note_response_local_var = NULL;

    char *message_local_str = NULL;

    char *pdf_url_local_str = NULL;

    // define the local variable for print_delivery_note_response->success
    int *success_local_var = NULL;

    // print_delivery_note_response->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(print_delivery_note_responseJSON, "message");
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

    // print_delivery_note_response->pdf_url
    cJSON *pdf_url = cJSON_GetObjectItemCaseSensitive(print_delivery_note_responseJSON, "pdf_url");
    if (cJSON_IsNull(pdf_url)) {
        pdf_url = NULL;
    }
    if (pdf_url) { 
    if(!cJSON_IsString(pdf_url) && !cJSON_IsNull(pdf_url))
    {
    goto end; //String
    }
    }

    // print_delivery_note_response->success
    cJSON *success = cJSON_GetObjectItemCaseSensitive(print_delivery_note_responseJSON, "success");
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


    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (pdf_url && !cJSON_IsNull(pdf_url)) pdf_url_local_str = strdup(pdf_url->valuestring);

    print_delivery_note_response_local_var = print_delivery_note_response_create_internal (
        message_local_str,
        pdf_url_local_str,
        success_local_var
        );

    if (!print_delivery_note_response_local_var) {
        goto end;
    }

    return print_delivery_note_response_local_var;
end:
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    if (pdf_url_local_str) {
        free(pdf_url_local_str);
        pdf_url_local_str = NULL;
    }
    if (success_local_var) {
        free(success_local_var);
        success_local_var = NULL;
    }
    return NULL;

}
