#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ai_suggestion_request.h"



static ai_suggestion_request_t *ai_suggestion_request_create_internal(
    char *instructions,
    char *message_body,
    char *ticket_id
    ) {
    ai_suggestion_request_t *ai_suggestion_request_local_var = malloc(sizeof(ai_suggestion_request_t));
    if (!ai_suggestion_request_local_var) {
        return NULL;
    }
    memset(ai_suggestion_request_local_var, 0, sizeof(ai_suggestion_request_t));
    ai_suggestion_request_local_var->_library_owned = 1;
    ai_suggestion_request_local_var->instructions = instructions;
    ai_suggestion_request_local_var->message_body = message_body;
    ai_suggestion_request_local_var->ticket_id = ticket_id;
    return ai_suggestion_request_local_var;
}

__attribute__((deprecated)) ai_suggestion_request_t *ai_suggestion_request_create(
    char *instructions,
    char *message_body,
    char *ticket_id
    ) {
    ai_suggestion_request_t *result = ai_suggestion_request_create_internal (
        instructions,
        message_body,
        ticket_id
        );
    if (!result) {
    }
    return result;
}

void ai_suggestion_request_free(ai_suggestion_request_t *ai_suggestion_request) {
    if(NULL == ai_suggestion_request){
        return ;
    }
    if(ai_suggestion_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ai_suggestion_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ai_suggestion_request->instructions) {
        free(ai_suggestion_request->instructions);
        ai_suggestion_request->instructions = NULL;
    }
    if (ai_suggestion_request->message_body) {
        free(ai_suggestion_request->message_body);
        ai_suggestion_request->message_body = NULL;
    }
    if (ai_suggestion_request->ticket_id) {
        free(ai_suggestion_request->ticket_id);
        ai_suggestion_request->ticket_id = NULL;
    }
    free(ai_suggestion_request);
}

cJSON *ai_suggestion_request_convertToJSON(ai_suggestion_request_t *ai_suggestion_request) {
    cJSON *item = cJSON_CreateObject();

    // ai_suggestion_request->instructions
    if(ai_suggestion_request->instructions) {
    if(cJSON_AddStringToObject(item, "instructions", ai_suggestion_request->instructions) == NULL) {
    goto fail; //String
    }
    }


    // ai_suggestion_request->message_body
    if(ai_suggestion_request->message_body) {
    if(cJSON_AddStringToObject(item, "message_body", ai_suggestion_request->message_body) == NULL) {
    goto fail; //String
    }
    }


    // ai_suggestion_request->ticket_id
    if (!ai_suggestion_request->ticket_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ticket_id", ai_suggestion_request->ticket_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ai_suggestion_request_t *ai_suggestion_request_parseFromJSON(cJSON *ai_suggestion_requestJSON){

    ai_suggestion_request_t *ai_suggestion_request_local_var = NULL;

    char *instructions_local_str = NULL;

    char *message_body_local_str = NULL;

    char *ticket_id_local_str = NULL;

    // ai_suggestion_request->instructions
    cJSON *instructions = cJSON_GetObjectItemCaseSensitive(ai_suggestion_requestJSON, "instructions");
    if (cJSON_IsNull(instructions)) {
        instructions = NULL;
    }
    if (instructions) { 
    if(!cJSON_IsString(instructions) && !cJSON_IsNull(instructions))
    {
    goto end; //String
    }
    }

    // ai_suggestion_request->message_body
    cJSON *message_body = cJSON_GetObjectItemCaseSensitive(ai_suggestion_requestJSON, "message_body");
    if (cJSON_IsNull(message_body)) {
        message_body = NULL;
    }
    if (message_body) { 
    if(!cJSON_IsString(message_body) && !cJSON_IsNull(message_body))
    {
    goto end; //String
    }
    }

    // ai_suggestion_request->ticket_id
    cJSON *ticket_id = cJSON_GetObjectItemCaseSensitive(ai_suggestion_requestJSON, "ticket_id");
    if (cJSON_IsNull(ticket_id)) {
        ticket_id = NULL;
    }
    if (!ticket_id) {
        goto end;
    }

    
    if(!cJSON_IsString(ticket_id))
    {
    goto end; //String
    }


    if (instructions && !cJSON_IsNull(instructions)) instructions_local_str = strdup(instructions->valuestring);
    if (message_body && !cJSON_IsNull(message_body)) message_body_local_str = strdup(message_body->valuestring);
    if (ticket_id && !cJSON_IsNull(ticket_id)) ticket_id_local_str = strdup(ticket_id->valuestring);

    ai_suggestion_request_local_var = ai_suggestion_request_create_internal (
        instructions_local_str,
        message_body_local_str,
        ticket_id_local_str
        );

    if (!ai_suggestion_request_local_var) {
        goto end;
    }

    return ai_suggestion_request_local_var;
end:
    if (instructions_local_str) {
        free(instructions_local_str);
        instructions_local_str = NULL;
    }
    if (message_body_local_str) {
        free(message_body_local_str);
        message_body_local_str = NULL;
    }
    if (ticket_id_local_str) {
        free(ticket_id_local_str);
        ticket_id_local_str = NULL;
    }
    return NULL;

}
