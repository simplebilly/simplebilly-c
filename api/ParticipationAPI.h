#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/participation.h"
#include "../model/participation_create.h"
#include "../model/participation_update.h"
#include "../model/plugin_error.h"


participation_t*
ParticipationAPI_createParticipation(apiClient_t *apiClient, participation_create_t *participation_create);


void
ParticipationAPI_deleteParticipation(apiClient_t *apiClient, char *id);


participation_t*
ParticipationAPI_getParticipation(apiClient_t *apiClient, char *id);


list_t*
ParticipationAPI_getParticipations(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


participation_t*
ParticipationAPI_updateParticipation(apiClient_t *apiClient, char *id, participation_update_t *participation_update);


