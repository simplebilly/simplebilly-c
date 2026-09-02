/*
 * e_bilanz_report.h
 *
 * 
 */

#ifndef _e_bilanz_report_H_
#define _e_bilanz_report_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct e_bilanz_report_t e_bilanz_report_t;

#include "account_overview.h"
#include "balance_sheet.h"
#include "income_statement.h"
#include "vat_summary.h"



typedef struct e_bilanz_report_t {
    list_t *account_overview; //nonprimitive container
    struct balance_sheet_t *balance_sheet; //model
    char *generated_at; // string
    struct income_statement_t *income_statement; //model
    char *period; // string
    struct vat_summary_t *vat_summary; //model

    int _library_owned; // Is the library responsible for freeing this object?
} e_bilanz_report_t;

__attribute__((deprecated)) e_bilanz_report_t *e_bilanz_report_create(
    list_t *account_overview,
    balance_sheet_t *balance_sheet,
    char *generated_at,
    income_statement_t *income_statement,
    char *period,
    vat_summary_t *vat_summary
);

void e_bilanz_report_free(e_bilanz_report_t *e_bilanz_report);

e_bilanz_report_t *e_bilanz_report_parseFromJSON(cJSON *e_bilanz_reportJSON);

cJSON *e_bilanz_report_convertToJSON(e_bilanz_report_t *e_bilanz_report);

#endif /* _e_bilanz_report_H_ */

