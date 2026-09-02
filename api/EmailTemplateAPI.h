#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/email_template.h"
#include "../model/email_template_create.h"
#include "../model/email_template_update.h"
#include "../model/plugin_error.h"


email_template_t*
EmailTemplateAPI_createEmailTemplate(apiClient_t *apiClient, email_template_create_t *email_template_create);


void
EmailTemplateAPI_deleteEmailTemplate(apiClient_t *apiClient, char *email_template_id);


email_template_t*
EmailTemplateAPI_getEmailTemplate(apiClient_t *apiClient, char *email_template_id);


list_t*
EmailTemplateAPI_listEmailTemplates(apiClient_t *apiClient, int *page, int *pageSize, char *status, char *search);


any_type_t*
EmailTemplateAPI_renderEmailTemplate(apiClient_t *apiClient, char *email_template_id, body);


email_template_t*
EmailTemplateAPI_updateEmailTemplate(apiClient_t *apiClient, char *email_template_id, email_template_update_t *email_template_update);


