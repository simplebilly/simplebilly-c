#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "my_training_item.h"



static my_training_item_t *my_training_item_create_internal(
    char *assignment_id,
    char *certificate_id,
    char *code,
    char *description,
    char *due_date,
    int *last_score,
    int *pass_score,
    int *passed,
    simplebilly_api_assignment_status__e status,
    char *title,
    char *training_id,
    char *valid_until
    ) {
    my_training_item_t *my_training_item_local_var = malloc(sizeof(my_training_item_t));
    if (!my_training_item_local_var) {
        return NULL;
    }
    memset(my_training_item_local_var, 0, sizeof(my_training_item_t));
    my_training_item_local_var->_library_owned = 1;
    my_training_item_local_var->assignment_id = assignment_id;
    my_training_item_local_var->certificate_id = certificate_id;
    my_training_item_local_var->code = code;
    my_training_item_local_var->description = description;
    my_training_item_local_var->due_date = due_date;
    my_training_item_local_var->last_score = last_score;
    my_training_item_local_var->pass_score = pass_score;
    my_training_item_local_var->passed = passed;
    my_training_item_local_var->status = status;
    my_training_item_local_var->title = title;
    my_training_item_local_var->training_id = training_id;
    my_training_item_local_var->valid_until = valid_until;
    return my_training_item_local_var;
}

__attribute__((deprecated)) my_training_item_t *my_training_item_create(
    char *assignment_id,
    char *certificate_id,
    char *code,
    char *description,
    char *due_date,
    int *last_score,
    int *pass_score,
    int *passed,
    simplebilly_api_assignment_status__e status,
    char *title,
    char *training_id,
    char *valid_until
    ) {
    int *last_score_copy = NULL;
    if (last_score) {
        last_score_copy = malloc(sizeof(int));
        if (last_score_copy) *last_score_copy = *last_score;
    }
    int *pass_score_copy = NULL;
    if (pass_score) {
        pass_score_copy = malloc(sizeof(int));
        if (pass_score_copy) *pass_score_copy = *pass_score;
    }
    int *passed_copy = NULL;
    if (passed) {
        passed_copy = malloc(sizeof(int));
        if (passed_copy) *passed_copy = *passed;
    }
    my_training_item_t *result = my_training_item_create_internal (
        assignment_id,
        certificate_id,
        code,
        description,
        due_date,
        last_score_copy,
        pass_score_copy,
        passed_copy,
        status,
        title,
        training_id,
        valid_until
        );
    if (!result) {
        free(last_score_copy);
        free(pass_score_copy);
        free(passed_copy);
    }
    return result;
}

void my_training_item_free(my_training_item_t *my_training_item) {
    if(NULL == my_training_item){
        return ;
    }
    if(my_training_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "my_training_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (my_training_item->assignment_id) {
        free(my_training_item->assignment_id);
        my_training_item->assignment_id = NULL;
    }
    if (my_training_item->certificate_id) {
        free(my_training_item->certificate_id);
        my_training_item->certificate_id = NULL;
    }
    if (my_training_item->code) {
        free(my_training_item->code);
        my_training_item->code = NULL;
    }
    if (my_training_item->description) {
        free(my_training_item->description);
        my_training_item->description = NULL;
    }
    if (my_training_item->due_date) {
        free(my_training_item->due_date);
        my_training_item->due_date = NULL;
    }
    if (my_training_item->last_score) {
        free(my_training_item->last_score);
        my_training_item->last_score = NULL;
    }
    if (my_training_item->pass_score) {
        free(my_training_item->pass_score);
        my_training_item->pass_score = NULL;
    }
    if (my_training_item->passed) {
        free(my_training_item->passed);
        my_training_item->passed = NULL;
    }
    if (my_training_item->title) {
        free(my_training_item->title);
        my_training_item->title = NULL;
    }
    if (my_training_item->training_id) {
        free(my_training_item->training_id);
        my_training_item->training_id = NULL;
    }
    if (my_training_item->valid_until) {
        free(my_training_item->valid_until);
        my_training_item->valid_until = NULL;
    }
    free(my_training_item);
}

