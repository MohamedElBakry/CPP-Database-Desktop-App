# CSCCOREI001-CppDatabases
 
For more details, please see pages 28 - 32 in the [specification](https://live.moodle.hope.ac.uk/pluginfile.php/75945/mod_resource/content/0/Course%20Booklet%20CSCCOREI%202019-2.pdf).


## Self-Notes
AddStudentWizard:
    *OnPageChange Event*
        If student is Level H:
            Get Research Project details

        If course 1 and 2 are same:
            prevent
        
        Get student's courses and enrol to degrees of course 1 and 2:
            SELECT degreeID FROM courses WHERE courseID=x; <-- Do this for both course 1 and 2.
            And enrol the student to each degree, unless the degree is the same, then enrol them once. 
        
        Insert data.

## TODO 
1. Update database data whilst the app is running
2. Edit student marks:
    Table of students:
        Click on a student ->
            Table of their edittable marks...
