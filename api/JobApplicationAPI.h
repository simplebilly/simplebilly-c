#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/application_status_dto.h"
#include "../model/job_application.h"
#include "../model/public_posting.h"


void
JobApplicationAPI_applyPublic(apiClient_t *apiClient, char *posting_id);


job_application_t*
JobApplicationAPI_deleteJobApplication(apiClient_t *apiClient, char *application_id);


void
JobApplicationAPI_downloadCv(apiClient_t *apiClient, char *application_id);


job_application_t*
JobApplicationAPI_getJobApplication(apiClient_t *apiClient, char *application_id);


// Inbound CV email, mailgun/sendgrid inbound-parse style: multipart form with `from`, `subject`, `body-plain` and one or more `attachment-N` file fields. The subject may reference a posting as `[JOB-<posting_id>]`; without one the application lands in the general inbox.
//
void
JobApplicationAPI_inboundEmail(apiClient_t *apiClient);


list_t*
JobApplicationAPI_listJobApplications(apiClient_t *apiClient, char *postingId, char *status, int *page, int *pageSize);


list_t*
JobApplicationAPI_listPublicPostings(apiClient_t *apiClient);


job_application_t*
JobApplicationAPI_scoreJobApplication(apiClient_t *apiClient, char *application_id);


job_application_t*
JobApplicationAPI_updateJobApplicationStatus(apiClient_t *apiClient, char *application_id, application_status_dto_t *application_status_dto);


