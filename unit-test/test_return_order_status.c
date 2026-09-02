#ifndef return_order_status_TEST
#define return_order_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define return_order_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/return_order_status.h"
return_order_status_t* instantiate_return_order_status(int include_optional);



return_order_status_t* instantiate_return_order_status(int include_optional) {
  return_order_status_t* return_order_status = NULL;
  if (include_optional) {
    return_order_status = return_order_status_create(
    );
  } else {
    return_order_status = return_order_status_create(
    );
  }

  return return_order_status;
}


#ifdef return_order_status_MAIN

void test_return_order_status(int include_optional) {
    return_order_status_t* return_order_status_1 = instantiate_return_order_status(include_optional);

	cJSON* jsonreturn_order_status_1 = return_order_status_convertToJSON(return_order_status_1);
	printf("return_order_status :\n%s\n", cJSON_Print(jsonreturn_order_status_1));
	return_order_status_t* return_order_status_2 = return_order_status_parseFromJSON(jsonreturn_order_status_1);
	cJSON* jsonreturn_order_status_2 = return_order_status_convertToJSON(return_order_status_2);
	printf("repeating return_order_status:\n%s\n", cJSON_Print(jsonreturn_order_status_2));
}

int main() {
  test_return_order_status(1);
  test_return_order_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // return_order_status_MAIN
#endif // return_order_status_TEST
