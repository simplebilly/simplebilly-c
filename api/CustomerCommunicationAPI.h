#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/communication_channel.h"
#include "../model/communication_direction.h"
#include "../model/contact_history_response.h"
#include "../model/customer_communication.h"
#include "../model/customer_communication_create.h"
#include "../model/customer_communication_update.h"
#include "../model/plugin_error.h"


customer_communication_t*
CustomerCommunicationAPI_createCommunication(apiClient_t *apiClient, customer_communication_create_t *customer_communication_create);


customer_communication_t*
CustomerCommunicationAPI_customercommunicationRestore(apiClient_t *apiClient, char *communication_id);


void
CustomerCommunicationAPI_deleteCommunication(apiClient_t *apiClient, char *communication_id);


customer_communication_t*
CustomerCommunicationAPI_getCommunication(apiClient_t *apiClient, char *communication_id);


contact_history_response_t*
CustomerCommunicationAPI_getContactHistory(apiClient_t *apiClient, char *contact_id);


list_t*
CustomerCommunicationAPI_listCommunications(apiClient_t *apiClient, int *page, int *page_size, char *contact_id, channel, direction, char from, char to);


customer_communication_t*
CustomerCommunicationAPI_updateCommunication(apiClient_t *apiClient, char *communication_id, customer_communication_update_t *customer_communication_update);


