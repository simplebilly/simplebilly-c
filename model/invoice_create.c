#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invoice_create.h"



static invoice_create_t *invoice_create_create_internal(
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
    ) {
    invoice_create_t *invoice_create_local_var = malloc(sizeof(invoice_create_t));
    if (!invoice_create_local_var) {
        return NULL;
    }
    memset(invoice_create_local_var, 0, sizeof(invoice_create_t));
    invoice_create_local_var->_library_owned = 1;
    invoice_create_local_var->attachments = attachments;
    invoice_create_local_var->billing_period_end = billing_period_end;
    invoice_create_local_var->billing_period_start = billing_period_start;
    invoice_create_local_var->cancellation_date = cancellation_date;
    invoice_create_local_var->cancellation_invoice_id = cancellation_invoice_id;
    invoice_create_local_var->cancellation_reason = cancellation_reason;
    invoice_create_local_var->contract_id = contract_id;
    invoice_create_local_var->currency = currency;
    invoice_create_local_var->customer_id = customer_id;
    invoice_create_local_var->discount_amount = discount_amount;
    invoice_create_local_var->discount_days = discount_days;
    invoice_create_local_var->discount_percentage = discount_percentage;
    invoice_create_local_var->document_type = document_type;
    invoice_create_local_var->dunning_level = dunning_level;
    invoice_create_local_var->input_vat_amount = input_vat_amount;
    invoice_create_local_var->input_vat_deductible = input_vat_deductible;
    invoice_create_local_var->input_vat_percentage = input_vat_percentage;
    invoice_create_local_var->introduction_text = introduction_text;
    invoice_create_local_var->invoice_type = invoice_type;
    invoice_create_local_var->is_cancelled = is_cancelled;
    invoice_create_local_var->is_draft = is_draft;
    invoice_create_local_var->is_eu_acquisition = is_eu_acquisition;
    invoice_create_local_var->is_eu_delivery = is_eu_delivery;
    invoice_create_local_var->is_intra_community_acquisition = is_intra_community_acquisition;
    invoice_create_local_var->is_reverse_charge = is_reverse_charge;
    invoice_create_local_var->issue_date = issue_date;
    invoice_create_local_var->ledger_account = ledger_account;
    invoice_create_local_var->line_items = line_items;
    invoice_create_local_var->margin25a = margin25a;
    invoice_create_local_var->margin25a_gross = margin25a_gross;
    invoice_create_local_var->margin25a_purchase_price = margin25a_purchase_price;
    invoice_create_local_var->notes = notes;
    invoice_create_local_var->order_number = order_number;
    invoice_create_local_var->original_pdf_path = original_pdf_path;
    invoice_create_local_var->paid_amount = paid_amount;
    invoice_create_local_var->payment_due_date = payment_due_date;
    invoice_create_local_var->payment_status = payment_status;
    invoice_create_local_var->payment_terms_text = payment_terms_text;
    invoice_create_local_var->preceding_sales_voucher_id = preceding_sales_voucher_id;
    invoice_create_local_var->preceding_sales_voucher_type = preceding_sales_voucher_type;
    invoice_create_local_var->receipt_confirmation_available = receipt_confirmation_available;
    invoice_create_local_var->related_invoice_id = related_invoice_id;
    invoice_create_local_var->relationship_type = relationship_type;
    invoice_create_local_var->sender_snapshot = sender_snapshot;
    invoice_create_local_var->sent_at = sent_at;
    invoice_create_local_var->service_period_end = service_period_end;
    invoice_create_local_var->service_period_start = service_period_start;
    invoice_create_local_var->status = status;
    invoice_create_local_var->subtotal = subtotal;
    invoice_create_local_var->supplier_id = supplier_id;
    invoice_create_local_var->tax_exemption_reason = tax_exemption_reason;
    invoice_create_local_var->total_amount = total_amount;
    invoice_create_local_var->total_tax = total_tax;
    invoice_create_local_var->vat_country = vat_country;
    invoice_create_local_var->vat_special_case = vat_special_case;
    return invoice_create_local_var;
}

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
    ) {
    int *discount_days_copy = NULL;
    if (discount_days) {
        discount_days_copy = malloc(sizeof(int));
        if (discount_days_copy) *discount_days_copy = *discount_days;
    }
    int *dunning_level_copy = NULL;
    if (dunning_level) {
        dunning_level_copy = malloc(sizeof(int));
        if (dunning_level_copy) *dunning_level_copy = *dunning_level;
    }
    int *input_vat_deductible_copy = NULL;
    if (input_vat_deductible) {
        input_vat_deductible_copy = malloc(sizeof(int));
        if (input_vat_deductible_copy) *input_vat_deductible_copy = *input_vat_deductible;
    }
    int *is_cancelled_copy = NULL;
    if (is_cancelled) {
        is_cancelled_copy = malloc(sizeof(int));
        if (is_cancelled_copy) *is_cancelled_copy = *is_cancelled;
    }
    int *is_draft_copy = NULL;
    if (is_draft) {
        is_draft_copy = malloc(sizeof(int));
        if (is_draft_copy) *is_draft_copy = *is_draft;
    }
    int *is_eu_acquisition_copy = NULL;
    if (is_eu_acquisition) {
        is_eu_acquisition_copy = malloc(sizeof(int));
        if (is_eu_acquisition_copy) *is_eu_acquisition_copy = *is_eu_acquisition;
    }
    int *is_eu_delivery_copy = NULL;
    if (is_eu_delivery) {
        is_eu_delivery_copy = malloc(sizeof(int));
        if (is_eu_delivery_copy) *is_eu_delivery_copy = *is_eu_delivery;
    }
    int *is_intra_community_acquisition_copy = NULL;
    if (is_intra_community_acquisition) {
        is_intra_community_acquisition_copy = malloc(sizeof(int));
        if (is_intra_community_acquisition_copy) *is_intra_community_acquisition_copy = *is_intra_community_acquisition;
    }
    int *is_reverse_charge_copy = NULL;
    if (is_reverse_charge) {
        is_reverse_charge_copy = malloc(sizeof(int));
        if (is_reverse_charge_copy) *is_reverse_charge_copy = *is_reverse_charge;
    }
    int *margin25a_copy = NULL;
    if (margin25a) {
        margin25a_copy = malloc(sizeof(int));
        if (margin25a_copy) *margin25a_copy = *margin25a;
    }
    int *receipt_confirmation_available_copy = NULL;
    if (receipt_confirmation_available) {
        receipt_confirmation_available_copy = malloc(sizeof(int));
        if (receipt_confirmation_available_copy) *receipt_confirmation_available_copy = *receipt_confirmation_available;
    }
    invoice_create_t *result = invoice_create_create_internal (
        attachments,
        billing_period_end,
        billing_period_start,
        cancellation_date,
        cancellation_invoice_id,
        cancellation_reason,
        contract_id,
        currency,
        customer_id,
        discount_amount,
        discount_days_copy,
        discount_percentage,
        document_type,
        dunning_level_copy,
        input_vat_amount,
        input_vat_deductible_copy,
        input_vat_percentage,
        introduction_text,
        invoice_type,
        is_cancelled_copy,
        is_draft_copy,
        is_eu_acquisition_copy,
        is_eu_delivery_copy,
        is_intra_community_acquisition_copy,
        is_reverse_charge_copy,
        issue_date,
        ledger_account,
        line_items,
        margin25a_copy,
        margin25a_gross,
        margin25a_purchase_price,
        notes,
        order_number,
        original_pdf_path,
        paid_amount,
        payment_due_date,
        payment_status,
        payment_terms_text,
        preceding_sales_voucher_id,
        preceding_sales_voucher_type,
        receipt_confirmation_available_copy,
        related_invoice_id,
        relationship_type,
        sender_snapshot,
        sent_at,
        service_period_end,
        service_period_start,
        status,
        subtotal,
        supplier_id,
        tax_exemption_reason,
        total_amount,
        total_tax,
        vat_country,
        vat_special_case
        );
    if (!result) {
        free(discount_days_copy);
        free(dunning_level_copy);
        free(input_vat_deductible_copy);
        free(is_cancelled_copy);
        free(is_draft_copy);
        free(is_eu_acquisition_copy);
        free(is_eu_delivery_copy);
        free(is_intra_community_acquisition_copy);
        free(is_reverse_charge_copy);
        free(margin25a_copy);
        free(receipt_confirmation_available_copy);
    }
    return result;
}

