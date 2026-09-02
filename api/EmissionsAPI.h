#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/create_emission_entry.h"
#include "../model/create_emission_target.h"
#include "../model/emission_entry.h"
#include "../model/emission_factor_response.h"
#include "../model/emission_target.h"
#include "../model/emissions_export_response.h"
#include "../model/emissions_report.h"
#include "../model/plugin_error.h"


emission_entry_t*
EmissionsAPI_createEmissionEntryApi(apiClient_t *apiClient, create_emission_entry_t *create_emission_entry);


emission_target_t*
EmissionsAPI_createEmissionTargetApi(apiClient_t *apiClient, create_emission_target_t *create_emission_target);


void
EmissionsAPI_deleteEmissionEntryApi(apiClient_t *apiClient, char *id);


void
EmissionsAPI_deleteEmissionTargetApi(apiClient_t *apiClient, char *id);


list_t*
EmissionsAPI_emissionsEntriesApi(apiClient_t *apiClient, int *year);


emissions_export_response_t*
EmissionsAPI_emissionsExportApi(apiClient_t *apiClient, int *year);


list_t*
EmissionsAPI_emissionsFactorsApi(apiClient_t *apiClient);


emissions_report_t*
EmissionsAPI_emissionsReportApi(apiClient_t *apiClient, int *year);


list_t*
EmissionsAPI_emissionsTargetsApi(apiClient_t *apiClient);


