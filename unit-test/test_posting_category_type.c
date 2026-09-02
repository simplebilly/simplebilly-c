#ifndef posting_category_type_TEST
#define posting_category_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define posting_category_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/posting_category_type.h"
posting_category_type_t* instantiate_posting_category_type(int include_optional);



posting_category_type_t* instantiate_posting_category_type(int include_optional) {
  posting_category_type_t* posting_category_type = NULL;
  if (include_optional) {
    posting_category_type = posting_category_type_create(
    );
  } else {
    posting_category_type = posting_category_type_create(
    );
  }

  return posting_category_type;
}


#ifdef posting_category_type_MAIN

void test_posting_category_type(int include_optional) {
    posting_category_type_t* posting_category_type_1 = instantiate_posting_category_type(include_optional);

	cJSON* jsonposting_category_type_1 = posting_category_type_convertToJSON(posting_category_type_1);
	printf("posting_category_type :\n%s\n", cJSON_Print(jsonposting_category_type_1));
	posting_category_type_t* posting_category_type_2 = posting_category_type_parseFromJSON(jsonposting_category_type_1);
	cJSON* jsonposting_category_type_2 = posting_category_type_convertToJSON(posting_category_type_2);
	printf("repeating posting_category_type:\n%s\n", cJSON_Print(jsonposting_category_type_2));
}

int main() {
  test_posting_category_type(1);
  test_posting_category_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // posting_category_type_MAIN
#endif // posting_category_type_TEST
