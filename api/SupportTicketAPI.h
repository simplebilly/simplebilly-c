#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/create_ticket_request.h"
#include "../model/support_ticket.h"
#include "../model/support_ticket_update.h"


support_ticket_t*
SupportTicketAPI_createTicketApi(apiClient_t *apiClient, create_ticket_request_t *create_ticket_request);


void
SupportTicketAPI_deleteTicketApi(apiClient_t *apiClient, char *ticket_id);


support_ticket_t*
SupportTicketAPI_getTicketApi(apiClient_t *apiClient, char *ticket_id);


list_t*
SupportTicketAPI_listTicketsApi(apiClient_t *apiClient, char *status, char *priority, char *assigned_to, char *channel_type, char *customer_id, char *search, int *page, int *page_size);


support_ticket_t*
SupportTicketAPI_updateTicketApi(apiClient_t *apiClient, char *ticket_id, support_ticket_update_t *support_ticket_update);


