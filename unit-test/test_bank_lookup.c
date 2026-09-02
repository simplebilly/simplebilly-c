#ifndef bank_lookup_TEST
#define bank_lookup_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bank_lookup_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bank_lookup.h"
bank_lookup_t* instantiate_bank_lookup(int include_optional);



bank_lookup_t* instantiate_bank_lookup(int include_optional) {
  bank_lookup_t* bank_lookup = NULL;
  if (include_optional) {
    bank_lookup = bank_lookup_create(
      "0",
      "0",
      "0",
      "0",
      1
    );
  } else {
    bank_lookup = bank_lookup_create(
      "0",
      "0",
      "0",
      "0",
      1
    );
  }

  return bank_lookup;
}


#ifdef bank_lookup_MAIN

void test_bank_lookup(int include_optional) {
    bank_lookup_t* bank_lookup_1 = instantiate_bank_lookup(include_optional);

	cJSON* jsonbank_lookup_1 = bank_lookup_convertToJSON(bank_lookup_1);
	printf("bank_lookup :\n%s\n", cJSON_Print(jsonbank_lookup_1));
	bank_lookup_t* bank_lookup_2 = bank_lookup_parseFromJSON(jsonbank_lookup_1);
	cJSON* jsonbank_lookup_2 = bank_lookup_convertToJSON(bank_lookup_2);
	printf("repeating bank_lookup:\n%s\n", cJSON_Print(jsonbank_lookup_2));
}

int main() {
  test_bank_lookup(1);
  test_bank_lookup(0);

  printf("Hello world \n");
  return 0;
}

#endif // bank_lookup_MAIN
#endif // bank_lookup_TEST
