#ifndef hebesatz_lookup_TEST
#define hebesatz_lookup_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define hebesatz_lookup_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/hebesatz_lookup.h"
hebesatz_lookup_t* instantiate_hebesatz_lookup(int include_optional);



hebesatz_lookup_t* instantiate_hebesatz_lookup(int include_optional) {
  hebesatz_lookup_t* hebesatz_lookup = NULL;
  if (include_optional) {
    hebesatz_lookup = hebesatz_lookup_create(
      "0",
      "0",
      "0",
      "0",
      1.337,
      1.337,
      56,
      "0",
      "0",
      "0"
    );
  } else {
    hebesatz_lookup = hebesatz_lookup_create(
      "0",
      "0",
      "0",
      "0",
      1.337,
      1.337,
      56,
      "0",
      "0",
      "0"
    );
  }

  return hebesatz_lookup;
}


#ifdef hebesatz_lookup_MAIN

void test_hebesatz_lookup(int include_optional) {
    hebesatz_lookup_t* hebesatz_lookup_1 = instantiate_hebesatz_lookup(include_optional);

	cJSON* jsonhebesatz_lookup_1 = hebesatz_lookup_convertToJSON(hebesatz_lookup_1);
	printf("hebesatz_lookup :\n%s\n", cJSON_Print(jsonhebesatz_lookup_1));
	hebesatz_lookup_t* hebesatz_lookup_2 = hebesatz_lookup_parseFromJSON(jsonhebesatz_lookup_1);
	cJSON* jsonhebesatz_lookup_2 = hebesatz_lookup_convertToJSON(hebesatz_lookup_2);
	printf("repeating hebesatz_lookup:\n%s\n", cJSON_Print(jsonhebesatz_lookup_2));
}

int main() {
  test_hebesatz_lookup(1);
  test_hebesatz_lookup(0);

  printf("Hello world \n");
  return 0;
}

#endif // hebesatz_lookup_MAIN
#endif // hebesatz_lookup_TEST
