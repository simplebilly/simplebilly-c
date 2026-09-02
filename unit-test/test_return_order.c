#ifndef return_order_TEST
#define return_order_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define return_order_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/return_order.h"
return_order_t* instantiate_return_order(int include_optional);



return_order_t* instantiate_return_order(int include_optional) {
  return_order_t* return_order = NULL;
  if (include_optional) {
    return_order = return_order_create(
      "0",
      "0",
      null,
      "0",
      "0",
      "0",
      "0",
      "0",
      requested,
      "0"
    );
  } else {
    return_order = return_order_create(
      "0",
      "0",
      null,
      "0",
      "0",
      "0",
      "0",
      "0",
      requested,
      "0"
    );
  }

  return return_order;
}


#ifdef return_order_MAIN

void test_return_order(int include_optional) {
    return_order_t* return_order_1 = instantiate_return_order(include_optional);

	cJSON* jsonreturn_order_1 = return_order_convertToJSON(return_order_1);
	printf("return_order :\n%s\n", cJSON_Print(jsonreturn_order_1));
	return_order_t* return_order_2 = return_order_parseFromJSON(jsonreturn_order_1);
	cJSON* jsonreturn_order_2 = return_order_convertToJSON(return_order_2);
	printf("repeating return_order:\n%s\n", cJSON_Print(jsonreturn_order_2));
}

int main() {
  test_return_order(1);
  test_return_order(0);

  printf("Hello world \n");
  return 0;
}

#endif // return_order_MAIN
#endif // return_order_TEST
