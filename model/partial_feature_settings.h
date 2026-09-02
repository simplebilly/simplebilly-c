/*
 * partial_feature_settings.h
 *
 * Partial feature toggles: &#x60;None&#x60; keeps the company-type default, &#x60;Some&#x60; overrides it.
 */

#ifndef _partial_feature_settings_H_
#define _partial_feature_settings_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct partial_feature_settings_t partial_feature_settings_t;




typedef struct partial_feature_settings_t {
    int *onlineshop; //boolean
    int *report_bilanz; //boolean
    int *report_bwa; //boolean
    int *report_euer; //boolean
    int *report_gewerbesteuer; //boolean
    int *report_guv; //boolean
    int *report_kst; //boolean
    int *report_ustva; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} partial_feature_settings_t;

__attribute__((deprecated)) partial_feature_settings_t *partial_feature_settings_create(
    int *onlineshop,
    int *report_bilanz,
    int *report_bwa,
    int *report_euer,
    int *report_gewerbesteuer,
    int *report_guv,
    int *report_kst,
    int *report_ustva
);

void partial_feature_settings_free(partial_feature_settings_t *partial_feature_settings);

partial_feature_settings_t *partial_feature_settings_parseFromJSON(cJSON *partial_feature_settingsJSON);

cJSON *partial_feature_settings_convertToJSON(partial_feature_settings_t *partial_feature_settings);

#endif /* _partial_feature_settings_H_ */

