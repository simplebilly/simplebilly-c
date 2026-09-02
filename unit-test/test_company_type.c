#ifndef company_type_TEST
#define company_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define company_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/company_type.h"
company_type_t* instantiate_company_type(int include_optional);



company_type_t* instantiate_company_type(int include_optional) {
  company_type_t* company_type = NULL;
  if (include_optional) {
    company_type = company_type_create(
    );
  } else {
    company_type = company_type_create(
    );
  }

  return company_type;
}


#ifdef company_type_MAIN

void test_company_type(int include_optional) {
    company_type_t* company_type_1 = instantiate_company_type(include_optional);

	cJSON* jsoncompany_type_1 = company_type_convertToJSON(company_type_1);
	printf("company_type :\n%s\n", cJSON_Print(jsoncompany_type_1));
	company_type_t* company_type_2 = company_type_parseFromJSON(jsoncompany_type_1);
	cJSON* jsoncompany_type_2 = company_type_convertToJSON(company_type_2);
	printf("repeating company_type:\n%s\n", cJSON_Print(jsoncompany_type_2));
}

int main() {
  test_company_type(1);
  test_company_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // company_type_MAIN
#endif // company_type_TEST
