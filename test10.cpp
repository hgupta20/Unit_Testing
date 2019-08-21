/*test10 .cpp*/

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


TEST_CASE( "Test 10", "[Project01]" ) 
{
    
   //vector<Course> FindCourses(const College& college, int courseNumber);
////make all
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
   
    
   Dept K;
   Dept L;
   L.Name = "CHEM";
   K.Name = "PHY";

   //(K.Courses).push_back(A);
   College ASU;
   ASU.Name = "ALU";    
        
    (K.Courses).push_back(A);
    (K.Courses).push_back(B);
    (K.Courses).push_back(C);

    (ASU.Depts).push_back(K);
    (ASU.Depts).push_back(L);
    
    vector<Course> vec1 = FindCourses(K, 49);
    REQUIRE(vec1.size()==0);
    vector<Course> vec2 = FindCourses(ASU,134);
    REQUIRE(vec2.size()==0);
    vector<Course> vec3 = FindCourses(K, "Humm");
    REQUIRE(vec3.size()==3);

}