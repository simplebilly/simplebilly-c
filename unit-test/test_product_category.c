#ifndef product_category_TEST
#define product_category_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define product_category_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/product_category.h"
product_category_t* instantiate_product_category(int include_optional);



product_category_t* instantiate_product_category(int include_optional) {
  product_category_t* product_category = NULL;
  if (include_optional) {
    product_category = product_category_create(
      "0",
      "0",
      "0",
      56
    );
  } else {
    product_category = product_category_create(
      "0",
      "0",
      "0",
      56
    );
  }

  return product_category;
}


#ifdef product_category_MAIN

void test_product_category(int include_optional) {
    product_category_t* product_category_1 = instantiate_product_category(include_optional);

	cJSON* jsonproduct_category_1 = product_category_convertToJSON(product_category_1);
	printf("product_category :\n%s\n", cJSON_Print(jsonproduct_category_1));
	product_category_t* product_category_2 = product_category_parseFromJSON(jsonproduct_category_1);
	cJSON* jsonproduct_category_2 = product_category_convertToJSON(product_category_2);
	printf("repeating product_category:\n%s\n", cJSON_Print(jsonproduct_category_2));
}

int main() {
  test_product_category(1);
  test_product_category(0);

  printf("Hello world \n");
  return 0;
}

#endif // product_category_MAIN
#endif // product_category_TEST
