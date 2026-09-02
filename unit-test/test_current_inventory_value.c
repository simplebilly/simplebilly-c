#ifndef current_inventory_value_TEST
#define current_inventory_value_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define current_inventory_value_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/current_inventory_value.h"
current_inventory_value_t* instantiate_current_inventory_value(int include_optional);



current_inventory_value_t* instantiate_current_inventory_value(int include_optional) {
  current_inventory_value_t* current_inventory_value = NULL;
  if (include_optional) {
    current_inventory_value = current_inventory_value_create(
      list_createList(),
      56,
      "0",
      "0"
    );
  } else {
    current_inventory_value = current_inventory_value_create(
      list_createList(),
      56,
      "0",
      "0"
    );
  }

  return current_inventory_value;
}


#ifdef current_inventory_value_MAIN

void test_current_inventory_value(int include_optional) {
    current_inventory_value_t* current_inventory_value_1 = instantiate_current_inventory_value(include_optional);

	cJSON* jsoncurrent_inventory_value_1 = current_inventory_value_convertToJSON(current_inventory_value_1);
	printf("current_inventory_value :\n%s\n", cJSON_Print(jsoncurrent_inventory_value_1));
	current_inventory_value_t* current_inventory_value_2 = current_inventory_value_parseFromJSON(jsoncurrent_inventory_value_1);
	cJSON* jsoncurrent_inventory_value_2 = current_inventory_value_convertToJSON(current_inventory_value_2);
	printf("repeating current_inventory_value:\n%s\n", cJSON_Print(jsoncurrent_inventory_value_2));
}

int main() {
  test_current_inventory_value(1);
  test_current_inventory_value(0);

  printf("Hello world \n");
  return 0;
}

#endif // current_inventory_value_MAIN
#endif // current_inventory_value_TEST
