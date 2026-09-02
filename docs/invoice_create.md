# invoice_create_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**attachments** | **any_type_t \*** |  | [optional] 
**billing_period_end** | **char \*** |  | [optional] 
**billing_period_start** | **char \*** |  | [optional] 
**cancellation_date** | **char \*** |  | [optional] 
**cancellation_invoice_id** | **char \*** | References the invoice entity. | [optional] 
**cancellation_reason** | **char \*** |  | [optional] 
**contract_id** | **char \*** | References the contract entity. | [optional] 
**currency** | **currency_code_t \*** |  | 
**customer_id** | **char \*** | References the customer entity. | [optional] 
**discount_amount** | **char \*** |  | [optional] 
**discount_days** | **int** |  | [optional] 
**discount_percentage** | **char \*** |  | [optional] 
**document_type** | **document_type_t \*** |  | [optional] 
**dunning_level** | **int** |  | [optional] 
**input_vat_amount** | **char \*** |  | [optional] 
**input_vat_deductible** | **int** |  | [optional] 
**input_vat_percentage** | **char \*** |  | [optional] 
**introduction_text** | **char \*** |  | [optional] 
**invoice_type** | **invoice_type_t \*** |  | 
**is_cancelled** | **int** |  | [optional] 
**is_draft** | **int** |  | [optional] 
**is_eu_acquisition** | **int** |  | [optional] 
**is_eu_delivery** | **int** |  | [optional] 
**is_intra_community_acquisition** | **int** |  | [optional] 
**is_reverse_charge** | **int** |  | [optional] 
**issue_date** | **char \*** |  | 
**ledger_account** | **char \*** |  | [optional] 
**line_items** | **any_type_t \*** |  | 
**margin25a** | **int** |  | [optional] 
**margin25a_gross** | **char \*** |  | [optional] 
**margin25a_purchase_price** | **char \*** |  | [optional] 
**notes** | **char \*** |  | [optional] 
**order_number** | **char \*** |  | [optional] 
**original_pdf_path** | **char \*** |  | [optional] 
**paid_amount** | **char \*** |  | [optional] 
**payment_due_date** | **char \*** |  | [optional] 
**payment_status** | **payment_status_t \*** |  | [optional] 
**payment_terms_text** | **char \*** |  | [optional] 
**preceding_sales_voucher_id** | **char \*** | References the preceding sales voucher entity. | [optional] 
**preceding_sales_voucher_type** | **preceding_sales_voucher_type_t \*** |  | [optional] 
**receipt_confirmation_available** | **int** |  | [optional] 
**related_invoice_id** | **char \*** | References the invoice entity. | [optional] 
**relationship_type** | **char \*** |  | [optional] 
**sender_snapshot** | **any_type_t \*** |  | [optional] 
**sent_at** | **char \*** |  | [optional] 
**service_period_end** | **char \*** |  | [optional] 
**service_period_start** | **char \*** |  | [optional] 
**status** | **invoice_status_t \*** |  | 
**subtotal** | **char \*** |  | 
**supplier_id** | **char \*** | References the supplier entity. | [optional] 
**tax_exemption_reason** | **char \*** |  | [optional] 
**total_amount** | **char \*** |  | 
**total_tax** | **char \*** |  | 
**vat_country** | **country_code_t \*** |  | [optional] 
**vat_special_case** | **char \*** |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


