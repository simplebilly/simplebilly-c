#ifndef euer_zeile_detail_TEST
#define euer_zeile_detail_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define euer_zeile_detail_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/euer_zeile_detail.h"
euer_zeile_detail_t* instantiate_euer_zeile_detail(int include_optional);



euer_zeile_detail_t* instantiate_euer_zeile_detail(int include_optional) {
  euer_zeile_detail_t* euer_zeile_detail = NULL;
  if (include_optional) {
    euer_zeile_detail = euer_zeile_detail_create(
      "0",
      "0",
      "0",
      list_createList(),
      56
    );
  } else {
    euer_zeile_detail = euer_zeile_detail_create(
      "0",
      "0",
      "0",
      list_createList(),
      56
    );
  }

  return euer_zeile_detail;
}


#ifdef euer_zeile_detail_MAIN

void test_euer_zeile_detail(int include_optional) {
    euer_zeile_detail_t* euer_zeile_detail_1 = instantiate_euer_zeile_detail(include_optional);

	cJSON* jsoneuer_zeile_detail_1 = euer_zeile_detail_convertToJSON(euer_zeile_detail_1);
	printf("euer_zeile_detail :\n%s\n", cJSON_Print(jsoneuer_zeile_detail_1));
	euer_zeile_detail_t* euer_zeile_detail_2 = euer_zeile_detail_parseFromJSON(jsoneuer_zeile_detail_1);
	cJSON* jsoneuer_zeile_detail_2 = euer_zeile_detail_convertToJSON(euer_zeile_detail_2);
	printf("repeating euer_zeile_detail:\n%s\n", cJSON_Print(jsoneuer_zeile_detail_2));
}

int main() {
  test_euer_zeile_detail(1);
  test_euer_zeile_detail(0);

  printf("Hello world \n");
  return 0;
}

#endif // euer_zeile_detail_MAIN
#endif // euer_zeile_detail_TEST
