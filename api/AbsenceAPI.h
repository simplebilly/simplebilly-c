#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/absence.h"
#include "../model/absence_create.h"
#include "../model/absence_update.h"
#include "../model/plugin_error.h"


absence_t*
AbsenceAPI_createAbsence(apiClient_t *apiClient, absence_create_t *absence_create);


void
AbsenceAPI_deleteAbsence(apiClient_t *apiClient, char *id);


absence_t*
AbsenceAPI_getAbsence(apiClient_t *apiClient, char *id);


list_t*
AbsenceAPI_getAbsences(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


absence_t*
AbsenceAPI_updateAbsence(apiClient_t *apiClient, char *id, absence_update_t *absence_update);


