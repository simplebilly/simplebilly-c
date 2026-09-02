#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/plugin_error.h"
#include "../model/silent_partner.h"
#include "../model/silent_partner_create.h"
#include "../model/silent_partner_update.h"


silent_partner_t*
SilentPartnerAPI_createSilentPartner(apiClient_t *apiClient, silent_partner_create_t *silent_partner_create);


void
SilentPartnerAPI_deleteSilentPartner(apiClient_t *apiClient, char *id);


silent_partner_t*
SilentPartnerAPI_getSilentPartner(apiClient_t *apiClient, char *id);


list_t*
SilentPartnerAPI_getSilentPartners(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


silent_partner_t*
SilentPartnerAPI_updateSilentPartner(apiClient_t *apiClient, char *id, silent_partner_update_t *silent_partner_update);


