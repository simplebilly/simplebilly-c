#ifndef vat_summary_TEST
#define vat_summary_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define vat_summary_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/vat_summary.h"
vat_summary_t* instantiate_vat_summary(int include_optional);



vat_summary_t* instantiate_vat_summary(int include_optional) {
  vat_summary_t* vat_summary = NULL;
  if (include_optional) {
    vat_summary = vat_summary_create(
      list_createList(),
      list_createList(),
      "0",
      "0",
      "0"
    );
  } else {
    vat_summary = vat_summary_create(
      list_createList(),
      list_createList(),
      "0",
      "0",
      "0"
    );
  }

  return vat_summary;
}


#ifdef vat_summary_MAIN

void test_vat_summary(int include_optional) {
    vat_summary_t* vat_summary_1 = instantiate_vat_summary(include_optional);

	cJSON* jsonvat_summary_1 = vat_summary_convertToJSON(vat_summary_1);
	printf("vat_summary :\n%s\n", cJSON_Print(jsonvat_summary_1));
	vat_summary_t* vat_summary_2 = vat_summary_parseFromJSON(jsonvat_summary_1);
	cJSON* jsonvat_summary_2 = vat_summary_convertToJSON(vat_summary_2);
	printf("repeating vat_summary:\n%s\n", cJSON_Print(jsonvat_summary_2));
}

int main() {
  test_vat_summary(1);
  test_vat_summary(0);

  printf("Hello world \n");
  return 0;
}

#endif // vat_summary_MAIN
#endif // vat_summary_TEST
