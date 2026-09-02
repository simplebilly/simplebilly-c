/*
 * email_template_status.h
 *
 * Email template status.
 */

#ifndef _email_template_status_H_
#define _email_template_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct email_template_status_t email_template_status_t;


// Enum  for email_template_status

typedef enum { simplebilly_api_email_template_status__NULL = 0, simplebilly_api_email_template_status__active, simplebilly_api_email_template_status__inactive } simplebilly_api_email_template_status__e;

char* email_template_status_email_template_status_ToString(simplebilly_api_email_template_status__e email_template_status);

simplebilly_api_email_template_status__e email_template_status_email_template_status_FromString(char* email_template_status);

cJSON *email_template_status_convertToJSON(simplebilly_api_email_template_status__e email_template_status);

simplebilly_api_email_template_status__e email_template_status_parseFromJSON(cJSON *email_template_statusJSON);

#endif /* _email_template_status_H_ */

