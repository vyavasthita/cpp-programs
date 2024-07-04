#include <tc.h>
#include <workspaceobject.h>

int ITK_user_main(int argc, char* argv[])
{

	int status, count;
	tag_t* objects;
	char *text;

	char name[WSO_name_size_c +1];
	char description[WSO_desc_size_c +1];

	strcpy(name, "test_name");
	status = WSOM_find(name, &count, &objects);

	if (status != ITK_ok) 
	{
		EMH_ask_error_text(status, &text);
		printf("Error with WSOM_find: \"%d\", \"%s\"\n", status, text);
		MEM_free(text);
		return status;
	}

	for(int i = 0; i < count; i++) 
	{
		status = WSOM_ask_description(objects[i], description);

		if (status != ITK_ok) 
		{
			EMH_ask_error_text(status, &text);
			printf("Error with WSOM_ask_description: \"%d\", \"%s\"\n",status, text);
			MEM_free(text);
			return (status);
		}

		printf ("Name: %s; Description: %s\n", name, description);

	}
	MEM_free(objects);
	return 0;

}