#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/mirror_trigger_response.h"
#include "../model/plugin_error.h"


mirror_trigger_response_t*
AdminAPI_triggerMirror(apiClient_t *apiClient);


