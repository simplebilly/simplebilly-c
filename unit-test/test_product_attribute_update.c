#ifndef product_attribute_update_TEST
#define product_attribute_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define product_attribute_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/product_attribute_update.h"
product_attribute_update_t* instantiate_product_attribute_update(int include_optional);



product_attribute_update_t* instantiate_product_attribute_update(int include_optional) {
  product_attribute_update_t* product_attribute_update = NULL;
  if (include_optional) {
    product_attribute_update = product_attribute_update_create(
      1,
      "0",
      56,
      "0",
      "0",
      "0"
    );
  } else {
    product_attribute_update = product_attribute_update_create(
      1,
      "0",
      56,
      "0",
      "0",
      "0"
    );
  }

  return product_attribute_update;
}


#ifdef product_attribute_update_MAIN

void test_product_attribute_update(int include_optional) {
    product_attribute_update_t* product_attribute_update_1 = instantiate_product_attribute_update(include_optional);

	cJSON* jsonproduct_attribute_update_1 = product_attribute_update_convertToJSON(product_attribute_update_1);
	printf("product_attribute_update :\n%s\n", cJSON_Print(jsonproduct_attribute_update_1));
	product_attribute_update_t* product_attribute_update_2 = product_attribute_update_parseFromJSON(jsonproduct_attribute_update_1);
	cJSON* jsonproduct_attribute_update_2 = product_attribute_update_convertToJSON(product_attribute_update_2);
	printf("repeating product_attribute_update:\n%s\n", cJSON_Print(jsonproduct_attribute_update_2));
}

int main() {
  test_product_attribute_update(1);
  test_product_attribute_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // product_attribute_update_MAIN
#endif // product_attribute_update_TEST
