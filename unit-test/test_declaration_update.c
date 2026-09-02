#ifndef declaration_update_TEST
#define declaration_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define declaration_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/declaration_update.h"
declaration_update_t* instantiate_declaration_update(int include_optional);



declaration_update_t* instantiate_declaration_update(int include_optional) {
  declaration_update_t* declaration_update = NULL;
  if (include_optional) {
    declaration_update = declaration_update_create(
      dcgk,
      1,
      "0",
      "2013-10-20",
      "0"
    );
  } else {
    declaration_update = declaration_update_create(
      dcgk,
      1,
      "0",
      "2013-10-20",
      "0"
    );
  }

  return declaration_update;
}


#ifdef declaration_update_MAIN

void test_declaration_update(int include_optional) {
    declaration_update_t* declaration_update_1 = instantiate_declaration_update(include_optional);

	cJSON* jsondeclaration_update_1 = declaration_update_convertToJSON(declaration_update_1);
	printf("declaration_update :\n%s\n", cJSON_Print(jsondeclaration_update_1));
	declaration_update_t* declaration_update_2 = declaration_update_parseFromJSON(jsondeclaration_update_1);
	cJSON* jsondeclaration_update_2 = declaration_update_convertToJSON(declaration_update_2);
	printf("repeating declaration_update:\n%s\n", cJSON_Print(jsondeclaration_update_2));
}

int main() {
  test_declaration_update(1);
  test_declaration_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // declaration_update_MAIN
#endif // declaration_update_TEST
