#ifndef warehouse_create_TEST
#define warehouse_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define warehouse_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/warehouse_create.h"
warehouse_create_t* instantiate_warehouse_create(int include_optional);



warehouse_create_t* instantiate_warehouse_create(int include_optional) {
  warehouse_create_t* warehouse_create = NULL;
  if (include_optional) {
    warehouse_create = warehouse_create_create(
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
    warehouse_create = warehouse_create_create(
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

  return warehouse_create;
}


#ifdef warehouse_create_MAIN

void test_warehouse_create(int include_optional) {
    warehouse_create_t* warehouse_create_1 = instantiate_warehouse_create(include_optional);

	cJSON* jsonwarehouse_create_1 = warehouse_create_convertToJSON(warehouse_create_1);
	printf("warehouse_create :\n%s\n", cJSON_Print(jsonwarehouse_create_1));
	warehouse_create_t* warehouse_create_2 = warehouse_create_parseFromJSON(jsonwarehouse_create_1);
	cJSON* jsonwarehouse_create_2 = warehouse_create_convertToJSON(warehouse_create_2);
	printf("repeating warehouse_create:\n%s\n", cJSON_Print(jsonwarehouse_create_2));
}

int main() {
  test_warehouse_create(1);
  test_warehouse_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // warehouse_create_MAIN
#endif // warehouse_create_TEST
