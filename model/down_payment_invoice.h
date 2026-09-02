/*
 * down_payment_invoice.h
 *
 * 
 */

#ifndef _down_payment_invoice_H_
#define _down_payment_invoice_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct down_payment_invoice_t down_payment_invoice_t;




typedef struct down_payment_invoice_t {
    char *contact_id; // string
    char *contact_name; // string
    char *created_at; // string
    char *currency; // string
    char *id; // string
    char *notes; // string
    char *paid_amount; // string
    char *total_amount; // string
    char *voucher_date; //date
    char *voucher_number; // string
    char *voucher_status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} down_payment_invoice_t;

__attribute__((deprecated)) down_payment_invoice_t *down_payment_invoice_create(
    char *contact_id,
    char *contact_name,
    char *created_at,
    char *currency,
    char *id,
    char *notes,
    char *paid_amount,
    char *total_amount,
    char *voucher_date,
    char *voucher_number,
    char *voucher_status
);

void down_payment_invoice_free(down_payment_invoice_t *down_payment_invoice);

down_payment_invoice_t *down_payment_invoice_parseFromJSON(cJSON *down_payment_invoiceJSON);

cJSON *down_payment_invoice_convertToJSON(down_payment_invoice_t *down_payment_invoice);

#endif /* _down_payment_invoice_H_ */

