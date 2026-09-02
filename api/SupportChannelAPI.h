#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/create_channel_dto.h"
#include "../model/support_channel.h"
#include "../model/update_channel_dto.h"


support_channel_t*
SupportChannelAPI_createChannelApi(apiClient_t *apiClient, create_channel_dto_t *create_channel_dto);


void
SupportChannelAPI_deleteChannelApi(apiClient_t *apiClient, char *channel_id);


list_t*
SupportChannelAPI_listChannelsApi(apiClient_t *apiClient);


support_channel_t*
SupportChannelAPI_updateChannelApi(apiClient_t *apiClient, char *channel_id, update_channel_dto_t *update_channel_dto);


