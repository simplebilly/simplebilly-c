#ifndef inventory_count_update_TEST
#define inventory_count_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define inventory_count_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/inventory_count_update.h"
inventory_count_update_t* instantiate_inventory_count_update(int include_optional);



inventory_count_update_t* instantiate_inventory_count_update(int include_optional) {
  inventory_count_update_t* inventory_count_update = NULL;
  if (include_optional) {
    inventory_count_update = inventory_count_update_create(
      "2013-10-20",
      "0",
      null,
      "0",
      draft,
      "0"
    );
  } else {
    inventory_count_update = inventory_count_update_create(
      "2013-10-20",
      "0",
      null,
      "0",
      draft,
      "0"
    );
  }

  return inventory_count_update;
}


#ifdef inventory_count_update_MAIN

void test_inventory_count_update(int include_optional) {
    inventory_count_update_t* inventory_count_update_1 = instantiate_inventory_count_update(include_optional);

	cJSON* jsoninventory_count_update_1 = inventory_count_update_convertToJSON(inventory_count_update_1);
	printf("inventory_count_update :\n%s\n", cJSON_Print(jsoninventory_count_update_1));
	inventory_count_update_t* inventory_count_update_2 = inventory_count_update_parseFromJSON(jsoninventory_count_update_1);
	cJSON* jsoninventory_count_update_2 = inventory_count_update_convertToJSON(inventory_count_update_2);
	printf("repeating inventory_count_update:\n%s\n", cJSON_Print(jsoninventory_count_update_2));
}

int main() {
  test_inventory_count_update(1);
  test_inventory_count_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // inventory_count_update_MAIN
#endif // inventory_count_update_TEST
