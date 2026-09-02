#ifndef pay_gap_report_TEST
#define pay_gap_report_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pay_gap_report_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pay_gap_report.h"
pay_gap_report_t* instantiate_pay_gap_report(int include_optional);



pay_gap_report_t* instantiate_pay_gap_report(int include_optional) {
  pay_gap_report_t* pay_gap_report = NULL;
  if (include_optional) {
    pay_gap_report = pay_gap_report_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1.337,
      1.337,
      list_createList()
    );
  } else {
    pay_gap_report = pay_gap_report_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1.337,
      1.337,
      list_createList()
    );
  }

  return pay_gap_report;
}


#ifdef pay_gap_report_MAIN

void test_pay_gap_report(int include_optional) {
    pay_gap_report_t* pay_gap_report_1 = instantiate_pay_gap_report(include_optional);

	cJSON* jsonpay_gap_report_1 = pay_gap_report_convertToJSON(pay_gap_report_1);
	printf("pay_gap_report :\n%s\n", cJSON_Print(jsonpay_gap_report_1));
	pay_gap_report_t* pay_gap_report_2 = pay_gap_report_parseFromJSON(jsonpay_gap_report_1);
	cJSON* jsonpay_gap_report_2 = pay_gap_report_convertToJSON(pay_gap_report_2);
	printf("repeating pay_gap_report:\n%s\n", cJSON_Print(jsonpay_gap_report_2));
}

int main() {
  test_pay_gap_report(1);
  test_pay_gap_report(0);

  printf("Hello world \n");
  return 0;
}

#endif // pay_gap_report_MAIN
#endif // pay_gap_report_TEST
