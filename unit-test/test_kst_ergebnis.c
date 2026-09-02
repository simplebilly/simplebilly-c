#ifndef kst_ergebnis_TEST
#define kst_ergebnis_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define kst_ergebnis_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/kst_ergebnis.h"
kst_ergebnis_t* instantiate_kst_ergebnis(int include_optional);



kst_ergebnis_t* instantiate_kst_ergebnis(int include_optional) {
  kst_ergebnis_t* kst_ergebnis = NULL;
  if (include_optional) {
    kst_ergebnis = kst_ergebnis_create(
      "0",
      "0",
      "0",
      "0",
      1,
      56,
      "0",
      "0"
    );
  } else {
    kst_ergebnis = kst_ergebnis_create(
      "0",
      "0",
      "0",
      "0",
      1,
      56,
      "0",
      "0"
    );
  }

  return kst_ergebnis;
}


#ifdef kst_ergebnis_MAIN

void test_kst_ergebnis(int include_optional) {
    kst_ergebnis_t* kst_ergebnis_1 = instantiate_kst_ergebnis(include_optional);

	cJSON* jsonkst_ergebnis_1 = kst_ergebnis_convertToJSON(kst_ergebnis_1);
	printf("kst_ergebnis :\n%s\n", cJSON_Print(jsonkst_ergebnis_1));
	kst_ergebnis_t* kst_ergebnis_2 = kst_ergebnis_parseFromJSON(jsonkst_ergebnis_1);
	cJSON* jsonkst_ergebnis_2 = kst_ergebnis_convertToJSON(kst_ergebnis_2);
	printf("repeating kst_ergebnis:\n%s\n", cJSON_Print(jsonkst_ergebnis_2));
}

int main() {
  test_kst_ergebnis(1);
  test_kst_ergebnis(0);

  printf("Hello world \n");
  return 0;
}

#endif // kst_ergebnis_MAIN
#endif // kst_ergebnis_TEST
