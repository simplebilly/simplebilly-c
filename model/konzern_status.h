/*
 * konzern_status.h
 *
 * 
 */

#ifndef _konzern_status_H_
#define _konzern_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct konzern_status_t konzern_status_t;

#include "konzern_beteiligung.h"
#include "konzern_thresholds.h"



typedef struct konzern_status_t {
    int *groessenbefreit; //boolean
    int *kapitalmarktorientiert; //boolean
    int *konzernabschlusspflicht; //boolean
    int *missing_group_figures; //boolean
    int *mutterunternehmen; //boolean
    char *parent_name; // string
    char *parent_situs; // string
    list_t *participations; //nonprimitive container
    struct konzern_thresholds_t *thresholds; //model
    int *year; //numeric
    int *zwischenholding_befreit; //boolean
    char *zwischenholding_hinweis; // string

    int _library_owned; // Is the library responsible for freeing this object?
} konzern_status_t;

__attribute__((deprecated)) konzern_status_t *konzern_status_create(
    int *groessenbefreit,
    int *kapitalmarktorientiert,
    int *konzernabschlusspflicht,
    int *missing_group_figures,
    int *mutterunternehmen,
    char *parent_name,
    char *parent_situs,
    list_t *participations,
    konzern_thresholds_t *thresholds,
    int *year,
    int *zwischenholding_befreit,
    char *zwischenholding_hinweis
);

void konzern_status_free(konzern_status_t *konzern_status);

konzern_status_t *konzern_status_parseFromJSON(cJSON *konzern_statusJSON);

cJSON *konzern_status_convertToJSON(konzern_status_t *konzern_status);

#endif /* _konzern_status_H_ */

