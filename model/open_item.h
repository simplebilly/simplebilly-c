/*
 * open_item.h
 *
 * 
 */

#ifndef _open_item_H_
#define _open_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct open_item_t open_item_t;

#include "reminder_level.h"



typedef struct open_item_t {
    char *amount_due; // string
    char *amount_paid; // string
    char *customer_id; // string
    long *days_overdue; //numeric
    char *due_date; // string
    char *invoice_id; // string
    char *invoice_number; // string
    char *issue_date; // string
    char *open_amount; // string
    simplebilly_api_reminder_level__e reminder_level; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} open_item_t;

__attribute__((deprecated)) open_item_t *open_item_create(
    char *amount_due,
    char *amount_paid,
    char *customer_id,
    long *days_overdue,
    char *due_date,
    char *invoice_id,
    char *invoice_number,
    char *issue_date,
    char *open_amount,
    simplebilly_api_reminder_level__e reminder_level
);

void open_item_free(open_item_t *open_item);

open_item_t *open_item_parseFromJSON(cJSON *open_itemJSON);

cJSON *open_item_convertToJSON(open_item_t *open_item);

#endif /* _open_item_H_ */

