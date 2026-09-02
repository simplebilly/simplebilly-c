#ifndef bom_TEST
#define bom_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bom_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bom.h"
bom_t* instantiate_bom(int include_optional);



bom_t* instantiate_bom(int include_optional) {
  bom_t* bom = NULL;
  if (include_optional) {
    bom = bom_create(
      null,
      "0",
      "0",
      56,
      "0",
      draft
    );
  } else {
    bom = bom_create(
      null,
      "0",
      "0",
      56,
      "0",
      draft
    );
  }

  return bom;
}


#ifdef bom_MAIN

void test_bom(int include_optional) {
    bom_t* bom_1 = instantiate_bom(include_optional);

	cJSON* jsonbom_1 = bom_convertToJSON(bom_1);
	printf("bom :\n%s\n", cJSON_Print(jsonbom_1));
	bom_t* bom_2 = bom_parseFromJSON(jsonbom_1);
	cJSON* jsonbom_2 = bom_convertToJSON(bom_2);
	printf("repeating bom:\n%s\n", cJSON_Print(jsonbom_2));
}

int main() {
  test_bom(1);
  test_bom(0);

  printf("Hello world \n");
  return 0;
}

#endif // bom_MAIN
#endif // bom_TEST
