/*
 * posting_category_type.h
 *
 * Posting category type: income or expense.
 */

#ifndef _posting_category_type_H_
#define _posting_category_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct posting_category_type_t posting_category_type_t;


// Enum  for posting_category_type

typedef enum { simplebilly_api_posting_category_type__NULL = 0, simplebilly_api_posting_category_type__income, simplebilly_api_posting_category_type__expense } simplebilly_api_posting_category_type__e;

char* posting_category_type_posting_category_type_ToString(simplebilly_api_posting_category_type__e posting_category_type);

simplebilly_api_posting_category_type__e posting_category_type_posting_category_type_FromString(char* posting_category_type);

cJSON *posting_category_type_convertToJSON(simplebilly_api_posting_category_type__e posting_category_type);

simplebilly_api_posting_category_type__e posting_category_type_parseFromJSON(cJSON *posting_category_typeJSON);

#endif /* _posting_category_type_H_ */

