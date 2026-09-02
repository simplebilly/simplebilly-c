#ifndef order_confirmation_create_TEST
#define order_confirmation_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define order_confirmation_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/order_confirmation_create.h"
order_confirmation_create_t* instantiate_order_confirmation_create(int include_optional);



order_confirmation_create_t* instantiate_order_confirmation_create(int include_optional) {
  order_confirmation_create_t* order_confirmation_create = NULL;
  if (include_optional) {
    order_confirmation_create = order_confirmation_create_create(
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
      "2013-10-20",
      simplebilly_api_order_confirmation_create__open
    );
  } else {
    order_confirmation_create = order_confirmation_create_create(
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
      "2013-10-20",
      simplebilly_api_order_confirmation_create__open
    );
  }

  return order_confirmation_create;
}


#ifdef order_confirmation_create_MAIN

void test_order_confirmation_create(int include_optional) {
    order_confirmation_create_t* order_confirmation_create_1 = instantiate_order_confirmation_create(include_optional);

	cJSON* jsonorder_confirmation_create_1 = order_confirmation_create_convertToJSON(order_confirmation_create_1);
	printf("order_confirmation_create :\n%s\n", cJSON_Print(jsonorder_confirmation_create_1));
	order_confirmation_create_t* order_confirmation_create_2 = order_confirmation_create_parseFromJSON(jsonorder_confirmation_create_1);
	cJSON* jsonorder_confirmation_create_2 = order_confirmation_create_convertToJSON(order_confirmation_create_2);
	printf("repeating order_confirmation_create:\n%s\n", cJSON_Print(jsonorder_confirmation_create_2));
}

int main() {
  test_order_confirmation_create(1);
  test_order_confirmation_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // order_confirmation_create_MAIN
#endif // order_confirmation_create_TEST
