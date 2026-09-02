#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/legal_document.h"
#include "../model/legal_document_reset.h"
#include "../model/legal_document_upsert.h"
#include "../model/plugin_error.h"


// List all legal documents of the tenant. Missing documents are seeded from the default texts (with tenant placeholders replaced) on first access.
//
list_t*
LegalDocumentAPI_getLegalDocuments(apiClient_t *apiClient);


// Restore default texts for all documents (or a single doc_type/lang when the optional filter is given). Returns the full tenant list.
//
list_t*
LegalDocumentAPI_resetLegalDocuments(apiClient_t *apiClient, legal_document_reset_t *legal_document_reset);


// Upsert legal documents per (doc_type, lang). Returns the full tenant list.
//
list_t*
LegalDocumentAPI_upsertLegalDocuments(apiClient_t *apiClient, list_t *legal_document_upsert);


