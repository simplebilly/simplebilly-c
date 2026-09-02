#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/compliance_training.h"
#include "../model/compliance_training_create.h"
#include "../model/compliance_training_update.h"
#include "../model/plugin_error.h"


compliance_training_t*
ComplianceTrainingAPI_createComplianceTraining(apiClient_t *apiClient, compliance_training_create_t *compliance_training_create);


void
ComplianceTrainingAPI_deleteComplianceTraining(apiClient_t *apiClient, char *id);


compliance_training_t*
ComplianceTrainingAPI_getComplianceTraining(apiClient_t *apiClient, char *id);


list_t*
ComplianceTrainingAPI_getComplianceTrainings(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


compliance_training_t*
ComplianceTrainingAPI_updateComplianceTraining(apiClient_t *apiClient, char *id, compliance_training_update_t *compliance_training_update);


