#ifndef warehouse_TEST
#define warehouse_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define warehouse_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/warehouse.h"
warehouse_t* instantiate_warehouse(int include_optional);



warehouse_t* instantiate_warehouse(int include_optional) {
  warehouse_t* warehouse = NULL;
  if (include_optional) {
    warehouse = warehouse_create(
      "0",
      ABW,
      "0",
      "0",
      null,
      "0",
      1,
      1,
      "0",
      "0"
    );
  } else {
    warehouse = warehouse_create(
      "0",
      ABW,
      "0",
      "0",
      null,
      "0",
      1,
      1,
      "0",
      "0"
    );
  }

  return warehouse;
}


#ifdef warehouse_MAIN

void test_warehouse(int include_optional) {
    warehouse_t* warehouse_1 = instantiate_warehouse(include_optional);

	cJSON* jsonwarehouse_1 = warehouse_convertToJSON(warehouse_1);
	printf("warehouse :\n%s\n", cJSON_Print(jsonwarehouse_1));
	warehouse_t* warehouse_2 = warehouse_parseFromJSON(jsonwarehouse_1);
	cJSON* jsonwarehouse_2 = warehouse_convertToJSON(warehouse_2);
	printf("repeating warehouse:\n%s\n", cJSON_Print(jsonwarehouse_2));
}

int main() {
  test_warehouse(1);
  test_warehouse(0);

  printf("Hello world \n");
  return 0;
}

#endif // warehouse_MAIN
#endif // warehouse_TEST
