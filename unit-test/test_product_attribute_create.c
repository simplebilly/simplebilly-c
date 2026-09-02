#ifndef product_attribute_create_TEST
#define product_attribute_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define product_attribute_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/product_attribute_create.h"
product_attribute_create_t* instantiate_product_attribute_create(int include_optional);



product_attribute_create_t* instantiate_product_attribute_create(int include_optional) {
  product_attribute_create_t* product_attribute_create = NULL;
  if (include_optional) {
    product_attribute_create = product_attribute_create_create(
      1,
      "0",
      56,
      "0",
      "0",
      "0"
    );
  } else {
    product_attribute_create = product_attribute_create_create(
      1,
      "0",
      56,
      "0",
      "0",
      "0"
    );
  }

  return product_attribute_create;
}


#ifdef product_attribute_create_MAIN

void test_product_attribute_create(int include_optional) {
    product_attribute_create_t* product_attribute_create_1 = instantiate_product_attribute_create(include_optional);

	cJSON* jsonproduct_attribute_create_1 = product_attribute_create_convertToJSON(product_attribute_create_1);
	printf("product_attribute_create :\n%s\n", cJSON_Print(jsonproduct_attribute_create_1));
	product_attribute_create_t* product_attribute_create_2 = product_attribute_create_parseFromJSON(jsonproduct_attribute_create_1);
	cJSON* jsonproduct_attribute_create_2 = product_attribute_create_convertToJSON(product_attribute_create_2);
	printf("repeating product_attribute_create:\n%s\n", cJSON_Print(jsonproduct_attribute_create_2));
}

int main() {
  test_product_attribute_create(1);
  test_product_attribute_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // product_attribute_create_MAIN
#endif // product_attribute_create_TEST
