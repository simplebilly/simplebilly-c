#ifndef supplier_condition_update_TEST
#define supplier_condition_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define supplier_condition_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/supplier_condition_update.h"
supplier_condition_update_t* instantiate_supplier_condition_update(int include_optional);



supplier_condition_update_t* instantiate_supplier_condition_update(int include_optional) {
  supplier_condition_update_t* supplier_condition_update = NULL;
  if (include_optional) {
    supplier_condition_update = supplier_condition_update_create(
      "012",
      "0",
      "0",
      1,
      "0",
      "0",
      56,
      "0",
      "0",
      "0",
      null
    );
  } else {
    supplier_condition_update = supplier_condition_update_create(
      "012",
      "0",
      "0",
      1,
      "0",
      "0",
      56,
      "0",
      "0",
      "0",
      null
    );
  }

  return supplier_condition_update;
}


#ifdef supplier_condition_update_MAIN

void test_supplier_condition_update(int include_optional) {
    supplier_condition_update_t* supplier_condition_update_1 = instantiate_supplier_condition_update(include_optional);

	cJSON* jsonsupplier_condition_update_1 = supplier_condition_update_convertToJSON(supplier_condition_update_1);
	printf("supplier_condition_update :\n%s\n", cJSON_Print(jsonsupplier_condition_update_1));
	supplier_condition_update_t* supplier_condition_update_2 = supplier_condition_update_parseFromJSON(jsonsupplier_condition_update_1);
	cJSON* jsonsupplier_condition_update_2 = supplier_condition_update_convertToJSON(supplier_condition_update_2);
	printf("repeating supplier_condition_update:\n%s\n", cJSON_Print(jsonsupplier_condition_update_2));
}

int main() {
  test_supplier_condition_update(1);
  test_supplier_condition_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // supplier_condition_update_MAIN
#endif // supplier_condition_update_TEST
