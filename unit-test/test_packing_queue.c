#ifndef packing_queue_TEST
#define packing_queue_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define packing_queue_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/packing_queue.h"
packing_queue_t* instantiate_packing_queue(int include_optional);



packing_queue_t* instantiate_packing_queue(int include_optional) {
  packing_queue_t* packing_queue = NULL;
  if (include_optional) {
    packing_queue = packing_queue_create(
      list_createList(),
      0,
      0,
      0
    );
  } else {
    packing_queue = packing_queue_create(
      list_createList(),
      0,
      0,
      0
    );
  }

  return packing_queue;
}


#ifdef packing_queue_MAIN

void test_packing_queue(int include_optional) {
    packing_queue_t* packing_queue_1 = instantiate_packing_queue(include_optional);

	cJSON* jsonpacking_queue_1 = packing_queue_convertToJSON(packing_queue_1);
	printf("packing_queue :\n%s\n", cJSON_Print(jsonpacking_queue_1));
	packing_queue_t* packing_queue_2 = packing_queue_parseFromJSON(jsonpacking_queue_1);
	cJSON* jsonpacking_queue_2 = packing_queue_convertToJSON(packing_queue_2);
	printf("repeating packing_queue:\n%s\n", cJSON_Print(jsonpacking_queue_2));
}

int main() {
  test_packing_queue(1);
  test_packing_queue(0);

  printf("Hello world \n");
  return 0;
}

#endif // packing_queue_MAIN
#endif // packing_queue_TEST
