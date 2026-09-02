#ifndef bilanz_item_TEST
#define bilanz_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bilanz_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bilanz_item.h"
bilanz_item_t* instantiate_bilanz_item(int include_optional);



bilanz_item_t* instantiate_bilanz_item(int include_optional) {
  bilanz_item_t* bilanz_item = NULL;
  if (include_optional) {
    bilanz_item = bilanz_item_create(
      "0",
      "0",
      "0"
    );
  } else {
    bilanz_item = bilanz_item_create(
      "0",
      "0",
      "0"
    );
  }

  return bilanz_item;
}


#ifdef bilanz_item_MAIN

void test_bilanz_item(int include_optional) {
    bilanz_item_t* bilanz_item_1 = instantiate_bilanz_item(include_optional);

	cJSON* jsonbilanz_item_1 = bilanz_item_convertToJSON(bilanz_item_1);
	printf("bilanz_item :\n%s\n", cJSON_Print(jsonbilanz_item_1));
	bilanz_item_t* bilanz_item_2 = bilanz_item_parseFromJSON(jsonbilanz_item_1);
	cJSON* jsonbilanz_item_2 = bilanz_item_convertToJSON(bilanz_item_2);
	printf("repeating bilanz_item:\n%s\n", cJSON_Print(jsonbilanz_item_2));
}

int main() {
  test_bilanz_item(1);
  test_bilanz_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // bilanz_item_MAIN
#endif // bilanz_item_TEST
