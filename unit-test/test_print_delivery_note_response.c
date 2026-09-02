#ifndef print_delivery_note_response_TEST
#define print_delivery_note_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define print_delivery_note_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/print_delivery_note_response.h"
print_delivery_note_response_t* instantiate_print_delivery_note_response(int include_optional);



print_delivery_note_response_t* instantiate_print_delivery_note_response(int include_optional) {
  print_delivery_note_response_t* print_delivery_note_response = NULL;
  if (include_optional) {
    print_delivery_note_response = print_delivery_note_response_create(
      "0",
      "0",
      1
    );
  } else {
    print_delivery_note_response = print_delivery_note_response_create(
      "0",
      "0",
      1
    );
  }

  return print_delivery_note_response;
}


#ifdef print_delivery_note_response_MAIN

void test_print_delivery_note_response(int include_optional) {
    print_delivery_note_response_t* print_delivery_note_response_1 = instantiate_print_delivery_note_response(include_optional);

	cJSON* jsonprint_delivery_note_response_1 = print_delivery_note_response_convertToJSON(print_delivery_note_response_1);
	printf("print_delivery_note_response :\n%s\n", cJSON_Print(jsonprint_delivery_note_response_1));
	print_delivery_note_response_t* print_delivery_note_response_2 = print_delivery_note_response_parseFromJSON(jsonprint_delivery_note_response_1);
	cJSON* jsonprint_delivery_note_response_2 = print_delivery_note_response_convertToJSON(print_delivery_note_response_2);
	printf("repeating print_delivery_note_response:\n%s\n", cJSON_Print(jsonprint_delivery_note_response_2));
}

int main() {
  test_print_delivery_note_response(1);
  test_print_delivery_note_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // print_delivery_note_response_MAIN
#endif // print_delivery_note_response_TEST
