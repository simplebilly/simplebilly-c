#ifndef warehouse_update_TEST
#define warehouse_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define warehouse_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/warehouse_update.h"
warehouse_update_t* instantiate_warehouse_update(int include_optional);



warehouse_update_t* instantiate_warehouse_update(int include_optional) {
  warehouse_update_t* warehouse_update = NULL;
  if (include_optional) {
    warehouse_update = warehouse_update_create(
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
    warehouse_update = warehouse_update_create(
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

  return warehouse_update;
}


#ifdef warehouse_update_MAIN

void test_warehouse_update(int include_optional) {
    warehouse_update_t* warehouse_update_1 = instantiate_warehouse_update(include_optional);

	cJSON* jsonwarehouse_update_1 = warehouse_update_convertToJSON(warehouse_update_1);
	printf("warehouse_update :\n%s\n", cJSON_Print(jsonwarehouse_update_1));
	warehouse_update_t* warehouse_update_2 = warehouse_update_parseFromJSON(jsonwarehouse_update_1);
	cJSON* jsonwarehouse_update_2 = warehouse_update_convertToJSON(warehouse_update_2);
	printf("repeating warehouse_update:\n%s\n", cJSON_Print(jsonwarehouse_update_2));
}

int main() {
  test_warehouse_update(1);
  test_warehouse_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // warehouse_update_MAIN
#endif // warehouse_update_TEST
