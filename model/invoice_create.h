/*
 * invoice_create.h
 *
 * 
 */

#ifndef _invoice_create_H_
#define _invoice_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct invoice_create_t invoice_create_t;

#include "any_type.h"
#include "country_code.h"
#include "currency_code.h"
#include "document_type.h"
#include "invoice_status.h"
#include "invoice_type.h"
#include "payment_status.h"
#include "preceding_sales_voucher_type.h"



typedef struct invoice_create_t {
    any_type_t *attachments; // custom
    char *billing_period_end; //date
    char *billing_period_start; //date
    char *cancellation_date; //date
    char *cancellation_invoice_id; // string
    char *cancellation_reason; // string
    char *contract_id; // string
    simplebilly_api_currency_code__e currency; //referenced enum
    char *customer_id; // string
    char *discount_amount; // string
    int *discount_days; //numeric
    char *discount_percentage; // string
    simplebilly_api_document_type__e document_type; //referenced enum
    int *dunning_level; //numeric
    char *input_vat_amount; // string
    int *input_vat_deductible; //boolean
    char *input_vat_percentage; // string
    char *introduction_text; // string
    simplebilly_api_invoice_type__e invoice_type; //referenced enum
    int *is_cancelled; //boolean
    int *is_draft; //boolean
    int *is_eu_acquisition; //boolean
    int *is_eu_delivery; //boolean
    int *is_intra_community_acquisition; //boolean
    int *is_reverse_charge; //boolean
    char *issue_date; //date
    char *ledger_account; // string
    any_type_t *line_items; // custom
    int *margin25a; //boolean
    char *margin25a_gross; // string
    char *margin25a_purchase_price; // string
    char *notes; // string
    char *order_number; // string
    char *original_pdf_path; // string
    char *paid_amount; // string
    char *payment_due_date; //date
    simplebilly_api_payment_status__e payment_status; //referenced enum
    char *payment_terms_text; // string
    char *preceding_sales_voucher_id; // string
    preceding_sales_voucher_type_t *preceding_sales_voucher_type; // custom
    int *receipt_confirmation_available; //boolean
    char *related_invoice_id; // string
    char *relationship_type; // string
    any_type_t *sender_snapshot; // custom
    char *sent_at; //date time
    char *service_period_end; //date
    char *service_period_start; //date
    simplebilly_api_invoice_status__e status; //referenced enum
    char *subtotal; // string
    char *supplier_id; // string
    char *tax_exemption_reason; // string
    char *total_amount; // string
    char *total_tax; // string
    country_code_t *vat_country; // custom
    char *vat_special_case; // string

    int _library_owned; // Is the library responsible for freeing this object?
} invoice_create_t;

__attribute__((deprecated)) invoice_create_t *invoice_create_create(
    any_type_t *attachments,
    char *billing_period_end,
    char *billing_period_start,
    char *cancellation_date,
    char *cancellation_invoice_id,
    char *cancellation_reason,
    char *contract_id,
    simplebilly_api_currency_code__e currency,
    char *customer_id,
    char *discount_amount,
    int *discount_days,
    char *discount_percentage,
    simplebilly_api_document_type__e document_type,
    int *dunning_level,
    char *input_vat_amount,
    int *input_vat_deductible,
    char *input_vat_percentage,
    char *introduction_text,
    simplebilly_api_invoice_type__e invoice_type,
    int *is_cancelled,
    int *is_draft,
    int *is_eu_acquisition,
    int *is_eu_delivery,
    int *is_intra_community_acquisition,
    int *is_reverse_charge,
    char *issue_date,
    char *ledger_account,
    any_type_t *line_items,
    int *margin25a,
    char *margin25a_gross,
    char *margin25a_purchase_price,
    char *notes,
    char *order_number,
    char *original_pdf_path,
    char *paid_amount,
    char *payment_due_date,
    simplebilly_api_payment_status__e payment_status,
    char *payment_terms_text,
    char *preceding_sales_voucher_id,
    preceding_sales_voucher_type_t *preceding_sales_voucher_type,
    int *receipt_confirmation_available,
    char *related_invoice_id,
    char *relationship_type,
    any_type_t *sender_snapshot,
    char *sent_at,
    char *service_period_end,
    char *service_period_start,
    simplebilly_api_invoice_status__e status,
    char *subtotal,
    char *supplier_id,
    char *tax_exemption_reason,
    char *total_amount,
    char *total_tax,
    country_code_t *vat_country,
    char *vat_special_case
);

void invoice_create_free(invoice_create_t *invoice_create);

invoice_create_t *invoice_create_parseFromJSON(cJSON *invoice_createJSON);

cJSON *invoice_create_convertToJSON(invoice_create_t *invoice_create);

#endif /* _invoice_create_H_ */

