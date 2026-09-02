#ifndef import_job_status_TEST
#define import_job_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define import_job_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/import_job_status.h"
import_job_status_t* instantiate_import_job_status(int include_optional);



import_job_status_t* instantiate_import_job_status(int include_optional) {
  import_job_status_t* import_job_status = NULL;
  if (include_optional) {
    import_job_status = import_job_status_create(
      "0",
      "0",
      0,
      0,
      "0",
      "0",
      "0",
      0
    );
  } else {
    import_job_status = import_job_status_create(
      "0",
      "0",
      0,
      0,
      "0",
      "0",
      "0",
      0
    );
  }

  return import_job_status;
}


#ifdef import_job_status_MAIN

void test_import_job_status(int include_optional) {
    import_job_status_t* import_job_status_1 = instantiate_import_job_status(include_optional);

	cJSON* jsonimport_job_status_1 = import_job_status_convertToJSON(import_job_status_1);
	printf("import_job_status :\n%s\n", cJSON_Print(jsonimport_job_status_1));
	import_job_status_t* import_job_status_2 = import_job_status_parseFromJSON(jsonimport_job_status_1);
	cJSON* jsonimport_job_status_2 = import_job_status_convertToJSON(import_job_status_2);
	printf("repeating import_job_status:\n%s\n", cJSON_Print(jsonimport_job_status_2));
}

int main() {
  test_import_job_status(1);
  test_import_job_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // import_job_status_MAIN
#endif // import_job_status_TEST
