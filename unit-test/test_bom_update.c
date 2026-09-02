#ifndef bom_update_TEST
#define bom_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bom_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bom_update.h"
bom_update_t* instantiate_bom_update(int include_optional);



bom_update_t* instantiate_bom_update(int include_optional) {
  bom_update_t* bom_update = NULL;
  if (include_optional) {
    bom_update = bom_update_create(
      null,
      "0",
      "0",
      56,
      "0",
      draft
    );
  } else {
    bom_update = bom_update_create(
      null,
      "0",
      "0",
      56,
      "0",
      draft
    );
  }

  return bom_update;
}


#ifdef bom_update_MAIN

void test_bom_update(int include_optional) {
    bom_update_t* bom_update_1 = instantiate_bom_update(include_optional);

	cJSON* jsonbom_update_1 = bom_update_convertToJSON(bom_update_1);
	printf("bom_update :\n%s\n", cJSON_Print(jsonbom_update_1));
	bom_update_t* bom_update_2 = bom_update_parseFromJSON(jsonbom_update_1);
	cJSON* jsonbom_update_2 = bom_update_convertToJSON(bom_update_2);
	printf("repeating bom_update:\n%s\n", cJSON_Print(jsonbom_update_2));
}

int main() {
  test_bom_update(1);
  test_bom_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // bom_update_MAIN
#endif // bom_update_TEST
