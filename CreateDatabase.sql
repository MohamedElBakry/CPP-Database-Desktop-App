/* Uncomment if needed */
CREATE DATABASE lhu_db;

USE lhu_db;

CREATE TABLE Students (
    studentID INT AUTO_INCREMENT PRIMARY KEY,
    forename VARCHAR(35) NOT NULL,
    surname VARCHAR(35) NOT NULL,
    dateOfBirth DATE NOT NULL,
    studyLevel CHAR(1) NOT NULL,
    resProjName VARCHAR(100)
);

CREATE TABLE degreePrograms (
    degreeID INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(70) NOT NULL,
    startDate DATE,
    endDate DATE
);

CREATE TABLE Courses (
    courseID INT AUTO_INCREMENT PRIMARY KEY,
    degreeID INT NOT NULL,
    name VARCHAR(40) NOT NULL,
    courseLevel CHAR(1),

    FOREIGN KEY (degreeID) REFERENCES degreePrograms(degreeID) ON UPDATE CASCADE ON DELETE RESTRICT
);

CREATE TABLE Assessments (
    assessmentID INT AUTO_INCREMENT PRIMARY KEY,
    courseID INT NOT NULL,
    name VARCHAR(40) NOT NULL,
    weighting INT NOT NULL,
    deadline DATE NOT NULL,

    FOREIGN KEY (courseID) REFERENCES Courses(courseID) ON UPDATE CASCADE ON DELETE RESTRICT
);

CREATE TABLE studentsDegrees (
    studentID INT NOT NULL,
    degreeID INT NOT NULL,
    overallGrade VARCHAR(3),

    FOREIGN KEY (studentID) REFERENCES Students(studentID) ON UPDATE CASCADE ON DELETE RESTRICT,
    FOREIGN KEY (degreeID) REFERENCES degreePrograms(degreeID) ON UPDATE CASCADE ON DELETE RESTRICT
);

CREATE TABLE studentsCourses (
    studentID INT NOT NULL,
    courseID INT NOT NULL,
    mark INT,
    letterGrade VARCHAR(3), /* We will run a trigger on insertion or call a conversion function */
    progressionCode VARCHAR(150),

    FOREIGN KEY (studentID) REFERENCES Students(studentID) ON UPDATE CASCADE ON DELETE RESTRICT,
    FOREIGN KEY (courseID) REFERENCES Courses(courseID) ON UPDATE CASCADE ON DELETE RESTRICT
);

CREATE TABLE studentsAssessments (
    studentID INT NOT NULL,
    assessmentID INT NOT NULL,
    mark INT,
    letterGrade VARCHAR(3),
    concessionalCode CHAR(2),

    FOREIGN KEY (studentID) REFERENCES Students(studentID) ON UPDATE CASCADE ON DELETE RESTRICT,
    FOREIGN KEY (assessmentID) REFERENCES Assessments(assessmentID) ON UPDATE CASCADE ON DELETE RESTRICT
);

-- Procedures. 
    -- Use CALL [ProcedureName];

-- Just use SELECT MAX(studentID) FROM Students WHERE forename = ?;
DELIMITER //
CREATE PROCEDURE getLastSIDFrom (IN fname VARCHAR(35))
BEGIN
    SELECT studentID
    FROM Students
    WHERE forename = fname
    ORDER BY studentID DESC
    LIMIT 1;
END//

DELIMITER ;

-- Notable Queries

-- Get Students forename and surname with the courses studied:
SELECT s.studentID, forename, surname, c.name
FROM students as s
INNER JOIN studentscourses as sc
ON s.studentID = sc.studentID
INNER JOIN courses as c
ON c.courseID = sc.courseID

-- Get student details with courses and assessment details. adjust fields after SELECT
SELECT assessments.assessmentID
FROM students
INNER JOIN studentscourses
ON students.studentID = studentscourses.studentID
INNER JOIN assessments
ON assessments.courseID = studentscourses.courseID

-- INSERT 
INSERT INTO studentsassessments (studentsassessments.studentID, studentsassessments.assessmentID)
SELECT s.studentID, a.assessmentID
FROM Students as S
INNER JOIN studentsCourses as sC
ON S.studentID = sC.studentID
INNER JOIN assessments as a
ON a.courseID = sC.courseID
WHERE S.studentID = ?;