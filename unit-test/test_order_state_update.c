#ifndef order_state_update_TEST
#define order_state_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define order_state_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/order_state_update.h"
order_state_update_t* instantiate_order_state_update(int include_optional);



order_state_update_t* instantiate_order_state_update(int include_optional) {
  order_state_update_t* order_state_update = NULL;
  if (include_optional) {
    order_state_update = order_state_update_create(
      1,
      "0"
    );
  } else {
    order_state_update = order_state_update_create(
      1,
      "0"
    );
  }

  return order_state_update;
}


#ifdef order_state_update_MAIN

void test_order_state_update(int include_optional) {
    order_state_update_t* order_state_update_1 = instantiate_order_state_update(include_optional);

	cJSON* jsonorder_state_update_1 = order_state_update_convertToJSON(order_state_update_1);
	printf("order_state_update :\n%s\n", cJSON_Print(jsonorder_state_update_1));
	order_state_update_t* order_state_update_2 = order_state_update_parseFromJSON(jsonorder_state_update_1);
	cJSON* jsonorder_state_update_2 = order_state_update_convertToJSON(order_state_update_2);
	printf("repeating order_state_update:\n%s\n", cJSON_Print(jsonorder_state_update_2));
}

int main() {
  test_order_state_update(1);
  test_order_state_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // order_state_update_MAIN
#endif // order_state_update_TEST
