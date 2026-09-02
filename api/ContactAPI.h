#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/contact.h"
#include "../model/contact_timeline_response.h"
#include "../model/plugin_error.h"
#include "../model/sales_volume_report.h"


// Serve JSON Schema for client-side validation
//
any_type_t*
ContactAPI_contactSchema(apiClient_t *apiClient);


// Get the full per-contact timeline (Xentral §4.6/4.7).
//
// Aggregates communications, quotations, orders, invoices and uploaded documents for a contact, merged into a single reverse-chronological feed.
//
contact_timeline_response_t*
ContactAPI_contactTimeline(apiClient_t *apiClient, char *contact_id);


// Create contact
//
contact_t*
ContactAPI_createContact(apiClient_t *apiClient, body);


// Soft-delete contact
//
void
ContactAPI_deleteContact(apiClient_t *apiClient, char *contact_id);


// Get single contact
//
contact_t*
ContactAPI_getContact(apiClient_t *apiClient, char *contact_id);


// List contacts with search, type filter, and pagination
//
list_t*
ContactAPI_listContacts(apiClient_t *apiClient, int *page, int *page_size, char *search, char *contact_type, char *tag);


// Sales volume per contact
//
sales_volume_report_t*
ContactAPI_salesVolume(apiClient_t *apiClient, int *page, int *page_size, char *search, char *contact_type, char *tag);


// Update contact
//
contact_t*
ContactAPI_updateContact(apiClient_t *apiClient, char *contact_id, body);


