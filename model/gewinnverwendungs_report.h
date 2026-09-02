/*
 * gewinnverwendungs_report.h
 *
 * 
 */

#ifndef _gewinnverwendungs_report_H_
#define _gewinnverwendungs_report_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gewinnverwendungs_report_t gewinnverwendungs_report_t;

#include "gewinnverwendungs_zeile.h"



typedef struct gewinnverwendungs_report_t {
    char *bilanzgewinn; // string
    char *gesetzliche_ruecklage_bestand; // string
    char *gesetzliche_ruecklage_cap; // string
    char *gesetzliche_ruecklage_nach; // string
    char *gesetzliche_ruecklage_soll; // string
    char *gezeichnetes_kapital; // string
    char *jahresueberschuss; // string
    int *year; //numeric
    list_t *zeilen; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} gewinnverwendungs_report_t;

__attribute__((deprecated)) gewinnverwendungs_report_t *gewinnverwendungs_report_create(
    char *bilanzgewinn,
    char *gesetzliche_ruecklage_bestand,
    char *gesetzliche_ruecklage_cap,
    char *gesetzliche_ruecklage_nach,
    char *gesetzliche_ruecklage_soll,
    char *gezeichnetes_kapital,
    char *jahresueberschuss,
    int *year,
    list_t *zeilen
);

void gewinnverwendungs_report_free(gewinnverwendungs_report_t *gewinnverwendungs_report);

gewinnverwendungs_report_t *gewinnverwendungs_report_parseFromJSON(cJSON *gewinnverwendungs_reportJSON);

cJSON *gewinnverwendungs_report_convertToJSON(gewinnverwendungs_report_t *gewinnverwendungs_report);

#endif /* _gewinnverwendungs_report_H_ */

