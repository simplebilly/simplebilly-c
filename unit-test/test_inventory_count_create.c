#ifndef inventory_count_create_TEST
#define inventory_count_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define inventory_count_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/inventory_count_create.h"
inventory_count_create_t* instantiate_inventory_count_create(int include_optional);



inventory_count_create_t* instantiate_inventory_count_create(int include_optional) {
  inventory_count_create_t* inventory_count_create = NULL;
  if (include_optional) {
    inventory_count_create = inventory_count_create_create(
      "2013-10-20",
      "0",
      null,
      "0",
      draft,
      "0"
    );
  } else {
    inventory_count_create = inventory_count_create_create(
      "2013-10-20",
      "0",
      null,
      "0",
      draft,
      "0"
    );
  }

  return inventory_count_create;
}


#ifdef inventory_count_create_MAIN

void test_inventory_count_create(int include_optional) {
    inventory_count_create_t* inventory_count_create_1 = instantiate_inventory_count_create(include_optional);

	cJSON* jsoninventory_count_create_1 = inventory_count_create_convertToJSON(inventory_count_create_1);
	printf("inventory_count_create :\n%s\n", cJSON_Print(jsoninventory_count_create_1));
	inventory_count_create_t* inventory_count_create_2 = inventory_count_create_parseFromJSON(jsoninventory_count_create_1);
	cJSON* jsoninventory_count_create_2 = inventory_count_create_convertToJSON(inventory_count_create_2);
	printf("repeating inventory_count_create:\n%s\n", cJSON_Print(jsoninventory_count_create_2));
}

int main() {
  test_inventory_count_create(1);
  test_inventory_count_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // inventory_count_create_MAIN
#endif // inventory_count_create_TEST
