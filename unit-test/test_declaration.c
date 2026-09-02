#ifndef declaration_TEST
#define declaration_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define declaration_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/declaration.h"
declaration_t* instantiate_declaration(int include_optional);



declaration_t* instantiate_declaration(int include_optional) {
  declaration_t* declaration = NULL;
  if (include_optional) {
    declaration = declaration_create(
      dcgk,
      1,
      "0",
      "2013-10-20",
      "0"
    );
  } else {
    declaration = declaration_create(
      dcgk,
      1,
      "0",
      "2013-10-20",
      "0"
    );
  }

  return declaration;
}


#ifdef declaration_MAIN

void test_declaration(int include_optional) {
    declaration_t* declaration_1 = instantiate_declaration(include_optional);

	cJSON* jsondeclaration_1 = declaration_convertToJSON(declaration_1);
	printf("declaration :\n%s\n", cJSON_Print(jsondeclaration_1));
	declaration_t* declaration_2 = declaration_parseFromJSON(jsondeclaration_1);
	cJSON* jsondeclaration_2 = declaration_convertToJSON(declaration_2);
	printf("repeating declaration:\n%s\n", cJSON_Print(jsondeclaration_2));
}

int main() {
  test_declaration(1);
  test_declaration(0);

  printf("Hello world \n");
  return 0;
}

#endif // declaration_MAIN
#endif // declaration_TEST
