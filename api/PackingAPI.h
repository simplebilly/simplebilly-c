#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/packing_complete_request.h"
#include "../model/packing_complete_response.h"
#include "../model/packing_queue.h"
#include "../model/packing_video_response.h"
#include "../model/plugin_error.h"
#include "../model/print_delivery_note_response.h"
#include "../model/print_label_response.h"


// Mark packing as complete and transition order to shipped
//
packing_complete_response_t*
PackingAPI_completePacking(apiClient_t *apiClient, char *order_number, packing_complete_request_t *packing_complete_request);


// Get the packing queue - orders ready for packing
//
packing_queue_t*
PackingAPI_getPackingQueue(apiClient_t *apiClient, int *page, int *page_size, char *search);


// Print delivery note (Lieferschein) for an order
//
print_delivery_note_response_t*
PackingAPI_printDeliveryNote(apiClient_t *apiClient, char *order_number);


// Print shipping label for an order
//
print_label_response_t*
PackingAPI_printLabel(apiClient_t *apiClient, char *order_number);


// Record video of packing process
//
packing_video_response_t*
PackingAPI_recordPackingVideo(apiClient_t *apiClient, char *order_number, body);


