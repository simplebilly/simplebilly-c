#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "track_order_request.h"



static track_order_request_t *track_order_request_create_internal(
    char *email,
    char *order_number
    ) {
    track_order_request_t *track_order_request_local_var = malloc(sizeof(track_order_request_t));
    if (!track_order_request_local_var) {
        return NULL;
    }
    memset(track_order_request_local_var, 0, sizeof(track_order_request_t));
    track_order_request_local_var->_library_owned = 1;
    track_order_request_local_var->email = email;
    track_order_request_local_var->order_number = order_number;
    return track_order_request_local_var;
}

__attribute__((deprecated)) track_order_request_t *track_order_request_create(
    char *email,
    char *order_number
    ) {
    track_order_request_t *result = track_order_request_create_internal (
        email,
        order_number
        );
    if (!result) {
    }
    return result;
}

void track_order_request_free(track_order_request_t *track_order_request) {
    if(NULL == track_order_request){
        return ;
    }
    if(track_order_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "track_order_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (track_order_request->email) {
        free(track_order_request->email);
        track_order_request->email = NULL;
    }
    if (track_order_request->order_number) {
        free(track_order_request->order_number);
        track_order_request->order_number = NULL;
    }
    free(track_order_request);
}

cJSON *track_order_request_convertToJSON(track_order_request_t *track_order_request) {
    cJSON *item = cJSON_CreateObject();

    // track_order_request->email
    if (!track_order_request->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", track_order_request->email) == NULL) {
    goto fail; //String
    }


    // track_order_request->order_number
    if (!track_order_request->order_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "order_number", track_order_request->order_number) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

track_order_request_t *track_order_request_parseFromJSON(cJSON *track_order_requestJSON){

    track_order_request_t *track_order_request_local_var = NULL;

    char *email_local_str = NULL;

    char *order_number_local_str = NULL;

    // track_order_request->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(track_order_requestJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (!email) {
        goto end;
    }

    
    if(!cJSON_IsString(email))
    {
    goto end; //String
    }

    // track_order_request->order_number
    cJSON *order_number = cJSON_GetObjectItemCaseSensitive(track_order_requestJSON, "order_number");
    if (cJSON_IsNull(order_number)) {
        order_number = NULL;
    }
    if (!order_number) {
        goto end;
    }

    
    if(!cJSON_IsString(order_number))
    {
    goto end; //String
    }


    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);
    if (order_number && !cJSON_IsNull(order_number)) order_number_local_str = strdup(order_number->valuestring);

    track_order_request_local_var = track_order_request_create_internal (
        email_local_str,
        order_number_local_str
        );

    if (!track_order_request_local_var) {
        goto end;
    }

    return track_order_request_local_var;
end:
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    if (order_number_local_str) {
        free(order_number_local_str);
        order_number_local_str = NULL;
    }
    return NULL;

}
