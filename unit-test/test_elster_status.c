#ifndef elster_status_TEST
#define elster_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define elster_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/elster_status.h"
elster_status_t* instantiate_elster_status(int include_optional);



elster_status_t* instantiate_elster_status(int include_optional) {
  elster_status_t* elster_status = NULL;
  if (include_optional) {
    elster_status = elster_status_create(
      1,
      1,
      "0",
      1,
      "0",
      "0",
      1
    );
  } else {
    elster_status = elster_status_create(
      1,
      1,
      "0",
      1,
      "0",
      "0",
      1
    );
  }

  return elster_status;
}


#ifdef elster_status_MAIN

void test_elster_status(int include_optional) {
    elster_status_t* elster_status_1 = instantiate_elster_status(include_optional);

	cJSON* jsonelster_status_1 = elster_status_convertToJSON(elster_status_1);
	printf("elster_status :\n%s\n", cJSON_Print(jsonelster_status_1));
	elster_status_t* elster_status_2 = elster_status_parseFromJSON(jsonelster_status_1);
	cJSON* jsonelster_status_2 = elster_status_convertToJSON(elster_status_2);
	printf("repeating elster_status:\n%s\n", cJSON_Print(jsonelster_status_2));
}

int main() {
  test_elster_status(1);
  test_elster_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // elster_status_MAIN
#endif // elster_status_TEST
