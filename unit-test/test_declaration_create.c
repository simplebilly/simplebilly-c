#ifndef declaration_create_TEST
#define declaration_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define declaration_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/declaration_create.h"
declaration_create_t* instantiate_declaration_create(int include_optional);



declaration_create_t* instantiate_declaration_create(int include_optional) {
  declaration_create_t* declaration_create = NULL;
  if (include_optional) {
    declaration_create = declaration_create_create(
      dcgk,
      1,
      "0",
      "2013-10-20",
      "0"
    );
  } else {
    declaration_create = declaration_create_create(
      dcgk,
      1,
      "0",
      "2013-10-20",
      "0"
    );
  }

  return declaration_create;
}


#ifdef declaration_create_MAIN

void test_declaration_create(int include_optional) {
    declaration_create_t* declaration_create_1 = instantiate_declaration_create(include_optional);

	cJSON* jsondeclaration_create_1 = declaration_create_convertToJSON(declaration_create_1);
	printf("declaration_create :\n%s\n", cJSON_Print(jsondeclaration_create_1));
	declaration_create_t* declaration_create_2 = declaration_create_parseFromJSON(jsondeclaration_create_1);
	cJSON* jsondeclaration_create_2 = declaration_create_convertToJSON(declaration_create_2);
	printf("repeating declaration_create:\n%s\n", cJSON_Print(jsondeclaration_create_2));
}

int main() {
  test_declaration_create(1);
  test_declaration_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // declaration_create_MAIN
#endif // declaration_create_TEST
