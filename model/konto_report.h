/*
 * konto_report.h
 *
 * 
 */

#ifndef _konto_report_H_
#define _konto_report_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct konto_report_t konto_report_t;

#include "konto_item.h"



typedef struct konto_report_t {
    char *generated_at; // string
    list_t *konten; //nonprimitive container
    char *period; // string

    int _library_owned; // Is the library responsible for freeing this object?
} konto_report_t;

__attribute__((deprecated)) konto_report_t *konto_report_create(
    char *generated_at,
    list_t *konten,
    char *period
);

void konto_report_free(konto_report_t *konto_report);

konto_report_t *konto_report_parseFromJSON(cJSON *konto_reportJSON);

cJSON *konto_report_convertToJSON(konto_report_t *konto_report);

#endif /* _konto_report_H_ */

