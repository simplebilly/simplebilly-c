cmake_minimum_required (VERSION 2.6...3.10.2)
project (CGenerator C)

cmake_policy(SET CMP0063 NEW)

set(CMAKE_C_VISIBILITY_PRESET default)
set(CMAKE_VISIBILITY_INLINES_HIDDEN OFF)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror=implicit-function-declaration")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror=missing-declarations")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror=int-conversion")

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

find_package(OpenSSL)

if (OPENSSL_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DOPENSSL")
    if(CMAKE_VERSION VERSION_LESS 3.4)
        include_directories(${OPENSSL_INCLUDE_DIR})
        include_directories(${OPENSSL_INCLUDE_DIRS})
        link_directories(${OPENSSL_LIBRARIES})
    endif()
endif()

set(pkgName "simplebilly_api")

# this default version can be overridden in PreTarget.cmake
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 1)

if( (DEFINED CURL_INCLUDE_DIR) AND (DEFINED CURL_LIBRARIES))
    include_directories(${CURL_INCLUDE_DIR})
    set(PLATFORM_LIBRARIES ${PLATFORM_LIBRARIES} ${CURL_LIBRARIES} )
else()
    find_package(CURL 7.58.0 REQUIRED)
    if(CURL_FOUND)
        include_directories(${CURL_INCLUDE_DIR})
        set(PLATFORM_LIBRARIES ${PLATFORM_LIBRARIES} ${CURL_LIBRARIES} )
    endif()
endif()

