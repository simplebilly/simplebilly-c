#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/delivery_note.h"
#include "../model/delivery_note_create.h"
#include "../model/invoice.h"
#include "../model/plugin_error.h"


delivery_note_t*
DeliveryNoteAPI_createDeliveryNote(apiClient_t *apiClient, delivery_note_create_t *delivery_note_create);


void
DeliveryNoteAPI_deleteDeliveryNote(apiClient_t *apiClient, char *delivery_note_id);


delivery_note_t*
DeliveryNoteAPI_deliverynoteRestore(apiClient_t *apiClient, char *delivery_note_id);


void
DeliveryNoteAPI_downloadDeliveryNotePdf(apiClient_t *apiClient, char *delivery_note_id);


delivery_note_t*
DeliveryNoteAPI_getDeliveryNote(apiClient_t *apiClient, char *delivery_note_id);


list_t*
DeliveryNoteAPI_listDeliveryNotes(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


invoice_t*
DeliveryNoteAPI_pursueDeliveryNote(apiClient_t *apiClient, char *delivery_note_id);


