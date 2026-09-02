#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "contact.h"



static contact_t *contact_create_internal(
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
    char *contact_id,
    any_type_t *contact_persons,
    char *contact_type,
    char *country,
    char *created_at,
    char *credit_limit,
    char *creditor_account_skr03,
    char *creditor_account_skr04,
    char *currency,
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
    any_type_t *social_media,
    char *source,
    char *state,
    char *street,
    char *street_number,
    char *supplier_number,
    list_t *tags,
    char *tax_country,
    char *tax_number,
    char *tax_office,
    int *total_invoices,
    char *total_revenue,
    char *updated_at,
    char *vat_id,
    int *vat_id_validated,
    char *vat_id_validation_date,
    char *website,
    char *zip
    ) {
    contact_t *contact_local_var = malloc(sizeof(contact_t));
    if (!contact_local_var) {
        return NULL;
    }
    memset(contact_local_var, 0, sizeof(contact_t));
    contact_local_var->_library_owned = 1;
    contact_local_var->account_holder = account_holder;
    contact_local_var->acquisition_cost = acquisition_cost;
    contact_local_var->address_supplement = address_supplement;
    contact_local_var->attention = attention;
    contact_local_var->bank_name = bank_name;
    contact_local_var->bic = bic;
    contact_local_var->buyer_reference = buyer_reference;
    contact_local_var->category = category;
    contact_local_var->certificate_authority = certificate_authority;
    contact_local_var->certificate_number = certificate_number;
    contact_local_var->certificate_paragraph = certificate_paragraph;
    contact_local_var->certificate_valid_until = certificate_valid_until;
    contact_local_var->city = city;
    contact_local_var->company_name = company_name;
    contact_local_var->contact_id = contact_id;
    contact_local_var->contact_persons = contact_persons;
    contact_local_var->contact_type = contact_type;
    contact_local_var->country = country;
    contact_local_var->created_at = created_at;
    contact_local_var->credit_limit = credit_limit;
    contact_local_var->creditor_account_skr03 = creditor_account_skr03;
    contact_local_var->creditor_account_skr04 = creditor_account_skr04;
    contact_local_var->currency = currency;
    contact_local_var->customer_number = customer_number;
    contact_local_var->debitor_account_skr03 = debitor_account_skr03;
    contact_local_var->debitor_account_skr04 = debitor_account_skr04;
    contact_local_var->default_debitor_number = default_debitor_number;
    contact_local_var->delivery_block = delivery_block;
    contact_local_var->department = department;
    contact_local_var->discount_days = discount_days;
    contact_local_var->discount_percentage = discount_percentage;
    contact_local_var->donation_receipt_eligible = donation_receipt_eligible;
    contact_local_var->email = email;
    contact_local_var->external_id = external_id;
    contact_local_var->fax = fax;
    contact_local_var->iban = iban;
    contact_local_var->industry = industry;
    contact_local_var->is_active = is_active;
    contact_local_var->is_member = is_member;
    contact_local_var->is_nonprofit = is_nonprofit;
    contact_local_var->last_contact_date = last_contact_date;
    contact_local_var->last_purchase_date = last_purchase_date;
    contact_local_var->leitweg_id = leitweg_id;
    contact_local_var->lifetime_value = lifetime_value;
    contact_local_var->mandate_date = mandate_date;
    contact_local_var->mandate_reference = mandate_reference;
    contact_local_var->marketing_consent = marketing_consent;
    contact_local_var->marketing_consent_at = marketing_consent_at;
    contact_local_var->marketing_consent_source = marketing_consent_source;
    contact_local_var->mobile = mobile;
    contact_local_var->name = name;
    contact_local_var->next_contact_date = next_contact_date;
    contact_local_var->notes = notes;
    contact_local_var->opening_balance = opening_balance;
    contact_local_var->opening_balance_date = opening_balance_date;
    contact_local_var->order_reference = order_reference;
    contact_local_var->payment_block = payment_block;
    contact_local_var->payment_grace_period_days = payment_grace_period_days;
    contact_local_var->payment_methods = payment_methods;
    contact_local_var->payment_terms = payment_terms;
    contact_local_var->phone = phone;
    contact_local_var->rating = rating;
    contact_local_var->sales_representative = sales_representative;
    contact_local_var->social_media = social_media;
    contact_local_var->source = source;
    contact_local_var->state = state;
    contact_local_var->street = street;
    contact_local_var->street_number = street_number;
    contact_local_var->supplier_number = supplier_number;
    contact_local_var->tags = tags;
    contact_local_var->tax_country = tax_country;
    contact_local_var->tax_number = tax_number;
    contact_local_var->tax_office = tax_office;
    contact_local_var->total_invoices = total_invoices;
    contact_local_var->total_revenue = total_revenue;
    contact_local_var->updated_at = updated_at;
    contact_local_var->vat_id = vat_id;
    contact_local_var->vat_id_validated = vat_id_validated;
    contact_local_var->vat_id_validation_date = vat_id_validation_date;
    contact_local_var->website = website;
    contact_local_var->zip = zip;
    return contact_local_var;
}

__attribute__((deprecated)) contact_t *contact_create(
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
    char *contact_id,
    any_type_t *contact_persons,
    char *contact_type,
    char *country,
    char *created_at,
    char *credit_limit,
    char *creditor_account_skr03,
    char *creditor_account_skr04,
    char *currency,
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
    any_type_t *social_media,
    char *source,
    char *state,
    char *street,
    char *street_number,
    char *supplier_number,
    list_t *tags,
    char *tax_country,
    char *tax_number,
    char *tax_office,
    int *total_invoices,
    char *total_revenue,
    char *updated_at,
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
    contact_t *result = contact_create_internal (
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
        contact_id,
        contact_persons,
        contact_type,
        country,
        created_at,
        credit_limit,
        creditor_account_skr03,
        creditor_account_skr04,
        currency,
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
        updated_at,
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
        free(total_invoices_copy);
        free(vat_id_validated_copy);
    }
    return result;
}

