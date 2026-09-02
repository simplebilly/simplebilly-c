/*
 * section.h
 *
 * 
 */

#ifndef _section_H_
#define _section_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct section_t section_t;




typedef struct section_t {
    char *body_html; // string
    char *body_html_en; // string
    char *id; // string
    char *title; // string
    char *title_en; // string

    int _library_owned; // Is the library responsible for freeing this object?
} section_t;

__attribute__((deprecated)) section_t *section_create(
    char *body_html,
    char *body_html_en,
    char *id,
    char *title,
    char *title_en
);

void section_free(section_t *section);

section_t *section_parseFromJSON(cJSON *sectionJSON);

cJSON *section_convertToJSON(section_t *section);

#endif /* _section_H_ */

