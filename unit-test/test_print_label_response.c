#ifndef print_label_response_TEST
#define print_label_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define print_label_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/print_label_response.h"
print_label_response_t* instantiate_print_label_response(int include_optional);



print_label_response_t* instantiate_print_label_response(int include_optional) {
  print_label_response_t* print_label_response = NULL;
  if (include_optional) {
    print_label_response = print_label_response_create(
      "0",
      "0",
      "0",
      1,
      "0"
    );
  } else {
    print_label_response = print_label_response_create(
      "0",
      "0",
      "0",
      1,
      "0"
    );
  }

  return print_label_response;
}


#ifdef print_label_response_MAIN

void test_print_label_response(int include_optional) {
    print_label_response_t* print_label_response_1 = instantiate_print_label_response(include_optional);

	cJSON* jsonprint_label_response_1 = print_label_response_convertToJSON(print_label_response_1);
	printf("print_label_response :\n%s\n", cJSON_Print(jsonprint_label_response_1));
	print_label_response_t* print_label_response_2 = print_label_response_parseFromJSON(jsonprint_label_response_1);
	cJSON* jsonprint_label_response_2 = print_label_response_convertToJSON(print_label_response_2);
	printf("repeating print_label_response:\n%s\n", cJSON_Print(jsonprint_label_response_2));
}

int main() {
  test_print_label_response(1);
  test_print_label_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // print_label_response_MAIN
#endif // print_label_response_TEST
