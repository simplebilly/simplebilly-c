/*
 * datev_booking_preview.h
 *
 * 
 */

#ifndef _datev_booking_preview_H_
#define _datev_booking_preview_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct datev_booking_preview_t datev_booking_preview_t;




typedef struct datev_booking_preview_t {
    char *account_number; // string
    char *debit_credit; // string
    char *document_date; // string
    char *document_text; // string
    char *net_amount; // string
    char *opposite_account; // string
    char *tax_amount; // string
    char *tax_rate; // string

    int _library_owned; // Is the library responsible for freeing this object?
} datev_booking_preview_t;

__attribute__((deprecated)) datev_booking_preview_t *datev_booking_preview_create(
    char *account_number,
    char *debit_credit,
    char *document_date,
    char *document_text,
    char *net_amount,
    char *opposite_account,
    char *tax_amount,
    char *tax_rate
);

void datev_booking_preview_free(datev_booking_preview_t *datev_booking_preview);

datev_booking_preview_t *datev_booking_preview_parseFromJSON(cJSON *datev_booking_previewJSON);

cJSON *datev_booking_preview_convertToJSON(datev_booking_preview_t *datev_booking_preview);

#endif /* _datev_booking_preview_H_ */

