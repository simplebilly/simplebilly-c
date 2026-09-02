#ifndef sepa_direct_debit_response_TEST
#define sepa_direct_debit_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sepa_direct_debit_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sepa_direct_debit_response.h"
sepa_direct_debit_response_t* instantiate_sepa_direct_debit_response(int include_optional);



sepa_direct_debit_response_t* instantiate_sepa_direct_debit_response(int include_optional) {
  sepa_direct_debit_response_t* sepa_direct_debit_response = NULL;
  if (include_optional) {
    sepa_direct_debit_response = sepa_direct_debit_response_create(
      "0",
      "0",
      "0"
    );
  } else {
    sepa_direct_debit_response = sepa_direct_debit_response_create(
      "0",
      "0",
      "0"
    );
  }

  return sepa_direct_debit_response;
}


#ifdef sepa_direct_debit_response_MAIN

void test_sepa_direct_debit_response(int include_optional) {
    sepa_direct_debit_response_t* sepa_direct_debit_response_1 = instantiate_sepa_direct_debit_response(include_optional);

	cJSON* jsonsepa_direct_debit_response_1 = sepa_direct_debit_response_convertToJSON(sepa_direct_debit_response_1);
	printf("sepa_direct_debit_response :\n%s\n", cJSON_Print(jsonsepa_direct_debit_response_1));
	sepa_direct_debit_response_t* sepa_direct_debit_response_2 = sepa_direct_debit_response_parseFromJSON(jsonsepa_direct_debit_response_1);
	cJSON* jsonsepa_direct_debit_response_2 = sepa_direct_debit_response_convertToJSON(sepa_direct_debit_response_2);
	printf("repeating sepa_direct_debit_response:\n%s\n", cJSON_Print(jsonsepa_direct_debit_response_2));
}

int main() {
  test_sepa_direct_debit_response(1);
  test_sepa_direct_debit_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // sepa_direct_debit_response_MAIN
#endif // sepa_direct_debit_response_TEST
