#ifndef euer_ergebnis_TEST
#define euer_ergebnis_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define euer_ergebnis_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/euer_ergebnis.h"
euer_ergebnis_t* instantiate_euer_ergebnis(int include_optional);



euer_ergebnis_t* instantiate_euer_ergebnis(int include_optional) {
  euer_ergebnis_t* euer_ergebnis = NULL;
  if (include_optional) {
    euer_ergebnis = euer_ergebnis_create(
      "0",
      "0",
      56,
      "0",
      "0",
      list_createList()
    );
  } else {
    euer_ergebnis = euer_ergebnis_create(
      "0",
      "0",
      56,
      "0",
      "0",
      list_createList()
    );
  }

  return euer_ergebnis;
}


#ifdef euer_ergebnis_MAIN

void test_euer_ergebnis(int include_optional) {
    euer_ergebnis_t* euer_ergebnis_1 = instantiate_euer_ergebnis(include_optional);

	cJSON* jsoneuer_ergebnis_1 = euer_ergebnis_convertToJSON(euer_ergebnis_1);
	printf("euer_ergebnis :\n%s\n", cJSON_Print(jsoneuer_ergebnis_1));
	euer_ergebnis_t* euer_ergebnis_2 = euer_ergebnis_parseFromJSON(jsoneuer_ergebnis_1);
	cJSON* jsoneuer_ergebnis_2 = euer_ergebnis_convertToJSON(euer_ergebnis_2);
	printf("repeating euer_ergebnis:\n%s\n", cJSON_Print(jsoneuer_ergebnis_2));
}

int main() {
  test_euer_ergebnis(1);
  test_euer_ergebnis(0);

  printf("Hello world \n");
  return 0;
}

#endif // euer_ergebnis_MAIN
#endif // euer_ergebnis_TEST
