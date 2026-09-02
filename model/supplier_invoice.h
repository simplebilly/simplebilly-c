/*
 * supplier_invoice.h
 *
 * 
 */

#ifndef _supplier_invoice_H_
#define _supplier_invoice_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct supplier_invoice_t supplier_invoice_t;

#include "any_type.h"
#include "supplier_invoice_status.h"



typedef struct supplier_invoice_t {
    char *currency; // string
    char *goods_receipt_id; // string
    char *invoice_date; //date
    char *invoice_number; // string
    any_type_t *line_items; // custom
    char *notes; // string
    char *purchase_order_id; // string
    supplier_invoice_status_t *status; // custom
    char *supplier_contact_id; // string
    char *supplier_name; // string
    char *total_gross_amount; // string
    char *total_net_amount; // string

    int _library_owned; // Is the library responsible for freeing this object?
} supplier_invoice_t;

__attribute__((deprecated)) supplier_invoice_t *supplier_invoice_create(
    char *currency,
    char *goods_receipt_id,
    char *invoice_date,
    char *invoice_number,
    any_type_t *line_items,
    char *notes,
    char *purchase_order_id,
    supplier_invoice_status_t *status,
    char *supplier_contact_id,
    char *supplier_name,
    char *total_gross_amount,
    char *total_net_amount
);

void supplier_invoice_free(supplier_invoice_t *supplier_invoice);

supplier_invoice_t *supplier_invoice_parseFromJSON(cJSON *supplier_invoiceJSON);

cJSON *supplier_invoice_convertToJSON(supplier_invoice_t *supplier_invoice);

#endif /* _supplier_invoice_H_ */

