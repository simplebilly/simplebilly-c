#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "submit_result_response.h"



static submit_result_response_t *submit_result_response_create_internal(
    char *certificate_id,
    char *completion_id,
    int *pass_score,
    int *passed,
    int *score,
    char *valid_until
    ) {
    submit_result_response_t *submit_result_response_local_var = malloc(sizeof(submit_result_response_t));
    if (!submit_result_response_local_var) {
        return NULL;
    }
    memset(submit_result_response_local_var, 0, sizeof(submit_result_response_t));
    submit_result_response_local_var->_library_owned = 1;
    submit_result_response_local_var->certificate_id = certificate_id;
    submit_result_response_local_var->completion_id = completion_id;
    submit_result_response_local_var->pass_score = pass_score;
    submit_result_response_local_var->passed = passed;
    submit_result_response_local_var->score = score;
    submit_result_response_local_var->valid_until = valid_until;
    return submit_result_response_local_var;
}

__attribute__((deprecated)) submit_result_response_t *submit_result_response_create(
    char *certificate_id,
    char *completion_id,
    int *pass_score,
    int *passed,
    int *score,
    char *valid_until
    ) {
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
    int *score_copy = NULL;
    if (score) {
        score_copy = malloc(sizeof(int));
        if (score_copy) *score_copy = *score;
    }
    submit_result_response_t *result = submit_result_response_create_internal (
        certificate_id,
        completion_id,
        pass_score_copy,
        passed_copy,
        score_copy,
        valid_until
        );
    if (!result) {
        free(pass_score_copy);
        free(passed_copy);
        free(score_copy);
    }
    return result;
}

void submit_result_response_free(submit_result_response_t *submit_result_response) {
    if(NULL == submit_result_response){
        return ;
    }
    if(submit_result_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "submit_result_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (submit_result_response->certificate_id) {
        free(submit_result_response->certificate_id);
        submit_result_response->certificate_id = NULL;
    }
    if (submit_result_response->completion_id) {
        free(submit_result_response->completion_id);
        submit_result_response->completion_id = NULL;
    }
    if (submit_result_response->pass_score) {
        free(submit_result_response->pass_score);
        submit_result_response->pass_score = NULL;
    }
    if (submit_result_response->passed) {
        free(submit_result_response->passed);
        submit_result_response->passed = NULL;
    }
    if (submit_result_response->score) {
        free(submit_result_response->score);
        submit_result_response->score = NULL;
    }
    if (submit_result_response->valid_until) {
        free(submit_result_response->valid_until);
        submit_result_response->valid_until = NULL;
    }
    free(submit_result_response);
}

