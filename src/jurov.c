#include "stdio.h"
#include "parser.h"

int compile(FILE *stream)
{
    ast *tree;
    int res = 0;
    res = parse_file(stream, &tree);
    delete_parser(tree);
    return res;
}

int main(int argc, char **argv)
{
    int res;
    FILE *source;

    switch(argc) 
    {
        case 2:
            source = fopen(argv[1], "r");
            if(source == NULL) {
                fprintf(stderr, "Could not open file %s\n", argv[1]);
                return 1;
            }
            res = compile(source);
            fclose(source);
            return res;
        default:
            fprintf(stderr, "Usage: jurov <file>\n");
            return 1;
    }
    return 1;
}
