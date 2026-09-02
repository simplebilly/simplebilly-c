#ifndef revenue_item_TEST
#define revenue_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define revenue_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/revenue_item.h"
revenue_item_t* instantiate_revenue_item(int include_optional);



revenue_item_t* instantiate_revenue_item(int include_optional) {
  revenue_item_t* revenue_item = NULL;
  if (include_optional) {
    revenue_item = revenue_item_create(
      "0",
      "0",
      1.337
    );
  } else {
    revenue_item = revenue_item_create(
      "0",
      "0",
      1.337
    );
  }

  return revenue_item;
}


#ifdef revenue_item_MAIN

void test_revenue_item(int include_optional) {
    revenue_item_t* revenue_item_1 = instantiate_revenue_item(include_optional);

	cJSON* jsonrevenue_item_1 = revenue_item_convertToJSON(revenue_item_1);
	printf("revenue_item :\n%s\n", cJSON_Print(jsonrevenue_item_1));
	revenue_item_t* revenue_item_2 = revenue_item_parseFromJSON(jsonrevenue_item_1);
	cJSON* jsonrevenue_item_2 = revenue_item_convertToJSON(revenue_item_2);
	printf("repeating revenue_item:\n%s\n", cJSON_Print(jsonrevenue_item_2));
}

int main() {
  test_revenue_item(1);
  test_revenue_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // revenue_item_MAIN
#endif // revenue_item_TEST
