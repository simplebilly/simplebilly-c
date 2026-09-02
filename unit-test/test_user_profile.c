#ifndef user_profile_TEST
#define user_profile_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define user_profile_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/user_profile.h"
user_profile_t* instantiate_user_profile(int include_optional);



user_profile_t* instantiate_user_profile(int include_optional) {
  user_profile_t* user_profile = NULL;
  if (include_optional) {
    user_profile = user_profile_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      1,
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    user_profile = user_profile_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      1,
      "0",
      "0",
      "0",
      "0"
    );
  }

  return user_profile;
}


#ifdef user_profile_MAIN

void test_user_profile(int include_optional) {
    user_profile_t* user_profile_1 = instantiate_user_profile(include_optional);

	cJSON* jsonuser_profile_1 = user_profile_convertToJSON(user_profile_1);
	printf("user_profile :\n%s\n", cJSON_Print(jsonuser_profile_1));
	user_profile_t* user_profile_2 = user_profile_parseFromJSON(jsonuser_profile_1);
	cJSON* jsonuser_profile_2 = user_profile_convertToJSON(user_profile_2);
	printf("repeating user_profile:\n%s\n", cJSON_Print(jsonuser_profile_2));
}

int main() {
  test_user_profile(1);
  test_user_profile(0);

  printf("Hello world \n");
  return 0;
}

#endif // user_profile_MAIN
#endif // user_profile_TEST
