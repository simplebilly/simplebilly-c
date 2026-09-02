/*
 * voucher_create.h
 *
 * 
 */

#ifndef _voucher_create_H_
#define _voucher_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct voucher_create_t voucher_create_t;

#include "any_type.h"
#include "payment_status.h"
#include "voucher_status.h"
#include "voucher_type.h"



typedef struct voucher_create_t {
    char *category_id; // string
    char *contact_id; // string
    char *contact_name; // string
    char *currency; // string
    char *description; // string
    any_type_t *file_attachments; // custom
    any_type_t *line_items; // custom
    any_type_t *metadata; // custom
    char *notes; // string
    char *open_amount; // string
    char *paid_date; //date
    payment_status_t *payment_status; // custom
    any_type_t *tax_amounts; // custom
    char *tax_condition; // string
    char *total_gross_amount; // string
    char *total_net_amount; // string
    char *voucher_date; //date
    char *voucher_number; // string
    simplebilly_api_voucher_status__e voucher_status; //referenced enum
    simplebilly_api_voucher_type__e voucher_type; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} voucher_create_t;

__attribute__((deprecated)) voucher_create_t *voucher_create_create(
    char *category_id,
    char *contact_id,
    char *contact_name,
    char *currency,
    char *description,
    any_type_t *file_attachments,
    any_type_t *line_items,
    any_type_t *metadata,
    char *notes,
    char *open_amount,
    char *paid_date,
    payment_status_t *payment_status,
    any_type_t *tax_amounts,
    char *tax_condition,
    char *total_gross_amount,
    char *total_net_amount,
    char *voucher_date,
    char *voucher_number,
    simplebilly_api_voucher_status__e voucher_status,
    simplebilly_api_voucher_type__e voucher_type
);

void voucher_create_free(voucher_create_t *voucher_create);

voucher_create_t *voucher_create_parseFromJSON(cJSON *voucher_createJSON);

cJSON *voucher_create_convertToJSON(voucher_create_t *voucher_create);

#endif /* _voucher_create_H_ */

