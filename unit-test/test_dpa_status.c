#ifndef dpa_status_TEST
#define dpa_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dpa_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dpa_status.h"
dpa_status_t* instantiate_dpa_status(int include_optional);



dpa_status_t* instantiate_dpa_status(int include_optional) {
  dpa_status_t* dpa_status = NULL;
  if (include_optional) {
    dpa_status = dpa_status_create(
      1,
      "0",
      "0",
      "0"
    );
  } else {
    dpa_status = dpa_status_create(
      1,
      "0",
      "0",
      "0"
    );
  }

  return dpa_status;
}


#ifdef dpa_status_MAIN

void test_dpa_status(int include_optional) {
    dpa_status_t* dpa_status_1 = instantiate_dpa_status(include_optional);

	cJSON* jsondpa_status_1 = dpa_status_convertToJSON(dpa_status_1);
	printf("dpa_status :\n%s\n", cJSON_Print(jsondpa_status_1));
	dpa_status_t* dpa_status_2 = dpa_status_parseFromJSON(jsondpa_status_1);
	cJSON* jsondpa_status_2 = dpa_status_convertToJSON(dpa_status_2);
	printf("repeating dpa_status:\n%s\n", cJSON_Print(jsondpa_status_2));
}

int main() {
  test_dpa_status(1);
  test_dpa_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // dpa_status_MAIN
#endif // dpa_status_TEST
