#ifndef konto_report_TEST
#define konto_report_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define konto_report_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/konto_report.h"
konto_report_t* instantiate_konto_report(int include_optional);



konto_report_t* instantiate_konto_report(int include_optional) {
  konto_report_t* konto_report = NULL;
  if (include_optional) {
    konto_report = konto_report_create(
      "0",
      list_createList(),
      "0"
    );
  } else {
    konto_report = konto_report_create(
      "0",
      list_createList(),
      "0"
    );
  }

  return konto_report;
}


#ifdef konto_report_MAIN

void test_konto_report(int include_optional) {
    konto_report_t* konto_report_1 = instantiate_konto_report(include_optional);

	cJSON* jsonkonto_report_1 = konto_report_convertToJSON(konto_report_1);
	printf("konto_report :\n%s\n", cJSON_Print(jsonkonto_report_1));
	konto_report_t* konto_report_2 = konto_report_parseFromJSON(jsonkonto_report_1);
	cJSON* jsonkonto_report_2 = konto_report_convertToJSON(konto_report_2);
	printf("repeating konto_report:\n%s\n", cJSON_Print(jsonkonto_report_2));
}

int main() {
  test_konto_report(1);
  test_konto_report(0);

  printf("Hello world \n");
  return 0;
}

#endif // konto_report_MAIN
#endif // konto_report_TEST
