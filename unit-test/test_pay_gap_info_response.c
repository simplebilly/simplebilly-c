#ifndef pay_gap_info_response_TEST
#define pay_gap_info_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pay_gap_info_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pay_gap_info_response.h"
pay_gap_info_response_t* instantiate_pay_gap_info_response(int include_optional);



pay_gap_info_response_t* instantiate_pay_gap_info_response(int include_optional) {
  pay_gap_info_response_t* pay_gap_info_response = NULL;
  if (include_optional) {
    pay_gap_info_response = pay_gap_info_response_create(
      "0",
      "0",
      "0",
      1.337,
      1.337,
      0,
      "0",
      "0",
      1.337,
      1.337,
      1.337
    );
  } else {
    pay_gap_info_response = pay_gap_info_response_create(
      "0",
      "0",
      "0",
      1.337,
      1.337,
      0,
      "0",
      "0",
      1.337,
      1.337,
      1.337
    );
  }

  return pay_gap_info_response;
}


#ifdef pay_gap_info_response_MAIN

void test_pay_gap_info_response(int include_optional) {
    pay_gap_info_response_t* pay_gap_info_response_1 = instantiate_pay_gap_info_response(include_optional);

	cJSON* jsonpay_gap_info_response_1 = pay_gap_info_response_convertToJSON(pay_gap_info_response_1);
	printf("pay_gap_info_response :\n%s\n", cJSON_Print(jsonpay_gap_info_response_1));
	pay_gap_info_response_t* pay_gap_info_response_2 = pay_gap_info_response_parseFromJSON(jsonpay_gap_info_response_1);
	cJSON* jsonpay_gap_info_response_2 = pay_gap_info_response_convertToJSON(pay_gap_info_response_2);
	printf("repeating pay_gap_info_response:\n%s\n", cJSON_Print(jsonpay_gap_info_response_2));
}

int main() {
  test_pay_gap_info_response(1);
  test_pay_gap_info_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // pay_gap_info_response_MAIN
#endif // pay_gap_info_response_TEST
