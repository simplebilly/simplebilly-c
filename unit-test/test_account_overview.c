#ifndef account_overview_TEST
#define account_overview_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define account_overview_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/account_overview.h"
account_overview_t* instantiate_account_overview(int include_optional);



account_overview_t* instantiate_account_overview(int include_optional) {
  account_overview_t* account_overview = NULL;
  if (include_optional) {
    account_overview = account_overview_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    account_overview = account_overview_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return account_overview;
}


#ifdef account_overview_MAIN

void test_account_overview(int include_optional) {
    account_overview_t* account_overview_1 = instantiate_account_overview(include_optional);

	cJSON* jsonaccount_overview_1 = account_overview_convertToJSON(account_overview_1);
	printf("account_overview :\n%s\n", cJSON_Print(jsonaccount_overview_1));
	account_overview_t* account_overview_2 = account_overview_parseFromJSON(jsonaccount_overview_1);
	cJSON* jsonaccount_overview_2 = account_overview_convertToJSON(account_overview_2);
	printf("repeating account_overview:\n%s\n", cJSON_Print(jsonaccount_overview_2));
}

int main() {
  test_account_overview(1);
  test_account_overview(0);

  printf("Hello world \n");
  return 0;
}

#endif // account_overview_MAIN
#endif // account_overview_TEST
