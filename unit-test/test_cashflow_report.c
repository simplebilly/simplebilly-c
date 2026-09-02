#ifndef cashflow_report_TEST
#define cashflow_report_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cashflow_report_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cashflow_report.h"
cashflow_report_t* instantiate_cashflow_report(int include_optional);



cashflow_report_t* instantiate_cashflow_report(int include_optional) {
  cashflow_report_t* cashflow_report = NULL;
  if (include_optional) {
    cashflow_report = cashflow_report_create(
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      "0"
    );
  } else {
    cashflow_report = cashflow_report_create(
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      "0"
    );
  }

  return cashflow_report;
}


#ifdef cashflow_report_MAIN

void test_cashflow_report(int include_optional) {
    cashflow_report_t* cashflow_report_1 = instantiate_cashflow_report(include_optional);

	cJSON* jsoncashflow_report_1 = cashflow_report_convertToJSON(cashflow_report_1);
	printf("cashflow_report :\n%s\n", cJSON_Print(jsoncashflow_report_1));
	cashflow_report_t* cashflow_report_2 = cashflow_report_parseFromJSON(jsoncashflow_report_1);
	cJSON* jsoncashflow_report_2 = cashflow_report_convertToJSON(cashflow_report_2);
	printf("repeating cashflow_report:\n%s\n", cJSON_Print(jsoncashflow_report_2));
}

int main() {
  test_cashflow_report(1);
  test_cashflow_report(0);

  printf("Hello world \n");
  return 0;
}

#endif // cashflow_report_MAIN
#endif // cashflow_report_TEST
