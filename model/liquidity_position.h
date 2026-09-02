/*
 * liquidity_position.h
 *
 * 
 */

#ifndef _liquidity_position_H_
#define _liquidity_position_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct liquidity_position_t liquidity_position_t;




typedef struct liquidity_position_t {
    double *accounts_payable; //numeric
    double *accounts_receivable; //numeric
    double *cash_and_equivalents; //numeric
    double *current_ratio; //numeric
    double *quick_ratio; //numeric
    double *working_capital; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} liquidity_position_t;

__attribute__((deprecated)) liquidity_position_t *liquidity_position_create(
    double *accounts_payable,
    double *accounts_receivable,
    double *cash_and_equivalents,
    double *current_ratio,
    double *quick_ratio,
    double *working_capital
);

void liquidity_position_free(liquidity_position_t *liquidity_position);

liquidity_position_t *liquidity_position_parseFromJSON(cJSON *liquidity_positionJSON);

cJSON *liquidity_position_convertToJSON(liquidity_position_t *liquidity_position);

#endif /* _liquidity_position_H_ */