set(SRCS
    src/list.c
    src/apiKey.c
    src/apiClient.c
    src/binary.c
    external/cJSON.c
    model/object.c
    model/absence.c
    model/absence_create.c
    model/absence_status.c
    model/absence_type.c
    model/absence_update.c
    model/accept_invite_request.c
    model/account_overview.c
    model/activity.c
    model/activity_create.c
    model/activity_status.c
    model/activity_status_update.c
    model/activity_type.c
    model/activity_update.c
    model/address.c
    model/ai_config_dto.c
    model/ai_suggestion.c
    model/ai_suggestion_request.c
    model/ai_worker_config.c
    model/allocate_payment_request.c
    model/anlage_g_ergebnis.c
    model/anlage_g_kfz_hinweis.c
    model/anlage_s_ergebnis.c
    model/anlage_s_kfz_hinweis.c
    model/api_response_gdpr_export.c
    model/api_response_gdpr_export_data.c
    model/api_response_string.c
    model/api_response_subscription_overview.c
    model/api_response_subscription_overview_data.c
    model/api_response_team.c
    model/api_response_team_data.c
    model/api_response_user_profile.c
    model/api_response_user_profile_data.c
    model/api_response_vec_plan.c
    model/api_response_vec_plan_data_inner.c
    model/api_response_vec_team.c
    model/api_response_vec_user_tenant_info.c
    model/api_response_vec_user_tenant_info_data_inner.c
    model/application_filter.c
    model/application_status.c
    model/application_status_dto.c
    model/appointment_status_update.c
    model/assignment_status.c
    model/attachment.c
    model/attachment_create.c
    model/attachment_version.c
    model/auth_response.c
    model/automation.c
    model/automation_dto.c
    model/balance_item.c
    model/balance_sheet.c
    model/bank_lookup.c
    model/betriebsstaette.c
    model/betriebsstaetten_detail.c
    model/bilanz_item.c
    model/bilanz_report.c
    model/bom.c
    model/bom_create.c
    model/bom_status.c
    model/bom_update.c
    model/box_fit.c
    model/budget.c
    model/budget_ergebnis.c
    model/budget_goal_request.c
    model/budget_kategorie.c
    model/bwa_expenses.c
    model/bwa_report.c
    model/bwa_revenue.c
    model/bwa_summary.c
    model/cart_item_input.c
    model/cashflow_report.c
    model/category_total.c
    model/change_password_request.c
    model/changelog_entry.c
    model/check_status.c
    model/communication_channel.c
    model/communication_direction.c
    model/company_type.c
    model/compliance_entry.c
    model/compliance_training.c
    model/compliance_training_create.c
    model/compliance_training_update.c
    model/config_field_info.c
    model/config_field_kind.c
    model/config_field_kind_one_of.c
    model/config_field_kind_one_of_1.c
    model/config_field_kind_one_of_2.c
    model/config_field_kind_one_of_3.c
    model/config_field_kind_one_of_4.c
    model/connector_type.c
    model/contact.c
    model/contact_create.c
    model/contact_history_response.c
    model/contact_info.c
    model/contact_timeline_response.c
    model/contact_type.c
    model/contact_update.c
    model/convert_response.c
    model/costing_line.c
    model/country_code.c
    model/coupon.c
    model/coupon_create.c
    model/coupon_update.c
    model/coupon_validation.c
    model/create_channel_dto.c
    model/create_connection_request.c
    model/create_emission_entry.c
    model/create_emission_target.c
    model/create_shipment_request.c
    model/create_subscription_request.c
    model/create_ticket_request.c
    model/currency_code.c
    model/current_inventory_value.c
    model/customer.c
    model/customer_communication.c
    model/customer_communication_create.c
    model/customer_communication_update.c
    model/customer_create.c
    model/customer_group.c
    model/customer_group_create.c
    model/customer_group_update.c
    model/customer_info.c
    model/customer_update.c
    model/data_quality.c
    model/datev_booking_preview.c
    model/datev_export_response.c
    model/datev_import_response.c
    model/datev_import_row.c
    model/declaration.c
    model/declaration_create.c
    model/declaration_type.c
    model/declaration_update.c
    model/deliverable_response.c
    model/delivery_appointment.c
    model/delivery_appointment_create.c
    model/delivery_appointment_status.c
    model/delivery_date.c
    model/delivery_date_create.c
    model/delivery_date_status.c
    model/delivery_date_status_update.c
    model/delivery_date_update.c
    model/delivery_note.c
    model/delivery_note_create.c
    model/dhl_credentials.c
    model/discount_type.c
    model/document_type.c
    model/down_payment_invoice.c
    model/dpa_accept_request.c
    model/dpa_status.c
    model/dunning_result.c
    model/e_bilanz_report.c
    model/eks_ergebnis.c
    model/eks_monats_wert.c
    model/elster_status.c
    model/email_template.c
    model/email_template_create.c
    model/email_template_status.c
    model/email_template_update.c
    model/emission_entry.c
    model/emission_factor_response.c
    model/emission_method.c
    model/emission_target.c
    model/emission_target_scope.c
    model/emissions_export_response.c
    model/emissions_report.c
    model/emit_event_request.c
    model/employee.c
    model/employee_create.c
    model/employee_status.c
    model/employee_update.c
    model/employment_type.c
    model/euer_detail_ergebnis.c
    model/euer_ergebnis.c
    model/euer_kat_summe.c
    model/euer_zeile.c
    model/euer_zeile_detail.c
    model/event_subscription.c
    model/execution_status.c
    model/expense_item.c
    model/extra_payment.c
    model/feature_settings.c
    model/forgot_password_request.c
    model/frist_eintrag.c
    model/fristen_ergebnis.c
    model/gateway_o_auth_authorize_request.c
    model/gateway_o_auth_authorize_response.c
    model/gateway_o_auth_callback_request.c
    model/gateway_type.c
    model/gdpr_activity.c
    model/gdpr_api_key.c
    model/gdpr_billing_info.c
    model/gdpr_export.c
    model/gdpr_notification.c
    model/gdpr_refresh_token.c
    model/gdpr_tenant.c
    model/gdpr_usage_event.c
    model/gdpr_user.c
    model/gender.c
    model/generate_count_request.c
    model/generate_variants_request.c
    model/gewerbesteuer_ergebnis.c
    model/gewinnverwendungs_export_response.c
    model/gewinnverwendungs_report.c
    model/gewinnverwendungs_zeile.c
    model/gez_report.c
    model/ghg_scope.c
    model/go_bd_export_response.c
    model/goods_receipt.c
    model/group_figure.c
    model/group_figure_create.c
    model/group_figure_update.c
    model/gu_v_item.c
    model/gu_v_report.c
    model/hebesatz_lookup.c
    model/hr_training_overview.c
    model/import_job_status.c
    model/import_start_request.c
    model/import_start_response.c
    model/import_test_request.c
    model/import_test_response.c
    model/income_statement.c
    model/institute_check_item.c
    model/institute_deadlines.c
    model/institute_profile.c
    model/institute_profile_update.c
    model/institute_status.c
    model/institute_type.c
    model/instrument_type.c
    model/inventory_count.c
    model/inventory_count_create.c
    model/inventory_count_status.c
    model/inventory_count_status_update.c
    model/inventory_count_update.c
    model/inventory_value_point.c
    model/invite_request.c
    model/invoice.c
    model/invoice_create.c
    model/invoice_line_item.c
    model/invoice_match_request.c
    model/invoice_pdf_url_response.c
    model/invoice_status.c
    model/invoice_type.c
    model/jahres_ust_ergebnis.c
    model/job.c
    model/job_application.c
    model/job_posting.c
    model/job_posting_create.c
    model/job_posting_filter.c
    model/job_posting_status.c
    model/job_posting_update.c
    model/job_status.c
    model/job_title_gap.c
    model/konto_item.c
    model/konto_report.c
    model/konzern_beteiligung.c
    model/konzern_export_response.c
    model/konzern_status.c
    model/konzern_thresholds.c
    model/kosten_eintrag.c
    model/kosten_vorschau.c
    model/kst_ergebnis.c
    model/kyc_record.c
    model/kyc_record_create.c
    model/kyc_record_update.c
    model/labor_cost_row.c
    model/language_code.c
    model/lead.c
    model/lead_status.c
    model/lead_update.c
    model/legal_doc_type.c
    model/legal_document.c
    model/legal_document_reset.c
    model/legal_document_upsert.c
    model/liquidity_position.c
    model/login_request.c
    model/magic_link_request.c
    model/magic_link_verify_request.c
    model/marketplace_connection.c
    model/marketplace_sync_log.c
    model/marketplace_webhook_event.c
    model/message_direction.c
    model/message_type.c
    model/metered_usage.c
    model/method_suitability.c
    model/mirror_trigger_response.c
    model/model.c
    model/movement_type.c
    model/my_training_item.c
    model/new_version_request.c
    model/notification_dto.c
    model/o_auth_authorize_request.c
    model/o_auth_authorize_response.c
    model/o_auth_callback_request.c
    model/ocr_text_request.c
    model/offenlegung_item.c
    model/offenlegung_report.c
    model/open_item.c
    model/order.c
    model/order_confirmation.c
    model/order_confirmation_create.c
    model/order_create.c
    model/order_state_update.c
    model/order_status.c
    model/order_tags_request.c
    model/order_update.c
    model/oss_dependency.c
    model/oss_report.c
    model/package.c
    model/packing_complete_request.c
    model/packing_complete_response.c
    model/packing_queue.c
    model/packing_queue_item.c
    model/packing_video_response.c
    model/partial_feature_settings.c
    model/participation.c
    model/participation_create.c
    model/participation_update.c
    model/pay_gap_export_response.c
    model/pay_gap_info_response.c
    model/pay_gap_report.c
    model/payment.c
    model/payment_condition.c
    model/payment_create.c
    model/payment_gateway.c
    model/payment_gateway_create.c
    model/payment_gateway_update.c
    model/payment_method.c
    model/payment_status.c
    model/payroll_autopay_payload.c
    model/payroll_create_payload.c
    model/payroll_entry_api.c
    model/payroll_month.c
    model/payroll_pay_payload.c
    model/payroll_run_api.c
    model/payroll_run_status.c
    model/payroll_summary.c
    model/payroll_summary_item.c
    model/peppol_response.c
    model/plan.c
    model/plan_features.c
    model/plan_limits.c
    model/platform_info.c
    model/plausibility_check.c
    model/plausibility_report.c
    model/plausibility_summary.c
    model/plugin_error.c
    model/plugin_error_one_of.c
    model/plugin_error_one_of_1.c
    model/plugin_error_one_of_2.c
    model/plugin_error_one_of_3.c
    model/plugin_error_one_of_4.c
    model/plugin_error_one_of_5.c
    model/plugin_error_one_of_6.c
    model/plugin_pricing.c
    model/plugin_pricing_one_of.c
    model/plugin_pricing_one_of_1.c
    model/plugin_pricing_one_of_2.c
    model/pn_l_item.c
    model/pos_register.c
    model/pos_register_create.c
    model/pos_register_status.c
    model/pos_table.c
    model/pos_table_create.c
    model/pos_table_status.c
    model/posting_category.c
    model/posting_category_create.c
    model/posting_category_type.c
    model/posting_category_update.c
    model/preceding_sales_voucher_type.c
    model/price_tier.c
    model/price_tier_create.c
    model/price_tier_update.c
    model/print_delivery_note_response.c
    model/print_label_response.c
    model/product.c
    model/product_attribute.c
    model/product_attribute_create.c
    model/product_attribute_update.c
    model/product_category.c
    model/product_category_create.c
    model/product_category_update.c
    model/product_create.c
    model/product_stock.c
    model/product_update.c
    model/product_variant.c
    model/product_variant_create.c
    model/product_variant_update.c
    model/production_order.c
    model/production_order_costing.c
    model/production_order_status.c
    model/production_order_status_update.c
    model/proforma_invoice.c
    model/proforma_invoice_create.c
    model/proforma_invoice_status.c
    model/proforma_invoice_update.c
    model/proposed_assignment.c
    model/provider_info.c
    model/public_delivery_appointment_request.c
    model/public_delivery_appointment_response.c
    model/public_delivery_appointment_status_response.c
    model/public_posting.c
    model/public_return_item.c
    model/public_return_request.c
    model/public_return_response.c
    model/public_return_status_response.c
    model/purchase_order.c
    model/purchase_order_create.c
    model/purchase_order_status.c
    model/purchase_order_status_update.c
    model/purchase_order_update.c
    model/qr_code_response.c
    model/quartile_band.c
    model/quiz_question.c
    model/quota_override.c
    model/quota_override_features.c
    model/quota_overview.c
    model/quotation.c
    model/quotation_create.c
    model/rate_request.c
    model/rate_response.c
    model/recurring_template.c
    model/recurring_template_create.c
    model/recurring_template_type.c
    model/recurring_template_update.c
    model/reference_type.c
    model/register_request.c
    model/reminder_level.c
    model/remove_user_request.c
    model/reorder_proposal_line.c
    model/reorder_proposal_response.c
    model/replenishment_response.c
    model/replenishment_suggestion_line.c
    model/reset_password_request.c
    model/resolved_price_response.c
    model/return_logistics_queue_item.c
    model/return_logistics_summary.c
    model/return_order.c
    model/return_order_status.c
    model/return_order_status_update.c
    model/return_warehouse_summary.c
    model/revenue_item.c
    model/rfq.c
    model/rfq_create.c
    model/rfq_status.c
    model/rfq_status_update.c
    model/rfq_update.c
    model/sales_volume_item.c
    model/sales_volume_report.c
    model/scope_total.c
    model/section.c
    model/send_message_dto.c
    model/sepa_direct_debit_response.c
    model/sepa_sequence_type.c
    model/service_assignment.c
    model/service_assignment_create.c
    model/service_assignment_status.c
    model/service_assignment_update.c
    model/service_job.c
    model/service_job_create.c
    model/service_job_status.c
    model/service_job_update.c
    model/severity.c
    model/shareholder.c
    model/shareholder_create.c
    model/shareholder_update.c
    model/shipment.c
    model/shipment_status_update.c
    model/shipping_credentials.c
    model/shipping_rate.c
    model/shipping_rule.c
    model/shipping_rule_create.c
    model/shipping_rule_update.c
    model/shipping_threshold.c
    model/shipping_threshold_create.c
    model/shipping_threshold_update.c
    model/silent_partner.c
    model/silent_partner_create.c
    model/silent_partner_update.c
    model/smtp_config.c
    model/smtp_encryption.c
    model/stille_export_response.c
    model/stille_partner_zeile.c
    model/stille_report.c
    model/stock_adjustment.c
    model/stock_movement.c
    model/stock_transfer.c
    model/stock_transfer_status.c
    model/stock_transfer_status_update.c
    model/stock_update_request.c
    model/submit_result_dto.c
    model/submit_result_response.c
    model/subscription_overview.c
    model/suitability_request.c
    model/suitability_result.c
    model/supplier_condition.c
    model/supplier_condition_create.c
    model/supplier_condition_update.c
    model/supplier_invoice.c
    model/supplier_invoice_create.c
    model/supplier_invoice_status.c
    model/supplier_invoice_status_update.c
    model/supplier_invoice_update.c
    model/support_channel.c
    model/support_channel_type.c
    model/support_ticket.c
    model/support_ticket_status.c
    model/support_ticket_update.c
    model/sync_log.c
    model/sync_log_status.c
    model/sync_status.c
    model/sync_summary.c
    model/sync_type.c
    model/target_progress.c
    model/tax_rate_create.c
    model/team.c
    model/team_create.c
    model/tenant_settings.c
    model/tenant_user.c
    model/ticket_message.c
    model/ticket_priority.c
    model/time_entry_clock_in.c
    model/time_entry_clock_out.c
    model/time_entry_dto.c
    model/timeline_event.c
    model/totp_enable_request.c
    model/totp_setup_response.c
    model/track_order_request.c
    model/track_order_response.c
    model/tracked_shipment.c
    model/tracking_event.c
    model/tracking_info.c
    model/training_assignment.c
    model/training_assignment_create.c
    model/training_assignment_update.c
    model/training_content.c
    model/training_source.c
    model/umsatzsteuer_report.c
    model/update_automation.c
    model/update_channel_dto.c
    model/update_connection_request.c
    model/update_permissions_payload.c
    model/update_profile_request.c
    model/update_role_payload.c
    model/update_subscription_request.c
    model/update_sync_direction_request.c
    model/update_tenant_settings.c
    model/ups_credentials.c
    model/usage_snapshot.c
    model/user_profile.c
    model/user_tenant_info.c
    model/ustva_ergebnis.c
    model/vat_detail.c
    model/vat_item.c
    model/vat_summary.c
    model/verfahrensdokumentation.c
    model/verify_email_request.c
    model/voucher.c
    model/voucher_create.c
    model/voucher_status.c
    model/voucher_type.c
    model/warehouse.c
    model/warehouse_create.c
    model/warehouse_stock.c
    model/warehouse_update.c
    model/webhook_direction.c
    model/webhook_event.c
    model/webhook_event_status.c
    model/webhook_subscription.c
    model/workflow.c
    model/workflow_action.c
    model/workflow_enabled_update.c
    model/x_rechnung_response.c
    model/year_total.c
    model/yearly_payroll_summary.c
    api/AbsenceAPI.c
    api/ActivityAPI.c
    api/AdminAPI.c
    api/AiAPI.c
    api/AnlageEksAPI.c
    api/AnlageGAPI.c
    api/AnlageSAPI.c
    api/AttachmentAPI.c
    api/AttachmentVersionAPI.c
    api/AuthAPI.c
    api/AutomationsAPI.c
    api/BankingAPI.c
    api/BillingAPI.c
    api/BomAPI.c
    api/BookkeepingAPI.c
    api/BudgetsAPI.c
    api/ComplianceTrainingAPI.c
    api/ContactAPI.c
    api/CouponAPI.c
    api/CreateSepaDirectDebitAPI.c
    api/CreditNoteAPI.c
    api/CustomerAPI.c
    api/CustomerCommunicationAPI.c
    api/CustomerGroupAPI.c
    api/DatevAPI.c
    api/DatevImportAPI.c
    api/DeclarationAPI.c
    api/DeliveryAppointmentAPI.c
    api/DeliveryDateAPI.c
    api/DeliveryNoteAPI.c
    api/DownPaymentInvoiceAPI.c
    api/EbilanzAPI.c
    api/EmailTemplateAPI.c
    api/EmissionsAPI.c
    api/EmployeeAPI.c
    api/EuerAPI.c
    api/EventSubscriptionAPI.c
    api/FristenAPI.c
    api/GdprAPI.c
    api/GenerateQrcodeAPI.c
    api/GenerateXrechnungAPI.c
    api/GewerbesteuerAPI.c
    api/GewinnverwendungAPI.c
    api/GezAPI.c
    api/GobdExportAPI.c
    api/GoodsReceiptAPI.c
    api/GroupFigureAPI.c
    api/ImportRunnerAPI.c
    api/InstituteAPI.c
    api/InstituteProfileAPI.c
    api/InventoryCountAPI.c
    api/InventoryValueAPI.c
    api/InvoiceAPI.c
    api/JobApplicationAPI.c
    api/JobPostingAPI.c
    api/KonzernAPI.c
    api/KostenVorschauAPI.c
    api/KstAPI.c
    api/KycRecordAPI.c
    api/LeadAPI.c
    api/LegalDocumentAPI.c
    api/ListOpenItemsAPI.c
    api/MarketplaceApiAPI.c
    api/NotificationsAPI.c
    api/OffenlegungAPI.c
    api/OnlineshopAPI.c
    api/OrderAPI.c
    api/OrderConfirmationAPI.c
    api/OssReportAPI.c
    api/PackingAPI.c
    api/ParticipationAPI.c
    api/PaygapAPI.c
    api/PaymentAPI.c
    api/PaymentConditionAPI.c
    api/PaymentGatewayAPI.c
    api/PayrollAPI.c
    api/PeppolAPI.c
    api/PlausibilityAPI.c
    api/PosAPI.c
    api/PostingCategoryAPI.c
    api/PriceTierAPI.c
    api/ProductAPI.c
    api/ProductAttributeAPI.c
    api/ProductCategoryAPI.c
    api/ProductVariantAPI.c
    api/ProductionOrderAPI.c
    api/ProformaInvoiceAPI.c
    api/ProposeAssignmentsAPI.c
    api/PublicReturnsAPI.c
    api/PurchaseOrderAPI.c
    api/QuotationAPI.c
    api/RecurringTemplateAPI.c
    api/ReorderProposalAPI.c
    api/ReplenishmentAPI.c
    api/ReportsAPI.c
    api/ReturnOrderAPI.c
    api/RfqAPI.c
    api/SearchAPI.c
    api/ServiceAssignmentAPI.c
    api/ServiceJobAPI.c
    api/ShareholderAPI.c
    api/ShipmentAPI.c
    api/ShippingAPI.c
    api/ShippingRuleAPI.c
    api/ShippingThresholdAPI.c
    api/ShopAPI.c
    api/SilentPartnerAPI.c
    api/StilleAPI.c
    api/StockMovementAPI.c
    api/StockTransferAPI.c
    api/SuitabilityAPI.c
    api/SupplierConditionAPI.c
    api/SupplierInvoiceAPI.c
    api/SupportChannelAPI.c
    api/SupportTicketAPI.c
    api/TaxAPI.c
    api/TenantSettingsAPI.c
    api/TicketMessageAPI.c
    api/TimeEntriesAPI.c
    api/TrainingAssignmentAPI.c
    api/TrainingsAPI.c
    api/UserAPI.c
    api/UserManagementAPI.c
    api/UstvaAPI.c
    api/VoucherAPI.c
    api/WarehouseAPI.c
    api/WarehouseStockAPI.c
    api/WebhooksAPI.c
    api/WorkflowsAPI.c
    api/ZugferdAPI.c

)

