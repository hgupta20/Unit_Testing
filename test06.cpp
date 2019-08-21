/*test06 .cpp*/

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


TEST_CASE( "Test 06", "[Project01]" ) 
{
  Course A("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
  Course B("CS", "Professional 101", 499, 01, "Hummel", 
           /*A-F*/0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 3, 1);
  Course Z("CS", "Professional 102", 499, 01, "Hummel", 
           /*A-F*/0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 7, 1);
  Course Y("CS", "Professional 103", 499, 01, "Hummel", 
           /*A-F*/0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 3, 1);
  Course X("CS", "CS 341", 499, 01, "Hummel", 
           /*A-F*/0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 7, 1);
        
  Dept K;
  Dept L;
  L.Name = "CHEM";
  K.Name = "PHY";
  int DFW;
  int N;
  (K.Courses).push_back(A);\
  College ASU;
// GetDFWRate:
//
// Returns the DFW rate as a percentage for a given course, 
// department, or college.  For a course whose grading type 
// is defined as Course::Letter, the DFW rate is defined as
// 
//   # of D grades + F grades + Withdrawals
//   -------------------------------------- * 100.0
//   # of A, B, C, D, F grades + Withdrawls
//
// The numerator is returned via the reference parameter DFW;
// the denominator is returned via the reference parameter N.
// If the course grading type is not Course::Letter, the DFW
// rate is 0.0, and parameters DFW and N are set to 0.  
//
// When computed for a dept or college, all courses of type 
// Course::Letter are considered in computing an overall DFW 
// rate for the dept or college.  The reference parameters 
// DFW and N are also computed across the dept or college.
//
   (K.Courses).push_back(B);
   (L.Courses).push_back(X);
   (L.Courses).push_back(Y);
   (L.Courses).push_back(Z);
        
   ASU.Name = "ALU";
   (ASU.Depts).push_back(K);
   (ASU.Depts).push_back(L);
   
   REQUIRE(abs((GetDFWRate(ASU, DFW, N))-0) < 0.001);
   REQUIRE((N - 0) == 0);
   REQUIRE((DFW-0) == 0);
   
           
  /*REQUIRE(C.Dept == "CS");
  REQUIRE(C.Title == "Professional Seminar");
  REQUIRE(C.Number == 499);
  REQUIRE(C.Section == 01);
  REQUIRE(C.Instructor == "Hummel");
  
  REQUIRE(C.NumA == 0);
  REQUIRE(C.NumB == 0);           
  REQUIRE(C.NumC == 0);
  REQUIRE(C.NumD == 0);
  REQUIRE(C.NumF == 0);
  
  REQUIRE(C.NumI == 2);
  REQUIRE(C.NumS == 88);           
  REQUIRE(C.NumU == 0);
  REQUIRE(C.NumW == 0);
  REQUIRE(C.NumNR == 1);  
  
  REQUIRE(C.getGradingType() == Course::Satisfactory);
  */
}
