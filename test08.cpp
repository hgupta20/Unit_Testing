/*test08 .cpp*/

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


TEST_CASE( "Test 08", "[Project01]" ) 
{
 Course A("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/1, 2, 3, 4, 8, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
  Course B("CS", "Professional 101", 499, 01, "Hummel", 
           /*A-F*/0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 3, 1);
  Course Z("CS", "Professional 102", 499, 01, "Hummel", 
           /*A-F*/1, 2, 3, 4, 5, 
           /*I,S,U,W,NR*/ 2, 88, 0, 7, 1);
  Course Y("CS", "Professional 103", 499, 01, "Hummel", 
           /*A-F*/0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 3, 1);
  Course X("CS", "CS 341", 499, 01, "Hummel", 
           /*A-F*/1, 2, 4, 4, 5,  
           /*I,S,U,W,NR*/ 2, 88, 0, 7, 1);

 //
// GetGradeDistribution
//
// Returns an object containing the grade distribution for a given
// course, dept or college.  For a course whose grading type is
// defined as Course::Letter, the grade distribution is defined by
// the following values:
//
//   N: the # of A, B, C, D, F grades
//   NumA, NumB, NumC, NumD, NumF: # of A, B, C, D, F grades
//   PercentA, PercentB, PercentC, PercentD, PercentF: % of A, B, 
//     C, D, F grades.  Example: PercentA = NumA / N * 100.0
//
// If the course grading type is not Course::Letter, all values
// are 0.  When computed for a dept or college, all courses of
// type Course::Letter are considered in computing an overall 
// grade distribution for the dept or college.
//
  Dept K;
  Dept L;
  L.Name = "CHEM";
  K.Name = "PHY";

  (K.Courses).push_back(A);
  College ASU;
  ASU.Name = "ALU";     
 
   (K.Courses).push_back(B);
   (L.Courses).push_back(X);
   (L.Courses).push_back(Y);
   (L.Courses).push_back(Z);
   (ASU.Depts).push_back(K);
   (ASU.Depts).push_back(L);
        
   GradeStats F=GetGradeDistribution(ASU);
   
   REQUIRE(F.N == 49);
   REQUIRE(F.NumA == 3);
   REQUIRE(F.NumB == 6);
   REQUIRE(F.NumC == 10);
   REQUIRE(F.NumD == 12);
   REQUIRE(F.NumF == 18);
   REQUIRE(abs(F.PercentA-6.1224489796) <.001 );
   REQUIRE(abs(F.PercentB-12.2448979592) <.001);
   REQUIRE(abs(F.PercentD-24.4897959184)<.001);
   REQUIRE(abs(F.PercentF-36.7346938776)<.001); 

    /*
 REQUIRE(C.Dept == "CS");
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
  
  REQUIRE(C.getGradingType() == Course::Satisfactory);*/
}