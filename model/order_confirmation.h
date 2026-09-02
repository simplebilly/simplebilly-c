/*
 * order_confirmation.h
 *
 * 
 */

#ifndef _order_confirmation_H_
#define _order_confirmation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct order_confirmation_t order_confirmation_t;

#include "any_type.h"
#include "preceding_sales_voucher_type.h"
#include "voucher_status.h"



typedef struct order_confirmation_t {
    any_type_t *address; // custom
    char *confirmation_number; // string
    char *contact_id; // string
    char *contact_name; // string
    char *currency; // string
    any_type_t *files; // custom
    char *introduction; // string
    any_type_t *line_items; // custom
    char *preceding_sales_voucher_id; // string
    preceding_sales_voucher_type_t *preceding_sales_voucher_type; // custom
    char *remark; // string
    char *subtotal; // string
    char *tax_condition; // string
    char *title; // string
    char *total_amount; // string
    char *total_tax; // string
    char *voucher_date; //date
    simplebilly_api_voucher_status__e voucher_status; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} order_confirmation_t;

__attribute__((deprecated)) order_confirmation_t *order_confirmation_create(
    any_type_t *address,
    char *confirmation_number,
    char *contact_id,
    char *contact_name,
    char *currency,
    any_type_t *files,
    char *introduction,
    any_type_t *line_items,
    char *preceding_sales_voucher_id,
    preceding_sales_voucher_type_t *preceding_sales_voucher_type,
    char *remark,
    char *subtotal,
    char *tax_condition,
    char *title,
    char *total_amount,
    char *total_tax,
    char *voucher_date,
    simplebilly_api_voucher_status__e voucher_status
);

void order_confirmation_free(order_confirmation_t *order_confirmation);

order_confirmation_t *order_confirmation_parseFromJSON(cJSON *order_confirmationJSON);

cJSON *order_confirmation_convertToJSON(order_confirmation_t *order_confirmation);

#endif /* _order_confirmation_H_ */

