/*
 * training_content.h
 *
 * 
 */

#ifndef _training_content_H_
#define _training_content_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct training_content_t training_content_t;

#include "contact_info.h"
#include "quiz_question.h"
#include "section.h"



typedef struct training_content_t {
    char *code; // string
    struct contact_info_t *contact; //model
    int *pass_score; //numeric
    list_t *quiz; //nonprimitive container
    list_t *sections; //nonprimitive container
    char *title; // string
    char *title_en; // string

    int _library_owned; // Is the library responsible for freeing this object?
} training_content_t;

__attribute__((deprecated)) training_content_t *training_content_create(
    char *code,
    contact_info_t *contact,
    int *pass_score,
    list_t *quiz,
    list_t *sections,
    char *title,
    char *title_en
);

void training_content_free(training_content_t *training_content);

training_content_t *training_content_parseFromJSON(cJSON *training_contentJSON);

cJSON *training_content_convertToJSON(training_content_t *training_content);

#endif /* _training_content_H_ */

