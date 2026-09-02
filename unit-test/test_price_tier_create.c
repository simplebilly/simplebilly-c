#ifndef price_tier_create_TEST
#define price_tier_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define price_tier_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/price_tier_create.h"
price_tier_create_t* instantiate_price_tier_create(int include_optional);



price_tier_create_t* instantiate_price_tier_create(int include_optional) {
  price_tier_create_t* price_tier_create = NULL;
  if (include_optional) {
    price_tier_create = price_tier_create_create(
      "0",
      56,
      "0",
      "0"
    );
  } else {
    price_tier_create = price_tier_create_create(
      "0",
      56,
      "0",
      "0"
    );
  }

  return price_tier_create;
}


#ifdef price_tier_create_MAIN

void test_price_tier_create(int include_optional) {
    price_tier_create_t* price_tier_create_1 = instantiate_price_tier_create(include_optional);

	cJSON* jsonprice_tier_create_1 = price_tier_create_convertToJSON(price_tier_create_1);
	printf("price_tier_create :\n%s\n", cJSON_Print(jsonprice_tier_create_1));
	price_tier_create_t* price_tier_create_2 = price_tier_create_parseFromJSON(jsonprice_tier_create_1);
	cJSON* jsonprice_tier_create_2 = price_tier_create_convertToJSON(price_tier_create_2);
	printf("repeating price_tier_create:\n%s\n", cJSON_Print(jsonprice_tier_create_2));
}

int main() {
  test_price_tier_create(1);
  test_price_tier_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // price_tier_create_MAIN
#endif // price_tier_create_TEST
