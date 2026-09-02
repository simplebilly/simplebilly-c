#ifndef bom_status_TEST
#define bom_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bom_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bom_status.h"
bom_status_t* instantiate_bom_status(int include_optional);



bom_status_t* instantiate_bom_status(int include_optional) {
  bom_status_t* bom_status = NULL;
  if (include_optional) {
    bom_status = bom_status_create(
    );
  } else {
    bom_status = bom_status_create(
    );
  }

  return bom_status;
}


#ifdef bom_status_MAIN

void test_bom_status(int include_optional) {
    bom_status_t* bom_status_1 = instantiate_bom_status(include_optional);

	cJSON* jsonbom_status_1 = bom_status_convertToJSON(bom_status_1);
	printf("bom_status :\n%s\n", cJSON_Print(jsonbom_status_1));
	bom_status_t* bom_status_2 = bom_status_parseFromJSON(jsonbom_status_1);
	cJSON* jsonbom_status_2 = bom_status_convertToJSON(bom_status_2);
	printf("repeating bom_status:\n%s\n", cJSON_Print(jsonbom_status_2));
}

int main() {
  test_bom_status(1);
  test_bom_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // bom_status_MAIN
#endif // bom_status_TEST
