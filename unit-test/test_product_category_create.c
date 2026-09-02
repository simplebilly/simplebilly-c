#ifndef product_category_create_TEST
#define product_category_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define product_category_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/product_category_create.h"
product_category_create_t* instantiate_product_category_create(int include_optional);



product_category_create_t* instantiate_product_category_create(int include_optional) {
  product_category_create_t* product_category_create = NULL;
  if (include_optional) {
    product_category_create = product_category_create_create(
      "0",
      "0",
      "0",
      56
    );
  } else {
    product_category_create = product_category_create_create(
      "0",
      "0",
      "0",
      56
    );
  }

  return product_category_create;
}


#ifdef product_category_create_MAIN

void test_product_category_create(int include_optional) {
    product_category_create_t* product_category_create_1 = instantiate_product_category_create(include_optional);

	cJSON* jsonproduct_category_create_1 = product_category_create_convertToJSON(product_category_create_1);
	printf("product_category_create :\n%s\n", cJSON_Print(jsonproduct_category_create_1));
	product_category_create_t* product_category_create_2 = product_category_create_parseFromJSON(jsonproduct_category_create_1);
	cJSON* jsonproduct_category_create_2 = product_category_create_convertToJSON(product_category_create_2);
	printf("repeating product_category_create:\n%s\n", cJSON_Print(jsonproduct_category_create_2));
}

int main() {
  test_product_category_create(1);
  test_product_category_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // product_category_create_MAIN
#endif // product_category_create_TEST
