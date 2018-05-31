#define CTEST_MAIN

#include "checkfile.h"
#include "displaylist.h"
#include "select.h"
#include <ctest.h>
#include <string.h>
#include <stdio.h>

CTEST (Check_Fake_File, Correct_Check)
{
    char a[256];
    strcpy(a,"Empty.txt");
    int result = Checkfile(a);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST (Check_File, Correct_Check)
{
    char a[256];
    strcpy(a,"testxt/testfile.txt");
    int result = Checkfile(a);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST (Check_Empty_File, Correct_Check)
{
    char a[256];
    strcpy(a,"testxt/testfile_empty.txt");
    int result = Checkfile(a);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST (Display_Empty_File, Correct_Check)
{
    char a[256];
    strcpy(a,"testxt/testfile_empty.txt");
    int result = Displaylist(a);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST (Display_Fake_File, Correct_Check)
{
    char a[256];
    strcpy(a,"Empty.txt");
    int result = Displaylist(a);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST (Display_File, Correct_Check)
{
    char a[256];
    strcpy(a,"testxt/testfile.txt");
    printf("\n");
    int result = Displaylist(a);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST (Select_InCorrect_Theme, Correct_Check)
{
    char a[256],tema[256];
    int choice=2;
    strcpy(a,"testxt/testfile.txt");
    int result = Select(a,tema,choice);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST (Select_Correct_Theme, Correct_Check)
{
    char a[256],tema[256];
    int choice=1;
    strcpy(a,"testxt/testfile.txt");
    int result = Select(a,tema,choice);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST (Select_In_Fake_File, Correct_Check)
{
    char a[256],tema[256];
    int choice=1;
    strcpy(a,"Empty.txt");
    int result = Select(a,tema,choice);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST (Select_In_Empty_File, Correct_Check)
{
    char a[256],tema[256];
    int choice=0;
    strcpy(a,"testxt/testfile_empty.txt");
    int result = Select(a,tema,choice);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

int main(int argc, const char** argv)
{
    int test_result = ctest_main(argc, argv);
    return test_result;
}