set(HDRS
    include/apiClient.h
    include/list.h
    include/binary.h
    include/keyValuePair.h
    external/cJSON.h
    model/object.h
    model/any_type.h
    model/absence.h
    model/absence_create.h
    model/absence_status.h
    model/absence_type.h
    model/absence_update.h
    model/accept_invite_request.h
    model/account_overview.h
    model/activity.h
    model/activity_create.h
    model/activity_status.h
    model/activity_status_update.h
    model/activity_type.h
    model/activity_update.h
    model/address.h
    model/ai_config_dto.h
    model/ai_suggestion.h
    model/ai_suggestion_request.h
    model/ai_worker_config.h
    model/allocate_payment_request.h
    model/anlage_g_ergebnis.h
    model/anlage_g_kfz_hinweis.h
    model/anlage_s_ergebnis.h
    model/anlage_s_kfz_hinweis.h
    model/api_response_gdpr_export.h
    model/api_response_gdpr_export_data.h
    model/api_response_string.h
    model/api_response_subscription_overview.h
    model/api_response_subscription_overview_data.h
    model/api_response_team.h
    model/api_response_team_data.h
    model/api_response_user_profile.h
    model/api_response_user_profile_data.h
    model/api_response_vec_plan.h
    model/api_response_vec_plan_data_inner.h
    model/api_response_vec_team.h
    model/api_response_vec_user_tenant_info.h
    model/api_response_vec_user_tenant_info_data_inner.h
    model/application_filter.h
    model/application_status.h
    model/application_status_dto.h
    model/appointment_status_update.h
    model/assignment_status.h
    model/attachment.h
    model/attachment_create.h
    model/attachment_version.h
    model/auth_response.h
    model/automation.h
    model/automation_dto.h
    model/balance_item.h
    model/balance_sheet.h
    model/bank_lookup.h
    model/betriebsstaette.h
    model/betriebsstaetten_detail.h
    model/bilanz_item.h
    model/bilanz_report.h
    model/bom.h
    model/bom_create.h
    model/bom_status.h
    model/bom_update.h
    model/box_fit.h
    model/budget.h
    model/budget_ergebnis.h
    model/budget_goal_request.h
    model/budget_kategorie.h
    model/bwa_expenses.h
    model/bwa_report.h
    model/bwa_revenue.h
    model/bwa_summary.h
    model/cart_item_input.h
    model/cashflow_report.h
    model/category_total.h
    model/change_password_request.h
    model/changelog_entry.h
    model/check_status.h
    model/communication_channel.h
    model/communication_direction.h
    model/company_type.h
    model/compliance_entry.h
    model/compliance_training.h
    model/compliance_training_create.h
    model/compliance_training_update.h
    model/config_field_info.h
    model/config_field_kind.h
    model/config_field_kind_one_of.h
    model/config_field_kind_one_of_1.h
    model/config_field_kind_one_of_2.h
    model/config_field_kind_one_of_3.h
    model/config_field_kind_one_of_4.h
    model/connector_type.h
    model/contact.h
    model/contact_create.h
    model/contact_history_response.h
    model/contact_info.h
    model/contact_timeline_response.h
    model/contact_type.h
    model/contact_update.h
    model/convert_response.h
    model/costing_line.h
    model/country_code.h
    model/coupon.h
    model/coupon_create.h
    model/coupon_update.h
    model/coupon_validation.h
    model/create_channel_dto.h
    model/create_connection_request.h
    model/create_emission_entry.h
    model/create_emission_target.h
    model/create_shipment_request.h
    model/create_subscription_request.h
    model/create_ticket_request.h
    model/currency_code.h
    model/current_inventory_value.h
    model/customer.h
    model/customer_communication.h
    model/customer_communication_create.h
    model/customer_communication_update.h
    model/customer_create.h
    model/customer_group.h
    model/customer_group_create.h
    model/customer_group_update.h
    model/customer_info.h
    model/customer_update.h
    model/data_quality.h
    model/datev_booking_preview.h
    model/datev_export_response.h
    model/datev_import_response.h
    model/datev_import_row.h
    model/declaration.h
    model/declaration_create.h
    model/declaration_type.h
    model/declaration_update.h
    model/deliverable_response.h
    model/delivery_appointment.h
    model/delivery_appointment_create.h
    model/delivery_appointment_status.h
    model/delivery_date.h
    model/delivery_date_create.h
    model/delivery_date_status.h
    model/delivery_date_status_update.h
    model/delivery_date_update.h
    model/delivery_note.h
    model/delivery_note_create.h
    model/dhl_credentials.h
    model/discount_type.h
    model/document_type.h
    model/down_payment_invoice.h
    model/dpa_accept_request.h
    model/dpa_status.h
    model/dunning_result.h
    model/e_bilanz_report.h
    model/eks_ergebnis.h
    model/eks_monats_wert.h
    model/elster_status.h
    model/email_template.h
    model/email_template_create.h
    model/email_template_status.h
    model/email_template_update.h
    model/emission_entry.h
    model/emission_factor_response.h
    model/emission_method.h
    model/emission_target.h
    model/emission_target_scope.h
    model/emissions_export_response.h
    model/emissions_report.h
    model/emit_event_request.h
    model/employee.h
    model/employee_create.h
    model/employee_status.h
    model/employee_update.h
    model/employment_type.h
    model/euer_detail_ergebnis.h
    model/euer_ergebnis.h
    model/euer_kat_summe.h
    model/euer_zeile.h
    model/euer_zeile_detail.h
    model/event_subscription.h
    model/execution_status.h
    model/expense_item.h
    model/extra_payment.h
    model/feature_settings.h
    model/forgot_password_request.h
    model/frist_eintrag.h
    model/fristen_ergebnis.h
    model/gateway_o_auth_authorize_request.h
    model/gateway_o_auth_authorize_response.h
    model/gateway_o_auth_callback_request.h
    model/gateway_type.h
    model/gdpr_activity.h
    model/gdpr_api_key.h
    model/gdpr_billing_info.h
    model/gdpr_export.h
    model/gdpr_notification.h
    model/gdpr_refresh_token.h
    model/gdpr_tenant.h
    model/gdpr_usage_event.h
    model/gdpr_user.h
    model/gender.h
    model/generate_count_request.h
    model/generate_variants_request.h
    model/gewerbesteuer_ergebnis.h
    model/gewinnverwendungs_export_response.h
    model/gewinnverwendungs_report.h
    model/gewinnverwendungs_zeile.h
    model/gez_report.h
    model/ghg_scope.h
    model/go_bd_export_response.h
    model/goods_receipt.h
    model/group_figure.h
    model/group_figure_create.h
    model/group_figure_update.h
    model/gu_v_item.h
    model/gu_v_report.h
    model/hebesatz_lookup.h
    model/hr_training_overview.h
    model/import_job_status.h
    model/import_start_request.h
    model/import_start_response.h
    model/import_test_request.h
    model/import_test_response.h
    model/income_statement.h
    model/institute_check_item.h
    model/institute_deadlines.h
    model/institute_profile.h
    model/institute_profile_update.h
    model/institute_status.h
    model/institute_type.h
    model/instrument_type.h
    model/inventory_count.h
    model/inventory_count_create.h
    model/inventory_count_status.h
    model/inventory_count_status_update.h
    model/inventory_count_update.h
    model/inventory_value_point.h
    model/invite_request.h
    model/invoice.h
    model/invoice_create.h
    model/invoice_line_item.h
    model/invoice_match_request.h
    model/invoice_pdf_url_response.h
    model/invoice_status.h
    model/invoice_type.h
    model/jahres_ust_ergebnis.h
    model/job.h
    model/job_application.h
    model/job_posting.h
    model/job_posting_create.h
    model/job_posting_filter.h
    model/job_posting_status.h
    model/job_posting_update.h
    model/job_status.h
    model/job_title_gap.h
    model/konto_item.h
    model/konto_report.h
    model/konzern_beteiligung.h
    model/konzern_export_response.h
    model/konzern_status.h
    model/konzern_thresholds.h
    model/kosten_eintrag.h
    model/kosten_vorschau.h
    model/kst_ergebnis.h
    model/kyc_record.h
    model/kyc_record_create.h
    model/kyc_record_update.h
    model/labor_cost_row.h
    model/language_code.h
    model/lead.h
    model/lead_status.h
    model/lead_update.h
    model/legal_doc_type.h
    model/legal_document.h
    model/legal_document_reset.h
    model/legal_document_upsert.h
    model/liquidity_position.h
    model/login_request.h
    model/magic_link_request.h
    model/magic_link_verify_request.h
    model/marketplace_connection.h
    model/marketplace_sync_log.h
    model/marketplace_webhook_event.h
    model/message_direction.h
    model/message_type.h
    model/metered_usage.h
    model/method_suitability.h
    model/mirror_trigger_response.h
    model/model.h
    model/movement_type.h
    model/my_training_item.h
    model/new_version_request.h
    model/notification_dto.h
    model/o_auth_authorize_request.h
    model/o_auth_authorize_response.h
    model/o_auth_callback_request.h
    model/ocr_text_request.h
    model/offenlegung_item.h
    model/offenlegung_report.h
    model/open_item.h
    model/order.h
    model/order_confirmation.h
    model/order_confirmation_create.h
    model/order_create.h
    model/order_state_update.h
    model/order_status.h
    model/order_tags_request.h
    model/order_update.h
    model/oss_dependency.h
    model/oss_report.h
    model/package.h
    model/packing_complete_request.h
    model/packing_complete_response.h
    model/packing_queue.h
    model/packing_queue_item.h
    model/packing_video_response.h
    model/partial_feature_settings.h
    model/participation.h
    model/participation_create.h
    model/participation_update.h
    model/pay_gap_export_response.h
    model/pay_gap_info_response.h
    model/pay_gap_report.h
    model/payment.h
    model/payment_condition.h
    model/payment_create.h
    model/payment_gateway.h
    model/payment_gateway_create.h
    model/payment_gateway_update.h
    model/payment_method.h
    model/payment_status.h
    model/payroll_autopay_payload.h
    model/payroll_create_payload.h
    model/payroll_entry_api.h
    model/payroll_month.h
    model/payroll_pay_payload.h
    model/payroll_run_api.h
    model/payroll_run_status.h
    model/payroll_summary.h
    model/payroll_summary_item.h
    model/peppol_response.h
    model/plan.h
    model/plan_features.h
    model/plan_limits.h
    model/platform_info.h
    model/plausibility_check.h
    model/plausibility_report.h
    model/plausibility_summary.h
    model/plugin_error.h
    model/plugin_error_one_of.h
    model/plugin_error_one_of_1.h
    model/plugin_error_one_of_2.h
    model/plugin_error_one_of_3.h
    model/plugin_error_one_of_4.h
    model/plugin_error_one_of_5.h
    model/plugin_error_one_of_6.h
    model/plugin_pricing.h
    model/plugin_pricing_one_of.h
    model/plugin_pricing_one_of_1.h
    model/plugin_pricing_one_of_2.h
    model/pn_l_item.h
    model/pos_register.h
    model/pos_register_create.h
    model/pos_register_status.h
    model/pos_table.h
    model/pos_table_create.h
    model/pos_table_status.h
    model/posting_category.h
    model/posting_category_create.h
    model/posting_category_type.h
    model/posting_category_update.h
    model/preceding_sales_voucher_type.h
    model/price_tier.h
    model/price_tier_create.h
    model/price_tier_update.h
    model/print_delivery_note_response.h
    model/print_label_response.h
    model/product.h
    model/product_attribute.h
    model/product_attribute_create.h
    model/product_attribute_update.h
    model/product_category.h
    model/product_category_create.h
    model/product_category_update.h
    model/product_create.h
    model/product_stock.h
    model/product_update.h
    model/product_variant.h
    model/product_variant_create.h
    model/product_variant_update.h
    model/production_order.h
    model/production_order_costing.h
    model/production_order_status.h
    model/production_order_status_update.h
    model/proforma_invoice.h
    model/proforma_invoice_create.h
    model/proforma_invoice_status.h
    model/proforma_invoice_update.h
    model/proposed_assignment.h
    model/provider_info.h
    model/public_delivery_appointment_request.h
    model/public_delivery_appointment_response.h
    model/public_delivery_appointment_status_response.h
    model/public_posting.h
    model/public_return_item.h
    model/public_return_request.h
    model/public_return_response.h
    model/public_return_status_response.h
    model/purchase_order.h
    model/purchase_order_create.h
    model/purchase_order_status.h
    model/purchase_order_status_update.h
    model/purchase_order_update.h
    model/qr_code_response.h
    model/quartile_band.h
    model/quiz_question.h
    model/quota_override.h
    model/quota_override_features.h
    model/quota_overview.h
    model/quotation.h
    model/quotation_create.h
    model/rate_request.h
    model/rate_response.h
    model/recurring_template.h
    model/recurring_template_create.h
    model/recurring_template_type.h
    model/recurring_template_update.h
    model/reference_type.h
    model/register_request.h
    model/reminder_level.h
    model/remove_user_request.h
    model/reorder_proposal_line.h
    model/reorder_proposal_response.h
    model/replenishment_response.h
    model/replenishment_suggestion_line.h
    model/reset_password_request.h
    model/resolved_price_response.h
    model/return_logistics_queue_item.h
    model/return_logistics_summary.h
    model/return_order.h
    model/return_order_status.h
    model/return_order_status_update.h
    model/return_warehouse_summary.h
    model/revenue_item.h
    model/rfq.h
    model/rfq_create.h
    model/rfq_status.h
    model/rfq_status_update.h
    model/rfq_update.h
    model/sales_volume_item.h
    model/sales_volume_report.h
    model/scope_total.h
    model/section.h
    model/send_message_dto.h
    model/sepa_direct_debit_response.h
    model/sepa_sequence_type.h
    model/service_assignment.h
    model/service_assignment_create.h
    model/service_assignment_status.h
    model/service_assignment_update.h
    model/service_job.h
    model/service_job_create.h
    model/service_job_status.h
    model/service_job_update.h
    model/severity.h
    model/shareholder.h
    model/shareholder_create.h
    model/shareholder_update.h
    model/shipment.h
    model/shipment_status_update.h
    model/shipping_credentials.h
    model/shipping_rate.h
    model/shipping_rule.h
    model/shipping_rule_create.h
    model/shipping_rule_update.h
    model/shipping_threshold.h
    model/shipping_threshold_create.h
    model/shipping_threshold_update.h
    model/silent_partner.h
    model/silent_partner_create.h
    model/silent_partner_update.h
    model/smtp_config.h
    model/smtp_encryption.h
    model/stille_export_response.h
    model/stille_partner_zeile.h
    model/stille_report.h
    model/stock_adjustment.h
    model/stock_movement.h
    model/stock_transfer.h
    model/stock_transfer_status.h
    model/stock_transfer_status_update.h
    model/stock_update_request.h
    model/submit_result_dto.h
    model/submit_result_response.h
    model/subscription_overview.h
    model/suitability_request.h
    model/suitability_result.h
    model/supplier_condition.h
    model/supplier_condition_create.h
    model/supplier_condition_update.h
    model/supplier_invoice.h
    model/supplier_invoice_create.h
    model/supplier_invoice_status.h
    model/supplier_invoice_status_update.h
    model/supplier_invoice_update.h
    model/support_channel.h
    model/support_channel_type.h
    model/support_ticket.h
    model/support_ticket_status.h
    model/support_ticket_update.h
    model/sync_log.h
    model/sync_log_status.h
    model/sync_status.h
    model/sync_summary.h
    model/sync_type.h
    model/target_progress.h
    model/tax_rate_create.h
    model/team.h
    model/team_create.h
    model/tenant_settings.h
    model/tenant_user.h
    model/ticket_message.h
    model/ticket_priority.h
    model/time_entry_clock_in.h
    model/time_entry_clock_out.h
    model/time_entry_dto.h
    model/timeline_event.h
    model/totp_enable_request.h
    model/totp_setup_response.h
    model/track_order_request.h
    model/track_order_response.h
    model/tracked_shipment.h
    model/tracking_event.h
    model/tracking_info.h
    model/training_assignment.h
    model/training_assignment_create.h
    model/training_assignment_update.h
    model/training_content.h
    model/training_source.h
    model/umsatzsteuer_report.h
    model/update_automation.h
    model/update_channel_dto.h
    model/update_connection_request.h
    model/update_permissions_payload.h
    model/update_profile_request.h
    model/update_role_payload.h
    model/update_subscription_request.h
    model/update_sync_direction_request.h
    model/update_tenant_settings.h
    model/ups_credentials.h
    model/usage_snapshot.h
    model/user_profile.h
    model/user_tenant_info.h
    model/ustva_ergebnis.h
    model/vat_detail.h
    model/vat_item.h
    model/vat_summary.h
    model/verfahrensdokumentation.h
    model/verify_email_request.h
    model/voucher.h
    model/voucher_create.h
    model/voucher_status.h
    model/voucher_type.h
    model/warehouse.h
    model/warehouse_create.h
    model/warehouse_stock.h
    model/warehouse_update.h
    model/webhook_direction.h
    model/webhook_event.h
    model/webhook_event_status.h
    model/webhook_subscription.h
    model/workflow.h
    model/workflow_action.h
    model/workflow_enabled_update.h
    model/x_rechnung_response.h
    model/year_total.h
    model/yearly_payroll_summary.h
    api/AbsenceAPI.h
    api/ActivityAPI.h
    api/AdminAPI.h
    api/AiAPI.h
    api/AnlageEksAPI.h
    api/AnlageGAPI.h
    api/AnlageSAPI.h
    api/AttachmentAPI.h
    api/AttachmentVersionAPI.h
    api/AuthAPI.h
    api/AutomationsAPI.h
    api/BankingAPI.h
    api/BillingAPI.h
    api/BomAPI.h
    api/BookkeepingAPI.h
    api/BudgetsAPI.h
    api/ComplianceTrainingAPI.h
    api/ContactAPI.h
    api/CouponAPI.h
    api/CreateSepaDirectDebitAPI.h
    api/CreditNoteAPI.h
    api/CustomerAPI.h
    api/CustomerCommunicationAPI.h
    api/CustomerGroupAPI.h
    api/DatevAPI.h
    api/DatevImportAPI.h
    api/DeclarationAPI.h
    api/DeliveryAppointmentAPI.h
    api/DeliveryDateAPI.h
    api/DeliveryNoteAPI.h
    api/DownPaymentInvoiceAPI.h
    api/EbilanzAPI.h
    api/EmailTemplateAPI.h
    api/EmissionsAPI.h
    api/EmployeeAPI.h
    api/EuerAPI.h
    api/EventSubscriptionAPI.h
    api/FristenAPI.h
    api/GdprAPI.h
    api/GenerateQrcodeAPI.h
    api/GenerateXrechnungAPI.h
    api/GewerbesteuerAPI.h
    api/GewinnverwendungAPI.h
    api/GezAPI.h
    api/GobdExportAPI.h
    api/GoodsReceiptAPI.h
    api/GroupFigureAPI.h
    api/ImportRunnerAPI.h
    api/InstituteAPI.h
    api/InstituteProfileAPI.h
    api/InventoryCountAPI.h
    api/InventoryValueAPI.h
    api/InvoiceAPI.h
    api/JobApplicationAPI.h
    api/JobPostingAPI.h
    api/KonzernAPI.h
    api/KostenVorschauAPI.h
    api/KstAPI.h
    api/KycRecordAPI.h
    api/LeadAPI.h
    api/LegalDocumentAPI.h
    api/ListOpenItemsAPI.h
    api/MarketplaceApiAPI.h
    api/NotificationsAPI.h
    api/OffenlegungAPI.h
    api/OnlineshopAPI.h
    api/OrderAPI.h
    api/OrderConfirmationAPI.h
    api/OssReportAPI.h
    api/PackingAPI.h
    api/ParticipationAPI.h
    api/PaygapAPI.h
    api/PaymentAPI.h
    api/PaymentConditionAPI.h
    api/PaymentGatewayAPI.h
    api/PayrollAPI.h
    api/PeppolAPI.h
    api/PlausibilityAPI.h
    api/PosAPI.h
    api/PostingCategoryAPI.h
    api/PriceTierAPI.h
    api/ProductAPI.h
    api/ProductAttributeAPI.h
    api/ProductCategoryAPI.h
    api/ProductVariantAPI.h
    api/ProductionOrderAPI.h
    api/ProformaInvoiceAPI.h
    api/ProposeAssignmentsAPI.h
    api/PublicReturnsAPI.h
    api/PurchaseOrderAPI.h
    api/QuotationAPI.h
    api/RecurringTemplateAPI.h
    api/ReorderProposalAPI.h
    api/ReplenishmentAPI.h
    api/ReportsAPI.h
    api/ReturnOrderAPI.h
    api/RfqAPI.h
    api/SearchAPI.h
    api/ServiceAssignmentAPI.h
    api/ServiceJobAPI.h
    api/ShareholderAPI.h
    api/ShipmentAPI.h
    api/ShippingAPI.h
    api/ShippingRuleAPI.h
    api/ShippingThresholdAPI.h
    api/ShopAPI.h
    api/SilentPartnerAPI.h
    api/StilleAPI.h
    api/StockMovementAPI.h
    api/StockTransferAPI.h
    api/SuitabilityAPI.h
    api/SupplierConditionAPI.h
    api/SupplierInvoiceAPI.h
    api/SupportChannelAPI.h
    api/SupportTicketAPI.h
    api/TaxAPI.h
    api/TenantSettingsAPI.h
    api/TicketMessageAPI.h
    api/TimeEntriesAPI.h
    api/TrainingAssignmentAPI.h
    api/TrainingsAPI.h
    api/UserAPI.h
    api/UserManagementAPI.h
    api/UstvaAPI.h
    api/VoucherAPI.h
    api/WarehouseAPI.h
    api/WarehouseStockAPI.h
    api/WebhooksAPI.h
    api/WorkflowsAPI.h
    api/ZugferdAPI.h

)

