#ifndef ups_credentials_TEST
#define ups_credentials_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ups_credentials_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ups_credentials.h"
ups_credentials_t* instantiate_ups_credentials(int include_optional);



ups_credentials_t* instantiate_ups_credentials(int include_optional) {
  ups_credentials_t* ups_credentials = NULL;
  if (include_optional) {
    ups_credentials = ups_credentials_create(
      "0",
      "0",
      "0"
    );
  } else {
    ups_credentials = ups_credentials_create(
      "0",
      "0",
      "0"
    );
  }

  return ups_credentials;
}


#ifdef ups_credentials_MAIN

void test_ups_credentials(int include_optional) {
    ups_credentials_t* ups_credentials_1 = instantiate_ups_credentials(include_optional);

	cJSON* jsonups_credentials_1 = ups_credentials_convertToJSON(ups_credentials_1);
	printf("ups_credentials :\n%s\n", cJSON_Print(jsonups_credentials_1));
	ups_credentials_t* ups_credentials_2 = ups_credentials_parseFromJSON(jsonups_credentials_1);
	cJSON* jsonups_credentials_2 = ups_credentials_convertToJSON(ups_credentials_2);
	printf("repeating ups_credentials:\n%s\n", cJSON_Print(jsonups_credentials_2));
}

int main() {
  test_ups_credentials(1);
  test_ups_credentials(0);

  printf("Hello world \n");
  return 0;
}

#endif // ups_credentials_MAIN
#endif // ups_credentials_TEST
