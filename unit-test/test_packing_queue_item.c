#ifndef packing_queue_item_TEST
#define packing_queue_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define packing_queue_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/packing_queue_item.h"
packing_queue_item_t* instantiate_packing_queue_item(int include_optional);



packing_queue_item_t* instantiate_packing_queue_item(int include_optional) {
  packing_queue_item_t* packing_queue_item = NULL;
  if (include_optional) {
    packing_queue_item = packing_queue_item_create(
      "0",
      "0",
      1,
      null,
      56,
      1,
      "0",
      "0",
      "0",
      null,
      "0",
      "0",
      "0"
    );
  } else {
    packing_queue_item = packing_queue_item_create(
      "0",
      "0",
      1,
      null,
      56,
      1,
      "0",
      "0",
      "0",
      null,
      "0",
      "0",
      "0"
    );
  }

  return packing_queue_item;
}


#ifdef packing_queue_item_MAIN

void test_packing_queue_item(int include_optional) {
    packing_queue_item_t* packing_queue_item_1 = instantiate_packing_queue_item(include_optional);

	cJSON* jsonpacking_queue_item_1 = packing_queue_item_convertToJSON(packing_queue_item_1);
	printf("packing_queue_item :\n%s\n", cJSON_Print(jsonpacking_queue_item_1));
	packing_queue_item_t* packing_queue_item_2 = packing_queue_item_parseFromJSON(jsonpacking_queue_item_1);
	cJSON* jsonpacking_queue_item_2 = packing_queue_item_convertToJSON(packing_queue_item_2);
	printf("repeating packing_queue_item:\n%s\n", cJSON_Print(jsonpacking_queue_item_2));
}

int main() {
  test_packing_queue_item(1);
  test_packing_queue_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // packing_queue_item_MAIN
#endif // packing_queue_item_TEST
