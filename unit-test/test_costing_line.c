#ifndef costing_line_TEST
#define costing_line_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define costing_line_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/costing_line.h"
costing_line_t* instantiate_costing_line(int include_optional);



costing_line_t* instantiate_costing_line(int include_optional) {
  costing_line_t* costing_line = NULL;
  if (include_optional) {
    costing_line = costing_line_create(
      "0",
      "0",
      "0",
      56,
      "0",
      56,
      "0"
    );
  } else {
    costing_line = costing_line_create(
      "0",
      "0",
      "0",
      56,
      "0",
      56,
      "0"
    );
  }

  return costing_line;
}


#ifdef costing_line_MAIN

void test_costing_line(int include_optional) {
    costing_line_t* costing_line_1 = instantiate_costing_line(include_optional);

	cJSON* jsoncosting_line_1 = costing_line_convertToJSON(costing_line_1);
	printf("costing_line :\n%s\n", cJSON_Print(jsoncosting_line_1));
	costing_line_t* costing_line_2 = costing_line_parseFromJSON(jsoncosting_line_1);
	cJSON* jsoncosting_line_2 = costing_line_convertToJSON(costing_line_2);
	printf("repeating costing_line:\n%s\n", cJSON_Print(jsoncosting_line_2));
}

int main() {
  test_costing_line(1);
  test_costing_line(0);

  printf("Hello world \n");
  return 0;
}

#endif // costing_line_MAIN
#endif // costing_line_TEST
