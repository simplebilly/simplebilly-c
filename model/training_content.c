#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "training_content.h"



static training_content_t *training_content_create_internal(
    char *code,
    contact_info_t *contact,
    int *pass_score,
    list_t *quiz,
    list_t *sections,
    char *title,
    char *title_en
    ) {
    training_content_t *training_content_local_var = malloc(sizeof(training_content_t));
    if (!training_content_local_var) {
        return NULL;
    }
    memset(training_content_local_var, 0, sizeof(training_content_t));
    training_content_local_var->_library_owned = 1;
    training_content_local_var->code = code;
    training_content_local_var->contact = contact;
    training_content_local_var->pass_score = pass_score;
    training_content_local_var->quiz = quiz;
    training_content_local_var->sections = sections;
    training_content_local_var->title = title;
    training_content_local_var->title_en = title_en;
    return training_content_local_var;
}

__attribute__((deprecated)) training_content_t *training_content_create(
    char *code,
    contact_info_t *contact,
    int *pass_score,
    list_t *quiz,
    list_t *sections,
    char *title,
    char *title_en
    ) {
    int *pass_score_copy = NULL;
    if (pass_score) {
        pass_score_copy = malloc(sizeof(int));
        if (pass_score_copy) *pass_score_copy = *pass_score;
    }
    training_content_t *result = training_content_create_internal (
        code,
        contact,
        pass_score_copy,
        quiz,
        sections,
        title,
        title_en
        );
    if (!result) {
        free(pass_score_copy);
    }
    return result;
}

void training_content_free(training_content_t *training_content) {
    if(NULL == training_content){
        return ;
    }
    if(training_content->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "training_content_free");
        return ;
    }
    listEntry_t *listEntry;
    if (training_content->code) {
        free(training_content->code);
        training_content->code = NULL;
    }
    if (training_content->contact) {
        contact_info_free(training_content->contact);
        training_content->contact = NULL;
    }
    if (training_content->pass_score) {
        free(training_content->pass_score);
        training_content->pass_score = NULL;
    }
    if (training_content->quiz) {
        list_ForEach(listEntry, training_content->quiz) {
            quiz_question_free(listEntry->data);
        }
        list_freeList(training_content->quiz);
        training_content->quiz = NULL;
    }
    if (training_content->sections) {
        list_ForEach(listEntry, training_content->sections) {
            section_free(listEntry->data);
        }
        list_freeList(training_content->sections);
        training_content->sections = NULL;
    }
    if (training_content->title) {
        free(training_content->title);
        training_content->title = NULL;
    }
    if (training_content->title_en) {
        free(training_content->title_en);
        training_content->title_en = NULL;
    }
    free(training_content);
}

