/*
 * contact_create.h
 *
 * 
 */

#ifndef _contact_create_H_
#define _contact_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct contact_create_t contact_create_t;

#include "any_type.h"
#include "contact_type.h"
#include "country_code.h"
#include "sepa_sequence_type.h"



typedef struct contact_create_t {
    char *account_holder; // string
    char *acquisition_cost; // string
    char *address_supplement; // string
    char *attention; // string
    char *bank_name; // string
    char *bic; // string
    char *buyer_reference; // string
    char *category; // string
    char *certificate_authority; // string
    char *certificate_number; // string
    char *certificate_paragraph; // string
    char *certificate_valid_until; //date
    char *city; // string
    char *company_name; // string
    any_type_t *contact_persons; // custom
    simplebilly_api_contact_type__e contact_type; //referenced enum
    country_code_t *country; // custom
    char *credit_limit; // string
    char *creditor_account_skr03; // string
    char *creditor_account_skr04; // string
    char *currency; // string
    any_type_t *custom_fields; // custom
    char *customer_number; // string
    char *debitor_account_skr03; // string
    char *debitor_account_skr04; // string
    char *default_debitor_number; // string
    int *delivery_block; //boolean
    char *department; // string
    int *discount_days; //numeric
    char *discount_percentage; // string
    int *donation_receipt_eligible; //boolean
    char *email; // string
    char *external_id; // string
    char *fax; // string
    char *iban; // string
    char *industry; // string
    int *is_active; //boolean
    int *is_member; //boolean
    int *is_nonprofit; //boolean
    char *last_contact_date; //date
    char *last_purchase_date; //date
    char *leitweg_id; // string
    char *lifetime_value; // string
    char *mandate_date; //date
    char *mandate_reference; // string
    int *marketing_consent; //boolean
    char *marketing_consent_at; //date time
    char *marketing_consent_source; // string
    char *mobile; // string
    char *name; // string
    char *next_contact_date; //date
    char *notes; // string
    char *opening_balance; // string
    char *opening_balance_date; //date
    char *order_reference; // string
    int *payment_block; //boolean
    int *payment_grace_period_days; //numeric
    list_t *payment_methods; //primitive container
    char *payment_terms; // string
    char *phone; // string
    int *rating; //numeric
    char *sales_representative; // string
    int *sepa_batch_booking; //boolean
    sepa_sequence_type_t *sepa_sequence_type; // custom
    any_type_t *social_media; // custom
    char *source; // string
    char *state; // string
    char *street; // string
    char *street_number; // string
    char *supplier_number; // string
    list_t *tags; //primitive container
    country_code_t *tax_country; // custom
    char *tax_number; // string
    char *tax_office; // string
    int *total_invoices; //numeric
    char *total_revenue; // string
    char *vat_id; // string
    int *vat_id_validated; //boolean
    char *vat_id_validation_date; //date
    char *website; // string
    char *zip; // string

    int _library_owned; // Is the library responsible for freeing this object?
} contact_create_t;

__attribute__((deprecated)) contact_create_t *contact_create_create(
    char *account_holder,
    char *acquisition_cost,
    char *address_supplement,
    char *attention,
    char *bank_name,
    char *bic,
    char *buyer_reference,
    char *category,
    char *certificate_authority,
    char *certificate_number,
    char *certificate_paragraph,
    char *certificate_valid_until,
    char *city,
    char *company_name,
    any_type_t *contact_persons,
    simplebilly_api_contact_type__e contact_type,
    country_code_t *country,
    char *credit_limit,
    char *creditor_account_skr03,
    char *creditor_account_skr04,
    char *currency,
    any_type_t *custom_fields,
    char *customer_number,
    char *debitor_account_skr03,
    char *debitor_account_skr04,
    char *default_debitor_number,
    int *delivery_block,
    char *department,
    int *discount_days,
    char *discount_percentage,
    int *donation_receipt_eligible,
    char *email,
    char *external_id,
    char *fax,
    char *iban,
    char *industry,
    int *is_active,
    int *is_member,
    int *is_nonprofit,
    char *last_contact_date,
    char *last_purchase_date,
    char *leitweg_id,
    char *lifetime_value,
    char *mandate_date,
    char *mandate_reference,
    int *marketing_consent,
    char *marketing_consent_at,
    char *marketing_consent_source,
    char *mobile,
    char *name,
    char *next_contact_date,
    char *notes,
    char *opening_balance,
    char *opening_balance_date,
    char *order_reference,
    int *payment_block,
    int *payment_grace_period_days,
    list_t *payment_methods,
    char *payment_terms,
    char *phone,
    int *rating,
    char *sales_representative,
    int *sepa_batch_booking,
    sepa_sequence_type_t *sepa_sequence_type,
    any_type_t *social_media,
    char *source,
    char *state,
    char *street,
    char *street_number,
    char *supplier_number,
    list_t *tags,
    country_code_t *tax_country,
    char *tax_number,
    char *tax_office,
    int *total_invoices,
    char *total_revenue,
    char *vat_id,
    int *vat_id_validated,
    char *vat_id_validation_date,
    char *website,
    char *zip
);

void contact_create_free(contact_create_t *contact_create);

contact_create_t *contact_create_parseFromJSON(cJSON *contact_createJSON);

cJSON *contact_create_convertToJSON(contact_create_t *contact_create);

#endif /* _contact_create_H_ */

