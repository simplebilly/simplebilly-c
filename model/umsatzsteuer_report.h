/*
 * umsatzsteuer_report.h
 *
 * 
 */

#ifndef _umsatzsteuer_report_H_
#define _umsatzsteuer_report_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct umsatzsteuer_report_t umsatzsteuer_report_t;

#include "vat_detail.h"



typedef struct umsatzsteuer_report_t {
    char *generated_at; // string
    list_t *input_tax; //nonprimitive container
    list_t *output_tax; //nonprimitive container
    char *period; // string
    char *total_input_tax; // string
    char *total_output_tax; // string
    char *vat_payable; // string
    char *vat_refund; // string

    int _library_owned; // Is the library responsible for freeing this object?
} umsatzsteuer_report_t;

__attribute__((deprecated)) umsatzsteuer_report_t *umsatzsteuer_report_create(
    char *generated_at,
    list_t *input_tax,
    list_t *output_tax,
    char *period,
    char *total_input_tax,
    char *total_output_tax,
    char *vat_payable,
    char *vat_refund
);

void umsatzsteuer_report_free(umsatzsteuer_report_t *umsatzsteuer_report);

umsatzsteuer_report_t *umsatzsteuer_report_parseFromJSON(cJSON *umsatzsteuer_reportJSON);

cJSON *umsatzsteuer_report_convertToJSON(umsatzsteuer_report_t *umsatzsteuer_report);

#endif /* _umsatzsteuer_report_H_ */

