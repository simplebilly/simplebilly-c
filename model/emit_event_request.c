#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "emit_event_request.h"



static emit_event_request_t *emit_event_request_create_internal(
    char *event_type,
    any_type_t *payload
    ) {
    emit_event_request_t *emit_event_request_local_var = malloc(sizeof(emit_event_request_t));
    if (!emit_event_request_local_var) {
        return NULL;
    }
    memset(emit_event_request_local_var, 0, sizeof(emit_event_request_t));
    emit_event_request_local_var->_library_owned = 1;
    emit_event_request_local_var->event_type = event_type;
    emit_event_request_local_var->payload = payload;
    return emit_event_request_local_var;
}

__attribute__((deprecated)) emit_event_request_t *emit_event_request_create(
    char *event_type,
    any_type_t *payload
    ) {
    emit_event_request_t *result = emit_event_request_create_internal (
        event_type,
        payload
        );
    if (!result) {
    }
    return result;
}

void emit_event_request_free(emit_event_request_t *emit_event_request) {
    if(NULL == emit_event_request){
        return ;
    }
    if(emit_event_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "emit_event_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (emit_event_request->event_type) {
        free(emit_event_request->event_type);
        emit_event_request->event_type = NULL;
    }
    if (emit_event_request->payload) {
        _free(emit_event_request->payload);
        emit_event_request->payload = NULL;
    }
    free(emit_event_request);
}

cJSON *emit_event_request_convertToJSON(emit_event_request_t *emit_event_request) {
    cJSON *item = cJSON_CreateObject();

    // emit_event_request->event_type
    if (!emit_event_request->event_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "event_type", emit_event_request->event_type) == NULL) {
    goto fail; //String
    }


    // emit_event_request->payload
    if(emit_event_request->payload) {
    cJSON *payload_local_JSON = _convertToJSON(emit_event_request->payload);
    if(payload_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "payload", payload_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

emit_event_request_t *emit_event_request_parseFromJSON(cJSON *emit_event_requestJSON){

    emit_event_request_t *emit_event_request_local_var = NULL;

    char *event_type_local_str = NULL;

    // define the local variable for emit_event_request->payload
    _t *payload_local_nonprim = NULL;

    // emit_event_request->event_type
    cJSON *event_type = cJSON_GetObjectItemCaseSensitive(emit_event_requestJSON, "event_type");
    if (cJSON_IsNull(event_type)) {
        event_type = NULL;
    }
    if (!event_type) {
        goto end;
    }

    
    if(!cJSON_IsString(event_type))
    {
    goto end; //String
    }

    // emit_event_request->payload
    cJSON *payload = cJSON_GetObjectItemCaseSensitive(emit_event_requestJSON, "payload");
    if (cJSON_IsNull(payload)) {
        payload = NULL;
    }
    if (payload) { 
    payload_local_nonprim = _parseFromJSON(payload); //custom
    }


    if (event_type && !cJSON_IsNull(event_type)) event_type_local_str = strdup(event_type->valuestring);

    emit_event_request_local_var = emit_event_request_create_internal (
        event_type_local_str,
        payload ? payload_local_nonprim : NULL
        );

    if (!emit_event_request_local_var) {
        goto end;
    }

    return emit_event_request_local_var;
end:
    if (event_type_local_str) {
        free(event_type_local_str);
        event_type_local_str = NULL;
    }
    if (payload_local_nonprim) {
        _free(payload_local_nonprim);
        payload_local_nonprim = NULL;
    }
    return NULL;

}
