#ifndef ghg_scope_TEST
#define ghg_scope_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ghg_scope_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ghg_scope.h"
ghg_scope_t* instantiate_ghg_scope(int include_optional);



ghg_scope_t* instantiate_ghg_scope(int include_optional) {
  ghg_scope_t* ghg_scope = NULL;
  if (include_optional) {
    ghg_scope = ghg_scope_create(
    );
  } else {
    ghg_scope = ghg_scope_create(
    );
  }

  return ghg_scope;
}


#ifdef ghg_scope_MAIN

void test_ghg_scope(int include_optional) {
    ghg_scope_t* ghg_scope_1 = instantiate_ghg_scope(include_optional);

	cJSON* jsonghg_scope_1 = ghg_scope_convertToJSON(ghg_scope_1);
	printf("ghg_scope :\n%s\n", cJSON_Print(jsonghg_scope_1));
	ghg_scope_t* ghg_scope_2 = ghg_scope_parseFromJSON(jsonghg_scope_1);
	cJSON* jsonghg_scope_2 = ghg_scope_convertToJSON(ghg_scope_2);
	printf("repeating ghg_scope:\n%s\n", cJSON_Print(jsonghg_scope_2));
}

int main() {
  test_ghg_scope(1);
  test_ghg_scope(0);

  printf("Hello world \n");
  return 0;
}

#endif // ghg_scope_MAIN
#endif // ghg_scope_TEST
