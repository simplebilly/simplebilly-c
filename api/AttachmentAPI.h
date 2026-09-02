#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/attachment.h"
#include "../model/attachment_create.h"
#include "../model/ocr_text_request.h"
#include "../model/plugin_error.h"


attachment_t*
AttachmentAPI_attachmentRestore(apiClient_t *apiClient, char *id);


attachment_t*
AttachmentAPI_createAttachment(apiClient_t *apiClient, attachment_create_t *attachment_create);


void
AttachmentAPI_deleteAttachment(apiClient_t *apiClient, char *id);


attachment_t*
AttachmentAPI_getAttachment(apiClient_t *apiClient, char *id);


list_t*
AttachmentAPI_listAttachments(apiClient_t *apiClient, int *page, int *pageSize, char *contactId);


// Persist client-side OCR output for an attachment.
//
attachment_t*
AttachmentAPI_saveAttachmentOcrText(apiClient_t *apiClient, char *attachment_id, ocr_text_request_t *ocr_text_request);


