/*
 * quotation_create.h
 *
 * 
 */

#ifndef _quotation_create_H_
#define _quotation_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct quotation_create_t quotation_create_t;

#include "any_type.h"
#include "preceding_sales_voucher_type.h"
#include "voucher_status.h"



typedef struct quotation_create_t {
    any_type_t *address; // custom
    char *contact_id; // string
    char *contact_name; // string
    char *currency; // string
    char *expiration_date; //date
    any_type_t *files; // custom
    char *introduction; // string
    any_type_t *line_items; // custom
    char *preceding_sales_voucher_id; // string
    preceding_sales_voucher_type_t *preceding_sales_voucher_type; // custom
    char *quotation_number; // string
    char *remark; // string
    char *tax_condition; // string
    char *title; // string
    char *voucher_date; //date
    simplebilly_api_voucher_status__e voucher_status; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} quotation_create_t;

__attribute__((deprecated)) quotation_create_t *quotation_create_create(
    any_type_t *address,
    char *contact_id,
    char *contact_name,
    char *currency,
    char *expiration_date,
    any_type_t *files,
    char *introduction,
    any_type_t *line_items,
    char *preceding_sales_voucher_id,
    preceding_sales_voucher_type_t *preceding_sales_voucher_type,
    char *quotation_number,
    char *remark,
    char *tax_condition,
    char *title,
    char *voucher_date,
    simplebilly_api_voucher_status__e voucher_status
);

void quotation_create_free(quotation_create_t *quotation_create);

quotation_create_t *quotation_create_parseFromJSON(cJSON *quotation_createJSON);

cJSON *quotation_create_convertToJSON(quotation_create_t *quotation_create);

#endif /* _quotation_create_H_ */

