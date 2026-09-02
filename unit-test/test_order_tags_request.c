#ifndef order_tags_request_TEST
#define order_tags_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define order_tags_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/order_tags_request.h"
order_tags_request_t* instantiate_order_tags_request(int include_optional);



order_tags_request_t* instantiate_order_tags_request(int include_optional) {
  order_tags_request_t* order_tags_request = NULL;
  if (include_optional) {
    order_tags_request = order_tags_request_create(
      list_createList()
    );
  } else {
    order_tags_request = order_tags_request_create(
      list_createList()
    );
  }

  return order_tags_request;
}


#ifdef order_tags_request_MAIN

void test_order_tags_request(int include_optional) {
    order_tags_request_t* order_tags_request_1 = instantiate_order_tags_request(include_optional);

	cJSON* jsonorder_tags_request_1 = order_tags_request_convertToJSON(order_tags_request_1);
	printf("order_tags_request :\n%s\n", cJSON_Print(jsonorder_tags_request_1));
	order_tags_request_t* order_tags_request_2 = order_tags_request_parseFromJSON(jsonorder_tags_request_1);
	cJSON* jsonorder_tags_request_2 = order_tags_request_convertToJSON(order_tags_request_2);
	printf("repeating order_tags_request:\n%s\n", cJSON_Print(jsonorder_tags_request_2));
}

int main() {
  test_order_tags_request(1);
  test_order_tags_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // order_tags_request_MAIN
#endif // order_tags_request_TEST
