#ifndef inventory_value_point_TEST
#define inventory_value_point_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define inventory_value_point_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/inventory_value_point.h"
inventory_value_point_t* instantiate_inventory_value_point(int include_optional);



inventory_value_point_t* instantiate_inventory_value_point(int include_optional) {
  inventory_value_point_t* inventory_value_point = NULL;
  if (include_optional) {
    inventory_value_point = inventory_value_point_create(
      56,
      "2013-10-20T19:20:30+01:00",
      "0",
      "0"
    );
  } else {
    inventory_value_point = inventory_value_point_create(
      56,
      "2013-10-20T19:20:30+01:00",
      "0",
      "0"
    );
  }

  return inventory_value_point;
}


#ifdef inventory_value_point_MAIN

void test_inventory_value_point(int include_optional) {
    inventory_value_point_t* inventory_value_point_1 = instantiate_inventory_value_point(include_optional);

	cJSON* jsoninventory_value_point_1 = inventory_value_point_convertToJSON(inventory_value_point_1);
	printf("inventory_value_point :\n%s\n", cJSON_Print(jsoninventory_value_point_1));
	inventory_value_point_t* inventory_value_point_2 = inventory_value_point_parseFromJSON(jsoninventory_value_point_1);
	cJSON* jsoninventory_value_point_2 = inventory_value_point_convertToJSON(inventory_value_point_2);
	printf("repeating inventory_value_point:\n%s\n", cJSON_Print(jsoninventory_value_point_2));
}

int main() {
  test_inventory_value_point(1);
  test_inventory_value_point(0);

  printf("Hello world \n");
  return 0;
}

#endif // inventory_value_point_MAIN
#endif // inventory_value_point_TEST
