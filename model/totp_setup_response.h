/*
 * totp_setup_response.h
 *
 * 
 */

#ifndef _totp_setup_response_H_
#define _totp_setup_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct totp_setup_response_t totp_setup_response_t;




typedef struct totp_setup_response_t {
    list_t *backup_codes; //primitive container
    char *qr_code_url; // string
    char *secret; // string

    int _library_owned; // Is the library responsible for freeing this object?
} totp_setup_response_t;

__attribute__((deprecated)) totp_setup_response_t *totp_setup_response_create(
    list_t *backup_codes,
    char *qr_code_url,
    char *secret
);

void totp_setup_response_free(totp_setup_response_t *totp_setup_response);

totp_setup_response_t *totp_setup_response_parseFromJSON(cJSON *totp_setup_responseJSON);

cJSON *totp_setup_response_convertToJSON(totp_setup_response_t *totp_setup_response);

#endif /* _totp_setup_response_H_ */

