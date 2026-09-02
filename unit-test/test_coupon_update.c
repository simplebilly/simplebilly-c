#ifndef coupon_update_TEST
#define coupon_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define coupon_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/coupon_update.h"
coupon_update_t* instantiate_coupon_update(int include_optional);



coupon_update_t* instantiate_coupon_update(int include_optional) {
  coupon_update_t* coupon_update = NULL;
  if (include_optional) {
    coupon_update = coupon_update_create(
      "0",
      "0",
      percentage,
      "0",
      "2013-10-20T19:20:30+01:00",
      1,
      1,
      "0",
      56,
      56,
      "0",
      null,
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    coupon_update = coupon_update_create(
      "0",
      "0",
      percentage,
      "0",
      "2013-10-20T19:20:30+01:00",
      1,
      1,
      "0",
      56,
      56,
      "0",
      null,
      "2013-10-20T19:20:30+01:00"
    );
  }

  return coupon_update;
}


#ifdef coupon_update_MAIN

void test_coupon_update(int include_optional) {
    coupon_update_t* coupon_update_1 = instantiate_coupon_update(include_optional);

	cJSON* jsoncoupon_update_1 = coupon_update_convertToJSON(coupon_update_1);
	printf("coupon_update :\n%s\n", cJSON_Print(jsoncoupon_update_1));
	coupon_update_t* coupon_update_2 = coupon_update_parseFromJSON(jsoncoupon_update_1);
	cJSON* jsoncoupon_update_2 = coupon_update_convertToJSON(coupon_update_2);
	printf("repeating coupon_update:\n%s\n", cJSON_Print(jsoncoupon_update_2));
}

int main() {
  test_coupon_update(1);
  test_coupon_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // coupon_update_MAIN
#endif // coupon_update_TEST
