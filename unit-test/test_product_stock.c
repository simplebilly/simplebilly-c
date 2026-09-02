#ifndef product_stock_TEST
#define product_stock_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define product_stock_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/product_stock.h"
product_stock_t* instantiate_product_stock(int include_optional);



product_stock_t* instantiate_product_stock(int include_optional) {
  product_stock_t* product_stock = NULL;
  if (include_optional) {
    product_stock = product_stock_create(
      "0",
      "0",
      "0",
      56
    );
  } else {
    product_stock = product_stock_create(
      "0",
      "0",
      "0",
      56
    );
  }

  return product_stock;
}


#ifdef product_stock_MAIN

void test_product_stock(int include_optional) {
    product_stock_t* product_stock_1 = instantiate_product_stock(include_optional);

	cJSON* jsonproduct_stock_1 = product_stock_convertToJSON(product_stock_1);
	printf("product_stock :\n%s\n", cJSON_Print(jsonproduct_stock_1));
	product_stock_t* product_stock_2 = product_stock_parseFromJSON(jsonproduct_stock_1);
	cJSON* jsonproduct_stock_2 = product_stock_convertToJSON(product_stock_2);
	printf("repeating product_stock:\n%s\n", cJSON_Print(jsonproduct_stock_2));
}

int main() {
  test_product_stock(1);
  test_product_stock(0);

  printf("Hello world \n");
  return 0;
}

#endif // product_stock_MAIN
#endif // product_stock_TEST
