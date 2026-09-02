/*
 * budget_kategorie.h
 *
 * 
 */

#ifndef _budget_kategorie_H_
#define _budget_kategorie_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct budget_kategorie_t budget_kategorie_t;




typedef struct budget_kategorie_t {
    char *budget; // string
    char *differenz; // string
    char *goal; // string
    char *ist; // string
    char *kategorie; // string

    int _library_owned; // Is the library responsible for freeing this object?
} budget_kategorie_t;

__attribute__((deprecated)) budget_kategorie_t *budget_kategorie_create(
    char *budget,
    char *differenz,
    char *goal,
    char *ist,
    char *kategorie
);

void budget_kategorie_free(budget_kategorie_t *budget_kategorie);

budget_kategorie_t *budget_kategorie_parseFromJSON(cJSON *budget_kategorieJSON);

cJSON *budget_kategorie_convertToJSON(budget_kategorie_t *budget_kategorie);

#endif /* _budget_kategorie_H_ */