void invoice_create_free(invoice_create_t *invoice_create) {
    if(NULL == invoice_create){
        return ;
    }
    if(invoice_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invoice_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invoice_create->attachments) {
        _free(invoice_create->attachments);
        invoice_create->attachments = NULL;
    }
    if (invoice_create->billing_period_end) {
        free(invoice_create->billing_period_end);
        invoice_create->billing_period_end = NULL;
    }
    if (invoice_create->billing_period_start) {
        free(invoice_create->billing_period_start);
        invoice_create->billing_period_start = NULL;
    }
    if (invoice_create->cancellation_date) {
        free(invoice_create->cancellation_date);
        invoice_create->cancellation_date = NULL;
    }
    if (invoice_create->cancellation_invoice_id) {
        free(invoice_create->cancellation_invoice_id);
        invoice_create->cancellation_invoice_id = NULL;
    }
    if (invoice_create->cancellation_reason) {
        free(invoice_create->cancellation_reason);
        invoice_create->cancellation_reason = NULL;
    }
    if (invoice_create->contract_id) {
        free(invoice_create->contract_id);
        invoice_create->contract_id = NULL;
    }
    if (invoice_create->customer_id) {
        free(invoice_create->customer_id);
        invoice_create->customer_id = NULL;
    }
    if (invoice_create->discount_amount) {
        free(invoice_create->discount_amount);
        invoice_create->discount_amount = NULL;
    }
    if (invoice_create->discount_days) {
        free(invoice_create->discount_days);
        invoice_create->discount_days = NULL;
    }
    if (invoice_create->discount_percentage) {
        free(invoice_create->discount_percentage);
        invoice_create->discount_percentage = NULL;
    }
    if (invoice_create->dunning_level) {
        free(invoice_create->dunning_level);
        invoice_create->dunning_level = NULL;
    }
    if (invoice_create->input_vat_amount) {
        free(invoice_create->input_vat_amount);
        invoice_create->input_vat_amount = NULL;
    }
    if (invoice_create->input_vat_deductible) {
        free(invoice_create->input_vat_deductible);
        invoice_create->input_vat_deductible = NULL;
    }
    if (invoice_create->input_vat_percentage) {
        free(invoice_create->input_vat_percentage);
        invoice_create->input_vat_percentage = NULL;
    }
    if (invoice_create->introduction_text) {
        free(invoice_create->introduction_text);
        invoice_create->introduction_text = NULL;
    }
    if (invoice_create->is_cancelled) {
        free(invoice_create->is_cancelled);
        invoice_create->is_cancelled = NULL;
    }
    if (invoice_create->is_draft) {
        free(invoice_create->is_draft);
        invoice_create->is_draft = NULL;
    }
    if (invoice_create->is_eu_acquisition) {
        free(invoice_create->is_eu_acquisition);
        invoice_create->is_eu_acquisition = NULL;
    }
    if (invoice_create->is_eu_delivery) {
        free(invoice_create->is_eu_delivery);
        invoice_create->is_eu_delivery = NULL;
    }
    if (invoice_create->is_intra_community_acquisition) {
        free(invoice_create->is_intra_community_acquisition);
        invoice_create->is_intra_community_acquisition = NULL;
    }
    if (invoice_create->is_reverse_charge) {
        free(invoice_create->is_reverse_charge);
        invoice_create->is_reverse_charge = NULL;
    }
    if (invoice_create->issue_date) {
        free(invoice_create->issue_date);
        invoice_create->issue_date = NULL;
    }
    if (invoice_create->ledger_account) {
        free(invoice_create->ledger_account);
        invoice_create->ledger_account = NULL;
    }
    if (invoice_create->line_items) {
        _free(invoice_create->line_items);
        invoice_create->line_items = NULL;
    }
    if (invoice_create->margin25a) {
        free(invoice_create->margin25a);
        invoice_create->margin25a = NULL;
    }
    if (invoice_create->margin25a_gross) {
        free(invoice_create->margin25a_gross);
        invoice_create->margin25a_gross = NULL;
    }
    if (invoice_create->margin25a_purchase_price) {
        free(invoice_create->margin25a_purchase_price);
        invoice_create->margin25a_purchase_price = NULL;
    }
    if (invoice_create->notes) {
        free(invoice_create->notes);
        invoice_create->notes = NULL;
    }
    if (invoice_create->order_number) {
        free(invoice_create->order_number);
        invoice_create->order_number = NULL;
    }
    if (invoice_create->original_pdf_path) {
        free(invoice_create->original_pdf_path);
        invoice_create->original_pdf_path = NULL;
    }
    if (invoice_create->paid_amount) {
        free(invoice_create->paid_amount);
        invoice_create->paid_amount = NULL;
    }
    if (invoice_create->payment_due_date) {
        free(invoice_create->payment_due_date);
        invoice_create->payment_due_date = NULL;
    }
    if (invoice_create->payment_terms_text) {
        free(invoice_create->payment_terms_text);
        invoice_create->payment_terms_text = NULL;
    }
    if (invoice_create->preceding_sales_voucher_id) {
        free(invoice_create->preceding_sales_voucher_id);
        invoice_create->preceding_sales_voucher_id = NULL;
    }
    if (invoice_create->preceding_sales_voucher_type) {
        preceding_sales_voucher_type_free(invoice_create->preceding_sales_voucher_type);
        invoice_create->preceding_sales_voucher_type = NULL;
    }
    if (invoice_create->receipt_confirmation_available) {
        free(invoice_create->receipt_confirmation_available);
        invoice_create->receipt_confirmation_available = NULL;
    }
    if (invoice_create->related_invoice_id) {
        free(invoice_create->related_invoice_id);
        invoice_create->related_invoice_id = NULL;
    }
    if (invoice_create->relationship_type) {
        free(invoice_create->relationship_type);
        invoice_create->relationship_type = NULL;
    }
    if (invoice_create->sender_snapshot) {
        _free(invoice_create->sender_snapshot);
        invoice_create->sender_snapshot = NULL;
    }
    if (invoice_create->sent_at) {
        free(invoice_create->sent_at);
        invoice_create->sent_at = NULL;
    }
    if (invoice_create->service_period_end) {
        free(invoice_create->service_period_end);
        invoice_create->service_period_end = NULL;
    }
    if (invoice_create->service_period_start) {
        free(invoice_create->service_period_start);
        invoice_create->service_period_start = NULL;
    }
    if (invoice_create->subtotal) {
        free(invoice_create->subtotal);
        invoice_create->subtotal = NULL;
    }
    if (invoice_create->supplier_id) {
        free(invoice_create->supplier_id);
        invoice_create->supplier_id = NULL;
    }
    if (invoice_create->tax_exemption_reason) {
        free(invoice_create->tax_exemption_reason);
        invoice_create->tax_exemption_reason = NULL;
    }
    if (invoice_create->total_amount) {
        free(invoice_create->total_amount);
        invoice_create->total_amount = NULL;
    }
    if (invoice_create->total_tax) {
        free(invoice_create->total_tax);
        invoice_create->total_tax = NULL;
    }
    if (invoice_create->vat_country) {
        country_code_free(invoice_create->vat_country);
        invoice_create->vat_country = NULL;
    }
    if (invoice_create->vat_special_case) {
        free(invoice_create->vat_special_case);
        invoice_create->vat_special_case = NULL;
    }
    free(invoice_create);
}

