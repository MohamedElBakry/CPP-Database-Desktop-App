# CSCCOREI001-CppDatabases
 
For more details, please see pages 28 - 32 in the [specification](https://live.moodle.hope.ac.uk/pluginfile.php/75945/mod_resource/content/0/Course%20Booklet%20CSCCOREI%202019-2.pdf).


## Self-Notes
0. Do courses have a variable number of assessments, or are there always 3 assessments?

1. Clear form on load?

2. Read in studentID too from enrol.txt, or generate on INSERT with AUTO_INCREMENT?

4. Prevent submission of any fields with empty          spaces      ? 
    -- Currently, empty fields are prevented. Can use boost::string for trim()

5. Set wxTextCtrl max length to correspond to database field length?

6. Change Main Menu buttons: View <name> to View/Edit <name> ? 

7. StudentID foreign key: ON DELETE CASCADE instead of RESTRICT?


## TODO 

1. studentGridView: -- TODO: Update data on open -- TODO: Set read only attribute to certain columns
    a. Display all student details/student transcript (to be specified) 
    b. Allow grid cells to be editted
    c. Get user confirmation for the changed data
    d. Iterate over grid cells, get data, and UPDATE the database. 

2. Display student transcript for a specified student.
    a. Course names, Level and Assessment Details with Marks (courses.name, courses.level, assessment.name, assessment.weighting, students.assessments.mark) ?
    b. With the Calculated overall aggregate for each level completed (studentsCourses.letterGrade)?
    c. With the Calculated overall degree classification if all levels completed  (studentsDegrees.overallGrade) if Level C, I and H courses entries found 

3. Create SQL Trigger for ON INSERT assessment mark OR course mark, generate and INSERT letterGrade
