#ifndef product_attribute_TEST
#define product_attribute_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define product_attribute_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/product_attribute.h"
product_attribute_t* instantiate_product_attribute(int include_optional);



product_attribute_t* instantiate_product_attribute(int include_optional) {
  product_attribute_t* product_attribute = NULL;
  if (include_optional) {
    product_attribute = product_attribute_create(
      1,
      "0",
      56,
      "0",
      "0",
      "0"
    );
  } else {
    product_attribute = product_attribute_create(
      1,
      "0",
      56,
      "0",
      "0",
      "0"
    );
  }

  return product_attribute;
}


#ifdef product_attribute_MAIN

void test_product_attribute(int include_optional) {
    product_attribute_t* product_attribute_1 = instantiate_product_attribute(include_optional);

	cJSON* jsonproduct_attribute_1 = product_attribute_convertToJSON(product_attribute_1);
	printf("product_attribute :\n%s\n", cJSON_Print(jsonproduct_attribute_1));
	product_attribute_t* product_attribute_2 = product_attribute_parseFromJSON(jsonproduct_attribute_1);
	cJSON* jsonproduct_attribute_2 = product_attribute_convertToJSON(product_attribute_2);
	printf("repeating product_attribute:\n%s\n", cJSON_Print(jsonproduct_attribute_2));
}

int main() {
  test_product_attribute(1);
  test_product_attribute(0);

  printf("Hello world \n");
  return 0;
}

#endif // product_attribute_MAIN
#endif // product_attribute_TEST
