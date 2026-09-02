/*
 * group_figure_create.h
 *
 * 
 */

#ifndef _group_figure_create_H_
#define _group_figure_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct group_figure_create_t group_figure_create_t;




typedef struct group_figure_create_t {
    char *bilanzsumme; // string
    int *exemption_claimed; //boolean
    long *mitarbeiter; //numeric
    char *netto_umsatz; // string
    char *parent_name; // string
    char *parent_situs; // string

    int _library_owned; // Is the library responsible for freeing this object?
} group_figure_create_t;

__attribute__((deprecated)) group_figure_create_t *group_figure_create_create(
    char *bilanzsumme,
    int *exemption_claimed,
    long *mitarbeiter,
    char *netto_umsatz,
    char *parent_name,
    char *parent_situs
);

void group_figure_create_free(group_figure_create_t *group_figure_create);

group_figure_create_t *group_figure_create_parseFromJSON(cJSON *group_figure_createJSON);

cJSON *group_figure_create_convertToJSON(group_figure_create_t *group_figure_create);

#endif /* _group_figure_create_H_ */

