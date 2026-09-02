#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ocr_text_request.h"



static ocr_text_request_t *ocr_text_request_create_internal(
    char *ocr_text
    ) {
    ocr_text_request_t *ocr_text_request_local_var = malloc(sizeof(ocr_text_request_t));
    if (!ocr_text_request_local_var) {
        return NULL;
    }
    memset(ocr_text_request_local_var, 0, sizeof(ocr_text_request_t));
    ocr_text_request_local_var->_library_owned = 1;
    ocr_text_request_local_var->ocr_text = ocr_text;
    return ocr_text_request_local_var;
}

__attribute__((deprecated)) ocr_text_request_t *ocr_text_request_create(
    char *ocr_text
    ) {
    ocr_text_request_t *result = ocr_text_request_create_internal (
        ocr_text
        );
    if (!result) {
    }
    return result;
}

void ocr_text_request_free(ocr_text_request_t *ocr_text_request) {
    if(NULL == ocr_text_request){
        return ;
    }
    if(ocr_text_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ocr_text_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ocr_text_request->ocr_text) {
        free(ocr_text_request->ocr_text);
        ocr_text_request->ocr_text = NULL;
    }
    free(ocr_text_request);
}

cJSON *ocr_text_request_convertToJSON(ocr_text_request_t *ocr_text_request) {
    cJSON *item = cJSON_CreateObject();

    // ocr_text_request->ocr_text
    if(ocr_text_request->ocr_text) {
    if(cJSON_AddStringToObject(item, "ocrText", ocr_text_request->ocr_text) == NULL) {
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

ocr_text_request_t *ocr_text_request_parseFromJSON(cJSON *ocr_text_requestJSON){

    ocr_text_request_t *ocr_text_request_local_var = NULL;

    char *ocr_text_local_str = NULL;

    // ocr_text_request->ocr_text
    cJSON *ocr_text = cJSON_GetObjectItemCaseSensitive(ocr_text_requestJSON, "ocrText");
    if (cJSON_IsNull(ocr_text)) {
        ocr_text = NULL;
    }
    if (ocr_text) { 
    if(!cJSON_IsString(ocr_text) && !cJSON_IsNull(ocr_text))
    {
    goto end; //String
    }
    }


    if (ocr_text && !cJSON_IsNull(ocr_text)) ocr_text_local_str = strdup(ocr_text->valuestring);

    ocr_text_request_local_var = ocr_text_request_create_internal (
        ocr_text_local_str
        );

    if (!ocr_text_request_local_var) {
        goto end;
    }

    return ocr_text_request_local_var;
end:
    if (ocr_text_local_str) {
        free(ocr_text_local_str);
        ocr_text_local_str = NULL;
    }
    return NULL;

}
