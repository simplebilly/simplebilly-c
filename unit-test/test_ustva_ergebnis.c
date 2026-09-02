#ifndef ustva_ergebnis_TEST
#define ustva_ergebnis_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ustva_ergebnis_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ustva_ergebnis.h"
ustva_ergebnis_t* instantiate_ustva_ergebnis(int include_optional);



ustva_ergebnis_t* instantiate_ustva_ergebnis(int include_optional) {
  ustva_ergebnis_t* ustva_ergebnis = NULL;
  if (include_optional) {
    ustva_ergebnis = ustva_ergebnis_create(
      "0",
      "0",
      1,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    ustva_ergebnis = ustva_ergebnis_create(
      "0",
      "0",
      1,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return ustva_ergebnis;
}


#ifdef ustva_ergebnis_MAIN

void test_ustva_ergebnis(int include_optional) {
    ustva_ergebnis_t* ustva_ergebnis_1 = instantiate_ustva_ergebnis(include_optional);

	cJSON* jsonustva_ergebnis_1 = ustva_ergebnis_convertToJSON(ustva_ergebnis_1);
	printf("ustva_ergebnis :\n%s\n", cJSON_Print(jsonustva_ergebnis_1));
	ustva_ergebnis_t* ustva_ergebnis_2 = ustva_ergebnis_parseFromJSON(jsonustva_ergebnis_1);
	cJSON* jsonustva_ergebnis_2 = ustva_ergebnis_convertToJSON(ustva_ergebnis_2);
	printf("repeating ustva_ergebnis:\n%s\n", cJSON_Print(jsonustva_ergebnis_2));
}

int main() {
  test_ustva_ergebnis(1);
  test_ustva_ergebnis(0);

  printf("Hello world \n");
  return 0;
}

#endif // ustva_ergebnis_MAIN
#endif // ustva_ergebnis_TEST
