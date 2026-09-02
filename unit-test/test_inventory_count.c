#ifndef inventory_count_TEST
#define inventory_count_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define inventory_count_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/inventory_count.h"
inventory_count_t* instantiate_inventory_count(int include_optional);



inventory_count_t* instantiate_inventory_count(int include_optional) {
  inventory_count_t* inventory_count = NULL;
  if (include_optional) {
    inventory_count = inventory_count_create(
      "2013-10-20",
      "0",
      null,
      "0",
      draft,
      "0"
    );
  } else {
    inventory_count = inventory_count_create(
      "2013-10-20",
      "0",
      null,
      "0",
      draft,
      "0"
    );
  }

  return inventory_count;
}


#ifdef inventory_count_MAIN

void test_inventory_count(int include_optional) {
    inventory_count_t* inventory_count_1 = instantiate_inventory_count(include_optional);

	cJSON* jsoninventory_count_1 = inventory_count_convertToJSON(inventory_count_1);
	printf("inventory_count :\n%s\n", cJSON_Print(jsoninventory_count_1));
	inventory_count_t* inventory_count_2 = inventory_count_parseFromJSON(jsoninventory_count_1);
	cJSON* jsoninventory_count_2 = inventory_count_convertToJSON(inventory_count_2);
	printf("repeating inventory_count:\n%s\n", cJSON_Print(jsoninventory_count_2));
}

int main() {
  test_inventory_count(1);
  test_inventory_count(0);

  printf("Hello world \n");
  return 0;
}

#endif // inventory_count_MAIN
#endif // inventory_count_TEST
