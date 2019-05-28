%{
    #include "y.tab.c"
%}
%%
a {return A;}
b {return B;}
.|\n {return '\n';}
%%