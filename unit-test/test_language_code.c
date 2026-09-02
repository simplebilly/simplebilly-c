#ifndef language_code_TEST
#define language_code_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define language_code_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/language_code.h"
language_code_t* instantiate_language_code(int include_optional);



language_code_t* instantiate_language_code(int include_optional) {
  language_code_t* language_code = NULL;
  if (include_optional) {
    language_code = language_code_create(
    );
  } else {
    language_code = language_code_create(
    );
  }

  return language_code;
}


#ifdef language_code_MAIN

void test_language_code(int include_optional) {
    language_code_t* language_code_1 = instantiate_language_code(include_optional);

	cJSON* jsonlanguage_code_1 = language_code_convertToJSON(language_code_1);
	printf("language_code :\n%s\n", cJSON_Print(jsonlanguage_code_1));
	language_code_t* language_code_2 = language_code_parseFromJSON(jsonlanguage_code_1);
	cJSON* jsonlanguage_code_2 = language_code_convertToJSON(language_code_2);
	printf("repeating language_code:\n%s\n", cJSON_Print(jsonlanguage_code_2));
}

int main() {
  test_language_code(1);
  test_language_code(0);

  printf("Hello world \n");
  return 0;
}

#endif // language_code_MAIN
#endif // language_code_TEST
