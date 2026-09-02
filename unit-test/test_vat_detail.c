#ifndef vat_detail_TEST
#define vat_detail_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define vat_detail_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/vat_detail.h"
vat_detail_t* instantiate_vat_detail(int include_optional);



vat_detail_t* instantiate_vat_detail(int include_optional) {
  vat_detail_t* vat_detail = NULL;
  if (include_optional) {
    vat_detail = vat_detail_create(
      56,
      "0",
      "0",
      "0"
    );
  } else {
    vat_detail = vat_detail_create(
      56,
      "0",
      "0",
      "0"
    );
  }

  return vat_detail;
}


#ifdef vat_detail_MAIN

void test_vat_detail(int include_optional) {
    vat_detail_t* vat_detail_1 = instantiate_vat_detail(include_optional);

	cJSON* jsonvat_detail_1 = vat_detail_convertToJSON(vat_detail_1);
	printf("vat_detail :\n%s\n", cJSON_Print(jsonvat_detail_1));
	vat_detail_t* vat_detail_2 = vat_detail_parseFromJSON(jsonvat_detail_1);
	cJSON* jsonvat_detail_2 = vat_detail_convertToJSON(vat_detail_2);
	printf("repeating vat_detail:\n%s\n", cJSON_Print(jsonvat_detail_2));
}

int main() {
  test_vat_detail(1);
  test_vat_detail(0);

  printf("Hello world \n");
  return 0;
}

#endif // vat_detail_MAIN
#endif // vat_detail_TEST
