#ifndef emission_factor_response_TEST
#define emission_factor_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define emission_factor_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/emission_factor_response.h"
emission_factor_response_t* instantiate_emission_factor_response(int include_optional);



emission_factor_response_t* instantiate_emission_factor_response(int include_optional) {
  emission_factor_response_t* emission_factor_response = NULL;
  if (include_optional) {
    emission_factor_response = emission_factor_response_create(
      "0",
      1.337,
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    emission_factor_response = emission_factor_response_create(
      "0",
      1.337,
      "0",
      "0",
      "0",
      "0"
    );
  }

  return emission_factor_response;
}


#ifdef emission_factor_response_MAIN

void test_emission_factor_response(int include_optional) {
    emission_factor_response_t* emission_factor_response_1 = instantiate_emission_factor_response(include_optional);

	cJSON* jsonemission_factor_response_1 = emission_factor_response_convertToJSON(emission_factor_response_1);
	printf("emission_factor_response :\n%s\n", cJSON_Print(jsonemission_factor_response_1));
	emission_factor_response_t* emission_factor_response_2 = emission_factor_response_parseFromJSON(jsonemission_factor_response_1);
	cJSON* jsonemission_factor_response_2 = emission_factor_response_convertToJSON(emission_factor_response_2);
	printf("repeating emission_factor_response:\n%s\n", cJSON_Print(jsonemission_factor_response_2));
}

int main() {
  test_emission_factor_response(1);
  test_emission_factor_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // emission_factor_response_MAIN
#endif // emission_factor_response_TEST
