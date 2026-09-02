/*
 * proforma_invoice_create.h
 *
 * 
 */

#ifndef _proforma_invoice_create_H_
#define _proforma_invoice_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct proforma_invoice_create_t proforma_invoice_create_t;

#include "any_type.h"
#include "currency_code.h"
#include "proforma_invoice_status.h"



typedef struct proforma_invoice_create_t {
    char *converted_at; //date time
    char *converted_to_invoice_id; // string
    simplebilly_api_currency_code__e currency; //referenced enum
    char *customer_id; // string
    any_type_t *customer_snapshot; // custom
    char *issue_date; //date
    any_type_t *line_items; // custom
    char *notes; // string
    char *order_number; // string
    char *payment_due_date; //date
    char *quotation_id; // string
    proforma_invoice_status_t *status; // custom
    char *subtotal; // string
    char *total_amount; // string
    char *total_tax; // string

    int _library_owned; // Is the library responsible for freeing this object?
} proforma_invoice_create_t;

__attribute__((deprecated)) proforma_invoice_create_t *proforma_invoice_create_create(
    char *converted_at,
    char *converted_to_invoice_id,
    simplebilly_api_currency_code__e currency,
    char *customer_id,
    any_type_t *customer_snapshot,
    char *issue_date,
    any_type_t *line_items,
    char *notes,
    char *order_number,
    char *payment_due_date,
    char *quotation_id,
    proforma_invoice_status_t *status,
    char *subtotal,
    char *total_amount,
    char *total_tax
);

void proforma_invoice_create_free(proforma_invoice_create_t *proforma_invoice_create);

proforma_invoice_create_t *proforma_invoice_create_parseFromJSON(cJSON *proforma_invoice_createJSON);

cJSON *proforma_invoice_create_convertToJSON(proforma_invoice_create_t *proforma_invoice_create);

#endif /* _proforma_invoice_create_H_ */

