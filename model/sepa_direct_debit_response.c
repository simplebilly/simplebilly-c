#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sepa_direct_debit_response.h"



static sepa_direct_debit_response_t *sepa_direct_debit_response_create_internal(
    char *content_type,
    char *filename,
    char *xml_content
    ) {
    sepa_direct_debit_response_t *sepa_direct_debit_response_local_var = malloc(sizeof(sepa_direct_debit_response_t));
    if (!sepa_direct_debit_response_local_var) {
        return NULL;
    }
    memset(sepa_direct_debit_response_local_var, 0, sizeof(sepa_direct_debit_response_t));
    sepa_direct_debit_response_local_var->_library_owned = 1;
    sepa_direct_debit_response_local_var->content_type = content_type;
    sepa_direct_debit_response_local_var->filename = filename;
    sepa_direct_debit_response_local_var->xml_content = xml_content;
    return sepa_direct_debit_response_local_var;
}

__attribute__((deprecated)) sepa_direct_debit_response_t *sepa_direct_debit_response_create(
    char *content_type,
    char *filename,
    char *xml_content
    ) {
    sepa_direct_debit_response_t *result = sepa_direct_debit_response_create_internal (
        content_type,
        filename,
        xml_content
        );
    if (!result) {
    }
    return result;
}

void sepa_direct_debit_response_free(sepa_direct_debit_response_t *sepa_direct_debit_response) {
    if(NULL == sepa_direct_debit_response){
        return ;
    }
    if(sepa_direct_debit_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "sepa_direct_debit_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (sepa_direct_debit_response->content_type) {
        free(sepa_direct_debit_response->content_type);
        sepa_direct_debit_response->content_type = NULL;
    }
    if (sepa_direct_debit_response->filename) {
        free(sepa_direct_debit_response->filename);
        sepa_direct_debit_response->filename = NULL;
    }
    if (sepa_direct_debit_response->xml_content) {
        free(sepa_direct_debit_response->xml_content);
        sepa_direct_debit_response->xml_content = NULL;
    }
    free(sepa_direct_debit_response);
}

cJSON *sepa_direct_debit_response_convertToJSON(sepa_direct_debit_response_t *sepa_direct_debit_response) {
    cJSON *item = cJSON_CreateObject();

    // sepa_direct_debit_response->content_type
    if (!sepa_direct_debit_response->content_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "content_type", sepa_direct_debit_response->content_type) == NULL) {
    goto fail; //String
    }


    // sepa_direct_debit_response->filename
    if (!sepa_direct_debit_response->filename) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "filename", sepa_direct_debit_response->filename) == NULL) {
    goto fail; //String
    }


    // sepa_direct_debit_response->xml_content
    if (!sepa_direct_debit_response->xml_content) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "xml_content", sepa_direct_debit_response->xml_content) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

sepa_direct_debit_response_t *sepa_direct_debit_response_parseFromJSON(cJSON *sepa_direct_debit_responseJSON){

    sepa_direct_debit_response_t *sepa_direct_debit_response_local_var = NULL;

    char *content_type_local_str = NULL;

    char *filename_local_str = NULL;

    char *xml_content_local_str = NULL;

    // sepa_direct_debit_response->content_type
    cJSON *content_type = cJSON_GetObjectItemCaseSensitive(sepa_direct_debit_responseJSON, "content_type");
    if (cJSON_IsNull(content_type)) {
        content_type = NULL;
    }
    if (!content_type) {
        goto end;
    }

    
    if(!cJSON_IsString(content_type))
    {
    goto end; //String
    }

    // sepa_direct_debit_response->filename
    cJSON *filename = cJSON_GetObjectItemCaseSensitive(sepa_direct_debit_responseJSON, "filename");
    if (cJSON_IsNull(filename)) {
        filename = NULL;
    }
    if (!filename) {
        goto end;
    }

    
    if(!cJSON_IsString(filename))
    {
    goto end; //String
    }

    // sepa_direct_debit_response->xml_content
    cJSON *xml_content = cJSON_GetObjectItemCaseSensitive(sepa_direct_debit_responseJSON, "xml_content");
    if (cJSON_IsNull(xml_content)) {
        xml_content = NULL;
    }
    if (!xml_content) {
        goto end;
    }

    
    if(!cJSON_IsString(xml_content))
    {
    goto end; //String
    }


    if (content_type && !cJSON_IsNull(content_type)) content_type_local_str = strdup(content_type->valuestring);
    if (filename && !cJSON_IsNull(filename)) filename_local_str = strdup(filename->valuestring);
    if (xml_content && !cJSON_IsNull(xml_content)) xml_content_local_str = strdup(xml_content->valuestring);

    sepa_direct_debit_response_local_var = sepa_direct_debit_response_create_internal (
        content_type_local_str,
        filename_local_str,
        xml_content_local_str
        );

    if (!sepa_direct_debit_response_local_var) {
        goto end;
    }

    return sepa_direct_debit_response_local_var;
end:
    if (content_type_local_str) {
        free(content_type_local_str);
        content_type_local_str = NULL;
    }
    if (filename_local_str) {
        free(filename_local_str);
        filename_local_str = NULL;
    }
    if (xml_content_local_str) {
        free(xml_content_local_str);
        xml_content_local_str = NULL;
    }
    return NULL;

}
