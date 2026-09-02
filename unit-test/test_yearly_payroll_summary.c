#ifndef yearly_payroll_summary_TEST
#define yearly_payroll_summary_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define yearly_payroll_summary_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/yearly_payroll_summary.h"
yearly_payroll_summary_t* instantiate_yearly_payroll_summary(int include_optional);



yearly_payroll_summary_t* instantiate_yearly_payroll_summary(int include_optional) {
  yearly_payroll_summary_t* yearly_payroll_summary = NULL;
  if (include_optional) {
    yearly_payroll_summary = yearly_payroll_summary_create(
      56,
      list_createList(),
      56,
      "0",
      "0",
      "0"
    );
  } else {
    yearly_payroll_summary = yearly_payroll_summary_create(
      56,
      list_createList(),
      56,
      "0",
      "0",
      "0"
    );
  }

  return yearly_payroll_summary;
}


#ifdef yearly_payroll_summary_MAIN

void test_yearly_payroll_summary(int include_optional) {
    yearly_payroll_summary_t* yearly_payroll_summary_1 = instantiate_yearly_payroll_summary(include_optional);

	cJSON* jsonyearly_payroll_summary_1 = yearly_payroll_summary_convertToJSON(yearly_payroll_summary_1);
	printf("yearly_payroll_summary :\n%s\n", cJSON_Print(jsonyearly_payroll_summary_1));
	yearly_payroll_summary_t* yearly_payroll_summary_2 = yearly_payroll_summary_parseFromJSON(jsonyearly_payroll_summary_1);
	cJSON* jsonyearly_payroll_summary_2 = yearly_payroll_summary_convertToJSON(yearly_payroll_summary_2);
	printf("repeating yearly_payroll_summary:\n%s\n", cJSON_Print(jsonyearly_payroll_summary_2));
}

int main() {
  test_yearly_payroll_summary(1);
  test_yearly_payroll_summary(0);

  printf("Hello world \n");
  return 0;
}

#endif // yearly_payroll_summary_MAIN
#endif // yearly_payroll_summary_TEST