cJSON *training_content_convertToJSON(training_content_t *training_content) {
    cJSON *item = cJSON_CreateObject();

    // training_content->code
    if (!training_content->code) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "code", training_content->code) == NULL) {
    goto fail; //String
    }


    // training_content->contact
    if (!training_content->contact) {
        goto fail;
    }
    cJSON *contact_local_JSON = contact_info_convertToJSON(training_content->contact);
    if(contact_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "contact", contact_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // training_content->pass_score
    if (!training_content->pass_score) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "passScore", *training_content->pass_score) == NULL) {
    goto fail; //Numeric
    }


    // training_content->quiz
    if (!training_content->quiz) {
        goto fail;
    }
    cJSON *quiz = cJSON_AddArrayToObject(item, "quiz");
    if(quiz == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *quizListEntry;
    if (training_content->quiz) {
    list_ForEach(quizListEntry, training_content->quiz) {
    cJSON *itemLocal = quiz_question_convertToJSON(quizListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(quiz, itemLocal);
    }
    }


    // training_content->sections
    if (!training_content->sections) {
        goto fail;
    }
    cJSON *sections = cJSON_AddArrayToObject(item, "sections");
    if(sections == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *sectionsListEntry;
    if (training_content->sections) {
    list_ForEach(sectionsListEntry, training_content->sections) {
    cJSON *itemLocal = section_convertToJSON(sectionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(sections, itemLocal);
    }
    }


    // training_content->title
    if (!training_content->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", training_content->title) == NULL) {
    goto fail; //String
    }


    // training_content->title_en
    if (!training_content->title_en) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "titleEn", training_content->title_en) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

training_content_t *training_content_parseFromJSON(cJSON *training_contentJSON){

    training_content_t *training_content_local_var = NULL;

    char *code_local_str = NULL;

    // define the local variable for training_content->contact
    contact_info_t *contact_local_nonprim = NULL;

    // define the local variable for training_content->pass_score
    int *pass_score_local_var = NULL;

    // define the local list for training_content->quiz
    list_t *quizList = NULL;

    // define the local list for training_content->sections
    list_t *sectionsList = NULL;

    char *title_local_str = NULL;

    char *title_en_local_str = NULL;

    // training_content->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(training_contentJSON, "code");
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

    // training_content->contact
    cJSON *contact = cJSON_GetObjectItemCaseSensitive(training_contentJSON, "contact");
    if (cJSON_IsNull(contact)) {
        contact = NULL;
    }
    if (!contact) {
        goto end;
    }

    
    contact_local_nonprim = contact_info_parseFromJSON(contact); //nonprimitive

    // training_content->pass_score
    cJSON *pass_score = cJSON_GetObjectItemCaseSensitive(training_contentJSON, "passScore");
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

    // training_content->quiz
    cJSON *quiz = cJSON_GetObjectItemCaseSensitive(training_contentJSON, "quiz");
    if (cJSON_IsNull(quiz)) {
        quiz = NULL;
    }
    if (!quiz) {
        goto end;
    }

    
    cJSON *quiz_local_nonprimitive = NULL;
    if(!cJSON_IsArray(quiz)){
        goto end; //nonprimitive container
    }

    quizList = list_createList();

    cJSON_ArrayForEach(quiz_local_nonprimitive,quiz )
    {
        if(!cJSON_IsObject(quiz_local_nonprimitive)){
            goto end;
        }
        quiz_question_t *quizItem = quiz_question_parseFromJSON(quiz_local_nonprimitive);

        list_addElement(quizList, quizItem);
    }

    // training_content->sections
    cJSON *sections = cJSON_GetObjectItemCaseSensitive(training_contentJSON, "sections");
    if (cJSON_IsNull(sections)) {
        sections = NULL;
    }
    if (!sections) {
        goto end;
    }

    
    cJSON *sections_local_nonprimitive = NULL;
    if(!cJSON_IsArray(sections)){
        goto end; //nonprimitive container
    }

    sectionsList = list_createList();

    cJSON_ArrayForEach(sections_local_nonprimitive,sections )
    {
        if(!cJSON_IsObject(sections_local_nonprimitive)){
            goto end;
        }
        section_t *sectionsItem = section_parseFromJSON(sections_local_nonprimitive);

        list_addElement(sectionsList, sectionsItem);
    }

    // training_content->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(training_contentJSON, "title");
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

    // training_content->title_en
    cJSON *title_en = cJSON_GetObjectItemCaseSensitive(training_contentJSON, "titleEn");
    if (cJSON_IsNull(title_en)) {
        title_en = NULL;
    }
    if (!title_en) {
        goto end;
    }

    
    if(!cJSON_IsString(title_en))
    {
    goto end; //String
    }


    if (code && !cJSON_IsNull(code)) code_local_str = strdup(code->valuestring);
    if (title && !cJSON_IsNull(title)) title_local_str = strdup(title->valuestring);
    if (title_en && !cJSON_IsNull(title_en)) title_en_local_str = strdup(title_en->valuestring);

    training_content_local_var = training_content_create_internal (
        code_local_str,
        contact_local_nonprim,
        pass_score_local_var,
        quizList,
        sectionsList,
        title_local_str,
        title_en_local_str
        );

    if (!training_content_local_var) {
        goto end;
    }

    return training_content_local_var;
end:
    if (code_local_str) {
        free(code_local_str);
        code_local_str = NULL;
    }
    if (contact_local_nonprim) {
        contact_info_free(contact_local_nonprim);
        contact_local_nonprim = NULL;
    }
    if (pass_score_local_var) {
        free(pass_score_local_var);
        pass_score_local_var = NULL;
    }
    if (quizList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, quizList) {
            quiz_question_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(quizList);
        quizList = NULL;
    }
    if (sectionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, sectionsList) {
            section_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(sectionsList);
        sectionsList = NULL;
    }
    if (title_local_str) {
        free(title_local_str);
        title_local_str = NULL;
    }
    if (title_en_local_str) {
        free(title_en_local_str);
        title_en_local_str = NULL;
    }
    return NULL;

}