cJSON *invoice_create_convertToJSON(invoice_create_t *invoice_create) {
    cJSON *item = cJSON_CreateObject();

    // invoice_create->attachments
    if(invoice_create->attachments) {
    cJSON *attachments_local_JSON = _convertToJSON(invoice_create->attachments);
    if(attachments_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "attachments", attachments_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // invoice_create->billing_period_end
    if(invoice_create->billing_period_end) {
    if(cJSON_AddStringToObject(item, "billingPeriodEnd", invoice_create->billing_period_end) == NULL) {
    goto fail; //Date
    }
    }


    // invoice_create->billing_period_start
    if(invoice_create->billing_period_start) {
    if(cJSON_AddStringToObject(item, "billingPeriodStart", invoice_create->billing_period_start) == NULL) {
    goto fail; //Date
    }
    }


    // invoice_create->cancellation_date
    if(invoice_create->cancellation_date) {
    if(cJSON_AddStringToObject(item, "cancellationDate", invoice_create->cancellation_date) == NULL) {
    goto fail; //Date
    }
    }


    // invoice_create->cancellation_invoice_id
    if(invoice_create->cancellation_invoice_id) {
    if(cJSON_AddStringToObject(item, "cancellationInvoiceId", invoice_create->cancellation_invoice_id) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->cancellation_reason
    if(invoice_create->cancellation_reason) {
    if(cJSON_AddStringToObject(item, "cancellationReason", invoice_create->cancellation_reason) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->contract_id
    if(invoice_create->contract_id) {
    if(cJSON_AddStringToObject(item, "contractId", invoice_create->contract_id) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->currency
    if (simplebilly_api_currency_code__NULL == invoice_create->currency) {
        goto fail;
    }
    cJSON *currency_local_JSON = currency_code_convertToJSON(invoice_create->currency);
    if(currency_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "currency", currency_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // invoice_create->customer_id
    if(invoice_create->customer_id) {
    if(cJSON_AddStringToObject(item, "customerId", invoice_create->customer_id) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->discount_amount
    if(invoice_create->discount_amount) {
    if(cJSON_AddStringToObject(item, "discountAmount", invoice_create->discount_amount) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->discount_days
    if(invoice_create->discount_days) {
    if(cJSON_AddNumberToObject(item, "discountDays", *invoice_create->discount_days) == NULL) {
    goto fail; //Numeric
    }
    }


    // invoice_create->discount_percentage
    if(invoice_create->discount_percentage) {
    if(cJSON_AddStringToObject(item, "discountPercentage", invoice_create->discount_percentage) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->document_type
    if(invoice_create->document_type != simplebilly_api_document_type__NULL) {
    cJSON *document_type_local_JSON = document_type_convertToJSON(invoice_create->document_type);
    if(document_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "documentType", document_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // invoice_create->dunning_level
    if(invoice_create->dunning_level) {
    if(cJSON_AddNumberToObject(item, "dunningLevel", *invoice_create->dunning_level) == NULL) {
    goto fail; //Numeric
    }
    }


    // invoice_create->input_vat_amount
    if(invoice_create->input_vat_amount) {
    if(cJSON_AddStringToObject(item, "inputVatAmount", invoice_create->input_vat_amount) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->input_vat_deductible
    if(invoice_create->input_vat_deductible) {
    if(cJSON_AddBoolToObject(item, "inputVatDeductible", *invoice_create->input_vat_deductible) == NULL) {
    goto fail; //Bool
    }
    }


    // invoice_create->input_vat_percentage
    if(invoice_create->input_vat_percentage) {
    if(cJSON_AddStringToObject(item, "inputVatPercentage", invoice_create->input_vat_percentage) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->introduction_text
    if(invoice_create->introduction_text) {
    if(cJSON_AddStringToObject(item, "introductionText", invoice_create->introduction_text) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->invoice_type
    if (simplebilly_api_invoice_type__NULL == invoice_create->invoice_type) {
        goto fail;
    }
    cJSON *invoice_type_local_JSON = invoice_type_convertToJSON(invoice_create->invoice_type);
    if(invoice_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "invoiceType", invoice_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // invoice_create->is_cancelled
    if(invoice_create->is_cancelled) {
    if(cJSON_AddBoolToObject(item, "isCancelled", *invoice_create->is_cancelled) == NULL) {
    goto fail; //Bool
    }
    }


    // invoice_create->is_draft
    if(invoice_create->is_draft) {
    if(cJSON_AddBoolToObject(item, "isDraft", *invoice_create->is_draft) == NULL) {
    goto fail; //Bool
    }
    }


    // invoice_create->is_eu_acquisition
    if(invoice_create->is_eu_acquisition) {
    if(cJSON_AddBoolToObject(item, "isEuAcquisition", *invoice_create->is_eu_acquisition) == NULL) {
    goto fail; //Bool
    }
    }


    // invoice_create->is_eu_delivery
    if(invoice_create->is_eu_delivery) {
    if(cJSON_AddBoolToObject(item, "isEuDelivery", *invoice_create->is_eu_delivery) == NULL) {
    goto fail; //Bool
    }
    }


    // invoice_create->is_intra_community_acquisition
    if(invoice_create->is_intra_community_acquisition) {
    if(cJSON_AddBoolToObject(item, "isIntraCommunityAcquisition", *invoice_create->is_intra_community_acquisition) == NULL) {
    goto fail; //Bool
    }
    }


    // invoice_create->is_reverse_charge
    if(invoice_create->is_reverse_charge) {
    if(cJSON_AddBoolToObject(item, "isReverseCharge", *invoice_create->is_reverse_charge) == NULL) {
    goto fail; //Bool
    }
    }


    // invoice_create->issue_date
    if (!invoice_create->issue_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "issueDate", invoice_create->issue_date) == NULL) {
    goto fail; //Date
    }


    // invoice_create->ledger_account
    if(invoice_create->ledger_account) {
    if(cJSON_AddStringToObject(item, "ledgerAccount", invoice_create->ledger_account) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->line_items
    if (!invoice_create->line_items) {
        goto fail;
    }
    cJSON *line_items_local_JSON = _convertToJSON(invoice_create->line_items);
    if(line_items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "lineItems", line_items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // invoice_create->margin25a
    if(invoice_create->margin25a) {
    if(cJSON_AddBoolToObject(item, "margin25a", *invoice_create->margin25a) == NULL) {
    goto fail; //Bool
    }
    }


    // invoice_create->margin25a_gross
    if(invoice_create->margin25a_gross) {
    if(cJSON_AddStringToObject(item, "margin25aGross", invoice_create->margin25a_gross) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->margin25a_purchase_price
    if(invoice_create->margin25a_purchase_price) {
    if(cJSON_AddStringToObject(item, "margin25aPurchasePrice", invoice_create->margin25a_purchase_price) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->notes
    if(invoice_create->notes) {
    if(cJSON_AddStringToObject(item, "notes", invoice_create->notes) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->order_number
    if(invoice_create->order_number) {
    if(cJSON_AddStringToObject(item, "orderNumber", invoice_create->order_number) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->original_pdf_path
    if(invoice_create->original_pdf_path) {
    if(cJSON_AddStringToObject(item, "originalPdfPath", invoice_create->original_pdf_path) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->paid_amount
    if(invoice_create->paid_amount) {
    if(cJSON_AddStringToObject(item, "paidAmount", invoice_create->paid_amount) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->payment_due_date
    if(invoice_create->payment_due_date) {
    if(cJSON_AddStringToObject(item, "paymentDueDate", invoice_create->payment_due_date) == NULL) {
    goto fail; //Date
    }
    }


    // invoice_create->payment_status
    if(invoice_create->payment_status != simplebilly_api_payment_status__NULL) {
    cJSON *payment_status_local_JSON = payment_status_convertToJSON(invoice_create->payment_status);
    if(payment_status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "paymentStatus", payment_status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // invoice_create->payment_terms_text
    if(invoice_create->payment_terms_text) {
    if(cJSON_AddStringToObject(item, "paymentTermsText", invoice_create->payment_terms_text) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->preceding_sales_voucher_id
    if(invoice_create->preceding_sales_voucher_id) {
    if(cJSON_AddStringToObject(item, "precedingSalesVoucherId", invoice_create->preceding_sales_voucher_id) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->preceding_sales_voucher_type
    if(invoice_create->preceding_sales_voucher_type) {
    cJSON *preceding_sales_voucher_type_local_JSON = preceding_sales_voucher_type_convertToJSON(invoice_create->preceding_sales_voucher_type);
    if(preceding_sales_voucher_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "precedingSalesVoucherType", preceding_sales_voucher_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // invoice_create->receipt_confirmation_available
    if(invoice_create->receipt_confirmation_available) {
    if(cJSON_AddBoolToObject(item, "receiptConfirmationAvailable", *invoice_create->receipt_confirmation_available) == NULL) {
    goto fail; //Bool
    }
    }


    // invoice_create->related_invoice_id
    if(invoice_create->related_invoice_id) {
    if(cJSON_AddStringToObject(item, "relatedInvoiceId", invoice_create->related_invoice_id) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->relationship_type
    if(invoice_create->relationship_type) {
    if(cJSON_AddStringToObject(item, "relationshipType", invoice_create->relationship_type) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->sender_snapshot
    if(invoice_create->sender_snapshot) {
    cJSON *sender_snapshot_local_JSON = _convertToJSON(invoice_create->sender_snapshot);
    if(sender_snapshot_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "senderSnapshot", sender_snapshot_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // invoice_create->sent_at
    if(invoice_create->sent_at) {
    if(cJSON_AddStringToObject(item, "sentAt", invoice_create->sent_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // invoice_create->service_period_end
    if(invoice_create->service_period_end) {
    if(cJSON_AddStringToObject(item, "servicePeriodEnd", invoice_create->service_period_end) == NULL) {
    goto fail; //Date
    }
    }


    // invoice_create->service_period_start
    if(invoice_create->service_period_start) {
    if(cJSON_AddStringToObject(item, "servicePeriodStart", invoice_create->service_period_start) == NULL) {
    goto fail; //Date
    }
    }


    // invoice_create->status
    if (simplebilly_api_invoice_status__NULL == invoice_create->status) {
        goto fail;
    }
    cJSON *status_local_JSON = invoice_status_convertToJSON(invoice_create->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // invoice_create->subtotal
    if (!invoice_create->subtotal) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "subtotal", invoice_create->subtotal) == NULL) {
    goto fail; //String
    }


    // invoice_create->supplier_id
    if(invoice_create->supplier_id) {
    if(cJSON_AddStringToObject(item, "supplierId", invoice_create->supplier_id) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->tax_exemption_reason
    if(invoice_create->tax_exemption_reason) {
    if(cJSON_AddStringToObject(item, "taxExemptionReason", invoice_create->tax_exemption_reason) == NULL) {
    goto fail; //String
    }
    }


    // invoice_create->total_amount
    if (!invoice_create->total_amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "totalAmount", invoice_create->total_amount) == NULL) {
    goto fail; //String
    }


    // invoice_create->total_tax
    if (!invoice_create->total_tax) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "totalTax", invoice_create->total_tax) == NULL) {
    goto fail; //String
    }


    // invoice_create->vat_country
    if(invoice_create->vat_country) {
    cJSON *vat_country_local_JSON = country_code_convertToJSON(invoice_create->vat_country);
    if(vat_country_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "vatCountry", vat_country_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // invoice_create->vat_special_case
    if(invoice_create->vat_special_case) {
    if(cJSON_AddStringToObject(item, "vatSpecialCase", invoice_create->vat_special_case) == NULL) {
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

invoice_create_t *invoice_create_parseFromJSON(cJSON *invoice_createJSON){

    invoice_create_t *invoice_create_local_var = NULL;

    // define the local variable for invoice_create->attachments
    _t *attachments_local_nonprim = NULL;

    char *billing_period_end_local_str = NULL;

    char *billing_period_start_local_str = NULL;

    char *cancellation_date_local_str = NULL;

    char *cancellation_invoice_id_local_str = NULL;

    char *cancellation_reason_local_str = NULL;

    char *contract_id_local_str = NULL;

    // define the local variable for invoice_create->currency
    simplebilly_api_currency_code__e currency_local_nonprim = 0;

    char *customer_id_local_str = NULL;

    char *discount_amount_local_str = NULL;

    // define the local variable for invoice_create->discount_days
    int *discount_days_local_var = NULL;

    char *discount_percentage_local_str = NULL;

    // define the local variable for invoice_create->document_type
    simplebilly_api_document_type__e document_type_local_nonprim = 0;

    // define the local variable for invoice_create->dunning_level
    int *dunning_level_local_var = NULL;

    char *input_vat_amount_local_str = NULL;

    // define the local variable for invoice_create->input_vat_deductible
    int *input_vat_deductible_local_var = NULL;

    char *input_vat_percentage_local_str = NULL;

    char *introduction_text_local_str = NULL;

    // define the local variable for invoice_create->invoice_type
    simplebilly_api_invoice_type__e invoice_type_local_nonprim = 0;

    // define the local variable for invoice_create->is_cancelled
    int *is_cancelled_local_var = NULL;

    // define the local variable for invoice_create->is_draft
    int *is_draft_local_var = NULL;

    // define the local variable for invoice_create->is_eu_acquisition
    int *is_eu_acquisition_local_var = NULL;

    // define the local variable for invoice_create->is_eu_delivery
    int *is_eu_delivery_local_var = NULL;

    // define the local variable for invoice_create->is_intra_community_acquisition
    int *is_intra_community_acquisition_local_var = NULL;

    // define the local variable for invoice_create->is_reverse_charge
    int *is_reverse_charge_local_var = NULL;

    char *issue_date_local_str = NULL;

    char *ledger_account_local_str = NULL;

    // define the local variable for invoice_create->line_items
    _t *line_items_local_nonprim = NULL;

    // define the local variable for invoice_create->margin25a
    int *margin25a_local_var = NULL;

    char *margin25a_gross_local_str = NULL;

    char *margin25a_purchase_price_local_str = NULL;

    char *notes_local_str = NULL;

    char *order_number_local_str = NULL;

    char *original_pdf_path_local_str = NULL;

    char *paid_amount_local_str = NULL;

    char *payment_due_date_local_str = NULL;

    // define the local variable for invoice_create->payment_status
    simplebilly_api_payment_status__e payment_status_local_nonprim = 0;

    char *payment_terms_text_local_str = NULL;

    char *preceding_sales_voucher_id_local_str = NULL;

    // define the local variable for invoice_create->preceding_sales_voucher_type
    preceding_sales_voucher_type_t *preceding_sales_voucher_type_local_nonprim = NULL;

    // define the local variable for invoice_create->receipt_confirmation_available
    int *receipt_confirmation_available_local_var = NULL;

    char *related_invoice_id_local_str = NULL;

    char *relationship_type_local_str = NULL;

    // define the local variable for invoice_create->sender_snapshot
    _t *sender_snapshot_local_nonprim = NULL;

    char *sent_at_local_str = NULL;

    char *service_period_end_local_str = NULL;

    char *service_period_start_local_str = NULL;

    // define the local variable for invoice_create->status
    simplebilly_api_invoice_status__e status_local_nonprim = 0;

    char *subtotal_local_str = NULL;

    char *supplier_id_local_str = NULL;

    char *tax_exemption_reason_local_str = NULL;

    char *total_amount_local_str = NULL;

    char *total_tax_local_str = NULL;

    // define the local variable for invoice_create->vat_country
    country_code_t *vat_country_local_nonprim = NULL;

    char *vat_special_case_local_str = NULL;

    // invoice_create->attachments
    cJSON *attachments = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "attachments");
    if (cJSON_IsNull(attachments)) {
        attachments = NULL;
    }
    if (attachments) { 
    attachments_local_nonprim = _parseFromJSON(attachments); //custom
    }

    // invoice_create->billing_period_end
    cJSON *billing_period_end = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "billingPeriodEnd");
    if (cJSON_IsNull(billing_period_end)) {
        billing_period_end = NULL;
    }
    if (billing_period_end) { 
    if(!cJSON_IsString(billing_period_end))
    {
    goto end; //Date
    }
    }

    // invoice_create->billing_period_start
    cJSON *billing_period_start = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "billingPeriodStart");
    if (cJSON_IsNull(billing_period_start)) {
        billing_period_start = NULL;
    }
    if (billing_period_start) { 
    if(!cJSON_IsString(billing_period_start))
    {
    goto end; //Date
    }
    }

    // invoice_create->cancellation_date
    cJSON *cancellation_date = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "cancellationDate");
    if (cJSON_IsNull(cancellation_date)) {
        cancellation_date = NULL;
    }
    if (cancellation_date) { 
    if(!cJSON_IsString(cancellation_date))
    {
    goto end; //Date
    }
    }

    // invoice_create->cancellation_invoice_id
    cJSON *cancellation_invoice_id = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "cancellationInvoiceId");
    if (cJSON_IsNull(cancellation_invoice_id)) {
        cancellation_invoice_id = NULL;
    }
    if (cancellation_invoice_id) { 
    if(!cJSON_IsString(cancellation_invoice_id) && !cJSON_IsNull(cancellation_invoice_id))
    {
    goto end; //String
    }
    }

    // invoice_create->cancellation_reason
    cJSON *cancellation_reason = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "cancellationReason");
    if (cJSON_IsNull(cancellation_reason)) {
        cancellation_reason = NULL;
    }
    if (cancellation_reason) { 
    if(!cJSON_IsString(cancellation_reason) && !cJSON_IsNull(cancellation_reason))
    {
    goto end; //String
    }
    }

    // invoice_create->contract_id
    cJSON *contract_id = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "contractId");
    if (cJSON_IsNull(contract_id)) {
        contract_id = NULL;
    }
    if (contract_id) { 
    if(!cJSON_IsString(contract_id) && !cJSON_IsNull(contract_id))
    {
    goto end; //String
    }
    }

    // invoice_create->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (!currency) {
        goto end;
    }

    
    currency_local_nonprim = currency_code_parseFromJSON(currency); //custom

    // invoice_create->customer_id
    cJSON *customer_id = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "customerId");
    if (cJSON_IsNull(customer_id)) {
        customer_id = NULL;
    }
    if (customer_id) { 
    if(!cJSON_IsString(customer_id) && !cJSON_IsNull(customer_id))
    {
    goto end; //String
    }
    }

    // invoice_create->discount_amount
    cJSON *discount_amount = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "discountAmount");
    if (cJSON_IsNull(discount_amount)) {
        discount_amount = NULL;
    }
    if (discount_amount) { 
    if(!cJSON_IsString(discount_amount) && !cJSON_IsNull(discount_amount))
    {
    goto end; //String
    }
    }

    // invoice_create->discount_days
    cJSON *discount_days = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "discountDays");
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

    // invoice_create->discount_percentage
    cJSON *discount_percentage = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "discountPercentage");
    if (cJSON_IsNull(discount_percentage)) {
        discount_percentage = NULL;
    }
    if (discount_percentage) { 
    if(!cJSON_IsString(discount_percentage) && !cJSON_IsNull(discount_percentage))
    {
    goto end; //String
    }
    }

    // invoice_create->document_type
    cJSON *document_type = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "documentType");
    if (cJSON_IsNull(document_type)) {
        document_type = NULL;
    }
    if (document_type) { 
    document_type_local_nonprim = document_type_parseFromJSON(document_type); //custom
    }

    // invoice_create->dunning_level
    cJSON *dunning_level = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "dunningLevel");
    if (cJSON_IsNull(dunning_level)) {
        dunning_level = NULL;
    }
    if (dunning_level) { 
    if(!cJSON_IsNumber(dunning_level))
    {
    goto end; //Numeric
    }
    dunning_level_local_var = malloc(sizeof(int));
    if(!dunning_level_local_var)
    {
        goto end;
    }
    *dunning_level_local_var = dunning_level->valuedouble;
    }

    // invoice_create->input_vat_amount
    cJSON *input_vat_amount = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "inputVatAmount");
    if (cJSON_IsNull(input_vat_amount)) {
        input_vat_amount = NULL;
    }
    if (input_vat_amount) { 
    if(!cJSON_IsString(input_vat_amount) && !cJSON_IsNull(input_vat_amount))
    {
    goto end; //String
    }
    }

    // invoice_create->input_vat_deductible
    cJSON *input_vat_deductible = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "inputVatDeductible");
    if (cJSON_IsNull(input_vat_deductible)) {
        input_vat_deductible = NULL;
    }
    if (input_vat_deductible) { 
    if(!cJSON_IsBool(input_vat_deductible))
    {
    goto end; //Bool
    }
    input_vat_deductible_local_var = malloc(sizeof(int));
    if(!input_vat_deductible_local_var)
    {
        goto end;
    }
    *input_vat_deductible_local_var = input_vat_deductible->valueint;
    }

    // invoice_create->input_vat_percentage
    cJSON *input_vat_percentage = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "inputVatPercentage");
    if (cJSON_IsNull(input_vat_percentage)) {
        input_vat_percentage = NULL;
    }
    if (input_vat_percentage) { 
    if(!cJSON_IsString(input_vat_percentage) && !cJSON_IsNull(input_vat_percentage))
    {
    goto end; //String
    }
    }

    // invoice_create->introduction_text
    cJSON *introduction_text = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "introductionText");
    if (cJSON_IsNull(introduction_text)) {
        introduction_text = NULL;
    }
    if (introduction_text) { 
    if(!cJSON_IsString(introduction_text) && !cJSON_IsNull(introduction_text))
    {
    goto end; //String
    }
    }

    // invoice_create->invoice_type
    cJSON *invoice_type = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "invoiceType");
    if (cJSON_IsNull(invoice_type)) {
        invoice_type = NULL;
    }
    if (!invoice_type) {
        goto end;
    }

    
    invoice_type_local_nonprim = invoice_type_parseFromJSON(invoice_type); //custom

    // invoice_create->is_cancelled
    cJSON *is_cancelled = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "isCancelled");
    if (cJSON_IsNull(is_cancelled)) {
        is_cancelled = NULL;
    }
    if (is_cancelled) { 
    if(!cJSON_IsBool(is_cancelled))
    {
    goto end; //Bool
    }
    is_cancelled_local_var = malloc(sizeof(int));
    if(!is_cancelled_local_var)
    {
        goto end;
    }
    *is_cancelled_local_var = is_cancelled->valueint;
    }

    // invoice_create->is_draft
    cJSON *is_draft = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "isDraft");
    if (cJSON_IsNull(is_draft)) {
        is_draft = NULL;
    }
    if (is_draft) { 
    if(!cJSON_IsBool(is_draft))
    {
    goto end; //Bool
    }
    is_draft_local_var = malloc(sizeof(int));
    if(!is_draft_local_var)
    {
        goto end;
    }
    *is_draft_local_var = is_draft->valueint;
    }

    // invoice_create->is_eu_acquisition
    cJSON *is_eu_acquisition = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "isEuAcquisition");
    if (cJSON_IsNull(is_eu_acquisition)) {
        is_eu_acquisition = NULL;
    }
    if (is_eu_acquisition) { 
    if(!cJSON_IsBool(is_eu_acquisition))
    {
    goto end; //Bool
    }
    is_eu_acquisition_local_var = malloc(sizeof(int));
    if(!is_eu_acquisition_local_var)
    {
        goto end;
    }
    *is_eu_acquisition_local_var = is_eu_acquisition->valueint;
    }

    // invoice_create->is_eu_delivery
    cJSON *is_eu_delivery = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "isEuDelivery");
    if (cJSON_IsNull(is_eu_delivery)) {
        is_eu_delivery = NULL;
    }
    if (is_eu_delivery) { 
    if(!cJSON_IsBool(is_eu_delivery))
    {
    goto end; //Bool
    }
    is_eu_delivery_local_var = malloc(sizeof(int));
    if(!is_eu_delivery_local_var)
    {
        goto end;
    }
    *is_eu_delivery_local_var = is_eu_delivery->valueint;
    }

    // invoice_create->is_intra_community_acquisition
    cJSON *is_intra_community_acquisition = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "isIntraCommunityAcquisition");
    if (cJSON_IsNull(is_intra_community_acquisition)) {
        is_intra_community_acquisition = NULL;
    }
    if (is_intra_community_acquisition) { 
    if(!cJSON_IsBool(is_intra_community_acquisition))
    {
    goto end; //Bool
    }
    is_intra_community_acquisition_local_var = malloc(sizeof(int));
    if(!is_intra_community_acquisition_local_var)
    {
        goto end;
    }
    *is_intra_community_acquisition_local_var = is_intra_community_acquisition->valueint;
    }

    // invoice_create->is_reverse_charge
    cJSON *is_reverse_charge = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "isReverseCharge");
    if (cJSON_IsNull(is_reverse_charge)) {
        is_reverse_charge = NULL;
    }
    if (is_reverse_charge) { 
    if(!cJSON_IsBool(is_reverse_charge))
    {
    goto end; //Bool
    }
    is_reverse_charge_local_var = malloc(sizeof(int));
    if(!is_reverse_charge_local_var)
    {
        goto end;
    }
    *is_reverse_charge_local_var = is_reverse_charge->valueint;
    }

    // invoice_create->issue_date
    cJSON *issue_date = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "issueDate");
    if (cJSON_IsNull(issue_date)) {
        issue_date = NULL;
    }
    if (!issue_date) {
        goto end;
    }

    
    if(!cJSON_IsString(issue_date))
    {
    goto end; //Date
    }

    // invoice_create->ledger_account
    cJSON *ledger_account = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "ledgerAccount");
    if (cJSON_IsNull(ledger_account)) {
        ledger_account = NULL;
    }
    if (ledger_account) { 
    if(!cJSON_IsString(ledger_account) && !cJSON_IsNull(ledger_account))
    {
    goto end; //String
    }
    }

    // invoice_create->line_items
    cJSON *line_items = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "lineItems");
    if (cJSON_IsNull(line_items)) {
        line_items = NULL;
    }
    if (!line_items) {
        goto end;
    }

    
    line_items_local_nonprim = _parseFromJSON(line_items); //custom

    // invoice_create->margin25a
    cJSON *margin25a = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "margin25a");
    if (cJSON_IsNull(margin25a)) {
        margin25a = NULL;
    }
    if (margin25a) { 
    if(!cJSON_IsBool(margin25a))
    {
    goto end; //Bool
    }
    margin25a_local_var = malloc(sizeof(int));
    if(!margin25a_local_var)
    {
        goto end;
    }
    *margin25a_local_var = margin25a->valueint;
    }

    // invoice_create->margin25a_gross
    cJSON *margin25a_gross = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "margin25aGross");
    if (cJSON_IsNull(margin25a_gross)) {
        margin25a_gross = NULL;
    }
    if (margin25a_gross) { 
    if(!cJSON_IsString(margin25a_gross) && !cJSON_IsNull(margin25a_gross))
    {
    goto end; //String
    }
    }

    // invoice_create->margin25a_purchase_price
    cJSON *margin25a_purchase_price = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "margin25aPurchasePrice");
    if (cJSON_IsNull(margin25a_purchase_price)) {
        margin25a_purchase_price = NULL;
    }
    if (margin25a_purchase_price) { 
    if(!cJSON_IsString(margin25a_purchase_price) && !cJSON_IsNull(margin25a_purchase_price))
    {
    goto end; //String
    }
    }

    // invoice_create->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // invoice_create->order_number
    cJSON *order_number = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "orderNumber");
    if (cJSON_IsNull(order_number)) {
        order_number = NULL;
    }
    if (order_number) { 
    if(!cJSON_IsString(order_number) && !cJSON_IsNull(order_number))
    {
    goto end; //String
    }
    }

    // invoice_create->original_pdf_path
    cJSON *original_pdf_path = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "originalPdfPath");
    if (cJSON_IsNull(original_pdf_path)) {
        original_pdf_path = NULL;
    }
    if (original_pdf_path) { 
    if(!cJSON_IsString(original_pdf_path) && !cJSON_IsNull(original_pdf_path))
    {
    goto end; //String
    }
    }

    // invoice_create->paid_amount
    cJSON *paid_amount = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "paidAmount");
    if (cJSON_IsNull(paid_amount)) {
        paid_amount = NULL;
    }
    if (paid_amount) { 
    if(!cJSON_IsString(paid_amount) && !cJSON_IsNull(paid_amount))
    {
    goto end; //String
    }
    }

    // invoice_create->payment_due_date
    cJSON *payment_due_date = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "paymentDueDate");
    if (cJSON_IsNull(payment_due_date)) {
        payment_due_date = NULL;
    }
    if (payment_due_date) { 
    if(!cJSON_IsString(payment_due_date))
    {
    goto end; //Date
    }
    }

    // invoice_create->payment_status
    cJSON *payment_status = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "paymentStatus");
    if (cJSON_IsNull(payment_status)) {
        payment_status = NULL;
    }
    if (payment_status) { 
    payment_status_local_nonprim = payment_status_parseFromJSON(payment_status); //custom
    }

    // invoice_create->payment_terms_text
    cJSON *payment_terms_text = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "paymentTermsText");
    if (cJSON_IsNull(payment_terms_text)) {
        payment_terms_text = NULL;
    }
    if (payment_terms_text) { 
    if(!cJSON_IsString(payment_terms_text) && !cJSON_IsNull(payment_terms_text))
    {
    goto end; //String
    }
    }

    // invoice_create->preceding_sales_voucher_id
    cJSON *preceding_sales_voucher_id = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "precedingSalesVoucherId");
    if (cJSON_IsNull(preceding_sales_voucher_id)) {
        preceding_sales_voucher_id = NULL;
    }
    if (preceding_sales_voucher_id) { 
    if(!cJSON_IsString(preceding_sales_voucher_id) && !cJSON_IsNull(preceding_sales_voucher_id))
    {
    goto end; //String
    }
    }

    // invoice_create->preceding_sales_voucher_type
    cJSON *preceding_sales_voucher_type = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "precedingSalesVoucherType");
    if (cJSON_IsNull(preceding_sales_voucher_type)) {
        preceding_sales_voucher_type = NULL;
    }
    if (preceding_sales_voucher_type) { 
    preceding_sales_voucher_type_local_nonprim = preceding_sales_voucher_type_parseFromJSON(preceding_sales_voucher_type); //custom
    }

    // invoice_create->receipt_confirmation_available
    cJSON *receipt_confirmation_available = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "receiptConfirmationAvailable");
    if (cJSON_IsNull(receipt_confirmation_available)) {
        receipt_confirmation_available = NULL;
    }
    if (receipt_confirmation_available) { 
    if(!cJSON_IsBool(receipt_confirmation_available))
    {
    goto end; //Bool
    }
    receipt_confirmation_available_local_var = malloc(sizeof(int));
    if(!receipt_confirmation_available_local_var)
    {
        goto end;
    }
    *receipt_confirmation_available_local_var = receipt_confirmation_available->valueint;
    }

    // invoice_create->related_invoice_id
    cJSON *related_invoice_id = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "relatedInvoiceId");
    if (cJSON_IsNull(related_invoice_id)) {
        related_invoice_id = NULL;
    }
    if (related_invoice_id) { 
    if(!cJSON_IsString(related_invoice_id) && !cJSON_IsNull(related_invoice_id))
    {
    goto end; //String
    }
    }

    // invoice_create->relationship_type
    cJSON *relationship_type = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "relationshipType");
    if (cJSON_IsNull(relationship_type)) {
        relationship_type = NULL;
    }
    if (relationship_type) { 
    if(!cJSON_IsString(relationship_type) && !cJSON_IsNull(relationship_type))
    {
    goto end; //String
    }
    }

    // invoice_create->sender_snapshot
    cJSON *sender_snapshot = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "senderSnapshot");
    if (cJSON_IsNull(sender_snapshot)) {
        sender_snapshot = NULL;
    }
    if (sender_snapshot) { 
    sender_snapshot_local_nonprim = _parseFromJSON(sender_snapshot); //custom
    }

    // invoice_create->sent_at
    cJSON *sent_at = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "sentAt");
    if (cJSON_IsNull(sent_at)) {
        sent_at = NULL;
    }
    if (sent_at) { 
    if(!cJSON_IsString(sent_at) && !cJSON_IsNull(sent_at))
    {
    goto end; //DateTime
    }
    }

    // invoice_create->service_period_end
    cJSON *service_period_end = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "servicePeriodEnd");
    if (cJSON_IsNull(service_period_end)) {
        service_period_end = NULL;
    }
    if (service_period_end) { 
    if(!cJSON_IsString(service_period_end))
    {
    goto end; //Date
    }
    }

    // invoice_create->service_period_start
    cJSON *service_period_start = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "servicePeriodStart");
    if (cJSON_IsNull(service_period_start)) {
        service_period_start = NULL;
    }
    if (service_period_start) { 
    if(!cJSON_IsString(service_period_start))
    {
    goto end; //Date
    }
    }

    // invoice_create->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = invoice_status_parseFromJSON(status); //custom

    // invoice_create->subtotal
    cJSON *subtotal = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "subtotal");
    if (cJSON_IsNull(subtotal)) {
        subtotal = NULL;
    }
    if (!subtotal) {
        goto end;
    }

    
    if(!cJSON_IsString(subtotal))
    {
    goto end; //String
    }

    // invoice_create->supplier_id
    cJSON *supplier_id = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "supplierId");
    if (cJSON_IsNull(supplier_id)) {
        supplier_id = NULL;
    }
    if (supplier_id) { 
    if(!cJSON_IsString(supplier_id) && !cJSON_IsNull(supplier_id))
    {
    goto end; //String
    }
    }

    // invoice_create->tax_exemption_reason
    cJSON *tax_exemption_reason = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "taxExemptionReason");
    if (cJSON_IsNull(tax_exemption_reason)) {
        tax_exemption_reason = NULL;
    }
    if (tax_exemption_reason) { 
    if(!cJSON_IsString(tax_exemption_reason) && !cJSON_IsNull(tax_exemption_reason))
    {
    goto end; //String
    }
    }

    // invoice_create->total_amount
    cJSON *total_amount = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "totalAmount");
    if (cJSON_IsNull(total_amount)) {
        total_amount = NULL;
    }
    if (!total_amount) {
        goto end;
    }

    
    if(!cJSON_IsString(total_amount))
    {
    goto end; //String
    }

    // invoice_create->total_tax
    cJSON *total_tax = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "totalTax");
    if (cJSON_IsNull(total_tax)) {
        total_tax = NULL;
    }
    if (!total_tax) {
        goto end;
    }

    
    if(!cJSON_IsString(total_tax))
    {
    goto end; //String
    }

    // invoice_create->vat_country
    cJSON *vat_country = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "vatCountry");
    if (cJSON_IsNull(vat_country)) {
        vat_country = NULL;
    }
    if (vat_country) { 
    vat_country_local_nonprim = country_code_parseFromJSON(vat_country); //custom
    }

    // invoice_create->vat_special_case
    cJSON *vat_special_case = cJSON_GetObjectItemCaseSensitive(invoice_createJSON, "vatSpecialCase");
    if (cJSON_IsNull(vat_special_case)) {
        vat_special_case = NULL;
    }
    if (vat_special_case) { 
    if(!cJSON_IsString(vat_special_case) && !cJSON_IsNull(vat_special_case))
    {
    goto end; //String
    }
    }


    if (billing_period_end) billing_period_end_local_str = strdup(billing_period_end->valuestring);
    if (billing_period_start) billing_period_start_local_str = strdup(billing_period_start->valuestring);
    if (cancellation_date) cancellation_date_local_str = strdup(cancellation_date->valuestring);
    if (cancellation_invoice_id && !cJSON_IsNull(cancellation_invoice_id)) cancellation_invoice_id_local_str = strdup(cancellation_invoice_id->valuestring);
    if (cancellation_reason && !cJSON_IsNull(cancellation_reason)) cancellation_reason_local_str = strdup(cancellation_reason->valuestring);
    if (contract_id && !cJSON_IsNull(contract_id)) contract_id_local_str = strdup(contract_id->valuestring);
    if (customer_id && !cJSON_IsNull(customer_id)) customer_id_local_str = strdup(customer_id->valuestring);
    if (discount_amount && !cJSON_IsNull(discount_amount)) discount_amount_local_str = strdup(discount_amount->valuestring);
    if (discount_percentage && !cJSON_IsNull(discount_percentage)) discount_percentage_local_str = strdup(discount_percentage->valuestring);
    if (input_vat_amount && !cJSON_IsNull(input_vat_amount)) input_vat_amount_local_str = strdup(input_vat_amount->valuestring);
    if (input_vat_percentage && !cJSON_IsNull(input_vat_percentage)) input_vat_percentage_local_str = strdup(input_vat_percentage->valuestring);
    if (introduction_text && !cJSON_IsNull(introduction_text)) introduction_text_local_str = strdup(introduction_text->valuestring);
    if (issue_date) issue_date_local_str = strdup(issue_date->valuestring);
    if (ledger_account && !cJSON_IsNull(ledger_account)) ledger_account_local_str = strdup(ledger_account->valuestring);
    if (margin25a_gross && !cJSON_IsNull(margin25a_gross)) margin25a_gross_local_str = strdup(margin25a_gross->valuestring);
    if (margin25a_purchase_price && !cJSON_IsNull(margin25a_purchase_price)) margin25a_purchase_price_local_str = strdup(margin25a_purchase_price->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (order_number && !cJSON_IsNull(order_number)) order_number_local_str = strdup(order_number->valuestring);
    if (original_pdf_path && !cJSON_IsNull(original_pdf_path)) original_pdf_path_local_str = strdup(original_pdf_path->valuestring);
    if (paid_amount && !cJSON_IsNull(paid_amount)) paid_amount_local_str = strdup(paid_amount->valuestring);
    if (payment_due_date) payment_due_date_local_str = strdup(payment_due_date->valuestring);
    if (payment_terms_text && !cJSON_IsNull(payment_terms_text)) payment_terms_text_local_str = strdup(payment_terms_text->valuestring);
    if (preceding_sales_voucher_id && !cJSON_IsNull(preceding_sales_voucher_id)) preceding_sales_voucher_id_local_str = strdup(preceding_sales_voucher_id->valuestring);
    if (related_invoice_id && !cJSON_IsNull(related_invoice_id)) related_invoice_id_local_str = strdup(related_invoice_id->valuestring);
    if (relationship_type && !cJSON_IsNull(relationship_type)) relationship_type_local_str = strdup(relationship_type->valuestring);
    if (sent_at && !cJSON_IsNull(sent_at)) sent_at_local_str = strdup(sent_at->valuestring);
    if (service_period_end) service_period_end_local_str = strdup(service_period_end->valuestring);
    if (service_period_start) service_period_start_local_str = strdup(service_period_start->valuestring);
    if (subtotal && !cJSON_IsNull(subtotal)) subtotal_local_str = strdup(subtotal->valuestring);
    if (supplier_id && !cJSON_IsNull(supplier_id)) supplier_id_local_str = strdup(supplier_id->valuestring);
    if (tax_exemption_reason && !cJSON_IsNull(tax_exemption_reason)) tax_exemption_reason_local_str = strdup(tax_exemption_reason->valuestring);
    if (total_amount && !cJSON_IsNull(total_amount)) total_amount_local_str = strdup(total_amount->valuestring);
    if (total_tax && !cJSON_IsNull(total_tax)) total_tax_local_str = strdup(total_tax->valuestring);
    if (vat_special_case && !cJSON_IsNull(vat_special_case)) vat_special_case_local_str = strdup(vat_special_case->valuestring);

    invoice_create_local_var = invoice_create_create_internal (
        attachments ? attachments_local_nonprim : NULL,
        billing_period_end_local_str,
        billing_period_start_local_str,
        cancellation_date_local_str,
        cancellation_invoice_id_local_str,
        cancellation_reason_local_str,
        contract_id_local_str,
        currency_local_nonprim,
        customer_id_local_str,
        discount_amount_local_str,
        discount_days_local_var,
        discount_percentage_local_str,
        document_type ? document_type_local_nonprim : 0,
        dunning_level_local_var,
        input_vat_amount_local_str,
        input_vat_deductible_local_var,
        input_vat_percentage_local_str,
        introduction_text_local_str,
        invoice_type_local_nonprim,
        is_cancelled_local_var,
        is_draft_local_var,
        is_eu_acquisition_local_var,
        is_eu_delivery_local_var,
        is_intra_community_acquisition_local_var,
        is_reverse_charge_local_var,
        issue_date_local_str,
        ledger_account_local_str,
        line_items_local_nonprim,
        margin25a_local_var,
        margin25a_gross_local_str,
        margin25a_purchase_price_local_str,
        notes_local_str,
        order_number_local_str,
        original_pdf_path_local_str,
        paid_amount_local_str,
        payment_due_date_local_str,
        payment_status ? payment_status_local_nonprim : 0,
        payment_terms_text_local_str,
        preceding_sales_voucher_id_local_str,
        preceding_sales_voucher_type ? preceding_sales_voucher_type_local_nonprim : NULL,
        receipt_confirmation_available_local_var,
        related_invoice_id_local_str,
        relationship_type_local_str,
        sender_snapshot ? sender_snapshot_local_nonprim : NULL,
        sent_at_local_str,
        service_period_end_local_str,
        service_period_start_local_str,
        status_local_nonprim,
        subtotal_local_str,
        supplier_id_local_str,
        tax_exemption_reason_local_str,
        total_amount_local_str,
        total_tax_local_str,
        vat_country ? vat_country_local_nonprim : NULL,
        vat_special_case_local_str
        );

    if (!invoice_create_local_var) {
        goto end;
    }

    return invoice_create_local_var;
end:
    if (attachments_local_nonprim) {
        _free(attachments_local_nonprim);
        attachments_local_nonprim = NULL;
    }
    if (billing_period_end_local_str) {
        free(billing_period_end_local_str);
        billing_period_end_local_str = NULL;
    }
    if (billing_period_start_local_str) {
        free(billing_period_start_local_str);
        billing_period_start_local_str = NULL;
    }
    if (cancellation_date_local_str) {
        free(cancellation_date_local_str);
        cancellation_date_local_str = NULL;
    }
    if (cancellation_invoice_id_local_str) {
        free(cancellation_invoice_id_local_str);
        cancellation_invoice_id_local_str = NULL;
    }
    if (cancellation_reason_local_str) {
        free(cancellation_reason_local_str);
        cancellation_reason_local_str = NULL;
    }
    if (contract_id_local_str) {
        free(contract_id_local_str);
        contract_id_local_str = NULL;
    }
    if (currency_local_nonprim) {
        currency_local_nonprim = 0;
    }
    if (customer_id_local_str) {
        free(customer_id_local_str);
        customer_id_local_str = NULL;
    }
    if (discount_amount_local_str) {
        free(discount_amount_local_str);
        discount_amount_local_str = NULL;
    }
    if (discount_days_local_var) {
        free(discount_days_local_var);
        discount_days_local_var = NULL;
    }
    if (discount_percentage_local_str) {
        free(discount_percentage_local_str);
        discount_percentage_local_str = NULL;
    }
    if (document_type_local_nonprim) {
        document_type_local_nonprim = 0;
    }
    if (dunning_level_local_var) {
        free(dunning_level_local_var);
        dunning_level_local_var = NULL;
    }
    if (input_vat_amount_local_str) {
        free(input_vat_amount_local_str);
        input_vat_amount_local_str = NULL;
    }
    if (input_vat_deductible_local_var) {
        free(input_vat_deductible_local_var);
        input_vat_deductible_local_var = NULL;
    }
    if (input_vat_percentage_local_str) {
        free(input_vat_percentage_local_str);
        input_vat_percentage_local_str = NULL;
    }
    if (introduction_text_local_str) {
        free(introduction_text_local_str);
        introduction_text_local_str = NULL;
    }
    if (invoice_type_local_nonprim) {
        invoice_type_local_nonprim = 0;
    }
    if (is_cancelled_local_var) {
        free(is_cancelled_local_var);
        is_cancelled_local_var = NULL;
    }
    if (is_draft_local_var) {
        free(is_draft_local_var);
        is_draft_local_var = NULL;
    }
    if (is_eu_acquisition_local_var) {
        free(is_eu_acquisition_local_var);
        is_eu_acquisition_local_var = NULL;
    }
    if (is_eu_delivery_local_var) {
        free(is_eu_delivery_local_var);
        is_eu_delivery_local_var = NULL;
    }
    if (is_intra_community_acquisition_local_var) {
        free(is_intra_community_acquisition_local_var);
        is_intra_community_acquisition_local_var = NULL;
    }
    if (is_reverse_charge_local_var) {
        free(is_reverse_charge_local_var);
        is_reverse_charge_local_var = NULL;
    }
    if (issue_date_local_str) {
        free(issue_date_local_str);
        issue_date_local_str = NULL;
    }
    if (ledger_account_local_str) {
        free(ledger_account_local_str);
        ledger_account_local_str = NULL;
    }
    if (line_items_local_nonprim) {
        _free(line_items_local_nonprim);
        line_items_local_nonprim = NULL;
    }
    if (margin25a_local_var) {
        free(margin25a_local_var);
        margin25a_local_var = NULL;
    }
    if (margin25a_gross_local_str) {
        free(margin25a_gross_local_str);
        margin25a_gross_local_str = NULL;
    }
    if (margin25a_purchase_price_local_str) {
        free(margin25a_purchase_price_local_str);
        margin25a_purchase_price_local_str = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (order_number_local_str) {
        free(order_number_local_str);
        order_number_local_str = NULL;
    }
    if (original_pdf_path_local_str) {
        free(original_pdf_path_local_str);
        original_pdf_path_local_str = NULL;
    }
    if (paid_amount_local_str) {
        free(paid_amount_local_str);
        paid_amount_local_str = NULL;
    }
    if (payment_due_date_local_str) {
        free(payment_due_date_local_str);
        payment_due_date_local_str = NULL;
    }
    if (payment_status_local_nonprim) {
        payment_status_local_nonprim = 0;
    }
    if (payment_terms_text_local_str) {
        free(payment_terms_text_local_str);
        payment_terms_text_local_str = NULL;
    }
    if (preceding_sales_voucher_id_local_str) {
        free(preceding_sales_voucher_id_local_str);
        preceding_sales_voucher_id_local_str = NULL;
    }
    if (preceding_sales_voucher_type_local_nonprim) {
        preceding_sales_voucher_type_free(preceding_sales_voucher_type_local_nonprim);
        preceding_sales_voucher_type_local_nonprim = NULL;
    }
    if (receipt_confirmation_available_local_var) {
        free(receipt_confirmation_available_local_var);
        receipt_confirmation_available_local_var = NULL;
    }
    if (related_invoice_id_local_str) {
        free(related_invoice_id_local_str);
        related_invoice_id_local_str = NULL;
    }
    if (relationship_type_local_str) {
        free(relationship_type_local_str);
        relationship_type_local_str = NULL;
    }
    if (sender_snapshot_local_nonprim) {
        _free(sender_snapshot_local_nonprim);
        sender_snapshot_local_nonprim = NULL;
    }
    if (sent_at_local_str) {
        free(sent_at_local_str);
        sent_at_local_str = NULL;
    }
    if (service_period_end_local_str) {
        free(service_period_end_local_str);
        service_period_end_local_str = NULL;
    }
    if (service_period_start_local_str) {
        free(service_period_start_local_str);
        service_period_start_local_str = NULL;
    }
    if (status_local_nonprim) {
        status_local_nonprim = 0;
    }
    if (subtotal_local_str) {
        free(subtotal_local_str);
        subtotal_local_str = NULL;
    }
    if (supplier_id_local_str) {
        free(supplier_id_local_str);
        supplier_id_local_str = NULL;
    }
    if (tax_exemption_reason_local_str) {
        free(tax_exemption_reason_local_str);
        tax_exemption_reason_local_str = NULL;
    }
    if (total_amount_local_str) {
        free(total_amount_local_str);
        total_amount_local_str = NULL;
    }
    if (total_tax_local_str) {
        free(total_tax_local_str);
        total_tax_local_str = NULL;
    }
    if (vat_country_local_nonprim) {
        country_code_free(vat_country_local_nonprim);
        vat_country_local_nonprim = NULL;
    }
    if (vat_special_case_local_str) {
        free(vat_special_case_local_str);
        vat_special_case_local_str = NULL;
    }
    return NULL;

}
