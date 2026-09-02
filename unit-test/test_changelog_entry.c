#ifndef changelog_entry_TEST
#define changelog_entry_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define changelog_entry_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/changelog_entry.h"
changelog_entry_t* instantiate_changelog_entry(int include_optional);



changelog_entry_t* instantiate_changelog_entry(int include_optional) {
  changelog_entry_t* changelog_entry = NULL;
  if (include_optional) {
    changelog_entry = changelog_entry_create(
      "0",
      "0",
      "0"
    );
  } else {
    changelog_entry = changelog_entry_create(
      "0",
      "0",
      "0"
    );
  }

  return changelog_entry;
}


#ifdef changelog_entry_MAIN

void test_changelog_entry(int include_optional) {
    changelog_entry_t* changelog_entry_1 = instantiate_changelog_entry(include_optional);

	cJSON* jsonchangelog_entry_1 = changelog_entry_convertToJSON(changelog_entry_1);
	printf("changelog_entry :\n%s\n", cJSON_Print(jsonchangelog_entry_1));
	changelog_entry_t* changelog_entry_2 = changelog_entry_parseFromJSON(jsonchangelog_entry_1);
	cJSON* jsonchangelog_entry_2 = changelog_entry_convertToJSON(changelog_entry_2);
	printf("repeating changelog_entry:\n%s\n", cJSON_Print(jsonchangelog_entry_2));
}

int main() {
  test_changelog_entry(1);
  test_changelog_entry(0);

  printf("Hello world \n");
  return 0;
}

#endif // changelog_entry_MAIN
#endif // changelog_entry_TEST
