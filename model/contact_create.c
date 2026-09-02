#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "contact_create.h"



static contact_create_t *contact_create_create_internal(
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
    ) {
    contact_create_t *contact_create_local_var = malloc(sizeof(contact_create_t));
    if (!contact_create_local_var) {
        return NULL;
    }
    memset(contact_create_local_var, 0, sizeof(contact_create_t));
    contact_create_local_var->_library_owned = 1;
    contact_create_local_var->account_holder = account_holder;
    contact_create_local_var->acquisition_cost = acquisition_cost;
    contact_create_local_var->address_supplement = address_supplement;
    contact_create_local_var->attention = attention;
    contact_create_local_var->bank_name = bank_name;
    contact_create_local_var->bic = bic;
    contact_create_local_var->buyer_reference = buyer_reference;
    contact_create_local_var->category = category;
    contact_create_local_var->certificate_authority = certificate_authority;
    contact_create_local_var->certificate_number = certificate_number;
    contact_create_local_var->certificate_paragraph = certificate_paragraph;
    contact_create_local_var->certificate_valid_until = certificate_valid_until;
    contact_create_local_var->city = city;
    contact_create_local_var->company_name = company_name;
    contact_create_local_var->contact_persons = contact_persons;
    contact_create_local_var->contact_type = contact_type;
    contact_create_local_var->country = country;
    contact_create_local_var->credit_limit = credit_limit;
    contact_create_local_var->creditor_account_skr03 = creditor_account_skr03;
    contact_create_local_var->creditor_account_skr04 = creditor_account_skr04;
    contact_create_local_var->currency = currency;
    contact_create_local_var->custom_fields = custom_fields;
    contact_create_local_var->customer_number = customer_number;
    contact_create_local_var->debitor_account_skr03 = debitor_account_skr03;
    contact_create_local_var->debitor_account_skr04 = debitor_account_skr04;
    contact_create_local_var->default_debitor_number = default_debitor_number;
    contact_create_local_var->delivery_block = delivery_block;
    contact_create_local_var->department = department;
    contact_create_local_var->discount_days = discount_days;
    contact_create_local_var->discount_percentage = discount_percentage;
    contact_create_local_var->donation_receipt_eligible = donation_receipt_eligible;
    contact_create_local_var->email = email;
    contact_create_local_var->external_id = external_id;
    contact_create_local_var->fax = fax;
    contact_create_local_var->iban = iban;
    contact_create_local_var->industry = industry;
    contact_create_local_var->is_active = is_active;
    contact_create_local_var->is_member = is_member;
    contact_create_local_var->is_nonprofit = is_nonprofit;
    contact_create_local_var->last_contact_date = last_contact_date;
    contact_create_local_var->last_purchase_date = last_purchase_date;
    contact_create_local_var->leitweg_id = leitweg_id;
    contact_create_local_var->lifetime_value = lifetime_value;
    contact_create_local_var->mandate_date = mandate_date;
    contact_create_local_var->mandate_reference = mandate_reference;
    contact_create_local_var->marketing_consent = marketing_consent;
    contact_create_local_var->marketing_consent_at = marketing_consent_at;
    contact_create_local_var->marketing_consent_source = marketing_consent_source;
    contact_create_local_var->mobile = mobile;
    contact_create_local_var->name = name;
    contact_create_local_var->next_contact_date = next_contact_date;
    contact_create_local_var->notes = notes;
    contact_create_local_var->opening_balance = opening_balance;
    contact_create_local_var->opening_balance_date = opening_balance_date;
    contact_create_local_var->order_reference = order_reference;
    contact_create_local_var->payment_block = payment_block;
    contact_create_local_var->payment_grace_period_days = payment_grace_period_days;
    contact_create_local_var->payment_methods = payment_methods;
    contact_create_local_var->payment_terms = payment_terms;
    contact_create_local_var->phone = phone;
    contact_create_local_var->rating = rating;
    contact_create_local_var->sales_representative = sales_representative;
    contact_create_local_var->sepa_batch_booking = sepa_batch_booking;
    contact_create_local_var->sepa_sequence_type = sepa_sequence_type;
    contact_create_local_var->social_media = social_media;
    contact_create_local_var->source = source;
    contact_create_local_var->state = state;
    contact_create_local_var->street = street;
    contact_create_local_var->street_number = street_number;
    contact_create_local_var->supplier_number = supplier_number;
    contact_create_local_var->tags = tags;
    contact_create_local_var->tax_country = tax_country;
    contact_create_local_var->tax_number = tax_number;
    contact_create_local_var->tax_office = tax_office;
    contact_create_local_var->total_invoices = total_invoices;
    contact_create_local_var->total_revenue = total_revenue;
    contact_create_local_var->vat_id = vat_id;
    contact_create_local_var->vat_id_validated = vat_id_validated;
    contact_create_local_var->vat_id_validation_date = vat_id_validation_date;
    contact_create_local_var->website = website;
    contact_create_local_var->zip = zip;
    return contact_create_local_var;
}

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
    ) {
    int *delivery_block_copy = NULL;
    if (delivery_block) {
        delivery_block_copy = malloc(sizeof(int));
        if (delivery_block_copy) *delivery_block_copy = *delivery_block;
    }
    int *discount_days_copy = NULL;
    if (discount_days) {
        discount_days_copy = malloc(sizeof(int));
        if (discount_days_copy) *discount_days_copy = *discount_days;
    }
    int *donation_receipt_eligible_copy = NULL;
    if (donation_receipt_eligible) {
        donation_receipt_eligible_copy = malloc(sizeof(int));
        if (donation_receipt_eligible_copy) *donation_receipt_eligible_copy = *donation_receipt_eligible;
    }
    int *is_active_copy = NULL;
    if (is_active) {
        is_active_copy = malloc(sizeof(int));
        if (is_active_copy) *is_active_copy = *is_active;
    }
    int *is_member_copy = NULL;
    if (is_member) {
        is_member_copy = malloc(sizeof(int));
        if (is_member_copy) *is_member_copy = *is_member;
    }
    int *is_nonprofit_copy = NULL;
    if (is_nonprofit) {
        is_nonprofit_copy = malloc(sizeof(int));
        if (is_nonprofit_copy) *is_nonprofit_copy = *is_nonprofit;
    }
    int *marketing_consent_copy = NULL;
    if (marketing_consent) {
        marketing_consent_copy = malloc(sizeof(int));
        if (marketing_consent_copy) *marketing_consent_copy = *marketing_consent;
    }
    int *payment_block_copy = NULL;
    if (payment_block) {
        payment_block_copy = malloc(sizeof(int));
        if (payment_block_copy) *payment_block_copy = *payment_block;
    }
    int *payment_grace_period_days_copy = NULL;
    if (payment_grace_period_days) {
        payment_grace_period_days_copy = malloc(sizeof(int));
        if (payment_grace_period_days_copy) *payment_grace_period_days_copy = *payment_grace_period_days;
    }
    int *rating_copy = NULL;
    if (rating) {
        rating_copy = malloc(sizeof(int));
        if (rating_copy) *rating_copy = *rating;
    }
    int *sepa_batch_booking_copy = NULL;
    if (sepa_batch_booking) {
        sepa_batch_booking_copy = malloc(sizeof(int));
        if (sepa_batch_booking_copy) *sepa_batch_booking_copy = *sepa_batch_booking;
    }
    int *total_invoices_copy = NULL;
    if (total_invoices) {
        total_invoices_copy = malloc(sizeof(int));
        if (total_invoices_copy) *total_invoices_copy = *total_invoices;
    }
    int *vat_id_validated_copy = NULL;
    if (vat_id_validated) {
        vat_id_validated_copy = malloc(sizeof(int));
        if (vat_id_validated_copy) *vat_id_validated_copy = *vat_id_validated;
    }
    contact_create_t *result = contact_create_create_internal (
        account_holder,
        acquisition_cost,
        address_supplement,
        attention,
        bank_name,
        bic,
        buyer_reference,
        category,
        certificate_authority,
        certificate_number,
        certificate_paragraph,
        certificate_valid_until,
        city,
        company_name,
        contact_persons,
        contact_type,
        country,
        credit_limit,
        creditor_account_skr03,
        creditor_account_skr04,
        currency,
        custom_fields,
        customer_number,
        debitor_account_skr03,
        debitor_account_skr04,
        default_debitor_number,
        delivery_block_copy,
        department,
        discount_days_copy,
        discount_percentage,
        donation_receipt_eligible_copy,
        email,
        external_id,
        fax,
        iban,
        industry,
        is_active_copy,
        is_member_copy,
        is_nonprofit_copy,
        last_contact_date,
        last_purchase_date,
        leitweg_id,
        lifetime_value,
        mandate_date,
        mandate_reference,
        marketing_consent_copy,
        marketing_consent_at,
        marketing_consent_source,
        mobile,
        name,
        next_contact_date,
        notes,
        opening_balance,
        opening_balance_date,
        order_reference,
        payment_block_copy,
        payment_grace_period_days_copy,
        payment_methods,
        payment_terms,
        phone,
        rating_copy,
        sales_representative,
        sepa_batch_booking_copy,
        sepa_sequence_type,
        social_media,
        source,
        state,
        street,
        street_number,
        supplier_number,
        tags,
        tax_country,
        tax_number,
        tax_office,
        total_invoices_copy,
        total_revenue,
        vat_id,
        vat_id_validated_copy,
        vat_id_validation_date,
        website,
        zip
        );
    if (!result) {
        free(delivery_block_copy);
        free(discount_days_copy);
        free(donation_receipt_eligible_copy);
        free(is_active_copy);
        free(is_member_copy);
        free(is_nonprofit_copy);
        free(marketing_consent_copy);
        free(payment_block_copy);
        free(payment_grace_period_days_copy);
        free(rating_copy);
        free(sepa_batch_booking_copy);
        free(total_invoices_copy);
        free(vat_id_validated_copy);
    }
    return result;
}

