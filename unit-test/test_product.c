#ifndef product_TEST
#define product_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define product_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/product.h"
product_t* instantiate_product(int include_optional);



product_t* instantiate_product(int include_optional) {
  product_t* product = NULL;
  if (include_optional) {
    product = product_create(
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
    product = product_create(
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

  return product;
}


#ifdef product_MAIN

void test_product(int include_optional) {
    product_t* product_1 = instantiate_product(include_optional);

	cJSON* jsonproduct_1 = product_convertToJSON(product_1);
	printf("product :\n%s\n", cJSON_Print(jsonproduct_1));
	product_t* product_2 = product_parseFromJSON(jsonproduct_1);
	cJSON* jsonproduct_2 = product_convertToJSON(product_2);
	printf("repeating product:\n%s\n", cJSON_Print(jsonproduct_2));
}

int main() {
  test_product(1);
  test_product(0);

  printf("Hello world \n");
  return 0;
}

#endif // product_MAIN
#endif // product_TEST
