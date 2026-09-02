#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/plugin_error.h"
#include "../model/training_assignment.h"
#include "../model/training_assignment_create.h"
#include "../model/training_assignment_update.h"


training_assignment_t*
TrainingAssignmentAPI_createTrainingAssignment(apiClient_t *apiClient, training_assignment_create_t *training_assignment_create);


void
TrainingAssignmentAPI_deleteTrainingAssignment(apiClient_t *apiClient, char *id);


training_assignment_t*
TrainingAssignmentAPI_getTrainingAssignment(apiClient_t *apiClient, char *id);


list_t*
TrainingAssignmentAPI_getTrainingAssignments(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


training_assignment_t*
TrainingAssignmentAPI_updateTrainingAssignment(apiClient_t *apiClient, char *id, training_assignment_update_t *training_assignment_update);


