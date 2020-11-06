#include <stdio.h>
#include <string.h>
#include <yaml.h>

int main(void) {
    FILE* fh = fopen("FR_fr.yaml", "r");
    yaml_parser_t parser;
    yaml_token_t token;
   

    if (!yaml_parser_initialize(&parser))
        fputs("Failed to initialize parser!\n", stderr);
    if (fh == NULL)
        fputs("Failed to open file!\n", stderr);
    yaml_parser_set_input_file(&parser, fh);


    /* As this is an example, I'll just use:
     *  state = 0 = expect key
     *  state = 1 = expect value
     */
    int state = 0;
    char** datap;
    char* tk;

    do {
        yaml_parser_scan(&parser, &token);
        switch(token.type) {
            case YAML_KEY_TOKEN:     state = 0; break;
            case YAML_VALUE_TOKEN:   state = 1; break;
            case YAML_SCALAR_TOKEN:
                tk = token.data.scalar.value;
                if (state == 0) {
                    printf("test %s ", tk);
                }
                break;
           default: break;
           }
       if (token.type != YAML_STREAM_END_TOKEN)
           yaml_token_delete(&token);
   } while (token.type != YAML_STREAM_END_TOKEN);
    puts("\nfin");
   yaml_token_delete(&token);
   yaml_parser_delete(&parser);
   fclose(fh);
     
return EXIT_SUCCESS;
 }  