#ifndef gewinnverwendungs_zeile_TEST
#define gewinnverwendungs_zeile_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gewinnverwendungs_zeile_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gewinnverwendungs_zeile.h"
gewinnverwendungs_zeile_t* instantiate_gewinnverwendungs_zeile(int include_optional);



gewinnverwendungs_zeile_t* instantiate_gewinnverwendungs_zeile(int include_optional) {
  gewinnverwendungs_zeile_t* gewinnverwendungs_zeile = NULL;
  if (include_optional) {
    gewinnverwendungs_zeile = gewinnverwendungs_zeile_create(
      "0",
      "0"
    );
  } else {
    gewinnverwendungs_zeile = gewinnverwendungs_zeile_create(
      "0",
      "0"
    );
  }

  return gewinnverwendungs_zeile;
}


#ifdef gewinnverwendungs_zeile_MAIN

void test_gewinnverwendungs_zeile(int include_optional) {
    gewinnverwendungs_zeile_t* gewinnverwendungs_zeile_1 = instantiate_gewinnverwendungs_zeile(include_optional);

	cJSON* jsongewinnverwendungs_zeile_1 = gewinnverwendungs_zeile_convertToJSON(gewinnverwendungs_zeile_1);
	printf("gewinnverwendungs_zeile :\n%s\n", cJSON_Print(jsongewinnverwendungs_zeile_1));
	gewinnverwendungs_zeile_t* gewinnverwendungs_zeile_2 = gewinnverwendungs_zeile_parseFromJSON(jsongewinnverwendungs_zeile_1);
	cJSON* jsongewinnverwendungs_zeile_2 = gewinnverwendungs_zeile_convertToJSON(gewinnverwendungs_zeile_2);
	printf("repeating gewinnverwendungs_zeile:\n%s\n", cJSON_Print(jsongewinnverwendungs_zeile_2));
}

int main() {
  test_gewinnverwendungs_zeile(1);
  test_gewinnverwendungs_zeile(0);

  printf("Hello world \n");
  return 0;
}

#endif // gewinnverwendungs_zeile_MAIN
#endif // gewinnverwendungs_zeile_TEST
