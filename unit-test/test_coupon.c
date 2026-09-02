#ifndef coupon_TEST
#define coupon_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define coupon_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/coupon.h"
coupon_t* instantiate_coupon(int include_optional);



coupon_t* instantiate_coupon(int include_optional) {
  coupon_t* coupon = NULL;
  if (include_optional) {
    coupon = coupon_create(
      "0",
      "0",
      simplebilly_api_coupon__percentage,
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
    coupon = coupon_create(
      "0",
      "0",
      simplebilly_api_coupon__percentage,
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

  return coupon;
}


#ifdef coupon_MAIN

void test_coupon(int include_optional) {
    coupon_t* coupon_1 = instantiate_coupon(include_optional);

	cJSON* jsoncoupon_1 = coupon_convertToJSON(coupon_1);
	printf("coupon :\n%s\n", cJSON_Print(jsoncoupon_1));
	coupon_t* coupon_2 = coupon_parseFromJSON(jsoncoupon_1);
	cJSON* jsoncoupon_2 = coupon_convertToJSON(coupon_2);
	printf("repeating coupon:\n%s\n", cJSON_Print(jsoncoupon_2));
}

int main() {
  test_coupon(1);
  test_coupon(0);

  printf("Hello world \n");
  return 0;
}

#endif // coupon_MAIN
#endif // coupon_TEST
