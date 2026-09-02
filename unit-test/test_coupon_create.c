#ifndef coupon_create_TEST
#define coupon_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define coupon_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/coupon_create.h"
coupon_create_t* instantiate_coupon_create(int include_optional);



coupon_create_t* instantiate_coupon_create(int include_optional) {
  coupon_create_t* coupon_create = NULL;
  if (include_optional) {
    coupon_create = coupon_create_create(
      "0",
      "0",
      simplebilly_api_coupon_create__percentage,
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
    coupon_create = coupon_create_create(
      "0",
      "0",
      simplebilly_api_coupon_create__percentage,
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

  return coupon_create;
}


#ifdef coupon_create_MAIN

void test_coupon_create(int include_optional) {
    coupon_create_t* coupon_create_1 = instantiate_coupon_create(include_optional);

	cJSON* jsoncoupon_create_1 = coupon_create_convertToJSON(coupon_create_1);
	printf("coupon_create :\n%s\n", cJSON_Print(jsoncoupon_create_1));
	coupon_create_t* coupon_create_2 = coupon_create_parseFromJSON(jsoncoupon_create_1);
	cJSON* jsoncoupon_create_2 = coupon_create_convertToJSON(coupon_create_2);
	printf("repeating coupon_create:\n%s\n", cJSON_Print(jsoncoupon_create_2));
}

int main() {
  test_coupon_create(1);
  test_coupon_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // coupon_create_MAIN
#endif // coupon_create_TEST
