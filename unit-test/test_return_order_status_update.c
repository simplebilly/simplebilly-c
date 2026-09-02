#ifndef return_order_status_update_TEST
#define return_order_status_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define return_order_status_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/return_order_status_update.h"
return_order_status_update_t* instantiate_return_order_status_update(int include_optional);



return_order_status_update_t* instantiate_return_order_status_update(int include_optional) {
  return_order_status_update_t* return_order_status_update = NULL;
  if (include_optional) {
    return_order_status_update = return_order_status_update_create(
      "0"
    );
  } else {
    return_order_status_update = return_order_status_update_create(
      "0"
    );
  }

  return return_order_status_update;
}


#ifdef return_order_status_update_MAIN

void test_return_order_status_update(int include_optional) {
    return_order_status_update_t* return_order_status_update_1 = instantiate_return_order_status_update(include_optional);

	cJSON* jsonreturn_order_status_update_1 = return_order_status_update_convertToJSON(return_order_status_update_1);
	printf("return_order_status_update :\n%s\n", cJSON_Print(jsonreturn_order_status_update_1));
	return_order_status_update_t* return_order_status_update_2 = return_order_status_update_parseFromJSON(jsonreturn_order_status_update_1);
	cJSON* jsonreturn_order_status_update_2 = return_order_status_update_convertToJSON(return_order_status_update_2);
	printf("repeating return_order_status_update:\n%s\n", cJSON_Print(jsonreturn_order_status_update_2));
}

int main() {
  test_return_order_status_update(1);
  test_return_order_status_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // return_order_status_update_MAIN
#endif // return_order_status_update_TEST
