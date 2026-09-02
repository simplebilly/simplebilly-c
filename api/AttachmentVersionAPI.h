#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/attachment.h"
#include "../model/attachment_version.h"
#include "../model/new_version_request.h"
#include "../model/plugin_error.h"


attachment_version_t*
AttachmentVersionAPI_createAttachmentVersion(apiClient_t *apiClient, char *attachment_id, new_version_request_t *new_version_request);


list_t*
AttachmentVersionAPI_listAttachmentVersions(apiClient_t *apiClient, char *attachment_id);


attachment_t*
AttachmentVersionAPI_restoreAttachmentVersion(apiClient_t *apiClient, char *attachment_id, char *version_id);


