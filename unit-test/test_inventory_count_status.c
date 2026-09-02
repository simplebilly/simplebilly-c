#ifndef inventory_count_status_TEST
#define inventory_count_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define inventory_count_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/inventory_count_status.h"
inventory_count_status_t* instantiate_inventory_count_status(int include_optional);



inventory_count_status_t* instantiate_inventory_count_status(int include_optional) {
  inventory_count_status_t* inventory_count_status = NULL;
  if (include_optional) {
    inventory_count_status = inventory_count_status_create(
    );
  } else {
    inventory_count_status = inventory_count_status_create(
    );
  }

  return inventory_count_status;
}


#ifdef inventory_count_status_MAIN

void test_inventory_count_status(int include_optional) {
    inventory_count_status_t* inventory_count_status_1 = instantiate_inventory_count_status(include_optional);

	cJSON* jsoninventory_count_status_1 = inventory_count_status_convertToJSON(inventory_count_status_1);
	printf("inventory_count_status :\n%s\n", cJSON_Print(jsoninventory_count_status_1));
	inventory_count_status_t* inventory_count_status_2 = inventory_count_status_parseFromJSON(jsoninventory_count_status_1);
	cJSON* jsoninventory_count_status_2 = inventory_count_status_convertToJSON(inventory_count_status_2);
	printf("repeating inventory_count_status:\n%s\n", cJSON_Print(jsoninventory_count_status_2));
}

int main() {
  test_inventory_count_status(1);
  test_inventory_count_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // inventory_count_status_MAIN
#endif // inventory_count_status_TEST
