/*test09 .cpp*/

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


TEST_CASE( "Test 09", "[Project01]" ) 
{
//vector<Course> FindCourses(const College& college, int courseNumber);
////
// FindCourses(dept, courseNumber)
//
// Searches the courses in the department for those that match
// the given course number.  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, with the courses
// appearing in ascending order by course number.  If two courses
// have the same course number, they are given in ascending order
// by section number.
//
    
    Course A("CS", "Seminar", 499, 02, "Hummel", 
           /*A-F*/ 1,2, 8, 0, 9, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1); 
    Course B("CS", "101", 499, 01, "Hummel", 
           /*A-F*/ 1, 2, 3, 4, 5, 
           /*I,S,U,W,NR*/ 2, 88, 8, 3, 1); 
    Course C("CS", "102", 499, 03, "Hummel", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 3, 1);
    Course X("CS", "103", 499, 04, "Hummel", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 7, 1);
   
    Course Y("CS", "104", 233, 05, "Hummel", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 3, 1);
    Course Z("CS", "105", 499, 06, "Hummel", 
           /*A-F*/ 1, 2, 3, 4, 5, 
           /*I,S,U,W,NR*/ 2, 88, 0, 7, 1);
    
   Dept K;
   Dept L;
   L.Name = "CHEM";
   K.Name = "PHY";

   (K.Courses).push_back(A);
   College ASU;
   ASU.Name = "ALU";    
        
    (K.Courses).push_back(C);
    (K.Courses).push_back(B);
    (K.Courses).push_back(X);
    (L.Courses).push_back(Y);
    (L.Courses).push_back(Z);
    (L.Courses).push_back(A);
    (ASU.Depts).push_back(K);
    (ASU.Depts).push_back(L);
    
    

  vector<Course> courseResults = FindCourses(K, 499);
  REQUIRE(FindCourses(ASU, 499).size() == 6);  
  int i=1;
        
      REQUIRE(courseResults.at(i).Dept == "CS");
      REQUIRE(courseResults.at(i).Title == "Seminar");
      REQUIRE(courseResults.at(i).Number == 499);
      REQUIRE(courseResults.at(i).Section == 2);
      REQUIRE(courseResults.at(i).Instructor == "Hummel");

      REQUIRE(courseResults.at(i).NumA == 1);
      REQUIRE(courseResults.at(i).NumB == 2);           
      REQUIRE(courseResults.at(i).NumC == 8);
      REQUIRE(courseResults.at(i).NumD == 0);
      REQUIRE(courseResults.at(i).NumF == 9);
    
    
    i=2;
      REQUIRE(courseResults.at(i).Dept == "CS");
      REQUIRE(courseResults.at(i).Title == "102");
      REQUIRE(courseResults.at(i).Number == 499);
      REQUIRE(courseResults.at(i).Section == 3);
      REQUIRE(courseResults.at(i).Instructor == "Hummel");

      REQUIRE(courseResults.at(i).NumA == 0);
      REQUIRE(courseResults.at(i).NumB == 0);           
      REQUIRE(courseResults.at(i).NumC == 0);
      REQUIRE(courseResults.at(i).NumD == 0);
      REQUIRE(courseResults.at(i).NumF == 0);  
    
    
}