cJSON *submit_result_response_convertToJSON(submit_result_response_t *submit_result_response) {
    cJSON *item = cJSON_CreateObject();

    // submit_result_response->certificate_id
    if(submit_result_response->certificate_id) {
    if(cJSON_AddStringToObject(item, "certificateId", submit_result_response->certificate_id) == NULL) {
    goto fail; //String
    }
    }


    // submit_result_response->completion_id
    if (!submit_result_response->completion_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "completionId", submit_result_response->completion_id) == NULL) {
    goto fail; //String
    }


    // submit_result_response->pass_score
    if (!submit_result_response->pass_score) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "passScore", *submit_result_response->pass_score) == NULL) {
    goto fail; //Numeric
    }


    // submit_result_response->passed
    if (!submit_result_response->passed) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "passed", *submit_result_response->passed) == NULL) {
    goto fail; //Bool
    }


    // submit_result_response->score
    if (!submit_result_response->score) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "score", *submit_result_response->score) == NULL) {
    goto fail; //Numeric
    }


    // submit_result_response->valid_until
    if(submit_result_response->valid_until) {
    if(cJSON_AddStringToObject(item, "validUntil", submit_result_response->valid_until) == NULL) {
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

submit_result_response_t *submit_result_response_parseFromJSON(cJSON *submit_result_responseJSON){

    submit_result_response_t *submit_result_response_local_var = NULL;

    char *certificate_id_local_str = NULL;

    char *completion_id_local_str = NULL;

    // define the local variable for submit_result_response->pass_score
    int *pass_score_local_var = NULL;

    // define the local variable for submit_result_response->passed
    int *passed_local_var = NULL;

    // define the local variable for submit_result_response->score
    int *score_local_var = NULL;

    char *valid_until_local_str = NULL;

    // submit_result_response->certificate_id
    cJSON *certificate_id = cJSON_GetObjectItemCaseSensitive(submit_result_responseJSON, "certificateId");
    if (cJSON_IsNull(certificate_id)) {
        certificate_id = NULL;
    }
    if (certificate_id) { 
    if(!cJSON_IsString(certificate_id) && !cJSON_IsNull(certificate_id))
    {
    goto end; //String
    }
    }

    // submit_result_response->completion_id
    cJSON *completion_id = cJSON_GetObjectItemCaseSensitive(submit_result_responseJSON, "completionId");
    if (cJSON_IsNull(completion_id)) {
        completion_id = NULL;
    }
    if (!completion_id) {
        goto end;
    }

    
    if(!cJSON_IsString(completion_id))
    {
    goto end; //String
    }

    // submit_result_response->pass_score
    cJSON *pass_score = cJSON_GetObjectItemCaseSensitive(submit_result_responseJSON, "passScore");
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

    // submit_result_response->passed
    cJSON *passed = cJSON_GetObjectItemCaseSensitive(submit_result_responseJSON, "passed");
    if (cJSON_IsNull(passed)) {
        passed = NULL;
    }
    if (!passed) {
        goto end;
    }

    
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

    // submit_result_response->score
    cJSON *score = cJSON_GetObjectItemCaseSensitive(submit_result_responseJSON, "score");
    if (cJSON_IsNull(score)) {
        score = NULL;
    }
    if (!score) {
        goto end;
    }

    
    if(!cJSON_IsNumber(score))
    {
    goto end; //Numeric
    }
    score_local_var = malloc(sizeof(int));
    if(!score_local_var)
    {
        goto end;
    }
    *score_local_var = score->valuedouble;

    // submit_result_response->valid_until
    cJSON *valid_until = cJSON_GetObjectItemCaseSensitive(submit_result_responseJSON, "validUntil");
    if (cJSON_IsNull(valid_until)) {
        valid_until = NULL;
    }
    if (valid_until) { 
    if(!cJSON_IsString(valid_until) && !cJSON_IsNull(valid_until))
    {
    goto end; //DateTime
    }
    }


    if (certificate_id && !cJSON_IsNull(certificate_id)) certificate_id_local_str = strdup(certificate_id->valuestring);
    if (completion_id && !cJSON_IsNull(completion_id)) completion_id_local_str = strdup(completion_id->valuestring);
    if (valid_until && !cJSON_IsNull(valid_until)) valid_until_local_str = strdup(valid_until->valuestring);

    submit_result_response_local_var = submit_result_response_create_internal (
        certificate_id_local_str,
        completion_id_local_str,
        pass_score_local_var,
        passed_local_var,
        score_local_var,
        valid_until_local_str
        );

    if (!submit_result_response_local_var) {
        goto end;
    }

    return submit_result_response_local_var;
end:
    if (certificate_id_local_str) {
        free(certificate_id_local_str);
        certificate_id_local_str = NULL;
    }
    if (completion_id_local_str) {
        free(completion_id_local_str);
        completion_id_local_str = NULL;
    }
    if (pass_score_local_var) {
        free(pass_score_local_var);
        pass_score_local_var = NULL;
    }
    if (passed_local_var) {
        free(passed_local_var);
        passed_local_var = NULL;
    }
    if (score_local_var) {
        free(score_local_var);
        score_local_var = NULL;
    }
    if (valid_until_local_str) {
        free(valid_until_local_str);
        valid_until_local_str = NULL;
    }
    return NULL;

}
