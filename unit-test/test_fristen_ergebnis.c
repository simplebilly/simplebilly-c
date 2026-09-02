#ifndef fristen_ergebnis_TEST
#define fristen_ergebnis_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define fristen_ergebnis_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/fristen_ergebnis.h"
fristen_ergebnis_t* instantiate_fristen_ergebnis(int include_optional);



fristen_ergebnis_t* instantiate_fristen_ergebnis(int include_optional) {
  fristen_ergebnis_t* fristen_ergebnis = NULL;
  if (include_optional) {
    fristen_ergebnis = fristen_ergebnis_create(
      0,
      list_createList()
    );
  } else {
    fristen_ergebnis = fristen_ergebnis_create(
      0,
      list_createList()
    );
  }

  return fristen_ergebnis;
}


#ifdef fristen_ergebnis_MAIN

void test_fristen_ergebnis(int include_optional) {
    fristen_ergebnis_t* fristen_ergebnis_1 = instantiate_fristen_ergebnis(include_optional);

	cJSON* jsonfristen_ergebnis_1 = fristen_ergebnis_convertToJSON(fristen_ergebnis_1);
	printf("fristen_ergebnis :\n%s\n", cJSON_Print(jsonfristen_ergebnis_1));
	fristen_ergebnis_t* fristen_ergebnis_2 = fristen_ergebnis_parseFromJSON(jsonfristen_ergebnis_1);
	cJSON* jsonfristen_ergebnis_2 = fristen_ergebnis_convertToJSON(fristen_ergebnis_2);
	printf("repeating fristen_ergebnis:\n%s\n", cJSON_Print(jsonfristen_ergebnis_2));
}

int main() {
  test_fristen_ergebnis(1);
  test_fristen_ergebnis(0);

  printf("Hello world \n");
  return 0;
}

#endif // fristen_ergebnis_MAIN
#endif // fristen_ergebnis_TEST