void contact_create_free(contact_create_t *contact_create) {
    if(NULL == contact_create){
        return ;
    }
    if(contact_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "contact_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (contact_create->account_holder) {
        free(contact_create->account_holder);
        contact_create->account_holder = NULL;
    }
    if (contact_create->acquisition_cost) {
        free(contact_create->acquisition_cost);
        contact_create->acquisition_cost = NULL;
    }
    if (contact_create->address_supplement) {
        free(contact_create->address_supplement);
        contact_create->address_supplement = NULL;
    }
    if (contact_create->attention) {
        free(contact_create->attention);
        contact_create->attention = NULL;
    }
    if (contact_create->bank_name) {
        free(contact_create->bank_name);
        contact_create->bank_name = NULL;
    }
    if (contact_create->bic) {
        free(contact_create->bic);
        contact_create->bic = NULL;
    }
    if (contact_create->buyer_reference) {
        free(contact_create->buyer_reference);
        contact_create->buyer_reference = NULL;
    }
    if (contact_create->category) {
        free(contact_create->category);
        contact_create->category = NULL;
    }
    if (contact_create->certificate_authority) {
        free(contact_create->certificate_authority);
        contact_create->certificate_authority = NULL;
    }
    if (contact_create->certificate_number) {
        free(contact_create->certificate_number);
        contact_create->certificate_number = NULL;
    }
    if (contact_create->certificate_paragraph) {
        free(contact_create->certificate_paragraph);
        contact_create->certificate_paragraph = NULL;
    }
    if (contact_create->certificate_valid_until) {
        free(contact_create->certificate_valid_until);
        contact_create->certificate_valid_until = NULL;
    }
    if (contact_create->city) {
        free(contact_create->city);
        contact_create->city = NULL;
    }
    if (contact_create->company_name) {
        free(contact_create->company_name);
        contact_create->company_name = NULL;
    }
    if (contact_create->contact_persons) {
        _free(contact_create->contact_persons);
        contact_create->contact_persons = NULL;
    }
    if (contact_create->country) {
        country_code_free(contact_create->country);
        contact_create->country = NULL;
    }
    if (contact_create->credit_limit) {
        free(contact_create->credit_limit);
        contact_create->credit_limit = NULL;
    }
    if (contact_create->creditor_account_skr03) {
        free(contact_create->creditor_account_skr03);
        contact_create->creditor_account_skr03 = NULL;
    }
    if (contact_create->creditor_account_skr04) {
        free(contact_create->creditor_account_skr04);
        contact_create->creditor_account_skr04 = NULL;
    }
    if (contact_create->currency) {
        free(contact_create->currency);
        contact_create->currency = NULL;
    }
    if (contact_create->custom_fields) {
        _free(contact_create->custom_fields);
        contact_create->custom_fields = NULL;
    }
    if (contact_create->customer_number) {
        free(contact_create->customer_number);
        contact_create->customer_number = NULL;
    }
    if (contact_create->debitor_account_skr03) {
        free(contact_create->debitor_account_skr03);
        contact_create->debitor_account_skr03 = NULL;
    }
    if (contact_create->debitor_account_skr04) {
        free(contact_create->debitor_account_skr04);
        contact_create->debitor_account_skr04 = NULL;
    }
    if (contact_create->default_debitor_number) {
        free(contact_create->default_debitor_number);
        contact_create->default_debitor_number = NULL;
    }
    if (contact_create->delivery_block) {
        free(contact_create->delivery_block);
        contact_create->delivery_block = NULL;
    }
    if (contact_create->department) {
        free(contact_create->department);
        contact_create->department = NULL;
    }
    if (contact_create->discount_days) {
        free(contact_create->discount_days);
        contact_create->discount_days = NULL;
    }
    if (contact_create->discount_percentage) {
        free(contact_create->discount_percentage);
        contact_create->discount_percentage = NULL;
    }
    if (contact_create->donation_receipt_eligible) {
        free(contact_create->donation_receipt_eligible);
        contact_create->donation_receipt_eligible = NULL;
    }
    if (contact_create->email) {
        free(contact_create->email);
        contact_create->email = NULL;
    }
    if (contact_create->external_id) {
        free(contact_create->external_id);
        contact_create->external_id = NULL;
    }
    if (contact_create->fax) {
        free(contact_create->fax);
        contact_create->fax = NULL;
    }
    if (contact_create->iban) {
        free(contact_create->iban);
        contact_create->iban = NULL;
    }
    if (contact_create->industry) {
        free(contact_create->industry);
        contact_create->industry = NULL;
    }
    if (contact_create->is_active) {
        free(contact_create->is_active);
        contact_create->is_active = NULL;
    }
    if (contact_create->is_member) {
        free(contact_create->is_member);
        contact_create->is_member = NULL;
    }
    if (contact_create->is_nonprofit) {
        free(contact_create->is_nonprofit);
        contact_create->is_nonprofit = NULL;
    }
    if (contact_create->last_contact_date) {
        free(contact_create->last_contact_date);
        contact_create->last_contact_date = NULL;
    }
    if (contact_create->last_purchase_date) {
        free(contact_create->last_purchase_date);
        contact_create->last_purchase_date = NULL;
    }
    if (contact_create->leitweg_id) {
        free(contact_create->leitweg_id);
        contact_create->leitweg_id = NULL;
    }
    if (contact_create->lifetime_value) {
        free(contact_create->lifetime_value);
        contact_create->lifetime_value = NULL;
    }
    if (contact_create->mandate_date) {
        free(contact_create->mandate_date);
        contact_create->mandate_date = NULL;
    }
    if (contact_create->mandate_reference) {
        free(contact_create->mandate_reference);
        contact_create->mandate_reference = NULL;
    }
    if (contact_create->marketing_consent) {
        free(contact_create->marketing_consent);
        contact_create->marketing_consent = NULL;
    }
    if (contact_create->marketing_consent_at) {
        free(contact_create->marketing_consent_at);
        contact_create->marketing_consent_at = NULL;
    }
    if (contact_create->marketing_consent_source) {
        free(contact_create->marketing_consent_source);
        contact_create->marketing_consent_source = NULL;
    }
    if (contact_create->mobile) {
        free(contact_create->mobile);
        contact_create->mobile = NULL;
    }
    if (contact_create->name) {
        free(contact_create->name);
        contact_create->name = NULL;
    }
    if (contact_create->next_contact_date) {
        free(contact_create->next_contact_date);
        contact_create->next_contact_date = NULL;
    }
    if (contact_create->notes) {
        free(contact_create->notes);
        contact_create->notes = NULL;
    }
    if (contact_create->opening_balance) {
        free(contact_create->opening_balance);
        contact_create->opening_balance = NULL;
    }
    if (contact_create->opening_balance_date) {
        free(contact_create->opening_balance_date);
        contact_create->opening_balance_date = NULL;
    }
    if (contact_create->order_reference) {
        free(contact_create->order_reference);
        contact_create->order_reference = NULL;
    }
    if (contact_create->payment_block) {
        free(contact_create->payment_block);
        contact_create->payment_block = NULL;
    }
    if (contact_create->payment_grace_period_days) {
        free(contact_create->payment_grace_period_days);
        contact_create->payment_grace_period_days = NULL;
    }
    if (contact_create->payment_methods) {
        list_ForEach(listEntry, contact_create->payment_methods) {
            free(listEntry->data);
        }
        list_freeList(contact_create->payment_methods);
        contact_create->payment_methods = NULL;
    }
    if (contact_create->payment_terms) {
        free(contact_create->payment_terms);
        contact_create->payment_terms = NULL;
    }
    if (contact_create->phone) {
        free(contact_create->phone);
        contact_create->phone = NULL;
    }
    if (contact_create->rating) {
        free(contact_create->rating);
        contact_create->rating = NULL;
    }
    if (contact_create->sales_representative) {
        free(contact_create->sales_representative);
        contact_create->sales_representative = NULL;
    }
    if (contact_create->sepa_batch_booking) {
        free(contact_create->sepa_batch_booking);
        contact_create->sepa_batch_booking = NULL;
    }
    if (contact_create->sepa_sequence_type) {
        sepa_sequence_type_free(contact_create->sepa_sequence_type);
        contact_create->sepa_sequence_type = NULL;
    }
    if (contact_create->social_media) {
        _free(contact_create->social_media);
        contact_create->social_media = NULL;
    }
    if (contact_create->source) {
        free(contact_create->source);
        contact_create->source = NULL;
    }
    if (contact_create->state) {
        free(contact_create->state);
        contact_create->state = NULL;
    }
    if (contact_create->street) {
        free(contact_create->street);
        contact_create->street = NULL;
    }
    if (contact_create->street_number) {
        free(contact_create->street_number);
        contact_create->street_number = NULL;
    }
    if (contact_create->supplier_number) {
        free(contact_create->supplier_number);
        contact_create->supplier_number = NULL;
    }
    if (contact_create->tags) {
        list_ForEach(listEntry, contact_create->tags) {
            free(listEntry->data);
        }
        list_freeList(contact_create->tags);
        contact_create->tags = NULL;
    }
    if (contact_create->tax_country) {
        country_code_free(contact_create->tax_country);
        contact_create->tax_country = NULL;
    }
    if (contact_create->tax_number) {
        free(contact_create->tax_number);
        contact_create->tax_number = NULL;
    }
    if (contact_create->tax_office) {
        free(contact_create->tax_office);
        contact_create->tax_office = NULL;
    }
    if (contact_create->total_invoices) {
        free(contact_create->total_invoices);
        contact_create->total_invoices = NULL;
    }
    if (contact_create->total_revenue) {
        free(contact_create->total_revenue);
        contact_create->total_revenue = NULL;
    }
    if (contact_create->vat_id) {
        free(contact_create->vat_id);
        contact_create->vat_id = NULL;
    }
    if (contact_create->vat_id_validated) {
        free(contact_create->vat_id_validated);
        contact_create->vat_id_validated = NULL;
    }
    if (contact_create->vat_id_validation_date) {
        free(contact_create->vat_id_validation_date);
        contact_create->vat_id_validation_date = NULL;
    }
    if (contact_create->website) {
        free(contact_create->website);
        contact_create->website = NULL;
    }
    if (contact_create->zip) {
        free(contact_create->zip);
        contact_create->zip = NULL;
    }
    free(contact_create);
}