void contact_free(contact_t *contact) {
    if(NULL == contact){
        return ;
    }
    if(contact->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "contact_free");
        return ;
    }
    listEntry_t *listEntry;
    if (contact->account_holder) {
        free(contact->account_holder);
        contact->account_holder = NULL;
    }
    if (contact->acquisition_cost) {
        free(contact->acquisition_cost);
        contact->acquisition_cost = NULL;
    }
    if (contact->address_supplement) {
        free(contact->address_supplement);
        contact->address_supplement = NULL;
    }
    if (contact->attention) {
        free(contact->attention);
        contact->attention = NULL;
    }
    if (contact->bank_name) {
        free(contact->bank_name);
        contact->bank_name = NULL;
    }
    if (contact->bic) {
        free(contact->bic);
        contact->bic = NULL;
    }
    if (contact->buyer_reference) {
        free(contact->buyer_reference);
        contact->buyer_reference = NULL;
    }
    if (contact->category) {
        free(contact->category);
        contact->category = NULL;
    }
    if (contact->certificate_authority) {
        free(contact->certificate_authority);
        contact->certificate_authority = NULL;
    }
    if (contact->certificate_number) {
        free(contact->certificate_number);
        contact->certificate_number = NULL;
    }
    if (contact->certificate_paragraph) {
        free(contact->certificate_paragraph);
        contact->certificate_paragraph = NULL;
    }
    if (contact->certificate_valid_until) {
        free(contact->certificate_valid_until);
        contact->certificate_valid_until = NULL;
    }
    if (contact->city) {
        free(contact->city);
        contact->city = NULL;
    }
    if (contact->company_name) {
        free(contact->company_name);
        contact->company_name = NULL;
    }
    if (contact->contact_id) {
        free(contact->contact_id);
        contact->contact_id = NULL;
    }
    if (contact->contact_persons) {
        _free(contact->contact_persons);
        contact->contact_persons = NULL;
    }
    if (contact->contact_type) {
        free(contact->contact_type);
        contact->contact_type = NULL;
    }
    if (contact->country) {
        free(contact->country);
        contact->country = NULL;
    }
    if (contact->created_at) {
        free(contact->created_at);
        contact->created_at = NULL;
    }
    if (contact->credit_limit) {
        free(contact->credit_limit);
        contact->credit_limit = NULL;
    }
    if (contact->creditor_account_skr03) {
        free(contact->creditor_account_skr03);
        contact->creditor_account_skr03 = NULL;
    }
    if (contact->creditor_account_skr04) {
        free(contact->creditor_account_skr04);
        contact->creditor_account_skr04 = NULL;
    }
    if (contact->currency) {
        free(contact->currency);
        contact->currency = NULL;
    }
    if (contact->customer_number) {
        free(contact->customer_number);
        contact->customer_number = NULL;
    }
    if (contact->debitor_account_skr03) {
        free(contact->debitor_account_skr03);
        contact->debitor_account_skr03 = NULL;
    }
    if (contact->debitor_account_skr04) {
        free(contact->debitor_account_skr04);
        contact->debitor_account_skr04 = NULL;
    }
    if (contact->default_debitor_number) {
        free(contact->default_debitor_number);
        contact->default_debitor_number = NULL;
    }
    if (contact->delivery_block) {
        free(contact->delivery_block);
        contact->delivery_block = NULL;
    }
    if (contact->department) {
        free(contact->department);
        contact->department = NULL;
    }
    if (contact->discount_days) {
        free(contact->discount_days);
        contact->discount_days = NULL;
    }
    if (contact->discount_percentage) {
        free(contact->discount_percentage);
        contact->discount_percentage = NULL;
    }
    if (contact->donation_receipt_eligible) {
        free(contact->donation_receipt_eligible);
        contact->donation_receipt_eligible = NULL;
    }
    if (contact->email) {
        free(contact->email);
        contact->email = NULL;
    }
    if (contact->external_id) {
        free(contact->external_id);
        contact->external_id = NULL;
    }
    if (contact->fax) {
        free(contact->fax);
        contact->fax = NULL;
    }
    if (contact->iban) {
        free(contact->iban);
        contact->iban = NULL;
    }
    if (contact->industry) {
        free(contact->industry);
        contact->industry = NULL;
    }
    if (contact->is_active) {
        free(contact->is_active);
        contact->is_active = NULL;
    }
    if (contact->is_member) {
        free(contact->is_member);
        contact->is_member = NULL;
    }
    if (contact->is_nonprofit) {
        free(contact->is_nonprofit);
        contact->is_nonprofit = NULL;
    }
    if (contact->last_contact_date) {
        free(contact->last_contact_date);
        contact->last_contact_date = NULL;
    }
    if (contact->last_purchase_date) {
        free(contact->last_purchase_date);
        contact->last_purchase_date = NULL;
    }
    if (contact->leitweg_id) {
        free(contact->leitweg_id);
        contact->leitweg_id = NULL;
    }
    if (contact->lifetime_value) {
        free(contact->lifetime_value);
        contact->lifetime_value = NULL;
    }
    if (contact->mandate_date) {
        free(contact->mandate_date);
        contact->mandate_date = NULL;
    }
    if (contact->mandate_reference) {
        free(contact->mandate_reference);
        contact->mandate_reference = NULL;
    }
    if (contact->marketing_consent) {
        free(contact->marketing_consent);
        contact->marketing_consent = NULL;
    }
    if (contact->marketing_consent_at) {
        free(contact->marketing_consent_at);
        contact->marketing_consent_at = NULL;
    }
    if (contact->marketing_consent_source) {
        free(contact->marketing_consent_source);
        contact->marketing_consent_source = NULL;
    }
    if (contact->mobile) {
        free(contact->mobile);
        contact->mobile = NULL;
    }
    if (contact->name) {
        free(contact->name);
        contact->name = NULL;
    }
    if (contact->next_contact_date) {
        free(contact->next_contact_date);
        contact->next_contact_date = NULL;
    }
    if (contact->notes) {
        free(contact->notes);
        contact->notes = NULL;
    }
    if (contact->opening_balance) {
        free(contact->opening_balance);
        contact->opening_balance = NULL;
    }
    if (contact->opening_balance_date) {
        free(contact->opening_balance_date);
        contact->opening_balance_date = NULL;
    }
    if (contact->order_reference) {
        free(contact->order_reference);
        contact->order_reference = NULL;
    }
    if (contact->payment_block) {
        free(contact->payment_block);
        contact->payment_block = NULL;
    }
    if (contact->payment_grace_period_days) {
        free(contact->payment_grace_period_days);
        contact->payment_grace_period_days = NULL;
    }
    if (contact->payment_methods) {
        list_ForEach(listEntry, contact->payment_methods) {
            free(listEntry->data);
        }
        list_freeList(contact->payment_methods);
        contact->payment_methods = NULL;
    }
    if (contact->payment_terms) {
        free(contact->payment_terms);
        contact->payment_terms = NULL;
    }
    if (contact->phone) {
        free(contact->phone);
        contact->phone = NULL;
    }
    if (contact->rating) {
        free(contact->rating);
        contact->rating = NULL;
    }
    if (contact->sales_representative) {
        free(contact->sales_representative);
        contact->sales_representative = NULL;
    }
    if (contact->social_media) {
        _free(contact->social_media);
        contact->social_media = NULL;
    }
    if (contact->source) {
        free(contact->source);
        contact->source = NULL;
    }
    if (contact->state) {
        free(contact->state);
        contact->state = NULL;
    }
    if (contact->street) {
        free(contact->street);
        contact->street = NULL;
    }
    if (contact->street_number) {
        free(contact->street_number);
        contact->street_number = NULL;
    }
    if (contact->supplier_number) {
        free(contact->supplier_number);
        contact->supplier_number = NULL;
    }
    if (contact->tags) {
        list_ForEach(listEntry, contact->tags) {
            free(listEntry->data);
        }
        list_freeList(contact->tags);
        contact->tags = NULL;
    }
    if (contact->tax_country) {
        free(contact->tax_country);
        contact->tax_country = NULL;
    }
    if (contact->tax_number) {
        free(contact->tax_number);
        contact->tax_number = NULL;
    }
    if (contact->tax_office) {
        free(contact->tax_office);
        contact->tax_office = NULL;
    }
    if (contact->total_invoices) {
        free(contact->total_invoices);
        contact->total_invoices = NULL;
    }
    if (contact->total_revenue) {
        free(contact->total_revenue);
        contact->total_revenue = NULL;
    }
    if (contact->updated_at) {
        free(contact->updated_at);
        contact->updated_at = NULL;
    }
    if (contact->vat_id) {
        free(contact->vat_id);
        contact->vat_id = NULL;
    }
    if (contact->vat_id_validated) {
        free(contact->vat_id_validated);
        contact->vat_id_validated = NULL;
    }
    if (contact->vat_id_validation_date) {
        free(contact->vat_id_validation_date);
        contact->vat_id_validation_date = NULL;
    }
    if (contact->website) {
        free(contact->website);
        contact->website = NULL;
    }
    if (contact->zip) {
        free(contact->zip);
        contact->zip = NULL;
    }
    free(contact);
}

