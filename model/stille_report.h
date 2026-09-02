/*
 * stille_report.h
 *
 * 
 */

#ifndef _stille_report_H_
#define _stille_report_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct stille_report_t stille_report_t;

#include "stille_partner_zeile.h"



typedef struct stille_report_t {
    char *jahresueberschuss; // string
    list_t *partners; //nonprimitive container
    int *year; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} stille_report_t;

__attribute__((deprecated)) stille_report_t *stille_report_create(
    char *jahresueberschuss,
    list_t *partners,
    int *year
);

void stille_report_free(stille_report_t *stille_report);

stille_report_t *stille_report_parseFromJSON(cJSON *stille_reportJSON);

cJSON *stille_report_convertToJSON(stille_report_t *stille_report);

#endif /* _stille_report_H_ */

