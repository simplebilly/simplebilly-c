#ifndef tax_rate_create_TEST
#define tax_rate_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define tax_rate_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/tax_rate_create.h"
tax_rate_create_t* instantiate_tax_rate_create(int include_optional);



tax_rate_create_t* instantiate_tax_rate_create(int include_optional) {
  tax_rate_create_t* tax_rate_create = NULL;
  if (include_optional) {
    tax_rate_create = tax_rate_create_create(
      "0",
      "2013-10-20",
      1,
      "0",
      56
    );
  } else {
    tax_rate_create = tax_rate_create_create(
      "0",
      "2013-10-20",
      1,
      "0",
      56
    );
  }

  return tax_rate_create;
}


#ifdef tax_rate_create_MAIN

void test_tax_rate_create(int include_optional) {
    tax_rate_create_t* tax_rate_create_1 = instantiate_tax_rate_create(include_optional);

	cJSON* jsontax_rate_create_1 = tax_rate_create_convertToJSON(tax_rate_create_1);
	printf("tax_rate_create :\n%s\n", cJSON_Print(jsontax_rate_create_1));
	tax_rate_create_t* tax_rate_create_2 = tax_rate_create_parseFromJSON(jsontax_rate_create_1);
	cJSON* jsontax_rate_create_2 = tax_rate_create_convertToJSON(tax_rate_create_2);
	printf("repeating tax_rate_create:\n%s\n", cJSON_Print(jsontax_rate_create_2));
}

int main() {
  test_tax_rate_create(1);
  test_tax_rate_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // tax_rate_create_MAIN
#endif // tax_rate_create_TEST
