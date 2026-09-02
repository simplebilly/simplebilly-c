#ifndef currency_code_TEST
#define currency_code_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define currency_code_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/currency_code.h"
currency_code_t* instantiate_currency_code(int include_optional);



currency_code_t* instantiate_currency_code(int include_optional) {
  currency_code_t* currency_code = NULL;
  if (include_optional) {
    currency_code = currency_code_create(
    );
  } else {
    currency_code = currency_code_create(
    );
  }

  return currency_code;
}


#ifdef currency_code_MAIN

void test_currency_code(int include_optional) {
    currency_code_t* currency_code_1 = instantiate_currency_code(include_optional);

	cJSON* jsoncurrency_code_1 = currency_code_convertToJSON(currency_code_1);
	printf("currency_code :\n%s\n", cJSON_Print(jsoncurrency_code_1));
	currency_code_t* currency_code_2 = currency_code_parseFromJSON(jsoncurrency_code_1);
	cJSON* jsoncurrency_code_2 = currency_code_convertToJSON(currency_code_2);
	printf("repeating currency_code:\n%s\n", cJSON_Print(jsoncurrency_code_2));
}

int main() {
  test_currency_code(1);
  test_currency_code(0);

  printf("Hello world \n");
  return 0;
}

#endif // currency_code_MAIN
#endif // currency_code_TEST
