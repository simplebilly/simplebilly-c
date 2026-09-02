#ifndef product_update_TEST
#define product_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define product_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/product_update.h"
product_update_t* instantiate_product_update(int include_optional);



product_update_t* instantiate_product_update(int include_optional) {
  product_update_t* product_update = NULL;
  if (include_optional) {
    product_update = product_update_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      null,
      1,
      "0",
      "0",
      56,
      56,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      56,
      "0",
      "0",
      1,
      "0",
      56,
      null,
      "0",
      1,
      1,
      null,
      "0",
      "0",
      "0"
    );
  } else {
    product_update = product_update_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      null,
      1,
      "0",
      "0",
      56,
      56,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      56,
      "0",
      "0",
      1,
      "0",
      56,
      null,
      "0",
      1,
      1,
      null,
      "0",
      "0",
      "0"
    );
  }

  return product_update;
}


#ifdef product_update_MAIN

void test_product_update(int include_optional) {
    product_update_t* product_update_1 = instantiate_product_update(include_optional);

	cJSON* jsonproduct_update_1 = product_update_convertToJSON(product_update_1);
	printf("product_update :\n%s\n", cJSON_Print(jsonproduct_update_1));
	product_update_t* product_update_2 = product_update_parseFromJSON(jsonproduct_update_1);
	cJSON* jsonproduct_update_2 = product_update_convertToJSON(product_update_2);
	printf("repeating product_update:\n%s\n", cJSON_Print(jsonproduct_update_2));
}

int main() {
  test_product_update(1);
  test_product_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // product_update_MAIN
#endif // product_update_TEST
