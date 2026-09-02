/*
 * recurring_template.h
 *
 * 
 */

#ifndef _recurring_template_H_
#define _recurring_template_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct recurring_template_t recurring_template_t;

#include "any_type.h"



typedef struct recurring_template_t {
    char *created_at; // string
    char *deleted_at; // string
    char *end_date; //date
    char *execution_interval; // string
    char *execution_status; // string
    int *finalize; //boolean
    char *last_executed_at; //date time
    char *name; // string
    char *next_execution_at; //date time
    char *start_date; //date
    char *template_id; // string
    char *template_type; // string
    char *updated_at; // string
    any_type_t *voucher_data; // custom

    int _library_owned; // Is the library responsible for freeing this object?
} recurring_template_t;

__attribute__((deprecated)) recurring_template_t *recurring_template_create(
    char *created_at,
    char *deleted_at,
    char *end_date,
    char *execution_interval,
    char *execution_status,
    int *finalize,
    char *last_executed_at,
    char *name,
    char *next_execution_at,
    char *start_date,
    char *template_id,
    char *template_type,
    char *updated_at,
    any_type_t *voucher_data
);

void recurring_template_free(recurring_template_t *recurring_template);

recurring_template_t *recurring_template_parseFromJSON(cJSON *recurring_templateJSON);

cJSON *recurring_template_convertToJSON(recurring_template_t *recurring_template);

#endif /* _recurring_template_H_ */

