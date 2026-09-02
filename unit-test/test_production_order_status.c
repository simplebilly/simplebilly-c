#ifndef production_order_status_TEST
#define production_order_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define production_order_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/production_order_status.h"
production_order_status_t* instantiate_production_order_status(int include_optional);



production_order_status_t* instantiate_production_order_status(int include_optional) {
  production_order_status_t* production_order_status = NULL;
  if (include_optional) {
    production_order_status = production_order_status_create(
    );
  } else {
    production_order_status = production_order_status_create(
    );
  }

  return production_order_status;
}


#ifdef production_order_status_MAIN

void test_production_order_status(int include_optional) {
    production_order_status_t* production_order_status_1 = instantiate_production_order_status(include_optional);

	cJSON* jsonproduction_order_status_1 = production_order_status_convertToJSON(production_order_status_1);
	printf("production_order_status :\n%s\n", cJSON_Print(jsonproduction_order_status_1));
	production_order_status_t* production_order_status_2 = production_order_status_parseFromJSON(jsonproduction_order_status_1);
	cJSON* jsonproduction_order_status_2 = production_order_status_convertToJSON(production_order_status_2);
	printf("repeating production_order_status:\n%s\n", cJSON_Print(jsonproduction_order_status_2));
}

int main() {
  test_production_order_status(1);
  test_production_order_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // production_order_status_MAIN
#endif // production_order_status_TEST
