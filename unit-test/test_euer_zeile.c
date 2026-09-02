#ifndef euer_zeile_TEST
#define euer_zeile_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define euer_zeile_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/euer_zeile.h"
euer_zeile_t* instantiate_euer_zeile(int include_optional);



euer_zeile_t* instantiate_euer_zeile(int include_optional) {
  euer_zeile_t* euer_zeile = NULL;
  if (include_optional) {
    euer_zeile = euer_zeile_create(
      "0",
      "0",
      "0",
      56
    );
  } else {
    euer_zeile = euer_zeile_create(
      "0",
      "0",
      "0",
      56
    );
  }

  return euer_zeile;
}


#ifdef euer_zeile_MAIN

void test_euer_zeile(int include_optional) {
    euer_zeile_t* euer_zeile_1 = instantiate_euer_zeile(include_optional);

	cJSON* jsoneuer_zeile_1 = euer_zeile_convertToJSON(euer_zeile_1);
	printf("euer_zeile :\n%s\n", cJSON_Print(jsoneuer_zeile_1));
	euer_zeile_t* euer_zeile_2 = euer_zeile_parseFromJSON(jsoneuer_zeile_1);
	cJSON* jsoneuer_zeile_2 = euer_zeile_convertToJSON(euer_zeile_2);
	printf("repeating euer_zeile:\n%s\n", cJSON_Print(jsoneuer_zeile_2));
}

int main() {
  test_euer_zeile(1);
  test_euer_zeile(0);

  printf("Hello world \n");
  return 0;
}

#endif // euer_zeile_MAIN
#endif // euer_zeile_TEST
