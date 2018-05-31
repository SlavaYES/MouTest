#define CTEST_MAIN

#include "checkfile.h"
#include "displaylist.h"
#include "select.h"
#include "startTesting.h"
#include "add_tem.h"
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

//CORRECT MAKC

CTEST (checkCorrect1, Right_File)
{
    char testName[256];
    strcpy(testName, "testxt/checkCorrect1.txt");
    int result=checkCorrect(testName);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

//INCORRECT

CTEST (checkCorrect2, Absolutely_False_File)
{
    char testName[256];
    strcpy(testName, "testxt/checkCorrect2.txt");
    int result=checkCorrect(testName);
    int expected=1;
    ASSERT_EQUAL(expected, result);
}

CTEST (checkCorrect3, False_File_With_One_Right_Symbol)
{
    char testName[256];
    strcpy(testName, "testxt/checkCorrect3.txt");
    int result=checkCorrect(testName);
    int expected=1;
    ASSERT_EQUAL(expected, result);
}

CTEST (checkCorrect4, False_File_With_Two_Right_Symbol)
{
    char testName[256];
    strcpy(testName, "testxt/checkCorrect4.txt");
    int result=checkCorrect(testName);
    int expected=1;
    ASSERT_EQUAL(expected, result);
}

CTEST (checkCorrect5, False_File_With_Three_Right_Symbol)
{
    char testName[256];
    strcpy(testName, "testxt/checkCorrect5.txt");
    int result=checkCorrect(testName);
    int expected=1;
    ASSERT_EQUAL(expected, result);
}

CTEST (Creat_file_with_space, False_file)
{
    FILE *file = fopen("", "");
    fclose(file);
    char nameTest[256];

    strcpy(nameTest, "egwr");

    int result = setFile(nameTest, file);
    int expected = 1;

    ASSERT_EQUAL(expected, result);
}


int main(int argc, const char** argv)
{
    int test_result = ctest_main(argc, argv);
    return test_result;
}
