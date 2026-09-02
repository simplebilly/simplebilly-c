#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/api_response_gdpr_export.h"
#include "../model/dpa_accept_request.h"
#include "../model/dpa_status.h"
#include "../model/plugin_error.h"


// Record DPA acceptance: sets dpa_accepted_at/by/version on the tenant settings row (created with company-type defaults if missing).
//
dpa_status_t*
GdprAPI_acceptDpa(apiClient_t *apiClient, dpa_accept_request_t *dpa_accept_request);


// Erase ALL personal data of the tenant (TOS §11: deletion 90 days after termination).
//
// Anonymizes every contact, anonymizes personal fields on bookkeeping records (orders/invoices/payments keep amounts and dates for GoBD), removes the tenant linkage of the (global, saasy-framework) users and marks the erasure on `tenant_settings.gdpr_erased_at`. No row is physically deleted. The audit triggers on the touched tables record who/when.
//
any_type_t*
GdprAPI_accountErasure(apiClient_t *apiClient);


// Anonymize + soft-delete a contact: personal attributes are cleared, the record itself is kept for GoBD retention (Art. 17(3)(e) DSGVO). The audit trigger on `contacts` already records who/when.
//
any_type_t*
GdprAPI_erasureContact(apiClient_t *apiClient, char *contact_id);


// Art. 15 data-subject access export for a contact.
//
// Returns the contact itself plus the tenant-scoped rows linked to it.  ## Relations The `customers`/`orders`/`invoices`/`payments` tables have no FK to `contacts`; they are linked through the `customer_id` column, which per the app's conventions holds one of: - the admin customer's `customer_id` (a UUID, often the same value as   the contact's `contact_id`/`customer_number`), - the buyer's email for shop orders, or - the marketplace's external customer id for plugin orders.  The export therefore matches the contact's identifiers (`contact_id`, `customer_number`, `external_id`, `email`) plus any resolved customer ids against `customer_id`. `delivery_notes` and `customer_communications` reference contacts directly via `contact_id`. Soft-deleted rows are included (their data is still processed and retained for GoBD). Relations that genuinely do not exist for a contact stay empty but the key is always present.
//
any_type_t*
GdprAPI_exportContactData(apiClient_t *apiClient, char *contact_id);


// Export the current user's personal data (GDPR Art. 15/20).
//
// No admin permission required: a user always exports their own data.
//
api_response_gdpr_export_t*
GdprAPI_exportGdpr(apiClient_t *apiClient);


// Current DPA acceptance status (from tenant_settings).
//
dpa_status_t*
GdprAPI_getDpa(apiClient_t *apiClient);


