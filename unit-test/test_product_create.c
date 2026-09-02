#ifndef product_create_TEST
#define product_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define product_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/product_create.h"
product_create_t* instantiate_product_create(int include_optional);



product_create_t* instantiate_product_create(int include_optional) {
  product_create_t* product_create = NULL;
  if (include_optional) {
    product_create = product_create_create(
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
    product_create = product_create_create(
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

  return product_create;
}


#ifdef product_create_MAIN

void test_product_create(int include_optional) {
    product_create_t* product_create_1 = instantiate_product_create(include_optional);

	cJSON* jsonproduct_create_1 = product_create_convertToJSON(product_create_1);
	printf("product_create :\n%s\n", cJSON_Print(jsonproduct_create_1));
	product_create_t* product_create_2 = product_create_parseFromJSON(jsonproduct_create_1);
	cJSON* jsonproduct_create_2 = product_create_convertToJSON(product_create_2);
	printf("repeating product_create:\n%s\n", cJSON_Print(jsonproduct_create_2));
}

int main() {
  test_product_create(1);
  test_product_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // product_create_MAIN
#endif // product_create_TEST
