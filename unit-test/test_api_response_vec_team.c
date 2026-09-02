#ifndef api_response_vec_team_TEST
#define api_response_vec_team_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define api_response_vec_team_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/api_response_vec_team.h"
api_response_vec_team_t* instantiate_api_response_vec_team(int include_optional);



api_response_vec_team_t* instantiate_api_response_vec_team(int include_optional) {
  api_response_vec_team_t* api_response_vec_team = NULL;
  if (include_optional) {
    api_response_vec_team = api_response_vec_team_create(
      list_createList(),
      "0",
      "0",
      1
    );
  } else {
    api_response_vec_team = api_response_vec_team_create(
      list_createList(),
      "0",
      "0",
      1
    );
  }

  return api_response_vec_team;
}


#ifdef api_response_vec_team_MAIN

void test_api_response_vec_team(int include_optional) {
    api_response_vec_team_t* api_response_vec_team_1 = instantiate_api_response_vec_team(include_optional);

	cJSON* jsonapi_response_vec_team_1 = api_response_vec_team_convertToJSON(api_response_vec_team_1);
	printf("api_response_vec_team :\n%s\n", cJSON_Print(jsonapi_response_vec_team_1));
	api_response_vec_team_t* api_response_vec_team_2 = api_response_vec_team_parseFromJSON(jsonapi_response_vec_team_1);
	cJSON* jsonapi_response_vec_team_2 = api_response_vec_team_convertToJSON(api_response_vec_team_2);
	printf("repeating api_response_vec_team:\n%s\n", cJSON_Print(jsonapi_response_vec_team_2));
}

int main() {
  test_api_response_vec_team(1);
  test_api_response_vec_team(0);

  printf("Hello world \n");
  return 0;
}

#endif // api_response_vec_team_MAIN
#endif // api_response_vec_team_TEST
