#ifndef price_tier_update_TEST
#define price_tier_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define price_tier_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/price_tier_update.h"
price_tier_update_t* instantiate_price_tier_update(int include_optional);



price_tier_update_t* instantiate_price_tier_update(int include_optional) {
  price_tier_update_t* price_tier_update = NULL;
  if (include_optional) {
    price_tier_update = price_tier_update_create(
      "0",
      56,
      "0",
      "0"
    );
  } else {
    price_tier_update = price_tier_update_create(
      "0",
      56,
      "0",
      "0"
    );
  }

  return price_tier_update;
}


#ifdef price_tier_update_MAIN

void test_price_tier_update(int include_optional) {
    price_tier_update_t* price_tier_update_1 = instantiate_price_tier_update(include_optional);

	cJSON* jsonprice_tier_update_1 = price_tier_update_convertToJSON(price_tier_update_1);
	printf("price_tier_update :\n%s\n", cJSON_Print(jsonprice_tier_update_1));
	price_tier_update_t* price_tier_update_2 = price_tier_update_parseFromJSON(jsonprice_tier_update_1);
	cJSON* jsonprice_tier_update_2 = price_tier_update_convertToJSON(price_tier_update_2);
	printf("repeating price_tier_update:\n%s\n", cJSON_Print(jsonprice_tier_update_2));
}

int main() {
  test_price_tier_update(1);
  test_price_tier_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // price_tier_update_MAIN
#endif // price_tier_update_TEST
