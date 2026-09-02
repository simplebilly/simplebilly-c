/*
 * quiz_question.h
 *
 * 
 */

#ifndef _quiz_question_H_
#define _quiz_question_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct quiz_question_t quiz_question_t;




typedef struct quiz_question_t {
    char *id; // string
    list_t *options; //primitive container
    list_t *options_en; //primitive container
    char *question; // string
    char *question_en; // string

    int _library_owned; // Is the library responsible for freeing this object?
} quiz_question_t;

__attribute__((deprecated)) quiz_question_t *quiz_question_create(
    char *id,
    list_t *options,
    list_t *options_en,
    char *question,
    char *question_en
);

void quiz_question_free(quiz_question_t *quiz_question);

quiz_question_t *quiz_question_parseFromJSON(cJSON *quiz_questionJSON);

cJSON *quiz_question_convertToJSON(quiz_question_t *quiz_question);

#endif /* _quiz_question_H_ */

