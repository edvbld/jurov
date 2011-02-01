extern "C" {
#include "jurov.tab.h"
#include "lex.yy.h"
}

#include <gtest/gtest.h>

TEST(LexerTest, LexingPublicStaticVoidMain) 
{
    yy_scan_string("public static void main");
    ASSERT_EQ(MAIN, yylex());
    ASSERT_EQ(0, yylex());
}
