/*
 * my_training_item.h
 *
 * 
 */

#ifndef _my_training_item_H_
#define _my_training_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct my_training_item_t my_training_item_t;

#include "assignment_status.h"



typedef struct my_training_item_t {
    char *assignment_id; // string
    char *certificate_id; // string
    char *code; // string
    char *description; // string
    char *due_date; //date
    int *last_score; //numeric
    int *pass_score; //numeric
    int *passed; //boolean
    simplebilly_api_assignment_status__e status; //referenced enum
    char *title; // string
    char *training_id; // string
    char *valid_until; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} my_training_item_t;

__attribute__((deprecated)) my_training_item_t *my_training_item_create(
    char *assignment_id,
    char *certificate_id,
    char *code,
    char *description,
    char *due_date,
    int *last_score,
    int *pass_score,
    int *passed,
    simplebilly_api_assignment_status__e status,
    char *title,
    char *training_id,
    char *valid_until
);

void my_training_item_free(my_training_item_t *my_training_item);

my_training_item_t *my_training_item_parseFromJSON(cJSON *my_training_itemJSON);

cJSON *my_training_item_convertToJSON(my_training_item_t *my_training_item);

#endif /* _my_training_item_H_ */

