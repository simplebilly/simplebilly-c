#ifndef import_start_response_TEST
#define import_start_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define import_start_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/import_start_response.h"
import_start_response_t* instantiate_import_start_response(int include_optional);



import_start_response_t* instantiate_import_start_response(int include_optional) {
  import_start_response_t* import_start_response = NULL;
  if (include_optional) {
    import_start_response = import_start_response_create(
      "0"
    );
  } else {
    import_start_response = import_start_response_create(
      "0"
    );
  }

  return import_start_response;
}


#ifdef import_start_response_MAIN

void test_import_start_response(int include_optional) {
    import_start_response_t* import_start_response_1 = instantiate_import_start_response(include_optional);

	cJSON* jsonimport_start_response_1 = import_start_response_convertToJSON(import_start_response_1);
	printf("import_start_response :\n%s\n", cJSON_Print(jsonimport_start_response_1));
	import_start_response_t* import_start_response_2 = import_start_response_parseFromJSON(jsonimport_start_response_1);
	cJSON* jsonimport_start_response_2 = import_start_response_convertToJSON(import_start_response_2);
	printf("repeating import_start_response:\n%s\n", cJSON_Print(jsonimport_start_response_2));
}

int main() {
  test_import_start_response(1);
  test_import_start_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // import_start_response_MAIN
#endif // import_start_response_TEST
