#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/send_message_dto.h"
#include "../model/ticket_message.h"


list_t*
TicketMessageAPI_listMessagesApi(apiClient_t *apiClient, char *ticket_id);


ticket_message_t*
TicketMessageAPI_sendMessageApi(apiClient_t *apiClient, char *ticket_id, send_message_dto_t *send_message_dto);


