#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/hr_training_overview.h"
#include "../model/my_training_item.h"
#include "../model/plugin_error.h"
#include "../model/submit_result_dto.h"
#include "../model/submit_result_response.h"
#include "../model/training_content.h"


list_t*
TrainingsAPI_getMyTrainings(apiClient_t *apiClient);


training_content_t*
TrainingsAPI_getTrainingContent(apiClient_t *apiClient, char *code);


list_t*
TrainingsAPI_getTrainingOverview(apiClient_t *apiClient);


submit_result_response_t*
TrainingsAPI_submitTrainingResult(apiClient_t *apiClient, submit_result_dto_t *submit_result_dto);


