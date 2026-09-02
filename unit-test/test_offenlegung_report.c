#ifndef offenlegung_report_TEST
#define offenlegung_report_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define offenlegung_report_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/offenlegung_report.h"
offenlegung_report_t* instantiate_offenlegung_report(int include_optional);



offenlegung_report_t* instantiate_offenlegung_report(int include_optional) {
  offenlegung_report_t* offenlegung_report = NULL;
  if (include_optional) {
    offenlegung_report = offenlegung_report_create(
      "2013-10-20",
      56,
      list_createList(),
      1,
      "0",
      56
    );
  } else {
    offenlegung_report = offenlegung_report_create(
      "2013-10-20",
      56,
      list_createList(),
      1,
      "0",
      56
    );
  }

  return offenlegung_report;
}


#ifdef offenlegung_report_MAIN

void test_offenlegung_report(int include_optional) {
    offenlegung_report_t* offenlegung_report_1 = instantiate_offenlegung_report(include_optional);

	cJSON* jsonoffenlegung_report_1 = offenlegung_report_convertToJSON(offenlegung_report_1);
	printf("offenlegung_report :\n%s\n", cJSON_Print(jsonoffenlegung_report_1));
	offenlegung_report_t* offenlegung_report_2 = offenlegung_report_parseFromJSON(jsonoffenlegung_report_1);
	cJSON* jsonoffenlegung_report_2 = offenlegung_report_convertToJSON(offenlegung_report_2);
	printf("repeating offenlegung_report:\n%s\n", cJSON_Print(jsonoffenlegung_report_2));
}

int main() {
  test_offenlegung_report(1);
  test_offenlegung_report(0);

  printf("Hello world \n");
  return 0;
}

#endif // offenlegung_report_MAIN
#endif // offenlegung_report_TEST
