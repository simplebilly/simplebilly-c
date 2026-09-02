#ifndef payroll_summary_item_TEST
#define payroll_summary_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define payroll_summary_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/payroll_summary_item.h"
payroll_summary_item_t* instantiate_payroll_summary_item(int include_optional);



payroll_summary_item_t* instantiate_payroll_summary_item(int include_optional) {
  payroll_summary_item_t* payroll_summary_item = NULL;
  if (include_optional) {
    payroll_summary_item = payroll_summary_item_create(
      56,
      "0",
      simplebilly_api_payroll_summary_item__draft,
      "0",
      "0",
      "0",
      56
    );
  } else {
    payroll_summary_item = payroll_summary_item_create(
      56,
      "0",
      simplebilly_api_payroll_summary_item__draft,
      "0",
      "0",
      "0",
      56
    );
  }

  return payroll_summary_item;
}


#ifdef payroll_summary_item_MAIN

void test_payroll_summary_item(int include_optional) {
    payroll_summary_item_t* payroll_summary_item_1 = instantiate_payroll_summary_item(include_optional);

	cJSON* jsonpayroll_summary_item_1 = payroll_summary_item_convertToJSON(payroll_summary_item_1);
	printf("payroll_summary_item :\n%s\n", cJSON_Print(jsonpayroll_summary_item_1));
	payroll_summary_item_t* payroll_summary_item_2 = payroll_summary_item_parseFromJSON(jsonpayroll_summary_item_1);
	cJSON* jsonpayroll_summary_item_2 = payroll_summary_item_convertToJSON(payroll_summary_item_2);
	printf("repeating payroll_summary_item:\n%s\n", cJSON_Print(jsonpayroll_summary_item_2));
}

int main() {
  test_payroll_summary_item(1);
  test_payroll_summary_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // payroll_summary_item_MAIN
#endif // payroll_summary_item_TEST
