#ifndef country_code_TEST
#define country_code_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define country_code_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/country_code.h"
country_code_t* instantiate_country_code(int include_optional);



country_code_t* instantiate_country_code(int include_optional) {
  country_code_t* country_code = NULL;
  if (include_optional) {
    country_code = country_code_create(
    );
  } else {
    country_code = country_code_create(
    );
  }

  return country_code;
}


#ifdef country_code_MAIN

void test_country_code(int include_optional) {
    country_code_t* country_code_1 = instantiate_country_code(include_optional);

	cJSON* jsoncountry_code_1 = country_code_convertToJSON(country_code_1);
	printf("country_code :\n%s\n", cJSON_Print(jsoncountry_code_1));
	country_code_t* country_code_2 = country_code_parseFromJSON(jsoncountry_code_1);
	cJSON* jsoncountry_code_2 = country_code_convertToJSON(country_code_2);
	printf("repeating country_code:\n%s\n", cJSON_Print(jsoncountry_code_2));
}

int main() {
  test_country_code(1);
  test_country_code(0);

  printf("Hello world \n");
  return 0;
}

#endif // country_code_MAIN
#endif // country_code_TEST
