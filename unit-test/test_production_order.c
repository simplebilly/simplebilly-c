#ifndef production_order_TEST
#define production_order_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define production_order_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/production_order.h"
production_order_t* instantiate_production_order(int include_optional);



production_order_t* instantiate_production_order(int include_optional) {
  production_order_t* production_order = NULL;
  if (include_optional) {
    production_order = production_order_create(
      "0",
      null,
      "2013-10-20",
      "0",
      "0",
      "0",
      56,
      "0",
      "2013-10-20",
      planned,
      "0"
    );
  } else {
    production_order = production_order_create(
      "0",
      null,
      "2013-10-20",
      "0",
      "0",
      "0",
      56,
      "0",
      "2013-10-20",
      planned,
      "0"
    );
  }

  return production_order;
}


#ifdef production_order_MAIN

void test_production_order(int include_optional) {
    production_order_t* production_order_1 = instantiate_production_order(include_optional);

	cJSON* jsonproduction_order_1 = production_order_convertToJSON(production_order_1);
	printf("production_order :\n%s\n", cJSON_Print(jsonproduction_order_1));
	production_order_t* production_order_2 = production_order_parseFromJSON(jsonproduction_order_1);
	cJSON* jsonproduction_order_2 = production_order_convertToJSON(production_order_2);
	printf("repeating production_order:\n%s\n", cJSON_Print(jsonproduction_order_2));
}

int main() {
  test_production_order(1);
  test_production_order(0);

  printf("Hello world \n");
  return 0;
}

#endif // production_order_MAIN
#endif // production_order_TEST
