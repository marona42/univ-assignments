void main(int argc, char *argv[])
{ //적당히 고쳐서 사용하세요
    if ((yyin = fopen(argv[argc - 1], "r")) == NULL)
    {
        printf("can not open input file: %s\n", argv[argc - 1]);
        exit(1);
    }
    initialize();
    yyparse();
    if (!syntax_err)
        print_ast(root);
}