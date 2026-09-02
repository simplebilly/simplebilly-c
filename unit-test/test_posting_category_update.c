#ifndef posting_category_update_TEST
#define posting_category_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define posting_category_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/posting_category_update.h"
posting_category_update_t* instantiate_posting_category_update(int include_optional);



posting_category_update_t* instantiate_posting_category_update(int include_optional) {
  posting_category_update_t* posting_category_update = NULL;
  if (include_optional) {
    posting_category_update = posting_category_update_create(
      "0",
      "0",
      "0",
      "0",
      income,
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
    posting_category_update = posting_category_update_create(
      "0",
      "0",
      "0",
      "0",
      income,
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

  return posting_category_update;
}


#ifdef posting_category_update_MAIN

void test_posting_category_update(int include_optional) {
    posting_category_update_t* posting_category_update_1 = instantiate_posting_category_update(include_optional);

	cJSON* jsonposting_category_update_1 = posting_category_update_convertToJSON(posting_category_update_1);
	printf("posting_category_update :\n%s\n", cJSON_Print(jsonposting_category_update_1));
	posting_category_update_t* posting_category_update_2 = posting_category_update_parseFromJSON(jsonposting_category_update_1);
	cJSON* jsonposting_category_update_2 = posting_category_update_convertToJSON(posting_category_update_2);
	printf("repeating posting_category_update:\n%s\n", cJSON_Print(jsonposting_category_update_2));
}

int main() {
  test_posting_category_update(1);
  test_posting_category_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // posting_category_update_MAIN
#endif // posting_category_update_TEST
