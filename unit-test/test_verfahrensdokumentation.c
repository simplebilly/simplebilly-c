#ifndef verfahrensdokumentation_TEST
#define verfahrensdokumentation_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define verfahrensdokumentation_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/verfahrensdokumentation.h"
verfahrensdokumentation_t* instantiate_verfahrensdokumentation(int include_optional);



verfahrensdokumentation_t* instantiate_verfahrensdokumentation(int include_optional) {
  verfahrensdokumentation_t* verfahrensdokumentation = NULL;
  if (include_optional) {
    verfahrensdokumentation = verfahrensdokumentation_create(
      list_createList(),
      "0",
      "0",
      "0"
    );
  } else {
    verfahrensdokumentation = verfahrensdokumentation_create(
      list_createList(),
      "0",
      "0",
      "0"
    );
  }

  return verfahrensdokumentation;
}


#ifdef verfahrensdokumentation_MAIN

void test_verfahrensdokumentation(int include_optional) {
    verfahrensdokumentation_t* verfahrensdokumentation_1 = instantiate_verfahrensdokumentation(include_optional);

	cJSON* jsonverfahrensdokumentation_1 = verfahrensdokumentation_convertToJSON(verfahrensdokumentation_1);
	printf("verfahrensdokumentation :\n%s\n", cJSON_Print(jsonverfahrensdokumentation_1));
	verfahrensdokumentation_t* verfahrensdokumentation_2 = verfahrensdokumentation_parseFromJSON(jsonverfahrensdokumentation_1);
	cJSON* jsonverfahrensdokumentation_2 = verfahrensdokumentation_convertToJSON(verfahrensdokumentation_2);
	printf("repeating verfahrensdokumentation:\n%s\n", cJSON_Print(jsonverfahrensdokumentation_2));
}

int main() {
  test_verfahrensdokumentation(1);
  test_verfahrensdokumentation(0);

  printf("Hello world \n");
  return 0;
}

#endif // verfahrensdokumentation_MAIN
#endif // verfahrensdokumentation_TEST