cJSON *contact_create_convertToJSON(contact_create_t *contact_create) {
    cJSON *item = cJSON_CreateObject();

    // contact_create->account_holder
    if(contact_create->account_holder) {
    if(cJSON_AddStringToObject(item, "accountHolder", contact_create->account_holder) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->acquisition_cost
    if(contact_create->acquisition_cost) {
    if(cJSON_AddStringToObject(item, "acquisitionCost", contact_create->acquisition_cost) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->address_supplement
    if(contact_create->address_supplement) {
    if(cJSON_AddStringToObject(item, "addressSupplement", contact_create->address_supplement) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->attention
    if(contact_create->attention) {
    if(cJSON_AddStringToObject(item, "attention", contact_create->attention) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->bank_name
    if(contact_create->bank_name) {
    if(cJSON_AddStringToObject(item, "bankName", contact_create->bank_name) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->bic
    if(contact_create->bic) {
    if(cJSON_AddStringToObject(item, "bic", contact_create->bic) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->buyer_reference
    if(contact_create->buyer_reference) {
    if(cJSON_AddStringToObject(item, "buyerReference", contact_create->buyer_reference) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->category
    if(contact_create->category) {
    if(cJSON_AddStringToObject(item, "category", contact_create->category) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->certificate_authority
    if(contact_create->certificate_authority) {
    if(cJSON_AddStringToObject(item, "certificateAuthority", contact_create->certificate_authority) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->certificate_number
    if(contact_create->certificate_number) {
    if(cJSON_AddStringToObject(item, "certificateNumber", contact_create->certificate_number) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->certificate_paragraph
    if(contact_create->certificate_paragraph) {
    if(cJSON_AddStringToObject(item, "certificateParagraph", contact_create->certificate_paragraph) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->certificate_valid_until
    if(contact_create->certificate_valid_until) {
    if(cJSON_AddStringToObject(item, "certificateValidUntil", contact_create->certificate_valid_until) == NULL) {
    goto fail; //Date
    }
    }


    // contact_create->city
    if(contact_create->city) {
    if(cJSON_AddStringToObject(item, "city", contact_create->city) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->company_name
    if(contact_create->company_name) {
    if(cJSON_AddStringToObject(item, "companyName", contact_create->company_name) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->contact_persons
    if(contact_create->contact_persons) {
    cJSON *contact_persons_local_JSON = _convertToJSON(contact_create->contact_persons);
    if(contact_persons_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "contactPersons", contact_persons_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // contact_create->contact_type
    if (simplebilly_api_contact_type__NULL == contact_create->contact_type) {
        goto fail;
    }
    cJSON *contact_type_local_JSON = contact_type_convertToJSON(contact_create->contact_type);
    if(contact_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "contactType", contact_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // contact_create->country
    if(contact_create->country) {
    cJSON *country_local_JSON = country_code_convertToJSON(contact_create->country);
    if(country_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "country", country_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // contact_create->credit_limit
    if(contact_create->credit_limit) {
    if(cJSON_AddStringToObject(item, "creditLimit", contact_create->credit_limit) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->creditor_account_skr03
    if(contact_create->creditor_account_skr03) {
    if(cJSON_AddStringToObject(item, "creditorAccountSkr03", contact_create->creditor_account_skr03) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->creditor_account_skr04
    if(contact_create->creditor_account_skr04) {
    if(cJSON_AddStringToObject(item, "creditorAccountSkr04", contact_create->creditor_account_skr04) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->currency
    if(contact_create->currency) {
    if(cJSON_AddStringToObject(item, "currency", contact_create->currency) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->custom_fields
    if(contact_create->custom_fields) {
    cJSON *custom_fields_local_JSON = _convertToJSON(contact_create->custom_fields);
    if(custom_fields_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "customFields", custom_fields_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // contact_create->customer_number
    if(contact_create->customer_number) {
    if(cJSON_AddStringToObject(item, "customerNumber", contact_create->customer_number) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->debitor_account_skr03
    if(contact_create->debitor_account_skr03) {
    if(cJSON_AddStringToObject(item, "debitorAccountSkr03", contact_create->debitor_account_skr03) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->debitor_account_skr04
    if(contact_create->debitor_account_skr04) {
    if(cJSON_AddStringToObject(item, "debitorAccountSkr04", contact_create->debitor_account_skr04) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->default_debitor_number
    if(contact_create->default_debitor_number) {
    if(cJSON_AddStringToObject(item, "defaultDebitorNumber", contact_create->default_debitor_number) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->delivery_block
    if(contact_create->delivery_block) {
    if(cJSON_AddBoolToObject(item, "deliveryBlock", *contact_create->delivery_block) == NULL) {
    goto fail; //Bool
    }
    }


    // contact_create->department
    if(contact_create->department) {
    if(cJSON_AddStringToObject(item, "department", contact_create->department) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->discount_days
    if(contact_create->discount_days) {
    if(cJSON_AddNumberToObject(item, "discountDays", *contact_create->discount_days) == NULL) {
    goto fail; //Numeric
    }
    }


    // contact_create->discount_percentage
    if(contact_create->discount_percentage) {
    if(cJSON_AddStringToObject(item, "discountPercentage", contact_create->discount_percentage) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->donation_receipt_eligible
    if(contact_create->donation_receipt_eligible) {
    if(cJSON_AddBoolToObject(item, "donationReceiptEligible", *contact_create->donation_receipt_eligible) == NULL) {
    goto fail; //Bool
    }
    }


    // contact_create->email
    if(contact_create->email) {
    if(cJSON_AddStringToObject(item, "email", contact_create->email) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->external_id
    if(contact_create->external_id) {
    if(cJSON_AddStringToObject(item, "externalId", contact_create->external_id) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->fax
    if(contact_create->fax) {
    if(cJSON_AddStringToObject(item, "fax", contact_create->fax) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->iban
    if(contact_create->iban) {
    if(cJSON_AddStringToObject(item, "iban", contact_create->iban) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->industry
    if(contact_create->industry) {
    if(cJSON_AddStringToObject(item, "industry", contact_create->industry) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->is_active
    if(contact_create->is_active) {
    if(cJSON_AddBoolToObject(item, "isActive", *contact_create->is_active) == NULL) {
    goto fail; //Bool
    }
    }


    // contact_create->is_member
    if(contact_create->is_member) {
    if(cJSON_AddBoolToObject(item, "isMember", *contact_create->is_member) == NULL) {
    goto fail; //Bool
    }
    }


    // contact_create->is_nonprofit
    if(contact_create->is_nonprofit) {
    if(cJSON_AddBoolToObject(item, "isNonprofit", *contact_create->is_nonprofit) == NULL) {
    goto fail; //Bool
    }
    }


    // contact_create->last_contact_date
    if(contact_create->last_contact_date) {
    if(cJSON_AddStringToObject(item, "lastContactDate", contact_create->last_contact_date) == NULL) {
    goto fail; //Date
    }
    }


    // contact_create->last_purchase_date
    if(contact_create->last_purchase_date) {
    if(cJSON_AddStringToObject(item, "lastPurchaseDate", contact_create->last_purchase_date) == NULL) {
    goto fail; //Date
    }
    }


    // contact_create->leitweg_id
    if(contact_create->leitweg_id) {
    if(cJSON_AddStringToObject(item, "leitwegId", contact_create->leitweg_id) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->lifetime_value
    if(contact_create->lifetime_value) {
    if(cJSON_AddStringToObject(item, "lifetimeValue", contact_create->lifetime_value) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->mandate_date
    if(contact_create->mandate_date) {
    if(cJSON_AddStringToObject(item, "mandateDate", contact_create->mandate_date) == NULL) {
    goto fail; //Date
    }
    }


    // contact_create->mandate_reference
    if(contact_create->mandate_reference) {
    if(cJSON_AddStringToObject(item, "mandateReference", contact_create->mandate_reference) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->marketing_consent
    if(contact_create->marketing_consent) {
    if(cJSON_AddBoolToObject(item, "marketingConsent", *contact_create->marketing_consent) == NULL) {
    goto fail; //Bool
    }
    }


    // contact_create->marketing_consent_at
    if(contact_create->marketing_consent_at) {
    if(cJSON_AddStringToObject(item, "marketingConsentAt", contact_create->marketing_consent_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // contact_create->marketing_consent_source
    if(contact_create->marketing_consent_source) {
    if(cJSON_AddStringToObject(item, "marketingConsentSource", contact_create->marketing_consent_source) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->mobile
    if(contact_create->mobile) {
    if(cJSON_AddStringToObject(item, "mobile", contact_create->mobile) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->name
    if (!contact_create->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", contact_create->name) == NULL) {
    goto fail; //String
    }


    // contact_create->next_contact_date
    if(contact_create->next_contact_date) {
    if(cJSON_AddStringToObject(item, "nextContactDate", contact_create->next_contact_date) == NULL) {
    goto fail; //Date
    }
    }


    // contact_create->notes
    if(contact_create->notes) {
    if(cJSON_AddStringToObject(item, "notes", contact_create->notes) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->opening_balance
    if(contact_create->opening_balance) {
    if(cJSON_AddStringToObject(item, "openingBalance", contact_create->opening_balance) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->opening_balance_date
    if(contact_create->opening_balance_date) {
    if(cJSON_AddStringToObject(item, "openingBalanceDate", contact_create->opening_balance_date) == NULL) {
    goto fail; //Date
    }
    }


    // contact_create->order_reference
    if(contact_create->order_reference) {
    if(cJSON_AddStringToObject(item, "orderReference", contact_create->order_reference) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->payment_block
    if(contact_create->payment_block) {
    if(cJSON_AddBoolToObject(item, "paymentBlock", *contact_create->payment_block) == NULL) {
    goto fail; //Bool
    }
    }


    // contact_create->payment_grace_period_days
    if(contact_create->payment_grace_period_days) {
    if(cJSON_AddNumberToObject(item, "paymentGracePeriodDays", *contact_create->payment_grace_period_days) == NULL) {
    goto fail; //Numeric
    }
    }


    // contact_create->payment_methods
    if(contact_create->payment_methods) {
    cJSON *payment_methods = cJSON_AddArrayToObject(item, "paymentMethods");
    if(payment_methods == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *payment_methodsListEntry;
    list_ForEach(payment_methodsListEntry, contact_create->payment_methods) {
    if(cJSON_AddStringToObject(payment_methods, "", payment_methodsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // contact_create->payment_terms
    if(contact_create->payment_terms) {
    if(cJSON_AddStringToObject(item, "paymentTerms", contact_create->payment_terms) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->phone
    if(contact_create->phone) {
    if(cJSON_AddStringToObject(item, "phone", contact_create->phone) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->rating
    if(contact_create->rating) {
    if(cJSON_AddNumberToObject(item, "rating", *contact_create->rating) == NULL) {
    goto fail; //Numeric
    }
    }


    // contact_create->sales_representative
    if(contact_create->sales_representative) {
    if(cJSON_AddStringToObject(item, "salesRepresentative", contact_create->sales_representative) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->sepa_batch_booking
    if(contact_create->sepa_batch_booking) {
    if(cJSON_AddBoolToObject(item, "sepaBatchBooking", *contact_create->sepa_batch_booking) == NULL) {
    goto fail; //Bool
    }
    }


    // contact_create->sepa_sequence_type
    if(contact_create->sepa_sequence_type) {
    cJSON *sepa_sequence_type_local_JSON = sepa_sequence_type_convertToJSON(contact_create->sepa_sequence_type);
    if(sepa_sequence_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "sepaSequenceType", sepa_sequence_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // contact_create->social_media
    if(contact_create->social_media) {
    cJSON *social_media_local_JSON = _convertToJSON(contact_create->social_media);
    if(social_media_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "socialMedia", social_media_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // contact_create->source
    if(contact_create->source) {
    if(cJSON_AddStringToObject(item, "source", contact_create->source) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->state
    if(contact_create->state) {
    if(cJSON_AddStringToObject(item, "state", contact_create->state) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->street
    if(contact_create->street) {
    if(cJSON_AddStringToObject(item, "street", contact_create->street) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->street_number
    if(contact_create->street_number) {
    if(cJSON_AddStringToObject(item, "streetNumber", contact_create->street_number) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->supplier_number
    if(contact_create->supplier_number) {
    if(cJSON_AddStringToObject(item, "supplierNumber", contact_create->supplier_number) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->tags
    if(contact_create->tags) {
    cJSON *tags = cJSON_AddArrayToObject(item, "tags");
    if(tags == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *tagsListEntry;
    list_ForEach(tagsListEntry, contact_create->tags) {
    if(cJSON_AddStringToObject(tags, "", tagsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // contact_create->tax_country
    if(contact_create->tax_country) {
    cJSON *tax_country_local_JSON = country_code_convertToJSON(contact_create->tax_country);
    if(tax_country_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "taxCountry", tax_country_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // contact_create->tax_number
    if(contact_create->tax_number) {
    if(cJSON_AddStringToObject(item, "taxNumber", contact_create->tax_number) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->tax_office
    if(contact_create->tax_office) {
    if(cJSON_AddStringToObject(item, "taxOffice", contact_create->tax_office) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->total_invoices
    if(contact_create->total_invoices) {
    if(cJSON_AddNumberToObject(item, "totalInvoices", *contact_create->total_invoices) == NULL) {
    goto fail; //Numeric
    }
    }


    // contact_create->total_revenue
    if(contact_create->total_revenue) {
    if(cJSON_AddStringToObject(item, "totalRevenue", contact_create->total_revenue) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->vat_id
    if(contact_create->vat_id) {
    if(cJSON_AddStringToObject(item, "vatId", contact_create->vat_id) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->vat_id_validated
    if(contact_create->vat_id_validated) {
    if(cJSON_AddBoolToObject(item, "vatIdValidated", *contact_create->vat_id_validated) == NULL) {
    goto fail; //Bool
    }
    }


    // contact_create->vat_id_validation_date
    if(contact_create->vat_id_validation_date) {
    if(cJSON_AddStringToObject(item, "vatIdValidationDate", contact_create->vat_id_validation_date) == NULL) {
    goto fail; //Date
    }
    }


    // contact_create->website
    if(contact_create->website) {
    if(cJSON_AddStringToObject(item, "website", contact_create->website) == NULL) {
    goto fail; //String
    }
    }


    // contact_create->zip
    if(contact_create->zip) {
    if(cJSON_AddStringToObject(item, "zip", contact_create->zip) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

contact_create_t *contact_create_parseFromJSON(cJSON *contact_createJSON){

    contact_create_t *contact_create_local_var = NULL;

    char *account_holder_local_str = NULL;

    char *acquisition_cost_local_str = NULL;

    char *address_supplement_local_str = NULL;

    char *attention_local_str = NULL;

    char *bank_name_local_str = NULL;

    char *bic_local_str = NULL;

    char *buyer_reference_local_str = NULL;

    char *category_local_str = NULL;

    char *certificate_authority_local_str = NULL;

    char *certificate_number_local_str = NULL;

    char *certificate_paragraph_local_str = NULL;

    char *certificate_valid_until_local_str = NULL;

    char *city_local_str = NULL;

    char *company_name_local_str = NULL;

    // define the local variable for contact_create->contact_persons
    _t *contact_persons_local_nonprim = NULL;

    // define the local variable for contact_create->contact_type
    simplebilly_api_contact_type__e contact_type_local_nonprim = 0;

    // define the local variable for contact_create->country
    country_code_t *country_local_nonprim = NULL;

    char *credit_limit_local_str = NULL;

    char *creditor_account_skr03_local_str = NULL;

    char *creditor_account_skr04_local_str = NULL;

    char *currency_local_str = NULL;

    // define the local variable for contact_create->custom_fields
    _t *custom_fields_local_nonprim = NULL;

    char *customer_number_local_str = NULL;

    char *debitor_account_skr03_local_str = NULL;

    char *debitor_account_skr04_local_str = NULL;

    char *default_debitor_number_local_str = NULL;

    // define the local variable for contact_create->delivery_block
    int *delivery_block_local_var = NULL;

    char *department_local_str = NULL;

    // define the local variable for contact_create->discount_days
    int *discount_days_local_var = NULL;

    char *discount_percentage_local_str = NULL;

    // define the local variable for contact_create->donation_receipt_eligible
    int *donation_receipt_eligible_local_var = NULL;

    char *email_local_str = NULL;

    char *external_id_local_str = NULL;

    char *fax_local_str = NULL;

    char *iban_local_str = NULL;

    char *industry_local_str = NULL;

    // define the local variable for contact_create->is_active
    int *is_active_local_var = NULL;

    // define the local variable for contact_create->is_member
    int *is_member_local_var = NULL;

    // define the local variable for contact_create->is_nonprofit
    int *is_nonprofit_local_var = NULL;

    char *last_contact_date_local_str = NULL;

    char *last_purchase_date_local_str = NULL;

    char *leitweg_id_local_str = NULL;

    char *lifetime_value_local_str = NULL;

    char *mandate_date_local_str = NULL;

    char *mandate_reference_local_str = NULL;

    // define the local variable for contact_create->marketing_consent
    int *marketing_consent_local_var = NULL;

    char *marketing_consent_at_local_str = NULL;

    char *marketing_consent_source_local_str = NULL;

    char *mobile_local_str = NULL;

    char *name_local_str = NULL;

    char *next_contact_date_local_str = NULL;

    char *notes_local_str = NULL;

    char *opening_balance_local_str = NULL;

    char *opening_balance_date_local_str = NULL;

    char *order_reference_local_str = NULL;

    // define the local variable for contact_create->payment_block
    int *payment_block_local_var = NULL;

    // define the local variable for contact_create->payment_grace_period_days
    int *payment_grace_period_days_local_var = NULL;

    // define the local list for contact_create->payment_methods
    list_t *payment_methodsList = NULL;

    char *payment_terms_local_str = NULL;

    char *phone_local_str = NULL;

    // define the local variable for contact_create->rating
    int *rating_local_var = NULL;

    char *sales_representative_local_str = NULL;

    // define the local variable for contact_create->sepa_batch_booking
    int *sepa_batch_booking_local_var = NULL;

    // define the local variable for contact_create->sepa_sequence_type
    sepa_sequence_type_t *sepa_sequence_type_local_nonprim = NULL;

    // define the local variable for contact_create->social_media
    _t *social_media_local_nonprim = NULL;

    char *source_local_str = NULL;

    char *state_local_str = NULL;

    char *street_local_str = NULL;

    char *street_number_local_str = NULL;

    char *supplier_number_local_str = NULL;

    // define the local list for contact_create->tags
    list_t *tagsList = NULL;

    // define the local variable for contact_create->tax_country
    country_code_t *tax_country_local_nonprim = NULL;

    char *tax_number_local_str = NULL;

    char *tax_office_local_str = NULL;

    // define the local variable for contact_create->total_invoices
    int *total_invoices_local_var = NULL;

    char *total_revenue_local_str = NULL;

    char *vat_id_local_str = NULL;

    // define the local variable for contact_create->vat_id_validated
    int *vat_id_validated_local_var = NULL;

    char *vat_id_validation_date_local_str = NULL;

    char *website_local_str = NULL;

    char *zip_local_str = NULL;

    // contact_create->account_holder
    cJSON *account_holder = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "accountHolder");
    if (cJSON_IsNull(account_holder)) {
        account_holder = NULL;
    }
    if (account_holder) { 
    if(!cJSON_IsString(account_holder) && !cJSON_IsNull(account_holder))
    {
    goto end; //String
    }
    }

    // contact_create->acquisition_cost
    cJSON *acquisition_cost = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "acquisitionCost");
    if (cJSON_IsNull(acquisition_cost)) {
        acquisition_cost = NULL;
    }
    if (acquisition_cost) { 
    if(!cJSON_IsString(acquisition_cost) && !cJSON_IsNull(acquisition_cost))
    {
    goto end; //String
    }
    }

    // contact_create->address_supplement
    cJSON *address_supplement = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "addressSupplement");
    if (cJSON_IsNull(address_supplement)) {
        address_supplement = NULL;
    }
    if (address_supplement) { 
    if(!cJSON_IsString(address_supplement) && !cJSON_IsNull(address_supplement))
    {
    goto end; //String
    }
    }

    // contact_create->attention
    cJSON *attention = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "attention");
    if (cJSON_IsNull(attention)) {
        attention = NULL;
    }
    if (attention) { 
    if(!cJSON_IsString(attention) && !cJSON_IsNull(attention))
    {
    goto end; //String
    }
    }

    // contact_create->bank_name
    cJSON *bank_name = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "bankName");
    if (cJSON_IsNull(bank_name)) {
        bank_name = NULL;
    }
    if (bank_name) { 
    if(!cJSON_IsString(bank_name) && !cJSON_IsNull(bank_name))
    {
    goto end; //String
    }
    }

    // contact_create->bic
    cJSON *bic = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "bic");
    if (cJSON_IsNull(bic)) {
        bic = NULL;
    }
    if (bic) { 
    if(!cJSON_IsString(bic) && !cJSON_IsNull(bic))
    {
    goto end; //String
    }
    }

    // contact_create->buyer_reference
    cJSON *buyer_reference = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "buyerReference");
    if (cJSON_IsNull(buyer_reference)) {
        buyer_reference = NULL;
    }
    if (buyer_reference) { 
    if(!cJSON_IsString(buyer_reference) && !cJSON_IsNull(buyer_reference))
    {
    goto end; //String
    }
    }

    // contact_create->category
    cJSON *category = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "category");
    if (cJSON_IsNull(category)) {
        category = NULL;
    }
    if (category) { 
    if(!cJSON_IsString(category) && !cJSON_IsNull(category))
    {
    goto end; //String
    }
    }

    // contact_create->certificate_authority
    cJSON *certificate_authority = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "certificateAuthority");
    if (cJSON_IsNull(certificate_authority)) {
        certificate_authority = NULL;
    }
    if (certificate_authority) { 
    if(!cJSON_IsString(certificate_authority) && !cJSON_IsNull(certificate_authority))
    {
    goto end; //String
    }
    }

    // contact_create->certificate_number
    cJSON *certificate_number = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "certificateNumber");
    if (cJSON_IsNull(certificate_number)) {
        certificate_number = NULL;
    }
    if (certificate_number) { 
    if(!cJSON_IsString(certificate_number) && !cJSON_IsNull(certificate_number))
    {
    goto end; //String
    }
    }

    // contact_create->certificate_paragraph
    cJSON *certificate_paragraph = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "certificateParagraph");
    if (cJSON_IsNull(certificate_paragraph)) {
        certificate_paragraph = NULL;
    }
    if (certificate_paragraph) { 
    if(!cJSON_IsString(certificate_paragraph) && !cJSON_IsNull(certificate_paragraph))
    {
    goto end; //String
    }
    }

    // contact_create->certificate_valid_until
    cJSON *certificate_valid_until = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "certificateValidUntil");
    if (cJSON_IsNull(certificate_valid_until)) {
        certificate_valid_until = NULL;
    }
    if (certificate_valid_until) { 
    if(!cJSON_IsString(certificate_valid_until))
    {
    goto end; //Date
    }
    }

    // contact_create->city
    cJSON *city = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "city");
    if (cJSON_IsNull(city)) {
        city = NULL;
    }
    if (city) { 
    if(!cJSON_IsString(city) && !cJSON_IsNull(city))
    {
    goto end; //String
    }
    }

    // contact_create->company_name
    cJSON *company_name = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "companyName");
    if (cJSON_IsNull(company_name)) {
        company_name = NULL;
    }
    if (company_name) { 
    if(!cJSON_IsString(company_name) && !cJSON_IsNull(company_name))
    {
    goto end; //String
    }
    }

    // contact_create->contact_persons
    cJSON *contact_persons = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "contactPersons");
    if (cJSON_IsNull(contact_persons)) {
        contact_persons = NULL;
    }
    if (contact_persons) { 
    contact_persons_local_nonprim = _parseFromJSON(contact_persons); //custom
    }

    // contact_create->contact_type
    cJSON *contact_type = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "contactType");
    if (cJSON_IsNull(contact_type)) {
        contact_type = NULL;
    }
    if (!contact_type) {
        goto end;
    }

    
    contact_type_local_nonprim = contact_type_parseFromJSON(contact_type); //custom

    // contact_create->country
    cJSON *country = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "country");
    if (cJSON_IsNull(country)) {
        country = NULL;
    }
    if (country) { 
    country_local_nonprim = country_code_parseFromJSON(country); //custom
    }

    // contact_create->credit_limit
    cJSON *credit_limit = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "creditLimit");
    if (cJSON_IsNull(credit_limit)) {
        credit_limit = NULL;
    }
    if (credit_limit) { 
    if(!cJSON_IsString(credit_limit) && !cJSON_IsNull(credit_limit))
    {
    goto end; //String
    }
    }

    // contact_create->creditor_account_skr03
    cJSON *creditor_account_skr03 = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "creditorAccountSkr03");
    if (cJSON_IsNull(creditor_account_skr03)) {
        creditor_account_skr03 = NULL;
    }
    if (creditor_account_skr03) { 
    if(!cJSON_IsString(creditor_account_skr03) && !cJSON_IsNull(creditor_account_skr03))
    {
    goto end; //String
    }
    }

    // contact_create->creditor_account_skr04
    cJSON *creditor_account_skr04 = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "creditorAccountSkr04");
    if (cJSON_IsNull(creditor_account_skr04)) {
        creditor_account_skr04 = NULL;
    }
    if (creditor_account_skr04) { 
    if(!cJSON_IsString(creditor_account_skr04) && !cJSON_IsNull(creditor_account_skr04))
    {
    goto end; //String
    }
    }

    // contact_create->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (currency) { 
    if(!cJSON_IsString(currency) && !cJSON_IsNull(currency))
    {
    goto end; //String
    }
    }

    // contact_create->custom_fields
    cJSON *custom_fields = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "customFields");
    if (cJSON_IsNull(custom_fields)) {
        custom_fields = NULL;
    }
    if (custom_fields) { 
    custom_fields_local_nonprim = _parseFromJSON(custom_fields); //custom
    }

    // contact_create->customer_number
    cJSON *customer_number = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "customerNumber");
    if (cJSON_IsNull(customer_number)) {
        customer_number = NULL;
    }
    if (customer_number) { 
    if(!cJSON_IsString(customer_number) && !cJSON_IsNull(customer_number))
    {
    goto end; //String
    }
    }

    // contact_create->debitor_account_skr03
    cJSON *debitor_account_skr03 = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "debitorAccountSkr03");
    if (cJSON_IsNull(debitor_account_skr03)) {
        debitor_account_skr03 = NULL;
    }
    if (debitor_account_skr03) { 
    if(!cJSON_IsString(debitor_account_skr03) && !cJSON_IsNull(debitor_account_skr03))
    {
    goto end; //String
    }
    }

    // contact_create->debitor_account_skr04
    cJSON *debitor_account_skr04 = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "debitorAccountSkr04");
    if (cJSON_IsNull(debitor_account_skr04)) {
        debitor_account_skr04 = NULL;
    }
    if (debitor_account_skr04) { 
    if(!cJSON_IsString(debitor_account_skr04) && !cJSON_IsNull(debitor_account_skr04))
    {
    goto end; //String
    }
    }

    // contact_create->default_debitor_number
    cJSON *default_debitor_number = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "defaultDebitorNumber");
    if (cJSON_IsNull(default_debitor_number)) {
        default_debitor_number = NULL;
    }
    if (default_debitor_number) { 
    if(!cJSON_IsString(default_debitor_number) && !cJSON_IsNull(default_debitor_number))
    {
    goto end; //String
    }
    }

    // contact_create->delivery_block
    cJSON *delivery_block = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "deliveryBlock");
    if (cJSON_IsNull(delivery_block)) {
        delivery_block = NULL;
    }
    if (delivery_block) { 
    if(!cJSON_IsBool(delivery_block))
    {
    goto end; //Bool
    }
    delivery_block_local_var = malloc(sizeof(int));
    if(!delivery_block_local_var)
    {
        goto end;
    }
    *delivery_block_local_var = delivery_block->valueint;
    }

    // contact_create->department
    cJSON *department = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "department");
    if (cJSON_IsNull(department)) {
        department = NULL;
    }
    if (department) { 
    if(!cJSON_IsString(department) && !cJSON_IsNull(department))
    {
    goto end; //String
    }
    }

    // contact_create->discount_days
    cJSON *discount_days = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "discountDays");
    if (cJSON_IsNull(discount_days)) {
        discount_days = NULL;
    }
    if (discount_days) { 
    if(!cJSON_IsNumber(discount_days))
    {
    goto end; //Numeric
    }
    discount_days_local_var = malloc(sizeof(int));
    if(!discount_days_local_var)
    {
        goto end;
    }
    *discount_days_local_var = discount_days->valuedouble;
    }

    // contact_create->discount_percentage
    cJSON *discount_percentage = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "discountPercentage");
    if (cJSON_IsNull(discount_percentage)) {
        discount_percentage = NULL;
    }
    if (discount_percentage) { 
    if(!cJSON_IsString(discount_percentage) && !cJSON_IsNull(discount_percentage))
    {
    goto end; //String
    }
    }

    // contact_create->donation_receipt_eligible
    cJSON *donation_receipt_eligible = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "donationReceiptEligible");
    if (cJSON_IsNull(donation_receipt_eligible)) {
        donation_receipt_eligible = NULL;
    }
    if (donation_receipt_eligible) { 
    if(!cJSON_IsBool(donation_receipt_eligible))
    {
    goto end; //Bool
    }
    donation_receipt_eligible_local_var = malloc(sizeof(int));
    if(!donation_receipt_eligible_local_var)
    {
        goto end;
    }
    *donation_receipt_eligible_local_var = donation_receipt_eligible->valueint;
    }

    // contact_create->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // contact_create->external_id
    cJSON *external_id = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "externalId");
    if (cJSON_IsNull(external_id)) {
        external_id = NULL;
    }
    if (external_id) { 
    if(!cJSON_IsString(external_id) && !cJSON_IsNull(external_id))
    {
    goto end; //String
    }
    }

    // contact_create->fax
    cJSON *fax = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "fax");
    if (cJSON_IsNull(fax)) {
        fax = NULL;
    }
    if (fax) { 
    if(!cJSON_IsString(fax) && !cJSON_IsNull(fax))
    {
    goto end; //String
    }
    }

    // contact_create->iban
    cJSON *iban = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "iban");
    if (cJSON_IsNull(iban)) {
        iban = NULL;
    }
    if (iban) { 
    if(!cJSON_IsString(iban) && !cJSON_IsNull(iban))
    {
    goto end; //String
    }
    }

    // contact_create->industry
    cJSON *industry = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "industry");
    if (cJSON_IsNull(industry)) {
        industry = NULL;
    }
    if (industry) { 
    if(!cJSON_IsString(industry) && !cJSON_IsNull(industry))
    {
    goto end; //String
    }
    }

    // contact_create->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "isActive");
    if (cJSON_IsNull(is_active)) {
        is_active = NULL;
    }
    if (is_active) { 
    if(!cJSON_IsBool(is_active))
    {
    goto end; //Bool
    }
    is_active_local_var = malloc(sizeof(int));
    if(!is_active_local_var)
    {
        goto end;
    }
    *is_active_local_var = is_active->valueint;
    }

    // contact_create->is_member
    cJSON *is_member = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "isMember");
    if (cJSON_IsNull(is_member)) {
        is_member = NULL;
    }
    if (is_member) { 
    if(!cJSON_IsBool(is_member))
    {
    goto end; //Bool
    }
    is_member_local_var = malloc(sizeof(int));
    if(!is_member_local_var)
    {
        goto end;
    }
    *is_member_local_var = is_member->valueint;
    }

    // contact_create->is_nonprofit
    cJSON *is_nonprofit = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "isNonprofit");
    if (cJSON_IsNull(is_nonprofit)) {
        is_nonprofit = NULL;
    }
    if (is_nonprofit) { 
    if(!cJSON_IsBool(is_nonprofit))
    {
    goto end; //Bool
    }
    is_nonprofit_local_var = malloc(sizeof(int));
    if(!is_nonprofit_local_var)
    {
        goto end;
    }
    *is_nonprofit_local_var = is_nonprofit->valueint;
    }

    // contact_create->last_contact_date
    cJSON *last_contact_date = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "lastContactDate");
    if (cJSON_IsNull(last_contact_date)) {
        last_contact_date = NULL;
    }
    if (last_contact_date) { 
    if(!cJSON_IsString(last_contact_date))
    {
    goto end; //Date
    }
    }

    // contact_create->last_purchase_date
    cJSON *last_purchase_date = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "lastPurchaseDate");
    if (cJSON_IsNull(last_purchase_date)) {
        last_purchase_date = NULL;
    }
    if (last_purchase_date) { 
    if(!cJSON_IsString(last_purchase_date))
    {
    goto end; //Date
    }
    }

    // contact_create->leitweg_id
    cJSON *leitweg_id = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "leitwegId");
    if (cJSON_IsNull(leitweg_id)) {
        leitweg_id = NULL;
    }
    if (leitweg_id) { 
    if(!cJSON_IsString(leitweg_id) && !cJSON_IsNull(leitweg_id))
    {
    goto end; //String
    }
    }

    // contact_create->lifetime_value
    cJSON *lifetime_value = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "lifetimeValue");
    if (cJSON_IsNull(lifetime_value)) {
        lifetime_value = NULL;
    }
    if (lifetime_value) { 
    if(!cJSON_IsString(lifetime_value) && !cJSON_IsNull(lifetime_value))
    {
    goto end; //String
    }
    }

    // contact_create->mandate_date
    cJSON *mandate_date = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "mandateDate");
    if (cJSON_IsNull(mandate_date)) {
        mandate_date = NULL;
    }
    if (mandate_date) { 
    if(!cJSON_IsString(mandate_date))
    {
    goto end; //Date
    }
    }

    // contact_create->mandate_reference
    cJSON *mandate_reference = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "mandateReference");
    if (cJSON_IsNull(mandate_reference)) {
        mandate_reference = NULL;
    }
    if (mandate_reference) { 
    if(!cJSON_IsString(mandate_reference) && !cJSON_IsNull(mandate_reference))
    {
    goto end; //String
    }
    }

    // contact_create->marketing_consent
    cJSON *marketing_consent = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "marketingConsent");
    if (cJSON_IsNull(marketing_consent)) {
        marketing_consent = NULL;
    }
    if (marketing_consent) { 
    if(!cJSON_IsBool(marketing_consent))
    {
    goto end; //Bool
    }
    marketing_consent_local_var = malloc(sizeof(int));
    if(!marketing_consent_local_var)
    {
        goto end;
    }
    *marketing_consent_local_var = marketing_consent->valueint;
    }

    // contact_create->marketing_consent_at
    cJSON *marketing_consent_at = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "marketingConsentAt");
    if (cJSON_IsNull(marketing_consent_at)) {
        marketing_consent_at = NULL;
    }
    if (marketing_consent_at) { 
    if(!cJSON_IsString(marketing_consent_at) && !cJSON_IsNull(marketing_consent_at))
    {
    goto end; //DateTime
    }
    }

    // contact_create->marketing_consent_source
    cJSON *marketing_consent_source = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "marketingConsentSource");
    if (cJSON_IsNull(marketing_consent_source)) {
        marketing_consent_source = NULL;
    }
    if (marketing_consent_source) { 
    if(!cJSON_IsString(marketing_consent_source) && !cJSON_IsNull(marketing_consent_source))
    {
    goto end; //String
    }
    }

    // contact_create->mobile
    cJSON *mobile = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "mobile");
    if (cJSON_IsNull(mobile)) {
        mobile = NULL;
    }
    if (mobile) { 
    if(!cJSON_IsString(mobile) && !cJSON_IsNull(mobile))
    {
    goto end; //String
    }
    }

    // contact_create->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // contact_create->next_contact_date
    cJSON *next_contact_date = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "nextContactDate");
    if (cJSON_IsNull(next_contact_date)) {
        next_contact_date = NULL;
    }
    if (next_contact_date) { 
    if(!cJSON_IsString(next_contact_date))
    {
    goto end; //Date
    }
    }

    // contact_create->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // contact_create->opening_balance
    cJSON *opening_balance = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "openingBalance");
    if (cJSON_IsNull(opening_balance)) {
        opening_balance = NULL;
    }
    if (opening_balance) { 
    if(!cJSON_IsString(opening_balance) && !cJSON_IsNull(opening_balance))
    {
    goto end; //String
    }
    }

    // contact_create->opening_balance_date
    cJSON *opening_balance_date = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "openingBalanceDate");
    if (cJSON_IsNull(opening_balance_date)) {
        opening_balance_date = NULL;
    }
    if (opening_balance_date) { 
    if(!cJSON_IsString(opening_balance_date))
    {
    goto end; //Date
    }
    }

    // contact_create->order_reference
    cJSON *order_reference = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "orderReference");
    if (cJSON_IsNull(order_reference)) {
        order_reference = NULL;
    }
    if (order_reference) { 
    if(!cJSON_IsString(order_reference) && !cJSON_IsNull(order_reference))
    {
    goto end; //String
    }
    }

    // contact_create->payment_block
    cJSON *payment_block = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "paymentBlock");
    if (cJSON_IsNull(payment_block)) {
        payment_block = NULL;
    }
    if (payment_block) { 
    if(!cJSON_IsBool(payment_block))
    {
    goto end; //Bool
    }
    payment_block_local_var = malloc(sizeof(int));
    if(!payment_block_local_var)
    {
        goto end;
    }
    *payment_block_local_var = payment_block->valueint;
    }

    // contact_create->payment_grace_period_days
    cJSON *payment_grace_period_days = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "paymentGracePeriodDays");
    if (cJSON_IsNull(payment_grace_period_days)) {
        payment_grace_period_days = NULL;
    }
    if (payment_grace_period_days) { 
    if(!cJSON_IsNumber(payment_grace_period_days))
    {
    goto end; //Numeric
    }
    payment_grace_period_days_local_var = malloc(sizeof(int));
    if(!payment_grace_period_days_local_var)
    {
        goto end;
    }
    *payment_grace_period_days_local_var = payment_grace_period_days->valuedouble;
    }

    // contact_create->payment_methods
    cJSON *payment_methods = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "paymentMethods");
    if (cJSON_IsNull(payment_methods)) {
        payment_methods = NULL;
    }
    if (payment_methods) { 
    cJSON *payment_methods_local = NULL;
    if(!cJSON_IsArray(payment_methods)) {
        goto end;//primitive container
    }
    payment_methodsList = list_createList();

    cJSON_ArrayForEach(payment_methods_local, payment_methods)
    {
        if(!cJSON_IsString(payment_methods_local))
        {
            goto end;
        }
        list_addElement(payment_methodsList , strdup(payment_methods_local->valuestring));
    }
    }

    // contact_create->payment_terms
    cJSON *payment_terms = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "paymentTerms");
    if (cJSON_IsNull(payment_terms)) {
        payment_terms = NULL;
    }
    if (payment_terms) { 
    if(!cJSON_IsString(payment_terms) && !cJSON_IsNull(payment_terms))
    {
    goto end; //String
    }
    }

    // contact_create->phone
    cJSON *phone = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "phone");
    if (cJSON_IsNull(phone)) {
        phone = NULL;
    }
    if (phone) { 
    if(!cJSON_IsString(phone) && !cJSON_IsNull(phone))
    {
    goto end; //String
    }
    }

    // contact_create->rating
    cJSON *rating = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "rating");
    if (cJSON_IsNull(rating)) {
        rating = NULL;
    }
    if (rating) { 
    if(!cJSON_IsNumber(rating))
    {
    goto end; //Numeric
    }
    rating_local_var = malloc(sizeof(int));
    if(!rating_local_var)
    {
        goto end;
    }
    *rating_local_var = rating->valuedouble;
    }

    // contact_create->sales_representative
    cJSON *sales_representative = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "salesRepresentative");
    if (cJSON_IsNull(sales_representative)) {
        sales_representative = NULL;
    }
    if (sales_representative) { 
    if(!cJSON_IsString(sales_representative) && !cJSON_IsNull(sales_representative))
    {
    goto end; //String
    }
    }

    // contact_create->sepa_batch_booking
    cJSON *sepa_batch_booking = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "sepaBatchBooking");
    if (cJSON_IsNull(sepa_batch_booking)) {
        sepa_batch_booking = NULL;
    }
    if (sepa_batch_booking) { 
    if(!cJSON_IsBool(sepa_batch_booking))
    {
    goto end; //Bool
    }
    sepa_batch_booking_local_var = malloc(sizeof(int));
    if(!sepa_batch_booking_local_var)
    {
        goto end;
    }
    *sepa_batch_booking_local_var = sepa_batch_booking->valueint;
    }

    // contact_create->sepa_sequence_type
    cJSON *sepa_sequence_type = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "sepaSequenceType");
    if (cJSON_IsNull(sepa_sequence_type)) {
        sepa_sequence_type = NULL;
    }
    if (sepa_sequence_type) { 
    sepa_sequence_type_local_nonprim = sepa_sequence_type_parseFromJSON(sepa_sequence_type); //custom
    }

    // contact_create->social_media
    cJSON *social_media = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "socialMedia");
    if (cJSON_IsNull(social_media)) {
        social_media = NULL;
    }
    if (social_media) { 
    social_media_local_nonprim = _parseFromJSON(social_media); //custom
    }

    // contact_create->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "source");
    if (cJSON_IsNull(source)) {
        source = NULL;
    }
    if (source) { 
    if(!cJSON_IsString(source) && !cJSON_IsNull(source))
    {
    goto end; //String
    }
    }

    // contact_create->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    if (state) { 
    if(!cJSON_IsString(state) && !cJSON_IsNull(state))
    {
    goto end; //String
    }
    }

    // contact_create->street
    cJSON *street = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "street");
    if (cJSON_IsNull(street)) {
        street = NULL;
    }
    if (street) { 
    if(!cJSON_IsString(street) && !cJSON_IsNull(street))
    {
    goto end; //String
    }
    }

    // contact_create->street_number
    cJSON *street_number = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "streetNumber");
    if (cJSON_IsNull(street_number)) {
        street_number = NULL;
    }
    if (street_number) { 
    if(!cJSON_IsString(street_number) && !cJSON_IsNull(street_number))
    {
    goto end; //String
    }
    }

    // contact_create->supplier_number
    cJSON *supplier_number = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "supplierNumber");
    if (cJSON_IsNull(supplier_number)) {
        supplier_number = NULL;
    }
    if (supplier_number) { 
    if(!cJSON_IsString(supplier_number) && !cJSON_IsNull(supplier_number))
    {
    goto end; //String
    }
    }

    // contact_create->tags
    cJSON *tags = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "tags");
    if (cJSON_IsNull(tags)) {
        tags = NULL;
    }
    if (tags) { 
    cJSON *tags_local = NULL;
    if(!cJSON_IsArray(tags)) {
        goto end;//primitive container
    }
    tagsList = list_createList();

    cJSON_ArrayForEach(tags_local, tags)
    {
        if(!cJSON_IsString(tags_local))
        {
            goto end;
        }
        list_addElement(tagsList , strdup(tags_local->valuestring));
    }
    }

    // contact_create->tax_country
    cJSON *tax_country = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "taxCountry");
    if (cJSON_IsNull(tax_country)) {
        tax_country = NULL;
    }
    if (tax_country) { 
    tax_country_local_nonprim = country_code_parseFromJSON(tax_country); //custom
    }

    // contact_create->tax_number
    cJSON *tax_number = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "taxNumber");
    if (cJSON_IsNull(tax_number)) {
        tax_number = NULL;
    }
    if (tax_number) { 
    if(!cJSON_IsString(tax_number) && !cJSON_IsNull(tax_number))
    {
    goto end; //String
    }
    }

    // contact_create->tax_office
    cJSON *tax_office = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "taxOffice");
    if (cJSON_IsNull(tax_office)) {
        tax_office = NULL;
    }
    if (tax_office) { 
    if(!cJSON_IsString(tax_office) && !cJSON_IsNull(tax_office))
    {
    goto end; //String
    }
    }

    // contact_create->total_invoices
    cJSON *total_invoices = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "totalInvoices");
    if (cJSON_IsNull(total_invoices)) {
        total_invoices = NULL;
    }
    if (total_invoices) { 
    if(!cJSON_IsNumber(total_invoices))
    {
    goto end; //Numeric
    }
    total_invoices_local_var = malloc(sizeof(int));
    if(!total_invoices_local_var)
    {
        goto end;
    }
    *total_invoices_local_var = total_invoices->valuedouble;
    }

    // contact_create->total_revenue
    cJSON *total_revenue = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "totalRevenue");
    if (cJSON_IsNull(total_revenue)) {
        total_revenue = NULL;
    }
    if (total_revenue) { 
    if(!cJSON_IsString(total_revenue) && !cJSON_IsNull(total_revenue))
    {
    goto end; //String
    }
    }

    // contact_create->vat_id
    cJSON *vat_id = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "vatId");
    if (cJSON_IsNull(vat_id)) {
        vat_id = NULL;
    }
    if (vat_id) { 
    if(!cJSON_IsString(vat_id) && !cJSON_IsNull(vat_id))
    {
    goto end; //String
    }
    }

    // contact_create->vat_id_validated
    cJSON *vat_id_validated = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "vatIdValidated");
    if (cJSON_IsNull(vat_id_validated)) {
        vat_id_validated = NULL;
    }
    if (vat_id_validated) { 
    if(!cJSON_IsBool(vat_id_validated))
    {
    goto end; //Bool
    }
    vat_id_validated_local_var = malloc(sizeof(int));
    if(!vat_id_validated_local_var)
    {
        goto end;
    }
    *vat_id_validated_local_var = vat_id_validated->valueint;
    }

    // contact_create->vat_id_validation_date
    cJSON *vat_id_validation_date = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "vatIdValidationDate");
    if (cJSON_IsNull(vat_id_validation_date)) {
        vat_id_validation_date = NULL;
    }
    if (vat_id_validation_date) { 
    if(!cJSON_IsString(vat_id_validation_date))
    {
    goto end; //Date
    }
    }

    // contact_create->website
    cJSON *website = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "website");
    if (cJSON_IsNull(website)) {
        website = NULL;
    }
    if (website) { 
    if(!cJSON_IsString(website) && !cJSON_IsNull(website))
    {
    goto end; //String
    }
    }

    // contact_create->zip
    cJSON *zip = cJSON_GetObjectItemCaseSensitive(contact_createJSON, "zip");
    if (cJSON_IsNull(zip)) {
        zip = NULL;
    }
    if (zip) { 
    if(!cJSON_IsString(zip) && !cJSON_IsNull(zip))
    {
    goto end; //String
    }
    }


    if (account_holder && !cJSON_IsNull(account_holder)) account_holder_local_str = strdup(account_holder->valuestring);
    if (acquisition_cost && !cJSON_IsNull(acquisition_cost)) acquisition_cost_local_str = strdup(acquisition_cost->valuestring);
    if (address_supplement && !cJSON_IsNull(address_supplement)) address_supplement_local_str = strdup(address_supplement->valuestring);
    if (attention && !cJSON_IsNull(attention)) attention_local_str = strdup(attention->valuestring);
    if (bank_name && !cJSON_IsNull(bank_name)) bank_name_local_str = strdup(bank_name->valuestring);
    if (bic && !cJSON_IsNull(bic)) bic_local_str = strdup(bic->valuestring);
    if (buyer_reference && !cJSON_IsNull(buyer_reference)) buyer_reference_local_str = strdup(buyer_reference->valuestring);
    if (category && !cJSON_IsNull(category)) category_local_str = strdup(category->valuestring);
    if (certificate_authority && !cJSON_IsNull(certificate_authority)) certificate_authority_local_str = strdup(certificate_authority->valuestring);
    if (certificate_number && !cJSON_IsNull(certificate_number)) certificate_number_local_str = strdup(certificate_number->valuestring);
    if (certificate_paragraph && !cJSON_IsNull(certificate_paragraph)) certificate_paragraph_local_str = strdup(certificate_paragraph->valuestring);
    if (certificate_valid_until) certificate_valid_until_local_str = strdup(certificate_valid_until->valuestring);
    if (city && !cJSON_IsNull(city)) city_local_str = strdup(city->valuestring);
    if (company_name && !cJSON_IsNull(company_name)) company_name_local_str = strdup(company_name->valuestring);
    if (credit_limit && !cJSON_IsNull(credit_limit)) credit_limit_local_str = strdup(credit_limit->valuestring);
    if (creditor_account_skr03 && !cJSON_IsNull(creditor_account_skr03)) creditor_account_skr03_local_str = strdup(creditor_account_skr03->valuestring);
    if (creditor_account_skr04 && !cJSON_IsNull(creditor_account_skr04)) creditor_account_skr04_local_str = strdup(creditor_account_skr04->valuestring);
    if (currency && !cJSON_IsNull(currency)) currency_local_str = strdup(currency->valuestring);
    if (customer_number && !cJSON_IsNull(customer_number)) customer_number_local_str = strdup(customer_number->valuestring);
    if (debitor_account_skr03 && !cJSON_IsNull(debitor_account_skr03)) debitor_account_skr03_local_str = strdup(debitor_account_skr03->valuestring);
    if (debitor_account_skr04 && !cJSON_IsNull(debitor_account_skr04)) debitor_account_skr04_local_str = strdup(debitor_account_skr04->valuestring);
    if (default_debitor_number && !cJSON_IsNull(default_debitor_number)) default_debitor_number_local_str = strdup(default_debitor_number->valuestring);
    if (department && !cJSON_IsNull(department)) department_local_str = strdup(department->valuestring);
    if (discount_percentage && !cJSON_IsNull(discount_percentage)) discount_percentage_local_str = strdup(discount_percentage->valuestring);
    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);
    if (external_id && !cJSON_IsNull(external_id)) external_id_local_str = strdup(external_id->valuestring);
    if (fax && !cJSON_IsNull(fax)) fax_local_str = strdup(fax->valuestring);
    if (iban && !cJSON_IsNull(iban)) iban_local_str = strdup(iban->valuestring);
    if (industry && !cJSON_IsNull(industry)) industry_local_str = strdup(industry->valuestring);
    if (last_contact_date) last_contact_date_local_str = strdup(last_contact_date->valuestring);
    if (last_purchase_date) last_purchase_date_local_str = strdup(last_purchase_date->valuestring);
    if (leitweg_id && !cJSON_IsNull(leitweg_id)) leitweg_id_local_str = strdup(leitweg_id->valuestring);
    if (lifetime_value && !cJSON_IsNull(lifetime_value)) lifetime_value_local_str = strdup(lifetime_value->valuestring);
    if (mandate_date) mandate_date_local_str = strdup(mandate_date->valuestring);
    if (mandate_reference && !cJSON_IsNull(mandate_reference)) mandate_reference_local_str = strdup(mandate_reference->valuestring);
    if (marketing_consent_at && !cJSON_IsNull(marketing_consent_at)) marketing_consent_at_local_str = strdup(marketing_consent_at->valuestring);
    if (marketing_consent_source && !cJSON_IsNull(marketing_consent_source)) marketing_consent_source_local_str = strdup(marketing_consent_source->valuestring);
    if (mobile && !cJSON_IsNull(mobile)) mobile_local_str = strdup(mobile->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (next_contact_date) next_contact_date_local_str = strdup(next_contact_date->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (opening_balance && !cJSON_IsNull(opening_balance)) opening_balance_local_str = strdup(opening_balance->valuestring);
    if (opening_balance_date) opening_balance_date_local_str = strdup(opening_balance_date->valuestring);
    if (order_reference && !cJSON_IsNull(order_reference)) order_reference_local_str = strdup(order_reference->valuestring);
    if (payment_terms && !cJSON_IsNull(payment_terms)) payment_terms_local_str = strdup(payment_terms->valuestring);
    if (phone && !cJSON_IsNull(phone)) phone_local_str = strdup(phone->valuestring);
    if (sales_representative && !cJSON_IsNull(sales_representative)) sales_representative_local_str = strdup(sales_representative->valuestring);
    if (source && !cJSON_IsNull(source)) source_local_str = strdup(source->valuestring);
    if (state && !cJSON_IsNull(state)) state_local_str = strdup(state->valuestring);
    if (street && !cJSON_IsNull(street)) street_local_str = strdup(street->valuestring);
    if (street_number && !cJSON_IsNull(street_number)) street_number_local_str = strdup(street_number->valuestring);
    if (supplier_number && !cJSON_IsNull(supplier_number)) supplier_number_local_str = strdup(supplier_number->valuestring);
    if (tax_number && !cJSON_IsNull(tax_number)) tax_number_local_str = strdup(tax_number->valuestring);
    if (tax_office && !cJSON_IsNull(tax_office)) tax_office_local_str = strdup(tax_office->valuestring);
    if (total_revenue && !cJSON_IsNull(total_revenue)) total_revenue_local_str = strdup(total_revenue->valuestring);
    if (vat_id && !cJSON_IsNull(vat_id)) vat_id_local_str = strdup(vat_id->valuestring);
    if (vat_id_validation_date) vat_id_validation_date_local_str = strdup(vat_id_validation_date->valuestring);
    if (website && !cJSON_IsNull(website)) website_local_str = strdup(website->valuestring);
    if (zip && !cJSON_IsNull(zip)) zip_local_str = strdup(zip->valuestring);

    contact_create_local_var = contact_create_create_internal (
        account_holder_local_str,
        acquisition_cost_local_str,
        address_supplement_local_str,
        attention_local_str,
        bank_name_local_str,
        bic_local_str,
        buyer_reference_local_str,
        category_local_str,
        certificate_authority_local_str,
        certificate_number_local_str,
        certificate_paragraph_local_str,
        certificate_valid_until_local_str,
        city_local_str,
        company_name_local_str,
        contact_persons ? contact_persons_local_nonprim : NULL,
        contact_type_local_nonprim,
        country ? country_local_nonprim : NULL,
        credit_limit_local_str,
        creditor_account_skr03_local_str,
        creditor_account_skr04_local_str,
        currency_local_str,
        custom_fields ? custom_fields_local_nonprim : NULL,
        customer_number_local_str,
        debitor_account_skr03_local_str,
        debitor_account_skr04_local_str,
        default_debitor_number_local_str,
        delivery_block_local_var,
        department_local_str,
        discount_days_local_var,
        discount_percentage_local_str,
        donation_receipt_eligible_local_var,
        email_local_str,
        external_id_local_str,
        fax_local_str,
        iban_local_str,
        industry_local_str,
        is_active_local_var,
        is_member_local_var,
        is_nonprofit_local_var,
        last_contact_date_local_str,
        last_purchase_date_local_str,
        leitweg_id_local_str,
        lifetime_value_local_str,
        mandate_date_local_str,
        mandate_reference_local_str,
        marketing_consent_local_var,
        marketing_consent_at_local_str,
        marketing_consent_source_local_str,
        mobile_local_str,
        name_local_str,
        next_contact_date_local_str,
        notes_local_str,
        opening_balance_local_str,
        opening_balance_date_local_str,
        order_reference_local_str,
        payment_block_local_var,
        payment_grace_period_days_local_var,
        payment_methods ? payment_methodsList : NULL,
        payment_terms_local_str,
        phone_local_str,
        rating_local_var,
        sales_representative_local_str,
        sepa_batch_booking_local_var,
        sepa_sequence_type ? sepa_sequence_type_local_nonprim : NULL,
        social_media ? social_media_local_nonprim : NULL,
        source_local_str,
        state_local_str,
        street_local_str,
        street_number_local_str,
        supplier_number_local_str,
        tags ? tagsList : NULL,
        tax_country ? tax_country_local_nonprim : NULL,
        tax_number_local_str,
        tax_office_local_str,
        total_invoices_local_var,
        total_revenue_local_str,
        vat_id_local_str,
        vat_id_validated_local_var,
        vat_id_validation_date_local_str,
        website_local_str,
        zip_local_str
        );

    if (!contact_create_local_var) {
        goto end;
    }

    return contact_create_local_var;
end:
    if (account_holder_local_str) {
        free(account_holder_local_str);
        account_holder_local_str = NULL;
    }
    if (acquisition_cost_local_str) {
        free(acquisition_cost_local_str);
        acquisition_cost_local_str = NULL;
    }
    if (address_supplement_local_str) {
        free(address_supplement_local_str);
        address_supplement_local_str = NULL;
    }
    if (attention_local_str) {
        free(attention_local_str);
        attention_local_str = NULL;
    }
    if (bank_name_local_str) {
        free(bank_name_local_str);
        bank_name_local_str = NULL;
    }
    if (bic_local_str) {
        free(bic_local_str);
        bic_local_str = NULL;
    }
    if (buyer_reference_local_str) {
        free(buyer_reference_local_str);
        buyer_reference_local_str = NULL;
    }
    if (category_local_str) {
        free(category_local_str);
        category_local_str = NULL;
    }
    if (certificate_authority_local_str) {
        free(certificate_authority_local_str);
        certificate_authority_local_str = NULL;
    }
    if (certificate_number_local_str) {
        free(certificate_number_local_str);
        certificate_number_local_str = NULL;
    }
    if (certificate_paragraph_local_str) {
        free(certificate_paragraph_local_str);
        certificate_paragraph_local_str = NULL;
    }
    if (certificate_valid_until_local_str) {
        free(certificate_valid_until_local_str);
        certificate_valid_until_local_str = NULL;
    }
    if (city_local_str) {
        free(city_local_str);
        city_local_str = NULL;
    }
    if (company_name_local_str) {
        free(company_name_local_str);
        company_name_local_str = NULL;
    }
    if (contact_persons_local_nonprim) {
        _free(contact_persons_local_nonprim);
        contact_persons_local_nonprim = NULL;
    }
    if (contact_type_local_nonprim) {
        contact_type_local_nonprim = 0;
    }
    if (country_local_nonprim) {
        country_code_free(country_local_nonprim);
        country_local_nonprim = NULL;
    }
    if (credit_limit_local_str) {
        free(credit_limit_local_str);
        credit_limit_local_str = NULL;
    }
    if (creditor_account_skr03_local_str) {
        free(creditor_account_skr03_local_str);
        creditor_account_skr03_local_str = NULL;
    }
    if (creditor_account_skr04_local_str) {
        free(creditor_account_skr04_local_str);
        creditor_account_skr04_local_str = NULL;
    }
    if (currency_local_str) {
        free(currency_local_str);
        currency_local_str = NULL;
    }
    if (custom_fields_local_nonprim) {
        _free(custom_fields_local_nonprim);
        custom_fields_local_nonprim = NULL;
    }
    if (customer_number_local_str) {
        free(customer_number_local_str);
        customer_number_local_str = NULL;
    }
    if (debitor_account_skr03_local_str) {
        free(debitor_account_skr03_local_str);
        debitor_account_skr03_local_str = NULL;
    }
    if (debitor_account_skr04_local_str) {
        free(debitor_account_skr04_local_str);
        debitor_account_skr04_local_str = NULL;
    }
    if (default_debitor_number_local_str) {
        free(default_debitor_number_local_str);
        default_debitor_number_local_str = NULL;
    }
    if (delivery_block_local_var) {
        free(delivery_block_local_var);
        delivery_block_local_var = NULL;
    }
    if (department_local_str) {
        free(department_local_str);
        department_local_str = NULL;
    }
    if (discount_days_local_var) {
        free(discount_days_local_var);
        discount_days_local_var = NULL;
    }
    if (discount_percentage_local_str) {
        free(discount_percentage_local_str);
        discount_percentage_local_str = NULL;
    }
    if (donation_receipt_eligible_local_var) {
        free(donation_receipt_eligible_local_var);
        donation_receipt_eligible_local_var = NULL;
    }
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    if (external_id_local_str) {
        free(external_id_local_str);
        external_id_local_str = NULL;
    }
    if (fax_local_str) {
        free(fax_local_str);
        fax_local_str = NULL;
    }
    if (iban_local_str) {
        free(iban_local_str);
        iban_local_str = NULL;
    }
    if (industry_local_str) {
        free(industry_local_str);
        industry_local_str = NULL;
    }
    if (is_active_local_var) {
        free(is_active_local_var);
        is_active_local_var = NULL;
    }
    if (is_member_local_var) {
        free(is_member_local_var);
        is_member_local_var = NULL;
    }
    if (is_nonprofit_local_var) {
        free(is_nonprofit_local_var);
        is_nonprofit_local_var = NULL;
    }
    if (last_contact_date_local_str) {
        free(last_contact_date_local_str);
        last_contact_date_local_str = NULL;
    }
    if (last_purchase_date_local_str) {
        free(last_purchase_date_local_str);
        last_purchase_date_local_str = NULL;
    }
    if (leitweg_id_local_str) {
        free(leitweg_id_local_str);
        leitweg_id_local_str = NULL;
    }
    if (lifetime_value_local_str) {
        free(lifetime_value_local_str);
        lifetime_value_local_str = NULL;
    }
    if (mandate_date_local_str) {
        free(mandate_date_local_str);
        mandate_date_local_str = NULL;
    }
    if (mandate_reference_local_str) {
        free(mandate_reference_local_str);
        mandate_reference_local_str = NULL;
    }
    if (marketing_consent_local_var) {
        free(marketing_consent_local_var);
        marketing_consent_local_var = NULL;
    }
    if (marketing_consent_at_local_str) {
        free(marketing_consent_at_local_str);
        marketing_consent_at_local_str = NULL;
    }
    if (marketing_consent_source_local_str) {
        free(marketing_consent_source_local_str);
        marketing_consent_source_local_str = NULL;
    }
    if (mobile_local_str) {
        free(mobile_local_str);
        mobile_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (next_contact_date_local_str) {
        free(next_contact_date_local_str);
        next_contact_date_local_str = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (opening_balance_local_str) {
        free(opening_balance_local_str);
        opening_balance_local_str = NULL;
    }
    if (opening_balance_date_local_str) {
        free(opening_balance_date_local_str);
        opening_balance_date_local_str = NULL;
    }
    if (order_reference_local_str) {
        free(order_reference_local_str);
        order_reference_local_str = NULL;
    }
    if (payment_block_local_var) {
        free(payment_block_local_var);
        payment_block_local_var = NULL;
    }
    if (payment_grace_period_days_local_var) {
        free(payment_grace_period_days_local_var);
        payment_grace_period_days_local_var = NULL;
    }
    if (payment_methodsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, payment_methodsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(payment_methodsList);
        payment_methodsList = NULL;
    }
    if (payment_terms_local_str) {
        free(payment_terms_local_str);
        payment_terms_local_str = NULL;
    }
    if (phone_local_str) {
        free(phone_local_str);
        phone_local_str = NULL;
    }
    if (rating_local_var) {
        free(rating_local_var);
        rating_local_var = NULL;
    }
    if (sales_representative_local_str) {
        free(sales_representative_local_str);
        sales_representative_local_str = NULL;
    }
    if (sepa_batch_booking_local_var) {
        free(sepa_batch_booking_local_var);
        sepa_batch_booking_local_var = NULL;
    }
    if (sepa_sequence_type_local_nonprim) {
        sepa_sequence_type_free(sepa_sequence_type_local_nonprim);
        sepa_sequence_type_local_nonprim = NULL;
    }
    if (social_media_local_nonprim) {
        _free(social_media_local_nonprim);
        social_media_local_nonprim = NULL;
    }
    if (source_local_str) {
        free(source_local_str);
        source_local_str = NULL;
    }
    if (state_local_str) {
        free(state_local_str);
        state_local_str = NULL;
    }
    if (street_local_str) {
        free(street_local_str);
        street_local_str = NULL;
    }
    if (street_number_local_str) {
        free(street_number_local_str);
        street_number_local_str = NULL;
    }
    if (supplier_number_local_str) {
        free(supplier_number_local_str);
        supplier_number_local_str = NULL;
    }
    if (tagsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, tagsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(tagsList);
        tagsList = NULL;
    }
    if (tax_country_local_nonprim) {
        country_code_free(tax_country_local_nonprim);
        tax_country_local_nonprim = NULL;
    }
    if (tax_number_local_str) {
        free(tax_number_local_str);
        tax_number_local_str = NULL;
    }
    if (tax_office_local_str) {
        free(tax_office_local_str);
        tax_office_local_str = NULL;
    }
    if (total_invoices_local_var) {
        free(total_invoices_local_var);
        total_invoices_local_var = NULL;
    }
    if (total_revenue_local_str) {
        free(total_revenue_local_str);
        total_revenue_local_str = NULL;
    }
    if (vat_id_local_str) {
        free(vat_id_local_str);
        vat_id_local_str = NULL;
    }
    if (vat_id_validated_local_var) {
        free(vat_id_validated_local_var);
        vat_id_validated_local_var = NULL;
    }
    if (vat_id_validation_date_local_str) {
        free(vat_id_validation_date_local_str);
        vat_id_validation_date_local_str = NULL;
    }
    if (website_local_str) {
        free(website_local_str);
        website_local_str = NULL;
    }
    if (zip_local_str) {
        free(zip_local_str);
        zip_local_str = NULL;
    }
    return NULL;

}
