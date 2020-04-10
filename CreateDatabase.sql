/* Uncomment if needed */
DROP DATABASE IF EXISTS lhu_db;

CREATE DATABASE lhu_db;

USE lhu_db;

CREATE TABLE students (
    studentID INT AUTO_INCREMENT PRIMARY KEY,
    forename VARCHAR(35) NOT NULL,
    surname VARCHAR(35) NOT NULL,
    dateOfBirth DATE NOT NULL,
    studyLevel CHAR(1) NOT NULL,
    resProjName VARCHAR(100)
);

CREATE TABLE degree_programs (
    degreeID INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(70) NOT NULL,
    startDate DATE,
    endDate DATE
);

CREATE TABLE courses (
    courseID INT AUTO_INCREMENT PRIMARY KEY,
    degreeID INT NOT NULL,
    name VARCHAR(40) NOT NULL,
    courseLevel CHAR(1),

    FOREIGN KEY (degreeID) REFERENCES degree_programs(degreeID) ON UPDATE CASCADE ON DELETE RESTRICT
);

CREATE TABLE assessments (
    assessmentID INT AUTO_INCREMENT PRIMARY KEY,
    courseID INT NOT NULL,
    name VARCHAR(40) NOT NULL,
    weighting INT NOT NULL,
    deadline DATE NOT NULL,

    FOREIGN KEY (courseID) REFERENCES courses(courseID) ON UPDATE CASCADE ON DELETE RESTRICT
);

CREATE TABLE students_degrees (
    studentID INT NOT NULL,
    degreeID INT NOT NULL,
    overallGrade VARCHAR(3),

    FOREIGN KEY (studentID) REFERENCES students(studentID) ON UPDATE CASCADE ON DELETE CASCADE,
    FOREIGN KEY (degreeID) REFERENCES degree_programs(degreeID) ON UPDATE CASCADE ON DELETE RESTRICT
);

CREATE TABLE students_courses (
    studentID INT NOT NULL,
    courseID INT NOT NULL,
    mark INT,
    letterGrade VARCHAR(3), /* We will run a trigger on insertion or call a conversion function */
    progressionCode VARCHAR(150),

    FOREIGN KEY (studentID) REFERENCES students(studentID) ON UPDATE CASCADE ON DELETE CASCADE,
    FOREIGN KEY (courseID) REFERENCES courses(courseID) ON UPDATE CASCADE ON DELETE RESTRICT
);

CREATE TABLE students_assessments (
    studentID INT NOT NULL,
    assessmentID INT NOT NULL,
    mark INT,
    letterGrade VARCHAR(3),
    concessionalCode VARCHAR(2),

    FOREIGN KEY (studentID) REFERENCES students(studentID) ON UPDATE CASCADE ON DELETE CASCADE,
    FOREIGN KEY (assessmentID) REFERENCES assessments(assessmentID) ON UPDATE CASCADE ON DELETE RESTRICT
);

-- Procedures. 
    -- Use CALL [ProcedureName];

-- Get the courses that belong to a student
DELIMITER //

CREATE PROCEDURE getCoursesOfStudent(IN sid INT)
BEGIN
    SELECT courses.courseID, courses.name
    FROM students
    INNER JOIN students_courses
    ON students.studentID = students_courses.studentID
    INNER JOIN courses
    ON students_courses.courseID = courses.courseID
    WHERE students.studentID = sid;
END//

DELIMITER ;

-- Get the assessments that belong to a student
DROP PROCEDURE IF EXISTS getAssessmentsOfStudent

DELIMITER //
CREATE PROCEDURE getAssessmentsOfStudent(IN sid INT, IN cid INT)
BEGIN
    SELECT assessments.assessmentID, assessments.name, students_assessments.mark
    FROM assessments
    INNER JOIN students_courses
    ON students_courses.courseID = assessments.courseID
	INNER JOIN students_assessments
    ON students_assessments.assessmentID = assessments.assessmentID
    WHERE students_courses.studentID = sid
    AND students_courses.courseID = cid;
END//

DELIMITER ;

-- Get students transcript
DROP PROCEDURE IF EXISTS getStudentsTranscript;

DELIMITER //

