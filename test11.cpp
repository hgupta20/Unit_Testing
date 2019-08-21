/*test11 .cpp*/

//
// <<Harsh Devprakash Gupta>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases:
// 
// *****************************************************************

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;

TEST_CASE( "Test 11", "[Project01]" ) 
{
    Course A("CS", "Seminar", 499, 02, "Hummel", 
           /*A-F*/ 144,256, 788, 990, 7899, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1); 
    Course B("CS", "101", 499, 01, "Hummel", 
           /*A-F*/ 241, 242, 3535, 435, 355, 
           /*I,S,U,W,NR*/ 2, 88, 8, 3, 1); 
    Course C("CS", "102", 499, 03, "Hummel", 
           /*A-F*/ 8970, 750, 570, 680, 630, 
           /*I,S,U,W,NR*/ 2, 88, 0, 3, 1);
    Course X("CS", "103", 499, 04, "Hummel", 
           /*A-F*/ 574, 1289, 9035, 4882, 10,
           /*I,S,U,W,NR*/ 2, 88, 0, 7, 1);
   
    Course Y("CS", "104", 233, 05, "Hummel", 
           /*A-F*/ 8864, 4421, 56, 42, 1, 
           /*I,S,U,W,NR*/ 2, 88, 0, 3, 1);
    Course Z("CS", "105", 499, 06, "Hummel", 
           /*A-F*/ 1, 2, 3, 4, 5, 
           /*I,S,U,W,NR*/ 2, 88, 0, 7, 1);
    
   Dept K;
   Dept L;
   int DFW;
   int N;
   L.Name = "CHEM";
   K.Name = "PHY";

   (K.Courses).push_back(A);
   College ASU;
   ASU.Name = "ALU";    
        

    (K.Courses).push_back(A);
    (K.Courses).push_back(B);
    (L.Courses).push_back(X);
    (L.Courses).push_back(Y);
    (L.Courses).push_back(Z);
    (ASU.Depts).push_back(K);
    (ASU.Depts).push_back(L);
        
    
   //double GetDFWRate(const College& college, int& DFW, int& N);
     REQUIRE(abs((GetDFWRate(ASU, DFW,N))-43.4402170903) < .001);
     REQUIRE((DFW-23532)  == 0);
     REQUIRE((N-54171)==0);

//double GetDFWRate(const Dept& dept, int& DFW, int& N);
   double result = GetDFWRate(B, DFW, N);
    REQUIRE(abs((result-16.483059655))<.001);
    REQUIRE(DFW == 793);
    REQUIRE(N == 4811);
    
}