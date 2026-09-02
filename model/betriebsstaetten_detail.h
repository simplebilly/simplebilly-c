/*
 * betriebsstaetten_detail.h
 *
 * 
 */

#ifndef _betriebsstaetten_detail_H_
#define _betriebsstaetten_detail_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct betriebsstaetten_detail_t betriebsstaetten_detail_t;




typedef struct betriebsstaetten_detail_t {
    long *beschaefigte; //numeric
    char *monatlicher_beitrag; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} betriebsstaetten_detail_t;

__attribute__((deprecated)) betriebsstaetten_detail_t *betriebsstaetten_detail_create(
    long *beschaefigte,
    char *monatlicher_beitrag,
    char *name
);

void betriebsstaetten_detail_free(betriebsstaetten_detail_t *betriebsstaetten_detail);

betriebsstaetten_detail_t *betriebsstaetten_detail_parseFromJSON(cJSON *betriebsstaetten_detailJSON);

cJSON *betriebsstaetten_detail_convertToJSON(betriebsstaetten_detail_t *betriebsstaetten_detail);

#endif /* _betriebsstaetten_detail_H_ */

