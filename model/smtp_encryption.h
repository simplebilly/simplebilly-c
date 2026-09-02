/*
 * smtp_encryption.h
 *
 * 
 */

#ifndef _smtp_encryption_H_
#define _smtp_encryption_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct smtp_encryption_t smtp_encryption_t;


// Enum  for smtp_encryption

typedef enum { simplebilly_api_smtp_encryption__NULL = 0, simplebilly_api_smtp_encryption__StartTls, simplebilly_api_smtp_encryption__Tls } simplebilly_api_smtp_encryption__e;

char* smtp_encryption_smtp_encryption_ToString(simplebilly_api_smtp_encryption__e smtp_encryption);

simplebilly_api_smtp_encryption__e smtp_encryption_smtp_encryption_FromString(char* smtp_encryption);

cJSON *smtp_encryption_convertToJSON(simplebilly_api_smtp_encryption__e smtp_encryption);

simplebilly_api_smtp_encryption__e smtp_encryption_parseFromJSON(cJSON *smtp_encryptionJSON);

#endif /* _smtp_encryption_H_ */

