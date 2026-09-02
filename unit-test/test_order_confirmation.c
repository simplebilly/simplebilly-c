#ifndef order_confirmation_TEST
#define order_confirmation_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define order_confirmation_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/order_confirmation.h"
order_confirmation_t* instantiate_order_confirmation(int include_optional);



order_confirmation_t* instantiate_order_confirmation(int include_optional) {
  order_confirmation_t* order_confirmation = NULL;
  if (include_optional) {
    order_confirmation = order_confirmation_create(
      null,
      "0",
      "0",
      "0",
      "0",
      null,
      "0",
      null,
      "0",
      order_confirmation,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20",
      simplebilly_api_order_confirmation__open
    );
  } else {
    order_confirmation = order_confirmation_create(
      null,
      "0",
      "0",
      "0",
      "0",
      null,
      "0",
      null,
      "0",
      order_confirmation,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20",
      simplebilly_api_order_confirmation__open
    );
  }

  return order_confirmation;
}


#ifdef order_confirmation_MAIN

void test_order_confirmation(int include_optional) {
    order_confirmation_t* order_confirmation_1 = instantiate_order_confirmation(include_optional);

	cJSON* jsonorder_confirmation_1 = order_confirmation_convertToJSON(order_confirmation_1);
	printf("order_confirmation :\n%s\n", cJSON_Print(jsonorder_confirmation_1));
	order_confirmation_t* order_confirmation_2 = order_confirmation_parseFromJSON(jsonorder_confirmation_1);
	cJSON* jsonorder_confirmation_2 = order_confirmation_convertToJSON(order_confirmation_2);
	printf("repeating order_confirmation:\n%s\n", cJSON_Print(jsonorder_confirmation_2));
}

int main() {
  test_order_confirmation(1);
  test_order_confirmation(0);

  printf("Hello world \n");
  return 0;
}

#endif // order_confirmation_MAIN
#endif // order_confirmation_TEST