cJSON *my_training_item_convertToJSON(my_training_item_t *my_training_item) {
    cJSON *item = cJSON_CreateObject();

    // my_training_item->assignment_id
    if (!my_training_item->assignment_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "assignmentId", my_training_item->assignment_id) == NULL) {
    goto fail; //String
    }


    // my_training_item->certificate_id
    if(my_training_item->certificate_id) {
    if(cJSON_AddStringToObject(item, "certificateId", my_training_item->certificate_id) == NULL) {
    goto fail; //String
    }
    }


    // my_training_item->code
    if (!my_training_item->code) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "code", my_training_item->code) == NULL) {
    goto fail; //String
    }


    // my_training_item->description
    if(my_training_item->description) {
    if(cJSON_AddStringToObject(item, "description", my_training_item->description) == NULL) {
    goto fail; //String
    }
    }


    // my_training_item->due_date
    if(my_training_item->due_date) {
    if(cJSON_AddStringToObject(item, "dueDate", my_training_item->due_date) == NULL) {
    goto fail; //Date
    }
    }


    // my_training_item->last_score
    if(my_training_item->last_score) {
    if(cJSON_AddNumberToObject(item, "lastScore", *my_training_item->last_score) == NULL) {
    goto fail; //Numeric
    }
    }


    // my_training_item->pass_score
    if (!my_training_item->pass_score) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "passScore", *my_training_item->pass_score) == NULL) {
    goto fail; //Numeric
    }


    // my_training_item->passed
    if(my_training_item->passed) {
    if(cJSON_AddBoolToObject(item, "passed", *my_training_item->passed) == NULL) {
    goto fail; //Bool
    }
    }


    // my_training_item->status
    if (simplebilly_api_assignment_status__NULL == my_training_item->status) {
        goto fail;
    }
    cJSON *status_local_JSON = assignment_status_convertToJSON(my_training_item->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // my_training_item->title
    if (!my_training_item->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", my_training_item->title) == NULL) {
    goto fail; //String
    }


    // my_training_item->training_id
    if (!my_training_item->training_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "trainingId", my_training_item->training_id) == NULL) {
    goto fail; //String
    }


    // my_training_item->valid_until
    if(my_training_item->valid_until) {
    if(cJSON_AddStringToObject(item, "validUntil", my_training_item->valid_until) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

my_training_item_t *my_training_item_parseFromJSON(cJSON *my_training_itemJSON){

    my_training_item_t *my_training_item_local_var = NULL;

    char *assignment_id_local_str = NULL;

    char *certificate_id_local_str = NULL;

    char *code_local_str = NULL;

    char *description_local_str = NULL;

    char *due_date_local_str = NULL;

    // define the local variable for my_training_item->last_score
    int *last_score_local_var = NULL;

    // define the local variable for my_training_item->pass_score
    int *pass_score_local_var = NULL;

    // define the local variable for my_training_item->passed
    int *passed_local_var = NULL;

    // define the local variable for my_training_item->status
    simplebilly_api_assignment_status__e status_local_nonprim = 0;

    char *title_local_str = NULL;

    char *training_id_local_str = NULL;

    char *valid_until_local_str = NULL;

    // my_training_item->assignment_id
    cJSON *assignment_id = cJSON_GetObjectItemCaseSensitive(my_training_itemJSON, "assignmentId");
    if (cJSON_IsNull(assignment_id)) {
        assignment_id = NULL;
    }
    if (!assignment_id) {
        goto end;
    }

    
    if(!cJSON_IsString(assignment_id))
    {
    goto end; //String
    }

    // my_training_item->certificate_id
    cJSON *certificate_id = cJSON_GetObjectItemCaseSensitive(my_training_itemJSON, "certificateId");
    if (cJSON_IsNull(certificate_id)) {
        certificate_id = NULL;
    }
    if (certificate_id) { 
    if(!cJSON_IsString(certificate_id) && !cJSON_IsNull(certificate_id))
    {
    goto end; //String
    }
    }

    // my_training_item->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(my_training_itemJSON, "code");
    if (cJSON_IsNull(code)) {
        code = NULL;
    }
    if (!code) {
        goto end;
    }

    
    if(!cJSON_IsString(code))
    {
    goto end; //String
    }

    // my_training_item->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(my_training_itemJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // my_training_item->due_date
    cJSON *due_date = cJSON_GetObjectItemCaseSensitive(my_training_itemJSON, "dueDate");
    if (cJSON_IsNull(due_date)) {
        due_date = NULL;
    }
    if (due_date) { 
    if(!cJSON_IsString(due_date))
    {
    goto end; //Date
    }
    }

    // my_training_item->last_score
    cJSON *last_score = cJSON_GetObjectItemCaseSensitive(my_training_itemJSON, "lastScore");
    if (cJSON_IsNull(last_score)) {
        last_score = NULL;
    }
    if (last_score) { 
    if(!cJSON_IsNumber(last_score))
    {
    goto end; //Numeric
    }
    last_score_local_var = malloc(sizeof(int));
    if(!last_score_local_var)
    {
        goto end;
    }
    *last_score_local_var = last_score->valuedouble;
    }

    // my_training_item->pass_score
    cJSON *pass_score = cJSON_GetObjectItemCaseSensitive(my_training_itemJSON, "passScore");
    if (cJSON_IsNull(pass_score)) {
        pass_score = NULL;
    }
    if (!pass_score) {
        goto end;
    }

    
    if(!cJSON_IsNumber(pass_score))
    {
    goto end; //Numeric
    }
    pass_score_local_var = malloc(sizeof(int));
    if(!pass_score_local_var)
    {
        goto end;
    }
    *pass_score_local_var = pass_score->valuedouble;

    // my_training_item->passed
    cJSON *passed = cJSON_GetObjectItemCaseSensitive(my_training_itemJSON, "passed");
    if (cJSON_IsNull(passed)) {
        passed = NULL;
    }
    if (passed) { 
    if(!cJSON_IsBool(passed))
    {
    goto end; //Bool
    }
    passed_local_var = malloc(sizeof(int));
    if(!passed_local_var)
    {
        goto end;
    }
    *passed_local_var = passed->valueint;
    }

    // my_training_item->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(my_training_itemJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = assignment_status_parseFromJSON(status); //custom

    // my_training_item->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(my_training_itemJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (!title) {
        goto end;
    }

    
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }

    // my_training_item->training_id
    cJSON *training_id = cJSON_GetObjectItemCaseSensitive(my_training_itemJSON, "trainingId");
    if (cJSON_IsNull(training_id)) {
        training_id = NULL;
    }
    if (!training_id) {
        goto end;
    }

    
    if(!cJSON_IsString(training_id))
    {
    goto end; //String
    }

    // my_training_item->valid_until
    cJSON *valid_until = cJSON_GetObjectItemCaseSensitive(my_training_itemJSON, "validUntil");
    if (cJSON_IsNull(valid_until)) {
        valid_until = NULL;
    }
    if (valid_until) { 
    if(!cJSON_IsString(valid_until) && !cJSON_IsNull(valid_until))
    {
    goto end; //DateTime
    }
    }


    if (assignment_id && !cJSON_IsNull(assignment_id)) assignment_id_local_str = strdup(assignment_id->valuestring);
    if (certificate_id && !cJSON_IsNull(certificate_id)) certificate_id_local_str = strdup(certificate_id->valuestring);
    if (code && !cJSON_IsNull(code)) code_local_str = strdup(code->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (due_date) due_date_local_str = strdup(due_date->valuestring);
    if (title && !cJSON_IsNull(title)) title_local_str = strdup(title->valuestring);
    if (training_id && !cJSON_IsNull(training_id)) training_id_local_str = strdup(training_id->valuestring);
    if (valid_until && !cJSON_IsNull(valid_until)) valid_until_local_str = strdup(valid_until->valuestring);

    my_training_item_local_var = my_training_item_create_internal (
        assignment_id_local_str,
        certificate_id_local_str,
        code_local_str,
        description_local_str,
        due_date_local_str,
        last_score_local_var,
        pass_score_local_var,
        passed_local_var,
        status_local_nonprim,
        title_local_str,
        training_id_local_str,
        valid_until_local_str
        );

    if (!my_training_item_local_var) {
        goto end;
    }

    return my_training_item_local_var;
end:
    if (assignment_id_local_str) {
        free(assignment_id_local_str);
        assignment_id_local_str = NULL;
    }
    if (certificate_id_local_str) {
        free(certificate_id_local_str);
        certificate_id_local_str = NULL;
    }
    if (code_local_str) {
        free(code_local_str);
        code_local_str = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (due_date_local_str) {
        free(due_date_local_str);
        due_date_local_str = NULL;
    }
    if (last_score_local_var) {
        free(last_score_local_var);
        last_score_local_var = NULL;
    }
    if (pass_score_local_var) {
        free(pass_score_local_var);
        pass_score_local_var = NULL;
    }
    if (passed_local_var) {
        free(passed_local_var);
        passed_local_var = NULL;
    }
    if (status_local_nonprim) {
        status_local_nonprim = 0;
    }
    if (title_local_str) {
        free(title_local_str);
        title_local_str = NULL;
    }
    if (training_id_local_str) {
        free(training_id_local_str);
        training_id_local_str = NULL;
    }
    if (valid_until_local_str) {
        free(valid_until_local_str);
        valid_until_local_str = NULL;
    }
    return NULL;

}
