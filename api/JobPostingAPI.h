#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/job_posting.h"
#include "../model/job_posting_create.h"
#include "../model/job_posting_update.h"
#include "../model/plugin_error.h"


job_posting_t*
JobPostingAPI_createJobPosting(apiClient_t *apiClient, job_posting_create_t *job_posting_create);


void
JobPostingAPI_deleteJobPosting(apiClient_t *apiClient, char *id);


job_posting_t*
JobPostingAPI_getJobPosting(apiClient_t *apiClient, char *id);


list_t*
JobPostingAPI_listJobPostings(apiClient_t *apiClient, char *status, int *page, int *pageSize);


job_posting_t*
JobPostingAPI_updateJobPosting(apiClient_t *apiClient, char *id, job_posting_update_t *job_posting_update);


