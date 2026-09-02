#ifndef emissions_export_response_TEST
#define emissions_export_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define emissions_export_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/emissions_export_response.h"
emissions_export_response_t* instantiate_emissions_export_response(int include_optional);



emissions_export_response_t* instantiate_emissions_export_response(int include_optional) {
  emissions_export_response_t* emissions_export_response = NULL;
  if (include_optional) {
    emissions_export_response = emissions_export_response_create(
      "0",
      "0"
    );
  } else {
    emissions_export_response = emissions_export_response_create(
      "0",
      "0"
    );
  }

  return emissions_export_response;
}


#ifdef emissions_export_response_MAIN

void test_emissions_export_response(int include_optional) {
    emissions_export_response_t* emissions_export_response_1 = instantiate_emissions_export_response(include_optional);

	cJSON* jsonemissions_export_response_1 = emissions_export_response_convertToJSON(emissions_export_response_1);
	printf("emissions_export_response :\n%s\n", cJSON_Print(jsonemissions_export_response_1));
	emissions_export_response_t* emissions_export_response_2 = emissions_export_response_parseFromJSON(jsonemissions_export_response_1);
	cJSON* jsonemissions_export_response_2 = emissions_export_response_convertToJSON(emissions_export_response_2);
	printf("repeating emissions_export_response:\n%s\n", cJSON_Print(jsonemissions_export_response_2));
}

int main() {
  test_emissions_export_response(1);
  test_emissions_export_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // emissions_export_response_MAIN
#endif // emissions_export_response_TEST
