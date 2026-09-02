#ifndef production_order_costing_TEST
#define production_order_costing_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define production_order_costing_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/production_order_costing.h"
production_order_costing_t* instantiate_production_order_costing(int include_optional);



production_order_costing_t* instantiate_production_order_costing(int include_optional) {
  production_order_costing_t* production_order_costing = NULL;
  if (include_optional) {
    production_order_costing = production_order_costing_create(
      "0",
      "0",
      list_createList(),
      "0",
      "0",
      "0",
      "0",
      "0",
      56,
      "0",
      "0"
    );
  } else {
    production_order_costing = production_order_costing_create(
      "0",
      "0",
      list_createList(),
      "0",
      "0",
      "0",
      "0",
      "0",
      56,
      "0",
      "0"
    );
  }

  return production_order_costing;
}


#ifdef production_order_costing_MAIN

void test_production_order_costing(int include_optional) {
    production_order_costing_t* production_order_costing_1 = instantiate_production_order_costing(include_optional);

	cJSON* jsonproduction_order_costing_1 = production_order_costing_convertToJSON(production_order_costing_1);
	printf("production_order_costing :\n%s\n", cJSON_Print(jsonproduction_order_costing_1));
	production_order_costing_t* production_order_costing_2 = production_order_costing_parseFromJSON(jsonproduction_order_costing_1);
	cJSON* jsonproduction_order_costing_2 = production_order_costing_convertToJSON(production_order_costing_2);
	printf("repeating production_order_costing:\n%s\n", cJSON_Print(jsonproduction_order_costing_2));
}

int main() {
  test_production_order_costing(1);
  test_production_order_costing(0);

  printf("Hello world \n");
  return 0;
}

#endif // production_order_costing_MAIN
#endif // production_order_costing_TEST
