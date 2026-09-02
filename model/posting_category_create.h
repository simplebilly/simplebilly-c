/*
 * posting_category_create.h
 *
 * 
 */

#ifndef _posting_category_create_H_
#define _posting_category_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct posting_category_create_t posting_category_create_t;

#include "posting_category_type.h"



typedef struct posting_category_create_t {
    char *account_number; // string
    char *account_number_skr03; // string
    char *account_number_skr04; // string
    char *account_number_skr49; // string
    simplebilly_api_posting_category_type__e category_type; //referenced enum
    char *created_at; //date time
    int *default_vat_rate; //numeric
    char *description; // string
    char *eks_category; // string
    int *eu_vat_line; //numeric
    char *input_vat_percentage; // string
    int *is_active; //boolean
    int *is_system; //boolean
    char *name; // string
    char *skr_version; // string
    char *updated_at; //date time
    int *user_modified_skr03; //boolean
    int *user_modified_skr04; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} posting_category_create_t;

__attribute__((deprecated)) posting_category_create_t *posting_category_create_create(
    char *account_number,
    char *account_number_skr03,
    char *account_number_skr04,
    char *account_number_skr49,
    simplebilly_api_posting_category_type__e category_type,
    char *created_at,
    int *default_vat_rate,
    char *description,
    char *eks_category,
    int *eu_vat_line,
    char *input_vat_percentage,
    int *is_active,
    int *is_system,
    char *name,
    char *skr_version,
    char *updated_at,
    int *user_modified_skr03,
    int *user_modified_skr04
);

void posting_category_create_free(posting_category_create_t *posting_category_create);

posting_category_create_t *posting_category_create_parseFromJSON(cJSON *posting_category_createJSON);

cJSON *posting_category_create_convertToJSON(posting_category_create_t *posting_category_create);

#endif /* _posting_category_create_H_ */

