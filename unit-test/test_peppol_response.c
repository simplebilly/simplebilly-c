#ifndef peppol_response_TEST
#define peppol_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define peppol_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/peppol_response.h"
peppol_response_t* instantiate_peppol_response(int include_optional);



peppol_response_t* instantiate_peppol_response(int include_optional) {
  peppol_response_t* peppol_response = NULL;
  if (include_optional) {
    peppol_response = peppol_response_create(
      "0",
      "0",
      "0"
    );
  } else {
    peppol_response = peppol_response_create(
      "0",
      "0",
      "0"
    );
  }

  return peppol_response;
}


#ifdef peppol_response_MAIN

void test_peppol_response(int include_optional) {
    peppol_response_t* peppol_response_1 = instantiate_peppol_response(include_optional);

	cJSON* jsonpeppol_response_1 = peppol_response_convertToJSON(peppol_response_1);
	printf("peppol_response :\n%s\n", cJSON_Print(jsonpeppol_response_1));
	peppol_response_t* peppol_response_2 = peppol_response_parseFromJSON(jsonpeppol_response_1);
	cJSON* jsonpeppol_response_2 = peppol_response_convertToJSON(peppol_response_2);
	printf("repeating peppol_response:\n%s\n", cJSON_Print(jsonpeppol_response_2));
}

int main() {
  test_peppol_response(1);
  test_peppol_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // peppol_response_MAIN
#endif // peppol_response_TEST
