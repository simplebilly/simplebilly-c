#ifndef price_tier_TEST
#define price_tier_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define price_tier_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/price_tier.h"
price_tier_t* instantiate_price_tier(int include_optional);



price_tier_t* instantiate_price_tier(int include_optional) {
  price_tier_t* price_tier = NULL;
  if (include_optional) {
    price_tier = price_tier_create(
      "0",
      56,
      "0",
      "0"
    );
  } else {
    price_tier = price_tier_create(
      "0",
      56,
      "0",
      "0"
    );
  }

  return price_tier;
}


#ifdef price_tier_MAIN

void test_price_tier(int include_optional) {
    price_tier_t* price_tier_1 = instantiate_price_tier(include_optional);

	cJSON* jsonprice_tier_1 = price_tier_convertToJSON(price_tier_1);
	printf("price_tier :\n%s\n", cJSON_Print(jsonprice_tier_1));
	price_tier_t* price_tier_2 = price_tier_parseFromJSON(jsonprice_tier_1);
	cJSON* jsonprice_tier_2 = price_tier_convertToJSON(price_tier_2);
	printf("repeating price_tier:\n%s\n", cJSON_Print(jsonprice_tier_2));
}

int main() {
  test_price_tier(1);
  test_price_tier(0);

  printf("Hello world \n");
  return 0;
}

#endif // price_tier_MAIN
#endif // price_tier_TEST
