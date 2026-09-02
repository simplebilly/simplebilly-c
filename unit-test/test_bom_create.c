#ifndef bom_create_TEST
#define bom_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bom_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bom_create.h"
bom_create_t* instantiate_bom_create(int include_optional);



bom_create_t* instantiate_bom_create(int include_optional) {
  bom_create_t* bom_create = NULL;
  if (include_optional) {
    bom_create = bom_create_create(
      null,
      "0",
      "0",
      56,
      "0",
      draft
    );
  } else {
    bom_create = bom_create_create(
      null,
      "0",
      "0",
      56,
      "0",
      draft
    );
  }

  return bom_create;
}


#ifdef bom_create_MAIN

void test_bom_create(int include_optional) {
    bom_create_t* bom_create_1 = instantiate_bom_create(include_optional);

	cJSON* jsonbom_create_1 = bom_create_convertToJSON(bom_create_1);
	printf("bom_create :\n%s\n", cJSON_Print(jsonbom_create_1));
	bom_create_t* bom_create_2 = bom_create_parseFromJSON(jsonbom_create_1);
	cJSON* jsonbom_create_2 = bom_create_convertToJSON(bom_create_2);
	printf("repeating bom_create:\n%s\n", cJSON_Print(jsonbom_create_2));
}

int main() {
  test_bom_create(1);
  test_bom_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // bom_create_MAIN
#endif // bom_create_TEST
