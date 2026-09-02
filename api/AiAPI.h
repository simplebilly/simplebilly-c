#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/ai_config_dto.h"
#include "../model/ai_suggestion.h"
#include "../model/ai_suggestion_request.h"
#include "../model/ai_worker_config.h"
#include "../model/plugin_error.h"


ai_suggestion_t*
AiAPI_aiSuggestApi(apiClient_t *apiClient, ai_suggestion_request_t *ai_suggestion_request);


ai_worker_config_t*
AiAPI_createWorkerApi(apiClient_t *apiClient, ai_config_dto_t *ai_config_dto);


list_t*
AiAPI_listWorkersApi(apiClient_t *apiClient);


ai_suggestion_t*
AiAPI_runWorkerApi(apiClient_t *apiClient, char *worker_id, ai_suggestion_request_t *ai_suggestion_request);


