#ifndef euer_detail_ergebnis_TEST
#define euer_detail_ergebnis_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define euer_detail_ergebnis_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/euer_detail_ergebnis.h"
euer_detail_ergebnis_t* instantiate_euer_detail_ergebnis(int include_optional);



euer_detail_ergebnis_t* instantiate_euer_detail_ergebnis(int include_optional) {
  euer_detail_ergebnis_t* euer_detail_ergebnis = NULL;
  if (include_optional) {
    euer_detail_ergebnis = euer_detail_ergebnis_create(
      56,
      list_createList()
    );
  } else {
    euer_detail_ergebnis = euer_detail_ergebnis_create(
      56,
      list_createList()
    );
  }

  return euer_detail_ergebnis;
}


#ifdef euer_detail_ergebnis_MAIN

void test_euer_detail_ergebnis(int include_optional) {
    euer_detail_ergebnis_t* euer_detail_ergebnis_1 = instantiate_euer_detail_ergebnis(include_optional);

	cJSON* jsoneuer_detail_ergebnis_1 = euer_detail_ergebnis_convertToJSON(euer_detail_ergebnis_1);
	printf("euer_detail_ergebnis :\n%s\n", cJSON_Print(jsoneuer_detail_ergebnis_1));
	euer_detail_ergebnis_t* euer_detail_ergebnis_2 = euer_detail_ergebnis_parseFromJSON(jsoneuer_detail_ergebnis_1);
	cJSON* jsoneuer_detail_ergebnis_2 = euer_detail_ergebnis_convertToJSON(euer_detail_ergebnis_2);
	printf("repeating euer_detail_ergebnis:\n%s\n", cJSON_Print(jsoneuer_detail_ergebnis_2));
}

int main() {
  test_euer_detail_ergebnis(1);
  test_euer_detail_ergebnis(0);

  printf("Hello world \n");
  return 0;
}

#endif // euer_detail_ergebnis_MAIN
#endif // euer_detail_ergebnis_TEST
