/*
 * posting_category.h
 *
 * 
 */

#ifndef _posting_category_H_
#define _posting_category_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct posting_category_t posting_category_t;




typedef struct posting_category_t {
    char *account_number; // string
    char *account_number_skr03; // string
    char *account_number_skr04; // string
    char *account_number_skr49; // string
    char *category_id; // string
    int *default_vat_rate; //numeric
    char *description; // string
    char *eks_category; // string
    int *is_active; //boolean
    int *is_system; //boolean
    char *name; // string
    char *skr_version; // string
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} posting_category_t;

__attribute__((deprecated)) posting_category_t *posting_category_create(
    char *account_number,
    char *account_number_skr03,
    char *account_number_skr04,
    char *account_number_skr49,
    char *category_id,
    int *default_vat_rate,
    char *description,
    char *eks_category,
    int *is_active,
    int *is_system,
    char *name,
    char *skr_version,
    char *type
);

void posting_category_free(posting_category_t *posting_category);

posting_category_t *posting_category_parseFromJSON(cJSON *posting_categoryJSON);

cJSON *posting_category_convertToJSON(posting_category_t *posting_category);

#endif /* _posting_category_H_ */

