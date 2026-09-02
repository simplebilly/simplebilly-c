/*
 * gez_report.h
 *
 * Berechnungsergebnis des Rundfunkbeitrags für ein Unternehmen.
 */

#ifndef _gez_report_H_
#define _gez_report_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gez_report_t gez_report_t;

#include "betriebsstaetten_detail.h"



typedef struct gez_report_t {
    long *beitragsfreie_kfz; //numeric
    long *beitragspflichtige_kfz; //numeric
    list_t *betriebsstaetten; //nonprimitive container
    char *hinweis; // string
    char *hotelzimmer_beitrag; // string
    char *jaehrlicher_beitrag; // string
    int *jahr; //numeric
    char *kfz_beitrag; // string
    char *monatlicher_beitrag; // string
    char *vierteljaehrlicher_beitrag; // string

    int _library_owned; // Is the library responsible for freeing this object?
} gez_report_t;

__attribute__((deprecated)) gez_report_t *gez_report_create(
    long *beitragsfreie_kfz,
    long *beitragspflichtige_kfz,
    list_t *betriebsstaetten,
    char *hinweis,
    char *hotelzimmer_beitrag,
    char *jaehrlicher_beitrag,
    int *jahr,
    char *kfz_beitrag,
    char *monatlicher_beitrag,
    char *vierteljaehrlicher_beitrag
);

void gez_report_free(gez_report_t *gez_report);

gez_report_t *gez_report_parseFromJSON(cJSON *gez_reportJSON);

cJSON *gez_report_convertToJSON(gez_report_t *gez_report);

#endif /* _gez_report_H_ */

