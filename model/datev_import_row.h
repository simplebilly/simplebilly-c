/*
 * datev_import_row.h
 *
 * 
 */

#ifndef _datev_import_row_H_
#define _datev_import_row_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct datev_import_row_t datev_import_row_t;




typedef struct datev_import_row_t {
    char *account; // string
    char *amount; // string
    char *base_amount; // string
    char *base_currency; // string
    char *booking_text; // string
    char *bu_key; // string
    char *cost_center1; // string
    char *cost_center2; // string
    char *currency; // string
    char *debit_credit; // string
    char *discount; // string
    char *document_date; // string
    char *document_field2; // string
    char *document_number; // string
    char *eu_country_vat_id; // string
    char *eu_tax_rate; // string
    char *exchange_rate; // string
    char *opposite_account; // string

    int _library_owned; // Is the library responsible for freeing this object?
} datev_import_row_t;

__attribute__((deprecated)) datev_import_row_t *datev_import_row_create(
    char *account,
    char *amount,
    char *base_amount,
    char *base_currency,
    char *booking_text,
    char *bu_key,
    char *cost_center1,
    char *cost_center2,
    char *currency,
    char *debit_credit,
    char *discount,
    char *document_date,
    char *document_field2,
    char *document_number,
    char *eu_country_vat_id,
    char *eu_tax_rate,
    char *exchange_rate,
    char *opposite_account
);

void datev_import_row_free(datev_import_row_t *datev_import_row);

datev_import_row_t *datev_import_row_parseFromJSON(cJSON *datev_import_rowJSON);

cJSON *datev_import_row_convertToJSON(datev_import_row_t *datev_import_row);

#endif /* _datev_import_row_H_ */

