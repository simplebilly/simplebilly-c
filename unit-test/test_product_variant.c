#ifndef product_variant_TEST
#define product_variant_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define product_variant_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/product_variant.h"
product_variant_t* instantiate_product_variant(int include_optional);



product_variant_t* instantiate_product_variant(int include_optional) {
  product_variant_t* product_variant = NULL;
  if (include_optional) {
    product_variant = product_variant_create(
      "0",
      "0",
      1,
      "0",
      null,
      "0",
      "0",
      "0",
      "0",
      56
    );
  } else {
    product_variant = product_variant_create(
      "0",
      "0",
      1,
      "0",
      null,
      "0",
      "0",
      "0",
      "0",
      56
    );
  }

  return product_variant;
}


#ifdef product_variant_MAIN

void test_product_variant(int include_optional) {
    product_variant_t* product_variant_1 = instantiate_product_variant(include_optional);

	cJSON* jsonproduct_variant_1 = product_variant_convertToJSON(product_variant_1);
	printf("product_variant :\n%s\n", cJSON_Print(jsonproduct_variant_1));
	product_variant_t* product_variant_2 = product_variant_parseFromJSON(jsonproduct_variant_1);
	cJSON* jsonproduct_variant_2 = product_variant_convertToJSON(product_variant_2);
	printf("repeating product_variant:\n%s\n", cJSON_Print(jsonproduct_variant_2));
}

int main() {
  test_product_variant(1);
  test_product_variant(0);

  printf("Hello world \n");
  return 0;
}

#endif // product_variant_MAIN
#endif // product_variant_TEST
