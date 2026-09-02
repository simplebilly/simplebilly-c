#ifndef open_item_TEST
#define open_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define open_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/open_item.h"
open_item_t* instantiate_open_item(int include_optional);



open_item_t* instantiate_open_item(int include_optional) {
  open_item_t* open_item = NULL;
  if (include_optional) {
    open_item = open_item_create(
      "0",
      "0",
      "0",
      56,
      "0",
      "0",
      "0",
      "0",
      "0",
      simplebilly_api_open_item__none
    );
  } else {
    open_item = open_item_create(
      "0",
      "0",
      "0",
      56,
      "0",
      "0",
      "0",
      "0",
      "0",
      simplebilly_api_open_item__none
    );
  }

  return open_item;
}


#ifdef open_item_MAIN

void test_open_item(int include_optional) {
    open_item_t* open_item_1 = instantiate_open_item(include_optional);

	cJSON* jsonopen_item_1 = open_item_convertToJSON(open_item_1);
	printf("open_item :\n%s\n", cJSON_Print(jsonopen_item_1));
	open_item_t* open_item_2 = open_item_parseFromJSON(jsonopen_item_1);
	cJSON* jsonopen_item_2 = open_item_convertToJSON(open_item_2);
	printf("repeating open_item:\n%s\n", cJSON_Print(jsonopen_item_2));
}

int main() {
  test_open_item(1);
  test_open_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // open_item_MAIN
#endif // open_item_TEST