include(PreTarget.cmake OPTIONAL)

set(PROJECT_VERSION_STRING "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

# Add library with project file with project name as library name
if(NOT BUILD_STATIC_LIBS)
  add_library(${pkgName} ${SRCS} ${HDRS})
else()
  add_library(${pkgName} STATIC ${SRCS} ${HDRS})
endif()
# Link dependent libraries
if(NOT CMAKE_VERSION VERSION_LESS 3.4)
    target_link_libraries(${pkgName} PRIVATE OpenSSL::SSL OpenSSL::Crypto)
endif()
target_link_libraries(${pkgName} PUBLIC ${CURL_LIBRARIES} )
target_include_directories(
    ${pkgName} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

include(PostTarget.cmake OPTIONAL)

# installation of libraries, headers, and config files
if (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in)
    install(TARGETS ${pkgName} DESTINATION lib)
else()
    include(GNUInstallDirs)
    install(TARGETS ${pkgName} DESTINATION lib EXPORT ${pkgName}Targets)

    foreach(HDR_FILE ${HDRS})
        get_filename_component(HDR_DIRECTORY ${HDR_FILE} DIRECTORY)
        get_filename_component(ABSOLUTE_HDR_DIRECTORY ${HDR_DIRECTORY} ABSOLUTE)
        file(RELATIVE_PATH RELATIVE_HDR_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${ABSOLUTE_HDR_DIRECTORY})
        install(FILES ${HDR_FILE} DESTINATION include/${pkgName}/${RELATIVE_HDR_PATH})
    endforeach()

    include(CMakePackageConfigHelpers)
    write_basic_package_version_file(
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}ConfigVersion.cmake"
            VERSION "${PROJECT_VERSION_STRING}"
            COMPATIBILITY AnyNewerVersion
    )

    export(EXPORT ${pkgName}Targets
            FILE "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}Targets.cmake"
            NAMESPACE ${pkgName}::
            )

    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}Config.cmake"
            @ONLY
            )

    set(ConfigPackageLocation lib/cmake/${pkgName})
    install(EXPORT ${pkgName}Targets
            FILE
            ${pkgName}Targets.cmake
            NAMESPACE
            ${pkgName}::
            DESTINATION
            ${ConfigPackageLocation}
            )
    install(
            FILES
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}Config.cmake"
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}ConfigVersion.cmake"
            DESTINATION
            ${ConfigPackageLocation}
    )
