# CSCCOREI001-CppDatabases
 
For more details, please see pages 28 - 32 in the [specification](https://live.moodle.hope.ac.uk/pluginfile.php/75945/mod_resource/content/0/Course%20Booklet%20CSCCOREI%202019-2.pdf).


## Self-Notes
1. Clear form on load?
2. Read in studentID too from enrol.txt, or generate on INSERT with AUTO_INCREMENT?
3. Explore progression codes...#
4. Prevent submission of any fields with empty          spaces      ?


## TODO 
1. Edit student course marks:
2. Display student transcript for a specified student.
    a. Course names, Level and Assessment Details with Marks (courses.name, courses.level, assessment.name, assessment.weighting, students.assessments.mark) ?
    b. With the Calculated overall aggregate for each level completed (studentsCourses.letterGrade)?
    c. With the Calculated overall degree classification if all levels completed  (studentsDegrees.overallGrade) if Level C, I and H courses entries found 
