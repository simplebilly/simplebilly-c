#ifndef order_create_TEST
#define order_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define order_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/order_create.h"
order_create_t* instantiate_order_create(int include_optional);



order_create_t* instantiate_order_create(int include_optional) {
  order_create_t* order_create = NULL;
  if (include_optional) {
    order_create = order_create_create(
      null,
      "0",
      "0",
      "0",
      null,
      null,
      simplebilly_api_order_create__DE,
      simplebilly_api_order_create__pending,
      simplebilly_api_order_create__bank_transfer,
      null,
      "0",
      "0",
      "0",
      list_createList(),
      "0"
    );
  } else {
    order_create = order_create_create(
      null,
      "0",
      "0",
      "0",
      null,
      null,
      simplebilly_api_order_create__DE,
      simplebilly_api_order_create__pending,
      simplebilly_api_order_create__bank_transfer,
      null,
      "0",
      "0",
      "0",
      list_createList(),
      "0"
    );
  }

  return order_create;
}


#ifdef order_create_MAIN

void test_order_create(int include_optional) {
    order_create_t* order_create_1 = instantiate_order_create(include_optional);

	cJSON* jsonorder_create_1 = order_create_convertToJSON(order_create_1);
	printf("order_create :\n%s\n", cJSON_Print(jsonorder_create_1));
	order_create_t* order_create_2 = order_create_parseFromJSON(jsonorder_create_1);
	cJSON* jsonorder_create_2 = order_create_convertToJSON(order_create_2);
	printf("repeating order_create:\n%s\n", cJSON_Print(jsonorder_create_2));
}

int main() {
  test_order_create(1);
  test_order_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // order_create_MAIN
#endif // order_create_TEST
