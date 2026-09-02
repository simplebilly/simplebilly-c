/*
 * quartile_band.h
 *
 * 
 */

#ifndef _quartile_band_H_
#define _quartile_band_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct quartile_band_t quartile_band_t;




typedef struct quartile_band_t {
    double *female_share_pct; //numeric
    char *hourly_median; // string
    double *male_share_pct; //numeric
    char *quartile; // string

    int _library_owned; // Is the library responsible for freeing this object?
} quartile_band_t;

__attribute__((deprecated)) quartile_band_t *quartile_band_create(
    double *female_share_pct,
    char *hourly_median,
    double *male_share_pct,
    char *quartile
);

void quartile_band_free(quartile_band_t *quartile_band);

quartile_band_t *quartile_band_parseFromJSON(cJSON *quartile_bandJSON);

cJSON *quartile_band_convertToJSON(quartile_band_t *quartile_band);

#endif /* _quartile_band_H_ */

