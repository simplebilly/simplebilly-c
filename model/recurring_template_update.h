/*
 * recurring_template_update.h
 *
 * 
 */

#ifndef _recurring_template_update_H_
#define _recurring_template_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct recurring_template_update_t recurring_template_update_t;

#include "any_type.h"
#include "execution_status.h"
#include "recurring_template_type.h"



typedef struct recurring_template_update_t {
    char *end_date; //date
    char *execution_interval; // string
    execution_status_t *execution_status; // custom
    int *finalize; //boolean
    char *last_executed_at; //date time
    char *name; // string
    char *next_execution_at; //date time
    char *start_date; //date
    recurring_template_type_t *template_type; // custom
    any_type_t *voucher_data; // custom

    int _library_owned; // Is the library responsible for freeing this object?
} recurring_template_update_t;

__attribute__((deprecated)) recurring_template_update_t *recurring_template_update_create(
    char *end_date,
    char *execution_interval,
    execution_status_t *execution_status,
    int *finalize,
    char *last_executed_at,
    char *name,
    char *next_execution_at,
    char *start_date,
    recurring_template_type_t *template_type,
    any_type_t *voucher_data
);

void recurring_template_update_free(recurring_template_update_t *recurring_template_update);

recurring_template_update_t *recurring_template_update_parseFromJSON(cJSON *recurring_template_updateJSON);

cJSON *recurring_template_update_convertToJSON(recurring_template_update_t *recurring_template_update);

#endif /* _recurring_template_update_H_ */

