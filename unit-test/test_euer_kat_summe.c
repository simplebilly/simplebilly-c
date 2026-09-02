#ifndef euer_kat_summe_TEST
#define euer_kat_summe_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define euer_kat_summe_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/euer_kat_summe.h"
euer_kat_summe_t* instantiate_euer_kat_summe(int include_optional);



euer_kat_summe_t* instantiate_euer_kat_summe(int include_optional) {
  euer_kat_summe_t* euer_kat_summe = NULL;
  if (include_optional) {
    euer_kat_summe = euer_kat_summe_create(
      "0",
      "0"
    );
  } else {
    euer_kat_summe = euer_kat_summe_create(
      "0",
      "0"
    );
  }

  return euer_kat_summe;
}


#ifdef euer_kat_summe_MAIN

void test_euer_kat_summe(int include_optional) {
    euer_kat_summe_t* euer_kat_summe_1 = instantiate_euer_kat_summe(include_optional);

	cJSON* jsoneuer_kat_summe_1 = euer_kat_summe_convertToJSON(euer_kat_summe_1);
	printf("euer_kat_summe :\n%s\n", cJSON_Print(jsoneuer_kat_summe_1));
	euer_kat_summe_t* euer_kat_summe_2 = euer_kat_summe_parseFromJSON(jsoneuer_kat_summe_1);
	cJSON* jsoneuer_kat_summe_2 = euer_kat_summe_convertToJSON(euer_kat_summe_2);
	printf("repeating euer_kat_summe:\n%s\n", cJSON_Print(jsoneuer_kat_summe_2));
}

int main() {
  test_euer_kat_summe(1);
  test_euer_kat_summe(0);

  printf("Hello world \n");
  return 0;
}

#endif // euer_kat_summe_MAIN
#endif // euer_kat_summe_TEST
