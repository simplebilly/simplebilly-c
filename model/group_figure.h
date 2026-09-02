/*
 * group_figure.h
 *
 * 
 */

#ifndef _group_figure_H_
#define _group_figure_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct group_figure_t group_figure_t;




typedef struct group_figure_t {
    char *bilanzsumme; // string
    int *exemption_claimed; //boolean
    long *mitarbeiter; //numeric
    char *netto_umsatz; // string
    char *parent_name; // string
    char *parent_situs; // string
    int *year; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} group_figure_t;

__attribute__((deprecated)) group_figure_t *group_figure_create(
    char *bilanzsumme,
    int *exemption_claimed,
    long *mitarbeiter,
    char *netto_umsatz,
    char *parent_name,
    char *parent_situs,
    int *year
);

void group_figure_free(group_figure_t *group_figure);

group_figure_t *group_figure_parseFromJSON(cJSON *group_figureJSON);

cJSON *group_figure_convertToJSON(group_figure_t *group_figure);

#endif /* _group_figure_H_ */

