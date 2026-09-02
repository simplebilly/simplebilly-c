#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "submit_result_dto.h"



static submit_result_dto_t *submit_result_dto_create_internal(
    list_t *answers,
    char *assignment_id,
    int *score,
    char *training_code
    ) {
    submit_result_dto_t *submit_result_dto_local_var = malloc(sizeof(submit_result_dto_t));
    if (!submit_result_dto_local_var) {
        return NULL;
    }
    memset(submit_result_dto_local_var, 0, sizeof(submit_result_dto_t));
    submit_result_dto_local_var->_library_owned = 1;
    submit_result_dto_local_var->answers = answers;
    submit_result_dto_local_var->assignment_id = assignment_id;
    submit_result_dto_local_var->score = score;
    submit_result_dto_local_var->training_code = training_code;
    return submit_result_dto_local_var;
}

__attribute__((deprecated)) submit_result_dto_t *submit_result_dto_create(
    list_t *answers,
    char *assignment_id,
    int *score,
    char *training_code
    ) {
    int *score_copy = NULL;
    if (score) {
        score_copy = malloc(sizeof(int));
        if (score_copy) *score_copy = *score;
    }
    submit_result_dto_t *result = submit_result_dto_create_internal (
        answers,
        assignment_id,
        score_copy,
        training_code
        );
    if (!result) {
        free(score_copy);
    }
    return result;
}

void submit_result_dto_free(submit_result_dto_t *submit_result_dto) {
    if(NULL == submit_result_dto){
        return ;
    }
    if(submit_result_dto->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "submit_result_dto_free");
        return ;
    }
    listEntry_t *listEntry;
    if (submit_result_dto->answers) {
        list_ForEach(listEntry, submit_result_dto->answers) {
            free(listEntry->data);
        }
        list_freeList(submit_result_dto->answers);
        submit_result_dto->answers = NULL;
    }
    if (submit_result_dto->assignment_id) {
        free(submit_result_dto->assignment_id);
        submit_result_dto->assignment_id = NULL;
    }
    if (submit_result_dto->score) {
        free(submit_result_dto->score);
        submit_result_dto->score = NULL;
    }
    if (submit_result_dto->training_code) {
        free(submit_result_dto->training_code);
        submit_result_dto->training_code = NULL;
    }
    free(submit_result_dto);
}

cJSON *submit_result_dto_convertToJSON(submit_result_dto_t *submit_result_dto) {
    cJSON *item = cJSON_CreateObject();

    // submit_result_dto->answers
    if (!submit_result_dto->answers) {
        goto fail;
    }
    cJSON *answers = cJSON_AddArrayToObject(item, "answers");
    if(answers == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *answersListEntry;
    list_ForEach(answersListEntry, submit_result_dto->answers) {
    if(cJSON_AddNumberToObject(answers, "", *(double *)answersListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // submit_result_dto->assignment_id
    if(submit_result_dto->assignment_id) {
    if(cJSON_AddStringToObject(item, "assignmentId", submit_result_dto->assignment_id) == NULL) {
    goto fail; //String
    }
    }


    // submit_result_dto->score
    if (!submit_result_dto->score) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "score", *submit_result_dto->score) == NULL) {
    goto fail; //Numeric
    }


    // submit_result_dto->training_code
    if (!submit_result_dto->training_code) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "trainingCode", submit_result_dto->training_code) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

submit_result_dto_t *submit_result_dto_parseFromJSON(cJSON *submit_result_dtoJSON){

    submit_result_dto_t *submit_result_dto_local_var = NULL;

    // define the local list for submit_result_dto->answers
    list_t *answersList = NULL;

    char *assignment_id_local_str = NULL;

    // define the local variable for submit_result_dto->score
    int *score_local_var = NULL;

    char *training_code_local_str = NULL;

    // submit_result_dto->answers
    cJSON *answers = cJSON_GetObjectItemCaseSensitive(submit_result_dtoJSON, "answers");
    if (cJSON_IsNull(answers)) {
        answers = NULL;
    }
    if (!answers) {
        goto end;
    }

    
    cJSON *answers_local = NULL;
    if(!cJSON_IsArray(answers)) {
        goto end;//primitive container
    }
    answersList = list_createList();

    cJSON_ArrayForEach(answers_local, answers)
    {
        if(!cJSON_IsNumber(answers_local))
        {
            goto end;
        }
        double *answers_local_value = calloc(1, sizeof(double));
        if(!answers_local_value)
        {
            goto end;
        }
        *answers_local_value = answers_local->valuedouble;
        list_addElement(answersList , answers_local_value);
    }

    // submit_result_dto->assignment_id
    cJSON *assignment_id = cJSON_GetObjectItemCaseSensitive(submit_result_dtoJSON, "assignmentId");
    if (cJSON_IsNull(assignment_id)) {
        assignment_id = NULL;
    }
    if (assignment_id) { 
    if(!cJSON_IsString(assignment_id) && !cJSON_IsNull(assignment_id))
    {
    goto end; //String
    }
    }

    // submit_result_dto->score
    cJSON *score = cJSON_GetObjectItemCaseSensitive(submit_result_dtoJSON, "score");
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

    // submit_result_dto->training_code
    cJSON *training_code = cJSON_GetObjectItemCaseSensitive(submit_result_dtoJSON, "trainingCode");
    if (cJSON_IsNull(training_code)) {
        training_code = NULL;
    }
    if (!training_code) {
        goto end;
    }

    
    if(!cJSON_IsString(training_code))
    {
    goto end; //String
    }


    if (assignment_id && !cJSON_IsNull(assignment_id)) assignment_id_local_str = strdup(assignment_id->valuestring);
    if (training_code && !cJSON_IsNull(training_code)) training_code_local_str = strdup(training_code->valuestring);

    submit_result_dto_local_var = submit_result_dto_create_internal (
        answersList,
        assignment_id_local_str,
        score_local_var,
        training_code_local_str
        );

    if (!submit_result_dto_local_var) {
        goto end;
    }

    return submit_result_dto_local_var;
end:
    if (answersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, answersList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(answersList);
        answersList = NULL;
    }
    if (assignment_id_local_str) {
        free(assignment_id_local_str);
        assignment_id_local_str = NULL;
    }
    if (score_local_var) {
        free(score_local_var);
        score_local_var = NULL;
    }
    if (training_code_local_str) {
        free(training_code_local_str);
        training_code_local_str = NULL;
    }
    return NULL;

}
