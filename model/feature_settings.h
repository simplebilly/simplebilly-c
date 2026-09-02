/*
 * feature_settings.h
 *
 * Feature toggles for a tenant.
 */

#ifndef _feature_settings_H_
#define _feature_settings_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct feature_settings_t feature_settings_t;




typedef struct feature_settings_t {
    int *onlineshop; //boolean
    int *report_bilanz; //boolean
    int *report_bwa; //boolean
    int *report_euer; //boolean
    int *report_gewerbesteuer; //boolean
    int *report_guv; //boolean
    int *report_kst; //boolean
    int *report_ustva; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} feature_settings_t;

__attribute__((deprecated)) feature_settings_t *feature_settings_create(
    int *onlineshop,
    int *report_bilanz,
    int *report_bwa,
    int *report_euer,
    int *report_gewerbesteuer,
    int *report_guv,
    int *report_kst,
    int *report_ustva
);

void feature_settings_free(feature_settings_t *feature_settings);

feature_settings_t *feature_settings_parseFromJSON(cJSON *feature_settingsJSON);

cJSON *feature_settings_convertToJSON(feature_settings_t *feature_settings);

#endif /* _feature_settings_H_ */

