#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/invoice.h"
#include "../model/plugin_error.h"


invoice_t*
CreditNoteAPI_createCreditNote(apiClient_t *apiClient, body);


void
CreditNoteAPI_downloadCreditNotePdf(apiClient_t *apiClient, char *credit_note_id);


invoice_t*
CreditNoteAPI_getCreditNote(apiClient_t *apiClient, char *credit_note_id);


list_t*
CreditNoteAPI_listCreditNotes(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


