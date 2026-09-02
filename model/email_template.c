#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "email_template.h"



static email_template_t *email_template_create_internal(
    char *body,
    char *name,
    email_template_status_t *status,
    char *subject,
    any_type_t *variables
    ) {
    email_template_t *email_template_local_var = malloc(sizeof(email_template_t));
    if (!email_template_local_var) {
        return NULL;
    }
    memset(email_template_local_var, 0, sizeof(email_template_t));
    email_template_local_var->_library_owned = 1;
    email_template_local_var->body = body;
    email_template_local_var->name = name;
    email_template_local_var->status = status;
    email_template_local_var->subject = subject;
    email_template_local_var->variables = variables;
    return email_template_local_var;
}

__attribute__((deprecated)) email_template_t *email_template_create(
    char *body,
    char *name,
    email_template_status_t *status,
    char *subject,
    any_type_t *variables
    ) {
    email_template_t *result = email_template_create_internal (
        body,
        name,
        status,
        subject,
        variables
        );
    if (!result) {
    }
    return result;
}

void email_template_free(email_template_t *email_template) {
    if(NULL == email_template){
        return ;
    }
    if(email_template->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "email_template_free");
        return ;
    }
    listEntry_t *listEntry;
    if (email_template->body) {
        free(email_template->body);
        email_template->body = NULL;
    }
    if (email_template->name) {
        free(email_template->name);
        email_template->name = NULL;
    }
    if (email_template->status) {
        email_template_status_free(email_template->status);
        email_template->status = NULL;
    }
    if (email_template->subject) {
        free(email_template->subject);
        email_template->subject = NULL;
    }
    if (email_template->variables) {
        _free(email_template->variables);
        email_template->variables = NULL;
    }
    free(email_template);
}

cJSON *email_template_convertToJSON(email_template_t *email_template) {
    cJSON *item = cJSON_CreateObject();

    // email_template->body
    if (!email_template->body) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "body", email_template->body) == NULL) {
    goto fail; //String
    }


    // email_template->name
    if (!email_template->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", email_template->name) == NULL) {
    goto fail; //String
    }


    // email_template->status
    if (!email_template->status) {
        goto fail;
    }
    cJSON *status_local_JSON = email_template_status_convertToJSON(email_template->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // email_template->subject
    if (!email_template->subject) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "subject", email_template->subject) == NULL) {
    goto fail; //String
    }


    // email_template->variables
    if(email_template->variables) {
    cJSON *variables_local_JSON = _convertToJSON(email_template->variables);
    if(variables_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "variables", variables_local_JSON);
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

email_template_t *email_template_parseFromJSON(cJSON *email_templateJSON){

    email_template_t *email_template_local_var = NULL;

    char *body_local_str = NULL;

    char *name_local_str = NULL;

    // define the local variable for email_template->status
    email_template_status_t *status_local_nonprim = NULL;

    char *subject_local_str = NULL;

    // define the local variable for email_template->variables
    _t *variables_local_nonprim = NULL;

    // email_template->body
    cJSON *body = cJSON_GetObjectItemCaseSensitive(email_templateJSON, "body");
    if (cJSON_IsNull(body)) {
        body = NULL;
    }
    if (!body) {
        goto end;
    }

    
    if(!cJSON_IsString(body))
    {
    goto end; //String
    }

    // email_template->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(email_templateJSON, "name");
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

    // email_template->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(email_templateJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = email_template_status_parseFromJSON(status); //custom

    // email_template->subject
    cJSON *subject = cJSON_GetObjectItemCaseSensitive(email_templateJSON, "subject");
    if (cJSON_IsNull(subject)) {
        subject = NULL;
    }
    if (!subject) {
        goto end;
    }

    
    if(!cJSON_IsString(subject))
    {
    goto end; //String
    }

    // email_template->variables
    cJSON *variables = cJSON_GetObjectItemCaseSensitive(email_templateJSON, "variables");
    if (cJSON_IsNull(variables)) {
        variables = NULL;
    }
    if (variables) { 
    variables_local_nonprim = _parseFromJSON(variables); //custom
    }


    if (body && !cJSON_IsNull(body)) body_local_str = strdup(body->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (subject && !cJSON_IsNull(subject)) subject_local_str = strdup(subject->valuestring);

    email_template_local_var = email_template_create_internal (
        body_local_str,
        name_local_str,
        status_local_nonprim,
        subject_local_str,
        variables ? variables_local_nonprim : NULL
        );

    if (!email_template_local_var) {
        goto end;
    }

    return email_template_local_var;
end:
    if (body_local_str) {
        free(body_local_str);
        body_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (status_local_nonprim) {
        email_template_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    if (subject_local_str) {
        free(subject_local_str);
        subject_local_str = NULL;
    }
    if (variables_local_nonprim) {
        _free(variables_local_nonprim);
        variables_local_nonprim = NULL;
    }
    return NULL;

}
