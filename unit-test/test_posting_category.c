#ifndef posting_category_TEST
#define posting_category_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define posting_category_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/posting_category.h"
posting_category_t* instantiate_posting_category(int include_optional);



posting_category_t* instantiate_posting_category(int include_optional) {
  posting_category_t* posting_category = NULL;
  if (include_optional) {
    posting_category = posting_category_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      56,
      "0",
      "0",
      1,
      1,
      "0",
      "0",
      "0"
    );
  } else {
    posting_category = posting_category_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      56,
      "0",
      "0",
      1,
      1,
      "0",
      "0",
      "0"
    );
  }

  return posting_category;
}


#ifdef posting_category_MAIN

void test_posting_category(int include_optional) {
    posting_category_t* posting_category_1 = instantiate_posting_category(include_optional);

	cJSON* jsonposting_category_1 = posting_category_convertToJSON(posting_category_1);
	printf("posting_category :\n%s\n", cJSON_Print(jsonposting_category_1));
	posting_category_t* posting_category_2 = posting_category_parseFromJSON(jsonposting_category_1);
	cJSON* jsonposting_category_2 = posting_category_convertToJSON(posting_category_2);
	printf("repeating posting_category:\n%s\n", cJSON_Print(jsonposting_category_2));
}

int main() {
  test_posting_category(1);
  test_posting_category(0);

  printf("Hello world \n");
  return 0;
}

#endif // posting_category_MAIN
#endif // posting_category_TEST
