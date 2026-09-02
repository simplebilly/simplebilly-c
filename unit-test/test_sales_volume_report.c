#ifndef sales_volume_report_TEST
#define sales_volume_report_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sales_volume_report_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sales_volume_report.h"
sales_volume_report_t* instantiate_sales_volume_report(int include_optional);



sales_volume_report_t* instantiate_sales_volume_report(int include_optional) {
  sales_volume_report_t* sales_volume_report = NULL;
  if (include_optional) {
    sales_volume_report = sales_volume_report_create(
      "0",
      list_createList(),
      56
    );
  } else {
    sales_volume_report = sales_volume_report_create(
      "0",
      list_createList(),
      56
    );
  }

  return sales_volume_report;
}


#ifdef sales_volume_report_MAIN

void test_sales_volume_report(int include_optional) {
    sales_volume_report_t* sales_volume_report_1 = instantiate_sales_volume_report(include_optional);

	cJSON* jsonsales_volume_report_1 = sales_volume_report_convertToJSON(sales_volume_report_1);
	printf("sales_volume_report :\n%s\n", cJSON_Print(jsonsales_volume_report_1));
	sales_volume_report_t* sales_volume_report_2 = sales_volume_report_parseFromJSON(jsonsales_volume_report_1);
	cJSON* jsonsales_volume_report_2 = sales_volume_report_convertToJSON(sales_volume_report_2);
	printf("repeating sales_volume_report:\n%s\n", cJSON_Print(jsonsales_volume_report_2));
}

int main() {
  test_sales_volume_report(1);
  test_sales_volume_report(0);

  printf("Hello world \n");
  return 0;
}

#endif // sales_volume_report_MAIN
#endif // sales_volume_report_TEST
