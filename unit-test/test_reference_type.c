#ifndef reference_type_TEST
#define reference_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reference_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reference_type.h"
reference_type_t* instantiate_reference_type(int include_optional);



reference_type_t* instantiate_reference_type(int include_optional) {
  reference_type_t* reference_type = NULL;
  if (include_optional) {
    reference_type = reference_type_create(
    );
  } else {
    reference_type = reference_type_create(
    );
  }

  return reference_type;
}


#ifdef reference_type_MAIN

void test_reference_type(int include_optional) {
    reference_type_t* reference_type_1 = instantiate_reference_type(include_optional);

	cJSON* jsonreference_type_1 = reference_type_convertToJSON(reference_type_1);
	printf("reference_type :\n%s\n", cJSON_Print(jsonreference_type_1));
	reference_type_t* reference_type_2 = reference_type_parseFromJSON(jsonreference_type_1);
	cJSON* jsonreference_type_2 = reference_type_convertToJSON(reference_type_2);
	printf("repeating reference_type:\n%s\n", cJSON_Print(jsonreference_type_2));
}

int main() {
  test_reference_type(1);
  test_reference_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // reference_type_MAIN
#endif // reference_type_TEST