cJSON *contact_convertToJSON(contact_t *contact) {
    cJSON *item = cJSON_CreateObject();

    // contact->account_holder
    if(contact->account_holder) {
    if(cJSON_AddStringToObject(item, "account_holder", contact->account_holder) == NULL) {
    goto fail; //String
    }
    }


    // contact->acquisition_cost
    if(contact->acquisition_cost) {
    if(cJSON_AddStringToObject(item, "acquisition_cost", contact->acquisition_cost) == NULL) {
    goto fail; //String
    }
    }


    // contact->address_supplement
    if(contact->address_supplement) {
    if(cJSON_AddStringToObject(item, "address_supplement", contact->address_supplement) == NULL) {
    goto fail; //String
    }
    }


    // contact->attention
    if(contact->attention) {
    if(cJSON_AddStringToObject(item, "attention", contact->attention) == NULL) {
    goto fail; //String
    }
    }


    // contact->bank_name
    if(contact->bank_name) {
    if(cJSON_AddStringToObject(item, "bank_name", contact->bank_name) == NULL) {
    goto fail; //String
    }
    }


    // contact->bic
    if(contact->bic) {
    if(cJSON_AddStringToObject(item, "bic", contact->bic) == NULL) {
    goto fail; //String
    }
    }


    // contact->buyer_reference
    if(contact->buyer_reference) {
    if(cJSON_AddStringToObject(item, "buyer_reference", contact->buyer_reference) == NULL) {
    goto fail; //String
    }
    }


    // contact->category
    if(contact->category) {
    if(cJSON_AddStringToObject(item, "category", contact->category) == NULL) {
    goto fail; //String
    }
    }


    // contact->certificate_authority
    if(contact->certificate_authority) {
    if(cJSON_AddStringToObject(item, "certificate_authority", contact->certificate_authority) == NULL) {
    goto fail; //String
    }
    }


    // contact->certificate_number
    if(contact->certificate_number) {
    if(cJSON_AddStringToObject(item, "certificate_number", contact->certificate_number) == NULL) {
    goto fail; //String
    }
    }


    // contact->certificate_paragraph
    if(contact->certificate_paragraph) {
    if(cJSON_AddStringToObject(item, "certificate_paragraph", contact->certificate_paragraph) == NULL) {
    goto fail; //String
    }
    }


    // contact->certificate_valid_until
    if(contact->certificate_valid_until) {
    if(cJSON_AddStringToObject(item, "certificate_valid_until", contact->certificate_valid_until) == NULL) {
    goto fail; //String
    }
    }


    // contact->city
    if(contact->city) {
    if(cJSON_AddStringToObject(item, "city", contact->city) == NULL) {
    goto fail; //String
    }
    }


    // contact->company_name
    if(contact->company_name) {
    if(cJSON_AddStringToObject(item, "company_name", contact->company_name) == NULL) {
    goto fail; //String
    }
    }


    // contact->contact_id
    if (!contact->contact_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "contact_id", contact->contact_id) == NULL) {
    goto fail; //String
    }


    // contact->contact_persons
    if (!contact->contact_persons) {
        goto fail;
    }
    cJSON *contact_persons_local_JSON = _convertToJSON(contact->contact_persons);
    if(contact_persons_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "contact_persons", contact_persons_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // contact->contact_type
    if (!contact->contact_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "contact_type", contact->contact_type) == NULL) {
    goto fail; //String
    }


    // contact->country
    if(contact->country) {
    if(cJSON_AddStringToObject(item, "country", contact->country) == NULL) {
    goto fail; //String
    }
    }


    // contact->created_at
    if (!contact->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "created_at", contact->created_at) == NULL) {
    goto fail; //String
    }


    // contact->credit_limit
    if(contact->credit_limit) {
    if(cJSON_AddStringToObject(item, "credit_limit", contact->credit_limit) == NULL) {
    goto fail; //String
    }
    }


    // contact->creditor_account_skr03
    if(contact->creditor_account_skr03) {
    if(cJSON_AddStringToObject(item, "creditor_account_skr03", contact->creditor_account_skr03) == NULL) {
    goto fail; //String
    }
    }


    // contact->creditor_account_skr04
    if(contact->creditor_account_skr04) {
    if(cJSON_AddStringToObject(item, "creditor_account_skr04", contact->creditor_account_skr04) == NULL) {
    goto fail; //String
    }
    }


    // contact->currency
    if(contact->currency) {
    if(cJSON_AddStringToObject(item, "currency", contact->currency) == NULL) {
    goto fail; //String
    }
    }


    // contact->customer_number
    if(contact->customer_number) {
    if(cJSON_AddStringToObject(item, "customer_number", contact->customer_number) == NULL) {
    goto fail; //String
    }
    }


    // contact->debitor_account_skr03
    if(contact->debitor_account_skr03) {
    if(cJSON_AddStringToObject(item, "debitor_account_skr03", contact->debitor_account_skr03) == NULL) {
    goto fail; //String
    }
    }


    // contact->debitor_account_skr04
    if(contact->debitor_account_skr04) {
    if(cJSON_AddStringToObject(item, "debitor_account_skr04", contact->debitor_account_skr04) == NULL) {
    goto fail; //String
    }
    }


    // contact->default_debitor_number
    if(contact->default_debitor_number) {
    if(cJSON_AddStringToObject(item, "default_debitor_number", contact->default_debitor_number) == NULL) {
    goto fail; //String
    }
    }


    // contact->delivery_block
    if(contact->delivery_block) {
    if(cJSON_AddBoolToObject(item, "delivery_block", *contact->delivery_block) == NULL) {
    goto fail; //Bool
    }
    }


    // contact->department
    if(contact->department) {
    if(cJSON_AddStringToObject(item, "department", contact->department) == NULL) {
    goto fail; //String
    }
    }


    // contact->discount_days
    if(contact->discount_days) {
    if(cJSON_AddNumberToObject(item, "discount_days", *contact->discount_days) == NULL) {
    goto fail; //Numeric
    }
    }


    // contact->discount_percentage
    if(contact->discount_percentage) {
    if(cJSON_AddStringToObject(item, "discount_percentage", contact->discount_percentage) == NULL) {
    goto fail; //String
    }
    }


    // contact->donation_receipt_eligible
    if(contact->donation_receipt_eligible) {
    if(cJSON_AddBoolToObject(item, "donation_receipt_eligible", *contact->donation_receipt_eligible) == NULL) {
    goto fail; //Bool
    }
    }


    // contact->email
    if(contact->email) {
    if(cJSON_AddStringToObject(item, "email", contact->email) == NULL) {
    goto fail; //String
    }
    }


    // contact->external_id
    if(contact->external_id) {
    if(cJSON_AddStringToObject(item, "external_id", contact->external_id) == NULL) {
    goto fail; //String
    }
    }


    // contact->fax
    if(contact->fax) {
    if(cJSON_AddStringToObject(item, "fax", contact->fax) == NULL) {
    goto fail; //String
    }
    }


    // contact->iban
    if(contact->iban) {
    if(cJSON_AddStringToObject(item, "iban", contact->iban) == NULL) {
    goto fail; //String
    }
    }


    // contact->industry
    if(contact->industry) {
    if(cJSON_AddStringToObject(item, "industry", contact->industry) == NULL) {
    goto fail; //String
    }
    }


    // contact->is_active
    if(contact->is_active) {
    if(cJSON_AddBoolToObject(item, "is_active", *contact->is_active) == NULL) {
    goto fail; //Bool
    }
    }


    // contact->is_member
    if(contact->is_member) {
    if(cJSON_AddBoolToObject(item, "is_member", *contact->is_member) == NULL) {
    goto fail; //Bool
    }
    }


    // contact->is_nonprofit
    if(contact->is_nonprofit) {
    if(cJSON_AddBoolToObject(item, "is_nonprofit", *contact->is_nonprofit) == NULL) {
    goto fail; //Bool
    }
    }


    // contact->last_contact_date
    if(contact->last_contact_date) {
    if(cJSON_AddStringToObject(item, "last_contact_date", contact->last_contact_date) == NULL) {
    goto fail; //String
    }
    }


    // contact->last_purchase_date
    if(contact->last_purchase_date) {
    if(cJSON_AddStringToObject(item, "last_purchase_date", contact->last_purchase_date) == NULL) {
    goto fail; //String
    }
    }


    // contact->leitweg_id
    if(contact->leitweg_id) {
    if(cJSON_AddStringToObject(item, "leitweg_id", contact->leitweg_id) == NULL) {
    goto fail; //String
    }
    }


    // contact->lifetime_value
    if(contact->lifetime_value) {
    if(cJSON_AddStringToObject(item, "lifetime_value", contact->lifetime_value) == NULL) {
    goto fail; //String
    }
    }


    // contact->mandate_date
    if(contact->mandate_date) {
    if(cJSON_AddStringToObject(item, "mandate_date", contact->mandate_date) == NULL) {
    goto fail; //String
    }
    }


    // contact->mandate_reference
    if(contact->mandate_reference) {
    if(cJSON_AddStringToObject(item, "mandate_reference", contact->mandate_reference) == NULL) {
    goto fail; //String
    }
    }


    // contact->marketing_consent
    if(contact->marketing_consent) {
    if(cJSON_AddBoolToObject(item, "marketing_consent", *contact->marketing_consent) == NULL) {
    goto fail; //Bool
    }
    }


    // contact->marketing_consent_at
    if(contact->marketing_consent_at) {
    if(cJSON_AddStringToObject(item, "marketing_consent_at", contact->marketing_consent_at) == NULL) {
    goto fail; //String
    }
    }


    // contact->marketing_consent_source
    if(contact->marketing_consent_source) {
    if(cJSON_AddStringToObject(item, "marketing_consent_source", contact->marketing_consent_source) == NULL) {
    goto fail; //String
    }
    }


    // contact->mobile
    if(contact->mobile) {
    if(cJSON_AddStringToObject(item, "mobile", contact->mobile) == NULL) {
    goto fail; //String
    }
    }


    // contact->name
    if (!contact->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", contact->name) == NULL) {
    goto fail; //String
    }


    // contact->next_contact_date
    if(contact->next_contact_date) {
    if(cJSON_AddStringToObject(item, "next_contact_date", contact->next_contact_date) == NULL) {
    goto fail; //String
    }
    }


    // contact->notes
    if(contact->notes) {
    if(cJSON_AddStringToObject(item, "notes", contact->notes) == NULL) {
    goto fail; //String
    }
    }


    // contact->opening_balance
    if(contact->opening_balance) {
    if(cJSON_AddStringToObject(item, "opening_balance", contact->opening_balance) == NULL) {
    goto fail; //String
    }
    }


    // contact->opening_balance_date
    if(contact->opening_balance_date) {
    if(cJSON_AddStringToObject(item, "opening_balance_date", contact->opening_balance_date) == NULL) {
    goto fail; //String
    }
    }


    // contact->order_reference
    if(contact->order_reference) {
    if(cJSON_AddStringToObject(item, "order_reference", contact->order_reference) == NULL) {
    goto fail; //String
    }
    }


    // contact->payment_block
    if(contact->payment_block) {
    if(cJSON_AddBoolToObject(item, "payment_block", *contact->payment_block) == NULL) {
    goto fail; //Bool
    }
    }


    // contact->payment_grace_period_days
    if(contact->payment_grace_period_days) {
    if(cJSON_AddNumberToObject(item, "payment_grace_period_days", *contact->payment_grace_period_days) == NULL) {
    goto fail; //Numeric
    }
    }


    // contact->payment_methods
    if(contact->payment_methods) {
    cJSON *payment_methods = cJSON_AddArrayToObject(item, "payment_methods");
    if(payment_methods == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *payment_methodsListEntry;
    list_ForEach(payment_methodsListEntry, contact->payment_methods) {
    if(cJSON_AddStringToObject(payment_methods, "", payment_methodsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // contact->payment_terms
    if(contact->payment_terms) {
    if(cJSON_AddStringToObject(item, "payment_terms", contact->payment_terms) == NULL) {
    goto fail; //String
    }
    }


    // contact->phone
    if(contact->phone) {
    if(cJSON_AddStringToObject(item, "phone", contact->phone) == NULL) {
    goto fail; //String
    }
    }


    // contact->rating
    if(contact->rating) {
    if(cJSON_AddNumberToObject(item, "rating", *contact->rating) == NULL) {
    goto fail; //Numeric
    }
    }


    // contact->sales_representative
    if(contact->sales_representative) {
    if(cJSON_AddStringToObject(item, "sales_representative", contact->sales_representative) == NULL) {
    goto fail; //String
    }
    }


    // contact->social_media
    if (!contact->social_media) {
        goto fail;
    }
    cJSON *social_media_local_JSON = _convertToJSON(contact->social_media);
    if(social_media_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "social_media", social_media_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // contact->source
    if(contact->source) {
    if(cJSON_AddStringToObject(item, "source", contact->source) == NULL) {
    goto fail; //String
    }
    }


    // contact->state
    if(contact->state) {
    if(cJSON_AddStringToObject(item, "state", contact->state) == NULL) {
    goto fail; //String
    }
    }


    // contact->street
    if(contact->street) {
    if(cJSON_AddStringToObject(item, "street", contact->street) == NULL) {
    goto fail; //String
    }
    }


    // contact->street_number
    if(contact->street_number) {
    if(cJSON_AddStringToObject(item, "street_number", contact->street_number) == NULL) {
    goto fail; //String
    }
    }


    // contact->supplier_number
    if(contact->supplier_number) {
    if(cJSON_AddStringToObject(item, "supplier_number", contact->supplier_number) == NULL) {
    goto fail; //String
    }
    }


    // contact->tags
    if(contact->tags) {
    cJSON *tags = cJSON_AddArrayToObject(item, "tags");
    if(tags == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *tagsListEntry;
    list_ForEach(tagsListEntry, contact->tags) {
    if(cJSON_AddStringToObject(tags, "", tagsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // contact->tax_country
    if(contact->tax_country) {
    if(cJSON_AddStringToObject(item, "tax_country", contact->tax_country) == NULL) {
    goto fail; //String
    }
    }


    // contact->tax_number
    if(contact->tax_number) {
    if(cJSON_AddStringToObject(item, "tax_number", contact->tax_number) == NULL) {
    goto fail; //String
    }
    }


    // contact->tax_office
    if(contact->tax_office) {
    if(cJSON_AddStringToObject(item, "tax_office", contact->tax_office) == NULL) {
    goto fail; //String
    }
    }


    // contact->total_invoices
    if(contact->total_invoices) {
    if(cJSON_AddNumberToObject(item, "total_invoices", *contact->total_invoices) == NULL) {
    goto fail; //Numeric
    }
    }


    // contact->total_revenue
    if(contact->total_revenue) {
    if(cJSON_AddStringToObject(item, "total_revenue", contact->total_revenue) == NULL) {
    goto fail; //String
    }
    }


    // contact->updated_at
    if(contact->updated_at) {
    if(cJSON_AddStringToObject(item, "updated_at", contact->updated_at) == NULL) {
    goto fail; //String
    }
    }


    // contact->vat_id
    if(contact->vat_id) {
    if(cJSON_AddStringToObject(item, "vat_id", contact->vat_id) == NULL) {
    goto fail; //String
    }
    }


    // contact->vat_id_validated
    if(contact->vat_id_validated) {
    if(cJSON_AddBoolToObject(item, "vat_id_validated", *contact->vat_id_validated) == NULL) {
    goto fail; //Bool
    }
    }


    // contact->vat_id_validation_date
    if(contact->vat_id_validation_date) {
    if(cJSON_AddStringToObject(item, "vat_id_validation_date", contact->vat_id_validation_date) == NULL) {
    goto fail; //String
    }
    }


    // contact->website
    if(contact->website) {
    if(cJSON_AddStringToObject(item, "website", contact->website) == NULL) {
    goto fail; //String
    }
    }


    // contact->zip
    if(contact->zip) {
    if(cJSON_AddStringToObject(item, "zip", contact->zip) == NULL) {
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

contact_t *contact_parseFromJSON(cJSON *contactJSON){

    contact_t *contact_local_var = NULL;

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

    char *contact_id_local_str = NULL;

    // define the local variable for contact->contact_persons
    _t *contact_persons_local_nonprim = NULL;

    char *contact_type_local_str = NULL;

    char *country_local_str = NULL;

    char *created_at_local_str = NULL;

    char *credit_limit_local_str = NULL;

    char *creditor_account_skr03_local_str = NULL;

    char *creditor_account_skr04_local_str = NULL;

    char *currency_local_str = NULL;

    char *customer_number_local_str = NULL;

    char *debitor_account_skr03_local_str = NULL;

    char *debitor_account_skr04_local_str = NULL;

    char *default_debitor_number_local_str = NULL;

    // define the local variable for contact->delivery_block
    int *delivery_block_local_var = NULL;

    char *department_local_str = NULL;

    // define the local variable for contact->discount_days
    int *discount_days_local_var = NULL;

    char *discount_percentage_local_str = NULL;

    // define the local variable for contact->donation_receipt_eligible
    int *donation_receipt_eligible_local_var = NULL;

    char *email_local_str = NULL;

    char *external_id_local_str = NULL;

    char *fax_local_str = NULL;

    char *iban_local_str = NULL;

    char *industry_local_str = NULL;

    // define the local variable for contact->is_active
    int *is_active_local_var = NULL;

    // define the local variable for contact->is_member
    int *is_member_local_var = NULL;

    // define the local variable for contact->is_nonprofit
    int *is_nonprofit_local_var = NULL;

    char *last_contact_date_local_str = NULL;

    char *last_purchase_date_local_str = NULL;

    char *leitweg_id_local_str = NULL;

    char *lifetime_value_local_str = NULL;

    char *mandate_date_local_str = NULL;

    char *mandate_reference_local_str = NULL;

    // define the local variable for contact->marketing_consent
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

    // define the local variable for contact->payment_block
    int *payment_block_local_var = NULL;

    // define the local variable for contact->payment_grace_period_days
    int *payment_grace_period_days_local_var = NULL;

    // define the local list for contact->payment_methods
    list_t *payment_methodsList = NULL;

    char *payment_terms_local_str = NULL;

    char *phone_local_str = NULL;

    // define the local variable for contact->rating
    int *rating_local_var = NULL;

    char *sales_representative_local_str = NULL;

    // define the local variable for contact->social_media
    _t *social_media_local_nonprim = NULL;

    char *source_local_str = NULL;

    char *state_local_str = NULL;

    char *street_local_str = NULL;

    char *street_number_local_str = NULL;

    char *supplier_number_local_str = NULL;

    // define the local list for contact->tags
    list_t *tagsList = NULL;

    char *tax_country_local_str = NULL;

    char *tax_number_local_str = NULL;

    char *tax_office_local_str = NULL;

    // define the local variable for contact->total_invoices
    int *total_invoices_local_var = NULL;

    char *total_revenue_local_str = NULL;

    char *updated_at_local_str = NULL;

    char *vat_id_local_str = NULL;

    // define the local variable for contact->vat_id_validated
    int *vat_id_validated_local_var = NULL;

    char *vat_id_validation_date_local_str = NULL;

    char *website_local_str = NULL;

    char *zip_local_str = NULL;

    // contact->account_holder
    cJSON *account_holder = cJSON_GetObjectItemCaseSensitive(contactJSON, "account_holder");
    if (cJSON_IsNull(account_holder)) {
        account_holder = NULL;
    }
    if (account_holder) { 
    if(!cJSON_IsString(account_holder) && !cJSON_IsNull(account_holder))
    {
    goto end; //String
    }
    }

    // contact->acquisition_cost
    cJSON *acquisition_cost = cJSON_GetObjectItemCaseSensitive(contactJSON, "acquisition_cost");
    if (cJSON_IsNull(acquisition_cost)) {
        acquisition_cost = NULL;
    }
    if (acquisition_cost) { 
    if(!cJSON_IsString(acquisition_cost) && !cJSON_IsNull(acquisition_cost))
    {
    goto end; //String
    }
    }

    // contact->address_supplement
    cJSON *address_supplement = cJSON_GetObjectItemCaseSensitive(contactJSON, "address_supplement");
    if (cJSON_IsNull(address_supplement)) {
        address_supplement = NULL;
    }
    if (address_supplement) { 
    if(!cJSON_IsString(address_supplement) && !cJSON_IsNull(address_supplement))
    {
    goto end; //String
    }
    }

    // contact->attention
    cJSON *attention = cJSON_GetObjectItemCaseSensitive(contactJSON, "attention");
    if (cJSON_IsNull(attention)) {
        attention = NULL;
    }
    if (attention) { 
    if(!cJSON_IsString(attention) && !cJSON_IsNull(attention))
    {
    goto end; //String
    }
    }

    // contact->bank_name
    cJSON *bank_name = cJSON_GetObjectItemCaseSensitive(contactJSON, "bank_name");
    if (cJSON_IsNull(bank_name)) {
        bank_name = NULL;
    }
    if (bank_name) { 
    if(!cJSON_IsString(bank_name) && !cJSON_IsNull(bank_name))
    {
    goto end; //String
    }
    }

    // contact->bic
    cJSON *bic = cJSON_GetObjectItemCaseSensitive(contactJSON, "bic");
    if (cJSON_IsNull(bic)) {
        bic = NULL;
    }
    if (bic) { 
    if(!cJSON_IsString(bic) && !cJSON_IsNull(bic))
    {
    goto end; //String
    }
    }

    // contact->buyer_reference
    cJSON *buyer_reference = cJSON_GetObjectItemCaseSensitive(contactJSON, "buyer_reference");
    if (cJSON_IsNull(buyer_reference)) {
        buyer_reference = NULL;
    }
    if (buyer_reference) { 
    if(!cJSON_IsString(buyer_reference) && !cJSON_IsNull(buyer_reference))
    {
    goto end; //String
    }
    }

    // contact->category
    cJSON *category = cJSON_GetObjectItemCaseSensitive(contactJSON, "category");
    if (cJSON_IsNull(category)) {
        category = NULL;
    }
    if (category) { 
    if(!cJSON_IsString(category) && !cJSON_IsNull(category))
    {
    goto end; //String
    }
    }

    // contact->certificate_authority
    cJSON *certificate_authority = cJSON_GetObjectItemCaseSensitive(contactJSON, "certificate_authority");
    if (cJSON_IsNull(certificate_authority)) {
        certificate_authority = NULL;
    }
    if (certificate_authority) { 
    if(!cJSON_IsString(certificate_authority) && !cJSON_IsNull(certificate_authority))
    {
    goto end; //String
    }
    }

    // contact->certificate_number
    cJSON *certificate_number = cJSON_GetObjectItemCaseSensitive(contactJSON, "certificate_number");
    if (cJSON_IsNull(certificate_number)) {
        certificate_number = NULL;
    }
    if (certificate_number) { 
    if(!cJSON_IsString(certificate_number) && !cJSON_IsNull(certificate_number))
    {
    goto end; //String
    }
    }

    // contact->certificate_paragraph
    cJSON *certificate_paragraph = cJSON_GetObjectItemCaseSensitive(contactJSON, "certificate_paragraph");
    if (cJSON_IsNull(certificate_paragraph)) {
        certificate_paragraph = NULL;
    }
    if (certificate_paragraph) { 
    if(!cJSON_IsString(certificate_paragraph) && !cJSON_IsNull(certificate_paragraph))
    {
    goto end; //String
    }
    }

    // contact->certificate_valid_until
    cJSON *certificate_valid_until = cJSON_GetObjectItemCaseSensitive(contactJSON, "certificate_valid_until");
    if (cJSON_IsNull(certificate_valid_until)) {
        certificate_valid_until = NULL;
    }
    if (certificate_valid_until) { 
    if(!cJSON_IsString(certificate_valid_until) && !cJSON_IsNull(certificate_valid_until))
    {
    goto end; //String
    }
    }

    // contact->city
    cJSON *city = cJSON_GetObjectItemCaseSensitive(contactJSON, "city");
    if (cJSON_IsNull(city)) {
        city = NULL;
    }
    if (city) { 
    if(!cJSON_IsString(city) && !cJSON_IsNull(city))
    {
    goto end; //String
    }
    }

    // contact->company_name
    cJSON *company_name = cJSON_GetObjectItemCaseSensitive(contactJSON, "company_name");
    if (cJSON_IsNull(company_name)) {
        company_name = NULL;
    }
    if (company_name) { 
    if(!cJSON_IsString(company_name) && !cJSON_IsNull(company_name))
    {
    goto end; //String
    }
    }

    // contact->contact_id
    cJSON *contact_id = cJSON_GetObjectItemCaseSensitive(contactJSON, "contact_id");
    if (cJSON_IsNull(contact_id)) {
        contact_id = NULL;
    }
    if (!contact_id) {
        goto end;
    }

    
    if(!cJSON_IsString(contact_id))
    {
    goto end; //String
    }

    // contact->contact_persons
    cJSON *contact_persons = cJSON_GetObjectItemCaseSensitive(contactJSON, "contact_persons");
    if (cJSON_IsNull(contact_persons)) {
        contact_persons = NULL;
    }
    if (!contact_persons) {
        goto end;
    }

    
    contact_persons_local_nonprim = _parseFromJSON(contact_persons); //custom

    // contact->contact_type
    cJSON *contact_type = cJSON_GetObjectItemCaseSensitive(contactJSON, "contact_type");
    if (cJSON_IsNull(contact_type)) {
        contact_type = NULL;
    }
    if (!contact_type) {
        goto end;
    }

    
    if(!cJSON_IsString(contact_type))
    {
    goto end; //String
    }

    // contact->country
    cJSON *country = cJSON_GetObjectItemCaseSensitive(contactJSON, "country");
    if (cJSON_IsNull(country)) {
        country = NULL;
    }
    if (country) { 
    if(!cJSON_IsString(country) && !cJSON_IsNull(country))
    {
    goto end; //String
    }
    }

    // contact->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(contactJSON, "created_at");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at))
    {
    goto end; //String
    }

    // contact->credit_limit
    cJSON *credit_limit = cJSON_GetObjectItemCaseSensitive(contactJSON, "credit_limit");
    if (cJSON_IsNull(credit_limit)) {
        credit_limit = NULL;
    }
    if (credit_limit) { 
    if(!cJSON_IsString(credit_limit) && !cJSON_IsNull(credit_limit))
    {
    goto end; //String
    }
    }

    // contact->creditor_account_skr03
    cJSON *creditor_account_skr03 = cJSON_GetObjectItemCaseSensitive(contactJSON, "creditor_account_skr03");
    if (cJSON_IsNull(creditor_account_skr03)) {
        creditor_account_skr03 = NULL;
    }
    if (creditor_account_skr03) { 
    if(!cJSON_IsString(creditor_account_skr03) && !cJSON_IsNull(creditor_account_skr03))
    {
    goto end; //String
    }
    }

    // contact->creditor_account_skr04
    cJSON *creditor_account_skr04 = cJSON_GetObjectItemCaseSensitive(contactJSON, "creditor_account_skr04");
    if (cJSON_IsNull(creditor_account_skr04)) {
        creditor_account_skr04 = NULL;
    }
    if (creditor_account_skr04) { 
    if(!cJSON_IsString(creditor_account_skr04) && !cJSON_IsNull(creditor_account_skr04))
    {
    goto end; //String
    }
    }

    // contact->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(contactJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (currency) { 
    if(!cJSON_IsString(currency) && !cJSON_IsNull(currency))
    {
    goto end; //String
    }
    }

    // contact->customer_number
    cJSON *customer_number = cJSON_GetObjectItemCaseSensitive(contactJSON, "customer_number");
    if (cJSON_IsNull(customer_number)) {
        customer_number = NULL;
    }
    if (customer_number) { 
    if(!cJSON_IsString(customer_number) && !cJSON_IsNull(customer_number))
    {
    goto end; //String
    }
    }

    // contact->debitor_account_skr03
    cJSON *debitor_account_skr03 = cJSON_GetObjectItemCaseSensitive(contactJSON, "debitor_account_skr03");
    if (cJSON_IsNull(debitor_account_skr03)) {
        debitor_account_skr03 = NULL;
    }
    if (debitor_account_skr03) { 
    if(!cJSON_IsString(debitor_account_skr03) && !cJSON_IsNull(debitor_account_skr03))
    {
    goto end; //String
    }
    }

    // contact->debitor_account_skr04
    cJSON *debitor_account_skr04 = cJSON_GetObjectItemCaseSensitive(contactJSON, "debitor_account_skr04");
    if (cJSON_IsNull(debitor_account_skr04)) {
        debitor_account_skr04 = NULL;
    }
    if (debitor_account_skr04) { 
    if(!cJSON_IsString(debitor_account_skr04) && !cJSON_IsNull(debitor_account_skr04))
    {
    goto end; //String
    }
    }

    // contact->default_debitor_number
    cJSON *default_debitor_number = cJSON_GetObjectItemCaseSensitive(contactJSON, "default_debitor_number");
    if (cJSON_IsNull(default_debitor_number)) {
        default_debitor_number = NULL;
    }
    if (default_debitor_number) { 
    if(!cJSON_IsString(default_debitor_number) && !cJSON_IsNull(default_debitor_number))
    {
    goto end; //String
    }
    }

    // contact->delivery_block
    cJSON *delivery_block = cJSON_GetObjectItemCaseSensitive(contactJSON, "delivery_block");
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

    // contact->department
    cJSON *department = cJSON_GetObjectItemCaseSensitive(contactJSON, "department");
    if (cJSON_IsNull(department)) {
        department = NULL;
    }
    if (department) { 
    if(!cJSON_IsString(department) && !cJSON_IsNull(department))
    {
    goto end; //String
    }
    }

    // contact->discount_days
    cJSON *discount_days = cJSON_GetObjectItemCaseSensitive(contactJSON, "discount_days");
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

    // contact->discount_percentage
    cJSON *discount_percentage = cJSON_GetObjectItemCaseSensitive(contactJSON, "discount_percentage");
    if (cJSON_IsNull(discount_percentage)) {
        discount_percentage = NULL;
    }
    if (discount_percentage) { 
    if(!cJSON_IsString(discount_percentage) && !cJSON_IsNull(discount_percentage))
    {
    goto end; //String
    }
    }

    // contact->donation_receipt_eligible
    cJSON *donation_receipt_eligible = cJSON_GetObjectItemCaseSensitive(contactJSON, "donation_receipt_eligible");
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

    // contact->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(contactJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // contact->external_id
    cJSON *external_id = cJSON_GetObjectItemCaseSensitive(contactJSON, "external_id");
    if (cJSON_IsNull(external_id)) {
        external_id = NULL;
    }
    if (external_id) { 
    if(!cJSON_IsString(external_id) && !cJSON_IsNull(external_id))
    {
    goto end; //String
    }
    }

    // contact->fax
    cJSON *fax = cJSON_GetObjectItemCaseSensitive(contactJSON, "fax");
    if (cJSON_IsNull(fax)) {
        fax = NULL;
    }
    if (fax) { 
    if(!cJSON_IsString(fax) && !cJSON_IsNull(fax))
    {
    goto end; //String
    }
    }

    // contact->iban
    cJSON *iban = cJSON_GetObjectItemCaseSensitive(contactJSON, "iban");
    if (cJSON_IsNull(iban)) {
        iban = NULL;
    }
    if (iban) { 
    if(!cJSON_IsString(iban) && !cJSON_IsNull(iban))
    {
    goto end; //String
    }
    }

    // contact->industry
    cJSON *industry = cJSON_GetObjectItemCaseSensitive(contactJSON, "industry");
    if (cJSON_IsNull(industry)) {
        industry = NULL;
    }
    if (industry) { 
    if(!cJSON_IsString(industry) && !cJSON_IsNull(industry))
    {
    goto end; //String
    }
    }

    // contact->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(contactJSON, "is_active");
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

    // contact->is_member
    cJSON *is_member = cJSON_GetObjectItemCaseSensitive(contactJSON, "is_member");
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

    // contact->is_nonprofit
    cJSON *is_nonprofit = cJSON_GetObjectItemCaseSensitive(contactJSON, "is_nonprofit");
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

    // contact->last_contact_date
    cJSON *last_contact_date = cJSON_GetObjectItemCaseSensitive(contactJSON, "last_contact_date");
    if (cJSON_IsNull(last_contact_date)) {
        last_contact_date = NULL;
    }
    if (last_contact_date) { 
    if(!cJSON_IsString(last_contact_date) && !cJSON_IsNull(last_contact_date))
    {
    goto end; //String
    }
    }

    // contact->last_purchase_date
    cJSON *last_purchase_date = cJSON_GetObjectItemCaseSensitive(contactJSON, "last_purchase_date");
    if (cJSON_IsNull(last_purchase_date)) {
        last_purchase_date = NULL;
    }
    if (last_purchase_date) { 
    if(!cJSON_IsString(last_purchase_date) && !cJSON_IsNull(last_purchase_date))
    {
    goto end; //String
    }
    }

    // contact->leitweg_id
    cJSON *leitweg_id = cJSON_GetObjectItemCaseSensitive(contactJSON, "leitweg_id");
    if (cJSON_IsNull(leitweg_id)) {
        leitweg_id = NULL;
    }
    if (leitweg_id) { 
    if(!cJSON_IsString(leitweg_id) && !cJSON_IsNull(leitweg_id))
    {
    goto end; //String
    }
    }

    // contact->lifetime_value
    cJSON *lifetime_value = cJSON_GetObjectItemCaseSensitive(contactJSON, "lifetime_value");
    if (cJSON_IsNull(lifetime_value)) {
        lifetime_value = NULL;
    }
    if (lifetime_value) { 
    if(!cJSON_IsString(lifetime_value) && !cJSON_IsNull(lifetime_value))
    {
    goto end; //String
    }
    }

    // contact->mandate_date
    cJSON *mandate_date = cJSON_GetObjectItemCaseSensitive(contactJSON, "mandate_date");
    if (cJSON_IsNull(mandate_date)) {
        mandate_date = NULL;
    }
    if (mandate_date) { 
    if(!cJSON_IsString(mandate_date) && !cJSON_IsNull(mandate_date))
    {
    goto end; //String
    }
    }

    // contact->mandate_reference
    cJSON *mandate_reference = cJSON_GetObjectItemCaseSensitive(contactJSON, "mandate_reference");
    if (cJSON_IsNull(mandate_reference)) {
        mandate_reference = NULL;
    }
    if (mandate_reference) { 
    if(!cJSON_IsString(mandate_reference) && !cJSON_IsNull(mandate_reference))
    {
    goto end; //String
    }
    }

    // contact->marketing_consent
    cJSON *marketing_consent = cJSON_GetObjectItemCaseSensitive(contactJSON, "marketing_consent");
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

    // contact->marketing_consent_at
    cJSON *marketing_consent_at = cJSON_GetObjectItemCaseSensitive(contactJSON, "marketing_consent_at");
    if (cJSON_IsNull(marketing_consent_at)) {
        marketing_consent_at = NULL;
    }
    if (marketing_consent_at) { 
    if(!cJSON_IsString(marketing_consent_at) && !cJSON_IsNull(marketing_consent_at))
    {
    goto end; //String
    }
    }

    // contact->marketing_consent_source
    cJSON *marketing_consent_source = cJSON_GetObjectItemCaseSensitive(contactJSON, "marketing_consent_source");
    if (cJSON_IsNull(marketing_consent_source)) {
        marketing_consent_source = NULL;
    }
    if (marketing_consent_source) { 
    if(!cJSON_IsString(marketing_consent_source) && !cJSON_IsNull(marketing_consent_source))
    {
    goto end; //String
    }
    }

    // contact->mobile
    cJSON *mobile = cJSON_GetObjectItemCaseSensitive(contactJSON, "mobile");
    if (cJSON_IsNull(mobile)) {
        mobile = NULL;
    }
    if (mobile) { 
    if(!cJSON_IsString(mobile) && !cJSON_IsNull(mobile))
    {
    goto end; //String
    }
    }

    // contact->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(contactJSON, "name");
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

    // contact->next_contact_date
    cJSON *next_contact_date = cJSON_GetObjectItemCaseSensitive(contactJSON, "next_contact_date");
    if (cJSON_IsNull(next_contact_date)) {
        next_contact_date = NULL;
    }
    if (next_contact_date) { 
    if(!cJSON_IsString(next_contact_date) && !cJSON_IsNull(next_contact_date))
    {
    goto end; //String
    }
    }

    // contact->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(contactJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // contact->opening_balance
    cJSON *opening_balance = cJSON_GetObjectItemCaseSensitive(contactJSON, "opening_balance");
    if (cJSON_IsNull(opening_balance)) {
        opening_balance = NULL;
    }
    if (opening_balance) { 
    if(!cJSON_IsString(opening_balance) && !cJSON_IsNull(opening_balance))
    {
    goto end; //String
    }
    }

    // contact->opening_balance_date
    cJSON *opening_balance_date = cJSON_GetObjectItemCaseSensitive(contactJSON, "opening_balance_date");
    if (cJSON_IsNull(opening_balance_date)) {
        opening_balance_date = NULL;
    }
    if (opening_balance_date) { 
    if(!cJSON_IsString(opening_balance_date) && !cJSON_IsNull(opening_balance_date))
    {
    goto end; //String
    }
    }

    // contact->order_reference
    cJSON *order_reference = cJSON_GetObjectItemCaseSensitive(contactJSON, "order_reference");
    if (cJSON_IsNull(order_reference)) {
        order_reference = NULL;
    }
    if (order_reference) { 
    if(!cJSON_IsString(order_reference) && !cJSON_IsNull(order_reference))
    {
    goto end; //String
    }
    }

    // contact->payment_block
    cJSON *payment_block = cJSON_GetObjectItemCaseSensitive(contactJSON, "payment_block");
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

    // contact->payment_grace_period_days
    cJSON *payment_grace_period_days = cJSON_GetObjectItemCaseSensitive(contactJSON, "payment_grace_period_days");
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

    // contact->payment_methods
    cJSON *payment_methods = cJSON_GetObjectItemCaseSensitive(contactJSON, "payment_methods");
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

    // contact->payment_terms
    cJSON *payment_terms = cJSON_GetObjectItemCaseSensitive(contactJSON, "payment_terms");
    if (cJSON_IsNull(payment_terms)) {
        payment_terms = NULL;
    }
    if (payment_terms) { 
    if(!cJSON_IsString(payment_terms) && !cJSON_IsNull(payment_terms))
    {
    goto end; //String
    }
    }

    // contact->phone
    cJSON *phone = cJSON_GetObjectItemCaseSensitive(contactJSON, "phone");
    if (cJSON_IsNull(phone)) {
        phone = NULL;
    }
    if (phone) { 
    if(!cJSON_IsString(phone) && !cJSON_IsNull(phone))
    {
    goto end; //String
    }
    }

    // contact->rating
    cJSON *rating = cJSON_GetObjectItemCaseSensitive(contactJSON, "rating");
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

    // contact->sales_representative
    cJSON *sales_representative = cJSON_GetObjectItemCaseSensitive(contactJSON, "sales_representative");
    if (cJSON_IsNull(sales_representative)) {
        sales_representative = NULL;
    }
    if (sales_representative) { 
    if(!cJSON_IsString(sales_representative) && !cJSON_IsNull(sales_representative))
    {
    goto end; //String
    }
    }

    // contact->social_media
    cJSON *social_media = cJSON_GetObjectItemCaseSensitive(contactJSON, "social_media");
    if (cJSON_IsNull(social_media)) {
        social_media = NULL;
    }
    if (!social_media) {
        goto end;
    }

    
    social_media_local_nonprim = _parseFromJSON(social_media); //custom

    // contact->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(contactJSON, "source");
    if (cJSON_IsNull(source)) {
        source = NULL;
    }
    if (source) { 
    if(!cJSON_IsString(source) && !cJSON_IsNull(source))
    {
    goto end; //String
    }
    }

    // contact->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(contactJSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    if (state) { 
    if(!cJSON_IsString(state) && !cJSON_IsNull(state))
    {
    goto end; //String
    }
    }

    // contact->street
    cJSON *street = cJSON_GetObjectItemCaseSensitive(contactJSON, "street");
    if (cJSON_IsNull(street)) {
        street = NULL;
    }
    if (street) { 
    if(!cJSON_IsString(street) && !cJSON_IsNull(street))
    {
    goto end; //String
    }
    }

    // contact->street_number
    cJSON *street_number = cJSON_GetObjectItemCaseSensitive(contactJSON, "street_number");
    if (cJSON_IsNull(street_number)) {
        street_number = NULL;
    }
    if (street_number) { 
    if(!cJSON_IsString(street_number) && !cJSON_IsNull(street_number))
    {
    goto end; //String
    }
    }

    // contact->supplier_number
    cJSON *supplier_number = cJSON_GetObjectItemCaseSensitive(contactJSON, "supplier_number");
    if (cJSON_IsNull(supplier_number)) {
        supplier_number = NULL;
    }
    if (supplier_number) { 
    if(!cJSON_IsString(supplier_number) && !cJSON_IsNull(supplier_number))
    {
    goto end; //String
    }
    }

    // contact->tags
    cJSON *tags = cJSON_GetObjectItemCaseSensitive(contactJSON, "tags");
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

    // contact->tax_country
    cJSON *tax_country = cJSON_GetObjectItemCaseSensitive(contactJSON, "tax_country");
    if (cJSON_IsNull(tax_country)) {
        tax_country = NULL;
    }
    if (tax_country) { 
    if(!cJSON_IsString(tax_country) && !cJSON_IsNull(tax_country))
    {
    goto end; //String
    }
    }

    // contact->tax_number
    cJSON *tax_number = cJSON_GetObjectItemCaseSensitive(contactJSON, "tax_number");
    if (cJSON_IsNull(tax_number)) {
        tax_number = NULL;
    }
    if (tax_number) { 
    if(!cJSON_IsString(tax_number) && !cJSON_IsNull(tax_number))
    {
    goto end; //String
    }
    }

    // contact->tax_office
    cJSON *tax_office = cJSON_GetObjectItemCaseSensitive(contactJSON, "tax_office");
    if (cJSON_IsNull(tax_office)) {
        tax_office = NULL;
    }
    if (tax_office) { 
    if(!cJSON_IsString(tax_office) && !cJSON_IsNull(tax_office))
    {
    goto end; //String
    }
    }

    // contact->total_invoices
    cJSON *total_invoices = cJSON_GetObjectItemCaseSensitive(contactJSON, "total_invoices");
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

    // contact->total_revenue
    cJSON *total_revenue = cJSON_GetObjectItemCaseSensitive(contactJSON, "total_revenue");
    if (cJSON_IsNull(total_revenue)) {
        total_revenue = NULL;
    }
    if (total_revenue) { 
    if(!cJSON_IsString(total_revenue) && !cJSON_IsNull(total_revenue))
    {
    goto end; //String
    }
    }

    // contact->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(contactJSON, "updated_at");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //String
    }
    }

    // contact->vat_id
    cJSON *vat_id = cJSON_GetObjectItemCaseSensitive(contactJSON, "vat_id");
    if (cJSON_IsNull(vat_id)) {
        vat_id = NULL;
    }
    if (vat_id) { 
    if(!cJSON_IsString(vat_id) && !cJSON_IsNull(vat_id))
    {
    goto end; //String
    }
    }

    // contact->vat_id_validated
    cJSON *vat_id_validated = cJSON_GetObjectItemCaseSensitive(contactJSON, "vat_id_validated");
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

    // contact->vat_id_validation_date
    cJSON *vat_id_validation_date = cJSON_GetObjectItemCaseSensitive(contactJSON, "vat_id_validation_date");
    if (cJSON_IsNull(vat_id_validation_date)) {
        vat_id_validation_date = NULL;
    }
    if (vat_id_validation_date) { 
    if(!cJSON_IsString(vat_id_validation_date) && !cJSON_IsNull(vat_id_validation_date))
    {
    goto end; //String
    }
    }

    // contact->website
    cJSON *website = cJSON_GetObjectItemCaseSensitive(contactJSON, "website");
    if (cJSON_IsNull(website)) {
        website = NULL;
    }
    if (website) { 
    if(!cJSON_IsString(website) && !cJSON_IsNull(website))
    {
    goto end; //String
    }
    }

    // contact->zip
    cJSON *zip = cJSON_GetObjectItemCaseSensitive(contactJSON, "zip");
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
    if (certificate_valid_until && !cJSON_IsNull(certificate_valid_until)) certificate_valid_until_local_str = strdup(certificate_valid_until->valuestring);
    if (city && !cJSON_IsNull(city)) city_local_str = strdup(city->valuestring);
    if (company_name && !cJSON_IsNull(company_name)) company_name_local_str = strdup(company_name->valuestring);
    if (contact_id && !cJSON_IsNull(contact_id)) contact_id_local_str = strdup(contact_id->valuestring);
    if (contact_type && !cJSON_IsNull(contact_type)) contact_type_local_str = strdup(contact_type->valuestring);
    if (country && !cJSON_IsNull(country)) country_local_str = strdup(country->valuestring);
    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
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
    if (last_contact_date && !cJSON_IsNull(last_contact_date)) last_contact_date_local_str = strdup(last_contact_date->valuestring);
    if (last_purchase_date && !cJSON_IsNull(last_purchase_date)) last_purchase_date_local_str = strdup(last_purchase_date->valuestring);
    if (leitweg_id && !cJSON_IsNull(leitweg_id)) leitweg_id_local_str = strdup(leitweg_id->valuestring);
    if (lifetime_value && !cJSON_IsNull(lifetime_value)) lifetime_value_local_str = strdup(lifetime_value->valuestring);
    if (mandate_date && !cJSON_IsNull(mandate_date)) mandate_date_local_str = strdup(mandate_date->valuestring);
    if (mandate_reference && !cJSON_IsNull(mandate_reference)) mandate_reference_local_str = strdup(mandate_reference->valuestring);
    if (marketing_consent_at && !cJSON_IsNull(marketing_consent_at)) marketing_consent_at_local_str = strdup(marketing_consent_at->valuestring);
    if (marketing_consent_source && !cJSON_IsNull(marketing_consent_source)) marketing_consent_source_local_str = strdup(marketing_consent_source->valuestring);
    if (mobile && !cJSON_IsNull(mobile)) mobile_local_str = strdup(mobile->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (next_contact_date && !cJSON_IsNull(next_contact_date)) next_contact_date_local_str = strdup(next_contact_date->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (opening_balance && !cJSON_IsNull(opening_balance)) opening_balance_local_str = strdup(opening_balance->valuestring);
    if (opening_balance_date && !cJSON_IsNull(opening_balance_date)) opening_balance_date_local_str = strdup(opening_balance_date->valuestring);
    if (order_reference && !cJSON_IsNull(order_reference)) order_reference_local_str = strdup(order_reference->valuestring);
    if (payment_terms && !cJSON_IsNull(payment_terms)) payment_terms_local_str = strdup(payment_terms->valuestring);
    if (phone && !cJSON_IsNull(phone)) phone_local_str = strdup(phone->valuestring);
    if (sales_representative && !cJSON_IsNull(sales_representative)) sales_representative_local_str = strdup(sales_representative->valuestring);
    if (source && !cJSON_IsNull(source)) source_local_str = strdup(source->valuestring);
    if (state && !cJSON_IsNull(state)) state_local_str = strdup(state->valuestring);
    if (street && !cJSON_IsNull(street)) street_local_str = strdup(street->valuestring);
    if (street_number && !cJSON_IsNull(street_number)) street_number_local_str = strdup(street_number->valuestring);
    if (supplier_number && !cJSON_IsNull(supplier_number)) supplier_number_local_str = strdup(supplier_number->valuestring);
    if (tax_country && !cJSON_IsNull(tax_country)) tax_country_local_str = strdup(tax_country->valuestring);
    if (tax_number && !cJSON_IsNull(tax_number)) tax_number_local_str = strdup(tax_number->valuestring);
    if (tax_office && !cJSON_IsNull(tax_office)) tax_office_local_str = strdup(tax_office->valuestring);
    if (total_revenue && !cJSON_IsNull(total_revenue)) total_revenue_local_str = strdup(total_revenue->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);
    if (vat_id && !cJSON_IsNull(vat_id)) vat_id_local_str = strdup(vat_id->valuestring);
    if (vat_id_validation_date && !cJSON_IsNull(vat_id_validation_date)) vat_id_validation_date_local_str = strdup(vat_id_validation_date->valuestring);
    if (website && !cJSON_IsNull(website)) website_local_str = strdup(website->valuestring);
    if (zip && !cJSON_IsNull(zip)) zip_local_str = strdup(zip->valuestring);

    contact_local_var = contact_create_internal (
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
        contact_id_local_str,
        contact_persons_local_nonprim,
        contact_type_local_str,
        country_local_str,
        created_at_local_str,
        credit_limit_local_str,
        creditor_account_skr03_local_str,
        creditor_account_skr04_local_str,
        currency_local_str,
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
        social_media_local_nonprim,
        source_local_str,
        state_local_str,
        street_local_str,
        street_number_local_str,
        supplier_number_local_str,
        tags ? tagsList : NULL,
        tax_country_local_str,
        tax_number_local_str,
        tax_office_local_str,
        total_invoices_local_var,
        total_revenue_local_str,
        updated_at_local_str,
        vat_id_local_str,
        vat_id_validated_local_var,
        vat_id_validation_date_local_str,
        website_local_str,
        zip_local_str
        );

    if (!contact_local_var) {
        goto end;
    }

    return contact_local_var;
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
    if (contact_id_local_str) {
        free(contact_id_local_str);
        contact_id_local_str = NULL;
    }
    if (contact_persons_local_nonprim) {
        _free(contact_persons_local_nonprim);
        contact_persons_local_nonprim = NULL;
    }
    if (contact_type_local_str) {
        free(contact_type_local_str);
        contact_type_local_str = NULL;
    }
    if (country_local_str) {
        free(country_local_str);
        country_local_str = NULL;
    }
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
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
    if (tax_country_local_str) {
        free(tax_country_local_str);
        tax_country_local_str = NULL;
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
    if (updated_at_local_str) {
        free(updated_at_local_str);
        updated_at_local_str = NULL;
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
