#ifndef employment_type_TEST
#define employment_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define employment_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/employment_type.h"
employment_type_t* instantiate_employment_type(int include_optional);



employment_type_t* instantiate_employment_type(int include_optional) {
  employment_type_t* employment_type = NULL;
  if (include_optional) {
    employment_type = employment_type_create(
    );
  } else {
    employment_type = employment_type_create(
    );
  }

  return employment_type;
}


#ifdef employment_type_MAIN

void test_employment_type(int include_optional) {
    employment_type_t* employment_type_1 = instantiate_employment_type(include_optional);

	cJSON* jsonemployment_type_1 = employment_type_convertToJSON(employment_type_1);
	printf("employment_type :\n%s\n", cJSON_Print(jsonemployment_type_1));
	employment_type_t* employment_type_2 = employment_type_parseFromJSON(jsonemployment_type_1);
	cJSON* jsonemployment_type_2 = employment_type_convertToJSON(employment_type_2);
	printf("repeating employment_type:\n%s\n", cJSON_Print(jsonemployment_type_2));
}

int main() {
  test_employment_type(1);
  test_employment_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // employment_type_MAIN
#endif // employment_type_TEST
