/*
 * recurring_template_create.h
 *
 * 
 */

#ifndef _recurring_template_create_H_
#define _recurring_template_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct recurring_template_create_t recurring_template_create_t;

#include "any_type.h"
#include "execution_status.h"
#include "recurring_template_type.h"



typedef struct recurring_template_create_t {
    char *end_date; //date
    char *execution_interval; // string
    simplebilly_api_execution_status__e execution_status; //referenced enum
    int *finalize; //boolean
    char *last_executed_at; //date time
    char *name; // string
    char *next_execution_at; //date time
    char *start_date; //date
    simplebilly_api_recurring_template_type__e template_type; //referenced enum
    any_type_t *voucher_data; // custom

    int _library_owned; // Is the library responsible for freeing this object?
} recurring_template_create_t;

__attribute__((deprecated)) recurring_template_create_t *recurring_template_create_create(
    char *end_date,
    char *execution_interval,
    simplebilly_api_execution_status__e execution_status,
    int *finalize,
    char *last_executed_at,
    char *name,
    char *next_execution_at,
    char *start_date,
    simplebilly_api_recurring_template_type__e template_type,
    any_type_t *voucher_data
);

void recurring_template_create_free(recurring_template_create_t *recurring_template_create);

recurring_template_create_t *recurring_template_create_parseFromJSON(cJSON *recurring_template_createJSON);

cJSON *recurring_template_create_convertToJSON(recurring_template_create_t *recurring_template_create);

#endif /* _recurring_template_create_H_ */

