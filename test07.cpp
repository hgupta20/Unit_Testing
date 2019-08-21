/*test07 .cpp*/

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


TEST_CASE( "Test 07", "[Project01]" ) 
{
  Course H= ParseCourse ("BIOE,101,01,Intro to Bioengineering,1,2,3,4,5,2,69,88,1,2,Eddington");
  Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/0, 0, 1, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
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
  K.Name = "PHY";
  (K.Courses).push_back(C);
  (K.Courses).push_back(H);
  
  REQUIRE(C.Dept == "CS");
  REQUIRE(C.Title == "Professional Seminar");
  REQUIRE(C.Number == 499);
  REQUIRE(C.Section == 01);
  REQUIRE(C.Instructor == "Hummel");
  GradeStats F = GetGradeDistribution(K);
  
  REQUIRE(F.N == 16);
  REQUIRE(F.NumA == 1);
  REQUIRE(F.NumB == 2);
  REQUIRE(F.NumC == 4);
  REQUIRE(F.NumD == 4);
  REQUIRE(F.NumF == 5);
  REQUIRE(abs(F.PercentA-6.25)<.001);
  REQUIRE(abs(F.PercentB-12.5) <.001);
  REQUIRE(abs(F.PercentD-25) <.001);
  REQUIRE(abs(F.PercentF-31.25) <.001);
           
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
