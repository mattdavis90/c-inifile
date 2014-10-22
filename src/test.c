#include "inifile.h"

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        printf("Please supply an INIfile to parse\n");
        printf("%s <inifile>\n", argv[0]);
        return 1;
    }

    struct ini_section *sections = read_ini(argv[1]);
    struct ini_section *curr_section = sections;

    printf("Test printing the INIfile\n");

    while(curr_section != NULL)
    {
        struct ini_property *properties = curr_section->properties;
        struct ini_property *curr_property = properties;

        printf("Section %s\n", curr_section->name);

        while(curr_property != NULL)
        {
            printf("\t%s: %s\n", curr_property->key, curr_property->value);

            curr_property = curr_property->next_property;
        }

        curr_section = curr_section->next_section;
    }

    printf("\n");

    curr_section = get_ini_section(sections, "Section2");
    if(curr_section != NULL)
    {
        printf("Found section 2 [PASS]\n");

        if(get_ini_property(curr_section, "prop2") != NULL)
        {
            printf("Found property prop2 [PASS]\n");
        }
        else
        {
            printf("Couldn't find property prop2 [FAIL]\n");
        }

        if(get_ini_property(curr_section, "notexist") == NULL)
        {
            printf("Couldn't find property notexist [PASS]\n");
        }
        else
        {
            printf("Found property notexist [FAIL]\n");
        }
    }
    else
    {
        printf("Couldn't find section 2 [FAIL]\n");
    }
    
    curr_section = get_ini_section(sections, "Section4");
    if(curr_section == NULL)
    {
        printf("Couldn't find section 4 [PASS]\n");
    }
    else
    {
        printf("Found section 4 [FAIL]\n");
    }

    return 0;
}
