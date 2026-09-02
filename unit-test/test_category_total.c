#ifndef category_total_TEST
#define category_total_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define category_total_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/category_total.h"
category_total_t* instantiate_category_total(int include_optional);



category_total_t* instantiate_category_total(int include_optional) {
  category_total_t* category_total = NULL;
  if (include_optional) {
    category_total = category_total_create(
      "0",
      1.337,
      "0"
    );
  } else {
    category_total = category_total_create(
      "0",
      1.337,
      "0"
    );
  }

  return category_total;
}


#ifdef category_total_MAIN

void test_category_total(int include_optional) {
    category_total_t* category_total_1 = instantiate_category_total(include_optional);

	cJSON* jsoncategory_total_1 = category_total_convertToJSON(category_total_1);
	printf("category_total :\n%s\n", cJSON_Print(jsoncategory_total_1));
	category_total_t* category_total_2 = category_total_parseFromJSON(jsoncategory_total_1);
	cJSON* jsoncategory_total_2 = category_total_convertToJSON(category_total_2);
	printf("repeating category_total:\n%s\n", cJSON_Print(jsoncategory_total_2));
}

int main() {
  test_category_total(1);
  test_category_total(0);

  printf("Hello world \n");
  return 0;
}

#endif // category_total_MAIN
#endif // category_total_TEST
