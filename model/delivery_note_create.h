/*
 * delivery_note_create.h
 *
 * 
 */

#ifndef _delivery_note_create_H_
#define _delivery_note_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delivery_note_create_t delivery_note_create_t;

#include "any_type.h"
#include "preceding_sales_voucher_type.h"
#include "voucher_status.h"



typedef struct delivery_note_create_t {
    any_type_t *address; // custom
    char *contact_id; // string
    char *contact_name; // string
    char *currency; // string
    char *delivery_date; //date
    char *delivery_note_number; // string
    any_type_t *files; // custom
    char *introduction; // string
    any_type_t *line_items; // custom
    char *preceding_sales_voucher_id; // string
    preceding_sales_voucher_type_t *preceding_sales_voucher_type; // custom
    char *remark; // string
    char *shipping_date; //date
    char *shipping_method; // string
    char *title; // string
    char *voucher_date; //date
    simplebilly_api_voucher_status__e voucher_status; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} delivery_note_create_t;

__attribute__((deprecated)) delivery_note_create_t *delivery_note_create_create(
    any_type_t *address,
    char *contact_id,
    char *contact_name,
    char *currency,
    char *delivery_date,
    char *delivery_note_number,
    any_type_t *files,
    char *introduction,
    any_type_t *line_items,
    char *preceding_sales_voucher_id,
    preceding_sales_voucher_type_t *preceding_sales_voucher_type,
    char *remark,
    char *shipping_date,
    char *shipping_method,
    char *title,
    char *voucher_date,
    simplebilly_api_voucher_status__e voucher_status
);

void delivery_note_create_free(delivery_note_create_t *delivery_note_create);

delivery_note_create_t *delivery_note_create_parseFromJSON(cJSON *delivery_note_createJSON);

cJSON *delivery_note_create_convertToJSON(delivery_note_create_t *delivery_note_create);

#endif /* _delivery_note_create_H_ */