endif()

# make installation packages
include(Packing.cmake OPTIONAL)

# Setting file variables to null
set(SRCS "")
set(HDRS "")


## This section shows how to use the above compiled library to compile the source files
## set source files
#set(SRCS
#    unit-tests/manual-AbsenceAPI.c
#    unit-tests/manual-ActivityAPI.c
#    unit-tests/manual-AdminAPI.c
#    unit-tests/manual-AiAPI.c
#    unit-tests/manual-AnlageEksAPI.c
#    unit-tests/manual-AnlageGAPI.c
#    unit-tests/manual-AnlageSAPI.c
#    unit-tests/manual-AttachmentAPI.c
#    unit-tests/manual-AttachmentVersionAPI.c
#    unit-tests/manual-AuthAPI.c
#    unit-tests/manual-AutomationsAPI.c
#    unit-tests/manual-BankingAPI.c
#    unit-tests/manual-BillingAPI.c
#    unit-tests/manual-BomAPI.c
#    unit-tests/manual-BookkeepingAPI.c
#    unit-tests/manual-BudgetsAPI.c
#    unit-tests/manual-ComplianceTrainingAPI.c
#    unit-tests/manual-ContactAPI.c
#    unit-tests/manual-CouponAPI.c
#    unit-tests/manual-CreateSepaDirectDebitAPI.c
#    unit-tests/manual-CreditNoteAPI.c
#    unit-tests/manual-CustomerAPI.c
#    unit-tests/manual-CustomerCommunicationAPI.c
#    unit-tests/manual-CustomerGroupAPI.c
#    unit-tests/manual-DatevAPI.c
#    unit-tests/manual-DatevImportAPI.c
#    unit-tests/manual-DeclarationAPI.c
#    unit-tests/manual-DeliveryAppointmentAPI.c
#    unit-tests/manual-DeliveryDateAPI.c
#    unit-tests/manual-DeliveryNoteAPI.c
#    unit-tests/manual-DownPaymentInvoiceAPI.c
#    unit-tests/manual-EbilanzAPI.c
#    unit-tests/manual-EmailTemplateAPI.c
#    unit-tests/manual-EmissionsAPI.c
#    unit-tests/manual-EmployeeAPI.c
#    unit-tests/manual-EuerAPI.c
#    unit-tests/manual-EventSubscriptionAPI.c
#    unit-tests/manual-FristenAPI.c
#    unit-tests/manual-GdprAPI.c
#    unit-tests/manual-GenerateQrcodeAPI.c
#    unit-tests/manual-GenerateXrechnungAPI.c
#    unit-tests/manual-GewerbesteuerAPI.c
#    unit-tests/manual-GewinnverwendungAPI.c
#    unit-tests/manual-GezAPI.c
#    unit-tests/manual-GobdExportAPI.c
#    unit-tests/manual-GoodsReceiptAPI.c
#    unit-tests/manual-GroupFigureAPI.c
#    unit-tests/manual-ImportRunnerAPI.c
#    unit-tests/manual-InstituteAPI.c
#    unit-tests/manual-InstituteProfileAPI.c
#    unit-tests/manual-InventoryCountAPI.c
#    unit-tests/manual-InventoryValueAPI.c
#    unit-tests/manual-InvoiceAPI.c
#    unit-tests/manual-JobApplicationAPI.c
#    unit-tests/manual-JobPostingAPI.c
#    unit-tests/manual-KonzernAPI.c
#    unit-tests/manual-KostenVorschauAPI.c
#    unit-tests/manual-KstAPI.c
#    unit-tests/manual-KycRecordAPI.c
#    unit-tests/manual-LeadAPI.c
#    unit-tests/manual-LegalDocumentAPI.c
#    unit-tests/manual-ListOpenItemsAPI.c
#    unit-tests/manual-MarketplaceApiAPI.c
#    unit-tests/manual-NotificationsAPI.c
#    unit-tests/manual-OffenlegungAPI.c
#    unit-tests/manual-OnlineshopAPI.c
#    unit-tests/manual-OrderAPI.c
#    unit-tests/manual-OrderConfirmationAPI.c
#    unit-tests/manual-OssReportAPI.c
#    unit-tests/manual-PackingAPI.c
#    unit-tests/manual-ParticipationAPI.c
#    unit-tests/manual-PaygapAPI.c
#    unit-tests/manual-PaymentAPI.c
#    unit-tests/manual-PaymentConditionAPI.c
#    unit-tests/manual-PaymentGatewayAPI.c
#    unit-tests/manual-PayrollAPI.c
#    unit-tests/manual-PeppolAPI.c
#    unit-tests/manual-PlausibilityAPI.c
#    unit-tests/manual-PosAPI.c
#    unit-tests/manual-PostingCategoryAPI.c
#    unit-tests/manual-PriceTierAPI.c
#    unit-tests/manual-ProductAPI.c
#    unit-tests/manual-ProductAttributeAPI.c
#    unit-tests/manual-ProductCategoryAPI.c
#    unit-tests/manual-ProductVariantAPI.c
#    unit-tests/manual-ProductionOrderAPI.c
#    unit-tests/manual-ProformaInvoiceAPI.c
#    unit-tests/manual-ProposeAssignmentsAPI.c
#    unit-tests/manual-PublicReturnsAPI.c
#    unit-tests/manual-PurchaseOrderAPI.c
#    unit-tests/manual-QuotationAPI.c
#    unit-tests/manual-RecurringTemplateAPI.c
#    unit-tests/manual-ReorderProposalAPI.c
#    unit-tests/manual-ReplenishmentAPI.c
#    unit-tests/manual-ReportsAPI.c
#    unit-tests/manual-ReturnOrderAPI.c
#    unit-tests/manual-RfqAPI.c
#    unit-tests/manual-SearchAPI.c
#    unit-tests/manual-ServiceAssignmentAPI.c
#    unit-tests/manual-ServiceJobAPI.c
#    unit-tests/manual-ShareholderAPI.c
#    unit-tests/manual-ShipmentAPI.c
#    unit-tests/manual-ShippingAPI.c
#    unit-tests/manual-ShippingRuleAPI.c
#    unit-tests/manual-ShippingThresholdAPI.c
#    unit-tests/manual-ShopAPI.c
#    unit-tests/manual-SilentPartnerAPI.c
#    unit-tests/manual-StilleAPI.c
#    unit-tests/manual-StockMovementAPI.c
#    unit-tests/manual-StockTransferAPI.c
#    unit-tests/manual-SuitabilityAPI.c
#    unit-tests/manual-SupplierConditionAPI.c
#    unit-tests/manual-SupplierInvoiceAPI.c
#    unit-tests/manual-SupportChannelAPI.c
#    unit-tests/manual-SupportTicketAPI.c
#    unit-tests/manual-TaxAPI.c
#    unit-tests/manual-TenantSettingsAPI.c
#    unit-tests/manual-TicketMessageAPI.c
#    unit-tests/manual-TimeEntriesAPI.c
#    unit-tests/manual-TrainingAssignmentAPI.c
#    unit-tests/manual-TrainingsAPI.c
#    unit-tests/manual-UserAPI.c
#    unit-tests/manual-UserManagementAPI.c
#    unit-tests/manual-UstvaAPI.c
#    unit-tests/manual-VoucherAPI.c
#    unit-tests/manual-WarehouseAPI.c
#    unit-tests/manual-WarehouseStockAPI.c
#    unit-tests/manual-WebhooksAPI.c
#    unit-tests/manual-WorkflowsAPI.c
#    unit-tests/manual-ZugferdAPI.c
#)

##set header files
#set(HDRS
#)

## loop over all files in SRCS variable
#foreach(SOURCE_FILE ${SRCS})
#    # Get only the file name from the file as add_executable does not support executable with slash("/")
#    get_filename_component(FILE_NAME_ONLY ${SOURCE_FILE} NAME_WE)
#    # Remove .c from the file name and set it as executable name
#    string( REPLACE ".c" "" EXECUTABLE_FILE ${FILE_NAME_ONLY})
#    # Add executable for every source file in  SRCS
#    add_executable(unit-${EXECUTABLE_FILE} ${SOURCE_FILE})
#    # Link above created library to executable and dependent library curl
#    target_link_libraries(unit-${EXECUTABLE_FILE} ${CURL_LIBRARIES} ${pkgName} )
#endforeach(SOURCE_FILE ${SRCS})
