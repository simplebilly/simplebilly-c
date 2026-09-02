/*
 * public_posting.h
 *
 * Minimal shape for the public careers page (no tenant internals).
 */

#ifndef _public_posting_H_
#define _public_posting_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct public_posting_t public_posting_t;




typedef struct public_posting_t {
    char *currency; // string
    char *description; // string
    char *employment_type; // string
    char *id; // string
    char *location; // string
    int *remote; //boolean
    list_t *required_skills; //primitive container
    char *requirements; // string
    int *salary_max; //numeric
    int *salary_min; //numeric
    char *title; // string

    int _library_owned; // Is the library responsible for freeing this object?
} public_posting_t;

__attribute__((deprecated)) public_posting_t *public_posting_create(
    char *currency,
    char *description,
    char *employment_type,
    char *id,
    char *location,
    int *remote,
    list_t *required_skills,
    char *requirements,
    int *salary_max,
    int *salary_min,
    char *title
);

void public_posting_free(public_posting_t *public_posting);

public_posting_t *public_posting_parseFromJSON(cJSON *public_postingJSON);

cJSON *public_posting_convertToJSON(public_posting_t *public_posting);

#endif /* _public_posting_H_ */

