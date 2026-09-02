#ifndef order_update_TEST
#define order_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define order_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/order_update.h"
order_update_t* instantiate_order_update(int include_optional);



order_update_t* instantiate_order_update(int include_optional) {
  order_update_t* order_update = NULL;
  if (include_optional) {
    order_update = order_update_create(
      null,
      "0",
      "0",
      "0",
      null,
      null,
      DE,
      pending,
      bank_transfer,
      null,
      "0",
      "0",
      "0",
      list_createList(),
      "0"
    );
  } else {
    order_update = order_update_create(
      null,
      "0",
      "0",
      "0",
      null,
      null,
      DE,
      pending,
      bank_transfer,
      null,
      "0",
      "0",
      "0",
      list_createList(),
      "0"
    );
  }

  return order_update;
}


#ifdef order_update_MAIN

void test_order_update(int include_optional) {
    order_update_t* order_update_1 = instantiate_order_update(include_optional);

	cJSON* jsonorder_update_1 = order_update_convertToJSON(order_update_1);
	printf("order_update :\n%s\n", cJSON_Print(jsonorder_update_1));
	order_update_t* order_update_2 = order_update_parseFromJSON(jsonorder_update_1);
	cJSON* jsonorder_update_2 = order_update_convertToJSON(order_update_2);
	printf("repeating order_update:\n%s\n", cJSON_Print(jsonorder_update_2));
}

int main() {
  test_order_update(1);
  test_order_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // order_update_MAIN
#endif // order_update_TEST
