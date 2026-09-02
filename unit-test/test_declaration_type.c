#ifndef declaration_type_TEST
#define declaration_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define declaration_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/declaration_type.h"
declaration_type_t* instantiate_declaration_type(int include_optional);



declaration_type_t* instantiate_declaration_type(int include_optional) {
  declaration_type_t* declaration_type = NULL;
  if (include_optional) {
    declaration_type = declaration_type_create(
    );
  } else {
    declaration_type = declaration_type_create(
    );
  }

  return declaration_type;
}


#ifdef declaration_type_MAIN

void test_declaration_type(int include_optional) {
    declaration_type_t* declaration_type_1 = instantiate_declaration_type(include_optional);

	cJSON* jsondeclaration_type_1 = declaration_type_convertToJSON(declaration_type_1);
	printf("declaration_type :\n%s\n", cJSON_Print(jsondeclaration_type_1));
	declaration_type_t* declaration_type_2 = declaration_type_parseFromJSON(jsondeclaration_type_1);
	cJSON* jsondeclaration_type_2 = declaration_type_convertToJSON(declaration_type_2);
	printf("repeating declaration_type:\n%s\n", cJSON_Print(jsondeclaration_type_2));
}

int main() {
  test_declaration_type(1);
  test_declaration_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // declaration_type_MAIN
#endif // declaration_type_TEST
