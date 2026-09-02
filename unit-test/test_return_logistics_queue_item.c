#ifndef return_logistics_queue_item_TEST
#define return_logistics_queue_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define return_logistics_queue_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/return_logistics_queue_item.h"
return_logistics_queue_item_t* instantiate_return_logistics_queue_item(int include_optional);



return_logistics_queue_item_t* instantiate_return_logistics_queue_item(int include_optional) {
  return_logistics_queue_item_t* return_logistics_queue_item = NULL;
  if (include_optional) {
    return_logistics_queue_item = return_logistics_queue_item_create(
      56,
      "2013-10-20T19:20:30+01:00",
      "0",
      null,
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    return_logistics_queue_item = return_logistics_queue_item_create(
      56,
      "2013-10-20T19:20:30+01:00",
      "0",
      null,
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return return_logistics_queue_item;
}


#ifdef return_logistics_queue_item_MAIN

void test_return_logistics_queue_item(int include_optional) {
    return_logistics_queue_item_t* return_logistics_queue_item_1 = instantiate_return_logistics_queue_item(include_optional);

	cJSON* jsonreturn_logistics_queue_item_1 = return_logistics_queue_item_convertToJSON(return_logistics_queue_item_1);
	printf("return_logistics_queue_item :\n%s\n", cJSON_Print(jsonreturn_logistics_queue_item_1));
	return_logistics_queue_item_t* return_logistics_queue_item_2 = return_logistics_queue_item_parseFromJSON(jsonreturn_logistics_queue_item_1);
	cJSON* jsonreturn_logistics_queue_item_2 = return_logistics_queue_item_convertToJSON(return_logistics_queue_item_2);
	printf("repeating return_logistics_queue_item:\n%s\n", cJSON_Print(jsonreturn_logistics_queue_item_2));
}

int main() {
  test_return_logistics_queue_item(1);
  test_return_logistics_queue_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // return_logistics_queue_item_MAIN
#endif // return_logistics_queue_item_TEST
