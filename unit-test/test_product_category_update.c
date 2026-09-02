#ifndef product_category_update_TEST
#define product_category_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define product_category_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/product_category_update.h"
product_category_update_t* instantiate_product_category_update(int include_optional);



product_category_update_t* instantiate_product_category_update(int include_optional) {
  product_category_update_t* product_category_update = NULL;
  if (include_optional) {
    product_category_update = product_category_update_create(
      "0",
      "0",
      "0",
      56
    );
  } else {
    product_category_update = product_category_update_create(
      "0",
      "0",
      "0",
      56
    );
  }

  return product_category_update;
}


#ifdef product_category_update_MAIN

void test_product_category_update(int include_optional) {
    product_category_update_t* product_category_update_1 = instantiate_product_category_update(include_optional);

	cJSON* jsonproduct_category_update_1 = product_category_update_convertToJSON(product_category_update_1);
	printf("product_category_update :\n%s\n", cJSON_Print(jsonproduct_category_update_1));
	product_category_update_t* product_category_update_2 = product_category_update_parseFromJSON(jsonproduct_category_update_1);
	cJSON* jsonproduct_category_update_2 = product_category_update_convertToJSON(product_category_update_2);
	printf("repeating product_category_update:\n%s\n", cJSON_Print(jsonproduct_category_update_2));
}

int main() {
  test_product_category_update(1);
  test_product_category_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // product_category_update_MAIN
#endif // product_category_update_TEST
