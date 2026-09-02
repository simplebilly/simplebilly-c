#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "quiz_question.h"



static quiz_question_t *quiz_question_create_internal(
    char *id,
    list_t *options,
    list_t *options_en,
    char *question,
    char *question_en
    ) {
    quiz_question_t *quiz_question_local_var = malloc(sizeof(quiz_question_t));
    if (!quiz_question_local_var) {
        return NULL;
    }
    memset(quiz_question_local_var, 0, sizeof(quiz_question_t));
    quiz_question_local_var->_library_owned = 1;
    quiz_question_local_var->id = id;
    quiz_question_local_var->options = options;
    quiz_question_local_var->options_en = options_en;
    quiz_question_local_var->question = question;
    quiz_question_local_var->question_en = question_en;
    return quiz_question_local_var;
}

__attribute__((deprecated)) quiz_question_t *quiz_question_create(
    char *id,
    list_t *options,
    list_t *options_en,
    char *question,
    char *question_en
    ) {
    quiz_question_t *result = quiz_question_create_internal (
        id,
        options,
        options_en,
        question,
        question_en
        );
    if (!result) {
    }
    return result;
}

void quiz_question_free(quiz_question_t *quiz_question) {
    if(NULL == quiz_question){
        return ;
    }
    if(quiz_question->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "quiz_question_free");
        return ;
    }
    listEntry_t *listEntry;
    if (quiz_question->id) {
        free(quiz_question->id);
        quiz_question->id = NULL;
    }
    if (quiz_question->options) {
        list_ForEach(listEntry, quiz_question->options) {
            free(listEntry->data);
        }
        list_freeList(quiz_question->options);
        quiz_question->options = NULL;
    }
    if (quiz_question->options_en) {
        list_ForEach(listEntry, quiz_question->options_en) {
            free(listEntry->data);
        }
        list_freeList(quiz_question->options_en);
        quiz_question->options_en = NULL;
    }
    if (quiz_question->question) {
        free(quiz_question->question);
        quiz_question->question = NULL;
    }
    if (quiz_question->question_en) {
        free(quiz_question->question_en);
        quiz_question->question_en = NULL;
    }
    free(quiz_question);
}

cJSON *quiz_question_convertToJSON(quiz_question_t *quiz_question) {
    cJSON *item = cJSON_CreateObject();

    // quiz_question->id
    if (!quiz_question->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", quiz_question->id) == NULL) {
    goto fail; //String
    }


    // quiz_question->options
    if (!quiz_question->options) {
        goto fail;
    }
    cJSON *options = cJSON_AddArrayToObject(item, "options");
    if(options == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *optionsListEntry;
    list_ForEach(optionsListEntry, quiz_question->options) {
    if(cJSON_AddStringToObject(options, "", optionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // quiz_question->options_en
    if (!quiz_question->options_en) {
        goto fail;
    }
    cJSON *options_en = cJSON_AddArrayToObject(item, "optionsEn");
    if(options_en == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *options_enListEntry;
    list_ForEach(options_enListEntry, quiz_question->options_en) {
    if(cJSON_AddStringToObject(options_en, "", options_enListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // quiz_question->question
    if (!quiz_question->question) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "question", quiz_question->question) == NULL) {
    goto fail; //String
    }


    // quiz_question->question_en
    if (!quiz_question->question_en) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "questionEn", quiz_question->question_en) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

quiz_question_t *quiz_question_parseFromJSON(cJSON *quiz_questionJSON){

    quiz_question_t *quiz_question_local_var = NULL;

    char *id_local_str = NULL;

    // define the local list for quiz_question->options
    list_t *optionsList = NULL;

    // define the local list for quiz_question->options_en
    list_t *options_enList = NULL;

    char *question_local_str = NULL;

    char *question_en_local_str = NULL;

    // quiz_question->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(quiz_questionJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // quiz_question->options
    cJSON *options = cJSON_GetObjectItemCaseSensitive(quiz_questionJSON, "options");
    if (cJSON_IsNull(options)) {
        options = NULL;
    }
    if (!options) {
        goto end;
    }

    
    cJSON *options_local = NULL;
    if(!cJSON_IsArray(options)) {
        goto end;//primitive container
    }
    optionsList = list_createList();

    cJSON_ArrayForEach(options_local, options)
    {
        if(!cJSON_IsString(options_local))
        {
            goto end;
        }
        list_addElement(optionsList , strdup(options_local->valuestring));
    }

    // quiz_question->options_en
    cJSON *options_en = cJSON_GetObjectItemCaseSensitive(quiz_questionJSON, "optionsEn");
    if (cJSON_IsNull(options_en)) {
        options_en = NULL;
    }
    if (!options_en) {
        goto end;
    }

    
    cJSON *options_en_local = NULL;
    if(!cJSON_IsArray(options_en)) {
        goto end;//primitive container
    }
    options_enList = list_createList();

    cJSON_ArrayForEach(options_en_local, options_en)
    {
        if(!cJSON_IsString(options_en_local))
        {
            goto end;
        }
        list_addElement(options_enList , strdup(options_en_local->valuestring));
    }

    // quiz_question->question
    cJSON *question = cJSON_GetObjectItemCaseSensitive(quiz_questionJSON, "question");
    if (cJSON_IsNull(question)) {
        question = NULL;
    }
    if (!question) {
        goto end;
    }

    
    if(!cJSON_IsString(question))
    {
    goto end; //String
    }

    // quiz_question->question_en
    cJSON *question_en = cJSON_GetObjectItemCaseSensitive(quiz_questionJSON, "questionEn");
    if (cJSON_IsNull(question_en)) {
        question_en = NULL;
    }
    if (!question_en) {
        goto end;
    }

    
    if(!cJSON_IsString(question_en))
    {
    goto end; //String
    }


    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (question && !cJSON_IsNull(question)) question_local_str = strdup(question->valuestring);
    if (question_en && !cJSON_IsNull(question_en)) question_en_local_str = strdup(question_en->valuestring);

    quiz_question_local_var = quiz_question_create_internal (
        id_local_str,
        optionsList,
        options_enList,
        question_local_str,
        question_en_local_str
        );

    if (!quiz_question_local_var) {
        goto end;
    }

    return quiz_question_local_var;
end:
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (optionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, optionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(optionsList);
        optionsList = NULL;
    }
    if (options_enList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, options_enList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(options_enList);
        options_enList = NULL;
    }
    if (question_local_str) {
        free(question_local_str);
        question_local_str = NULL;
    }
    if (question_en_local_str) {
        free(question_en_local_str);
        question_en_local_str = NULL;
    }
    return NULL;

}
