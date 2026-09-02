#ifndef posting_category_create_TEST
#define posting_category_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define posting_category_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/posting_category_create.h"
posting_category_create_t* instantiate_posting_category_create(int include_optional);



posting_category_create_t* instantiate_posting_category_create(int include_optional) {
  posting_category_create_t* posting_category_create = NULL;
  if (include_optional) {
    posting_category_create = posting_category_create_create(
      "0",
      "0",
      "0",
      "0",
      simplebilly_api_posting_category_create__income,
      "2013-10-20T19:20:30+01:00",
      56,
      "0",
      "0",
      56,
      "0",
      1,
      1,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      1,
      1
    );
  } else {
    posting_category_create = posting_category_create_create(
      "0",
      "0",
      "0",
      "0",
      simplebilly_api_posting_category_create__income,
      "2013-10-20T19:20:30+01:00",
      56,
      "0",
      "0",
      56,
      "0",
      1,
      1,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      1,
      1
    );
  }

  return posting_category_create;
}


#ifdef posting_category_create_MAIN

void test_posting_category_create(int include_optional) {
    posting_category_create_t* posting_category_create_1 = instantiate_posting_category_create(include_optional);

	cJSON* jsonposting_category_create_1 = posting_category_create_convertToJSON(posting_category_create_1);
	printf("posting_category_create :\n%s\n", cJSON_Print(jsonposting_category_create_1));
	posting_category_create_t* posting_category_create_2 = posting_category_create_parseFromJSON(jsonposting_category_create_1);
	cJSON* jsonposting_category_create_2 = posting_category_create_convertToJSON(posting_category_create_2);
	printf("repeating posting_category_create:\n%s\n", cJSON_Print(jsonposting_category_create_2));
}

int main() {
  test_posting_category_create(1);
  test_posting_category_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // posting_category_create_MAIN
#endif // posting_category_create_TEST
