#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/plugin_error.h"
#include "../model/smtp_config.h"


smtp_config_t*
OnlineshopAPI_getSmtpConfigApi(apiClient_t *apiClient);


smtp_config_t*
OnlineshopAPI_saveSmtpConfigApi(apiClient_t *apiClient, smtp_config_t *smtp_config);


