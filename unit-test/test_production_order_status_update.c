#ifndef production_order_status_update_TEST
#define production_order_status_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define production_order_status_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/production_order_status_update.h"
production_order_status_update_t* instantiate_production_order_status_update(int include_optional);



production_order_status_update_t* instantiate_production_order_status_update(int include_optional) {
  production_order_status_update_t* production_order_status_update = NULL;
  if (include_optional) {
    production_order_status_update = production_order_status_update_create(
      "0"
    );
  } else {
    production_order_status_update = production_order_status_update_create(
      "0"
    );
  }

  return production_order_status_update;
}


#ifdef production_order_status_update_MAIN

void test_production_order_status_update(int include_optional) {
    production_order_status_update_t* production_order_status_update_1 = instantiate_production_order_status_update(include_optional);

	cJSON* jsonproduction_order_status_update_1 = production_order_status_update_convertToJSON(production_order_status_update_1);
	printf("production_order_status_update :\n%s\n", cJSON_Print(jsonproduction_order_status_update_1));
	production_order_status_update_t* production_order_status_update_2 = production_order_status_update_parseFromJSON(jsonproduction_order_status_update_1);
	cJSON* jsonproduction_order_status_update_2 = production_order_status_update_convertToJSON(production_order_status_update_2);
	printf("repeating production_order_status_update:\n%s\n", cJSON_Print(jsonproduction_order_status_update_2));
}

int main() {
  test_production_order_status_update(1);
  test_production_order_status_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // production_order_status_update_MAIN
#endif // production_order_status_update_TEST