CREATE PROCEDURE getStudentsTranscript()
BEGIN
    SELECT students.studentID, forename, surname, studyLevel, degree_programs.name as degreeName, students_degrees.overallGrade, courses.name as courseName, students_courses.letterGrade as courseGrade, assessments.name as assessmentName, students_assessments.mark, students_assessments.letterGrade
    FROM students
    INNER JOIN students_courses
    ON students.studentID = students_courses.studentID
    INNER JOIN assessments
    ON assessments.courseID = students_courses.courseID
    INNER JOIN courses
    ON courses.courseID = students_courses.courseID
    INNER JOIN students_assessments
    ON students_assessments.assessmentID = assessments.assessmentID
	INNER JOIN degree_programs
    ON degree_programs.degreeID = courses.degreeID
    INNER JOIN students_degrees
    ON students_degrees.studentID = students_courses.studentID;
END //

DELIMITER ;

-- Convert numerical mark to letter grade
DROP PROCEDURE IF EXISTS markToGrade;

DELIMITER //

CREATE PROCEDURE markToGrade(IN mark INT, OUT grade VARCHAR(3))
BEGIN
         IF mark >= 92 THEN SET grade = "A++";
         ELSEIF mark >= 84 THEN SET grade = "A+";
         ELSEIF mark >= 76 THEN SET grade = "A";
         ELSEIF mark >= 70 THEN SET grade = "A-";
         ELSEIF mark >= 68 THEN SET grade = "B+";
         ELSEIF mark >= 64 THEN SET grade = "B";
         ELSEIF mark >= 60 THEN SET grade = "B-";
         ELSEIF mark >= 58 THEN SET grade = "C+";
         ELSEIF mark >= 54 THEN SET grade = "C";
         ELSEIF mark >= 50 THEN SET grade = "C-";
         ELSEIF mark >= 48 THEN SET grade = "D";
         ELSEIF mark >= 42 THEN SET grade = "E";
         ELSEIF mark >= 38 THEN SET grade = "F+";
         ELSEIF mark >= 32 THEN SET grade = "F";
         ELSEIF mark >= 22 THEN SET grade = "F-";
         ELSEIF mark >= 12 THEN SET grade = "WF";
         ELSEIF mark <= 2 THEN SET grade = "U";
         ELSE SET grade = NULL;
         END IF;
END//

DELIMITER ;

-- Just use SELECT MAX(studentID) FROM Students WHERE forename = ?;
DELIMITER //
CREATE PROCEDURE getLastSIDFrom (IN fname VARCHAR(35))
BEGIN
    SELECT studentID
    FROM students
    WHERE forename = fname
    ORDER BY studentID DESC
    LIMIT 1;
END//

DELIMITER ;

-- Notable Queries

-- Get Students forename and surname with the courses studied:
SELECT s.studentID, forename, surname, c.name
FROM students as s
INNER JOIN students_courses as sc
ON s.studentID = sc.studentID
INNER JOIN courses as c
ON c.courseID = sc.courseID

-- Get student details with courses and assessment details. adjust fields after SELECT
SELECT assessments.assessmentID
FROM students
INNER JOIN students_courses
ON students.studentID = students_courses.studentID
INNER JOIN assessments
ON assessments.courseID = students_courses.courseID

-- As above with course and assessment names

SELECT students.studentID, forename, surname, studyLevel, degree_programs.name, students_degrees.overallGrade, courses.name, students_courses.letterGrade, assessments.name, students_assessments.mark, students_assessments.letterGrade
FROM students
INNER JOIN students_courses
ON students.studentID = students_courses.studentID
INNER JOIN assessments
ON assessments.courseID = students_courses.courseID
INNER JOIN courses
ON courses.courseID = students_courses.courseID
INNER JOIN students_assessments
ON students_assessments.assessmentID = assessments.assessmentID
INNER JOIN degree_programs
ON degree_programs.degreeID = courses.degreeID
INNER JOIN students_degrees
ON students_degrees.studentID = students_courses.studentID

-- INSERT 
INSERT INTO students_assessments (students_assessments.studentID, students_assessments.assessmentID)
SELECT s.studentID, a.assessmentID
FROM students as S
INNER JOIN students_courses as sC
ON S.studentID = sC.studentID
INNER JOIN assessments as a
ON a.courseID = sC.courseID
WHERE S.studentID = ?;